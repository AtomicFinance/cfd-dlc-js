/* eslint-disable max-len */
/* eslint-disable indent */
export interface AdaptorPair {
    signature: string;
    proof: string;
}

/** Add signatures to a refund transaction */
export interface AddSignaturesToRefundTxRequest {
    refundTxHex: string;
    signatures: string[];
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
}

export interface AddSignaturesToRefundTxResponse {
    hex: string;
}

/** Add a signature to fund transaction */
export interface AddSignatureToFundTransactionRequest {
    fundTxHex: string;
    signature: string;
    prevTxId: string;
    prevVout: number;
    pubkey: string;
}

export interface AddSignatureToFundTransactionResponse {
    hex: string;
}

/** Create Batch Dlc transactions */
export interface CreateBatchDlcTransactionsRequest {
    localPayouts: (bigint | number)[];
    remotePayouts: (bigint | number)[];
    numPayouts: (bigint | number)[];
    localFundPubkeys: string[];
    localFinalScriptPubkeys: string[];
    remoteFundPubkeys: string[];
    remoteFinalScriptPubkeys: string[];
    localInputAmount: (bigint | number);
    localCollateralAmounts: (bigint | number)[];
    localPayoutSerialIds: (bigint | number)[];
    localChangeSerialId: (bigint | number);
    remoteInputAmount: (bigint | number);
    remoteCollateralAmounts: (bigint | number)[];
    remotePayoutSerialIds: (bigint | number)[];
    remoteChangeSerialId: (bigint | number);
    refundLocktimes: (bigint | number)[];
    localInputs: TxInInfoRequest[];
    localChangeScriptPubkey: string;
    remoteInputs: TxInInfoRequest[];
    remoteChangeScriptPubkey: string;
    feeRate: number;
    cetLockTime?: (bigint | number);
    fundLockTime?: (bigint | number);
    fundOutputSerialIds?: (bigint | number)[];
}

export interface CreateBatchDlcTransactionsResponse {
    fundTxHex: string;
    cetsHexList: string[];
    refundTxHexList: string[];
}

/** Create a batch fund transaction */
export interface CreateBatchFundTransactionRequest {
    localPubkeys: string[];
    remotePubkeys: string[];
    outputAmounts: (bigint | number)[];
    localInputs: TxInInfoRequest[];
    localChange: TxOutRequest;
    remoteInputs: TxInInfoRequest[];
    remoteChange: TxOutRequest;
    feeRate: (bigint | number);
    lockTime?: (bigint | number);
    localSerialId?: (bigint | number);
    remoteSerialId?: (bigint | number);
    outputSerialIds: (bigint | number)[];
}

export interface CreateBatchFundTransactionResponse {
    hex: string;
}

/** Create an adaptor signature for a CET */
export interface CreateCetAdaptorSignatureRequest {
    cetHex: string;
    privkey: string;
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    oraclePubkey: string;
    oracleRValues: string[];
    fundInputAmount: (bigint | number);
    messages: string[];
}

export interface CreateCetAdaptorSignatureResponse {
    signature: string;
    proof: string;
}

/** Create an adaptor signature for a CET */
export interface CreateCetAdaptorSignaturesRequest {
    cetsHex: string[];
    privkey: string;
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    oraclePubkey: string;
    oracleRValues: string[];
    fundInputAmount: (bigint | number);
    messagesList: Messages[];
}

export interface CreateCetAdaptorSignaturesResponse {
    adaptorPairs: AdaptorPair[];
}

/** Create a CET */
export interface CreateCetRequest {
    localFundPubkey: string;
    remoteFundPubkey: string;
    localFinalAddress: string;
    remoteFinalAddress: string;
    localPayout: (bigint | number);
    remotePayout: (bigint | number);
    fundTxId: string;
    fundVout?: number;
    lockTime: (bigint | number);
    localSerialId?: (bigint | number);
    remoteSerialId?: (bigint | number);
}

export interface CreateCetResponse {
    hex: string;
}

/** Create Dlc transactions */
export interface CreateDlcTransactionsRequest {
    payouts: PayoutRequest[];
    localFundPubkey: string;
    localFinalScriptPubkey: string;
    remoteFundPubkey: string;
    remoteFinalScriptPubkey: string;
    localInputAmount: (bigint | number);
    localCollateralAmount: (bigint | number);
    localPayoutSerialId: (bigint | number);
    localChangeSerialId: (bigint | number);
    remoteInputAmount: (bigint | number);
    remoteCollateralAmount: (bigint | number);
    remotePayoutSerialId: (bigint | number);
    remoteChangeSerialId: (bigint | number);
    refundLocktime: (bigint | number);
    localInputs: TxInInfoRequest[];
    localDlcInputs?: DlcInputInfoRequest[];
    localChangeScriptPubkey: string;
    remoteInputs: TxInInfoRequest[];
    remoteDlcInputs?: DlcInputInfoRequest[];
    remoteChangeScriptPubkey: string;
    feeRate: number;
    cetLockTime?: (bigint | number);
    fundLockTime?: (bigint | number);
    fundOutputSerialId?: (bigint | number);
    optionDest?: string;
    optionPremium?: (bigint | number);
}

export interface CreateDlcTransactionsResponse {
    fundTxHex: string;
    cetsHex: string[];
    refundTxHex: string;
}

/** Create a fund transaction */
export interface CreateFundTransactionRequest {
    localPubkey: string;
    remotePubkey: string;
    outputAmount: (bigint | number);
    localInputs: TxInInfoRequest[];
    localChange: TxOutRequest;
    remoteInputs: TxInInfoRequest[];
    remoteChange: TxOutRequest;
    feeRate: (bigint | number);
    optionDest?: string;
    optionPremium?: (bigint | number);
    lockTime?: (bigint | number);
    localSerialId?: (bigint | number);
    remoteSerialId?: (bigint | number);
    outputSerialId?: (bigint | number);
}

export interface CreateFundTransactionResponse {
    hex: string;
}

/** Create a refund transaction */
export interface CreateRefundTransactionRequest {
    localFinalScriptPubkey: string;
    remoteFinalScriptPubkey: string;
    localAmount: (bigint | number);
    remoteAmount: (bigint | number);
    lockTime: (bigint | number);
    fundTxId: string;
    fundVout?: number;
}

export interface CreateRefundTransactionResponse {
    hex: string;
}

/** Create Spliced Dlc transactions */
export interface CreateSplicedDlcTransactionsRequest {
    payouts: PayoutRequest[];
    localFundPubkey: string;
    localFinalScriptPubkey: string;
    remoteFundPubkey: string;
    remoteFinalScriptPubkey: string;
    localInputAmount: (bigint | number);
    localCollateralAmount: (bigint | number);
    localPayoutSerialId: (bigint | number);
    localChangeSerialId: (bigint | number);
    remoteInputAmount: (bigint | number);
    remoteCollateralAmount: (bigint | number);
    remotePayoutSerialId: (bigint | number);
    remoteChangeSerialId: (bigint | number);
    refundLocktime: (bigint | number);
    localInputs: TxInInfoRequest[];
    localDlcInputs?: DlcInputInfoRequest[];
    localChangeScriptPubkey: string;
    remoteInputs: TxInInfoRequest[];
    remoteDlcInputs?: DlcInputInfoRequest[];
    remoteChangeScriptPubkey: string;
    feeRate: number;
    cetLockTime?: (bigint | number);
    fundLockTime?: (bigint | number);
    fundOutputSerialId?: (bigint | number);
    optionDest?: string;
    optionPremium?: (bigint | number);
}

export interface CreateSplicedDlcTransactionsResponse {
    fundTxHex: string;
    cetsHex: string[];
    refundTxHex: string;
}

export interface DlcInputInfoRequest {
    fundTxid: string;
    fundVout: number;
    fundAmount: (bigint | number);
    localFundPubkey: string;
    remoteFundPubkey: string;
    maxWitnessLength: number;
    inputSerialId?: (bigint | number);
}

export interface ErrorResponse {
    error: InnerErrorResponse;
}

/** Get raw DLC funding input signature */
export interface GetRawDlcFundingInputSignatureRequest {
    fundTxHex: string;
    fundTxid: string;
    fundVout: number;
    fundAmount: (bigint | number);
    localFundPubkey: string;
    remoteFundPubkey: string;
    privkey: string;
}

export interface GetRawDlcFundingInputSignatureResponse {
    hex: string;
}

/** Get a signature for a fund transaction input */
export interface GetRawFundTxSignatureRequest {
    fundTxHex: string;
    privkey: string;
    prevTxId: string;
    prevVout: number;
    amount: (bigint | number);
}

export interface GetRawFundTxSignatureResponse {
    hex: string;
}

/** Get a signature for a CET */
export interface GetRawRefundTxSignatureRequest {
    refundTxHex: string;
    privkey: string;
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: (bigint | number);
}

export interface GetRawRefundTxSignatureResponse {
    hex: string;
}

export interface InnerErrorResponse {
    code: number;
    type: string;
    message: string;
}

export interface Messages {
    messages: string[];
}

export interface PayoutRequest {
    local: (bigint | number);
    remote: (bigint | number);
}

/** Sign a CET */
export interface SignCetRequest {
    cetHex: string;
    fundPrivkey: string;
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: (bigint | number);
    adaptorSignature: string;
    oracleSignatures: string[];
}

export interface SignCetResponse {
    hex: string;
}

/** Sign DLC funding input */
export interface SignDlcFundingInputRequest {
    fundTxHex: string;
    fundTxid: string;
    fundVout: number;
    fundAmount: (bigint | number);
    localFundPubkey: string;
    remoteFundPubkey: string;
    localPrivkey: string;
    remoteSignature: string;
}

export interface SignDlcFundingInputResponse {
    hex: string;
}

/** Sign a fund transaction input */
export interface SignFundTransactionRequest {
    fundTxHex: string;
    privkey: string;
    prevTxId: string;
    prevVout: number;
    amount: (bigint | number);
}

export interface SignFundTransactionResponse {
    hex: string;
}

export interface TxInInfoRequest {
    txid: string;
    vout: number;
    redeemScript?: string;
    maxWitnessLength: number;
    inputSerialId?: (bigint | number);
}

export interface TxOutRequest {
    amount: (bigint | number);
    address: string;
}

/** Verify a signature for a CET */
export interface VerifyCetAdaptorSignatureRequest {
    cetHex: string;
    adaptorSignature: string;
    adaptorProof: string;
    messages: string[];
    localFundPubkey: string;
    remoteFundPubkey: string;
    oraclePubkey: string;
    oracleRValues: string[];
    fundTxId: string;
    fundVout?: number;
    fundInputAmount: (bigint | number);
    verifyRemote: boolean;
}

export interface VerifyCetAdaptorSignatureResponse {
    valid: boolean;
}

/** Verify a set of signatures for a set of CET */
export interface VerifyCetAdaptorSignaturesRequest {
    cetsHex: string[];
    adaptorPairs: AdaptorPair[];
    messagesList: Messages[];
    localFundPubkey: string;
    remoteFundPubkey: string;
    oraclePubkey: string;
    oracleRValues: string[];
    fundTxId: string;
    fundVout?: number;
    fundInputAmount: (bigint | number);
    verifyRemote: boolean;
}

export interface VerifyCetAdaptorSignaturesResponse {
    valid: boolean;
}

/** Verify DLC funding input signature */
export interface VerifyDlcFundingInputSignatureRequest {
    fundTxHex: string;
    fundTxid: string;
    fundVout: number;
    fundAmount: (bigint | number);
    localFundPubkey: string;
    remoteFundPubkey: string;
    signature: string;
    pubkey: string;
}

export interface VerifyDlcFundingInputSignatureResponse {
    valid: boolean;
}

/** Verify a signature for a mutual closing transaction */
export interface VerifyFundTxSignatureRequest {
    fundTxHex: string;
    signature: string;
    pubkey: string;
    prevTxId: string;
    prevVout: number;
    fundInputAmount: (bigint | number);
}

export interface VerifyFundTxSignatureResponse {
    valid: boolean;
}

/** Verify a signature for a refund transaction */
export interface VerifyRefundTxSignatureRequest {
    refundTxHex: string;
    signature: string;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundTxId: string;
    fundVout?: number;
    fundInputAmount: (bigint | number);
    verifyRemote: boolean;
}

export interface VerifyRefundTxSignatureResponse {
    valid: boolean;
}

/**
 * @param {AddSignaturesToRefundTxRequest} jsonObject - request data.
 * @return {AddSignaturesToRefundTxResponse} - response data.
 */
export function AddSignaturesToRefundTx(jsonObject: AddSignaturesToRefundTxRequest): AddSignaturesToRefundTxResponse;

/**
 * @param {AddSignatureToFundTransactionRequest} jsonObject - request data.
 * @return {AddSignatureToFundTransactionResponse} - response data.
 */
export function AddSignatureToFundTransaction(jsonObject: AddSignatureToFundTransactionRequest): AddSignatureToFundTransactionResponse;

/**
 * @param {CreateBatchDlcTransactionsRequest} jsonObject - request data.
 * @return {CreateBatchDlcTransactionsResponse} - response data.
 */
export function CreateBatchDlcTransactions(jsonObject: CreateBatchDlcTransactionsRequest): CreateBatchDlcTransactionsResponse;

/**
 * @param {CreateBatchFundTransactionRequest} jsonObject - request data.
 * @return {CreateBatchFundTransactionResponse} - response data.
 */
export function CreateBatchFundTransaction(jsonObject: CreateBatchFundTransactionRequest): CreateBatchFundTransactionResponse;

/**
 * @param {CreateCetRequest} jsonObject - request data.
 * @return {CreateCetResponse} - response data.
 */
export function CreateCet(jsonObject: CreateCetRequest): CreateCetResponse;

/**
 * @param {CreateCetAdaptorSignatureRequest} jsonObject - request data.
 * @return {CreateCetAdaptorSignatureResponse} - response data.
 */
export function CreateCetAdaptorSignature(jsonObject: CreateCetAdaptorSignatureRequest): CreateCetAdaptorSignatureResponse;

/**
 * @param {CreateCetAdaptorSignaturesRequest} jsonObject - request data.
 * @return {CreateCetAdaptorSignaturesResponse} - response data.
 */
export function CreateCetAdaptorSignatures(jsonObject: CreateCetAdaptorSignaturesRequest): CreateCetAdaptorSignaturesResponse;

/**
 * @param {CreateDlcTransactionsRequest} jsonObject - request data.
 * @return {CreateDlcTransactionsResponse} - response data.
 */
export function CreateDlcTransactions(jsonObject: CreateDlcTransactionsRequest): CreateDlcTransactionsResponse;

/**
 * @param {CreateFundTransactionRequest} jsonObject - request data.
 * @return {CreateFundTransactionResponse} - response data.
 */
export function CreateFundTransaction(jsonObject: CreateFundTransactionRequest): CreateFundTransactionResponse;

/**
 * @param {CreateRefundTransactionRequest} jsonObject - request data.
 * @return {CreateRefundTransactionResponse} - response data.
 */
export function CreateRefundTransaction(jsonObject: CreateRefundTransactionRequest): CreateRefundTransactionResponse;

/**
 * @param {CreateSplicedDlcTransactionsRequest} jsonObject - request data.
 * @return {CreateSplicedDlcTransactionsResponse} - response data.
 */
export function CreateSplicedDlcTransactions(jsonObject: CreateSplicedDlcTransactionsRequest): CreateSplicedDlcTransactionsResponse;

/**
 * @param {GetRawDlcFundingInputSignatureRequest} jsonObject - request data.
 * @return {GetRawDlcFundingInputSignatureResponse} - response data.
 */
export function GetRawDlcFundingInputSignature(jsonObject: GetRawDlcFundingInputSignatureRequest): GetRawDlcFundingInputSignatureResponse;

/**
 * @param {GetRawFundTxSignatureRequest} jsonObject - request data.
 * @return {GetRawFundTxSignatureResponse} - response data.
 */
export function GetRawFundTxSignature(jsonObject: GetRawFundTxSignatureRequest): GetRawFundTxSignatureResponse;

/**
 * @param {GetRawRefundTxSignatureRequest} jsonObject - request data.
 * @return {GetRawRefundTxSignatureResponse} - response data.
 */
export function GetRawRefundTxSignature(jsonObject: GetRawRefundTxSignatureRequest): GetRawRefundTxSignatureResponse;

/**
 * @param {SignCetRequest} jsonObject - request data.
 * @return {SignCetResponse} - response data.
 */
export function SignCet(jsonObject: SignCetRequest): SignCetResponse;

/**
 * @param {SignDlcFundingInputRequest} jsonObject - request data.
 * @return {SignDlcFundingInputResponse} - response data.
 */
export function SignDlcFundingInput(jsonObject: SignDlcFundingInputRequest): SignDlcFundingInputResponse;

/**
 * @param {SignFundTransactionRequest} jsonObject - request data.
 * @return {SignFundTransactionResponse} - response data.
 */
export function SignFundTransaction(jsonObject: SignFundTransactionRequest): SignFundTransactionResponse;

/**
 * @param {VerifyCetAdaptorSignatureRequest} jsonObject - request data.
 * @return {VerifyCetAdaptorSignatureResponse} - response data.
 */
export function VerifyCetAdaptorSignature(jsonObject: VerifyCetAdaptorSignatureRequest): VerifyCetAdaptorSignatureResponse;

/**
 * @param {VerifyCetAdaptorSignaturesRequest} jsonObject - request data.
 * @return {VerifyCetAdaptorSignaturesResponse} - response data.
 */
export function VerifyCetAdaptorSignatures(jsonObject: VerifyCetAdaptorSignaturesRequest): VerifyCetAdaptorSignaturesResponse;

/**
 * @param {VerifyDlcFundingInputSignatureRequest} jsonObject - request data.
 * @return {VerifyDlcFundingInputSignatureResponse} - response data.
 */
export function VerifyDlcFundingInputSignature(jsonObject: VerifyDlcFundingInputSignatureRequest): VerifyDlcFundingInputSignatureResponse;

/**
 * @param {VerifyFundTxSignatureRequest} jsonObject - request data.
 * @return {VerifyFundTxSignatureResponse} - response data.
 */
export function VerifyFundTxSignature(jsonObject: VerifyFundTxSignatureRequest): VerifyFundTxSignatureResponse;

/**
 * @param {VerifyRefundTxSignatureRequest} jsonObject - request data.
 * @return {VerifyRefundTxSignatureResponse} - response data.
 */
export function VerifyRefundTxSignature(jsonObject: VerifyRefundTxSignatureRequest): VerifyRefundTxSignatureResponse;

/** error class. */
export class CfdDlcError extends Error {
    /**
     * constructor.
     * @param {string} message - Error message.
     * @param {InnerErrorResponse} errorInformation - Error information data.
     * @param {Error} cause - Cause of the error.
     */
    constructor(message: string, errorInformation: InnerErrorResponse, cause: Error);
    /**
     * get error string.
     * @return {string} - string data.
     */
    toString(): string;
    /**
     * get error information.
     * @return {InnerErrorResponse} - InnerErrorResponse data.
     */
    getErrorInformation(): InnerErrorResponse;
    /**
     * get error cause.
     * @return {Error} - Error data.
     */
    getCause(): Error;
}
