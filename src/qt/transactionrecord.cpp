<<<<<<< HEAD
#include "transactionrecord.h"

#include "wallet.h"
#include "base58.h"
=======
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "transactionrecord.h"

#include "base58.h"
#include "wallet.h"

#include <stdint.h>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

/* Return positive answer if transaction should be shown in list.
 */
bool TransactionRecord::showTransaction(const CWalletTx &wtx)
{
    if (wtx.IsCoinBase())
    {
        // Ensures we show generated coins / mined transactions at depth 1
        if (!wtx.IsInMainChain())
        {
            return false;
        }
    }
    return true;
}

/*
 * Decompose CWallet transaction to model transaction records.
 */
QList<TransactionRecord> TransactionRecord::decomposeTransaction(const CWallet *wallet, const CWalletTx &wtx)
{
    QList<TransactionRecord> parts;
<<<<<<< HEAD
    int64 nTime = wtx.GetTxTime();
    int64 nCredit = wtx.GetCredit(true);
    int64 nDebit = wtx.GetDebit();
    int64 nNet = nCredit - nDebit;
=======
    int64_t nTime = wtx.GetTxTime();
    int64_t nCredit = wtx.GetCredit(true);
    int64_t nDebit = wtx.GetDebit();
    int64_t nNet = nCredit - nDebit;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    uint256 hash = wtx.GetHash();
    std::map<std::string, std::string> mapValue = wtx.mapValue;

    if (nNet > 0 || wtx.IsCoinBase())
    {
        //
        // Credit
        //
        BOOST_FOREACH(const CTxOut& txout, wtx.vout)
        {
            if(wallet->IsMine(txout))
            {
                TransactionRecord sub(hash, nTime);
                CTxDestination address;
                sub.idx = parts.size(); // sequence number
                sub.credit = txout.nValue;
                if (ExtractDestination(txout.scriptPubKey, address) && IsMine(*wallet, address))
                {
<<<<<<< HEAD
                    // Received by Bitcoin Address
=======
                    // Received by Dogecoin Address
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    sub.type = TransactionRecord::RecvWithAddress;
                    sub.address = CBitcoinAddress(address).ToString();
                }
                else
                {
                    // Received by IP connection (deprecated features), or a multisignature or other non-simple transaction
                    sub.type = TransactionRecord::RecvFromOther;
                    sub.address = mapValue["from"];
                }
                if (wtx.IsCoinBase())
                {
                    // Generated
                    sub.type = TransactionRecord::Generated;
                }

                parts.append(sub);
            }
        }
    }
    else
    {
        bool fAllFromMe = true;
        BOOST_FOREACH(const CTxIn& txin, wtx.vin)
            fAllFromMe = fAllFromMe && wallet->IsMine(txin);

        bool fAllToMe = true;
        BOOST_FOREACH(const CTxOut& txout, wtx.vout)
            fAllToMe = fAllToMe && wallet->IsMine(txout);

        if (fAllFromMe && fAllToMe)
        {
            // Payment to self
<<<<<<< HEAD
            int64 nChange = wtx.GetChange();
=======
            int64_t nChange = wtx.GetChange();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

            parts.append(TransactionRecord(hash, nTime, TransactionRecord::SendToSelf, "",
                            -(nDebit - nChange), nCredit - nChange));
        }
        else if (fAllFromMe)
        {
            //
            // Debit
            //
<<<<<<< HEAD
            int64 nTxFee = nDebit - wtx.GetValueOut();
=======
            int64_t nTxFee = nDebit - wtx.GetValueOut();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

            for (unsigned int nOut = 0; nOut < wtx.vout.size(); nOut++)
            {
                const CTxOut& txout = wtx.vout[nOut];
                TransactionRecord sub(hash, nTime);
                sub.idx = parts.size();

                if(wallet->IsMine(txout))
                {
                    // Ignore parts sent to self, as this is usually the change
                    // from a transaction sent back to our own address.
                    continue;
                }

                CTxDestination address;
                if (ExtractDestination(txout.scriptPubKey, address))
                {
<<<<<<< HEAD
                    // Sent to Bitcoin Address
=======
                    // Sent to Dogecoin Address
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    sub.type = TransactionRecord::SendToAddress;
                    sub.address = CBitcoinAddress(address).ToString();
                }
                else
                {
                    // Sent to IP, or other non-address transaction like OP_EVAL
                    sub.type = TransactionRecord::SendToOther;
                    sub.address = mapValue["to"];
                }

<<<<<<< HEAD
                int64 nValue = txout.nValue;
=======
                int64_t nValue = txout.nValue;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                /* Add fee to first output */
                if (nTxFee > 0)
                {
                    nValue += nTxFee;
                    nTxFee = 0;
                }
                sub.debit = -nValue;

                parts.append(sub);
            }
        }
        else
        {
            //
            // Mixed debit transaction, can't break down payees
            //
            parts.append(TransactionRecord(hash, nTime, TransactionRecord::Other, "", nNet, 0));
        }
    }

    return parts;
}

void TransactionRecord::updateStatus(const CWalletTx &wtx)
{
    // Determine transaction status

    // Find the block the tx is in
    CBlockIndex* pindex = NULL;
    std::map<uint256, CBlockIndex*>::iterator mi = mapBlockIndex.find(wtx.hashBlock);
    if (mi != mapBlockIndex.end())
        pindex = (*mi).second;

    // Sort order, unrecorded transactions sort to the top
    status.sortKey = strprintf("%010d-%01d-%010u-%03d",
        (pindex ? pindex->nHeight : std::numeric_limits<int>::max()),
        (wtx.IsCoinBase() ? 1 : 0),
        wtx.nTimeReceived,
        idx);
<<<<<<< HEAD
    status.confirmed = wtx.IsConfirmed();
    status.depth = wtx.GetDepthInMainChain();
    status.cur_num_blocks = nBestHeight;

    if (!wtx.IsFinal())
=======
    status.countsForBalance = wtx.IsTrusted() && !(wtx.GetBlocksToMaturity() > 0);
    status.depth = wtx.GetDepthInMainChain();
    status.cur_num_blocks = chainActive.Height();

    if (!IsFinalTx(wtx, chainActive.Height() + 1))
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        if (wtx.nLockTime < LOCKTIME_THRESHOLD)
        {
            status.status = TransactionStatus::OpenUntilBlock;
<<<<<<< HEAD
            status.open_for = wtx.nLockTime - nBestHeight + 1;
=======
            status.open_for = wtx.nLockTime - chainActive.Height();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
        else
        {
            status.status = TransactionStatus::OpenUntilDate;
            status.open_for = wtx.nLockTime;
        }
    }
<<<<<<< HEAD
    else
    {
        if (GetAdjustedTime() - wtx.nTimeReceived > 2 * 60 && wtx.GetRequestCount() == 0)
        {
            status.status = TransactionStatus::Offline;
        }
        else if (status.depth < NumConfirmations)
        {
            status.status = TransactionStatus::Unconfirmed;
        }
        else
        {
            status.status = TransactionStatus::HaveConfirmations;
        }
    }

    // For generated transactions, determine maturity
    if(type == TransactionRecord::Generated)
    {
        int64 nCredit = wtx.GetCredit(true);
        if (nCredit == 0)
        {
            status.maturity = TransactionStatus::Immature;
=======
    // For generated transactions, determine maturity
    else if(type == TransactionRecord::Generated)
    {
        if (wtx.GetBlocksToMaturity() > 0)
        {
            status.status = TransactionStatus::Immature;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

            if (wtx.IsInMainChain())
            {
                status.matures_in = wtx.GetBlocksToMaturity();

                // Check if the block was requested by anyone
                if (GetAdjustedTime() - wtx.nTimeReceived > 2 * 60 && wtx.GetRequestCount() == 0)
<<<<<<< HEAD
                    status.maturity = TransactionStatus::MaturesWarning;
            }
            else
            {
                status.maturity = TransactionStatus::NotAccepted;
=======
                    status.status = TransactionStatus::MaturesWarning;
            }
            else
            {
                status.status = TransactionStatus::NotAccepted;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            }
        }
        else
        {
<<<<<<< HEAD
            status.maturity = TransactionStatus::Mature;
        }
    }
=======
            status.status = TransactionStatus::Confirmed;
        }
    }
    else
    {
        if (status.depth < 0)
        {
            status.status = TransactionStatus::Conflicted;
        }
        else if (GetAdjustedTime() - wtx.nTimeReceived > 2 * 60 && wtx.GetRequestCount() == 0)
        {
            status.status = TransactionStatus::Offline;
        }
        else if (status.depth == 0)
        {
            status.status = TransactionStatus::Unconfirmed;
        }
        else if (status.depth < RecommendedNumConfirmations)
        {
            status.status = TransactionStatus::Confirming;
        }
        else
        {
            status.status = TransactionStatus::Confirmed;
        }
    }

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

bool TransactionRecord::statusUpdateNeeded()
{
<<<<<<< HEAD
    return status.cur_num_blocks != nBestHeight;
}

std::string TransactionRecord::getTxID()
{
    return hash.ToString(); // + strprintf("-%03d", idx);
=======
    return status.cur_num_blocks != chainActive.Height();
}

QString TransactionRecord::getTxID() const
{
    return formatSubTxId(hash, idx);
}

QString TransactionRecord::formatSubTxId(const uint256 &hash, int vout)
{
    return QString::fromStdString(hash.ToString() + strprintf("-%03d", vout));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

