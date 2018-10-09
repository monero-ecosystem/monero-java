package monero.wallet.model;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.math.BigInteger;

/**
 * Represents a payment on the Monero network to an address.
 * 
 * A transaction may have one or more payments.
 */
public class MoneroPayment {

  private MoneroTx tx;
  private MoneroSubaddress destination;
  private BigInteger amount;
  private Boolean isSpent;
  private String keyImage;
  
  public MoneroPayment() {
    super();
  }

  public MoneroTx getTx() {
    return tx;
  }

  public void setTx(MoneroTx tx) {
    this.tx = tx;
  }

  public MoneroSubaddress getDestination() {
    return destination;
  }

  public void setDestination(MoneroSubaddress subaddress) {
    this.destination = subaddress;
  }

  public BigInteger getAmount() {
    return amount;
  }

  public void setAmount(BigInteger amount) {
    this.amount = amount;
  }

  public Boolean getIsSpent() {
    return isSpent;
  }

  public void setIsSpent(Boolean isSpent) {
    this.isSpent = isSpent;
  }

  public String getKeyImage() {
    return keyImage;
  }

  public void setKeyImage(String keyImage) {
    this.keyImage = keyImage;
  }

  /**
   * Merges the given payment into this payment.
   * 
   * Sets uninitialized fields to the given payent. Validates initialized fields are equal.
   * 
   * @param tx is the transaction to merge into this one
   */
  public void merge(MoneroPayment payment) {
    if (tx == null) tx = payment.getTx();
    else if (payment.getTx() != null) tx.merge(payment.getTx());
    if (destination == null) destination = payment.getDestination();
    else if (payment.getDestination() != null) destination.merge(payment.getDestination());
    if (amount == null) amount = payment.getAmount();
    else if (payment.getAmount() != null) assertTrue("Amounts", amount.compareTo(payment.getAmount()) == 0);
    if (isSpent == null) isSpent = payment.getIsSpent();
    else if (payment.getIsSpent() != null) assertEquals("Is spents", isSpent, payment.getIsSpent());
    if (keyImage == null) keyImage = payment.getKeyImage();
    else if (payment.getKeyImage() != null) assertEquals("Key images", keyImage, payment.getKeyImage());
  }

  @Override
  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + ((amount == null) ? 0 : amount.hashCode());
    result = prime * result + ((isSpent == null) ? 0 : isSpent.hashCode());
    result = prime * result + ((keyImage == null) ? 0 : keyImage.hashCode());
    result = prime * result + ((destination == null) ? 0 : destination.hashCode());
    return result;
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) return true;
    if (obj == null) return false;
    if (getClass() != obj.getClass()) return false;
    MoneroPayment other = (MoneroPayment) obj;
    if (amount == null) {
      if (other.amount != null) return false;
    } else if (!amount.equals(other.amount)) return false;
    if (isSpent == null) {
      if (other.isSpent != null) return false;
    } else if (!isSpent.equals(other.isSpent)) return false;
    if (keyImage == null) {
      if (other.keyImage != null) return false;
    } else if (!keyImage.equals(other.keyImage)) return false;
    if (destination == null) {
      if (other.destination != null) return false;
    } else if (!destination.equals(other.destination)) return false;
    return true;
  }
}
