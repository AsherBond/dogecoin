<<<<<<< HEAD
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef EDITADDRESSDIALOG_H
#define EDITADDRESSDIALOG_H

#include <QDialog>

<<<<<<< HEAD
namespace Ui {
    class EditAddressDialog;
}
class AddressTableModel;
=======
class AddressTableModel;

namespace Ui {
    class EditAddressDialog;
}
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

QT_BEGIN_NAMESPACE
class QDataWidgetMapper;
QT_END_NAMESPACE

/** Dialog for editing an address and associated information.
 */
class EditAddressDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        NewReceivingAddress,
        NewSendingAddress,
        EditReceivingAddress,
        EditSendingAddress
    };

<<<<<<< HEAD
    explicit EditAddressDialog(Mode mode, QWidget *parent = 0);
=======
    explicit EditAddressDialog(Mode mode, QWidget *parent);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ~EditAddressDialog();

    void setModel(AddressTableModel *model);
    void loadRow(int row);

    QString getAddress() const;
    void setAddress(const QString &address);

public slots:
    void accept();

private:
    bool saveCurrentRow();

    Ui::EditAddressDialog *ui;
    QDataWidgetMapper *mapper;
    Mode mode;
    AddressTableModel *model;

    QString address;
};

#endif // EDITADDRESSDIALOG_H
