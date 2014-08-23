<<<<<<< HEAD
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef TRANSACTIONRECORD_H
#define TRANSACTIONRECORD_H

#include "uint256.h"

#include <QList>
<<<<<<< HEAD
=======
#include <QString>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

class CWallet;
class CWalletTx;

/** UI model for transaction status. The transaction status is the part of a transaction that will change over time.
 */
class TransactionStatus
{
public:
    TransactionStatus():
<<<<<<< HEAD
        confirmed(false), sortKey(""), maturity(Mature),
        matures_in(0), status(Offline), depth(0), open_for(0), cur_num_blocks(-1)
    { }

    enum Maturity
    {
        Immature,
        Mature,
        MaturesWarning, /**< Transaction will likely not mature because no nodes have confirmed */
        NotAccepted
    };

    enum Status {
        OpenUntilDate,
        OpenUntilBlock,
        Offline,
        Unconfirmed,
        HaveConfirmations
    };

    bool confirmed;
=======
        countsForBalance(false), sortKey(""),
        matures_in(0), status(Offline), depth(0), open_for(0), cur_num_blocks(-1)
    { }

    enum Status {
        Confirmed,          /**< Have 6 or more confirmations (normal tx) or fully mature (mined tx) **/
        /// Normal (sent/received) transactions
        OpenUntilDate,      /**< Transaction not yet final, waiting for date */
        OpenUntilBlock,     /**< Transaction not yet final, waiting for block */
        Offline,            /**< Not sent to any other nodes **/
        Unconfirmed,        /**< Not yet mined into a block **/
        Confirming,         /**< Confirmed, but waiting for the recommended number of confirmations **/
        Conflicted,         /**< Conflicts with other transaction or mempool **/
        /// Generated (mined) transactions
        Immature,           /**< Mined but waiting for maturity */
        MaturesWarning,     /**< Transaction will likely not mature because no nodes have confirmed */
        NotAccepted         /**< Mined but not accepted */
    };

    /// Transaction counts towards available balance
    bool countsForBalance;
    /// Sorting key based on status
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    std::string sortKey;

    /** @name Generated (mined) transactions
       @{*/
<<<<<<< HEAD
    Maturity maturity;
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    int matures_in;
    /**@}*/

    /** @name Reported status
       @{*/
    Status status;
<<<<<<< HEAD
    int64 depth;
    int64 open_for; /**< Timestamp if status==OpenUntilDate, otherwise number
=======
    qint64 depth;
    qint64 open_for; /**< Timestamp if status==OpenUntilDate, otherwise number
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                      of additional blocks that need to be mined before
                      finalization */
    /**@}*/

    /** Current number of blocks (to know whether cached status is still valid) */
    int cur_num_blocks;
};

/** UI model for a transaction. A core transaction can be represented by multiple UI transactions if it has
    multiple outputs.
 */
class TransactionRecord
{
public:
    enum Type
    {
        Other,
        Generated,
        SendToAddress,
        SendToOther,
        RecvWithAddress,
        RecvFromOther,
        SendToSelf
    };

<<<<<<< HEAD
    /** Number of confirmation needed for transaction */
    static const int NumConfirmations = 3;
=======
    /** Number of confirmation recommended for accepting a transaction */
    static const int RecommendedNumConfirmations = 3;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    TransactionRecord():
            hash(), time(0), type(Other), address(""), debit(0), credit(0), idx(0)
    {
    }

<<<<<<< HEAD
    TransactionRecord(uint256 hash, int64 time):
=======
    TransactionRecord(uint256 hash, qint64 time):
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            hash(hash), time(time), type(Other), address(""), debit(0),
            credit(0), idx(0)
    {
    }

<<<<<<< HEAD
    TransactionRecord(uint256 hash, int64 time,
                Type type, const std::string &address,
                int64 debit, int64 credit):
            hash(hash), time(time), type(type), address(address), debit(debit), credit(credit), idx(0)
=======
    TransactionRecord(uint256 hash, qint64 time,
                Type type, const std::string &address,
                qint64 debit, qint64 credit):
            hash(hash), time(time), type(type), address(address), debit(debit), credit(credit),
            idx(0)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
    }

    /** Decompose CWallet transaction to model transaction records.
     */
    static bool showTransaction(const CWalletTx &wtx);
    static QList<TransactionRecord> decomposeTransaction(const CWallet *wallet, const CWalletTx &wtx);

    /** @name Immutable transaction attributes
      @{*/
    uint256 hash;
<<<<<<< HEAD
    int64 time;
    Type type;
    std::string address;
    int64 debit;
    int64 credit;
=======
    qint64 time;
    Type type;
    std::string address;
    qint64 debit;
    qint64 credit;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    /**@}*/

    /** Subtransaction index, for sort key */
    int idx;

    /** Status: can change with block chain update */
    TransactionStatus status;

    /** Return the unique identifier for this transaction (part) */
<<<<<<< HEAD
    std::string getTxID();
=======
    QString getTxID() const;

    /** Format subtransaction id */
    static QString formatSubTxId(const uint256 &hash, int vout);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    /** Update status from core wallet tx.
     */
    void updateStatus(const CWalletTx &wtx);

    /** Return whether a status update is needed.
     */
    bool statusUpdateNeeded();
};

#endif // TRANSACTIONRECORD_H
