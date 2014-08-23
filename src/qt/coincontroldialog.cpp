<<<<<<< HEAD
#include "coincontroldialog.h"
#include "ui_coincontroldialog.h"

#include "init.h"
#include "bitcoinunits.h"
#include "walletmodel.h"
#include "addresstablemodel.h"
#include "optionsmodel.h"
#include "guiutil.h"
#include "coincontrol.h"

#include <QApplication>
#include <QCheckBox>
#include <QClipboard>
#include <QColor>
#include <QCursor>
#include <QDateTime>
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "coincontroldialog.h"
#include "ui_coincontroldialog.h"

#include "addresstablemodel.h"
#include "bitcoinunits.h"
#include "guiutil.h"
#include "init.h"
#include "optionsmodel.h"
#include "walletmodel.h"

#include "coincontrol.h"
#include "main.h"
#include "wallet.h"

#include <QApplication>
#include <QCheckBox>
#include <QColor>
#include <QCursor>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#include <QDialogButtonBox>
#include <QFlags>
#include <QIcon>
#include <QString>
#include <QTreeWidget>
#include <QTreeWidgetItem>

using namespace std;
QList<qint64> CoinControlDialog::payAmounts;
CCoinControl* CoinControlDialog::coinControl = new CCoinControl();

CoinControlDialog::CoinControlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoinControlDialog),
    model(0)
{
    ui->setupUi(this);
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // context menu actions
    QAction *copyAddressAction = new QAction(tr("Copy address"), this);
    QAction *copyLabelAction = new QAction(tr("Copy label"), this);
    QAction *copyAmountAction = new QAction(tr("Copy amount"), this);
             copyTransactionHashAction = new QAction(tr("Copy transaction ID"), this);  // we need to enable/disable this
             lockAction = new QAction(tr("Lock unspent"), this);                        // we need to enable/disable this
             unlockAction = new QAction(tr("Unlock unspent"), this);                    // we need to enable/disable this

    // context menu
    contextMenu = new QMenu();
    contextMenu->addAction(copyAddressAction);
    contextMenu->addAction(copyLabelAction);
    contextMenu->addAction(copyAmountAction);
    contextMenu->addAction(copyTransactionHashAction);
    contextMenu->addSeparator();
    contextMenu->addAction(lockAction);
    contextMenu->addAction(unlockAction);
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // context menu signals
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showMenu(QPoint)));
    connect(copyAddressAction, SIGNAL(triggered()), this, SLOT(copyAddress()));
    connect(copyLabelAction, SIGNAL(triggered()), this, SLOT(copyLabel()));
    connect(copyAmountAction, SIGNAL(triggered()), this, SLOT(copyAmount()));
    connect(copyTransactionHashAction, SIGNAL(triggered()), this, SLOT(copyTransactionHash()));
    connect(lockAction, SIGNAL(triggered()), this, SLOT(lockCoin()));
    connect(unlockAction, SIGNAL(triggered()), this, SLOT(unlockCoin()));
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // clipboard actions
    QAction *clipboardQuantityAction = new QAction(tr("Copy quantity"), this);
    QAction *clipboardAmountAction = new QAction(tr("Copy amount"), this);
    QAction *clipboardFeeAction = new QAction(tr("Copy fee"), this);
    QAction *clipboardAfterFeeAction = new QAction(tr("Copy after fee"), this);
    QAction *clipboardBytesAction = new QAction(tr("Copy bytes"), this);
    QAction *clipboardPriorityAction = new QAction(tr("Copy priority"), this);
    QAction *clipboardLowOutputAction = new QAction(tr("Copy low output"), this);
    QAction *clipboardChangeAction = new QAction(tr("Copy change"), this);
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    connect(clipboardQuantityAction, SIGNAL(triggered()), this, SLOT(clipboardQuantity()));
    connect(clipboardAmountAction, SIGNAL(triggered()), this, SLOT(clipboardAmount()));
    connect(clipboardFeeAction, SIGNAL(triggered()), this, SLOT(clipboardFee()));
    connect(clipboardAfterFeeAction, SIGNAL(triggered()), this, SLOT(clipboardAfterFee()));
    connect(clipboardBytesAction, SIGNAL(triggered()), this, SLOT(clipboardBytes()));
    connect(clipboardPriorityAction, SIGNAL(triggered()), this, SLOT(clipboardPriority()));
    connect(clipboardLowOutputAction, SIGNAL(triggered()), this, SLOT(clipboardLowOutput()));
    connect(clipboardChangeAction, SIGNAL(triggered()), this, SLOT(clipboardChange()));
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ui->labelCoinControlQuantity->addAction(clipboardQuantityAction);
    ui->labelCoinControlAmount->addAction(clipboardAmountAction);
    ui->labelCoinControlFee->addAction(clipboardFeeAction);
    ui->labelCoinControlAfterFee->addAction(clipboardAfterFeeAction);
    ui->labelCoinControlBytes->addAction(clipboardBytesAction);
    ui->labelCoinControlPriority->addAction(clipboardPriorityAction);
    ui->labelCoinControlLowOutput->addAction(clipboardLowOutputAction);
    ui->labelCoinControlChange->addAction(clipboardChangeAction);
<<<<<<< HEAD
    
    // toggle tree/list mode
    connect(ui->radioTreeMode, SIGNAL(toggled(bool)), this, SLOT(radioTreeMode(bool)));
    connect(ui->radioListMode, SIGNAL(toggled(bool)), this, SLOT(radioListMode(bool)));
    
    // click on checkbox
    connect(ui->treeWidget, SIGNAL(itemChanged( QTreeWidgetItem*, int)), this, SLOT(viewItemChanged( QTreeWidgetItem*, int)));
    
    // click on header
    #if QT_VERSION < 0x050000
        ui->treeWidget->header()->setClickable(true);
    #else
        ui->treeWidget->header()->setSectionsClickable(true);
    #endif
    connect(ui->treeWidget->header(), SIGNAL(sectionClicked(int)), this, SLOT(headerSectionClicked(int)));
    
    // ok button
    connect(ui->buttonBox, SIGNAL(clicked( QAbstractButton*)), this, SLOT(buttonBoxClicked(QAbstractButton*)));
    
    // (un)select all
    connect(ui->pushButtonSelectAll, SIGNAL(clicked()), this, SLOT(buttonSelectAllClicked()));
    
=======

    // toggle tree/list mode
    connect(ui->radioTreeMode, SIGNAL(toggled(bool)), this, SLOT(radioTreeMode(bool)));
    connect(ui->radioListMode, SIGNAL(toggled(bool)), this, SLOT(radioListMode(bool)));

    // click on checkbox
    connect(ui->treeWidget, SIGNAL(itemChanged( QTreeWidgetItem*, int)), this, SLOT(viewItemChanged( QTreeWidgetItem*, int)));

    // click on header
#if QT_VERSION < 0x050000
    ui->treeWidget->header()->setClickable(true);
#else
    ui->treeWidget->header()->setSectionsClickable(true);
#endif
    connect(ui->treeWidget->header(), SIGNAL(sectionClicked(int)), this, SLOT(headerSectionClicked(int)));

    // ok button
    connect(ui->buttonBox, SIGNAL(clicked( QAbstractButton*)), this, SLOT(buttonBoxClicked(QAbstractButton*)));

    // (un)select all
    connect(ui->pushButtonSelectAll, SIGNAL(clicked()), this, SLOT(buttonSelectAllClicked()));

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ui->treeWidget->setColumnWidth(COLUMN_CHECKBOX, 84);
    ui->treeWidget->setColumnWidth(COLUMN_AMOUNT, 100);
    ui->treeWidget->setColumnWidth(COLUMN_LABEL, 170);
    ui->treeWidget->setColumnWidth(COLUMN_ADDRESS, 290);
    ui->treeWidget->setColumnWidth(COLUMN_DATE, 110);
    ui->treeWidget->setColumnWidth(COLUMN_CONFIRMATIONS, 100);
    ui->treeWidget->setColumnWidth(COLUMN_PRIORITY, 100);
    ui->treeWidget->setColumnHidden(COLUMN_TXHASH, true);         // store transacton hash in this column, but dont show it
    ui->treeWidget->setColumnHidden(COLUMN_VOUT_INDEX, true);     // store vout index in this column, but dont show it
    ui->treeWidget->setColumnHidden(COLUMN_AMOUNT_INT64, true);   // store amount int64 in this column, but dont show it
    ui->treeWidget->setColumnHidden(COLUMN_PRIORITY_INT64, true); // store priority int64 in this column, but dont show it
<<<<<<< HEAD
   
=======
    ui->treeWidget->setColumnHidden(COLUMN_DATE_INT64, true);     // store date int64 in this column, but dont show it

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // default view is sorted by amount desc
    sortView(COLUMN_AMOUNT_INT64, Qt::DescendingOrder);
}

CoinControlDialog::~CoinControlDialog()
<<<<<<< HEAD
{    
=======
{
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    delete ui;
}

void CoinControlDialog::setModel(WalletModel *model)
{
    this->model = model;
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    if(model && model->getOptionsModel() && model->getAddressTableModel())
    {
        updateView();
        updateLabelLocked();
        CoinControlDialog::updateLabels(model, this);
    }
}

// helper function str_pad
QString CoinControlDialog::strPad(QString s, int nPadLength, QString sPadding)
{
    while (s.length() < nPadLength)
        s = sPadding + s;
<<<<<<< HEAD
        
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    return s;
}

// ok button
void CoinControlDialog::buttonBoxClicked(QAbstractButton* button)
{
    if (ui->buttonBox->buttonRole(button) == QDialogButtonBox::AcceptRole)
        done(QDialog::Accepted); // closes the dialog
}

// (un)select all
void CoinControlDialog::buttonSelectAllClicked()
{
    Qt::CheckState state = Qt::Checked;
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        if (ui->treeWidget->topLevelItem(i)->checkState(COLUMN_CHECKBOX) != Qt::Unchecked)
        {
            state = Qt::Unchecked;
            break;
        }
    }
    ui->treeWidget->setEnabled(false);
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
            if (ui->treeWidget->topLevelItem(i)->checkState(COLUMN_CHECKBOX) != state)
                ui->treeWidget->topLevelItem(i)->setCheckState(COLUMN_CHECKBOX, state);
    ui->treeWidget->setEnabled(true);
    if (state == Qt::Unchecked)
        coinControl->UnSelectAll(); // just to be sure
    CoinControlDialog::updateLabels(model, this);
}

// context menu
void CoinControlDialog::showMenu(const QPoint &point)
{
    QTreeWidgetItem *item = ui->treeWidget->itemAt(point);
    if(item)
    {
        contextMenuItem = item;
<<<<<<< HEAD
        
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        // disable some items (like Copy Transaction ID, lock, unlock) for tree roots in context menu
        if (item->text(COLUMN_TXHASH).length() == 64) // transaction hash is 64 characters (this means its a child node, so its not a parent node in tree mode)
        {
            copyTransactionHashAction->setEnabled(true);
            if (model->isLockedCoin(uint256(item->text(COLUMN_TXHASH).toStdString()), item->text(COLUMN_VOUT_INDEX).toUInt()))
            {
                lockAction->setEnabled(false);
                unlockAction->setEnabled(true);
            }
            else
            {
                lockAction->setEnabled(true);
                unlockAction->setEnabled(false);
            }
        }
        else // this means click on parent node in tree mode -> disable all
        {
            copyTransactionHashAction->setEnabled(false);
            lockAction->setEnabled(false);
            unlockAction->setEnabled(false);
        }

        // show context menu
        contextMenu->exec(QCursor::pos());
    }
}
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
// context menu action: copy amount
void CoinControlDialog::copyAmount()
{
    GUIUtil::setClipboard(contextMenuItem->text(COLUMN_AMOUNT));
}

// context menu action: copy label
void CoinControlDialog::copyLabel()
{
    if (ui->radioTreeMode->isChecked() && contextMenuItem->text(COLUMN_LABEL).length() == 0 && contextMenuItem->parent())
        GUIUtil::setClipboard(contextMenuItem->parent()->text(COLUMN_LABEL));
    else
        GUIUtil::setClipboard(contextMenuItem->text(COLUMN_LABEL));
}

// context menu action: copy address
void CoinControlDialog::copyAddress()
{
    if (ui->radioTreeMode->isChecked() && contextMenuItem->text(COLUMN_ADDRESS).length() == 0 && contextMenuItem->parent())
        GUIUtil::setClipboard(contextMenuItem->parent()->text(COLUMN_ADDRESS));
    else
        GUIUtil::setClipboard(contextMenuItem->text(COLUMN_ADDRESS));
}

// context menu action: copy transaction id
void CoinControlDialog::copyTransactionHash()
{
    GUIUtil::setClipboard(contextMenuItem->text(COLUMN_TXHASH));
}

// context menu action: lock coin
void CoinControlDialog::lockCoin()
{
    if (contextMenuItem->checkState(COLUMN_CHECKBOX) == Qt::Checked)
        contextMenuItem->setCheckState(COLUMN_CHECKBOX, Qt::Unchecked);
<<<<<<< HEAD
        
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    COutPoint outpt(uint256(contextMenuItem->text(COLUMN_TXHASH).toStdString()), contextMenuItem->text(COLUMN_VOUT_INDEX).toUInt());
    model->lockCoin(outpt);
    contextMenuItem->setDisabled(true);
    contextMenuItem->setIcon(COLUMN_CHECKBOX, QIcon(":/icons/lock_closed"));
    updateLabelLocked();
}

// context menu action: unlock coin
void CoinControlDialog::unlockCoin()
{
    COutPoint outpt(uint256(contextMenuItem->text(COLUMN_TXHASH).toStdString()), contextMenuItem->text(COLUMN_VOUT_INDEX).toUInt());
    model->unlockCoin(outpt);
    contextMenuItem->setDisabled(false);
    contextMenuItem->setIcon(COLUMN_CHECKBOX, QIcon());
    updateLabelLocked();
}

// copy label "Quantity" to clipboard
void CoinControlDialog::clipboardQuantity()
{
    GUIUtil::setClipboard(ui->labelCoinControlQuantity->text());
}

// copy label "Amount" to clipboard
void CoinControlDialog::clipboardAmount()
{
    GUIUtil::setClipboard(ui->labelCoinControlAmount->text().left(ui->labelCoinControlAmount->text().indexOf(" ")));
}

// copy label "Fee" to clipboard
void CoinControlDialog::clipboardFee()
{
    GUIUtil::setClipboard(ui->labelCoinControlFee->text().left(ui->labelCoinControlFee->text().indexOf(" ")));
}

// copy label "After fee" to clipboard
void CoinControlDialog::clipboardAfterFee()
{
    GUIUtil::setClipboard(ui->labelCoinControlAfterFee->text().left(ui->labelCoinControlAfterFee->text().indexOf(" ")));
}

// copy label "Bytes" to clipboard
void CoinControlDialog::clipboardBytes()
{
    GUIUtil::setClipboard(ui->labelCoinControlBytes->text());
}

// copy label "Priority" to clipboard
void CoinControlDialog::clipboardPriority()
{
    GUIUtil::setClipboard(ui->labelCoinControlPriority->text());
}

// copy label "Low output" to clipboard
void CoinControlDialog::clipboardLowOutput()
{
    GUIUtil::setClipboard(ui->labelCoinControlLowOutput->text());
}

// copy label "Change" to clipboard
void CoinControlDialog::clipboardChange()
{
    GUIUtil::setClipboard(ui->labelCoinControlChange->text().left(ui->labelCoinControlChange->text().indexOf(" ")));
}

// treeview: sort
void CoinControlDialog::sortView(int column, Qt::SortOrder order)
{
    sortColumn = column;
    sortOrder = order;
    ui->treeWidget->sortItems(column, order);
<<<<<<< HEAD
    ui->treeWidget->header()->setSortIndicator((sortColumn == COLUMN_AMOUNT_INT64 ? COLUMN_AMOUNT : (sortColumn == COLUMN_PRIORITY_INT64 ? COLUMN_PRIORITY : sortColumn)), sortOrder);
=======
    ui->treeWidget->header()->setSortIndicator(getMappedColumn(sortColumn), sortOrder);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

// treeview: clicked on header
void CoinControlDialog::headerSectionClicked(int logicalIndex)
{
    if (logicalIndex == COLUMN_CHECKBOX) // click on most left column -> do nothing
<<<<<<< HEAD
    {      
        ui->treeWidget->header()->setSortIndicator((sortColumn == COLUMN_AMOUNT_INT64 ? COLUMN_AMOUNT : (sortColumn == COLUMN_PRIORITY_INT64 ? COLUMN_PRIORITY : sortColumn)), sortOrder);
    }
    else
    {
        if (logicalIndex == COLUMN_AMOUNT) // sort by amount
            logicalIndex = COLUMN_AMOUNT_INT64;
            
        if (logicalIndex == COLUMN_PRIORITY) // sort by priority
            logicalIndex = COLUMN_PRIORITY_INT64;
            
=======
    {
        ui->treeWidget->header()->setSortIndicator(getMappedColumn(sortColumn), sortOrder);
    }
    else
    {
        logicalIndex = getMappedColumn(logicalIndex, false);

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        if (sortColumn == logicalIndex)
            sortOrder = ((sortOrder == Qt::AscendingOrder) ? Qt::DescendingOrder : Qt::AscendingOrder);
        else
        {
            sortColumn = logicalIndex;
<<<<<<< HEAD
            sortOrder = ((sortColumn == COLUMN_AMOUNT_INT64 || sortColumn == COLUMN_PRIORITY_INT64 || sortColumn == COLUMN_DATE || sortColumn == COLUMN_CONFIRMATIONS) ? Qt::DescendingOrder : Qt::AscendingOrder); // if amount,date,conf,priority then default => desc, else default => asc
=======
            sortOrder = ((sortColumn == COLUMN_LABEL || sortColumn == COLUMN_ADDRESS) ? Qt::AscendingOrder : Qt::DescendingOrder); // if label or address then default => asc, else default => desc
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }

        sortView(sortColumn, sortOrder);
    }
}

// toggle tree mode
void CoinControlDialog::radioTreeMode(bool checked)
{
    if (checked && model)
        updateView();
}

// toggle list mode
void CoinControlDialog::radioListMode(bool checked)
{
    if (checked && model)
        updateView();
}

// checkbox clicked by user
void CoinControlDialog::viewItemChanged(QTreeWidgetItem* item, int column)
{
    if (column == COLUMN_CHECKBOX && item->text(COLUMN_TXHASH).length() == 64) // transaction hash is 64 characters (this means its a child node, so its not a parent node in tree mode)
<<<<<<< HEAD
    { 
        COutPoint outpt(uint256(item->text(COLUMN_TXHASH).toStdString()), item->text(COLUMN_VOUT_INDEX).toUInt());
        
        if (item->checkState(COLUMN_CHECKBOX) == Qt::Unchecked)              
=======
    {
        COutPoint outpt(uint256(item->text(COLUMN_TXHASH).toStdString()), item->text(COLUMN_VOUT_INDEX).toUInt());

        if (item->checkState(COLUMN_CHECKBOX) == Qt::Unchecked)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            coinControl->UnSelect(outpt);
        else if (item->isDisabled()) // locked (this happens if "check all" through parent node)
            item->setCheckState(COLUMN_CHECKBOX, Qt::Unchecked);
        else
            coinControl->Select(outpt);
<<<<<<< HEAD
 
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        // selection changed -> update labels
        if (ui->treeWidget->isEnabled()) // do not update on every click for (un)select all
            CoinControlDialog::updateLabels(model, this);
    }
}

<<<<<<< HEAD
// helper function, return human readable label for priority number
QString CoinControlDialog::getPriorityLabel(double dPriority)
{
    if (CTransaction::AllowFree(dPriority)) // at least medium
    {
        if      (CTransaction::AllowFree(dPriority / 10000))  return tr("highest");
        else if (CTransaction::AllowFree(dPriority / 1000))   return tr("high");
        else if (CTransaction::AllowFree(dPriority / 100))    return tr("medium-high");
        else                                    return tr("medium");
    }
    else
    {
        if      (CTransaction::AllowFree(dPriority * 100))    return tr("low-medium");
        else if (CTransaction::AllowFree(dPriority * 10000))  return tr("low");
        else                                    return tr("lowest");
=======
// return human readable label for priority number
QString CoinControlDialog::getPriorityLabel(double dPriority)
{
    if (AllowFree(dPriority)) // at least medium
    {
        if      (AllowFree(dPriority / 1000000))  return tr("highest");
        else if (AllowFree(dPriority / 100000))   return tr("higher");
        else if (AllowFree(dPriority / 10000))    return tr("high");
        else if (AllowFree(dPriority / 1000))     return tr("medium-high");
        else                                      return tr("medium");
    }
    else
    {
        if      (AllowFree(dPriority * 10))   return tr("low-medium");
        else if (AllowFree(dPriority * 100))  return tr("low");
        else if (AllowFree(dPriority * 1000)) return tr("lower");
        else                                  return tr("lowest");
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
}

// shows count of locked unspent outputs
void CoinControlDialog::updateLabelLocked()
{
    vector<COutPoint> vOutpts;
    model->listLockedCoins(vOutpts);
    if (vOutpts.size() > 0)
    {
       ui->labelLocked->setText(tr("(%1 locked)").arg(vOutpts.size()));
<<<<<<< HEAD
       ui->labelLocked->setVisible(true); 
=======
       ui->labelLocked->setVisible(true);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
    else ui->labelLocked->setVisible(false);
}

void CoinControlDialog::updateLabels(WalletModel *model, QDialog* dialog)
{
    if (!model) return;

    // nPayAmount
    qint64 nPayAmount = 0;
    bool fLowOutput = false;
    bool fDust = false;
<<<<<<< HEAD
    unsigned int nQuantityDust = 0;
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    CTransaction txDummy;
    foreach(const qint64 &amount, CoinControlDialog::payAmounts)
    {
        nPayAmount += amount;
<<<<<<< HEAD
        
        if (amount > 0)
        {
            if (amount < CENT) {
                fLowOutput = true;
                nQuantityDust++;
            }

            CTxOut txout(amount, (CScript)vector<unsigned char>(24, 0));
            txDummy.vout.push_back(txout);
            if (txout.IsDust())
               fDust = true; 
        }
    }

    QString sPriorityLabel      = "";
    int64 nAmount               = 0;
    int64 nPayFee               = 0;
    int64 nAfterFee             = 0;
    int64 nChange               = 0;
=======

        if (amount > 0)
        {
            if (amount < COIN)
                fLowOutput = true;

            CTxOut txout(amount, (CScript)vector<unsigned char>(24, 0));
            txDummy.vout.push_back(txout);
            if (txout.IsDust(CTransaction::nMinRelayTxFee))
               fDust = true;
        }
    }

    QString sPriorityLabel      = tr("none");
    int64_t nAmount             = 0;
    int64_t nPayFee             = 0;
    int64_t nAfterFee           = 0;
    int64_t nChange             = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    unsigned int nBytes         = 0;
    unsigned int nBytesInputs   = 0;
    double dPriority            = 0;
    double dPriorityInputs      = 0;
    unsigned int nQuantity      = 0;
<<<<<<< HEAD
    
=======
    int nQuantityUncompressed   = 0;

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    vector<COutPoint> vCoinControl;
    vector<COutput>   vOutputs;
    coinControl->ListSelected(vCoinControl);
    model->getOutputs(vCoinControl, vOutputs);

    BOOST_FOREACH(const COutput& out, vOutputs)
    {
<<<<<<< HEAD
        // unselect already spent, very unlikely scenario, this could happen when selected are spent elsewhere, like rpc or another computer
        if (out.tx->IsSpent(out.i))
        {
            uint256 txhash = out.tx->GetHash();
            COutPoint outpt(txhash, out.i);
=======
        // unselect already spent, very unlikely scenario, this could happen
        // when selected are spent elsewhere, like rpc or another computer
        uint256 txhash = out.tx->GetHash();
        COutPoint outpt(txhash, out.i);
        if (model->isSpent(outpt))
        {
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            coinControl->UnSelect(outpt);
            continue;
        }

        // Quantity
        nQuantity++;
<<<<<<< HEAD
            
        // Amount
        nAmount += out.tx->vout[out.i].nValue;
        
        // Priority
        dPriorityInputs += (double)out.tx->vout[out.i].nValue * (out.nDepth+1);
        
=======

        // Amount
        nAmount += out.tx->vout[out.i].nValue;

        // Priority
        dPriorityInputs += (double)out.tx->vout[out.i].nValue * (out.nDepth+1);

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        // Bytes
        CTxDestination address;
        if(ExtractDestination(out.tx->vout[out.i].scriptPubKey, address))
        {
            CPubKey pubkey;
            CKeyID *keyid = boost::get<CKeyID>(&address);
            if (keyid && model->getPubKey(*keyid, pubkey))
<<<<<<< HEAD
                nBytesInputs += (pubkey.IsCompressed() ? 148 : 180);
=======
            {
                nBytesInputs += (pubkey.IsCompressed() ? 148 : 180);
                if (!pubkey.IsCompressed())
                    nQuantityUncompressed++;
            }
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            else
                nBytesInputs += 148; // in all error cases, simply assume 148 here
        }
        else nBytesInputs += 148;
    }
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // calculation
    if (nQuantity > 0)
    {
        // Bytes
        nBytes = nBytesInputs + ((CoinControlDialog::payAmounts.size() > 0 ? CoinControlDialog::payAmounts.size() + 1 : 2) * 34) + 10; // always assume +1 output for change here
<<<<<<< HEAD
        
        // Priority
        dPriority = dPriorityInputs / nBytes;
        sPriorityLabel = CoinControlDialog::getPriorityLabel(dPriority);
        
        // Fee
        int64 nFee = nTransactionFee * (1 + (int64)nBytes / 1000);
        
        // Min Fee
        int64 nMinFee = CTransaction::nMinTxFee * (1 + (int64)nBytes / 1000) + CTransaction::nMinTxFee * nQuantityDust;
        if (CTransaction::AllowFree(dPriority) && nBytes < 5000)
            nMinFee = 0;
        
        nPayFee = max(nFee, nMinFee);
        
        if (nPayAmount > 0)
        {
            nChange = nAmount - nPayFee - nPayAmount;
            
            // require CTransaction::nMinTxFee if any output is less than 0.01
            if (nPayFee < CTransaction::nMinTxFee && fLowOutput)
            {
                nChange = nChange + nPayFee - CTransaction::nMinTxFee;
                nPayFee = CTransaction::nMinTxFee * nQuantityDust;
            }
            
            // if sub-cent change is required, the fee must be raised to at least CTransaction::nMinTxFee   
            if (nPayFee < CTransaction::nMinTxFee && nChange > 0 && nChange < CENT)
=======

        // Priority
        dPriority = dPriorityInputs / (nBytes - nBytesInputs + (nQuantityUncompressed * 29)); // 29 = 180 - 151 (uncompressed public keys are over the limit. max 151 bytes of the input are ignored for priority)
        sPriorityLabel = CoinControlDialog::getPriorityLabel(dPriority);

        // Fee
        int64_t nFee = nTransactionFee * (1 + (int64_t)nBytes / 1000);

        // Min Fee
        int64_t nMinFee = GetMinFee(txDummy, nBytes, AllowFree(dPriority), GMF_SEND);

        nPayFee = max(nFee, nMinFee);

        if (nPayAmount > 0)
        {
            nChange = nAmount - nPayFee - nPayAmount;

            // if sub-cent change is required, the fee must be raised to at least CTransaction::nMinTxFee
            if (nPayFee < CTransaction::nMinTxFee && nChange > 0 && nChange < COIN)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            {
                if (nChange < CTransaction::nMinTxFee) // change < 0.0001 => simply move all change to fees
                {
                    nPayFee += nChange;
                    nChange = 0;
                }
                else
                {
                    nChange = nChange + nPayFee - CTransaction::nMinTxFee;
                    nPayFee = CTransaction::nMinTxFee;
<<<<<<< HEAD
                }  
            }
            
            // Never create dust outputs; if we would, just add the dust to the fee.
            if (nChange > 0 && nChange < CENT)
            {
                CTxOut txout(nChange, (CScript)vector<unsigned char>(24, 0));
                if (txout.IsDust())
=======
                }
            }

            // Never create dust outputs; if we would, just add the dust to the fee.
            if (nChange > 0 && nChange < COIN)
            {
                CTxOut txout(nChange, (CScript)vector<unsigned char>(24, 0));
                if (txout.IsDust(CTransaction::nMinRelayTxFee))
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                {
                    nPayFee += nChange;
                    nChange = 0;
                }
            }
<<<<<<< HEAD
            
            if (nChange == 0)
                nBytes -= 34;
        }
        
=======

            if (nChange == 0)
                nBytes -= 34;
        }

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        // after fee
        nAfterFee = nAmount - nPayFee;
        if (nAfterFee < 0)
            nAfterFee = 0;
    }
<<<<<<< HEAD
    
    // actually update labels
    int nDisplayUnit = BitcoinUnits::BTC;
    if (model && model->getOptionsModel())
        nDisplayUnit = model->getOptionsModel()->getDisplayUnit();
            
=======

    // actually update labels
    int nDisplayUnit = BitcoinUnits::DOGE;
    if (model && model->getOptionsModel())
        nDisplayUnit = model->getOptionsModel()->getDisplayUnit();

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    QLabel *l1 = dialog->findChild<QLabel *>("labelCoinControlQuantity");
    QLabel *l2 = dialog->findChild<QLabel *>("labelCoinControlAmount");
    QLabel *l3 = dialog->findChild<QLabel *>("labelCoinControlFee");
    QLabel *l4 = dialog->findChild<QLabel *>("labelCoinControlAfterFee");
    QLabel *l5 = dialog->findChild<QLabel *>("labelCoinControlBytes");
    QLabel *l6 = dialog->findChild<QLabel *>("labelCoinControlPriority");
    QLabel *l7 = dialog->findChild<QLabel *>("labelCoinControlLowOutput");
    QLabel *l8 = dialog->findChild<QLabel *>("labelCoinControlChange");
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // enable/disable "low output" and "change"
    dialog->findChild<QLabel *>("labelCoinControlLowOutputText")->setEnabled(nPayAmount > 0);
    dialog->findChild<QLabel *>("labelCoinControlLowOutput")    ->setEnabled(nPayAmount > 0);
    dialog->findChild<QLabel *>("labelCoinControlChangeText")   ->setEnabled(nPayAmount > 0);
    dialog->findChild<QLabel *>("labelCoinControlChange")       ->setEnabled(nPayAmount > 0);
<<<<<<< HEAD
    
    // stats
    l1->setText(QString::number(nQuantity));                                 // Quantity        
=======

    // stats
    l1->setText(QString::number(nQuantity));                                 // Quantity
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    l2->setText(BitcoinUnits::formatWithUnit(nDisplayUnit, nAmount));        // Amount
    l3->setText(BitcoinUnits::formatWithUnit(nDisplayUnit, nPayFee));        // Fee
    l4->setText(BitcoinUnits::formatWithUnit(nDisplayUnit, nAfterFee));      // After Fee
    l5->setText(((nBytes > 0) ? "~" : "") + QString::number(nBytes));        // Bytes
    l6->setText(sPriorityLabel);                                             // Priority
<<<<<<< HEAD
    l7->setText((fLowOutput ? (fDust ? tr("DUST") : tr("yes")) : tr("no"))); // Low Output / Dust
    l8->setText(BitcoinUnits::formatWithUnit(nDisplayUnit, nChange));        // Change
    
    // turn labels "red"
    l5->setStyleSheet((nBytes >= 5000) ? "color:red;" : "");               // Bytes >= 5000
    l6->setStyleSheet((!CTransaction::AllowFree(dPriority)) ? "color:red;" : "");         // Priority < "medium"
    l7->setStyleSheet((fLowOutput) ? "color:red;" : "");                    // Low Output = "yes"
    l8->setStyleSheet((nChange > 0 && nChange < CENT) ? "color:red;" : ""); // Change < 0.01BTC
        
    // tool tips
    l5->setToolTip(tr("This label turns red, if the transaction size is bigger than 5000 bytes.\n\n This means a fee of at least %1 per kb is required.\n\n Can vary +/- 1 Byte per input.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CTransaction::nMinTxFee)));
    l6->setToolTip(tr("Transactions with higher priority get more likely into a block.\n\nThis label turns red, if the priority is smaller than \"medium\".\n\n This means a fee of at least %1 per kb is required.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CTransaction::nMinTxFee)));
    l7->setToolTip(tr("This label turns red, if any recipient receives an amount smaller than %1.\n\n This means a fee of at least %2 is required. \n\n Amounts below 0.546 times the minimum relay fee are shown as DUST.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CENT)).arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CTransaction::nMinTxFee)));
    l8->setToolTip(tr("This label turns red, if the change is smaller than %1.\n\n This means a fee of at least %2 is required.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CENT)).arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CTransaction::nMinTxFee)));
=======
    l7->setText((fLowOutput ? (fDust ? tr("Dust") : tr("yes")) : tr("no"))); // Low Output / Dust
    l8->setText(BitcoinUnits::formatWithUnit(nDisplayUnit, nChange));        // Change

    // turn labels "red"
    l5->setStyleSheet((nBytes >= 1000) ? "color:red;" : "");                            // Bytes >= 1000
    l6->setStyleSheet((dPriority > 0 && !AllowFree(dPriority)) ? "color:red;" : "");    // Priority < "medium"
    l7->setStyleSheet((fLowOutput) ? "color:red;" : "");                                // Low Output = "yes"
    l8->setStyleSheet((nChange > 0 && nChange < COIN) ? "color:red;" : "");             // Change < 0.01DOGE

    // tool tips
    QString toolTip1 = tr("This label turns red, if the transaction size is greater than 1000 bytes.") + "<br /><br />";
    toolTip1 += tr("This means a fee of at least %1 per kB is required.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CTransaction::nMinTxFee)) + "<br /><br />";
    toolTip1 += tr("Can vary +/- 1 byte per input.");

    QString toolTip2 = tr("Transactions with higher priority are more likely to get included into a block.") + "<br /><br />";
    toolTip2 += tr("This label turns red, if the priority is smaller than \"medium\".") + "<br /><br />";
    toolTip2 += tr("This means a fee of at least %1 per kB is required.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CTransaction::nMinTxFee));

    QString toolTip3 = tr("This label turns red, if any recipient receives an amount smaller than %1.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, COIN)) + "<br /><br />";
    toolTip3 += tr("This means a fee of at least %1 is required.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CTransaction::nMinTxFee)) + "<br /><br />";
    toolTip3 += tr("Amounts below 0.546 times the minimum relay fee are shown as dust.");

    QString toolTip4 = tr("This label turns red, if the change is smaller than %1.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, COIN)) + "<br /><br />";
    toolTip4 += tr("This means a fee of at least %1 is required.").arg(BitcoinUnits::formatWithUnit(nDisplayUnit, CTransaction::nMinTxFee));

    l5->setToolTip(toolTip1);
    l6->setToolTip(toolTip2);
    l7->setToolTip(toolTip3);
    l8->setToolTip(toolTip4);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    dialog->findChild<QLabel *>("labelCoinControlBytesText")    ->setToolTip(l5->toolTip());
    dialog->findChild<QLabel *>("labelCoinControlPriorityText") ->setToolTip(l6->toolTip());
    dialog->findChild<QLabel *>("labelCoinControlLowOutputText")->setToolTip(l7->toolTip());
    dialog->findChild<QLabel *>("labelCoinControlChangeText")   ->setToolTip(l8->toolTip());
<<<<<<< HEAD
   
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // Insufficient funds
    QLabel *label = dialog->findChild<QLabel *>("labelCoinControlInsuffFunds");
    if (label)
        label->setVisible(nChange < 0);
}

void CoinControlDialog::updateView()
{
    bool treeMode = ui->radioTreeMode->isChecked();

    ui->treeWidget->clear();
    ui->treeWidget->setEnabled(false); // performance, otherwise updateLabels would be called for every checked checkbox
    ui->treeWidget->setAlternatingRowColors(!treeMode);
    QFlags<Qt::ItemFlag> flgCheckbox=Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
<<<<<<< HEAD
    QFlags<Qt::ItemFlag> flgTristate=Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsTristate;    
    
    int nDisplayUnit = BitcoinUnits::BTC;
    if (model && model->getOptionsModel())
        nDisplayUnit = model->getOptionsModel()->getDisplayUnit();
        
=======
    QFlags<Qt::ItemFlag> flgTristate=Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsTristate;

    int nDisplayUnit = BitcoinUnits::DOGE;
    if (model && model->getOptionsModel())
        nDisplayUnit = model->getOptionsModel()->getDisplayUnit();

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    map<QString, vector<COutput> > mapCoins;
    model->listCoins(mapCoins);

    BOOST_FOREACH(PAIRTYPE(QString, vector<COutput>) coins, mapCoins)
    {
        QTreeWidgetItem *itemWalletAddress = new QTreeWidgetItem();
        QString sWalletAddress = coins.first;
        QString sWalletLabel = "";
        if (model->getAddressTableModel())
            sWalletLabel = model->getAddressTableModel()->labelForAddress(sWalletAddress);
        if (sWalletLabel.length() == 0)
            sWalletLabel = tr("(no label)");
<<<<<<< HEAD
        
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        if (treeMode)
        {
            // wallet address
            ui->treeWidget->addTopLevelItem(itemWalletAddress);

            itemWalletAddress->setFlags(flgTristate);
            itemWalletAddress->setCheckState(COLUMN_CHECKBOX,Qt::Unchecked);
<<<<<<< HEAD
            
            for (int i = 0; i < ui->treeWidget->columnCount(); i++)
                itemWalletAddress->setBackground(i, QColor(248, 247, 246));
            
=======

            for (int i = 0; i < ui->treeWidget->columnCount(); i++)
                itemWalletAddress->setBackground(i, QColor(248, 247, 246));

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            // label
            itemWalletAddress->setText(COLUMN_LABEL, sWalletLabel);

            // address
            itemWalletAddress->setText(COLUMN_ADDRESS, sWalletAddress);
        }

<<<<<<< HEAD
        int64 nSum = 0;
=======
        int64_t nSum = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        double dPrioritySum = 0;
        int nChildren = 0;
        int nInputSum = 0;
        BOOST_FOREACH(const COutput& out, coins.second)
        {
<<<<<<< HEAD
            int nInputSize = 148; // 180 if uncompressed public key
            nSum += out.tx->vout[out.i].nValue;
            nChildren++;
            
=======
            int nInputSize = 0;
            nSum += out.tx->vout[out.i].nValue;
            nChildren++;

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            QTreeWidgetItem *itemOutput;
            if (treeMode)    itemOutput = new QTreeWidgetItem(itemWalletAddress);
            else             itemOutput = new QTreeWidgetItem(ui->treeWidget);
            itemOutput->setFlags(flgCheckbox);
            itemOutput->setCheckState(COLUMN_CHECKBOX,Qt::Unchecked);
<<<<<<< HEAD
                
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            // address
            CTxDestination outputAddress;
            QString sAddress = "";
            if(ExtractDestination(out.tx->vout[out.i].scriptPubKey, outputAddress))
            {
                sAddress = CBitcoinAddress(outputAddress).ToString().c_str();
<<<<<<< HEAD
                
                // if listMode or change => show bitcoin address. In tree mode, address is not shown again for direct wallet address outputs
                if (!treeMode || (!(sAddress == sWalletAddress)))
                    itemOutput->setText(COLUMN_ADDRESS, sAddress);
                    
                CPubKey pubkey;
                CKeyID *keyid = boost::get<CKeyID>(&outputAddress);
                if (keyid && model->getPubKey(*keyid, pubkey) && !pubkey.IsCompressed())
                    nInputSize = 180;
=======

                // if listMode or change => show bitcoin address. In tree mode, address is not shown again for direct wallet address outputs
                if (!treeMode || (!(sAddress == sWalletAddress)))
                    itemOutput->setText(COLUMN_ADDRESS, sAddress);

                CPubKey pubkey;
                CKeyID *keyid = boost::get<CKeyID>(&outputAddress);
                if (keyid && model->getPubKey(*keyid, pubkey) && !pubkey.IsCompressed())
                    nInputSize = 29; // 29 = 180 - 151 (public key is 180 bytes, priority free area is 151 bytes)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            }

            // label
            if (!(sAddress == sWalletAddress)) // change
            {
                // tooltip from where the change comes from
                itemOutput->setToolTip(COLUMN_LABEL, tr("change from %1 (%2)").arg(sWalletLabel).arg(sWalletAddress));
                itemOutput->setText(COLUMN_LABEL, tr("(change)"));
            }
            else if (!treeMode)
            {
                QString sLabel = "";
                if (model->getAddressTableModel())
                    sLabel = model->getAddressTableModel()->labelForAddress(sAddress);
                if (sLabel.length() == 0)
                    sLabel = tr("(no label)");
<<<<<<< HEAD
                itemOutput->setText(COLUMN_LABEL, sLabel); 
=======
                itemOutput->setText(COLUMN_LABEL, sLabel);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            }

            // amount
            itemOutput->setText(COLUMN_AMOUNT, BitcoinUnits::format(nDisplayUnit, out.tx->vout[out.i].nValue));
            itemOutput->setText(COLUMN_AMOUNT_INT64, strPad(QString::number(out.tx->vout[out.i].nValue), 15, " ")); // padding so that sorting works correctly

            // date
<<<<<<< HEAD
            itemOutput->setText(COLUMN_DATE, QDateTime::fromTime_t(out.tx->GetTxTime()).toString("yy-MM-dd hh:mm"));
            
            // confirmations
            itemOutput->setText(COLUMN_CONFIRMATIONS, strPad(QString::number(out.nDepth), 8, " "));
            
            // priority
            double dPriority = ((double)out.tx->vout[out.i].nValue  / (nInputSize + 78)) * (out.nDepth+1); // 78 = 2 * 34 + 10
            itemOutput->setText(COLUMN_PRIORITY, CoinControlDialog::getPriorityLabel(dPriority));
            itemOutput->setText(COLUMN_PRIORITY_INT64, strPad(QString::number((int64)dPriority), 20, " "));
            dPrioritySum += (double)out.tx->vout[out.i].nValue  * (out.nDepth+1);
            nInputSum    += nInputSize;
            
            // transaction hash
            uint256 txhash = out.tx->GetHash();
            itemOutput->setText(COLUMN_TXHASH, txhash.GetHex().c_str());
    
            // vout index
            itemOutput->setText(COLUMN_VOUT_INDEX, QString::number(out.i));
            
             // disable locked coins     
=======
            itemOutput->setText(COLUMN_DATE, GUIUtil::dateTimeStr(out.tx->GetTxTime()));
            itemOutput->setText(COLUMN_DATE_INT64, strPad(QString::number(out.tx->GetTxTime()), 20, " "));

            // confirmations
            itemOutput->setText(COLUMN_CONFIRMATIONS, strPad(QString::number(out.nDepth), 8, " "));

            // priority
            double dPriority = ((double)out.tx->vout[out.i].nValue  / (nInputSize + 78)) * (out.nDepth+1); // 78 = 2 * 34 + 10
            itemOutput->setText(COLUMN_PRIORITY, CoinControlDialog::getPriorityLabel(dPriority));
            itemOutput->setText(COLUMN_PRIORITY_INT64, strPad(QString::number((int64_t)dPriority), 20, " "));
            dPrioritySum += (double)out.tx->vout[out.i].nValue  * (out.nDepth+1);
            nInputSum    += nInputSize;

            // transaction hash
            uint256 txhash = out.tx->GetHash();
            itemOutput->setText(COLUMN_TXHASH, txhash.GetHex().c_str());

            // vout index
            itemOutput->setText(COLUMN_VOUT_INDEX, QString::number(out.i));

             // disable locked coins
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            if (model->isLockedCoin(txhash, out.i))
            {
                COutPoint outpt(txhash, out.i);
                coinControl->UnSelect(outpt); // just to be sure
                itemOutput->setDisabled(true);
                itemOutput->setIcon(COLUMN_CHECKBOX, QIcon(":/icons/lock_closed"));
            }
<<<<<<< HEAD
              
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            // set checkbox
            if (coinControl->IsSelected(txhash, out.i))
                itemOutput->setCheckState(COLUMN_CHECKBOX,Qt::Checked);
        }

        // amount
        if (treeMode)
        {
            dPrioritySum = dPrioritySum / (nInputSum + 78);
            itemWalletAddress->setText(COLUMN_CHECKBOX, "(" + QString::number(nChildren) + ")");
            itemWalletAddress->setText(COLUMN_AMOUNT, BitcoinUnits::format(nDisplayUnit, nSum));
            itemWalletAddress->setText(COLUMN_AMOUNT_INT64, strPad(QString::number(nSum), 15, " "));
            itemWalletAddress->setText(COLUMN_PRIORITY, CoinControlDialog::getPriorityLabel(dPrioritySum));
<<<<<<< HEAD
            itemWalletAddress->setText(COLUMN_PRIORITY_INT64, strPad(QString::number((int64)dPrioritySum), 20, " "));
        }
    }
    
=======
            itemWalletAddress->setText(COLUMN_PRIORITY_INT64, strPad(QString::number((int64_t)dPrioritySum), 20, " "));
        }
    }

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // expand all partially selected
    if (treeMode)
    {
        for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
            if (ui->treeWidget->topLevelItem(i)->checkState(COLUMN_CHECKBOX) == Qt::PartiallyChecked)
                ui->treeWidget->topLevelItem(i)->setExpanded(true);
    }
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // sort view
    sortView(sortColumn, sortOrder);
    ui->treeWidget->setEnabled(true);
}
