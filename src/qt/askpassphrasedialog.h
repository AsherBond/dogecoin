<<<<<<< HEAD
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef ASKPASSPHRASEDIALOG_H
#define ASKPASSPHRASEDIALOG_H

#include <QDialog>

<<<<<<< HEAD
namespace Ui {
    class AskPassphraseDialog;
}
class WalletModel;
=======
class WalletModel;

namespace Ui {
    class AskPassphraseDialog;
}
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class AskPassphraseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,    /**< Ask passphrase twice and encrypt */
        Unlock,     /**< Ask passphrase and unlock */
        ChangePass, /**< Ask old passphrase + new passphrase twice */
        Decrypt     /**< Ask passphrase and decrypt wallet */
    };

<<<<<<< HEAD
    explicit AskPassphraseDialog(Mode mode, QWidget *parent = 0);
=======
    explicit AskPassphraseDialog(Mode mode, QWidget *parent);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ~AskPassphraseDialog();

    void accept();

    void setModel(WalletModel *model);

private:
    Ui::AskPassphraseDialog *ui;
    Mode mode;
    WalletModel *model;
    bool fCapsLock;

private slots:
    void textChanged();
<<<<<<< HEAD
=======

protected:
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    bool event(QEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // ASKPASSPHRASEDIALOG_H
