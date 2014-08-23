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
#ifndef WALLETFRAME_H
#define WALLETFRAME_H

#include <QFrame>
<<<<<<< HEAD

class BitcoinGUI;
class ClientModel;
class WalletModel;
class WalletStack;
class WalletView;

=======
#include <QMap>

class BitcoinGUI;
class ClientModel;
class SendCoinsRecipient;
class WalletModel;
class WalletView;

QT_BEGIN_NAMESPACE
class QStackedWidget;
QT_END_NAMESPACE

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
class WalletFrame : public QFrame
{
    Q_OBJECT

public:
    explicit WalletFrame(BitcoinGUI *_gui = 0);
    ~WalletFrame();

    void setClientModel(ClientModel *clientModel);

    bool addWallet(const QString& name, WalletModel *walletModel);
    bool setCurrentWallet(const QString& name);
<<<<<<< HEAD

    void removeAllWallets();

    bool handleURI(const QString &uri);
=======
    bool removeWallet(const QString &name);
    void removeAllWallets();

    bool handlePaymentRequest(const SendCoinsRecipient& recipient);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    void showOutOfSyncWarning(bool fShow);

private:
<<<<<<< HEAD
    BitcoinGUI *gui;
    ClientModel *clientModel;
    WalletStack *walletStack;
=======
    QStackedWidget *walletStack;
    BitcoinGUI *gui;
    ClientModel *clientModel;
    QMap<QString, WalletView*> mapWalletViews;

    bool bOutOfSync;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    WalletView *currentWalletView();

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

    /** Encrypt the wallet */
    void encryptWallet(bool status);
    /** Backup the wallet */
    void backupWallet();
    /** Change encrypted wallet passphrase */
    void changePassphrase();
    /** Ask for passphrase to unlock wallet temporarily */
    void unlockWallet();

<<<<<<< HEAD
    /** Set the encryption status as shown in the UI.
     @param[in] status            current encryption status
     @see WalletModel::EncryptionStatus
     */
    void setEncryptionStatus();
=======
    /** Show used sending addresses */
    void usedSendingAddresses();
    /** Show used receiving addresses */
    void usedReceivingAddresses();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
};

#endif // WALLETFRAME_H
