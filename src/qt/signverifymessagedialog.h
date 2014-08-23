<<<<<<< HEAD
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef SIGNVERIFYMESSAGEDIALOG_H
#define SIGNVERIFYMESSAGEDIALOG_H

#include <QDialog>

<<<<<<< HEAD
namespace Ui {
    class SignVerifyMessageDialog;
}
class WalletModel;
=======
class WalletModel;

namespace Ui {
    class SignVerifyMessageDialog;
}
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

class SignVerifyMessageDialog : public QDialog
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit SignVerifyMessageDialog(QWidget *parent = 0);
=======
    explicit SignVerifyMessageDialog(QWidget *parent);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ~SignVerifyMessageDialog();

    void setModel(WalletModel *model);
    void setAddress_SM(const QString &address);
    void setAddress_VM(const QString &address);

    void showTab_SM(bool fShow);
    void showTab_VM(bool fShow);

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    Ui::SignVerifyMessageDialog *ui;
    WalletModel *model;

private slots:
    /* sign message */
    void on_addressBookButton_SM_clicked();
    void on_pasteButton_SM_clicked();
    void on_signMessageButton_SM_clicked();
    void on_copySignatureButton_SM_clicked();
    void on_clearButton_SM_clicked();
    /* verify message */
    void on_addressBookButton_VM_clicked();
    void on_verifyMessageButton_VM_clicked();
    void on_clearButton_VM_clicked();
};

#endif // SIGNVERIFYMESSAGEDIALOG_H
