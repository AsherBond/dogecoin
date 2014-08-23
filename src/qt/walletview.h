<<<<<<< HEAD
/*
 * Qt4 bitcoin GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 */
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef WALLETVIEW_H
#define WALLETVIEW_H

#include <QStackedWidget>

class BitcoinGUI;
class ClientModel;
<<<<<<< HEAD
class WalletModel;
class TransactionView;
class OverviewPage;
class AddressBookPage;
class SendCoinsDialog;
class SignVerifyMessageDialog;
class RPCConsole;

QT_BEGIN_NAMESPACE
class QLabel;
=======
class OverviewPage;
class ReceiveCoinsDialog;
class SendCoinsDialog;
class SendCoinsRecipient;
class TransactionView;
class WalletModel;

QT_BEGIN_NAMESPACE
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
class QModelIndex;
QT_END_NAMESPACE

/*
  WalletView class. This class represents the view to a single wallet.
  It was added to support multiple wallet functionality. Each wallet gets its own WalletView instance.
  It communicates with both the client and the wallet models to give the user an up-to-date view of the
  current core state.
*/
class WalletView : public QStackedWidget
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit WalletView(QWidget *parent, BitcoinGUI *_gui);
=======
    explicit WalletView(QWidget *parent);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ~WalletView();

    void setBitcoinGUI(BitcoinGUI *gui);
    /** Set the client model.
        The client model represents the part of the core that communicates with the P2P network, and is wallet-agnostic.
    */
    void setClientModel(ClientModel *clientModel);
    /** Set the wallet model.
        The wallet model represents a bitcoin wallet, and offers access to the list of transactions, address book and sending
        functionality.
    */
    void setWalletModel(WalletModel *walletModel);

<<<<<<< HEAD
    bool handleURI(const QString &uri);
=======
    bool handlePaymentRequest(const SendCoinsRecipient& recipient);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    void showOutOfSyncWarning(bool fShow);

private:
<<<<<<< HEAD
    BitcoinGUI *gui;
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ClientModel *clientModel;
    WalletModel *walletModel;

    OverviewPage *overviewPage;
    QWidget *transactionsPage;
<<<<<<< HEAD
    AddressBookPage *addressBookPage;
    AddressBookPage *receiveCoinsPage;
    SendCoinsDialog *sendCoinsPage;
    SignVerifyMessageDialog *signVerifyMessageDialog;
=======
    ReceiveCoinsDialog *receiveCoinsPage;
    SendCoinsDialog *sendCoinsPage;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    TransactionView *transactionView;

public slots:
    /** Switch to overview (home) page */
    void gotoOverviewPage();
    /** Switch to history (transactions) page */
    void gotoHistoryPage();
<<<<<<< HEAD
    /** Switch to address book page */
    void gotoAddressBookPage();
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    /** Switch to receive coins page */
    void gotoReceiveCoinsPage();
    /** Switch to send coins page */
    void gotoSendCoinsPage(QString addr = "");

    /** Show Sign/Verify Message dialog and switch to sign message tab */
    void gotoSignMessageTab(QString addr = "");
    /** Show Sign/Verify Message dialog and switch to verify message tab */
    void gotoVerifyMessageTab(QString addr = "");

    /** Show incoming transaction notification for new transactions.

        The new items are those between start and end inclusive, under the given parent item.
    */
<<<<<<< HEAD
    void incomingTransaction(const QModelIndex& parent, int start, int /*end*/);
=======
    void processNewTransaction(const QModelIndex& parent, int start, int /*end*/);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    /** Encrypt the wallet */
    void encryptWallet(bool status);
    /** Backup the wallet */
    void backupWallet();
    /** Change encrypted wallet passphrase */
    void changePassphrase();
    /** Ask for passphrase to unlock wallet temporarily */
    void unlockWallet();

<<<<<<< HEAD
    void setEncryptionStatus();
=======
    /** Show used sending addresses */
    void usedSendingAddresses();
    /** Show used receiving addresses */
    void usedReceivingAddresses();

    /** Re-emit encryption status signal */
    void updateEncryptionStatus();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

signals:
    /** Signal that we want to show the main window */
    void showNormalIfMinimized();
<<<<<<< HEAD
=======
    /**  Fired when a message should be reported to the user */
    void message(const QString &title, const QString &message, unsigned int style);
    /** Encryption status of wallet changed */
    void encryptionStatusChanged(int status);
    /** Notify that a new transaction appeared */
    void incomingTransaction(const QString& date, int unit, qint64 amount, const QString& type, const QString& address);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
};

#endif // WALLETVIEW_H
