<<<<<<< HEAD
#ifndef SENDCOINSENTRY_H
#define SENDCOINSENTRY_H

#include <QFrame>
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SENDCOINSENTRY_H
#define SENDCOINSENTRY_H

#include "walletmodel.h"

#include <QStackedWidget>

class WalletModel;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

namespace Ui {
    class SendCoinsEntry;
}
<<<<<<< HEAD
class WalletModel;
class SendCoinsRecipient;

/** A single entry in the dialog for sending bitcoins. */
class SendCoinsEntry : public QFrame
=======

/**
 * A single entry in the dialog for sending bitcoins.
 * Stacked widget, with different UIs for payment requests
 * with a strong payee identity.
 */
class SendCoinsEntry : public QStackedWidget
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    Q_OBJECT

public:
    explicit SendCoinsEntry(QWidget *parent = 0);
    ~SendCoinsEntry();

    void setModel(WalletModel *model);
    bool validate();
    SendCoinsRecipient getValue();

    /** Return whether the entry is still empty and unedited */
    bool isClear();

    void setValue(const SendCoinsRecipient &value);
    void setAddress(const QString &address);

<<<<<<< HEAD
    /** Set up the tab chain manually, as Qt messes up the tab chain by default in some cases (issue https://bugreports.qt-project.org/browse/QTBUG-10907).
=======
    /** Set up the tab chain manually, as Qt messes up the tab chain by default in some cases
     *  (issue https://bugreports.qt-project.org/browse/QTBUG-10907).
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
     */
    QWidget *setupTabChain(QWidget *prev);

    void setFocus();

public slots:
<<<<<<< HEAD
    void setRemoveEnabled(bool enabled);
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    void clear();

signals:
    void removeEntry(SendCoinsEntry *entry);
    void payAmountChanged();

private slots:
<<<<<<< HEAD
    void on_deleteButton_clicked();
=======
    void deleteClicked();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    void on_payTo_textChanged(const QString &address);
    void on_addressBookButton_clicked();
    void on_pasteButton_clicked();
    void updateDisplayUnit();

private:
<<<<<<< HEAD
    Ui::SendCoinsEntry *ui;
    WalletModel *model;
=======
    SendCoinsRecipient recipient;
    Ui::SendCoinsEntry *ui;
    WalletModel *model;

    bool updateLabel(const QString &address);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
};

#endif // SENDCOINSENTRY_H
