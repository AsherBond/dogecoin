<<<<<<< HEAD
#ifndef BITCOINGUI_H
#define BITCOINGUI_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMap>

class TransactionTableModel;
class WalletFrame;
class WalletView;
class ClientModel;
class WalletModel;
class WalletStack;
class TransactionView;
class OverviewPage;
class AddressBookPage;
class SendCoinsDialog;
class SignVerifyMessageDialog;
class Notificator;
class RPCConsole;
=======
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINGUI_H
#define BITCOINGUI_H

#if defined(HAVE_CONFIG_H)
#include "bitcoin-config.h"
#endif

#include <QMainWindow>
#include <QMap>
#include <QSystemTrayIcon>

class ClientModel;
class Notificator;
class RPCConsole;
class SendCoinsRecipient;
class WalletFrame;
class WalletModel;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

class CWallet;

QT_BEGIN_NAMESPACE
<<<<<<< HEAD
class QLabel;
class QModelIndex;
class QProgressBar;
class QStackedWidget;
class QUrl;
class QListWidget;
class QPushButton;
class QAction;
=======
class QAction;
class QLabel;
class QProgressBar;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_END_NAMESPACE

/**
  Bitcoin GUI main class. This class represents the main window of the Bitcoin UI. It communicates with both the client and
  wallet models to give the user an up-to-date view of the current core state.
*/
class BitcoinGUI : public QMainWindow
{
    Q_OBJECT

public:
    static const QString DEFAULT_WALLET;

<<<<<<< HEAD
    explicit BitcoinGUI(QWidget *parent = 0);
=======
    explicit BitcoinGUI(bool fIsTestnet = false, QWidget *parent = 0);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ~BitcoinGUI();

    /** Set the client model.
        The client model represents the part of the core that communicates with the P2P network, and is wallet-agnostic.
    */
    void setClientModel(ClientModel *clientModel);
<<<<<<< HEAD
=======

#ifdef ENABLE_WALLET
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    /** Set the wallet model.
        The wallet model represents a bitcoin wallet, and offers access to the list of transactions, address book and sending
        functionality.
    */
<<<<<<< HEAD

    bool addWallet(const QString& name, WalletModel *walletModel);
    bool setCurrentWallet(const QString& name);

    void removeAllWallets();

    /** Used by WalletView to allow access to needed QActions */
    // Todo: Use Qt signals for these
    QAction * getOverviewAction() { return overviewAction; }
    QAction * getHistoryAction() { return historyAction; }
    QAction * getAddressBookAction() { return addressBookAction; }
    QAction * getReceiveCoinsAction() { return receiveCoinsAction; }
    QAction * getSendCoinsAction() { return sendCoinsAction; }
=======
    bool addWallet(const QString& name, WalletModel *walletModel);
    bool setCurrentWallet(const QString& name);
    void removeAllWallets();
#endif
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    bool eventFilter(QObject *object, QEvent *event);

private:
    ClientModel *clientModel;
    WalletFrame *walletFrame;

    QLabel *labelEncryptionIcon;
    QLabel *labelConnectionsIcon;
    QLabel *labelBlocksIcon;
    QLabel *progressBarLabel;
    QProgressBar *progressBar;

    QMenuBar *appMenuBar;
    QAction *overviewAction;
    QAction *historyAction;
    QAction *quitAction;
    QAction *sendCoinsAction;
<<<<<<< HEAD
    QAction *addressBookAction;
=======
    QAction *usedSendingAddressesAction;
    QAction *usedReceivingAddressesAction;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    QAction *signMessageAction;
    QAction *verifyMessageAction;
    QAction *aboutAction;
    QAction *receiveCoinsAction;
    QAction *optionsAction;
    QAction *toggleHideAction;
    QAction *encryptWalletAction;
    QAction *backupWalletAction;
    QAction *changePassphraseAction;
    QAction *aboutQtAction;
    QAction *openRPCConsoleAction;
<<<<<<< HEAD

    QSystemTrayIcon *trayIcon;
    Notificator *notificator;
    TransactionView *transactionView;
    RPCConsole *rpcConsole;

    QMovie *syncIconMovie;
    /** Keep track of previous number of blocks, to detect progress */
    int prevBlocks;

    /** Create the main UI actions. */
    void createActions();
=======
    QAction *openAction;
    QAction *showHelpMessageAction;

    QSystemTrayIcon *trayIcon;
    Notificator *notificator;
    RPCConsole *rpcConsole;

    /** Keep track of previous number of blocks, to detect progress */
    int prevBlocks;
    int spinnerFrame;

    /** Create the main UI actions. */
    void createActions(bool fIsTestnet);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    /** Create the menu bar and sub-menus. */
    void createMenuBar();
    /** Create the toolbars */
    void createToolBars();
    /** Create system tray icon and notification */
<<<<<<< HEAD
    void createTrayIcon();
    /** Create system tray menu (or setup the dock menu) */
    void createTrayIconMenu();
    /** Save window size and position */
    void saveWindowGeometry();
    /** Restore window size and position */
    void restoreWindowGeometry();
    /** Enable or disable all wallet-related actions */
    void setWalletActionsEnabled(bool enabled);

=======
    void createTrayIcon(bool fIsTestnet);
    /** Create system tray menu (or setup the dock menu) */
    void createTrayIconMenu();

    /** Enable or disable all wallet-related actions */
    void setWalletActionsEnabled(bool enabled);

    /** Connect core signals to GUI client */
    void subscribeToCoreSignals();
    /** Disconnect core signals from GUI client */
    void unsubscribeFromCoreSignals();

signals:
    /** Signal raised when a URI was entered or dragged to the GUI */
    void receivedURI(const QString &uri);

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
public slots:
    /** Set number of connections shown in the UI */
    void setNumConnections(int count);
    /** Set number of blocks shown in the UI */
    void setNumBlocks(int count, int nTotalBlocks);
<<<<<<< HEAD
    /** Set the encryption status as shown in the UI.
       @param[in] status            current encryption status
       @see WalletModel::EncryptionStatus
    */
    void setEncryptionStatus(int status);
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    /** Notify the user of an event from the core network or transaction handling code.
       @param[in] title     the message box / notification title
       @param[in] message   the displayed text
       @param[in] style     modality and style definitions (icon and used buttons - buttons only for message boxes)
                            @see CClientUIInterface::MessageBoxFlags
       @param[in] ret       pointer to a bool that will be modified to whether Ok was clicked (modal only)
    */
    void message(const QString &title, const QString &message, unsigned int style, bool *ret = NULL);
<<<<<<< HEAD
    /** Asks the user whether to pay the transaction fee or to cancel the transaction.
       It is currently not possible to pass a return value to another thread through
       BlockingQueuedConnection, so an indirected pointer is used.
       https://bugreports.qt-project.org/browse/QTBUG-10440

      @param[in] nFeeRequired       the required fee
      @param[out] payFee            true to pay the fee, false to not pay the fee
    */
    void askFee(qint64 nFeeRequired, bool *payFee);
    void handleURI(QString strURI);

    /** Show incoming transaction notification for new transactions. */
    void incomingTransaction(const QString& date, int unit, qint64 amount, const QString& type, const QString& address);

private slots:
=======

#ifdef ENABLE_WALLET
    /** Set the encryption status as shown in the UI.
       @param[in] status            current encryption status
       @see WalletModel::EncryptionStatus
    */
    void setEncryptionStatus(int status);

    bool handlePaymentRequest(const SendCoinsRecipient& recipient);

    /** Show incoming transaction notification for new transactions. */
    void incomingTransaction(const QString& date, int unit, qint64 amount, const QString& type, const QString& address);
#endif

private slots:
#ifdef ENABLE_WALLET
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
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

<<<<<<< HEAD
=======
    /** Show open dialog */
    void openClicked();
#endif
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    /** Show configuration dialog */
    void optionsClicked();
    /** Show about dialog */
    void aboutClicked();
<<<<<<< HEAD
=======
    /** Show help message dialog */
    void showHelpMessageClicked();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef Q_OS_MAC
    /** Handle tray icon clicked */
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
#endif

    /** Show window if hidden, unminimize when minimized, rise when obscured or show if hidden and fToggleHidden is true */
    void showNormalIfMinimized(bool fToggleHidden = false);
    /** Simply calls showNormalIfMinimized(true) for use in SLOT() macro */
    void toggleHidden();

    /** called by a timer to check if fRequestShutdown has been set **/
    void detectShutdown();
};

#endif // BITCOINGUI_H
