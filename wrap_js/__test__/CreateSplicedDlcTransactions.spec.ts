import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateSplicedDlcTransactions",
    cfddlcjs.CreateSplicedDlcTransactions,
    {
      payouts: [
        {
          local: TestData.WinAmount,
          remote: TestData.LoseAmount,
        },
        {
          local: TestData.LoseAmount,
          remote: TestData.WinAmount,
        },
      ],
      localFundPubkey: TestData.LocalFundPubkey,
      localFinalScriptPubkey: TestData.LocalFinalScriptPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      remoteFinalScriptPubkey: TestData.RemoteFinalScriptPubkey,
      localInputAmount: TestData.LocalInputAmount,
      localCollateralAmount: TestData.LocalCollateralAmount,
      localPayoutSerialId: TestData.LocalPayoutSerialId,
      localChangeSerialId: TestData.LocalChangeSerialId,
      remoteInputAmount: TestData.RemoteInputAmount,
      remoteCollateralAmount: TestData.RemoteCollateralAmount,
      remotePayoutSerialId: TestData.RemotePayoutSerialId,
      remoteChangeSerialId: TestData.RemoteChangeSerialId,
      refundLocktime: TestData.RefundLocktime,
      localInputs: [
        {
          txid: TestData.LocalInputs[0].txid,
          vout: TestData.LocalInputs[0].vout,
          maxWitnessLength: TestData.LocalInputs[0].maxWitnessLength,
          redeemScript: TestData.LocalInputs[0].redeemScript,
          inputSerialId: TestData.LocalInputs[0].inputSerialId,
        },
      ],
      localDlcInputs: [
        {
          fundTxid:
            "83266d6b22a9babf6ee469b88fd0d3a0c690525f7c903aff22ec8ee44214604f",
          fundVout: 0,
          fundAmount: 10000000,
          localFundPubkey: TestData.LocalFundPubkey,
          remoteFundPubkey: TestData.RemoteFundPubkey,
          maxWitnessLength: 220,
          inputSerialId: 1,
        },
      ],
      localChangeScriptPubkey: TestData.LocalChangeScriptPubkey,
      remoteInputs: [
        {
          txid: TestData.RemoteInputs[0].txid,
          vout: TestData.RemoteInputs[0].vout,
          maxWitnessLength: TestData.RemoteInputs[0].maxWitnessLength,
          redeemScript: TestData.RemoteInputs[0].redeemScript,
          inputSerialId: TestData.RemoteInputs[0].inputSerialId,
        },
      ],
      remoteDlcInputs: [], // No remote DLC inputs for this test
      remoteChangeScriptPubkey: TestData.RemoteChangeScriptPubkey,
      feeRate: TestData.FeeRate,
      fundLockTime: TestData.FundLockTime,
      cetLockTime: TestData.CetLockTime,
      fundOutputSerialId: TestData.FundOutputSerialId,
    },
    {
      fundTxHex: "02000000034f601442e48eec22ff3a907c5f5290c6a0d3d08fb869e46ebfbaa9226b6d26830000000000ffffffff98bbd477219a151a1daf5377b30e8c5f9fb574783943f33ac523ef072fa292bc0000000000ffffffff4f601442e48eec22ff3a907c5f5290c6a0d3d08fb869e46ebfbaa9226b6d26830000000000ffffffff03aac2eb0b000000002200209b984c7bae3efddc3a3f0a20ff81bfe89ed1fe07ff13e562149ee654bed845db4da6a82401000000160014fa3629f3060b6c1a5a365c30bf66fa00f155cb9e2d1010240100000016001465d4d622585baf5151de860b1e7af58710f20da200000000",
      cetsHex: [
        "020000000146246284ff0ac74f2b660fff3e7f286700275a7cce9d2edc4c3abe02ccb22aad0000000000ffffffff02603bea0b000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f69a0860100000000001600149652d86bedf43ad264362e6e6eba6eb76450812700000000",
        "020000000146246284ff0ac74f2b660fff3e7f286700275a7cce9d2edc4c3abe02ccb22aad0000000000ffffffff02a0860100000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f69603bea0b000000001600149652d86bedf43ad264362e6e6eba6eb76450812700000000",
      ],
      refundTxHex: "020000000146246284ff0ac74f2b660fff3e7f286700275a7cce9d2edc4c3abe02ccb22aad0000000000feffffff0200e1f505000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f6900e1f505000000001600149652d86bedf43ad264362e6e6eba6eb76450812764000000",
    }
  ),
  TestHelper.createTestCase(
    "CreateSplicedDlcTransactions invalid DLC input",
    cfddlcjs.CreateSplicedDlcTransactions,
    {
      payouts: [
        {
          local: TestData.WinAmount,
          remote: TestData.LoseAmount,
        },
        {
          local: TestData.LoseAmount,
          remote: TestData.WinAmount,
        },
      ],
      localFundPubkey: TestData.LocalFundPubkey,
      localFinalScriptPubkey: TestData.LocalFinalScriptPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      remoteFinalScriptPubkey: TestData.RemoteFinalScriptPubkey,
      localInputAmount: TestData.LocalInputAmount,
      localCollateralAmount: TestData.LocalCollateralAmount,
      localPayoutSerialId: TestData.LocalPayoutSerialId,
      localChangeSerialId: TestData.LocalChangeSerialId,
      remoteInputAmount: TestData.RemoteInputAmount,
      remoteCollateralAmount: TestData.RemoteCollateralAmount,
      remotePayoutSerialId: TestData.RemotePayoutSerialId,
      remoteChangeSerialId: TestData.RemoteChangeSerialId,
      refundLocktime: TestData.RefundLocktime,
      localInputs: [
        {
          txid: TestData.LocalInputs[0].txid,
          vout: TestData.LocalInputs[0].vout,
          maxWitnessLength: TestData.LocalInputs[0].maxWitnessLength,
          redeemScript: TestData.LocalInputs[0].redeemScript,
          inputSerialId: TestData.LocalInputs[0].inputSerialId,
        },
      ],
      localDlcInputs: [
        {
          fundTxid: "invalid_txid",
          fundVout: 0,
          fundAmount: 10000000,
          localFundPubkey: TestData.LocalFundPubkey,
          remoteFundPubkey: TestData.RemoteFundPubkey,
          maxWitnessLength: 220,
          inputSerialId: 1,
        },
      ],
      localChangeScriptPubkey: TestData.LocalChangeScriptPubkey,
      remoteInputs: [
        {
          txid: TestData.RemoteInputs[0].txid,
          vout: TestData.RemoteInputs[0].vout,
          maxWitnessLength: TestData.RemoteInputs[0].maxWitnessLength,
          redeemScript: TestData.RemoteInputs[0].redeemScript,
          inputSerialId: TestData.RemoteInputs[0].inputSerialId,
        },
      ],
      remoteDlcInputs: [],
      remoteChangeScriptPubkey: TestData.RemoteChangeScriptPubkey,
      feeRate: TestData.FeeRate,
      fundLockTime: TestData.FundLockTime,
      cetLockTime: TestData.CetLockTime,
      fundOutputSerialId: TestData.FundOutputSerialId,
    },
    TestHelper.createIllegalArgumentError("hex to byte convert error.")
  ),
];

TestHelper.doTest("CreateSplicedDlcTransactions", testCase);
