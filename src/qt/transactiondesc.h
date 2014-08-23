<<<<<<< HEAD
#ifndef TRANSACTIONDESC_H
#define TRANSACTIONDESC_H

#include <QString>
#include <QObject>
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRANSACTIONDESC_H
#define TRANSACTIONDESC_H

#include <QObject>
#include <QString>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

class CWallet;
class CWalletTx;

/** Provide a human-readable extended HTML description of a transaction.
 */
class TransactionDesc: public QObject
{
    Q_OBJECT

public:
<<<<<<< HEAD
    static QString toHTML(CWallet *wallet, CWalletTx &wtx);
=======
    static QString toHTML(CWallet *wallet, CWalletTx &wtx, int vout, int unit);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

private:
    TransactionDesc() {}

    static QString FormatTxStatus(const CWalletTx& wtx);
};

#endif // TRANSACTIONDESC_H
