<<<<<<< HEAD
#include <QTest>
#include <QObject>

#include "uritests.h"
=======
#include "bitcoin-config.h"
#if defined(HAVE_CONFIG_H)
#include "bitcoin-config.h"
#endif

#include "bitcoinunitstests.h"
#include "uritests.h"
#ifdef ENABLE_WALLET
#include "paymentservertests.h"
#endif

#include <QCoreApplication>
#include <QObject>
#include <QTest>

#if defined(QT_STATICPLUGIN) && QT_VERSION < 0x050000
#include <QtPlugin>
Q_IMPORT_PLUGIN(qcncodecs)
Q_IMPORT_PLUGIN(qjpcodecs)
Q_IMPORT_PLUGIN(qtwcodecs)
Q_IMPORT_PLUGIN(qkrcodecs)
#endif
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

// This is all you need to run all the tests
int main(int argc, char *argv[])
{
    bool fInvalid = false;

<<<<<<< HEAD
    URITests test1;
    if (QTest::qExec(&test1) != 0)
        fInvalid = true;
=======
    // Don't remove this, it's needed to access
    // QCoreApplication:: in the tests
    QCoreApplication app(argc, argv);
    app.setApplicationName("Bitcoin-Qt-test");

    URITests test1;
    if (QTest::qExec(&test1) != 0)
        fInvalid = true;
#ifdef ENABLE_WALLET
    PaymentServerTests test2;
    if (QTest::qExec(&test2) != 0)
        fInvalid = true;
#endif
    BitcoinUnitsTests test3;
    if (QTest::qExec(&test3) != 0)
        fInvalid = true;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    return fInvalid;
}
