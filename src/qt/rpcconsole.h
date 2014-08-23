<<<<<<< HEAD
=======
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef RPCCONSOLE_H
#define RPCCONSOLE_H

#include <QDialog>

<<<<<<< HEAD
namespace Ui {
    class RPCConsole;
}
class ClientModel;
=======
class ClientModel;

namespace Ui {
    class RPCConsole;
}
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

/** Local Bitcoin RPC console. */
class RPCConsole: public QDialog
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit RPCConsole(QWidget *parent = 0);
=======
    explicit RPCConsole(QWidget *parent);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    ~RPCConsole();

    void setClientModel(ClientModel *model);

    enum MessageClass {
        MC_ERROR,
        MC_DEBUG,
        CMD_REQUEST,
        CMD_REPLY,
        CMD_ERROR
    };

protected:
    virtual bool eventFilter(QObject* obj, QEvent *event);

private slots:
    void on_lineEdit_returnPressed();
    void on_tabWidget_currentChanged(int index);
    /** open the debug.log from the current datadir */
    void on_openDebugLogfileButton_clicked();
<<<<<<< HEAD
    /** display messagebox with program parameters (same as bitcoin-qt --help) */
    void on_showCLOptionsButton_clicked();
=======
    /** change the time range of the network traffic graph */
    void on_sldGraphRange_valueChanged(int value);
    /** update traffic statistics */
    void updateTrafficStats(quint64 totalBytesIn, quint64 totalBytesOut);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

public slots:
    void clear();
    void message(int category, const QString &message, bool html = false);
    /** Set number of connections shown in the UI */
    void setNumConnections(int count);
    /** Set number of blocks shown in the UI */
    void setNumBlocks(int count, int countOfPeers);
    /** Go forward or back in history */
    void browseHistory(int offset);
    /** Scroll console view to end */
    void scrollToEnd();
<<<<<<< HEAD
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
signals:
    // For RPC command executor
    void stopExecutor();
    void cmdRequest(const QString &command);

private:
<<<<<<< HEAD
=======
    static QString FormatBytes(quint64 bytes);
    void setTrafficGraphRange(int mins);

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    Ui::RPCConsole *ui;
    ClientModel *clientModel;
    QStringList history;
    int historyPtr;

    void startExecutor();
};

#endif // RPCCONSOLE_H
