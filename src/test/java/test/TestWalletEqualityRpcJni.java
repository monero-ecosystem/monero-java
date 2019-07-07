package test;

import org.junit.Test;

import monero.wallet.MoneroWallet;
import utils.TestUtils;

/**
 * Tests the test rpc and jni wallets for equality.
 */
public class TestWalletEqualityRpcJni {

  @Test
  public void testWalletsEqualRpcJni() {
    MoneroWallet walletRpc = TestUtils.getWalletRpc();
    MoneroWallet walletJni = TestUtils.getWalletJni();
    TestMoneroWalletCommon.testWalletsEqualOnChain(walletRpc, walletJni);
  }
}
