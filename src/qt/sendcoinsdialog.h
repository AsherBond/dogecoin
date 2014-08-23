<<<<<<< HEAD
#ifndef SENDCOINSDIALOG_H
#define SENDCOINSDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
    class SendCoinsDialog;
}
class WalletModel;
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SENDCOINSDIALOG_H
#define SENDCOINSDIALOG_H

#include "walletmodel.h"

#include <QDialog>
#include <QString>

class OptionsModel;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
class SendCoinsEntry;
class SendCoinsRecipient;

QT_BEGIN_NAMESPACE
class QUrl;
QT_END_NAMESPACE

<<<<<<< HEAD
=======
namespace Ui {
    class SendCoinsDialog;
}

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
/** Dialog for sending bitcoins */
class SendCoinsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SendCoinsDialog(QWidget *parent = 0);
    ~SendCoinsDialog();

    void setModel(WalletModel *model);

    /** Set up the tab chain manually, as Qt messes up the tab chain by default in some cases (issue https://bugreports.qt-project.org/browse/QTBUG-10907).
     */
    QWidget *setupTabChain(QWidget *prev);

    void setAddress(const QString &address);
    void pasteEntry(const SendCoinsRecipient &rv);
<<<<<<< HEAD
    bool handleURI(const QString &uri);
=======
    bool handlePaymentRequest(const SendCoinsRecipient &recipient);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

public slots:
    void clear();
    void reject();
    void accept();
    SendCoinsEntry *addEntry();
<<<<<<< HEAD
    void updateRemoveEnabled();
=======
    void updateTabsAndLabels();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    void setBalance(qint64 balance, qint64 unconfirmedBalance, qint64 immatureBalance);

private:
    Ui::SendCoinsDialog *ui;
    WalletModel *model;
    bool fNewRecipientAllowed;

<<<<<<< HEAD
=======
    // Process WalletModel::SendCoinsReturn and generate a pair consisting
    // of a message and message flags for use in emit message().
    // Additional parameter msgArg can be used via .arg(msgArg).
    void processSendCoinsReturn(const WalletModel::SendCoinsReturn &sendCoinsReturn, const QString &msgArg = QString());

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
private slots:
    void on_sendButton_clicked();
    void removeEntry(SendCoinsEntry* entry);
    void updateDisplayUnit();
    void coinControlFeatureChanged(bool);
    void coinControlButtonClicked();
    void coinControlChangeChecked(int);
    void coinControlChangeEdited(const QString &);
    void coinControlUpdateLabels();
    void coinControlClipboardQuantity();
    void coinControlClipboardAmount();
    void coinControlClipboardFee();
    void coinControlClipboardAfterFee();
    void coinControlClipboardBytes();
    void coinControlClipboardPriority();
    void coinControlClipboardLowOutput();
    void coinControlClipboardChange();
<<<<<<< HEAD
=======

signals:
    // Fired when a message should be reported to the user
    void message(const QString &title, const QString &message, unsigned int style);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
};

#endif // SENDCOINSDIALOG_H
