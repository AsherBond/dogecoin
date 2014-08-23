<<<<<<< HEAD
/*
 * Qt4 bitcoin GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 */
#include "walletframe.h"
#include "bitcoingui.h"
#include "walletstack.h"
#include "walletview.h"

#include <QHBoxLayout>
#include <QMessageBox>
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "walletframe.h"

#include "bitcoingui.h"
#include "walletview.h"

#include <cstdio>

#include <QHBoxLayout>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#include <QLabel>

WalletFrame::WalletFrame(BitcoinGUI *_gui) :
    QFrame(_gui),
<<<<<<< HEAD
    gui(_gui),
    clientModel(0)
=======
    gui(_gui)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    // Leave HBox hook for adding a list view later
    QHBoxLayout *walletFrameLayout = new QHBoxLayout(this);
    setContentsMargins(0,0,0,0);
<<<<<<< HEAD
    walletStack = new WalletStack(this);
    walletStack->setBitcoinGUI(gui);
=======
    walletStack = new QStackedWidget(this);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    walletFrameLayout->setContentsMargins(0,0,0,0);
    walletFrameLayout->addWidget(walletStack);

    QLabel *noWallet = new QLabel(tr("No wallet has been loaded."));
    noWallet->setAlignment(Qt::AlignCenter);
    walletStack->addWidget(noWallet);
}

WalletFrame::~WalletFrame()
{
}

void WalletFrame::setClientModel(ClientModel *clientModel)
{
    this->clientModel = clientModel;
<<<<<<< HEAD
    walletStack->setClientModel(clientModel);
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

bool WalletFrame::addWallet(const QString& name, WalletModel *walletModel)
{
<<<<<<< HEAD
    return walletStack->addWallet(name, walletModel);
=======
    if (!gui || !clientModel || !walletModel || mapWalletViews.count(name) > 0)
        return false;

    WalletView *walletView = new WalletView(this);
    walletView->setBitcoinGUI(gui);
    walletView->setClientModel(clientModel);
    walletView->setWalletModel(walletModel);
    walletView->showOutOfSyncWarning(bOutOfSync);

     /* TODO we should goto the currently selected page once dynamically adding wallets is supported */
    walletView->gotoOverviewPage();
    walletStack->addWidget(walletView);
    mapWalletViews[name] = walletView;

    // Ensure a walletView is able to show the main window
    connect(walletView, SIGNAL(showNormalIfMinimized()), gui, SLOT(showNormalIfMinimized()));

    return true;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

bool WalletFrame::setCurrentWallet(const QString& name)
{
<<<<<<< HEAD
    // TODO: Check if valid name
    walletStack->setCurrentWallet(name);
=======
    if (mapWalletViews.count(name) == 0)
        return false;

    WalletView *walletView = mapWalletViews.value(name);
    walletStack->setCurrentWidget(walletView);
    walletView->updateEncryptionStatus();
    return true;
}

bool WalletFrame::removeWallet(const QString &name)
{
    if (mapWalletViews.count(name) == 0)
        return false;

    WalletView *walletView = mapWalletViews.take(name);
    walletStack->removeWidget(walletView);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    return true;
}

void WalletFrame::removeAllWallets()
{
<<<<<<< HEAD
    walletStack->removeAllWallets();
}

bool WalletFrame::handleURI(const QString &uri)
=======
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        walletStack->removeWidget(i.value());
    mapWalletViews.clear();
}

bool WalletFrame::handlePaymentRequest(const SendCoinsRecipient &recipient)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    WalletView *walletView = currentWalletView();
    if (!walletView)
        return false;

<<<<<<< HEAD
    return walletStack->handleURI(uri);
=======
    return walletView->handlePaymentRequest(recipient);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

void WalletFrame::showOutOfSyncWarning(bool fShow)
{
<<<<<<< HEAD
    if (!walletStack) {
        QMessageBox box;
        box.setText("walletStack is null");
        box.exec();
        return;
    }
    walletStack->showOutOfSyncWarning(fShow);
=======
    bOutOfSync = fShow;
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->showOutOfSyncWarning(fShow);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

void WalletFrame::gotoOverviewPage()
{
<<<<<<< HEAD
    walletStack->gotoOverviewPage();
=======
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->gotoOverviewPage();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

void WalletFrame::gotoHistoryPage()
{
<<<<<<< HEAD
    walletStack->gotoHistoryPage();
}

void WalletFrame::gotoAddressBookPage()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletStack->gotoAddressBookPage();
=======
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->gotoHistoryPage();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

void WalletFrame::gotoReceiveCoinsPage()
{
<<<<<<< HEAD
    walletStack->gotoReceiveCoinsPage();
=======
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->gotoReceiveCoinsPage();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

void WalletFrame::gotoSendCoinsPage(QString addr)
{
<<<<<<< HEAD
    walletStack->gotoSendCoinsPage(addr);
=======
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->gotoSendCoinsPage(addr);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

void WalletFrame::gotoSignMessageTab(QString addr)
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->gotoSignMessageTab(addr);
}

void WalletFrame::gotoVerifyMessageTab(QString addr)
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->gotoVerifyMessageTab(addr);
}

void WalletFrame::encryptWallet(bool status)
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->encryptWallet(status);
}

void WalletFrame::backupWallet()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->backupWallet();
}

void WalletFrame::changePassphrase()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->changePassphrase();
}

void WalletFrame::unlockWallet()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->unlockWallet();
}

<<<<<<< HEAD
void WalletFrame::setEncryptionStatus()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletStack->setEncryptionStatus();
=======
void WalletFrame::usedSendingAddresses()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->usedSendingAddresses();
}

void WalletFrame::usedReceivingAddresses()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->usedReceivingAddresses();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

WalletView *WalletFrame::currentWalletView()
{
    return qobject_cast<WalletView*>(walletStack->currentWidget());
}

