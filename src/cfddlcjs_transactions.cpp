// Copyright 2019 CryptoGarage
/**
 * @file cfddlcjs_transaction.cpp
 *
 * @brief cfd-dlc-apiで利用するTransaction作成の実装ファイル
 */

#include "cfddlcjs/cfddlcjs_transactions.h"

#include <sstream>
#include <vector>

#include "cfdcore/cfdcore_key.h"
#include "cfddlc/cfddlc_transactions.h"
#include "cfddlcjs/cfddlcjs_struct.h"
#include "cfddlcjs_internal.h"  // NOLINT

namespace cfd {
namespace dlc {
namespace js {
namespace api {

using cfd::core::ByteData256;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::HashUtil;
using cfd::core::Privkey;
using cfd::core::Txid;
using cfd::core::TxIn;
using cfd::dlc::DlcInputInfo;
using cfd::dlc::DlcManager;
using cfd::dlc::DlcOutcome;
using cfd::dlc::DlcTransactions;
using cfd::dlc::TxInputInfo;

TxOut GetChangeOutput(const std::string &address_string, int64_t amount_int) {
  Address address(address_string);
  auto amount = Amount::CreateBySatoshiAmount(amount_int);
  return TxOut(amount, address);
}

NetType ParseNetType(std::string input) {
  if (input == "mainnet") {
    return NetType::kMainnet;
  } else if (input == "testnet") {
    return NetType::kTestnet;
  } else if (input == "regtest") {
    return NetType::kRegtest;
  }

  throw CfdException(
    CfdError::kCfdIllegalArgumentError, "Unsupported network type");
}

static TxInputInfo ParseTxInRequest(TxInInfoRequestStruct &input_info) {
  Txid txid(input_info.txid);
  if (input_info.redeem_script != "") {
    TxIn input(txid, input_info.vout, 0, Script(input_info.redeem_script));
    return {input, input_info.max_witness_length, input_info.input_serial_id};
  } else {
    TxIn input(txid, input_info.vout, 0);
    return {input, input_info.max_witness_length, input_info.input_serial_id};
  }
}

static DlcInputInfo
ParseDlcInputRequest(DlcInputInfoRequestStruct &input_info) {
  Txid fund_txid(input_info.fund_txid);
  auto fund_amount = Amount::CreateBySatoshiAmount(input_info.fund_amount);
  Pubkey local_fund_pubkey(input_info.local_fund_pubkey);
  Pubkey remote_fund_pubkey(input_info.remote_fund_pubkey);

  DlcInputInfo dlc_input;
  dlc_input.fund_txid = fund_txid;
  dlc_input.fund_vout = input_info.fund_vout;
  dlc_input.fund_amount = fund_amount;
  dlc_input.local_fund_pubkey = local_fund_pubkey;
  dlc_input.remote_fund_pubkey = remote_fund_pubkey;
  dlc_input.max_witness_length = input_info.max_witness_length;
  dlc_input.input_serial_id = input_info.input_serial_id;

  return dlc_input;
}

CreateFundTransactionResponseStruct DlcTransactionsApi::CreateFundTransaction(
  const CreateFundTransactionRequestStruct &request) {
  auto call_func = [](const CreateFundTransactionRequestStruct &request)
    -> CreateFundTransactionResponseStruct {
    CreateFundTransactionResponseStruct response;
    auto local_pubkey = Pubkey(request.local_pubkey);
    auto remote_pubkey = Pubkey(request.remote_pubkey);
    auto output_amount = Amount::CreateBySatoshiAmount(request.output_amount);
    auto option_premium = Amount::CreateBySatoshiAmount(request.option_premium);
    auto option_dest =
      request.option_dest == "" ? Address() : Address(request.option_dest);

    std::vector<TxInputInfo> local_inputs;

    for (auto input_request : request.local_inputs) {
      local_inputs.push_back(ParseTxInRequest(input_request));
    }

    std::vector<TxInputInfo> remote_inputs;

    for (auto input_request : request.remote_inputs) {
      remote_inputs.push_back(ParseTxInRequest(input_request));
    }

    auto local_change = GetChangeOutput(
      request.local_change.address, request.local_change.amount);
    auto remote_change = GetChangeOutput(
      request.remote_change.address, request.remote_change.amount);

    uint64_t lock_time = request.lock_time;
    uint64_t local_serial_id = request.local_serial_id;
    uint64_t remote_serial_id = request.remote_serial_id;
    uint64_t output_serial_id = request.output_serial_id;

    auto transaction = DlcManager::CreateFundTransaction(
      local_pubkey, remote_pubkey, output_amount, local_inputs, local_change,
      remote_inputs, remote_change, option_dest, option_premium, lock_time,
      local_serial_id, remote_serial_id, output_serial_id);
    response.hex = transaction.GetHex();
    return response;
  };
  CreateFundTransactionResponseStruct result;
  result = ExecuteStructApi<
    CreateFundTransactionRequestStruct, CreateFundTransactionResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateBatchFundTransactionResponseStruct
DlcTransactionsApi::CreateBatchFundTransaction(
  const CreateBatchFundTransactionRequestStruct &request) {
  auto call_func = [](const CreateBatchFundTransactionRequestStruct &request)
    -> CreateBatchFundTransactionResponseStruct {
    CreateBatchFundTransactionResponseStruct response;

    std::vector<Pubkey> local_pubkeys;
    std::vector<Pubkey> remote_pubkeys;
    std::vector<Amount> output_amounts;
    std::vector<uint64_t> output_serial_ids;

    std::vector<TxInputInfo> local_inputs;

    for (auto input_request : request.local_inputs) {
      local_inputs.push_back(ParseTxInRequest(input_request));
    }

    std::vector<TxInputInfo> remote_inputs;

    for (auto input_request : request.remote_inputs) {
      remote_inputs.push_back(ParseTxInRequest(input_request));
    }

    auto local_change = GetChangeOutput(
      request.local_change.address, request.local_change.amount);
    auto remote_change = GetChangeOutput(
      request.remote_change.address, request.remote_change.amount);

    for (size_t i = 0; i < request.local_pubkeys.size(); ++i) {
      local_pubkeys.push_back(Pubkey(request.local_pubkeys[i]));
      remote_pubkeys.push_back(Pubkey(request.remote_pubkeys[i]));
      output_amounts.push_back(
        Amount::CreateBySatoshiAmount(request.output_amounts[i]));
      output_serial_ids.push_back(request.output_serial_ids[i]);
    }

    uint64_t lock_time = request.lock_time;
    uint64_t local_serial_id = request.local_serial_id;
    uint64_t remote_serial_id = request.remote_serial_id;

    auto transaction = DlcManager::CreateBatchFundTransaction(
      local_pubkeys, remote_pubkeys, output_amounts, local_inputs, local_change,
      remote_inputs, remote_change, lock_time, local_serial_id,
      remote_serial_id, output_serial_ids);

    response.hex = transaction.GetHex();
    return response;
  };

  CreateBatchFundTransactionResponseStruct result;
  result = ExecuteStructApi<
    CreateBatchFundTransactionRequestStruct,
    CreateBatchFundTransactionResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

SignFundTransactionResponseStruct DlcTransactionsApi::SignFundTransaction(
  const SignFundTransactionRequestStruct &request) {
  auto call_func = [](const SignFundTransactionRequestStruct &request)
    -> SignFundTransactionResponseStruct {
    SignFundTransactionResponseStruct response;
    auto transaction = TransactionController(request.fund_tx_hex);
    auto privkey = Privkey(request.privkey);
    auto prev_tx_id = Txid(request.prev_tx_id);
    auto value = Amount::CreateBySatoshiAmount(request.amount);

    DlcManager::SignFundTransactionInput(
      &transaction, privkey, prev_tx_id, request.prev_vout, value);
    response.hex = transaction.GetHex();
    return response;
  };
  SignFundTransactionResponseStruct result;
  result = ExecuteStructApi<
    SignFundTransactionRequestStruct, SignFundTransactionResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

GetRawFundTxSignatureResponseStruct DlcTransactionsApi::GetRawFundTxSignature(
  const GetRawFundTxSignatureRequestStruct &request) {
  auto call_func = [](const GetRawFundTxSignatureRequestStruct &request)
    -> GetRawFundTxSignatureResponseStruct {
    GetRawFundTxSignatureResponseStruct response;
    TransactionController fund_tx(request.fund_tx_hex);
    Privkey privkey(request.privkey);
    Txid prev_txid(request.prev_tx_id);
    auto amount = Amount::CreateBySatoshiAmount(request.amount);
    auto signature = DlcManager::GetRawFundingTransactionInputSignature(
      fund_tx, privkey, prev_txid, request.prev_vout, amount);
    response.hex = signature.GetHex();
    return response;
  };
  GetRawFundTxSignatureResponseStruct result;
  result = ExecuteStructApi<
    GetRawFundTxSignatureRequestStruct, GetRawFundTxSignatureResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

AddSignatureToFundTransactionResponseStruct
DlcTransactionsApi::AddSignatureToFundTransaction(
  const AddSignatureToFundTransactionRequestStruct &request) {
  auto call_func = [](const AddSignatureToFundTransactionRequestStruct &request)
    -> AddSignatureToFundTransactionResponseStruct {
    AddSignatureToFundTransactionResponseStruct response;
    TransactionController fund_tx(request.fund_tx_hex);
    Pubkey pubkey(request.pubkey);
    Txid prev_txid(request.prev_tx_id);
    ByteData signature(request.signature);
    DlcManager::AddSignatureToFundTransaction(
      &fund_tx, signature, pubkey, prev_txid, request.prev_vout);
    response.hex = fund_tx.GetHex();
    return response;
  };
  AddSignatureToFundTransactionResponseStruct result;
  result = ExecuteStructApi<
    AddSignatureToFundTransactionRequestStruct,
    AddSignatureToFundTransactionResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyFundTxSignatureResponseStruct DlcTransactionsApi::VerifyFundTxSignature(
  const VerifyFundTxSignatureRequestStruct &request) {
  auto call_func = [](const VerifyFundTxSignatureRequestStruct &request)
    -> VerifyFundTxSignatureResponseStruct {
    VerifyFundTxSignatureResponseStruct response;
    TransactionController fund_tx(request.fund_tx_hex);
    ByteData signature(request.signature);
    Pubkey pubkey(request.pubkey);
    Txid prev_txid(request.prev_tx_id);
    auto amount = Amount::CreateBySatoshiAmount(request.fund_input_amount);

    response.valid = DlcManager::VerifyFundTxSignature(
      fund_tx, signature, pubkey, prev_txid, request.prev_vout, amount);
    return response;
  };
  VerifyFundTxSignatureResponseStruct result;
  result = ExecuteStructApi<
    VerifyFundTxSignatureRequestStruct, VerifyFundTxSignatureResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateCetResponseStruct
DlcTransactionsApi::CreateCet(const CreateCetRequestStruct &request) {
  auto call_func =
    [](const CreateCetRequestStruct &request) -> CreateCetResponseStruct {
    CreateCetResponseStruct response;
    auto local_fund_pubkey = Pubkey(request.local_fund_pubkey);
    auto local_final_address = Address(request.local_final_address);
    auto remote_final_address = Address(request.remote_final_address);
    auto local_payout = Amount::CreateBySatoshiAmount(request.local_payout);
    auto remote_payout = Amount::CreateBySatoshiAmount(request.remote_payout);
    auto fund_tx_id = Txid(request.fund_tx_id);

    TxOut local_output(local_payout, local_final_address);
    TxOut remote_output(remote_payout, remote_final_address);

    auto transaction = DlcManager::CreateCet(
      local_output, remote_output, fund_tx_id, request.fund_vout,
      request.lock_time, request.local_serial_id, request.remote_serial_id);

    response.hex = transaction.GetHex();
    return response;
  };
  CreateCetResponseStruct result;
  result = ExecuteStructApi<CreateCetRequestStruct, CreateCetResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateRefundTransactionResponseStruct
DlcTransactionsApi::CreateRefundTransaction(
  const CreateRefundTransactionRequestStruct &request) {
  auto call_func = [](const CreateRefundTransactionRequestStruct &request)
    -> CreateRefundTransactionResponseStruct {
    CreateRefundTransactionResponseStruct response;
    auto local_final_script_pubkey = Script(request.local_final_script_pubkey);
    auto remote_final_script_pubkey =
      Script(request.remote_final_script_pubkey);
    auto local_amount = Amount::CreateBySatoshiAmount(request.local_amount);
    auto remote_amount = Amount::CreateBySatoshiAmount(request.remote_amount);
    auto fund_tx_id = Txid(request.fund_tx_id);

    auto transaction = DlcManager::CreateRefundTransaction(
      local_final_script_pubkey, remote_final_script_pubkey, local_amount,
      remote_amount, request.lock_time, fund_tx_id, request.fund_vout);

    response.hex = transaction.GetHex();
    return response;
  };
  CreateRefundTransactionResponseStruct result;
  result = ExecuteStructApi<
    CreateRefundTransactionRequestStruct,
    CreateRefundTransactionResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateDlcTransactionsResponseStruct DlcTransactionsApi::CreateDlcTransactions(
  const CreateDlcTransactionsRequestStruct &request) {
  auto call_func = [](const CreateDlcTransactionsRequestStruct &request)
    -> CreateDlcTransactionsResponseStruct {
    std::vector<DlcOutcome> outcomes;
    for (auto outcome_request : request.payouts) {
      DlcOutcome outcome;
      outcome.local_payout =
        Amount::CreateBySatoshiAmount(outcome_request.local);
      outcome.remote_payout =
        Amount::CreateBySatoshiAmount(outcome_request.remote);
      outcomes.push_back(outcome);
    }

    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Script local_final_script_pubkey(request.local_final_script_pubkey);
    Script remote_final_script_pubkey(request.remote_final_script_pubkey);
    auto local_input_amount =
      Amount::CreateBySatoshiAmount(request.local_input_amount);
    auto local_collateral_amount =
      Amount::CreateBySatoshiAmount(request.local_collateral_amount);
    auto remote_input_amount =
      Amount::CreateBySatoshiAmount(request.remote_input_amount);
    auto remote_collateral_amount =
      Amount::CreateBySatoshiAmount(request.remote_collateral_amount);
    uint64_t refund_locktime = request.refund_locktime;
    uint64_t fund_lock_time = request.fund_lock_time;
    uint64_t cet_lock_time = request.cet_lock_time;
    uint64_t fund_output_serial_id = request.fund_output_serial_id;
    auto option_premium = Amount::CreateBySatoshiAmount(request.option_premium);
    auto option_dest =
      request.option_dest == "" ? Address() : Address(request.option_dest);

    std::vector<TxInputInfo> local_inputs;

    for (auto input_request : request.local_inputs) {
      local_inputs.push_back(ParseTxInRequest(input_request));
    }

    std::vector<DlcInputInfo> local_dlc_inputs;
    for (auto dlc_input_request : request.local_dlc_inputs) {
      local_dlc_inputs.push_back(ParseDlcInputRequest(dlc_input_request));
    }

    std::vector<TxInputInfo> remote_inputs;

    for (auto input_request : request.remote_inputs) {
      remote_inputs.push_back(ParseTxInRequest(input_request));
    }

    std::vector<DlcInputInfo> remote_dlc_inputs;
    for (auto dlc_input_request : request.remote_dlc_inputs) {
      remote_dlc_inputs.push_back(ParseDlcInputRequest(dlc_input_request));
    }

    uint32_t fee_rate = request.fee_rate;

    uint64_t local_payout_serial_id = request.local_payout_serial_id;
    uint64_t local_change_serial_id = request.local_change_serial_id;
    uint64_t remote_payout_serial_id = request.remote_payout_serial_id;
    uint64_t remote_change_serial_id = request.remote_change_serial_id;

    Script local_change_script_pubkey(request.local_change_script_pubkey);
    Script remote_change_script_pubkey(request.remote_change_script_pubkey);
    PartyParams local_params = {
      local_fund_pubkey,         local_change_script_pubkey,
      local_final_script_pubkey, local_inputs,
      local_dlc_inputs,          local_input_amount,
      local_collateral_amount,   local_payout_serial_id,
      local_change_serial_id};
    PartyParams remote_params = {
      remote_fund_pubkey,         remote_change_script_pubkey,
      remote_final_script_pubkey, remote_inputs,
      remote_dlc_inputs,          remote_input_amount,
      remote_collateral_amount,   remote_payout_serial_id,
      remote_change_serial_id};
    auto transactions = DlcManager::CreateDlcTransactions(
      outcomes, local_params, remote_params, refund_locktime, fee_rate,
      option_dest, option_premium, fund_lock_time, cet_lock_time,
      fund_output_serial_id);
    CreateDlcTransactionsResponseStruct result;
    result.fund_tx_hex = transactions.fund_transaction.GetHex();
    result.refund_tx_hex = transactions.refund_transaction.GetHex();
    for (auto cet : transactions.cets) {
      result.cets_hex.push_back(cet.GetHex());
    }
    return result;
  };
  CreateDlcTransactionsResponseStruct result;
  result = ExecuteStructApi<
    CreateDlcTransactionsRequestStruct, CreateDlcTransactionsResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateBatchDlcTransactionsResponseStruct
DlcTransactionsApi::CreateBatchDlcTransactions(
  const CreateBatchDlcTransactionsRequestStruct &request) {
  auto call_func = [](const CreateBatchDlcTransactionsRequestStruct &request)
    -> CreateBatchDlcTransactionsResponseStruct {
    // Check that all std::vector objects have the appropriate length
    size_t num_pubkeys = request.local_fund_pubkeys.size();
    if (
      request.num_payouts.size() != num_pubkeys ||
      request.remote_fund_pubkeys.size() != num_pubkeys ||
      request.local_final_script_pubkeys.size() != num_pubkeys ||
      request.remote_final_script_pubkeys.size() != num_pubkeys ||
      request.local_collateral_amounts.size() != num_pubkeys ||
      request.remote_collateral_amounts.size() != num_pubkeys ||
      request.refund_locktimes.size() != num_pubkeys ||
      request.local_payout_serial_ids.size() != num_pubkeys ||
      request.remote_payout_serial_ids.size() != num_pubkeys ||
      (!request.fund_output_serial_ids.empty() &&
       request.fund_output_serial_ids.size() != num_pubkeys)) {
      throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Vector sizes do not match the number of pubkeys or "
        "fund_output_serial_ids is not empty and does not match the number of "
        "pubkeys.");
    }

    if (request.local_payouts.size() != request.remote_payouts.size()) {
      throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Local and remote payouts vectors must have the same size.");
    }

    // Check that fund_output_serial_ids is either empty or equal to
    // local_fund_pubkeys size
    bool fund_output_serial_ids_empty = request.fund_output_serial_ids.empty();

    std::vector<std::vector<DlcOutcome>> outcomes_list;
    size_t current_payout_index = 0;

    for (size_t i = 0; i < num_pubkeys; ++i) {
      std::vector<DlcOutcome> outcomes;
      for (size_t j = 0; j < request.num_payouts[i]; ++j) {
        DlcOutcome outcome;
        outcome.local_payout = Amount::CreateBySatoshiAmount(
          request.local_payouts[current_payout_index]);
        outcome.remote_payout = Amount::CreateBySatoshiAmount(
          request.remote_payouts[current_payout_index]);
        outcomes.push_back(outcome);
        current_payout_index++;
      }
      outcomes_list.push_back(outcomes);
    }

    auto local_input_amount =
      Amount::CreateBySatoshiAmount(request.local_input_amount);

    auto remote_input_amount =
      Amount::CreateBySatoshiAmount(request.remote_input_amount);

    std::vector<Pubkey> local_fund_pubkeys;
    std::vector<Pubkey> remote_fund_pubkeys;
    std::vector<Script> local_final_script_pubkeys;
    std::vector<Script> remote_final_script_pubkeys;
    std::vector<Amount> local_collateral_amounts;
    std::vector<Amount> remote_collateral_amounts;
    std::vector<uint64_t> refund_locktimes;
    std::vector<uint64_t> fund_output_serial_ids;
    std::vector<uint64_t> local_payout_serial_ids;
    std::vector<uint64_t> remote_payout_serial_ids;

    for (size_t i = 0; i < num_pubkeys; ++i) {
      local_fund_pubkeys.push_back(Pubkey(request.local_fund_pubkeys[i]));
      remote_fund_pubkeys.push_back(Pubkey(request.remote_fund_pubkeys[i]));
      local_final_script_pubkeys.push_back(
        Script(request.local_final_script_pubkeys[i]));
      remote_final_script_pubkeys.push_back(
        Script(request.remote_final_script_pubkeys[i]));
      local_collateral_amounts.push_back(
        Amount::CreateBySatoshiAmount(request.local_collateral_amounts[i]));
      remote_collateral_amounts.push_back(
        Amount::CreateBySatoshiAmount(request.remote_collateral_amounts[i]));
      refund_locktimes.push_back(request.refund_locktimes[i]);
      // Use zero if fund_output_serial_ids is empty, otherwise use the provided
      // value
      fund_output_serial_ids.push_back(
        fund_output_serial_ids_empty ? 0 : request.fund_output_serial_ids[i]);
      local_payout_serial_ids.push_back(request.local_payout_serial_ids[i]);
      remote_payout_serial_ids.push_back(request.remote_payout_serial_ids[i]);
    }

    uint64_t fund_lock_time = request.fund_lock_time;
    uint64_t cet_lock_time = request.cet_lock_time;

    std::vector<TxInputInfo> local_inputs;

    for (auto input_request : request.local_inputs) {
      local_inputs.push_back(ParseTxInRequest(input_request));
    }

    std::vector<TxInputInfo> remote_inputs;

    for (auto input_request : request.remote_inputs) {
      remote_inputs.push_back(ParseTxInRequest(input_request));
    }

    uint32_t fee_rate = request.fee_rate;

    uint64_t local_change_serial_id = request.local_change_serial_id;
    uint64_t remote_change_serial_id = request.remote_change_serial_id;

    Script local_change_script_pubkey(request.local_change_script_pubkey);
    Script remote_change_script_pubkey(request.remote_change_script_pubkey);

    BatchPartyParams local_params = {
      local_fund_pubkeys,         local_change_script_pubkey,
      local_final_script_pubkeys, local_inputs,
      local_input_amount,         local_collateral_amounts,
      local_payout_serial_ids,    local_change_serial_id};
    BatchPartyParams remote_params = {
      remote_fund_pubkeys,         remote_change_script_pubkey,
      remote_final_script_pubkeys, remote_inputs,
      remote_input_amount,         remote_collateral_amounts,
      remote_payout_serial_ids,    remote_change_serial_id};

    auto transactions = DlcManager::CreateBatchDlcTransactions(
      outcomes_list, local_params, remote_params, refund_locktimes, fee_rate,
      fund_lock_time, cet_lock_time, fund_output_serial_ids);
    CreateBatchDlcTransactionsResponseStruct result;
    result.fund_tx_hex = transactions.fund_transaction.GetHex();
    for (auto refund_tx : transactions.refund_transactions) {
      result.refund_tx_hex_list.push_back(refund_tx.GetHex());
    }
    for (auto cet_list : transactions.cets_list) {
      std::vector<std::string> temp_cet_list;
      for (auto cet : cet_list) {
        result.cets_hex_list.push_back(cet.GetHex());
      }
    }
    return result;
  };
  CreateBatchDlcTransactionsResponseStruct result;
  result = ExecuteStructApi<
    CreateBatchDlcTransactionsRequestStruct,
    CreateBatchDlcTransactionsResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

std::vector<Pubkey>
DlcTransactionsApi::ParsePubkeys(std::vector<std::string> input) {
  std::vector<Pubkey> output(input.size());
  for (int i = 0; i < input.size(); i++) {
    output[i] = Pubkey(input[i]);
  }
  return output;
}

std::vector<SchnorrPubkey>
DlcTransactionsApi::ParseSchnorrPubkeys(std::vector<std::string> input) {
  std::vector<SchnorrPubkey> output;
  for (int i = 0; i < input.size(); i++) {
    output.push_back(SchnorrPubkey(input[i]));
  }
  return output;
}

std::vector<SchnorrSignature>
DlcTransactionsApi::ParseSchnorrSignatures(std::vector<std::string> input) {
  std::vector<SchnorrSignature> output;
  for (int i = 0; i < input.size(); i++) {
    output.push_back(SchnorrSignature(input[i]));
  }
  return output;
}

std::vector<ByteData256>
DlcTransactionsApi::HashMessages(std::vector<std::string> input) {
  std::vector<ByteData256> output(input.size());
  auto tagHash = HashUtil::Sha256("DLC/oracle/attestation/v0").GetBytes();

  for (int i = 0; i < input.size(); i++) {
    std::vector<uint8_t> toHash;
    toHash.reserve(tagHash.size() + tagHash.size() + input[i].size());
    toHash.insert(toHash.end(), tagHash.begin(), tagHash.end());
    toHash.insert(toHash.end(), tagHash.begin(), tagHash.end());
    toHash.insert(toHash.end(), input[i].begin(), input[i].end());

    output[i] = HashUtil::Sha256(toHash);
  }
  return output;
}

std::vector<std::vector<ByteData256>>
DlcTransactionsApi::HashMessages(std::vector<MessagesStruct> input) {
  std::vector<std::vector<ByteData256>> output(input.size());
  for (int i = 0; i < input.size(); i++) {
    output[i] = HashMessages(input[i].messages);
  }
  return output;
}

CreateCetAdaptorSignatureResponseStruct
DlcTransactionsApi::CreateCetAdaptorSignature(
  const CreateCetAdaptorSignatureRequestStruct &request) {
  auto call_func = [](const CreateCetAdaptorSignatureRequestStruct &request)
    -> CreateCetAdaptorSignatureResponseStruct {
    CreateCetAdaptorSignatureResponseStruct response;
    TransactionController cet(request.cet_hex);
    Privkey privkey(request.privkey);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    SchnorrPubkey oracle_pubkey(request.oracle_pubkey);
    auto oracle_r_values = ParseSchnorrPubkeys(request.oracle_r_values);

    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
      Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto fund_script = DlcManager::CreateFundTxLockingScript(
      local_fund_pubkey, remote_fund_pubkey);

    auto hashed_msgs = HashMessages(request.messages);

    auto adaptor_pair = DlcManager::CreateCetAdaptorSignature(
      cet, oracle_pubkey, oracle_r_values, privkey, fund_script,
      fund_input_amount, hashed_msgs);
    response.signature = adaptor_pair.signature.GetData().GetHex();
    response.proof = adaptor_pair.proof.GetData().GetHex();
    return response;
  };
  CreateCetAdaptorSignatureResponseStruct result;
  result = ExecuteStructApi<
    CreateCetAdaptorSignatureRequestStruct,
    CreateCetAdaptorSignatureResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateCetAdaptorSignaturesResponseStruct
DlcTransactionsApi::CreateCetAdaptorSignatures(
  const CreateCetAdaptorSignaturesRequestStruct &request) {
  auto call_func = [](const CreateCetAdaptorSignaturesRequestStruct &request)
    -> CreateCetAdaptorSignaturesResponseStruct {
    CreateCetAdaptorSignaturesResponseStruct response;
    std::vector<TransactionController> cets;
    cets.reserve(request.cets_hex.size());
    SchnorrPubkey oracle_pubkey(request.oracle_pubkey);
    auto oracle_r_values = ParseSchnorrPubkeys(request.oracle_r_values);

    for (auto cet_hex : request.cets_hex) {
      cets.push_back(TransactionController(cet_hex));
    }

    auto hashed_messages = HashMessages(request.messages_list);

    Privkey privkey(request.privkey);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    auto fund_script = DlcManager::CreateFundTxLockingScript(
      local_fund_pubkey, remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
      Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto adaptor_pairs = DlcManager::CreateCetAdaptorSignatures(
      cets, oracle_pubkey, oracle_r_values, privkey, fund_script,
      fund_input_amount, hashed_messages);
    response.adaptor_pairs.reserve(adaptor_pairs.size());

    for (auto pair : adaptor_pairs) {
      AdaptorPairStruct pair_struct;
      pair_struct.signature = pair.signature.GetData().GetHex();
      pair_struct.proof = pair.proof.GetData().GetHex();
      response.adaptor_pairs.push_back(pair_struct);
    }

    return response;
  };
  CreateCetAdaptorSignaturesResponseStruct result;
  result = ExecuteStructApi<
    CreateCetAdaptorSignaturesRequestStruct,
    CreateCetAdaptorSignaturesResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

SignCetResponseStruct
DlcTransactionsApi::SignCet(const SignCetRequestStruct &request) {
  auto call_func =
    [](const SignCetRequestStruct &request) -> SignCetResponseStruct {
    SignCetResponseStruct response;
    TransactionController cet(request.cet_hex);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    AdaptorSignature adaptor_signature(request.adaptor_signature);
    auto oracle_signatures = ParseSchnorrSignatures(request.oracle_signatures);
    Privkey privkey(request.fund_privkey);
    auto fund_script = DlcManager::CreateFundTxLockingScript(
      local_fund_pubkey, remote_fund_pubkey);
    Txid fund_tx_id(request.fund_tx_id);
    auto fund_amount = Amount::CreateBySatoshiAmount(request.fund_input_amount);

    DlcManager::SignCet(
      &cet, adaptor_signature, oracle_signatures, privkey, fund_script,
      fund_tx_id, request.fund_vout, fund_amount);
    response.hex = cet.GetHex();
    return response;
  };
  SignCetResponseStruct result;
  result = ExecuteStructApi<SignCetRequestStruct, SignCetResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyCetAdaptorSignaturesResponseStruct
DlcTransactionsApi::VerifyCetAdaptorSignatures(
  const VerifyCetAdaptorSignaturesRequestStruct &request) {
  auto call_func = [](const VerifyCetAdaptorSignaturesRequestStruct &request)
    -> VerifyCetAdaptorSignaturesResponseStruct {
    VerifyCetAdaptorSignaturesResponseStruct response;
    size_t nb = request.cets_hex.size();
    if (
      nb != request.adaptor_pairs.size() ||
      nb != request.messages_list.size()) {
      throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Number of transactions and number of signatures differs.");
    }

    std::vector<TransactionController> cets;
    std::vector<AdaptorPair> adaptor_pairs;
    std::vector<std::vector<ByteData256>> msgs;
    cets.reserve(nb);
    adaptor_pairs.reserve(nb);
    msgs.reserve(nb);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    SchnorrPubkey oracle_pubkey(request.oracle_pubkey);
    auto oracle_r_values = ParseSchnorrPubkeys(request.oracle_r_values);
    auto pubkey =
      request.verify_remote ? remote_fund_pubkey : local_fund_pubkey;
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
      Amount::CreateBySatoshiAmount(request.fund_input_amount);

    for (size_t i = 0; i < nb; i++) {
      cets.push_back(TransactionController(request.cets_hex[i]));
      adaptor_pairs.push_back(
        {AdaptorSignature(request.adaptor_pairs[i].signature),
         AdaptorProof(request.adaptor_pairs[i].proof)});
      msgs.push_back(HashMessages(request.messages_list[i].messages));
    }

    auto fund_script = DlcManager::CreateFundTxLockingScript(
      local_fund_pubkey, remote_fund_pubkey);

    response.valid = DlcManager::VerifyCetAdaptorSignatures(
      cets, adaptor_pairs, msgs, pubkey, oracle_pubkey, oracle_r_values,
      fund_script, fund_input_amount);
    return response;
  };
  VerifyCetAdaptorSignaturesResponseStruct result;
  result = ExecuteStructApi<
    VerifyCetAdaptorSignaturesRequestStruct,
    VerifyCetAdaptorSignaturesResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyCetAdaptorSignatureResponseStruct
DlcTransactionsApi::VerifyCetAdaptorSignature(
  const VerifyCetAdaptorSignatureRequestStruct &request) {
  auto call_func = [](const VerifyCetAdaptorSignatureRequestStruct &request)
    -> VerifyCetAdaptorSignatureResponseStruct {
    VerifyCetAdaptorSignatureResponseStruct response;
    TransactionController cet(request.cet_hex);
    AdaptorSignature adaptor_signature(request.adaptor_signature);
    AdaptorProof adaptor_proof(request.adaptor_proof);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    SchnorrPubkey oracle_pubkey(request.oracle_pubkey);
    auto pubkey =
      request.verify_remote ? remote_fund_pubkey : local_fund_pubkey;
    auto oracle_r_values = ParseSchnorrPubkeys(request.oracle_r_values);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
      Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto fund_script = DlcManager::CreateFundTxLockingScript(
      local_fund_pubkey, remote_fund_pubkey);
    auto msg = HashMessages(request.messages);

    response.valid = DlcManager::VerifyCetAdaptorSignature(
      {adaptor_signature, adaptor_proof}, cet, pubkey, oracle_pubkey,
      oracle_r_values, fund_script, fund_input_amount, msg);
    return response;
  };
  VerifyCetAdaptorSignatureResponseStruct result;
  result = ExecuteStructApi<
    VerifyCetAdaptorSignatureRequestStruct,
    VerifyCetAdaptorSignatureResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

GetRawRefundTxSignatureResponseStruct
DlcTransactionsApi::GetRawRefundTxSignature(
  const GetRawRefundTxSignatureRequestStruct &request) {
  auto call_func = [](const GetRawRefundTxSignatureRequestStruct &request)
    -> GetRawRefundTxSignatureResponseStruct {
    GetRawRefundTxSignatureResponseStruct response;
    TransactionController refund_tx(request.refund_tx_hex);
    Privkey privkey(request.privkey);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
      Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto signature = DlcManager::GetRawRefundTxSignature(
      refund_tx, privkey, local_fund_pubkey, remote_fund_pubkey,
      fund_input_amount, fund_txid, request.fund_vout);
    response.hex = signature.GetHex();
    return response;
  };
  GetRawRefundTxSignatureResponseStruct result;
  result = ExecuteStructApi<
    GetRawRefundTxSignatureRequestStruct,
    GetRawRefundTxSignatureResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

AddSignaturesToRefundTxResponseStruct
DlcTransactionsApi::AddSignaturesToRefundTx(
  const AddSignaturesToRefundTxRequestStruct &request) {
  auto call_func = [](const AddSignaturesToRefundTxRequestStruct &request)
    -> AddSignaturesToRefundTxResponseStruct {
    AddSignaturesToRefundTxResponseStruct response;
    TransactionController refund_tx(request.refund_tx_hex);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto signatures_str = request.signatures;
    std::vector<ByteData> signatures(request.signatures.size());

    for (int i = 0; i < signatures_str.size(); i++) {
      signatures[i] = ByteData(signatures_str[i]);
    }

    DlcManager::AddSignaturesToRefundTx(
      &refund_tx, local_fund_pubkey, remote_fund_pubkey, signatures, fund_txid,
      request.fund_vout);
    response.hex = refund_tx.GetHex();
    return response;
  };
  AddSignaturesToRefundTxResponseStruct result;
  result = ExecuteStructApi<
    AddSignaturesToRefundTxRequestStruct,
    AddSignaturesToRefundTxResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyRefundTxSignatureResponseStruct
DlcTransactionsApi::VerifyRefundTxSignature(
  const VerifyRefundTxSignatureRequestStruct &request) {
  auto call_func = [](const VerifyRefundTxSignatureRequestStruct &request)
    -> VerifyRefundTxSignatureResponseStruct {
    VerifyRefundTxSignatureResponseStruct response;
    TransactionController refund_tx(request.refund_tx_hex);
    ByteData signature(request.signature);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
      Amount::CreateBySatoshiAmount(request.fund_input_amount);

    response.valid = DlcManager::VerifyRefundTxSignature(
      refund_tx, signature, local_fund_pubkey, remote_fund_pubkey,
      fund_input_amount, request.verify_remote, fund_txid, request.fund_vout);
    return response;
  };
  VerifyRefundTxSignatureResponseStruct result;
  result = ExecuteStructApi<
    VerifyRefundTxSignatureRequestStruct,
    VerifyRefundTxSignatureResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateSplicedDlcTransactionsResponseStruct
DlcTransactionsApi::CreateSplicedDlcTransactions(
  const CreateSplicedDlcTransactionsRequestStruct &request) {
  auto call_func = [](const CreateSplicedDlcTransactionsRequestStruct &request)
    -> CreateSplicedDlcTransactionsResponseStruct {
    CreateSplicedDlcTransactionsResponseStruct response;

    // Parse outcomes
    std::vector<DlcOutcome> outcomes;
    for (auto payout : request.payouts) {
      auto local_payout = Amount::CreateBySatoshiAmount(payout.local);
      auto remote_payout = Amount::CreateBySatoshiAmount(payout.remote);
      outcomes.push_back({local_payout, remote_payout});
    }

    // Parse local inputs
    std::vector<TxInputInfo> local_inputs;
    for (auto input_request : request.local_inputs) {
      local_inputs.push_back(ParseTxInRequest(input_request));
    }

    // Parse local DLC inputs
    std::vector<DlcInputInfo> local_dlc_inputs;
    for (auto dlc_input_request : request.local_dlc_inputs) {
      local_dlc_inputs.push_back(ParseDlcInputRequest(dlc_input_request));
    }

    // Parse remote inputs
    std::vector<TxInputInfo> remote_inputs;
    for (auto input_request : request.remote_inputs) {
      remote_inputs.push_back(ParseTxInRequest(input_request));
    }

    // Parse remote DLC inputs
    std::vector<DlcInputInfo> remote_dlc_inputs;
    for (auto dlc_input_request : request.remote_dlc_inputs) {
      remote_dlc_inputs.push_back(ParseDlcInputRequest(dlc_input_request));
    }

    // Create PartyParams
    cfd::dlc::PartyParams local_params;
    local_params.fund_pubkey = Pubkey(request.local_fund_pubkey);
    local_params.change_script_pubkey =
      Script(request.local_change_script_pubkey);
    local_params.final_script_pubkey =
      Script(request.local_final_script_pubkey);
    local_params.inputs_info = local_inputs;
    local_params.dlc_inputs_info = local_dlc_inputs;
    local_params.input_amount =
      Amount::CreateBySatoshiAmount(request.local_input_amount);
    local_params.collateral =
      Amount::CreateBySatoshiAmount(request.local_collateral_amount);
    local_params.payout_serial_id = request.local_payout_serial_id;
    local_params.change_serial_id = request.local_change_serial_id;

    cfd::dlc::PartyParams remote_params;
    remote_params.fund_pubkey = Pubkey(request.remote_fund_pubkey);
    remote_params.change_script_pubkey =
      Script(request.remote_change_script_pubkey);
    remote_params.final_script_pubkey =
      Script(request.remote_final_script_pubkey);
    remote_params.inputs_info = remote_inputs;
    remote_params.dlc_inputs_info = remote_dlc_inputs;
    remote_params.input_amount =
      Amount::CreateBySatoshiAmount(request.remote_input_amount);
    remote_params.collateral =
      Amount::CreateBySatoshiAmount(request.remote_collateral_amount);
    remote_params.payout_serial_id = request.remote_payout_serial_id;
    remote_params.change_serial_id = request.remote_change_serial_id;

    // Create optional parameters
    Address option_dest =
      request.option_dest.empty() ? Address() : Address(request.option_dest);
    Amount option_premium =
      Amount::CreateBySatoshiAmount(request.option_premium);

    // Create spliced DLC transactions
    auto dlc_transactions = DlcManager::CreateSplicedDlcTransactions(
      outcomes, local_params, remote_params, request.refund_locktime,
      request.fee_rate, option_dest, option_premium, request.fund_lock_time,
      request.cet_lock_time, request.fund_output_serial_id);

    // Set response values
    response.fund_tx_hex = dlc_transactions.fund_transaction.GetHex();
    response.refund_tx_hex = dlc_transactions.refund_transaction.GetHex();
    for (auto cet : dlc_transactions.cets) {
      response.cets_hex.push_back(cet.GetHex());
    }

    return response;
  };

  CreateSplicedDlcTransactionsResponseStruct result;
  result = ExecuteStructApi<
    CreateSplicedDlcTransactionsRequestStruct,
    CreateSplicedDlcTransactionsResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

SignDlcFundingInputResponseStruct DlcTransactionsApi::SignDlcFundingInput(
  const SignDlcFundingInputRequestStruct &request) {
  auto call_func = [](const SignDlcFundingInputRequestStruct &request)
    -> SignDlcFundingInputResponseStruct {
    SignDlcFundingInputResponseStruct response;

    auto fund_transaction = TransactionController(request.fund_tx_hex);

    // Create DLC input info
    DlcInputInfo dlc_input;
    dlc_input.fund_txid = Txid(request.fund_txid);
    dlc_input.fund_vout = request.fund_vout;
    dlc_input.fund_amount = Amount::CreateBySatoshiAmount(request.fund_amount);
    dlc_input.local_fund_pubkey = Pubkey(request.local_fund_pubkey);
    dlc_input.remote_fund_pubkey = Pubkey(request.remote_fund_pubkey);

    auto local_privkey = Privkey(request.local_privkey);
    auto remote_signature = ByteData(request.remote_signature);

    DlcManager::SignDlcFundingInput(
      &fund_transaction, dlc_input, local_privkey, remote_signature);

    response.hex = fund_transaction.GetHex();
    return response;
  };

  SignDlcFundingInputResponseStruct result;
  result = ExecuteStructApi<
    SignDlcFundingInputRequestStruct, SignDlcFundingInputResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

GetRawDlcFundingInputSignatureResponseStruct
DlcTransactionsApi::GetRawDlcFundingInputSignature(
  const GetRawDlcFundingInputSignatureRequestStruct &request) {
  auto call_func =
    [](const GetRawDlcFundingInputSignatureRequestStruct &request)
    -> GetRawDlcFundingInputSignatureResponseStruct {
    GetRawDlcFundingInputSignatureResponseStruct response;

    auto fund_transaction = TransactionController(request.fund_tx_hex);

    // Create DLC input info
    DlcInputInfo dlc_input;
    dlc_input.fund_txid = Txid(request.fund_txid);
    dlc_input.fund_vout = request.fund_vout;
    dlc_input.fund_amount = Amount::CreateBySatoshiAmount(request.fund_amount);
    dlc_input.local_fund_pubkey = Pubkey(request.local_fund_pubkey);
    dlc_input.remote_fund_pubkey = Pubkey(request.remote_fund_pubkey);

    auto privkey = Privkey(request.privkey);

    auto signature = DlcManager::GetRawDlcFundingInputSignature(
      fund_transaction, dlc_input, privkey);

    response.hex = signature.GetHex();
    return response;
  };

  GetRawDlcFundingInputSignatureResponseStruct result;
  result = ExecuteStructApi<
    GetRawDlcFundingInputSignatureRequestStruct,
    GetRawDlcFundingInputSignatureResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyDlcFundingInputSignatureResponseStruct
DlcTransactionsApi::VerifyDlcFundingInputSignature(
  const VerifyDlcFundingInputSignatureRequestStruct &request) {
  auto call_func =
    [](const VerifyDlcFundingInputSignatureRequestStruct &request)
    -> VerifyDlcFundingInputSignatureResponseStruct {
    VerifyDlcFundingInputSignatureResponseStruct response;

    auto fund_transaction = TransactionController(request.fund_tx_hex);

    // Create DLC input info
    DlcInputInfo dlc_input;
    dlc_input.fund_txid = Txid(request.fund_txid);
    dlc_input.fund_vout = request.fund_vout;
    dlc_input.fund_amount = Amount::CreateBySatoshiAmount(request.fund_amount);
    dlc_input.local_fund_pubkey = Pubkey(request.local_fund_pubkey);
    dlc_input.remote_fund_pubkey = Pubkey(request.remote_fund_pubkey);

    auto signature = ByteData(request.signature);
    auto pubkey = Pubkey(request.pubkey);

    response.valid = DlcManager::VerifyDlcFundingInputSignature(
      fund_transaction, dlc_input, signature, pubkey);

    return response;
  };

  VerifyDlcFundingInputSignatureResponseStruct result;
  result = ExecuteStructApi<
    VerifyDlcFundingInputSignatureRequestStruct,
    VerifyDlcFundingInputSignatureResponseStruct>(
    request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd
