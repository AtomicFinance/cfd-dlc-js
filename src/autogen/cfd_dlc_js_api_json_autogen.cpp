// Copyright 2020 CryptoGarage
/**
 * @file cfd_dlc_js_api_json_autogen.cpp
 *
 * @brief JSON mapping file (auto generate)
 */
#include <set>
#include <string>
#include <vector>

#include "cfd_dlc_js_api_json_autogen.h"  // NOLINT

namespace cfd {
namespace dlc {
namespace js {
namespace api {
namespace json {

using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// clang-format off
// @formatter:off

// ------------------------------------------------------------------------
// AdaptorPair
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AdaptorPair>
  AdaptorPair::json_mapper;
std::vector<std::string> AdaptorPair::item_list;

void AdaptorPair::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AdaptorPair> func_table;  // NOLINT

  func_table = {
    AdaptorPair::GetSignatureString,
    AdaptorPair::SetSignatureString,
    AdaptorPair::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    AdaptorPair::GetProofString,
    AdaptorPair::SetProofString,
    AdaptorPair::GetProofFieldType,
  };
  json_mapper.emplace("proof", func_table);
  item_list.push_back("proof");
}

void AdaptorPair::ConvertFromStruct(
    const AdaptorPairStruct& data) {
  signature_ = data.signature;
  proof_ = data.proof;
  ignore_items = data.ignore_items;
}

AdaptorPairStruct AdaptorPair::ConvertToStruct() const {  // NOLINT
  AdaptorPairStruct result;
  result.signature = signature_;
  result.proof = proof_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DlcInputInfoRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DlcInputInfoRequest>
  DlcInputInfoRequest::json_mapper;
std::vector<std::string> DlcInputInfoRequest::item_list;

void DlcInputInfoRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DlcInputInfoRequest> func_table;  // NOLINT

  func_table = {
    DlcInputInfoRequest::GetFundTxidString,
    DlcInputInfoRequest::SetFundTxidString,
    DlcInputInfoRequest::GetFundTxidFieldType,
  };
  json_mapper.emplace("fundTxid", func_table);
  item_list.push_back("fundTxid");
  func_table = {
    DlcInputInfoRequest::GetFundVoutString,
    DlcInputInfoRequest::SetFundVoutString,
    DlcInputInfoRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    DlcInputInfoRequest::GetFundAmountString,
    DlcInputInfoRequest::SetFundAmountString,
    DlcInputInfoRequest::GetFundAmountFieldType,
  };
  json_mapper.emplace("fundAmount", func_table);
  item_list.push_back("fundAmount");
  func_table = {
    DlcInputInfoRequest::GetLocalFundPubkeyString,
    DlcInputInfoRequest::SetLocalFundPubkeyString,
    DlcInputInfoRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    DlcInputInfoRequest::GetRemoteFundPubkeyString,
    DlcInputInfoRequest::SetRemoteFundPubkeyString,
    DlcInputInfoRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    DlcInputInfoRequest::GetMaxWitnessLengthString,
    DlcInputInfoRequest::SetMaxWitnessLengthString,
    DlcInputInfoRequest::GetMaxWitnessLengthFieldType,
  };
  json_mapper.emplace("maxWitnessLength", func_table);
  item_list.push_back("maxWitnessLength");
  func_table = {
    DlcInputInfoRequest::GetInputSerialIdString,
    DlcInputInfoRequest::SetInputSerialIdString,
    DlcInputInfoRequest::GetInputSerialIdFieldType,
  };
  json_mapper.emplace("inputSerialId", func_table);
  item_list.push_back("inputSerialId");
}

void DlcInputInfoRequest::ConvertFromStruct(
    const DlcInputInfoRequestStruct& data) {
  fund_txid_ = data.fund_txid;
  fund_vout_ = data.fund_vout;
  fund_amount_ = data.fund_amount;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  max_witness_length_ = data.max_witness_length;
  input_serial_id_ = data.input_serial_id;
  ignore_items = data.ignore_items;
}

DlcInputInfoRequestStruct DlcInputInfoRequest::ConvertToStruct() const {  // NOLINT
  DlcInputInfoRequestStruct result;
  result.fund_txid = fund_txid_;
  result.fund_vout = fund_vout_;
  result.fund_amount = fund_amount_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.max_witness_length = max_witness_length_;
  result.input_serial_id = input_serial_id_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// Messages
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<Messages>
  Messages::json_mapper;
std::vector<std::string> Messages::item_list;

void Messages::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<Messages> func_table;  // NOLINT

  func_table = {
    Messages::GetMessagesString,
    Messages::SetMessagesString,
    Messages::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
}

void Messages::ConvertFromStruct(
    const MessagesStruct& data) {
  messages_.ConvertFromStruct(data.messages);
  ignore_items = data.ignore_items;
}

MessagesStruct Messages::ConvertToStruct() const {  // NOLINT
  MessagesStruct result;
  result.messages = messages_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PayoutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PayoutRequest>
  PayoutRequest::json_mapper;
std::vector<std::string> PayoutRequest::item_list;

void PayoutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PayoutRequest> func_table;  // NOLINT

  func_table = {
    PayoutRequest::GetLocalString,
    PayoutRequest::SetLocalString,
    PayoutRequest::GetLocalFieldType,
  };
  json_mapper.emplace("local", func_table);
  item_list.push_back("local");
  func_table = {
    PayoutRequest::GetRemoteString,
    PayoutRequest::SetRemoteString,
    PayoutRequest::GetRemoteFieldType,
  };
  json_mapper.emplace("remote", func_table);
  item_list.push_back("remote");
}

void PayoutRequest::ConvertFromStruct(
    const PayoutRequestStruct& data) {
  local_ = data.local;
  remote_ = data.remote;
  ignore_items = data.ignore_items;
}

PayoutRequestStruct PayoutRequest::ConvertToStruct() const {  // NOLINT
  PayoutRequestStruct result;
  result.local = local_;
  result.remote = remote_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TxInInfoRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TxInInfoRequest>
  TxInInfoRequest::json_mapper;
std::vector<std::string> TxInInfoRequest::item_list;

void TxInInfoRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TxInInfoRequest> func_table;  // NOLINT

  func_table = {
    TxInInfoRequest::GetTxidString,
    TxInInfoRequest::SetTxidString,
    TxInInfoRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    TxInInfoRequest::GetVoutString,
    TxInInfoRequest::SetVoutString,
    TxInInfoRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    TxInInfoRequest::GetRedeemScriptString,
    TxInInfoRequest::SetRedeemScriptString,
    TxInInfoRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    TxInInfoRequest::GetMaxWitnessLengthString,
    TxInInfoRequest::SetMaxWitnessLengthString,
    TxInInfoRequest::GetMaxWitnessLengthFieldType,
  };
  json_mapper.emplace("maxWitnessLength", func_table);
  item_list.push_back("maxWitnessLength");
  func_table = {
    TxInInfoRequest::GetInputSerialIdString,
    TxInInfoRequest::SetInputSerialIdString,
    TxInInfoRequest::GetInputSerialIdFieldType,
  };
  json_mapper.emplace("inputSerialId", func_table);
  item_list.push_back("inputSerialId");
}

void TxInInfoRequest::ConvertFromStruct(
    const TxInInfoRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  redeem_script_ = data.redeem_script;
  max_witness_length_ = data.max_witness_length;
  input_serial_id_ = data.input_serial_id;
  ignore_items = data.ignore_items;
}

TxInInfoRequestStruct TxInInfoRequest::ConvertToStruct() const {  // NOLINT
  TxInInfoRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.redeem_script = redeem_script_;
  result.max_witness_length = max_witness_length_;
  result.input_serial_id = input_serial_id_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TxOutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TxOutRequest>
  TxOutRequest::json_mapper;
std::vector<std::string> TxOutRequest::item_list;

void TxOutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TxOutRequest> func_table;  // NOLINT

  func_table = {
    TxOutRequest::GetAmountString,
    TxOutRequest::SetAmountString,
    TxOutRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    TxOutRequest::GetAddressString,
    TxOutRequest::SetAddressString,
    TxOutRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
}

void TxOutRequest::ConvertFromStruct(
    const TxOutRequestStruct& data) {
  amount_ = data.amount;
  address_ = data.address;
  ignore_items = data.ignore_items;
}

TxOutRequestStruct TxOutRequest::ConvertToStruct() const {  // NOLINT
  TxOutRequestStruct result;
  result.amount = amount_;
  result.address = address_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignatureToFundTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignatureToFundTransactionRequest>
  AddSignatureToFundTransactionRequest::json_mapper;
std::vector<std::string> AddSignatureToFundTransactionRequest::item_list;

void AddSignatureToFundTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignatureToFundTransactionRequest> func_table;  // NOLINT

  func_table = {
    AddSignatureToFundTransactionRequest::GetFundTxHexString,
    AddSignatureToFundTransactionRequest::SetFundTxHexString,
    AddSignatureToFundTransactionRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    AddSignatureToFundTransactionRequest::GetSignatureString,
    AddSignatureToFundTransactionRequest::SetSignatureString,
    AddSignatureToFundTransactionRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    AddSignatureToFundTransactionRequest::GetPrevTxIdString,
    AddSignatureToFundTransactionRequest::SetPrevTxIdString,
    AddSignatureToFundTransactionRequest::GetPrevTxIdFieldType,
  };
  json_mapper.emplace("prevTxId", func_table);
  item_list.push_back("prevTxId");
  func_table = {
    AddSignatureToFundTransactionRequest::GetPrevVoutString,
    AddSignatureToFundTransactionRequest::SetPrevVoutString,
    AddSignatureToFundTransactionRequest::GetPrevVoutFieldType,
  };
  json_mapper.emplace("prevVout", func_table);
  item_list.push_back("prevVout");
  func_table = {
    AddSignatureToFundTransactionRequest::GetPubkeyString,
    AddSignatureToFundTransactionRequest::SetPubkeyString,
    AddSignatureToFundTransactionRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void AddSignatureToFundTransactionRequest::ConvertFromStruct(
    const AddSignatureToFundTransactionRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  signature_ = data.signature;
  prev_tx_id_ = data.prev_tx_id;
  prev_vout_ = data.prev_vout;
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

AddSignatureToFundTransactionRequestStruct AddSignatureToFundTransactionRequest::ConvertToStruct() const {  // NOLINT
  AddSignatureToFundTransactionRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.signature = signature_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_vout = prev_vout_;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignatureToFundTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignatureToFundTransactionResponse>
  AddSignatureToFundTransactionResponse::json_mapper;
std::vector<std::string> AddSignatureToFundTransactionResponse::item_list;

void AddSignatureToFundTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignatureToFundTransactionResponse> func_table;  // NOLINT

  func_table = {
    AddSignatureToFundTransactionResponse::GetHexString,
    AddSignatureToFundTransactionResponse::SetHexString,
    AddSignatureToFundTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddSignatureToFundTransactionResponse::ConvertFromStruct(
    const AddSignatureToFundTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddSignatureToFundTransactionResponseStruct AddSignatureToFundTransactionResponse::ConvertToStruct() const {  // NOLINT
  AddSignatureToFundTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignaturesToRefundTxRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignaturesToRefundTxRequest>
  AddSignaturesToRefundTxRequest::json_mapper;
std::vector<std::string> AddSignaturesToRefundTxRequest::item_list;

void AddSignaturesToRefundTxRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignaturesToRefundTxRequest> func_table;  // NOLINT

  func_table = {
    AddSignaturesToRefundTxRequest::GetRefundTxHexString,
    AddSignaturesToRefundTxRequest::SetRefundTxHexString,
    AddSignaturesToRefundTxRequest::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
  func_table = {
    AddSignaturesToRefundTxRequest::GetSignaturesString,
    AddSignaturesToRefundTxRequest::SetSignaturesString,
    AddSignaturesToRefundTxRequest::GetSignaturesFieldType,
  };
  json_mapper.emplace("signatures", func_table);
  item_list.push_back("signatures");
  func_table = {
    AddSignaturesToRefundTxRequest::GetFundTxIdString,
    AddSignaturesToRefundTxRequest::SetFundTxIdString,
    AddSignaturesToRefundTxRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    AddSignaturesToRefundTxRequest::GetFundVoutString,
    AddSignaturesToRefundTxRequest::SetFundVoutString,
    AddSignaturesToRefundTxRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    AddSignaturesToRefundTxRequest::GetLocalFundPubkeyString,
    AddSignaturesToRefundTxRequest::SetLocalFundPubkeyString,
    AddSignaturesToRefundTxRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    AddSignaturesToRefundTxRequest::GetRemoteFundPubkeyString,
    AddSignaturesToRefundTxRequest::SetRemoteFundPubkeyString,
    AddSignaturesToRefundTxRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
}

void AddSignaturesToRefundTxRequest::ConvertFromStruct(
    const AddSignaturesToRefundTxRequestStruct& data) {
  refund_tx_hex_ = data.refund_tx_hex;
  signatures_.ConvertFromStruct(data.signatures);
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  ignore_items = data.ignore_items;
}

AddSignaturesToRefundTxRequestStruct AddSignaturesToRefundTxRequest::ConvertToStruct() const {  // NOLINT
  AddSignaturesToRefundTxRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.signatures = signatures_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignaturesToRefundTxResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignaturesToRefundTxResponse>
  AddSignaturesToRefundTxResponse::json_mapper;
std::vector<std::string> AddSignaturesToRefundTxResponse::item_list;

void AddSignaturesToRefundTxResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignaturesToRefundTxResponse> func_table;  // NOLINT

  func_table = {
    AddSignaturesToRefundTxResponse::GetHexString,
    AddSignaturesToRefundTxResponse::SetHexString,
    AddSignaturesToRefundTxResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddSignaturesToRefundTxResponse::ConvertFromStruct(
    const AddSignaturesToRefundTxResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddSignaturesToRefundTxResponseStruct AddSignaturesToRefundTxResponse::ConvertToStruct() const {  // NOLINT
  AddSignaturesToRefundTxResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateBatchDlcTransactionsRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateBatchDlcTransactionsRequest>
  CreateBatchDlcTransactionsRequest::json_mapper;
std::vector<std::string> CreateBatchDlcTransactionsRequest::item_list;

void CreateBatchDlcTransactionsRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateBatchDlcTransactionsRequest> func_table;  // NOLINT

  func_table = {
    CreateBatchDlcTransactionsRequest::GetLocalPayoutsString,
    CreateBatchDlcTransactionsRequest::SetLocalPayoutsString,
    CreateBatchDlcTransactionsRequest::GetLocalPayoutsFieldType,
  };
  json_mapper.emplace("localPayouts", func_table);
  item_list.push_back("localPayouts");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRemotePayoutsString,
    CreateBatchDlcTransactionsRequest::SetRemotePayoutsString,
    CreateBatchDlcTransactionsRequest::GetRemotePayoutsFieldType,
  };
  json_mapper.emplace("remotePayouts", func_table);
  item_list.push_back("remotePayouts");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetNumPayoutsString,
    CreateBatchDlcTransactionsRequest::SetNumPayoutsString,
    CreateBatchDlcTransactionsRequest::GetNumPayoutsFieldType,
  };
  json_mapper.emplace("numPayouts", func_table);
  item_list.push_back("numPayouts");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetLocalFundPubkeysString,
    CreateBatchDlcTransactionsRequest::SetLocalFundPubkeysString,
    CreateBatchDlcTransactionsRequest::GetLocalFundPubkeysFieldType,
  };
  json_mapper.emplace("localFundPubkeys", func_table);
  item_list.push_back("localFundPubkeys");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetLocalFinalScriptPubkeysString,
    CreateBatchDlcTransactionsRequest::SetLocalFinalScriptPubkeysString,
    CreateBatchDlcTransactionsRequest::GetLocalFinalScriptPubkeysFieldType,
  };
  json_mapper.emplace("localFinalScriptPubkeys", func_table);
  item_list.push_back("localFinalScriptPubkeys");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRemoteFundPubkeysString,
    CreateBatchDlcTransactionsRequest::SetRemoteFundPubkeysString,
    CreateBatchDlcTransactionsRequest::GetRemoteFundPubkeysFieldType,
  };
  json_mapper.emplace("remoteFundPubkeys", func_table);
  item_list.push_back("remoteFundPubkeys");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRemoteFinalScriptPubkeysString,
    CreateBatchDlcTransactionsRequest::SetRemoteFinalScriptPubkeysString,
    CreateBatchDlcTransactionsRequest::GetRemoteFinalScriptPubkeysFieldType,
  };
  json_mapper.emplace("remoteFinalScriptPubkeys", func_table);
  item_list.push_back("remoteFinalScriptPubkeys");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetLocalInputAmountString,
    CreateBatchDlcTransactionsRequest::SetLocalInputAmountString,
    CreateBatchDlcTransactionsRequest::GetLocalInputAmountFieldType,
  };
  json_mapper.emplace("localInputAmount", func_table);
  item_list.push_back("localInputAmount");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetLocalCollateralAmountsString,
    CreateBatchDlcTransactionsRequest::SetLocalCollateralAmountsString,
    CreateBatchDlcTransactionsRequest::GetLocalCollateralAmountsFieldType,
  };
  json_mapper.emplace("localCollateralAmounts", func_table);
  item_list.push_back("localCollateralAmounts");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetLocalPayoutSerialIdsString,
    CreateBatchDlcTransactionsRequest::SetLocalPayoutSerialIdsString,
    CreateBatchDlcTransactionsRequest::GetLocalPayoutSerialIdsFieldType,
  };
  json_mapper.emplace("localPayoutSerialIds", func_table);
  item_list.push_back("localPayoutSerialIds");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetLocalChangeSerialIdString,
    CreateBatchDlcTransactionsRequest::SetLocalChangeSerialIdString,
    CreateBatchDlcTransactionsRequest::GetLocalChangeSerialIdFieldType,
  };
  json_mapper.emplace("localChangeSerialId", func_table);
  item_list.push_back("localChangeSerialId");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRemoteInputAmountString,
    CreateBatchDlcTransactionsRequest::SetRemoteInputAmountString,
    CreateBatchDlcTransactionsRequest::GetRemoteInputAmountFieldType,
  };
  json_mapper.emplace("remoteInputAmount", func_table);
  item_list.push_back("remoteInputAmount");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRemoteCollateralAmountsString,
    CreateBatchDlcTransactionsRequest::SetRemoteCollateralAmountsString,
    CreateBatchDlcTransactionsRequest::GetRemoteCollateralAmountsFieldType,
  };
  json_mapper.emplace("remoteCollateralAmounts", func_table);
  item_list.push_back("remoteCollateralAmounts");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRemotePayoutSerialIdsString,
    CreateBatchDlcTransactionsRequest::SetRemotePayoutSerialIdsString,
    CreateBatchDlcTransactionsRequest::GetRemotePayoutSerialIdsFieldType,
  };
  json_mapper.emplace("remotePayoutSerialIds", func_table);
  item_list.push_back("remotePayoutSerialIds");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRemoteChangeSerialIdString,
    CreateBatchDlcTransactionsRequest::SetRemoteChangeSerialIdString,
    CreateBatchDlcTransactionsRequest::GetRemoteChangeSerialIdFieldType,
  };
  json_mapper.emplace("remoteChangeSerialId", func_table);
  item_list.push_back("remoteChangeSerialId");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRefundLocktimesString,
    CreateBatchDlcTransactionsRequest::SetRefundLocktimesString,
    CreateBatchDlcTransactionsRequest::GetRefundLocktimesFieldType,
  };
  json_mapper.emplace("refundLocktimes", func_table);
  item_list.push_back("refundLocktimes");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetLocalInputsString,
    CreateBatchDlcTransactionsRequest::SetLocalInputsString,
    CreateBatchDlcTransactionsRequest::GetLocalInputsFieldType,
  };
  json_mapper.emplace("localInputs", func_table);
  item_list.push_back("localInputs");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetLocalChangeScriptPubkeyString,
    CreateBatchDlcTransactionsRequest::SetLocalChangeScriptPubkeyString,
    CreateBatchDlcTransactionsRequest::GetLocalChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("localChangeScriptPubkey", func_table);
  item_list.push_back("localChangeScriptPubkey");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRemoteInputsString,
    CreateBatchDlcTransactionsRequest::SetRemoteInputsString,
    CreateBatchDlcTransactionsRequest::GetRemoteInputsFieldType,
  };
  json_mapper.emplace("remoteInputs", func_table);
  item_list.push_back("remoteInputs");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetRemoteChangeScriptPubkeyString,
    CreateBatchDlcTransactionsRequest::SetRemoteChangeScriptPubkeyString,
    CreateBatchDlcTransactionsRequest::GetRemoteChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("remoteChangeScriptPubkey", func_table);
  item_list.push_back("remoteChangeScriptPubkey");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetFeeRateString,
    CreateBatchDlcTransactionsRequest::SetFeeRateString,
    CreateBatchDlcTransactionsRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetCetLockTimeString,
    CreateBatchDlcTransactionsRequest::SetCetLockTimeString,
    CreateBatchDlcTransactionsRequest::GetCetLockTimeFieldType,
  };
  json_mapper.emplace("cetLockTime", func_table);
  item_list.push_back("cetLockTime");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetFundLockTimeString,
    CreateBatchDlcTransactionsRequest::SetFundLockTimeString,
    CreateBatchDlcTransactionsRequest::GetFundLockTimeFieldType,
  };
  json_mapper.emplace("fundLockTime", func_table);
  item_list.push_back("fundLockTime");
  func_table = {
    CreateBatchDlcTransactionsRequest::GetFundOutputSerialIdsString,
    CreateBatchDlcTransactionsRequest::SetFundOutputSerialIdsString,
    CreateBatchDlcTransactionsRequest::GetFundOutputSerialIdsFieldType,
  };
  json_mapper.emplace("fundOutputSerialIds", func_table);
  item_list.push_back("fundOutputSerialIds");
}

void CreateBatchDlcTransactionsRequest::ConvertFromStruct(
    const CreateBatchDlcTransactionsRequestStruct& data) {
  local_payouts_.ConvertFromStruct(data.local_payouts);
  remote_payouts_.ConvertFromStruct(data.remote_payouts);
  num_payouts_.ConvertFromStruct(data.num_payouts);
  local_fund_pubkeys_.ConvertFromStruct(data.local_fund_pubkeys);
  local_final_script_pubkeys_.ConvertFromStruct(
      data.local_final_script_pubkeys);
  remote_fund_pubkeys_.ConvertFromStruct(data.remote_fund_pubkeys);
  remote_final_script_pubkeys_.ConvertFromStruct(
      data.remote_final_script_pubkeys);
  local_input_amount_ = data.local_input_amount;
  local_collateral_amounts_.ConvertFromStruct(data.local_collateral_amounts);
  local_payout_serial_ids_.ConvertFromStruct(data.local_payout_serial_ids);
  local_change_serial_id_ = data.local_change_serial_id;
  remote_input_amount_ = data.remote_input_amount;
  remote_collateral_amounts_.ConvertFromStruct(data.remote_collateral_amounts);
  remote_payout_serial_ids_.ConvertFromStruct(data.remote_payout_serial_ids);
  remote_change_serial_id_ = data.remote_change_serial_id;
  refund_locktimes_.ConvertFromStruct(data.refund_locktimes);
  local_inputs_.ConvertFromStruct(data.local_inputs);
  local_change_script_pubkey_ = data.local_change_script_pubkey;
  remote_inputs_.ConvertFromStruct(data.remote_inputs);
  remote_change_script_pubkey_ = data.remote_change_script_pubkey;
  fee_rate_ = data.fee_rate;
  cet_lock_time_ = data.cet_lock_time;
  fund_lock_time_ = data.fund_lock_time;
  fund_output_serial_ids_.ConvertFromStruct(data.fund_output_serial_ids);
  ignore_items = data.ignore_items;
}

CreateBatchDlcTransactionsRequestStruct CreateBatchDlcTransactionsRequest::ConvertToStruct() const {  // NOLINT
  CreateBatchDlcTransactionsRequestStruct result;
  result.local_payouts = local_payouts_.ConvertToStruct();
  result.remote_payouts = remote_payouts_.ConvertToStruct();
  result.num_payouts = num_payouts_.ConvertToStruct();
  result.local_fund_pubkeys = local_fund_pubkeys_.ConvertToStruct();
  result.local_final_script_pubkeys = local_final_script_pubkeys_.ConvertToStruct();  // NOLINT
  result.remote_fund_pubkeys = remote_fund_pubkeys_.ConvertToStruct();
  result.remote_final_script_pubkeys = remote_final_script_pubkeys_.ConvertToStruct();  // NOLINT
  result.local_input_amount = local_input_amount_;
  result.local_collateral_amounts = local_collateral_amounts_.ConvertToStruct();
  result.local_payout_serial_ids = local_payout_serial_ids_.ConvertToStruct();
  result.local_change_serial_id = local_change_serial_id_;
  result.remote_input_amount = remote_input_amount_;
  result.remote_collateral_amounts = remote_collateral_amounts_.ConvertToStruct();  // NOLINT
  result.remote_payout_serial_ids = remote_payout_serial_ids_.ConvertToStruct();
  result.remote_change_serial_id = remote_change_serial_id_;
  result.refund_locktimes = refund_locktimes_.ConvertToStruct();
  result.local_inputs = local_inputs_.ConvertToStruct();
  result.local_change_script_pubkey = local_change_script_pubkey_;
  result.remote_inputs = remote_inputs_.ConvertToStruct();
  result.remote_change_script_pubkey = remote_change_script_pubkey_;
  result.fee_rate = fee_rate_;
  result.cet_lock_time = cet_lock_time_;
  result.fund_lock_time = fund_lock_time_;
  result.fund_output_serial_ids = fund_output_serial_ids_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateBatchDlcTransactionsResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateBatchDlcTransactionsResponse>
  CreateBatchDlcTransactionsResponse::json_mapper;
std::vector<std::string> CreateBatchDlcTransactionsResponse::item_list;

void CreateBatchDlcTransactionsResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateBatchDlcTransactionsResponse> func_table;  // NOLINT

  func_table = {
    CreateBatchDlcTransactionsResponse::GetFundTxHexString,
    CreateBatchDlcTransactionsResponse::SetFundTxHexString,
    CreateBatchDlcTransactionsResponse::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    CreateBatchDlcTransactionsResponse::GetCetsHexListString,
    CreateBatchDlcTransactionsResponse::SetCetsHexListString,
    CreateBatchDlcTransactionsResponse::GetCetsHexListFieldType,
  };
  json_mapper.emplace("cetsHexList", func_table);
  item_list.push_back("cetsHexList");
  func_table = {
    CreateBatchDlcTransactionsResponse::GetRefundTxHexListString,
    CreateBatchDlcTransactionsResponse::SetRefundTxHexListString,
    CreateBatchDlcTransactionsResponse::GetRefundTxHexListFieldType,
  };
  json_mapper.emplace("refundTxHexList", func_table);
  item_list.push_back("refundTxHexList");
}

void CreateBatchDlcTransactionsResponse::ConvertFromStruct(
    const CreateBatchDlcTransactionsResponseStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  cets_hex_list_.ConvertFromStruct(data.cets_hex_list);
  refund_tx_hex_list_.ConvertFromStruct(data.refund_tx_hex_list);
  ignore_items = data.ignore_items;
}

CreateBatchDlcTransactionsResponseStruct CreateBatchDlcTransactionsResponse::ConvertToStruct() const {  // NOLINT
  CreateBatchDlcTransactionsResponseStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.cets_hex_list = cets_hex_list_.ConvertToStruct();
  result.refund_tx_hex_list = refund_tx_hex_list_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateBatchFundTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateBatchFundTransactionRequest>
  CreateBatchFundTransactionRequest::json_mapper;
std::vector<std::string> CreateBatchFundTransactionRequest::item_list;

void CreateBatchFundTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateBatchFundTransactionRequest> func_table;  // NOLINT

  func_table = {
    CreateBatchFundTransactionRequest::GetLocalPubkeysString,
    CreateBatchFundTransactionRequest::SetLocalPubkeysString,
    CreateBatchFundTransactionRequest::GetLocalPubkeysFieldType,
  };
  json_mapper.emplace("localPubkeys", func_table);
  item_list.push_back("localPubkeys");
  func_table = {
    CreateBatchFundTransactionRequest::GetRemotePubkeysString,
    CreateBatchFundTransactionRequest::SetRemotePubkeysString,
    CreateBatchFundTransactionRequest::GetRemotePubkeysFieldType,
  };
  json_mapper.emplace("remotePubkeys", func_table);
  item_list.push_back("remotePubkeys");
  func_table = {
    CreateBatchFundTransactionRequest::GetOutputAmountsString,
    CreateBatchFundTransactionRequest::SetOutputAmountsString,
    CreateBatchFundTransactionRequest::GetOutputAmountsFieldType,
  };
  json_mapper.emplace("outputAmounts", func_table);
  item_list.push_back("outputAmounts");
  func_table = {
    CreateBatchFundTransactionRequest::GetLocalInputsString,
    CreateBatchFundTransactionRequest::SetLocalInputsString,
    CreateBatchFundTransactionRequest::GetLocalInputsFieldType,
  };
  json_mapper.emplace("localInputs", func_table);
  item_list.push_back("localInputs");
  func_table = {
    CreateBatchFundTransactionRequest::GetLocalChangeString,
    CreateBatchFundTransactionRequest::SetLocalChangeString,
    CreateBatchFundTransactionRequest::GetLocalChangeFieldType,
  };
  json_mapper.emplace("localChange", func_table);
  item_list.push_back("localChange");
  func_table = {
    CreateBatchFundTransactionRequest::GetRemoteInputsString,
    CreateBatchFundTransactionRequest::SetRemoteInputsString,
    CreateBatchFundTransactionRequest::GetRemoteInputsFieldType,
  };
  json_mapper.emplace("remoteInputs", func_table);
  item_list.push_back("remoteInputs");
  func_table = {
    CreateBatchFundTransactionRequest::GetRemoteChangeString,
    CreateBatchFundTransactionRequest::SetRemoteChangeString,
    CreateBatchFundTransactionRequest::GetRemoteChangeFieldType,
  };
  json_mapper.emplace("remoteChange", func_table);
  item_list.push_back("remoteChange");
  func_table = {
    CreateBatchFundTransactionRequest::GetFeeRateString,
    CreateBatchFundTransactionRequest::SetFeeRateString,
    CreateBatchFundTransactionRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CreateBatchFundTransactionRequest::GetLockTimeString,
    CreateBatchFundTransactionRequest::SetLockTimeString,
    CreateBatchFundTransactionRequest::GetLockTimeFieldType,
  };
  json_mapper.emplace("lockTime", func_table);
  item_list.push_back("lockTime");
  func_table = {
    CreateBatchFundTransactionRequest::GetLocalSerialIdString,
    CreateBatchFundTransactionRequest::SetLocalSerialIdString,
    CreateBatchFundTransactionRequest::GetLocalSerialIdFieldType,
  };
  json_mapper.emplace("localSerialId", func_table);
  item_list.push_back("localSerialId");
  func_table = {
    CreateBatchFundTransactionRequest::GetRemoteSerialIdString,
    CreateBatchFundTransactionRequest::SetRemoteSerialIdString,
    CreateBatchFundTransactionRequest::GetRemoteSerialIdFieldType,
  };
  json_mapper.emplace("remoteSerialId", func_table);
  item_list.push_back("remoteSerialId");
  func_table = {
    CreateBatchFundTransactionRequest::GetOutputSerialIdsString,
    CreateBatchFundTransactionRequest::SetOutputSerialIdsString,
    CreateBatchFundTransactionRequest::GetOutputSerialIdsFieldType,
  };
  json_mapper.emplace("outputSerialIds", func_table);
  item_list.push_back("outputSerialIds");
}

void CreateBatchFundTransactionRequest::ConvertFromStruct(
    const CreateBatchFundTransactionRequestStruct& data) {
  local_pubkeys_.ConvertFromStruct(data.local_pubkeys);
  remote_pubkeys_.ConvertFromStruct(data.remote_pubkeys);
  output_amounts_.ConvertFromStruct(data.output_amounts);
  local_inputs_.ConvertFromStruct(data.local_inputs);
  local_change_.ConvertFromStruct(data.local_change);
  remote_inputs_.ConvertFromStruct(data.remote_inputs);
  remote_change_.ConvertFromStruct(data.remote_change);
  fee_rate_ = data.fee_rate;
  lock_time_ = data.lock_time;
  local_serial_id_ = data.local_serial_id;
  remote_serial_id_ = data.remote_serial_id;
  output_serial_ids_.ConvertFromStruct(data.output_serial_ids);
  ignore_items = data.ignore_items;
}

CreateBatchFundTransactionRequestStruct CreateBatchFundTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateBatchFundTransactionRequestStruct result;
  result.local_pubkeys = local_pubkeys_.ConvertToStruct();
  result.remote_pubkeys = remote_pubkeys_.ConvertToStruct();
  result.output_amounts = output_amounts_.ConvertToStruct();
  result.local_inputs = local_inputs_.ConvertToStruct();
  result.local_change = local_change_.ConvertToStruct();
  result.remote_inputs = remote_inputs_.ConvertToStruct();
  result.remote_change = remote_change_.ConvertToStruct();
  result.fee_rate = fee_rate_;
  result.lock_time = lock_time_;
  result.local_serial_id = local_serial_id_;
  result.remote_serial_id = remote_serial_id_;
  result.output_serial_ids = output_serial_ids_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateBatchFundTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateBatchFundTransactionResponse>
  CreateBatchFundTransactionResponse::json_mapper;
std::vector<std::string> CreateBatchFundTransactionResponse::item_list;

void CreateBatchFundTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateBatchFundTransactionResponse> func_table;  // NOLINT

  func_table = {
    CreateBatchFundTransactionResponse::GetHexString,
    CreateBatchFundTransactionResponse::SetHexString,
    CreateBatchFundTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateBatchFundTransactionResponse::ConvertFromStruct(
    const CreateBatchFundTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateBatchFundTransactionResponseStruct CreateBatchFundTransactionResponse::ConvertToStruct() const {  // NOLINT
  CreateBatchFundTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetRequest>
  CreateCetRequest::json_mapper;
std::vector<std::string> CreateCetRequest::item_list;

void CreateCetRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetRequest> func_table;  // NOLINT

  func_table = {
    CreateCetRequest::GetLocalFundPubkeyString,
    CreateCetRequest::SetLocalFundPubkeyString,
    CreateCetRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    CreateCetRequest::GetRemoteFundPubkeyString,
    CreateCetRequest::SetRemoteFundPubkeyString,
    CreateCetRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    CreateCetRequest::GetLocalFinalAddressString,
    CreateCetRequest::SetLocalFinalAddressString,
    CreateCetRequest::GetLocalFinalAddressFieldType,
  };
  json_mapper.emplace("localFinalAddress", func_table);
  item_list.push_back("localFinalAddress");
  func_table = {
    CreateCetRequest::GetRemoteFinalAddressString,
    CreateCetRequest::SetRemoteFinalAddressString,
    CreateCetRequest::GetRemoteFinalAddressFieldType,
  };
  json_mapper.emplace("remoteFinalAddress", func_table);
  item_list.push_back("remoteFinalAddress");
  func_table = {
    CreateCetRequest::GetLocalPayoutString,
    CreateCetRequest::SetLocalPayoutString,
    CreateCetRequest::GetLocalPayoutFieldType,
  };
  json_mapper.emplace("localPayout", func_table);
  item_list.push_back("localPayout");
  func_table = {
    CreateCetRequest::GetRemotePayoutString,
    CreateCetRequest::SetRemotePayoutString,
    CreateCetRequest::GetRemotePayoutFieldType,
  };
  json_mapper.emplace("remotePayout", func_table);
  item_list.push_back("remotePayout");
  func_table = {
    CreateCetRequest::GetFundTxIdString,
    CreateCetRequest::SetFundTxIdString,
    CreateCetRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    CreateCetRequest::GetFundVoutString,
    CreateCetRequest::SetFundVoutString,
    CreateCetRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    CreateCetRequest::GetLockTimeString,
    CreateCetRequest::SetLockTimeString,
    CreateCetRequest::GetLockTimeFieldType,
  };
  json_mapper.emplace("lockTime", func_table);
  item_list.push_back("lockTime");
  func_table = {
    CreateCetRequest::GetLocalSerialIdString,
    CreateCetRequest::SetLocalSerialIdString,
    CreateCetRequest::GetLocalSerialIdFieldType,
  };
  json_mapper.emplace("localSerialId", func_table);
  item_list.push_back("localSerialId");
  func_table = {
    CreateCetRequest::GetRemoteSerialIdString,
    CreateCetRequest::SetRemoteSerialIdString,
    CreateCetRequest::GetRemoteSerialIdFieldType,
  };
  json_mapper.emplace("remoteSerialId", func_table);
  item_list.push_back("remoteSerialId");
}

void CreateCetRequest::ConvertFromStruct(
    const CreateCetRequestStruct& data) {
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  local_final_address_ = data.local_final_address;
  remote_final_address_ = data.remote_final_address;
  local_payout_ = data.local_payout;
  remote_payout_ = data.remote_payout;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  lock_time_ = data.lock_time;
  local_serial_id_ = data.local_serial_id;
  remote_serial_id_ = data.remote_serial_id;
  ignore_items = data.ignore_items;
}

CreateCetRequestStruct CreateCetRequest::ConvertToStruct() const {  // NOLINT
  CreateCetRequestStruct result;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.local_final_address = local_final_address_;
  result.remote_final_address = remote_final_address_;
  result.local_payout = local_payout_;
  result.remote_payout = remote_payout_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.lock_time = lock_time_;
  result.local_serial_id = local_serial_id_;
  result.remote_serial_id = remote_serial_id_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetResponse>
  CreateCetResponse::json_mapper;
std::vector<std::string> CreateCetResponse::item_list;

void CreateCetResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetResponse> func_table;  // NOLINT

  func_table = {
    CreateCetResponse::GetHexString,
    CreateCetResponse::SetHexString,
    CreateCetResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateCetResponse::ConvertFromStruct(
    const CreateCetResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateCetResponseStruct CreateCetResponse::ConvertToStruct() const {  // NOLINT
  CreateCetResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetAdaptorSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetAdaptorSignatureRequest>
  CreateCetAdaptorSignatureRequest::json_mapper;
std::vector<std::string> CreateCetAdaptorSignatureRequest::item_list;

void CreateCetAdaptorSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetAdaptorSignatureRequest> func_table;  // NOLINT

  func_table = {
    CreateCetAdaptorSignatureRequest::GetCetHexString,
    CreateCetAdaptorSignatureRequest::SetCetHexString,
    CreateCetAdaptorSignatureRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetPrivkeyString,
    CreateCetAdaptorSignatureRequest::SetPrivkeyString,
    CreateCetAdaptorSignatureRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetFundTxIdString,
    CreateCetAdaptorSignatureRequest::SetFundTxIdString,
    CreateCetAdaptorSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetFundVoutString,
    CreateCetAdaptorSignatureRequest::SetFundVoutString,
    CreateCetAdaptorSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetLocalFundPubkeyString,
    CreateCetAdaptorSignatureRequest::SetLocalFundPubkeyString,
    CreateCetAdaptorSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetRemoteFundPubkeyString,
    CreateCetAdaptorSignatureRequest::SetRemoteFundPubkeyString,
    CreateCetAdaptorSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetOraclePubkeyString,
    CreateCetAdaptorSignatureRequest::SetOraclePubkeyString,
    CreateCetAdaptorSignatureRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetOracleRValuesString,
    CreateCetAdaptorSignatureRequest::SetOracleRValuesString,
    CreateCetAdaptorSignatureRequest::GetOracleRValuesFieldType,
  };
  json_mapper.emplace("oracleRValues", func_table);
  item_list.push_back("oracleRValues");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetFundInputAmountString,
    CreateCetAdaptorSignatureRequest::SetFundInputAmountString,
    CreateCetAdaptorSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetMessagesString,
    CreateCetAdaptorSignatureRequest::SetMessagesString,
    CreateCetAdaptorSignatureRequest::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
}

void CreateCetAdaptorSignatureRequest::ConvertFromStruct(
    const CreateCetAdaptorSignatureRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_values_.ConvertFromStruct(data.oracle_r_values);
  fund_input_amount_ = data.fund_input_amount;
  messages_.ConvertFromStruct(data.messages);
  ignore_items = data.ignore_items;
}

CreateCetAdaptorSignatureRequestStruct CreateCetAdaptorSignatureRequest::ConvertToStruct() const {  // NOLINT
  CreateCetAdaptorSignatureRequestStruct result;
  result.cet_hex = cet_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_values = oracle_r_values_.ConvertToStruct();
  result.fund_input_amount = fund_input_amount_;
  result.messages = messages_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetAdaptorSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetAdaptorSignatureResponse>
  CreateCetAdaptorSignatureResponse::json_mapper;
std::vector<std::string> CreateCetAdaptorSignatureResponse::item_list;

void CreateCetAdaptorSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetAdaptorSignatureResponse> func_table;  // NOLINT

  func_table = {
    CreateCetAdaptorSignatureResponse::GetSignatureString,
    CreateCetAdaptorSignatureResponse::SetSignatureString,
    CreateCetAdaptorSignatureResponse::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    CreateCetAdaptorSignatureResponse::GetProofString,
    CreateCetAdaptorSignatureResponse::SetProofString,
    CreateCetAdaptorSignatureResponse::GetProofFieldType,
  };
  json_mapper.emplace("proof", func_table);
  item_list.push_back("proof");
}

void CreateCetAdaptorSignatureResponse::ConvertFromStruct(
    const CreateCetAdaptorSignatureResponseStruct& data) {
  signature_ = data.signature;
  proof_ = data.proof;
  ignore_items = data.ignore_items;
}

CreateCetAdaptorSignatureResponseStruct CreateCetAdaptorSignatureResponse::ConvertToStruct() const {  // NOLINT
  CreateCetAdaptorSignatureResponseStruct result;
  result.signature = signature_;
  result.proof = proof_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetAdaptorSignaturesRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetAdaptorSignaturesRequest>
  CreateCetAdaptorSignaturesRequest::json_mapper;
std::vector<std::string> CreateCetAdaptorSignaturesRequest::item_list;

void CreateCetAdaptorSignaturesRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetAdaptorSignaturesRequest> func_table;  // NOLINT

  func_table = {
    CreateCetAdaptorSignaturesRequest::GetCetsHexString,
    CreateCetAdaptorSignaturesRequest::SetCetsHexString,
    CreateCetAdaptorSignaturesRequest::GetCetsHexFieldType,
  };
  json_mapper.emplace("cetsHex", func_table);
  item_list.push_back("cetsHex");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetPrivkeyString,
    CreateCetAdaptorSignaturesRequest::SetPrivkeyString,
    CreateCetAdaptorSignaturesRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetFundTxIdString,
    CreateCetAdaptorSignaturesRequest::SetFundTxIdString,
    CreateCetAdaptorSignaturesRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetFundVoutString,
    CreateCetAdaptorSignaturesRequest::SetFundVoutString,
    CreateCetAdaptorSignaturesRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetLocalFundPubkeyString,
    CreateCetAdaptorSignaturesRequest::SetLocalFundPubkeyString,
    CreateCetAdaptorSignaturesRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetRemoteFundPubkeyString,
    CreateCetAdaptorSignaturesRequest::SetRemoteFundPubkeyString,
    CreateCetAdaptorSignaturesRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetOraclePubkeyString,
    CreateCetAdaptorSignaturesRequest::SetOraclePubkeyString,
    CreateCetAdaptorSignaturesRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetOracleRValuesString,
    CreateCetAdaptorSignaturesRequest::SetOracleRValuesString,
    CreateCetAdaptorSignaturesRequest::GetOracleRValuesFieldType,
  };
  json_mapper.emplace("oracleRValues", func_table);
  item_list.push_back("oracleRValues");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetFundInputAmountString,
    CreateCetAdaptorSignaturesRequest::SetFundInputAmountString,
    CreateCetAdaptorSignaturesRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetMessagesListString,
    CreateCetAdaptorSignaturesRequest::SetMessagesListString,
    CreateCetAdaptorSignaturesRequest::GetMessagesListFieldType,
  };
  json_mapper.emplace("messagesList", func_table);
  item_list.push_back("messagesList");
}

void CreateCetAdaptorSignaturesRequest::ConvertFromStruct(
    const CreateCetAdaptorSignaturesRequestStruct& data) {
  cets_hex_.ConvertFromStruct(data.cets_hex);
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_values_.ConvertFromStruct(data.oracle_r_values);
  fund_input_amount_ = data.fund_input_amount;
  messages_list_.ConvertFromStruct(data.messages_list);
  ignore_items = data.ignore_items;
}

CreateCetAdaptorSignaturesRequestStruct CreateCetAdaptorSignaturesRequest::ConvertToStruct() const {  // NOLINT
  CreateCetAdaptorSignaturesRequestStruct result;
  result.cets_hex = cets_hex_.ConvertToStruct();
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_values = oracle_r_values_.ConvertToStruct();
  result.fund_input_amount = fund_input_amount_;
  result.messages_list = messages_list_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetAdaptorSignaturesResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetAdaptorSignaturesResponse>
  CreateCetAdaptorSignaturesResponse::json_mapper;
std::vector<std::string> CreateCetAdaptorSignaturesResponse::item_list;

void CreateCetAdaptorSignaturesResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetAdaptorSignaturesResponse> func_table;  // NOLINT

  func_table = {
    CreateCetAdaptorSignaturesResponse::GetAdaptorPairsString,
    CreateCetAdaptorSignaturesResponse::SetAdaptorPairsString,
    CreateCetAdaptorSignaturesResponse::GetAdaptorPairsFieldType,
  };
  json_mapper.emplace("adaptorPairs", func_table);
  item_list.push_back("adaptorPairs");
}

void CreateCetAdaptorSignaturesResponse::ConvertFromStruct(
    const CreateCetAdaptorSignaturesResponseStruct& data) {
  adaptor_pairs_.ConvertFromStruct(data.adaptor_pairs);
  ignore_items = data.ignore_items;
}

CreateCetAdaptorSignaturesResponseStruct CreateCetAdaptorSignaturesResponse::ConvertToStruct() const {  // NOLINT
  CreateCetAdaptorSignaturesResponseStruct result;
  result.adaptor_pairs = adaptor_pairs_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateDlcTransactionsRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateDlcTransactionsRequest>
  CreateDlcTransactionsRequest::json_mapper;
std::vector<std::string> CreateDlcTransactionsRequest::item_list;

void CreateDlcTransactionsRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateDlcTransactionsRequest> func_table;  // NOLINT

  func_table = {
    CreateDlcTransactionsRequest::GetPayoutsString,
    CreateDlcTransactionsRequest::SetPayoutsString,
    CreateDlcTransactionsRequest::GetPayoutsFieldType,
  };
  json_mapper.emplace("payouts", func_table);
  item_list.push_back("payouts");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalFundPubkeyString,
    CreateDlcTransactionsRequest::SetLocalFundPubkeyString,
    CreateDlcTransactionsRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalFinalScriptPubkeyString,
    CreateDlcTransactionsRequest::SetLocalFinalScriptPubkeyString,
    CreateDlcTransactionsRequest::GetLocalFinalScriptPubkeyFieldType,
  };
  json_mapper.emplace("localFinalScriptPubkey", func_table);
  item_list.push_back("localFinalScriptPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteFundPubkeyString,
    CreateDlcTransactionsRequest::SetRemoteFundPubkeyString,
    CreateDlcTransactionsRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteFinalScriptPubkeyString,
    CreateDlcTransactionsRequest::SetRemoteFinalScriptPubkeyString,
    CreateDlcTransactionsRequest::GetRemoteFinalScriptPubkeyFieldType,
  };
  json_mapper.emplace("remoteFinalScriptPubkey", func_table);
  item_list.push_back("remoteFinalScriptPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalInputAmountString,
    CreateDlcTransactionsRequest::SetLocalInputAmountString,
    CreateDlcTransactionsRequest::GetLocalInputAmountFieldType,
  };
  json_mapper.emplace("localInputAmount", func_table);
  item_list.push_back("localInputAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalCollateralAmountString,
    CreateDlcTransactionsRequest::SetLocalCollateralAmountString,
    CreateDlcTransactionsRequest::GetLocalCollateralAmountFieldType,
  };
  json_mapper.emplace("localCollateralAmount", func_table);
  item_list.push_back("localCollateralAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalPayoutSerialIdString,
    CreateDlcTransactionsRequest::SetLocalPayoutSerialIdString,
    CreateDlcTransactionsRequest::GetLocalPayoutSerialIdFieldType,
  };
  json_mapper.emplace("localPayoutSerialId", func_table);
  item_list.push_back("localPayoutSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalChangeSerialIdString,
    CreateDlcTransactionsRequest::SetLocalChangeSerialIdString,
    CreateDlcTransactionsRequest::GetLocalChangeSerialIdFieldType,
  };
  json_mapper.emplace("localChangeSerialId", func_table);
  item_list.push_back("localChangeSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteInputAmountString,
    CreateDlcTransactionsRequest::SetRemoteInputAmountString,
    CreateDlcTransactionsRequest::GetRemoteInputAmountFieldType,
  };
  json_mapper.emplace("remoteInputAmount", func_table);
  item_list.push_back("remoteInputAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteCollateralAmountString,
    CreateDlcTransactionsRequest::SetRemoteCollateralAmountString,
    CreateDlcTransactionsRequest::GetRemoteCollateralAmountFieldType,
  };
  json_mapper.emplace("remoteCollateralAmount", func_table);
  item_list.push_back("remoteCollateralAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetRemotePayoutSerialIdString,
    CreateDlcTransactionsRequest::SetRemotePayoutSerialIdString,
    CreateDlcTransactionsRequest::GetRemotePayoutSerialIdFieldType,
  };
  json_mapper.emplace("remotePayoutSerialId", func_table);
  item_list.push_back("remotePayoutSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteChangeSerialIdString,
    CreateDlcTransactionsRequest::SetRemoteChangeSerialIdString,
    CreateDlcTransactionsRequest::GetRemoteChangeSerialIdFieldType,
  };
  json_mapper.emplace("remoteChangeSerialId", func_table);
  item_list.push_back("remoteChangeSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetRefundLocktimeString,
    CreateDlcTransactionsRequest::SetRefundLocktimeString,
    CreateDlcTransactionsRequest::GetRefundLocktimeFieldType,
  };
  json_mapper.emplace("refundLocktime", func_table);
  item_list.push_back("refundLocktime");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalInputsString,
    CreateDlcTransactionsRequest::SetLocalInputsString,
    CreateDlcTransactionsRequest::GetLocalInputsFieldType,
  };
  json_mapper.emplace("localInputs", func_table);
  item_list.push_back("localInputs");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalDlcInputsString,
    CreateDlcTransactionsRequest::SetLocalDlcInputsString,
    CreateDlcTransactionsRequest::GetLocalDlcInputsFieldType,
  };
  json_mapper.emplace("localDlcInputs", func_table);
  item_list.push_back("localDlcInputs");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalChangeScriptPubkeyString,
    CreateDlcTransactionsRequest::SetLocalChangeScriptPubkeyString,
    CreateDlcTransactionsRequest::GetLocalChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("localChangeScriptPubkey", func_table);
  item_list.push_back("localChangeScriptPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteInputsString,
    CreateDlcTransactionsRequest::SetRemoteInputsString,
    CreateDlcTransactionsRequest::GetRemoteInputsFieldType,
  };
  json_mapper.emplace("remoteInputs", func_table);
  item_list.push_back("remoteInputs");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteDlcInputsString,
    CreateDlcTransactionsRequest::SetRemoteDlcInputsString,
    CreateDlcTransactionsRequest::GetRemoteDlcInputsFieldType,
  };
  json_mapper.emplace("remoteDlcInputs", func_table);
  item_list.push_back("remoteDlcInputs");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteChangeScriptPubkeyString,
    CreateDlcTransactionsRequest::SetRemoteChangeScriptPubkeyString,
    CreateDlcTransactionsRequest::GetRemoteChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("remoteChangeScriptPubkey", func_table);
  item_list.push_back("remoteChangeScriptPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetFeeRateString,
    CreateDlcTransactionsRequest::SetFeeRateString,
    CreateDlcTransactionsRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CreateDlcTransactionsRequest::GetCetLockTimeString,
    CreateDlcTransactionsRequest::SetCetLockTimeString,
    CreateDlcTransactionsRequest::GetCetLockTimeFieldType,
  };
  json_mapper.emplace("cetLockTime", func_table);
  item_list.push_back("cetLockTime");
  func_table = {
    CreateDlcTransactionsRequest::GetFundLockTimeString,
    CreateDlcTransactionsRequest::SetFundLockTimeString,
    CreateDlcTransactionsRequest::GetFundLockTimeFieldType,
  };
  json_mapper.emplace("fundLockTime", func_table);
  item_list.push_back("fundLockTime");
  func_table = {
    CreateDlcTransactionsRequest::GetFundOutputSerialIdString,
    CreateDlcTransactionsRequest::SetFundOutputSerialIdString,
    CreateDlcTransactionsRequest::GetFundOutputSerialIdFieldType,
  };
  json_mapper.emplace("fundOutputSerialId", func_table);
  item_list.push_back("fundOutputSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetOptionDestString,
    CreateDlcTransactionsRequest::SetOptionDestString,
    CreateDlcTransactionsRequest::GetOptionDestFieldType,
  };
  json_mapper.emplace("optionDest", func_table);
  item_list.push_back("optionDest");
  func_table = {
    CreateDlcTransactionsRequest::GetOptionPremiumString,
    CreateDlcTransactionsRequest::SetOptionPremiumString,
    CreateDlcTransactionsRequest::GetOptionPremiumFieldType,
  };
  json_mapper.emplace("optionPremium", func_table);
  item_list.push_back("optionPremium");
}

void CreateDlcTransactionsRequest::ConvertFromStruct(
    const CreateDlcTransactionsRequestStruct& data) {
  payouts_.ConvertFromStruct(data.payouts);
  local_fund_pubkey_ = data.local_fund_pubkey;
  local_final_script_pubkey_ = data.local_final_script_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  remote_final_script_pubkey_ = data.remote_final_script_pubkey;
  local_input_amount_ = data.local_input_amount;
  local_collateral_amount_ = data.local_collateral_amount;
  local_payout_serial_id_ = data.local_payout_serial_id;
  local_change_serial_id_ = data.local_change_serial_id;
  remote_input_amount_ = data.remote_input_amount;
  remote_collateral_amount_ = data.remote_collateral_amount;
  remote_payout_serial_id_ = data.remote_payout_serial_id;
  remote_change_serial_id_ = data.remote_change_serial_id;
  refund_locktime_ = data.refund_locktime;
  local_inputs_.ConvertFromStruct(data.local_inputs);
  local_dlc_inputs_.ConvertFromStruct(data.local_dlc_inputs);
  local_change_script_pubkey_ = data.local_change_script_pubkey;
  remote_inputs_.ConvertFromStruct(data.remote_inputs);
  remote_dlc_inputs_.ConvertFromStruct(data.remote_dlc_inputs);
  remote_change_script_pubkey_ = data.remote_change_script_pubkey;
  fee_rate_ = data.fee_rate;
  cet_lock_time_ = data.cet_lock_time;
  fund_lock_time_ = data.fund_lock_time;
  fund_output_serial_id_ = data.fund_output_serial_id;
  option_dest_ = data.option_dest;
  option_premium_ = data.option_premium;
  ignore_items = data.ignore_items;
}

CreateDlcTransactionsRequestStruct CreateDlcTransactionsRequest::ConvertToStruct() const {  // NOLINT
  CreateDlcTransactionsRequestStruct result;
  result.payouts = payouts_.ConvertToStruct();
  result.local_fund_pubkey = local_fund_pubkey_;
  result.local_final_script_pubkey = local_final_script_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.remote_final_script_pubkey = remote_final_script_pubkey_;
  result.local_input_amount = local_input_amount_;
  result.local_collateral_amount = local_collateral_amount_;
  result.local_payout_serial_id = local_payout_serial_id_;
  result.local_change_serial_id = local_change_serial_id_;
  result.remote_input_amount = remote_input_amount_;
  result.remote_collateral_amount = remote_collateral_amount_;
  result.remote_payout_serial_id = remote_payout_serial_id_;
  result.remote_change_serial_id = remote_change_serial_id_;
  result.refund_locktime = refund_locktime_;
  result.local_inputs = local_inputs_.ConvertToStruct();
  result.local_dlc_inputs = local_dlc_inputs_.ConvertToStruct();
  result.local_change_script_pubkey = local_change_script_pubkey_;
  result.remote_inputs = remote_inputs_.ConvertToStruct();
  result.remote_dlc_inputs = remote_dlc_inputs_.ConvertToStruct();
  result.remote_change_script_pubkey = remote_change_script_pubkey_;
  result.fee_rate = fee_rate_;
  result.cet_lock_time = cet_lock_time_;
  result.fund_lock_time = fund_lock_time_;
  result.fund_output_serial_id = fund_output_serial_id_;
  result.option_dest = option_dest_;
  result.option_premium = option_premium_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateDlcTransactionsResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateDlcTransactionsResponse>
  CreateDlcTransactionsResponse::json_mapper;
std::vector<std::string> CreateDlcTransactionsResponse::item_list;

void CreateDlcTransactionsResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateDlcTransactionsResponse> func_table;  // NOLINT

  func_table = {
    CreateDlcTransactionsResponse::GetFundTxHexString,
    CreateDlcTransactionsResponse::SetFundTxHexString,
    CreateDlcTransactionsResponse::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    CreateDlcTransactionsResponse::GetCetsHexString,
    CreateDlcTransactionsResponse::SetCetsHexString,
    CreateDlcTransactionsResponse::GetCetsHexFieldType,
  };
  json_mapper.emplace("cetsHex", func_table);
  item_list.push_back("cetsHex");
  func_table = {
    CreateDlcTransactionsResponse::GetRefundTxHexString,
    CreateDlcTransactionsResponse::SetRefundTxHexString,
    CreateDlcTransactionsResponse::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
}

void CreateDlcTransactionsResponse::ConvertFromStruct(
    const CreateDlcTransactionsResponseStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  cets_hex_.ConvertFromStruct(data.cets_hex);
  refund_tx_hex_ = data.refund_tx_hex;
  ignore_items = data.ignore_items;
}

CreateDlcTransactionsResponseStruct CreateDlcTransactionsResponse::ConvertToStruct() const {  // NOLINT
  CreateDlcTransactionsResponseStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.cets_hex = cets_hex_.ConvertToStruct();
  result.refund_tx_hex = refund_tx_hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateFundTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateFundTransactionRequest>
  CreateFundTransactionRequest::json_mapper;
std::vector<std::string> CreateFundTransactionRequest::item_list;

void CreateFundTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateFundTransactionRequest> func_table;  // NOLINT

  func_table = {
    CreateFundTransactionRequest::GetLocalPubkeyString,
    CreateFundTransactionRequest::SetLocalPubkeyString,
    CreateFundTransactionRequest::GetLocalPubkeyFieldType,
  };
  json_mapper.emplace("localPubkey", func_table);
  item_list.push_back("localPubkey");
  func_table = {
    CreateFundTransactionRequest::GetRemotePubkeyString,
    CreateFundTransactionRequest::SetRemotePubkeyString,
    CreateFundTransactionRequest::GetRemotePubkeyFieldType,
  };
  json_mapper.emplace("remotePubkey", func_table);
  item_list.push_back("remotePubkey");
  func_table = {
    CreateFundTransactionRequest::GetOutputAmountString,
    CreateFundTransactionRequest::SetOutputAmountString,
    CreateFundTransactionRequest::GetOutputAmountFieldType,
  };
  json_mapper.emplace("outputAmount", func_table);
  item_list.push_back("outputAmount");
  func_table = {
    CreateFundTransactionRequest::GetLocalInputsString,
    CreateFundTransactionRequest::SetLocalInputsString,
    CreateFundTransactionRequest::GetLocalInputsFieldType,
  };
  json_mapper.emplace("localInputs", func_table);
  item_list.push_back("localInputs");
  func_table = {
    CreateFundTransactionRequest::GetLocalChangeString,
    CreateFundTransactionRequest::SetLocalChangeString,
    CreateFundTransactionRequest::GetLocalChangeFieldType,
  };
  json_mapper.emplace("localChange", func_table);
  item_list.push_back("localChange");
  func_table = {
    CreateFundTransactionRequest::GetRemoteInputsString,
    CreateFundTransactionRequest::SetRemoteInputsString,
    CreateFundTransactionRequest::GetRemoteInputsFieldType,
  };
  json_mapper.emplace("remoteInputs", func_table);
  item_list.push_back("remoteInputs");
  func_table = {
    CreateFundTransactionRequest::GetRemoteChangeString,
    CreateFundTransactionRequest::SetRemoteChangeString,
    CreateFundTransactionRequest::GetRemoteChangeFieldType,
  };
  json_mapper.emplace("remoteChange", func_table);
  item_list.push_back("remoteChange");
  func_table = {
    CreateFundTransactionRequest::GetFeeRateString,
    CreateFundTransactionRequest::SetFeeRateString,
    CreateFundTransactionRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CreateFundTransactionRequest::GetOptionDestString,
    CreateFundTransactionRequest::SetOptionDestString,
    CreateFundTransactionRequest::GetOptionDestFieldType,
  };
  json_mapper.emplace("optionDest", func_table);
  item_list.push_back("optionDest");
  func_table = {
    CreateFundTransactionRequest::GetOptionPremiumString,
    CreateFundTransactionRequest::SetOptionPremiumString,
    CreateFundTransactionRequest::GetOptionPremiumFieldType,
  };
  json_mapper.emplace("optionPremium", func_table);
  item_list.push_back("optionPremium");
  func_table = {
    CreateFundTransactionRequest::GetLockTimeString,
    CreateFundTransactionRequest::SetLockTimeString,
    CreateFundTransactionRequest::GetLockTimeFieldType,
  };
  json_mapper.emplace("lockTime", func_table);
  item_list.push_back("lockTime");
  func_table = {
    CreateFundTransactionRequest::GetLocalSerialIdString,
    CreateFundTransactionRequest::SetLocalSerialIdString,
    CreateFundTransactionRequest::GetLocalSerialIdFieldType,
  };
  json_mapper.emplace("localSerialId", func_table);
  item_list.push_back("localSerialId");
  func_table = {
    CreateFundTransactionRequest::GetRemoteSerialIdString,
    CreateFundTransactionRequest::SetRemoteSerialIdString,
    CreateFundTransactionRequest::GetRemoteSerialIdFieldType,
  };
  json_mapper.emplace("remoteSerialId", func_table);
  item_list.push_back("remoteSerialId");
  func_table = {
    CreateFundTransactionRequest::GetOutputSerialIdString,
    CreateFundTransactionRequest::SetOutputSerialIdString,
    CreateFundTransactionRequest::GetOutputSerialIdFieldType,
  };
  json_mapper.emplace("outputSerialId", func_table);
  item_list.push_back("outputSerialId");
}

void CreateFundTransactionRequest::ConvertFromStruct(
    const CreateFundTransactionRequestStruct& data) {
  local_pubkey_ = data.local_pubkey;
  remote_pubkey_ = data.remote_pubkey;
  output_amount_ = data.output_amount;
  local_inputs_.ConvertFromStruct(data.local_inputs);
  local_change_.ConvertFromStruct(data.local_change);
  remote_inputs_.ConvertFromStruct(data.remote_inputs);
  remote_change_.ConvertFromStruct(data.remote_change);
  fee_rate_ = data.fee_rate;
  option_dest_ = data.option_dest;
  option_premium_ = data.option_premium;
  lock_time_ = data.lock_time;
  local_serial_id_ = data.local_serial_id;
  remote_serial_id_ = data.remote_serial_id;
  output_serial_id_ = data.output_serial_id;
  ignore_items = data.ignore_items;
}

CreateFundTransactionRequestStruct CreateFundTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateFundTransactionRequestStruct result;
  result.local_pubkey = local_pubkey_;
  result.remote_pubkey = remote_pubkey_;
  result.output_amount = output_amount_;
  result.local_inputs = local_inputs_.ConvertToStruct();
  result.local_change = local_change_.ConvertToStruct();
  result.remote_inputs = remote_inputs_.ConvertToStruct();
  result.remote_change = remote_change_.ConvertToStruct();
  result.fee_rate = fee_rate_;
  result.option_dest = option_dest_;
  result.option_premium = option_premium_;
  result.lock_time = lock_time_;
  result.local_serial_id = local_serial_id_;
  result.remote_serial_id = remote_serial_id_;
  result.output_serial_id = output_serial_id_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateFundTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateFundTransactionResponse>
  CreateFundTransactionResponse::json_mapper;
std::vector<std::string> CreateFundTransactionResponse::item_list;

void CreateFundTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateFundTransactionResponse> func_table;  // NOLINT

  func_table = {
    CreateFundTransactionResponse::GetHexString,
    CreateFundTransactionResponse::SetHexString,
    CreateFundTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateFundTransactionResponse::ConvertFromStruct(
    const CreateFundTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateFundTransactionResponseStruct CreateFundTransactionResponse::ConvertToStruct() const {  // NOLINT
  CreateFundTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateRefundTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateRefundTransactionRequest>
  CreateRefundTransactionRequest::json_mapper;
std::vector<std::string> CreateRefundTransactionRequest::item_list;

void CreateRefundTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateRefundTransactionRequest> func_table;  // NOLINT

  func_table = {
    CreateRefundTransactionRequest::GetLocalFinalScriptPubkeyString,
    CreateRefundTransactionRequest::SetLocalFinalScriptPubkeyString,
    CreateRefundTransactionRequest::GetLocalFinalScriptPubkeyFieldType,
  };
  json_mapper.emplace("localFinalScriptPubkey", func_table);
  item_list.push_back("localFinalScriptPubkey");
  func_table = {
    CreateRefundTransactionRequest::GetRemoteFinalScriptPubkeyString,
    CreateRefundTransactionRequest::SetRemoteFinalScriptPubkeyString,
    CreateRefundTransactionRequest::GetRemoteFinalScriptPubkeyFieldType,
  };
  json_mapper.emplace("remoteFinalScriptPubkey", func_table);
  item_list.push_back("remoteFinalScriptPubkey");
  func_table = {
    CreateRefundTransactionRequest::GetLocalAmountString,
    CreateRefundTransactionRequest::SetLocalAmountString,
    CreateRefundTransactionRequest::GetLocalAmountFieldType,
  };
  json_mapper.emplace("localAmount", func_table);
  item_list.push_back("localAmount");
  func_table = {
    CreateRefundTransactionRequest::GetRemoteAmountString,
    CreateRefundTransactionRequest::SetRemoteAmountString,
    CreateRefundTransactionRequest::GetRemoteAmountFieldType,
  };
  json_mapper.emplace("remoteAmount", func_table);
  item_list.push_back("remoteAmount");
  func_table = {
    CreateRefundTransactionRequest::GetLockTimeString,
    CreateRefundTransactionRequest::SetLockTimeString,
    CreateRefundTransactionRequest::GetLockTimeFieldType,
  };
  json_mapper.emplace("lockTime", func_table);
  item_list.push_back("lockTime");
  func_table = {
    CreateRefundTransactionRequest::GetFundTxIdString,
    CreateRefundTransactionRequest::SetFundTxIdString,
    CreateRefundTransactionRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    CreateRefundTransactionRequest::GetFundVoutString,
    CreateRefundTransactionRequest::SetFundVoutString,
    CreateRefundTransactionRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
}

void CreateRefundTransactionRequest::ConvertFromStruct(
    const CreateRefundTransactionRequestStruct& data) {
  local_final_script_pubkey_ = data.local_final_script_pubkey;
  remote_final_script_pubkey_ = data.remote_final_script_pubkey;
  local_amount_ = data.local_amount;
  remote_amount_ = data.remote_amount;
  lock_time_ = data.lock_time;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  ignore_items = data.ignore_items;
}

CreateRefundTransactionRequestStruct CreateRefundTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateRefundTransactionRequestStruct result;
  result.local_final_script_pubkey = local_final_script_pubkey_;
  result.remote_final_script_pubkey = remote_final_script_pubkey_;
  result.local_amount = local_amount_;
  result.remote_amount = remote_amount_;
  result.lock_time = lock_time_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateRefundTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateRefundTransactionResponse>
  CreateRefundTransactionResponse::json_mapper;
std::vector<std::string> CreateRefundTransactionResponse::item_list;

void CreateRefundTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateRefundTransactionResponse> func_table;  // NOLINT

  func_table = {
    CreateRefundTransactionResponse::GetHexString,
    CreateRefundTransactionResponse::SetHexString,
    CreateRefundTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateRefundTransactionResponse::ConvertFromStruct(
    const CreateRefundTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateRefundTransactionResponseStruct CreateRefundTransactionResponse::ConvertToStruct() const {  // NOLINT
  CreateRefundTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateSplicedDlcTransactionsRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateSplicedDlcTransactionsRequest>
  CreateSplicedDlcTransactionsRequest::json_mapper;
std::vector<std::string> CreateSplicedDlcTransactionsRequest::item_list;

void CreateSplicedDlcTransactionsRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateSplicedDlcTransactionsRequest> func_table;  // NOLINT

  func_table = {
    CreateSplicedDlcTransactionsRequest::GetPayoutsString,
    CreateSplicedDlcTransactionsRequest::SetPayoutsString,
    CreateSplicedDlcTransactionsRequest::GetPayoutsFieldType,
  };
  json_mapper.emplace("payouts", func_table);
  item_list.push_back("payouts");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetLocalFundPubkeyString,
    CreateSplicedDlcTransactionsRequest::SetLocalFundPubkeyString,
    CreateSplicedDlcTransactionsRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetLocalFinalScriptPubkeyString,
    CreateSplicedDlcTransactionsRequest::SetLocalFinalScriptPubkeyString,
    CreateSplicedDlcTransactionsRequest::GetLocalFinalScriptPubkeyFieldType,
  };
  json_mapper.emplace("localFinalScriptPubkey", func_table);
  item_list.push_back("localFinalScriptPubkey");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRemoteFundPubkeyString,
    CreateSplicedDlcTransactionsRequest::SetRemoteFundPubkeyString,
    CreateSplicedDlcTransactionsRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRemoteFinalScriptPubkeyString,
    CreateSplicedDlcTransactionsRequest::SetRemoteFinalScriptPubkeyString,
    CreateSplicedDlcTransactionsRequest::GetRemoteFinalScriptPubkeyFieldType,
  };
  json_mapper.emplace("remoteFinalScriptPubkey", func_table);
  item_list.push_back("remoteFinalScriptPubkey");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetLocalInputAmountString,
    CreateSplicedDlcTransactionsRequest::SetLocalInputAmountString,
    CreateSplicedDlcTransactionsRequest::GetLocalInputAmountFieldType,
  };
  json_mapper.emplace("localInputAmount", func_table);
  item_list.push_back("localInputAmount");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetLocalCollateralAmountString,
    CreateSplicedDlcTransactionsRequest::SetLocalCollateralAmountString,
    CreateSplicedDlcTransactionsRequest::GetLocalCollateralAmountFieldType,
  };
  json_mapper.emplace("localCollateralAmount", func_table);
  item_list.push_back("localCollateralAmount");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetLocalPayoutSerialIdString,
    CreateSplicedDlcTransactionsRequest::SetLocalPayoutSerialIdString,
    CreateSplicedDlcTransactionsRequest::GetLocalPayoutSerialIdFieldType,
  };
  json_mapper.emplace("localPayoutSerialId", func_table);
  item_list.push_back("localPayoutSerialId");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetLocalChangeSerialIdString,
    CreateSplicedDlcTransactionsRequest::SetLocalChangeSerialIdString,
    CreateSplicedDlcTransactionsRequest::GetLocalChangeSerialIdFieldType,
  };
  json_mapper.emplace("localChangeSerialId", func_table);
  item_list.push_back("localChangeSerialId");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRemoteInputAmountString,
    CreateSplicedDlcTransactionsRequest::SetRemoteInputAmountString,
    CreateSplicedDlcTransactionsRequest::GetRemoteInputAmountFieldType,
  };
  json_mapper.emplace("remoteInputAmount", func_table);
  item_list.push_back("remoteInputAmount");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRemoteCollateralAmountString,
    CreateSplicedDlcTransactionsRequest::SetRemoteCollateralAmountString,
    CreateSplicedDlcTransactionsRequest::GetRemoteCollateralAmountFieldType,
  };
  json_mapper.emplace("remoteCollateralAmount", func_table);
  item_list.push_back("remoteCollateralAmount");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRemotePayoutSerialIdString,
    CreateSplicedDlcTransactionsRequest::SetRemotePayoutSerialIdString,
    CreateSplicedDlcTransactionsRequest::GetRemotePayoutSerialIdFieldType,
  };
  json_mapper.emplace("remotePayoutSerialId", func_table);
  item_list.push_back("remotePayoutSerialId");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRemoteChangeSerialIdString,
    CreateSplicedDlcTransactionsRequest::SetRemoteChangeSerialIdString,
    CreateSplicedDlcTransactionsRequest::GetRemoteChangeSerialIdFieldType,
  };
  json_mapper.emplace("remoteChangeSerialId", func_table);
  item_list.push_back("remoteChangeSerialId");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRefundLocktimeString,
    CreateSplicedDlcTransactionsRequest::SetRefundLocktimeString,
    CreateSplicedDlcTransactionsRequest::GetRefundLocktimeFieldType,
  };
  json_mapper.emplace("refundLocktime", func_table);
  item_list.push_back("refundLocktime");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetLocalInputsString,
    CreateSplicedDlcTransactionsRequest::SetLocalInputsString,
    CreateSplicedDlcTransactionsRequest::GetLocalInputsFieldType,
  };
  json_mapper.emplace("localInputs", func_table);
  item_list.push_back("localInputs");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetLocalDlcInputsString,
    CreateSplicedDlcTransactionsRequest::SetLocalDlcInputsString,
    CreateSplicedDlcTransactionsRequest::GetLocalDlcInputsFieldType,
  };
  json_mapper.emplace("localDlcInputs", func_table);
  item_list.push_back("localDlcInputs");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetLocalChangeScriptPubkeyString,
    CreateSplicedDlcTransactionsRequest::SetLocalChangeScriptPubkeyString,
    CreateSplicedDlcTransactionsRequest::GetLocalChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("localChangeScriptPubkey", func_table);
  item_list.push_back("localChangeScriptPubkey");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRemoteInputsString,
    CreateSplicedDlcTransactionsRequest::SetRemoteInputsString,
    CreateSplicedDlcTransactionsRequest::GetRemoteInputsFieldType,
  };
  json_mapper.emplace("remoteInputs", func_table);
  item_list.push_back("remoteInputs");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRemoteDlcInputsString,
    CreateSplicedDlcTransactionsRequest::SetRemoteDlcInputsString,
    CreateSplicedDlcTransactionsRequest::GetRemoteDlcInputsFieldType,
  };
  json_mapper.emplace("remoteDlcInputs", func_table);
  item_list.push_back("remoteDlcInputs");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetRemoteChangeScriptPubkeyString,
    CreateSplicedDlcTransactionsRequest::SetRemoteChangeScriptPubkeyString,
    CreateSplicedDlcTransactionsRequest::GetRemoteChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("remoteChangeScriptPubkey", func_table);
  item_list.push_back("remoteChangeScriptPubkey");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetFeeRateString,
    CreateSplicedDlcTransactionsRequest::SetFeeRateString,
    CreateSplicedDlcTransactionsRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetCetLockTimeString,
    CreateSplicedDlcTransactionsRequest::SetCetLockTimeString,
    CreateSplicedDlcTransactionsRequest::GetCetLockTimeFieldType,
  };
  json_mapper.emplace("cetLockTime", func_table);
  item_list.push_back("cetLockTime");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetFundLockTimeString,
    CreateSplicedDlcTransactionsRequest::SetFundLockTimeString,
    CreateSplicedDlcTransactionsRequest::GetFundLockTimeFieldType,
  };
  json_mapper.emplace("fundLockTime", func_table);
  item_list.push_back("fundLockTime");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetFundOutputSerialIdString,
    CreateSplicedDlcTransactionsRequest::SetFundOutputSerialIdString,
    CreateSplicedDlcTransactionsRequest::GetFundOutputSerialIdFieldType,
  };
  json_mapper.emplace("fundOutputSerialId", func_table);
  item_list.push_back("fundOutputSerialId");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetOptionDestString,
    CreateSplicedDlcTransactionsRequest::SetOptionDestString,
    CreateSplicedDlcTransactionsRequest::GetOptionDestFieldType,
  };
  json_mapper.emplace("optionDest", func_table);
  item_list.push_back("optionDest");
  func_table = {
    CreateSplicedDlcTransactionsRequest::GetOptionPremiumString,
    CreateSplicedDlcTransactionsRequest::SetOptionPremiumString,
    CreateSplicedDlcTransactionsRequest::GetOptionPremiumFieldType,
  };
  json_mapper.emplace("optionPremium", func_table);
  item_list.push_back("optionPremium");
}

void CreateSplicedDlcTransactionsRequest::ConvertFromStruct(
    const CreateSplicedDlcTransactionsRequestStruct& data) {
  payouts_.ConvertFromStruct(data.payouts);
  local_fund_pubkey_ = data.local_fund_pubkey;
  local_final_script_pubkey_ = data.local_final_script_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  remote_final_script_pubkey_ = data.remote_final_script_pubkey;
  local_input_amount_ = data.local_input_amount;
  local_collateral_amount_ = data.local_collateral_amount;
  local_payout_serial_id_ = data.local_payout_serial_id;
  local_change_serial_id_ = data.local_change_serial_id;
  remote_input_amount_ = data.remote_input_amount;
  remote_collateral_amount_ = data.remote_collateral_amount;
  remote_payout_serial_id_ = data.remote_payout_serial_id;
  remote_change_serial_id_ = data.remote_change_serial_id;
  refund_locktime_ = data.refund_locktime;
  local_inputs_.ConvertFromStruct(data.local_inputs);
  local_dlc_inputs_.ConvertFromStruct(data.local_dlc_inputs);
  local_change_script_pubkey_ = data.local_change_script_pubkey;
  remote_inputs_.ConvertFromStruct(data.remote_inputs);
  remote_dlc_inputs_.ConvertFromStruct(data.remote_dlc_inputs);
  remote_change_script_pubkey_ = data.remote_change_script_pubkey;
  fee_rate_ = data.fee_rate;
  cet_lock_time_ = data.cet_lock_time;
  fund_lock_time_ = data.fund_lock_time;
  fund_output_serial_id_ = data.fund_output_serial_id;
  option_dest_ = data.option_dest;
  option_premium_ = data.option_premium;
  ignore_items = data.ignore_items;
}

CreateSplicedDlcTransactionsRequestStruct CreateSplicedDlcTransactionsRequest::ConvertToStruct() const {  // NOLINT
  CreateSplicedDlcTransactionsRequestStruct result;
  result.payouts = payouts_.ConvertToStruct();
  result.local_fund_pubkey = local_fund_pubkey_;
  result.local_final_script_pubkey = local_final_script_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.remote_final_script_pubkey = remote_final_script_pubkey_;
  result.local_input_amount = local_input_amount_;
  result.local_collateral_amount = local_collateral_amount_;
  result.local_payout_serial_id = local_payout_serial_id_;
  result.local_change_serial_id = local_change_serial_id_;
  result.remote_input_amount = remote_input_amount_;
  result.remote_collateral_amount = remote_collateral_amount_;
  result.remote_payout_serial_id = remote_payout_serial_id_;
  result.remote_change_serial_id = remote_change_serial_id_;
  result.refund_locktime = refund_locktime_;
  result.local_inputs = local_inputs_.ConvertToStruct();
  result.local_dlc_inputs = local_dlc_inputs_.ConvertToStruct();
  result.local_change_script_pubkey = local_change_script_pubkey_;
  result.remote_inputs = remote_inputs_.ConvertToStruct();
  result.remote_dlc_inputs = remote_dlc_inputs_.ConvertToStruct();
  result.remote_change_script_pubkey = remote_change_script_pubkey_;
  result.fee_rate = fee_rate_;
  result.cet_lock_time = cet_lock_time_;
  result.fund_lock_time = fund_lock_time_;
  result.fund_output_serial_id = fund_output_serial_id_;
  result.option_dest = option_dest_;
  result.option_premium = option_premium_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateSplicedDlcTransactionsResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateSplicedDlcTransactionsResponse>
  CreateSplicedDlcTransactionsResponse::json_mapper;
std::vector<std::string> CreateSplicedDlcTransactionsResponse::item_list;

void CreateSplicedDlcTransactionsResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateSplicedDlcTransactionsResponse> func_table;  // NOLINT

  func_table = {
    CreateSplicedDlcTransactionsResponse::GetFundTxHexString,
    CreateSplicedDlcTransactionsResponse::SetFundTxHexString,
    CreateSplicedDlcTransactionsResponse::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    CreateSplicedDlcTransactionsResponse::GetCetsHexString,
    CreateSplicedDlcTransactionsResponse::SetCetsHexString,
    CreateSplicedDlcTransactionsResponse::GetCetsHexFieldType,
  };
  json_mapper.emplace("cetsHex", func_table);
  item_list.push_back("cetsHex");
  func_table = {
    CreateSplicedDlcTransactionsResponse::GetRefundTxHexString,
    CreateSplicedDlcTransactionsResponse::SetRefundTxHexString,
    CreateSplicedDlcTransactionsResponse::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
}

void CreateSplicedDlcTransactionsResponse::ConvertFromStruct(
    const CreateSplicedDlcTransactionsResponseStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  cets_hex_.ConvertFromStruct(data.cets_hex);
  refund_tx_hex_ = data.refund_tx_hex;
  ignore_items = data.ignore_items;
}

CreateSplicedDlcTransactionsResponseStruct CreateSplicedDlcTransactionsResponse::ConvertToStruct() const {  // NOLINT
  CreateSplicedDlcTransactionsResponseStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.cets_hex = cets_hex_.ConvertToStruct();
  result.refund_tx_hex = refund_tx_hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// InnerErrorResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<InnerErrorResponse>
  InnerErrorResponse::json_mapper;
std::vector<std::string> InnerErrorResponse::item_list;

void InnerErrorResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<InnerErrorResponse> func_table;  // NOLINT

  func_table = {
    InnerErrorResponse::GetCodeString,
    InnerErrorResponse::SetCodeString,
    InnerErrorResponse::GetCodeFieldType,
  };
  json_mapper.emplace("code", func_table);
  item_list.push_back("code");
  func_table = {
    InnerErrorResponse::GetTypeString,
    InnerErrorResponse::SetTypeString,
    InnerErrorResponse::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    InnerErrorResponse::GetMessageString,
    InnerErrorResponse::SetMessageString,
    InnerErrorResponse::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
}

void InnerErrorResponse::ConvertFromStruct(
    const InnerErrorResponseStruct& data) {
  code_ = data.code;
  type_ = data.type;
  message_ = data.message;
  ignore_items = data.ignore_items;
}

InnerErrorResponseStruct InnerErrorResponse::ConvertToStruct() const {  // NOLINT
  InnerErrorResponseStruct result;
  result.code = code_;
  result.type = type_;
  result.message = message_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ErrorResponseBase
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ErrorResponseBase>
  ErrorResponseBase::json_mapper;
std::vector<std::string> ErrorResponseBase::item_list;

void ErrorResponseBase::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ErrorResponseBase> func_table;  // NOLINT

  func_table = {
    ErrorResponseBase::GetErrorString,
    ErrorResponseBase::SetErrorString,
    ErrorResponseBase::GetErrorFieldType,
  };
  json_mapper.emplace("error", func_table);
  item_list.push_back("error");
}

// ------------------------------------------------------------------------
// GetRawDlcFundingInputSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawDlcFundingInputSignatureRequest>
  GetRawDlcFundingInputSignatureRequest::json_mapper;
std::vector<std::string> GetRawDlcFundingInputSignatureRequest::item_list;

void GetRawDlcFundingInputSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawDlcFundingInputSignatureRequest> func_table;  // NOLINT

  func_table = {
    GetRawDlcFundingInputSignatureRequest::GetFundTxHexString,
    GetRawDlcFundingInputSignatureRequest::SetFundTxHexString,
    GetRawDlcFundingInputSignatureRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    GetRawDlcFundingInputSignatureRequest::GetFundTxidString,
    GetRawDlcFundingInputSignatureRequest::SetFundTxidString,
    GetRawDlcFundingInputSignatureRequest::GetFundTxidFieldType,
  };
  json_mapper.emplace("fundTxid", func_table);
  item_list.push_back("fundTxid");
  func_table = {
    GetRawDlcFundingInputSignatureRequest::GetFundVoutString,
    GetRawDlcFundingInputSignatureRequest::SetFundVoutString,
    GetRawDlcFundingInputSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    GetRawDlcFundingInputSignatureRequest::GetFundAmountString,
    GetRawDlcFundingInputSignatureRequest::SetFundAmountString,
    GetRawDlcFundingInputSignatureRequest::GetFundAmountFieldType,
  };
  json_mapper.emplace("fundAmount", func_table);
  item_list.push_back("fundAmount");
  func_table = {
    GetRawDlcFundingInputSignatureRequest::GetLocalFundPubkeyString,
    GetRawDlcFundingInputSignatureRequest::SetLocalFundPubkeyString,
    GetRawDlcFundingInputSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    GetRawDlcFundingInputSignatureRequest::GetRemoteFundPubkeyString,
    GetRawDlcFundingInputSignatureRequest::SetRemoteFundPubkeyString,
    GetRawDlcFundingInputSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    GetRawDlcFundingInputSignatureRequest::GetPrivkeyString,
    GetRawDlcFundingInputSignatureRequest::SetPrivkeyString,
    GetRawDlcFundingInputSignatureRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
}

void GetRawDlcFundingInputSignatureRequest::ConvertFromStruct(
    const GetRawDlcFundingInputSignatureRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  fund_txid_ = data.fund_txid;
  fund_vout_ = data.fund_vout;
  fund_amount_ = data.fund_amount;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  privkey_ = data.privkey;
  ignore_items = data.ignore_items;
}

GetRawDlcFundingInputSignatureRequestStruct GetRawDlcFundingInputSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawDlcFundingInputSignatureRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.fund_txid = fund_txid_;
  result.fund_vout = fund_vout_;
  result.fund_amount = fund_amount_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.privkey = privkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawDlcFundingInputSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawDlcFundingInputSignatureResponse>
  GetRawDlcFundingInputSignatureResponse::json_mapper;
std::vector<std::string> GetRawDlcFundingInputSignatureResponse::item_list;

void GetRawDlcFundingInputSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawDlcFundingInputSignatureResponse> func_table;  // NOLINT

  func_table = {
    GetRawDlcFundingInputSignatureResponse::GetHexString,
    GetRawDlcFundingInputSignatureResponse::SetHexString,
    GetRawDlcFundingInputSignatureResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void GetRawDlcFundingInputSignatureResponse::ConvertFromStruct(
    const GetRawDlcFundingInputSignatureResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

GetRawDlcFundingInputSignatureResponseStruct GetRawDlcFundingInputSignatureResponse::ConvertToStruct() const {  // NOLINT
  GetRawDlcFundingInputSignatureResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawFundTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawFundTxSignatureRequest>
  GetRawFundTxSignatureRequest::json_mapper;
std::vector<std::string> GetRawFundTxSignatureRequest::item_list;

void GetRawFundTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawFundTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    GetRawFundTxSignatureRequest::GetFundTxHexString,
    GetRawFundTxSignatureRequest::SetFundTxHexString,
    GetRawFundTxSignatureRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    GetRawFundTxSignatureRequest::GetPrivkeyString,
    GetRawFundTxSignatureRequest::SetPrivkeyString,
    GetRawFundTxSignatureRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    GetRawFundTxSignatureRequest::GetPrevTxIdString,
    GetRawFundTxSignatureRequest::SetPrevTxIdString,
    GetRawFundTxSignatureRequest::GetPrevTxIdFieldType,
  };
  json_mapper.emplace("prevTxId", func_table);
  item_list.push_back("prevTxId");
  func_table = {
    GetRawFundTxSignatureRequest::GetPrevVoutString,
    GetRawFundTxSignatureRequest::SetPrevVoutString,
    GetRawFundTxSignatureRequest::GetPrevVoutFieldType,
  };
  json_mapper.emplace("prevVout", func_table);
  item_list.push_back("prevVout");
  func_table = {
    GetRawFundTxSignatureRequest::GetAmountString,
    GetRawFundTxSignatureRequest::SetAmountString,
    GetRawFundTxSignatureRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void GetRawFundTxSignatureRequest::ConvertFromStruct(
    const GetRawFundTxSignatureRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  privkey_ = data.privkey;
  prev_tx_id_ = data.prev_tx_id;
  prev_vout_ = data.prev_vout;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

GetRawFundTxSignatureRequestStruct GetRawFundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawFundTxSignatureRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.privkey = privkey_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_vout = prev_vout_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawFundTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawFundTxSignatureResponse>
  GetRawFundTxSignatureResponse::json_mapper;
std::vector<std::string> GetRawFundTxSignatureResponse::item_list;

void GetRawFundTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawFundTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    GetRawFundTxSignatureResponse::GetHexString,
    GetRawFundTxSignatureResponse::SetHexString,
    GetRawFundTxSignatureResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void GetRawFundTxSignatureResponse::ConvertFromStruct(
    const GetRawFundTxSignatureResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

GetRawFundTxSignatureResponseStruct GetRawFundTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  GetRawFundTxSignatureResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawRefundTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawRefundTxSignatureRequest>
  GetRawRefundTxSignatureRequest::json_mapper;
std::vector<std::string> GetRawRefundTxSignatureRequest::item_list;

void GetRawRefundTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawRefundTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    GetRawRefundTxSignatureRequest::GetRefundTxHexString,
    GetRawRefundTxSignatureRequest::SetRefundTxHexString,
    GetRawRefundTxSignatureRequest::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
  func_table = {
    GetRawRefundTxSignatureRequest::GetPrivkeyString,
    GetRawRefundTxSignatureRequest::SetPrivkeyString,
    GetRawRefundTxSignatureRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    GetRawRefundTxSignatureRequest::GetFundTxIdString,
    GetRawRefundTxSignatureRequest::SetFundTxIdString,
    GetRawRefundTxSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    GetRawRefundTxSignatureRequest::GetFundVoutString,
    GetRawRefundTxSignatureRequest::SetFundVoutString,
    GetRawRefundTxSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    GetRawRefundTxSignatureRequest::GetLocalFundPubkeyString,
    GetRawRefundTxSignatureRequest::SetLocalFundPubkeyString,
    GetRawRefundTxSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    GetRawRefundTxSignatureRequest::GetRemoteFundPubkeyString,
    GetRawRefundTxSignatureRequest::SetRemoteFundPubkeyString,
    GetRawRefundTxSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    GetRawRefundTxSignatureRequest::GetFundInputAmountString,
    GetRawRefundTxSignatureRequest::SetFundInputAmountString,
    GetRawRefundTxSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
}

void GetRawRefundTxSignatureRequest::ConvertFromStruct(
    const GetRawRefundTxSignatureRequestStruct& data) {
  refund_tx_hex_ = data.refund_tx_hex;
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_input_amount_ = data.fund_input_amount;
  ignore_items = data.ignore_items;
}

GetRawRefundTxSignatureRequestStruct GetRawRefundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawRefundTxSignatureRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_input_amount = fund_input_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawRefundTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawRefundTxSignatureResponse>
  GetRawRefundTxSignatureResponse::json_mapper;
std::vector<std::string> GetRawRefundTxSignatureResponse::item_list;

void GetRawRefundTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawRefundTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    GetRawRefundTxSignatureResponse::GetHexString,
    GetRawRefundTxSignatureResponse::SetHexString,
    GetRawRefundTxSignatureResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void GetRawRefundTxSignatureResponse::ConvertFromStruct(
    const GetRawRefundTxSignatureResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

GetRawRefundTxSignatureResponseStruct GetRawRefundTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  GetRawRefundTxSignatureResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignCetRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignCetRequest>
  SignCetRequest::json_mapper;
std::vector<std::string> SignCetRequest::item_list;

void SignCetRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignCetRequest> func_table;  // NOLINT

  func_table = {
    SignCetRequest::GetCetHexString,
    SignCetRequest::SetCetHexString,
    SignCetRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
  func_table = {
    SignCetRequest::GetFundPrivkeyString,
    SignCetRequest::SetFundPrivkeyString,
    SignCetRequest::GetFundPrivkeyFieldType,
  };
  json_mapper.emplace("fundPrivkey", func_table);
  item_list.push_back("fundPrivkey");
  func_table = {
    SignCetRequest::GetFundTxIdString,
    SignCetRequest::SetFundTxIdString,
    SignCetRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    SignCetRequest::GetFundVoutString,
    SignCetRequest::SetFundVoutString,
    SignCetRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    SignCetRequest::GetLocalFundPubkeyString,
    SignCetRequest::SetLocalFundPubkeyString,
    SignCetRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    SignCetRequest::GetRemoteFundPubkeyString,
    SignCetRequest::SetRemoteFundPubkeyString,
    SignCetRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    SignCetRequest::GetFundInputAmountString,
    SignCetRequest::SetFundInputAmountString,
    SignCetRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    SignCetRequest::GetAdaptorSignatureString,
    SignCetRequest::SetAdaptorSignatureString,
    SignCetRequest::GetAdaptorSignatureFieldType,
  };
  json_mapper.emplace("adaptorSignature", func_table);
  item_list.push_back("adaptorSignature");
  func_table = {
    SignCetRequest::GetOracleSignaturesString,
    SignCetRequest::SetOracleSignaturesString,
    SignCetRequest::GetOracleSignaturesFieldType,
  };
  json_mapper.emplace("oracleSignatures", func_table);
  item_list.push_back("oracleSignatures");
}

void SignCetRequest::ConvertFromStruct(
    const SignCetRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  fund_privkey_ = data.fund_privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_input_amount_ = data.fund_input_amount;
  adaptor_signature_ = data.adaptor_signature;
  oracle_signatures_.ConvertFromStruct(data.oracle_signatures);
  ignore_items = data.ignore_items;
}

SignCetRequestStruct SignCetRequest::ConvertToStruct() const {  // NOLINT
  SignCetRequestStruct result;
  result.cet_hex = cet_hex_;
  result.fund_privkey = fund_privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_input_amount = fund_input_amount_;
  result.adaptor_signature = adaptor_signature_;
  result.oracle_signatures = oracle_signatures_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignCetResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignCetResponse>
  SignCetResponse::json_mapper;
std::vector<std::string> SignCetResponse::item_list;

void SignCetResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignCetResponse> func_table;  // NOLINT

  func_table = {
    SignCetResponse::GetHexString,
    SignCetResponse::SetHexString,
    SignCetResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void SignCetResponse::ConvertFromStruct(
    const SignCetResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

SignCetResponseStruct SignCetResponse::ConvertToStruct() const {  // NOLINT
  SignCetResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignDlcFundingInputRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignDlcFundingInputRequest>
  SignDlcFundingInputRequest::json_mapper;
std::vector<std::string> SignDlcFundingInputRequest::item_list;

void SignDlcFundingInputRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignDlcFundingInputRequest> func_table;  // NOLINT

  func_table = {
    SignDlcFundingInputRequest::GetFundTxHexString,
    SignDlcFundingInputRequest::SetFundTxHexString,
    SignDlcFundingInputRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    SignDlcFundingInputRequest::GetFundTxidString,
    SignDlcFundingInputRequest::SetFundTxidString,
    SignDlcFundingInputRequest::GetFundTxidFieldType,
  };
  json_mapper.emplace("fundTxid", func_table);
  item_list.push_back("fundTxid");
  func_table = {
    SignDlcFundingInputRequest::GetFundVoutString,
    SignDlcFundingInputRequest::SetFundVoutString,
    SignDlcFundingInputRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    SignDlcFundingInputRequest::GetFundAmountString,
    SignDlcFundingInputRequest::SetFundAmountString,
    SignDlcFundingInputRequest::GetFundAmountFieldType,
  };
  json_mapper.emplace("fundAmount", func_table);
  item_list.push_back("fundAmount");
  func_table = {
    SignDlcFundingInputRequest::GetLocalFundPubkeyString,
    SignDlcFundingInputRequest::SetLocalFundPubkeyString,
    SignDlcFundingInputRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    SignDlcFundingInputRequest::GetRemoteFundPubkeyString,
    SignDlcFundingInputRequest::SetRemoteFundPubkeyString,
    SignDlcFundingInputRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    SignDlcFundingInputRequest::GetLocalPrivkeyString,
    SignDlcFundingInputRequest::SetLocalPrivkeyString,
    SignDlcFundingInputRequest::GetLocalPrivkeyFieldType,
  };
  json_mapper.emplace("localPrivkey", func_table);
  item_list.push_back("localPrivkey");
  func_table = {
    SignDlcFundingInputRequest::GetRemoteSignatureString,
    SignDlcFundingInputRequest::SetRemoteSignatureString,
    SignDlcFundingInputRequest::GetRemoteSignatureFieldType,
  };
  json_mapper.emplace("remoteSignature", func_table);
  item_list.push_back("remoteSignature");
}

void SignDlcFundingInputRequest::ConvertFromStruct(
    const SignDlcFundingInputRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  fund_txid_ = data.fund_txid;
  fund_vout_ = data.fund_vout;
  fund_amount_ = data.fund_amount;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  local_privkey_ = data.local_privkey;
  remote_signature_ = data.remote_signature;
  ignore_items = data.ignore_items;
}

SignDlcFundingInputRequestStruct SignDlcFundingInputRequest::ConvertToStruct() const {  // NOLINT
  SignDlcFundingInputRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.fund_txid = fund_txid_;
  result.fund_vout = fund_vout_;
  result.fund_amount = fund_amount_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.local_privkey = local_privkey_;
  result.remote_signature = remote_signature_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignDlcFundingInputResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignDlcFundingInputResponse>
  SignDlcFundingInputResponse::json_mapper;
std::vector<std::string> SignDlcFundingInputResponse::item_list;

void SignDlcFundingInputResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignDlcFundingInputResponse> func_table;  // NOLINT

  func_table = {
    SignDlcFundingInputResponse::GetHexString,
    SignDlcFundingInputResponse::SetHexString,
    SignDlcFundingInputResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void SignDlcFundingInputResponse::ConvertFromStruct(
    const SignDlcFundingInputResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

SignDlcFundingInputResponseStruct SignDlcFundingInputResponse::ConvertToStruct() const {  // NOLINT
  SignDlcFundingInputResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignFundTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignFundTransactionRequest>
  SignFundTransactionRequest::json_mapper;
std::vector<std::string> SignFundTransactionRequest::item_list;

void SignFundTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignFundTransactionRequest> func_table;  // NOLINT

  func_table = {
    SignFundTransactionRequest::GetFundTxHexString,
    SignFundTransactionRequest::SetFundTxHexString,
    SignFundTransactionRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    SignFundTransactionRequest::GetPrivkeyString,
    SignFundTransactionRequest::SetPrivkeyString,
    SignFundTransactionRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    SignFundTransactionRequest::GetPrevTxIdString,
    SignFundTransactionRequest::SetPrevTxIdString,
    SignFundTransactionRequest::GetPrevTxIdFieldType,
  };
  json_mapper.emplace("prevTxId", func_table);
  item_list.push_back("prevTxId");
  func_table = {
    SignFundTransactionRequest::GetPrevVoutString,
    SignFundTransactionRequest::SetPrevVoutString,
    SignFundTransactionRequest::GetPrevVoutFieldType,
  };
  json_mapper.emplace("prevVout", func_table);
  item_list.push_back("prevVout");
  func_table = {
    SignFundTransactionRequest::GetAmountString,
    SignFundTransactionRequest::SetAmountString,
    SignFundTransactionRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void SignFundTransactionRequest::ConvertFromStruct(
    const SignFundTransactionRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  privkey_ = data.privkey;
  prev_tx_id_ = data.prev_tx_id;
  prev_vout_ = data.prev_vout;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

SignFundTransactionRequestStruct SignFundTransactionRequest::ConvertToStruct() const {  // NOLINT
  SignFundTransactionRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.privkey = privkey_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_vout = prev_vout_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignFundTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignFundTransactionResponse>
  SignFundTransactionResponse::json_mapper;
std::vector<std::string> SignFundTransactionResponse::item_list;

void SignFundTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignFundTransactionResponse> func_table;  // NOLINT

  func_table = {
    SignFundTransactionResponse::GetHexString,
    SignFundTransactionResponse::SetHexString,
    SignFundTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void SignFundTransactionResponse::ConvertFromStruct(
    const SignFundTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

SignFundTransactionResponseStruct SignFundTransactionResponse::ConvertToStruct() const {  // NOLINT
  SignFundTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetAdaptorSignatureRequest>
  VerifyCetAdaptorSignatureRequest::json_mapper;
std::vector<std::string> VerifyCetAdaptorSignatureRequest::item_list;

void VerifyCetAdaptorSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetAdaptorSignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifyCetAdaptorSignatureRequest::GetCetHexString,
    VerifyCetAdaptorSignatureRequest::SetCetHexString,
    VerifyCetAdaptorSignatureRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetAdaptorSignatureString,
    VerifyCetAdaptorSignatureRequest::SetAdaptorSignatureString,
    VerifyCetAdaptorSignatureRequest::GetAdaptorSignatureFieldType,
  };
  json_mapper.emplace("adaptorSignature", func_table);
  item_list.push_back("adaptorSignature");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetAdaptorProofString,
    VerifyCetAdaptorSignatureRequest::SetAdaptorProofString,
    VerifyCetAdaptorSignatureRequest::GetAdaptorProofFieldType,
  };
  json_mapper.emplace("adaptorProof", func_table);
  item_list.push_back("adaptorProof");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetMessagesString,
    VerifyCetAdaptorSignatureRequest::SetMessagesString,
    VerifyCetAdaptorSignatureRequest::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetLocalFundPubkeyString,
    VerifyCetAdaptorSignatureRequest::SetLocalFundPubkeyString,
    VerifyCetAdaptorSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetRemoteFundPubkeyString,
    VerifyCetAdaptorSignatureRequest::SetRemoteFundPubkeyString,
    VerifyCetAdaptorSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetOraclePubkeyString,
    VerifyCetAdaptorSignatureRequest::SetOraclePubkeyString,
    VerifyCetAdaptorSignatureRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetOracleRValuesString,
    VerifyCetAdaptorSignatureRequest::SetOracleRValuesString,
    VerifyCetAdaptorSignatureRequest::GetOracleRValuesFieldType,
  };
  json_mapper.emplace("oracleRValues", func_table);
  item_list.push_back("oracleRValues");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetFundTxIdString,
    VerifyCetAdaptorSignatureRequest::SetFundTxIdString,
    VerifyCetAdaptorSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetFundVoutString,
    VerifyCetAdaptorSignatureRequest::SetFundVoutString,
    VerifyCetAdaptorSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetFundInputAmountString,
    VerifyCetAdaptorSignatureRequest::SetFundInputAmountString,
    VerifyCetAdaptorSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetVerifyRemoteString,
    VerifyCetAdaptorSignatureRequest::SetVerifyRemoteString,
    VerifyCetAdaptorSignatureRequest::GetVerifyRemoteFieldType,
  };
  json_mapper.emplace("verifyRemote", func_table);
  item_list.push_back("verifyRemote");
}

void VerifyCetAdaptorSignatureRequest::ConvertFromStruct(
    const VerifyCetAdaptorSignatureRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  adaptor_signature_ = data.adaptor_signature;
  adaptor_proof_ = data.adaptor_proof;
  messages_.ConvertFromStruct(data.messages);
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_values_.ConvertFromStruct(data.oracle_r_values);
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_remote_ = data.verify_remote;
  ignore_items = data.ignore_items;
}

VerifyCetAdaptorSignatureRequestStruct VerifyCetAdaptorSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyCetAdaptorSignatureRequestStruct result;
  result.cet_hex = cet_hex_;
  result.adaptor_signature = adaptor_signature_;
  result.adaptor_proof = adaptor_proof_;
  result.messages = messages_.ConvertToStruct();
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_values = oracle_r_values_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_remote = verify_remote_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetAdaptorSignatureResponse>
  VerifyCetAdaptorSignatureResponse::json_mapper;
std::vector<std::string> VerifyCetAdaptorSignatureResponse::item_list;

void VerifyCetAdaptorSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetAdaptorSignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifyCetAdaptorSignatureResponse::GetValidString,
    VerifyCetAdaptorSignatureResponse::SetValidString,
    VerifyCetAdaptorSignatureResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyCetAdaptorSignatureResponse::ConvertFromStruct(
    const VerifyCetAdaptorSignatureResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyCetAdaptorSignatureResponseStruct VerifyCetAdaptorSignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifyCetAdaptorSignatureResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignaturesRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetAdaptorSignaturesRequest>
  VerifyCetAdaptorSignaturesRequest::json_mapper;
std::vector<std::string> VerifyCetAdaptorSignaturesRequest::item_list;

void VerifyCetAdaptorSignaturesRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetAdaptorSignaturesRequest> func_table;  // NOLINT

  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetCetsHexString,
    VerifyCetAdaptorSignaturesRequest::SetCetsHexString,
    VerifyCetAdaptorSignaturesRequest::GetCetsHexFieldType,
  };
  json_mapper.emplace("cetsHex", func_table);
  item_list.push_back("cetsHex");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetAdaptorPairsString,
    VerifyCetAdaptorSignaturesRequest::SetAdaptorPairsString,
    VerifyCetAdaptorSignaturesRequest::GetAdaptorPairsFieldType,
  };
  json_mapper.emplace("adaptorPairs", func_table);
  item_list.push_back("adaptorPairs");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetMessagesListString,
    VerifyCetAdaptorSignaturesRequest::SetMessagesListString,
    VerifyCetAdaptorSignaturesRequest::GetMessagesListFieldType,
  };
  json_mapper.emplace("messagesList", func_table);
  item_list.push_back("messagesList");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetLocalFundPubkeyString,
    VerifyCetAdaptorSignaturesRequest::SetLocalFundPubkeyString,
    VerifyCetAdaptorSignaturesRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetRemoteFundPubkeyString,
    VerifyCetAdaptorSignaturesRequest::SetRemoteFundPubkeyString,
    VerifyCetAdaptorSignaturesRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetOraclePubkeyString,
    VerifyCetAdaptorSignaturesRequest::SetOraclePubkeyString,
    VerifyCetAdaptorSignaturesRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetOracleRValuesString,
    VerifyCetAdaptorSignaturesRequest::SetOracleRValuesString,
    VerifyCetAdaptorSignaturesRequest::GetOracleRValuesFieldType,
  };
  json_mapper.emplace("oracleRValues", func_table);
  item_list.push_back("oracleRValues");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetFundTxIdString,
    VerifyCetAdaptorSignaturesRequest::SetFundTxIdString,
    VerifyCetAdaptorSignaturesRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetFundVoutString,
    VerifyCetAdaptorSignaturesRequest::SetFundVoutString,
    VerifyCetAdaptorSignaturesRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetFundInputAmountString,
    VerifyCetAdaptorSignaturesRequest::SetFundInputAmountString,
    VerifyCetAdaptorSignaturesRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetVerifyRemoteString,
    VerifyCetAdaptorSignaturesRequest::SetVerifyRemoteString,
    VerifyCetAdaptorSignaturesRequest::GetVerifyRemoteFieldType,
  };
  json_mapper.emplace("verifyRemote", func_table);
  item_list.push_back("verifyRemote");
}

void VerifyCetAdaptorSignaturesRequest::ConvertFromStruct(
    const VerifyCetAdaptorSignaturesRequestStruct& data) {
  cets_hex_.ConvertFromStruct(data.cets_hex);
  adaptor_pairs_.ConvertFromStruct(data.adaptor_pairs);
  messages_list_.ConvertFromStruct(data.messages_list);
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_values_.ConvertFromStruct(data.oracle_r_values);
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_remote_ = data.verify_remote;
  ignore_items = data.ignore_items;
}

VerifyCetAdaptorSignaturesRequestStruct VerifyCetAdaptorSignaturesRequest::ConvertToStruct() const {  // NOLINT
  VerifyCetAdaptorSignaturesRequestStruct result;
  result.cets_hex = cets_hex_.ConvertToStruct();
  result.adaptor_pairs = adaptor_pairs_.ConvertToStruct();
  result.messages_list = messages_list_.ConvertToStruct();
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_values = oracle_r_values_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_remote = verify_remote_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignaturesResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetAdaptorSignaturesResponse>
  VerifyCetAdaptorSignaturesResponse::json_mapper;
std::vector<std::string> VerifyCetAdaptorSignaturesResponse::item_list;

void VerifyCetAdaptorSignaturesResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetAdaptorSignaturesResponse> func_table;  // NOLINT

  func_table = {
    VerifyCetAdaptorSignaturesResponse::GetValidString,
    VerifyCetAdaptorSignaturesResponse::SetValidString,
    VerifyCetAdaptorSignaturesResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyCetAdaptorSignaturesResponse::ConvertFromStruct(
    const VerifyCetAdaptorSignaturesResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyCetAdaptorSignaturesResponseStruct VerifyCetAdaptorSignaturesResponse::ConvertToStruct() const {  // NOLINT
  VerifyCetAdaptorSignaturesResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyDlcFundingInputSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyDlcFundingInputSignatureRequest>
  VerifyDlcFundingInputSignatureRequest::json_mapper;
std::vector<std::string> VerifyDlcFundingInputSignatureRequest::item_list;

void VerifyDlcFundingInputSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyDlcFundingInputSignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifyDlcFundingInputSignatureRequest::GetFundTxHexString,
    VerifyDlcFundingInputSignatureRequest::SetFundTxHexString,
    VerifyDlcFundingInputSignatureRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    VerifyDlcFundingInputSignatureRequest::GetFundTxidString,
    VerifyDlcFundingInputSignatureRequest::SetFundTxidString,
    VerifyDlcFundingInputSignatureRequest::GetFundTxidFieldType,
  };
  json_mapper.emplace("fundTxid", func_table);
  item_list.push_back("fundTxid");
  func_table = {
    VerifyDlcFundingInputSignatureRequest::GetFundVoutString,
    VerifyDlcFundingInputSignatureRequest::SetFundVoutString,
    VerifyDlcFundingInputSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyDlcFundingInputSignatureRequest::GetFundAmountString,
    VerifyDlcFundingInputSignatureRequest::SetFundAmountString,
    VerifyDlcFundingInputSignatureRequest::GetFundAmountFieldType,
  };
  json_mapper.emplace("fundAmount", func_table);
  item_list.push_back("fundAmount");
  func_table = {
    VerifyDlcFundingInputSignatureRequest::GetLocalFundPubkeyString,
    VerifyDlcFundingInputSignatureRequest::SetLocalFundPubkeyString,
    VerifyDlcFundingInputSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    VerifyDlcFundingInputSignatureRequest::GetRemoteFundPubkeyString,
    VerifyDlcFundingInputSignatureRequest::SetRemoteFundPubkeyString,
    VerifyDlcFundingInputSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    VerifyDlcFundingInputSignatureRequest::GetSignatureString,
    VerifyDlcFundingInputSignatureRequest::SetSignatureString,
    VerifyDlcFundingInputSignatureRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    VerifyDlcFundingInputSignatureRequest::GetPubkeyString,
    VerifyDlcFundingInputSignatureRequest::SetPubkeyString,
    VerifyDlcFundingInputSignatureRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void VerifyDlcFundingInputSignatureRequest::ConvertFromStruct(
    const VerifyDlcFundingInputSignatureRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  fund_txid_ = data.fund_txid;
  fund_vout_ = data.fund_vout;
  fund_amount_ = data.fund_amount;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  signature_ = data.signature;
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

VerifyDlcFundingInputSignatureRequestStruct VerifyDlcFundingInputSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyDlcFundingInputSignatureRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.fund_txid = fund_txid_;
  result.fund_vout = fund_vout_;
  result.fund_amount = fund_amount_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.signature = signature_;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyDlcFundingInputSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyDlcFundingInputSignatureResponse>
  VerifyDlcFundingInputSignatureResponse::json_mapper;
std::vector<std::string> VerifyDlcFundingInputSignatureResponse::item_list;

void VerifyDlcFundingInputSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyDlcFundingInputSignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifyDlcFundingInputSignatureResponse::GetValidString,
    VerifyDlcFundingInputSignatureResponse::SetValidString,
    VerifyDlcFundingInputSignatureResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyDlcFundingInputSignatureResponse::ConvertFromStruct(
    const VerifyDlcFundingInputSignatureResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyDlcFundingInputSignatureResponseStruct VerifyDlcFundingInputSignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifyDlcFundingInputSignatureResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyFundTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyFundTxSignatureRequest>
  VerifyFundTxSignatureRequest::json_mapper;
std::vector<std::string> VerifyFundTxSignatureRequest::item_list;

void VerifyFundTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyFundTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifyFundTxSignatureRequest::GetFundTxHexString,
    VerifyFundTxSignatureRequest::SetFundTxHexString,
    VerifyFundTxSignatureRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    VerifyFundTxSignatureRequest::GetSignatureString,
    VerifyFundTxSignatureRequest::SetSignatureString,
    VerifyFundTxSignatureRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    VerifyFundTxSignatureRequest::GetPubkeyString,
    VerifyFundTxSignatureRequest::SetPubkeyString,
    VerifyFundTxSignatureRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    VerifyFundTxSignatureRequest::GetPrevTxIdString,
    VerifyFundTxSignatureRequest::SetPrevTxIdString,
    VerifyFundTxSignatureRequest::GetPrevTxIdFieldType,
  };
  json_mapper.emplace("prevTxId", func_table);
  item_list.push_back("prevTxId");
  func_table = {
    VerifyFundTxSignatureRequest::GetPrevVoutString,
    VerifyFundTxSignatureRequest::SetPrevVoutString,
    VerifyFundTxSignatureRequest::GetPrevVoutFieldType,
  };
  json_mapper.emplace("prevVout", func_table);
  item_list.push_back("prevVout");
  func_table = {
    VerifyFundTxSignatureRequest::GetFundInputAmountString,
    VerifyFundTxSignatureRequest::SetFundInputAmountString,
    VerifyFundTxSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
}

void VerifyFundTxSignatureRequest::ConvertFromStruct(
    const VerifyFundTxSignatureRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  signature_ = data.signature;
  pubkey_ = data.pubkey;
  prev_tx_id_ = data.prev_tx_id;
  prev_vout_ = data.prev_vout;
  fund_input_amount_ = data.fund_input_amount;
  ignore_items = data.ignore_items;
}

VerifyFundTxSignatureRequestStruct VerifyFundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyFundTxSignatureRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.signature = signature_;
  result.pubkey = pubkey_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_vout = prev_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyFundTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyFundTxSignatureResponse>
  VerifyFundTxSignatureResponse::json_mapper;
std::vector<std::string> VerifyFundTxSignatureResponse::item_list;

void VerifyFundTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyFundTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifyFundTxSignatureResponse::GetValidString,
    VerifyFundTxSignatureResponse::SetValidString,
    VerifyFundTxSignatureResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyFundTxSignatureResponse::ConvertFromStruct(
    const VerifyFundTxSignatureResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyFundTxSignatureResponseStruct VerifyFundTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifyFundTxSignatureResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyRefundTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyRefundTxSignatureRequest>
  VerifyRefundTxSignatureRequest::json_mapper;
std::vector<std::string> VerifyRefundTxSignatureRequest::item_list;

void VerifyRefundTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyRefundTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifyRefundTxSignatureRequest::GetRefundTxHexString,
    VerifyRefundTxSignatureRequest::SetRefundTxHexString,
    VerifyRefundTxSignatureRequest::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
  func_table = {
    VerifyRefundTxSignatureRequest::GetSignatureString,
    VerifyRefundTxSignatureRequest::SetSignatureString,
    VerifyRefundTxSignatureRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    VerifyRefundTxSignatureRequest::GetLocalFundPubkeyString,
    VerifyRefundTxSignatureRequest::SetLocalFundPubkeyString,
    VerifyRefundTxSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    VerifyRefundTxSignatureRequest::GetRemoteFundPubkeyString,
    VerifyRefundTxSignatureRequest::SetRemoteFundPubkeyString,
    VerifyRefundTxSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    VerifyRefundTxSignatureRequest::GetFundTxIdString,
    VerifyRefundTxSignatureRequest::SetFundTxIdString,
    VerifyRefundTxSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    VerifyRefundTxSignatureRequest::GetFundVoutString,
    VerifyRefundTxSignatureRequest::SetFundVoutString,
    VerifyRefundTxSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyRefundTxSignatureRequest::GetFundInputAmountString,
    VerifyRefundTxSignatureRequest::SetFundInputAmountString,
    VerifyRefundTxSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    VerifyRefundTxSignatureRequest::GetVerifyRemoteString,
    VerifyRefundTxSignatureRequest::SetVerifyRemoteString,
    VerifyRefundTxSignatureRequest::GetVerifyRemoteFieldType,
  };
  json_mapper.emplace("verifyRemote", func_table);
  item_list.push_back("verifyRemote");
}

void VerifyRefundTxSignatureRequest::ConvertFromStruct(
    const VerifyRefundTxSignatureRequestStruct& data) {
  refund_tx_hex_ = data.refund_tx_hex;
  signature_ = data.signature;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_remote_ = data.verify_remote;
  ignore_items = data.ignore_items;
}

VerifyRefundTxSignatureRequestStruct VerifyRefundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyRefundTxSignatureRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.signature = signature_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_remote = verify_remote_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyRefundTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyRefundTxSignatureResponse>
  VerifyRefundTxSignatureResponse::json_mapper;
std::vector<std::string> VerifyRefundTxSignatureResponse::item_list;

void VerifyRefundTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyRefundTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifyRefundTxSignatureResponse::GetValidString,
    VerifyRefundTxSignatureResponse::SetValidString,
    VerifyRefundTxSignatureResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyRefundTxSignatureResponse::ConvertFromStruct(
    const VerifyRefundTxSignatureResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyRefundTxSignatureResponseStruct VerifyRefundTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifyRefundTxSignatureResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd
