<<<<<<< HEAD
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H

#include <QObject>

<<<<<<< HEAD
class OptionsModel;
class AddressTableModel;
class TransactionTableModel;
=======
class AddressTableModel;
class OptionsModel;
class TransactionTableModel;

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
class CWallet;

QT_BEGIN_NAMESPACE
class QDateTime;
class QTimer;
QT_END_NAMESPACE

enum BlockSource {
    BLOCK_SOURCE_NONE,
    BLOCK_SOURCE_REINDEX,
    BLOCK_SOURCE_DISK,
    BLOCK_SOURCE_NETWORK
};

/** Model for Bitcoin network client. */
class ClientModel : public QObject
{
    Q_OBJECT

public:
    explicit ClientModel(OptionsModel *optionsModel, QObject *parent = 0);
    ~ClientModel();

    OptionsModel *getOptionsModel();

    int getNumConnections() const;
    int getNumBlocks() const;
    int getNumBlocksAtStartup();

<<<<<<< HEAD
    double getVerificationProgress() const;
    QDateTime getLastBlockDate() const;

    //! Return true if client connected to testnet
    bool isTestNet() const;
=======
    quint64 getTotalBytesRecv() const;
    quint64 getTotalBytesSent() const;

    double getVerificationProgress() const;
    QDateTime getLastBlockDate() const;

    //! Return network (main, testnet3, regtest)
    QString getNetworkName() const;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    //! Return true if core is doing initial block download
    bool inInitialBlockDownload() const;
    //! Return true if core is importing blocks
    enum BlockSource getBlockSource() const;
    //! Return conservative estimate of total number of blocks, or 0 if unknown
    int getNumBlocksOfPeers() const;
    //! Return warnings to be displayed in status bar
    QString getStatusBarWarnings() const;

    QString formatFullVersion() const;
    QString formatBuildDate() const;
    bool isReleaseVersion() const;
    QString clientName() const;
    QString formatClientStartupTime() const;

private:
    OptionsModel *optionsModel;

    int cachedNumBlocks;
    int cachedNumBlocksOfPeers;
<<<<<<< HEAD
	bool cachedReindexing;
	bool cachedImporting;
=======
    bool cachedReindexing;
    bool cachedImporting;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    int numBlocksAtStartup;

    QTimer *pollTimer;

    void subscribeToCoreSignals();
    void unsubscribeFromCoreSignals();

signals:
    void numConnectionsChanged(int count);
    void numBlocksChanged(int count, int countOfPeers);
    void alertsChanged(const QString &warnings);
<<<<<<< HEAD

    //! Asynchronous message notification
=======
    void bytesChanged(quint64 totalBytesIn, quint64 totalBytesOut);

    //! Fired when a message should be reported to the user
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    void message(const QString &title, const QString &message, unsigned int style);

public slots:
    void updateTimer();
    void updateNumConnections(int numConnections);
    void updateAlert(const QString &hash, int status);
};

#endif // CLIENTMODEL_H
