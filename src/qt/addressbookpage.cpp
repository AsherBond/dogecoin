<<<<<<< HEAD
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#if defined(HAVE_CONFIG_H)
#include "bitcoin-config.h"
#endif

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#include "addressbookpage.h"
#include "ui_addressbookpage.h"

#include "addresstablemodel.h"
<<<<<<< HEAD
#include "optionsmodel.h"
#include "bitcoingui.h"
#include "editaddressdialog.h"
#include "csvmodelwriter.h"
#include "guiutil.h"

#ifdef USE_QRCODE
#include "qrcodedialog.h"
#endif

#include <QSortFilterProxyModel>
#include <QClipboard>
#include <QMessageBox>
#include <QMenu>
=======
#include "bitcoingui.h"
#include "csvmodelwriter.h"
#include "editaddressdialog.h"
#include "guiutil.h"

#include <QIcon>
#include <QMenu>
#include <QMessageBox>
#include <QSortFilterProxyModel>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

AddressBookPage::AddressBookPage(Mode mode, Tabs tab, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddressBookPage),
    model(0),
<<<<<<< HEAD
    optionsModel(0),
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    mode(mode),
    tab(tab)
{
    ui->setupUi(this);

#ifdef Q_OS_MAC // Icons on push buttons are very uncommon on Mac
    ui->newAddress->setIcon(QIcon());
    ui->copyAddress->setIcon(QIcon());
    ui->deleteAddress->setIcon(QIcon());
<<<<<<< HEAD
    ui->verifyMessage->setIcon(QIcon());
    ui->signMessage->setIcon(QIcon());
    ui->exportButton->setIcon(QIcon());
#endif

#ifndef USE_QRCODE
    ui->showQRCode->setVisible(false);
#endif

    switch(mode)
    {
    case ForSending:
        connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(accept()));
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableView->setFocus();
        ui->exportButton->hide();
        break;
    case ForEditing:
        ui->buttonBox->setVisible(false);
=======
    ui->exportButton->setIcon(QIcon());
#endif

    switch(mode)
    {
    case ForSelection:
        switch(tab)
        {
        case SendingTab: setWindowTitle(tr("Choose the address to send coins to")); break;
        case ReceivingTab: setWindowTitle(tr("Choose the address to receive coins with")); break;
        }
        connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(accept()));
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableView->setFocus();
        ui->closeButton->setText(tr("C&hoose"));
        ui->exportButton->hide();
        break;
    case ForEditing:
        switch(tab)
        {
        case SendingTab: setWindowTitle(tr("Sending addresses")); break;
        case ReceivingTab: setWindowTitle(tr("Receiving addresses")); break;
        }
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        break;
    }
    switch(tab)
    {
    case SendingTab:
        ui->labelExplanation->setText(tr("These are your Dogecoin addresses for sending payments. Always check the amount and the receiving address before sending coins."));
        ui->deleteAddress->setVisible(true);
<<<<<<< HEAD
        ui->signMessage->setVisible(false);
        break;
    case ReceivingTab:
        ui->labelExplanation->setText(tr("These are your Dogecoin addresses for receiving payments. You may want to give a different one to each sender so you can keep track of who is paying you."));
        ui->deleteAddress->setVisible(false);
        ui->signMessage->setVisible(true);
=======
        break;
    case ReceivingTab:
        ui->labelExplanation->setText(tr("These are your Dogecoin addresses for receiving payments. It is recommended to use a new receiving address for each transaction."));
        ui->deleteAddress->setVisible(false);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        break;
    }

    // Context menu actions
<<<<<<< HEAD
    QAction *copyAddressAction = new QAction(ui->copyAddress->text(), this);
    QAction *copyLabelAction = new QAction(tr("Copy &Label"), this);
    QAction *editAction = new QAction(tr("&Edit"), this);
    QAction *sendCoinsAction = new QAction(tr("Send &Coins"), this);
    QAction *showQRCodeAction = new QAction(ui->showQRCode->text(), this);
    QAction *signMessageAction = new QAction(ui->signMessage->text(), this);
    QAction *verifyMessageAction = new QAction(ui->verifyMessage->text(), this);
=======
    QAction *copyAddressAction = new QAction(tr("&Copy Address"), this);
    QAction *copyLabelAction = new QAction(tr("Copy &Label"), this);
    QAction *editAction = new QAction(tr("&Edit"), this);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    deleteAction = new QAction(ui->deleteAddress->text(), this);

    // Build context menu
    contextMenu = new QMenu();
    contextMenu->addAction(copyAddressAction);
    contextMenu->addAction(copyLabelAction);
    contextMenu->addAction(editAction);
    if(tab == SendingTab)
        contextMenu->addAction(deleteAction);
    contextMenu->addSeparator();
<<<<<<< HEAD
    if(tab == SendingTab)
        contextMenu->addAction(sendCoinsAction);
#ifdef USE_QRCODE
    contextMenu->addAction(showQRCodeAction);
#endif
    if(tab == ReceivingTab)
        contextMenu->addAction(signMessageAction);
    else if(tab == SendingTab)
        contextMenu->addAction(verifyMessageAction);
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    // Connect signals for context menu actions
    connect(copyAddressAction, SIGNAL(triggered()), this, SLOT(on_copyAddress_clicked()));
    connect(copyLabelAction, SIGNAL(triggered()), this, SLOT(onCopyLabelAction()));
    connect(editAction, SIGNAL(triggered()), this, SLOT(onEditAction()));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(on_deleteAddress_clicked()));
<<<<<<< HEAD
    connect(sendCoinsAction, SIGNAL(triggered()), this, SLOT(onSendCoinsAction()));
    connect(showQRCodeAction, SIGNAL(triggered()), this, SLOT(on_showQRCode_clicked()));
    connect(signMessageAction, SIGNAL(triggered()), this, SLOT(on_signMessage_clicked()));
    connect(verifyMessageAction, SIGNAL(triggered()), this, SLOT(on_verifyMessage_clicked()));

    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextualMenu(QPoint)));

    // Pass through accept action from button box
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
=======

    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextualMenu(QPoint)));

    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(accept()));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

AddressBookPage::~AddressBookPage()
{
    delete ui;
}

void AddressBookPage::setModel(AddressTableModel *model)
{
    this->model = model;
    if(!model)
        return;

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setDynamicSortFilter(true);
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    switch(tab)
    {
    case ReceivingTab:
        // Receive filter
        proxyModel->setFilterRole(AddressTableModel::TypeRole);
        proxyModel->setFilterFixedString(AddressTableModel::Receive);
        break;
    case SendingTab:
        // Send filter
        proxyModel->setFilterRole(AddressTableModel::TypeRole);
        proxyModel->setFilterFixedString(AddressTableModel::Send);
        break;
    }
    ui->tableView->setModel(proxyModel);
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);

    // Set column widths
#if QT_VERSION < 0x050000
    ui->tableView->horizontalHeader()->setResizeMode(AddressTableModel::Label, QHeaderView::Stretch);
<<<<<<< HEAD
    ui->tableView->horizontalHeader()->setResizeMode(AddressTableModel::Address, QHeaderView::Interactive);
#else
    ui->tableView->horizontalHeader()->setSectionResizeMode(AddressTableModel::Label, QHeaderView::Interactive);
    ui->tableView->horizontalHeader()->setSectionResizeMode(AddressTableModel::Address, QHeaderView::Stretch);
#endif

    connect(ui->tableView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(selectionChanged()));
=======
    ui->tableView->horizontalHeader()->setResizeMode(AddressTableModel::Address, QHeaderView::ResizeToContents);
#else
    ui->tableView->horizontalHeader()->setSectionResizeMode(AddressTableModel::Label, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(AddressTableModel::Address, QHeaderView::ResizeToContents);
#endif

    connect(ui->tableView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
        this, SLOT(selectionChanged()));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    // Select row for newly created address
    connect(model, SIGNAL(rowsInserted(QModelIndex,int,int)), this, SLOT(selectNewAddress(QModelIndex,int,int)));

    selectionChanged();
}

<<<<<<< HEAD
void AddressBookPage::setOptionsModel(OptionsModel *optionsModel)
{
    this->optionsModel = optionsModel;
}

=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
void AddressBookPage::on_copyAddress_clicked()
{
    GUIUtil::copyEntryData(ui->tableView, AddressTableModel::Address);
}

void AddressBookPage::onCopyLabelAction()
{
    GUIUtil::copyEntryData(ui->tableView, AddressTableModel::Label);
}

void AddressBookPage::onEditAction()
{
<<<<<<< HEAD
=======
    if(!model)
        return;

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    if(!ui->tableView->selectionModel())
        return;
    QModelIndexList indexes = ui->tableView->selectionModel()->selectedRows();
    if(indexes.isEmpty())
        return;

    EditAddressDialog dlg(
<<<<<<< HEAD
            tab == SendingTab ?
            EditAddressDialog::EditSendingAddress :
            EditAddressDialog::EditReceivingAddress);
=======
        tab == SendingTab ?
        EditAddressDialog::EditSendingAddress :
        EditAddressDialog::EditReceivingAddress, this);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    dlg.setModel(model);
    QModelIndex origIndex = proxyModel->mapToSource(indexes.at(0));
    dlg.loadRow(origIndex.row());
    dlg.exec();
}

<<<<<<< HEAD
void AddressBookPage::on_signMessage_clicked()
{
    QTableView *table = ui->tableView;
    QModelIndexList indexes = table->selectionModel()->selectedRows(AddressTableModel::Address);

    foreach (QModelIndex index, indexes)
    {
        QString address = index.data().toString();
        emit signMessage(address);
    }
}

void AddressBookPage::on_verifyMessage_clicked()
{
    QTableView *table = ui->tableView;
    QModelIndexList indexes = table->selectionModel()->selectedRows(AddressTableModel::Address);

    foreach (QModelIndex index, indexes)
    {
        QString address = index.data().toString();
        emit verifyMessage(address);
    }
}

void AddressBookPage::onSendCoinsAction()
{
    QTableView *table = ui->tableView;
    QModelIndexList indexes = table->selectionModel()->selectedRows(AddressTableModel::Address);

    foreach (QModelIndex index, indexes)
    {
        QString address = index.data().toString();
        emit sendCoins(address);
    }
}

=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
void AddressBookPage::on_newAddress_clicked()
{
    if(!model)
        return;

    EditAddressDialog dlg(
<<<<<<< HEAD
            tab == SendingTab ?
            EditAddressDialog::NewSendingAddress :
            EditAddressDialog::NewReceivingAddress, this);
=======
        tab == SendingTab ?
        EditAddressDialog::NewSendingAddress :
        EditAddressDialog::NewReceivingAddress, this);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    dlg.setModel(model);
    if(dlg.exec())
    {
        newAddressToSelect = dlg.getAddress();
    }
}

void AddressBookPage::on_deleteAddress_clicked()
{
    QTableView *table = ui->tableView;
    if(!table->selectionModel())
        return;

    QModelIndexList indexes = table->selectionModel()->selectedRows();
    if(!indexes.isEmpty())
    {
        table->model()->removeRow(indexes.at(0).row());
    }
}

void AddressBookPage::selectionChanged()
{
    // Set button states based on selected tab and selection
    QTableView *table = ui->tableView;
    if(!table->selectionModel())
        return;

    if(table->selectionModel()->hasSelection())
    {
        switch(tab)
        {
        case SendingTab:
            // In sending tab, allow deletion of selection
            ui->deleteAddress->setEnabled(true);
            ui->deleteAddress->setVisible(true);
            deleteAction->setEnabled(true);
<<<<<<< HEAD
            ui->signMessage->setEnabled(false);
            ui->signMessage->setVisible(false);
            ui->verifyMessage->setEnabled(true);
            ui->verifyMessage->setVisible(true);
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            break;
        case ReceivingTab:
            // Deleting receiving addresses, however, is not allowed
            ui->deleteAddress->setEnabled(false);
            ui->deleteAddress->setVisible(false);
            deleteAction->setEnabled(false);
<<<<<<< HEAD
            ui->signMessage->setEnabled(true);
            ui->signMessage->setVisible(true);
            ui->verifyMessage->setEnabled(false);
            ui->verifyMessage->setVisible(false);
            break;
        }
        ui->copyAddress->setEnabled(true);
        ui->showQRCode->setEnabled(true);
=======
            break;
        }
        ui->copyAddress->setEnabled(true);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
    else
    {
        ui->deleteAddress->setEnabled(false);
<<<<<<< HEAD
        ui->showQRCode->setEnabled(false);
        ui->copyAddress->setEnabled(false);
        ui->signMessage->setEnabled(false);
        ui->verifyMessage->setEnabled(false);
=======
        ui->copyAddress->setEnabled(false);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
}

void AddressBookPage::done(int retval)
{
    QTableView *table = ui->tableView;
    if(!table->selectionModel() || !table->model())
        return;
<<<<<<< HEAD
    // When this is a tab/widget and not a model dialog, ignore "done"
    if(mode == ForEditing)
        return;
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    // Figure out which address was selected, and return it
    QModelIndexList indexes = table->selectionModel()->selectedRows(AddressTableModel::Address);

    foreach (QModelIndex index, indexes)
    {
        QVariant address = table->model()->data(index);
        returnValue = address.toString();
    }

    if(returnValue.isEmpty())
    {
        // If no address entry selected, return rejected
        retval = Rejected;
    }

    QDialog::done(retval);
}

void AddressBookPage::on_exportButton_clicked()
{
    // CSV is currently the only supported format
<<<<<<< HEAD
    QString filename = GUIUtil::getSaveFileName(
            this,
            tr("Export Address Book Data"), QString(),
            tr("Comma separated file (*.csv)"));

    if (filename.isNull()) return;
=======
    QString filename = GUIUtil::getSaveFileName(this,
        tr("Export Address List"), QString(),
        tr("Comma separated file (*.csv)"), NULL);

    if (filename.isNull())
        return;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    CSVModelWriter writer(filename);

    // name, column, role
    writer.setModel(proxyModel);
    writer.addColumn("Label", AddressTableModel::Label, Qt::EditRole);
    writer.addColumn("Address", AddressTableModel::Address, Qt::EditRole);

<<<<<<< HEAD
    if(!writer.write())
    {
        QMessageBox::critical(this, tr("Error exporting"), tr("Could not write to file %1.").arg(filename),
                              QMessageBox::Abort, QMessageBox::Abort);
    }
}

void AddressBookPage::on_showQRCode_clicked()
{
#ifdef USE_QRCODE
    QTableView *table = ui->tableView;
    QModelIndexList indexes = table->selectionModel()->selectedRows(AddressTableModel::Address);

    foreach (QModelIndex index, indexes)
    {
        QString address = index.data().toString();
        QString label = index.sibling(index.row(), 0).data(Qt::EditRole).toString();

        QRCodeDialog *dialog = new QRCodeDialog(address, label, tab == ReceivingTab, this);
        dialog->setModel(optionsModel);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    }
#endif
}

=======
    if(!writer.write()) {
        QMessageBox::critical(this, tr("Exporting Failed"),
            tr("There was an error trying to save the address list to %1.").arg(filename));
    }
}

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
void AddressBookPage::contextualMenu(const QPoint &point)
{
    QModelIndex index = ui->tableView->indexAt(point);
    if(index.isValid())
    {
        contextMenu->exec(QCursor::pos());
    }
}

void AddressBookPage::selectNewAddress(const QModelIndex &parent, int begin, int /*end*/)
{
    QModelIndex idx = proxyModel->mapFromSource(model->index(begin, AddressTableModel::Address, parent));
    if(idx.isValid() && (idx.data(Qt::EditRole).toString() == newAddressToSelect))
    {
        // Select row of newly created address, once
        ui->tableView->setFocus();
        ui->tableView->selectRow(idx.row());
        newAddressToSelect.clear();
    }
}
