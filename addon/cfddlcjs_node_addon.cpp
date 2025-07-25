// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_node_addon.cpp
 *
 * @brief cfdのnode.js向けAPI実装ファイル
 */
#include <napi.h>  // NOLINT

#include <string>

#include "cfd/cfd_common.h"
#include "cfddlcjs/cfddlcjs_api_json.h"
#include "cfddlcjs/cfddlcjs_common.h"

using cfd::dlc::js::api::json::JsonMappingApi;
using Napi::CallbackInfo;
using Napi::Env;
using Napi::Function;
using Napi::Number;
using Napi::Object;
using Napi::String;
using Napi::TypeError;
using Napi::Value;

// -----------------------------------------------------------------------------
// API wrapper for node addon
// -----------------------------------------------------------------------------

namespace cfd {
namespace dlc {
namespace js {
namespace api {
namespace json {

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @param[in] call_function   cfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
Value NodeAddonJsonApi(
  const CallbackInfo &information,
  std::function<std::string(const std::string &)> call_function) {
  Env env = information.Env();
  if (information.Length() < 1) {
    TypeError::New(env, "Invalid arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[0].IsString()) {
    TypeError::New(env, "Wrong arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }

  try {
    std::string json_message =
      call_function(information[0].As<String>().Utf8Value());
    return String::New(env, json_message.c_str());
  } catch (const std::exception &except) {
    // illegal route
    std::string errmsg = "exception=" + std::string(except.what());
    TypeError::New(env, errmsg).ThrowAsJavaScriptException();
    return env.Null();
  } catch (...) {
    // illegal route
    TypeError::New(env, "Illegal exception.").ThrowAsJavaScriptException();
    return env.Null();
  }
}

/**
 * @brief NodeAddonのJSON APIテンプレート関数(response only).
 * @param[in] information     node addon apiのコールバック情報
 * @param[in] call_function   cfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
Value NodeAddonJsonResponseApi(
  const CallbackInfo &information, std::function<std::string()> call_function) {
  Env env = information.Env();
  try {
    std::string json_message = call_function();
    return String::New(env, json_message.c_str());
  } catch (const std::exception &except) {
    // illegal route
    std::string errmsg = "exception=" + std::string(except.what());
    TypeError::New(env, errmsg).ThrowAsJavaScriptException();
    return env.Null();
  } catch (...) {
    // illegal route
    TypeError::New(env, "Illegal exception.").ThrowAsJavaScriptException();
    return env.Null();
  }
}

Value CreateFundTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateFundTransaction);
}

Value CreateBatchFundTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(
    information, JsonMappingApi::CreateBatchFundTransaction);
}

Value SignFundTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SignFundTransaction);
}

Value GetRawFundTxSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetRawFundTxSignature);
}

Value AddSignatureToFundTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(
    information, JsonMappingApi::AddSignatureToFundTransaction);
}

Value CreateCet(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateCet);
}

Value VerifyFundTxSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::VerifyFundTxSignature);
}

Value CreateRefundTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateRefundTransaction);
}

Value CreateDlcTransactions(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateDlcTransactions);
}

Value CreateSplicedDlcTransactions(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateSplicedDlcTransactions);
}

Value CreateBatchDlcTransactions(const CallbackInfo &information) {
  return NodeAddonJsonApi(
    information, JsonMappingApi::CreateBatchDlcTransactions);
}

Value CreateCetAdaptorSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(
    information, JsonMappingApi::CreateCetAdaptorSignature);
}

Value CreateCetAdaptorSignatures(const CallbackInfo &information) {
  return NodeAddonJsonApi(
    information, JsonMappingApi::CreateCetAdaptorSignatures);
}

Value SignCet(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SignCet);
}

Value VerifyCetAdaptorSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(
    information, JsonMappingApi::VerifyCetAdaptorSignature);
}

Value VerifyCetAdaptorSignatures(const CallbackInfo &information) {
  return NodeAddonJsonApi(
    information, JsonMappingApi::VerifyCetAdaptorSignatures);
}

Value GetRawRefundTxSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetRawRefundTxSignature);
}

Value AddSignaturesToRefundTx(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AddSignaturesToRefundTx);
}

Value VerifyRefundTxSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::VerifyRefundTxSignature);
}

Value SignDlcFundingInput(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SignDlcFundingInput);
}

Value GetRawDlcFundingInputSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetRawDlcFundingInputSignature);
}

Value VerifyDlcFundingInputSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::VerifyDlcFundingInputSignature);
}

/**
 * @brief JSON APIの生成初期化関数.
 * @param[in] env         環境情報
 * @param[out] exports    関数格納ポインタ
 */
void InitializeJsonApi(Env env, Object *exports) {
  cfd::Initialize();
  exports->Set(
    String::New(env, "CreateFundTransaction"),
    Function::New(env, CreateFundTransaction));
  exports->Set(
    String::New(env, "CreateBatchFundTransaction"),
    Function::New(env, CreateBatchFundTransaction));
  exports->Set(
    String::New(env, "SignFundTransaction"),
    Function::New(env, SignFundTransaction));
  exports->Set(
    String::New(env, "GetRawFundTxSignature"),
    Function::New(env, GetRawFundTxSignature));
  exports->Set(
    String::New(env, "AddSignatureToFundTransaction"),
    Function::New(env, AddSignatureToFundTransaction));
  exports->Set(
    String::New(env, "VerifyFundTxSignature"),
    Function::New(env, VerifyFundTxSignature));
  exports->Set(String::New(env, "CreateCet"), Function::New(env, CreateCet));
  exports->Set(
    String::New(env, "CreateRefundTransaction"),
    Function::New(env, CreateRefundTransaction));
  exports->Set(
    String::New(env, "CreateDlcTransactions"),
    Function::New(env, CreateDlcTransactions));
  exports->Set(
    String::New(env, "CreateSplicedDlcTransactions"),
    Function::New(env, CreateSplicedDlcTransactions));
  exports->Set(
    String::New(env, "CreateBatchDlcTransactions"),
    Function::New(env, CreateBatchDlcTransactions));
  exports->Set(
    String::New(env, "CreateCetAdaptorSignature"),
    Function::New(env, CreateCetAdaptorSignature));
  exports->Set(
    String::New(env, "CreateCetAdaptorSignatures"),
    Function::New(env, CreateCetAdaptorSignatures));
  exports->Set(String::New(env, "SignCet"), Function::New(env, SignCet));
  exports->Set(
    String::New(env, "VerifyCetAdaptorSignature"),
    Function::New(env, VerifyCetAdaptorSignature));
  exports->Set(
    String::New(env, "VerifyCetAdaptorSignatures"),
    Function::New(env, VerifyCetAdaptorSignatures));
  exports->Set(
    String::New(env, "GetRawRefundTxSignature"),
    Function::New(env, GetRawRefundTxSignature));
  exports->Set(
    String::New(env, "AddSignaturesToRefundTx"),
    Function::New(env, AddSignaturesToRefundTx));
  exports->Set(
    String::New(env, "VerifyRefundTxSignature"),
    Function::New(env, VerifyRefundTxSignature));
  exports->Set(
    String::New(env, "SignDlcFundingInput"),
    Function::New(env, SignDlcFundingInput));
  exports->Set(
    String::New(env, "GetRawDlcFundingInputSignature"),
    Function::New(env, GetRawDlcFundingInputSignature));
  exports->Set(
    String::New(env, "VerifyDlcFundingInputSignature"),
    Function::New(env, VerifyDlcFundingInputSignature));
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd
