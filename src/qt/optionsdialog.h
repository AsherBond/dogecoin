<<<<<<< HEAD
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

<<<<<<< HEAD
namespace Ui {
class OptionsDialog;
}
class OptionsModel;
class MonitoredDataMapper;
class QValidatedLineEdit;
=======
class MonitoredDataMapper;
class OptionsModel;
class QValidatedLineEdit;

namespace Ui {
class OptionsDialog;
}
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

/** Preferences dialog. */
class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit OptionsDialog(QWidget *parent = 0);
=======
    explicit OptionsDialog(QWidget *parent);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ~OptionsDialog();

    void setModel(OptionsModel *model);
    void setMapper();

protected:
    bool eventFilter(QObject *object, QEvent *event);

private slots:
<<<<<<< HEAD
    /* enable only apply button */
    void enableApplyButton();
    /* disable only apply button */
    void disableApplyButton();
    /* enable apply button and OK button */
    void enableSaveButtons();
    /* disable apply button and OK button */
    void disableSaveButtons();
    /* set apply button and OK button state (enabled / disabled) */
    void setSaveButtonState(bool fState);
    void on_resetButton_clicked();
    void on_okButton_clicked();
    void on_cancelButton_clicked();
    void on_applyButton_clicked();

    void showRestartWarning_Proxy();
    void showRestartWarning_Lang();
    void updateDisplayUnit();
    void handleProxyIpValid(QValidatedLineEdit *object, bool fState);

signals:
    void proxyIpValid(QValidatedLineEdit *object, bool fValid);
=======
    /* enable OK button */
    void enableOkButton();
    /* disable OK button */
    void disableOkButton();
    /* set OK button state (enabled / disabled) */
    void setOkButtonState(bool fState);
    void on_resetButton_clicked();
    void on_okButton_clicked();
    void on_cancelButton_clicked();

    void showRestartWarning(bool fPersistent = false);
    void clearStatusLabel();
    void updateDisplayUnit();
    void doProxyIpChecks(QValidatedLineEdit *pUiProxyIp, int nProxyPort);

signals:
    void proxyIpChecks(QValidatedLineEdit *pUiProxyIp, int nProxyPort);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

private:
    Ui::OptionsDialog *ui;
    OptionsModel *model;
    MonitoredDataMapper *mapper;
<<<<<<< HEAD
    bool fRestartWarningDisplayed_Proxy;
    bool fRestartWarningDisplayed_Lang;
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    bool fProxyIpValid;
};

#endif // OPTIONSDIALOG_H
