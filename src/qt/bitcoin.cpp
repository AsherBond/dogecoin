<<<<<<< HEAD
/*
 * W.J. van der Laan 2011-2012
 */

#include <QApplication>

#include "bitcoingui.h"
#include "clientmodel.h"
#include "walletmodel.h"
#include "optionsmodel.h"
#include "guiutil.h"
#include "guiconstants.h"
#include "init.h"
#include "util.h"
#include "ui_interface.h"
#include "paymentserver.h"
#include "splashscreen.h"

#include <QMessageBox>
#if QT_VERSION < 0x050000
#include <QTextCodec>
#endif
#include <QLocale>
#include <QTimer>
#include <QTranslator>
#include <QLibraryInfo>

#ifdef Q_OS_MAC
#include "macdockiconhandler.h"
#endif

#if defined(BITCOIN_NEED_QT_PLUGINS) && !defined(_BITCOIN_QT_PLUGINS_INCLUDED)
#define _BITCOIN_QT_PLUGINS_INCLUDED
#define __INSURE__
#include <QtPlugin>
=======
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#if defined(HAVE_CONFIG_H)
#include "bitcoin-config.h"
#endif

#include "bitcoingui.h"

#include "clientmodel.h"
#include "guiconstants.h"
#include "guiutil.h"
#include "intro.h"
#include "optionsmodel.h"
#include "splashscreen.h"
#include "utilitydialog.h"
#ifdef ENABLE_WALLET
#include "paymentserver.h"
#include "walletmodel.h"
#endif

#include "init.h"
#include "main.h"
#include "rpcserver.h"
#include "ui_interface.h"
#include "util.h"
#include "wallet.h"

#include <stdint.h>

#include <boost/filesystem/operations.hpp>
#include <QApplication>
#include <QLibraryInfo>
#include <QLocale>
#include <QMessageBox>
#include <QSettings>
#include <QTimer>
#include <QTranslator>
#include <QThread>

#if defined(QT_STATICPLUGIN)
#include <QtPlugin>
#if QT_VERSION < 0x050000
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
Q_IMPORT_PLUGIN(qcncodecs)
Q_IMPORT_PLUGIN(qjpcodecs)
Q_IMPORT_PLUGIN(qtwcodecs)
Q_IMPORT_PLUGIN(qkrcodecs)
Q_IMPORT_PLUGIN(qtaccessiblewidgets)
<<<<<<< HEAD
=======
#else
Q_IMPORT_PLUGIN(AccessibleFactory)
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
#endif
#endif

#if QT_VERSION < 0x050000
#include <QTextCodec>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#endif

// Declare meta types used for QMetaObject::invokeMethod
Q_DECLARE_METATYPE(bool*)

<<<<<<< HEAD
// Need a global reference for the notifications to find the GUI
static BitcoinGUI *guiref;
static SplashScreen *splashref;

static bool ThreadSafeMessageBox(const std::string& message, const std::string& caption, unsigned int style)
{
    // Message from network thread
    if(guiref)
    {
        bool modal = (style & CClientUIInterface::MODAL);
        bool ret = false;
        // In case of modal message, use blocking connection to wait for user to click a button
        QMetaObject::invokeMethod(guiref, "message",
                                   modal ? GUIUtil::blockingGUIThreadConnection() : Qt::QueuedConnection,
                                   Q_ARG(QString, QString::fromStdString(caption)),
                                   Q_ARG(QString, QString::fromStdString(message)),
                                   Q_ARG(unsigned int, style),
                                   Q_ARG(bool*, &ret));
        return ret;
    }
    else
    {
        printf("%s: %s\n", caption.c_str(), message.c_str());
        fprintf(stderr, "%s: %s\n", caption.c_str(), message.c_str());
        return false;
    }
}

static bool ThreadSafeAskFee(int64 nFeeRequired)
{
    if(!guiref)
        return false;
    if(nFeeRequired < CTransaction::nMinTxFee || nFeeRequired <= nTransactionFee || fDaemon)
        return true;

    bool payFee = false;

    QMetaObject::invokeMethod(guiref, "askFee", GUIUtil::blockingGUIThreadConnection(),
                               Q_ARG(qint64, nFeeRequired),
                               Q_ARG(bool*, &payFee));

    return payFee;
}

static void InitMessage(const std::string &message)
{
    if(splashref)
    {
        splashref->showMessage(QString::fromStdString(message), Qt::AlignBottom|Qt::AlignHCenter, QColor(55,55,55));
        qApp->processEvents();
    }
    printf("init message: %s\n", message.c_str());
}

/*
   Translate string to current locale using Qt.
 */
static std::string Translate(const char* psz)
{
    return QCoreApplication::translate("bitcoin-core", psz).toStdString();
}

/* Handle runaway exceptions. Shows a message box with the problem and quits the program.
 */
static void handleRunawayException(std::exception *e)
{
    PrintExceptionContinue(e, "Runaway exception");
    QMessageBox::critical(0, "Runaway exception", BitcoinGUI::tr("A fatal error occurred. Dogecoin can no longer continue safely and will quit.") + QString("\n\n") + QString::fromStdString(strMiscWarning));
    exit(1);
=======
static void InitMessage(const std::string &message)
{
    LogPrintf("init message: %s\n", message);
}

/*
   Translate string to current locale using Qt.
 */
static std::string Translate(const char* psz)
{
    return QCoreApplication::translate("bitcoin-core", psz).toStdString();
}

/** Set up translations */
static void initTranslations(QTranslator &qtTranslatorBase, QTranslator &qtTranslator, QTranslator &translatorBase, QTranslator &translator)
{
    QSettings settings;

    // Remove old translators
    QApplication::removeTranslator(&qtTranslatorBase);
    QApplication::removeTranslator(&qtTranslator);
    QApplication::removeTranslator(&translatorBase);
    QApplication::removeTranslator(&translator);

    // Get desired locale (e.g. "de_DE")
    // 1) System default language
    QString lang_territory = QLocale::system().name();
    // 2) Language from QSettings
    QString lang_territory_qsettings = settings.value("language", "").toString();
    if(!lang_territory_qsettings.isEmpty())
        lang_territory = lang_territory_qsettings;
    // 3) -lang command line argument
    lang_territory = QString::fromStdString(GetArg("-lang", lang_territory.toStdString()));

    // Convert to "de" only by truncating "_DE"
    QString lang = lang_territory;
    lang.truncate(lang_territory.lastIndexOf('_'));

    // Load language files for configured locale:
    // - First load the translator for the base language, without territory
    // - Then load the more specific locale translator

    // Load e.g. qt_de.qm
    if (qtTranslatorBase.load("qt_" + lang, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        QApplication::installTranslator(&qtTranslatorBase);

    // Load e.g. qt_de_DE.qm
    if (qtTranslator.load("qt_" + lang_territory, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        QApplication::installTranslator(&qtTranslator);

    // Load e.g. bitcoin_de.qm (shortcut "de" needs to be defined in bitcoin.qrc)
    if (translatorBase.load(lang, ":/translations/"))
        QApplication::installTranslator(&translatorBase);

    // Load e.g. bitcoin_de_DE.qm (shortcut "de_DE" needs to be defined in bitcoin.qrc)
    if (translator.load(lang_territory, ":/translations/"))
        QApplication::installTranslator(&translator);
}

/* qDebug() message handler --> debug.log */
#if QT_VERSION < 0x050000
void DebugMessageHandler(QtMsgType type, const char *msg)
{
    Q_UNUSED(type);
    LogPrint("qt", "GUI: %s\n", msg);
}
#else
void DebugMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString &msg)
{
    Q_UNUSED(type);
    Q_UNUSED(context);
    LogPrint("qt", "GUI: %s\n", qPrintable(msg));
}
#endif

/** Class encapsulating Dogecoin Core startup and shutdown.
 * Allows running startup and shutdown in a different thread from the UI thread.
 */
class BitcoinCore: public QObject
{
    Q_OBJECT
public:
    explicit BitcoinCore();

public slots:
    void initialize();
    void shutdown();

signals:
    void initializeResult(int retval);
    void shutdownResult(int retval);
    void runawayException(const QString &message);

private:
    boost::thread_group threadGroup;

    /// Pass fatal exception message to UI thread
    void handleRunawayException(std::exception *e);
};

/** Main Dogecoin application object */
class BitcoinApplication: public QApplication
{
    Q_OBJECT
public:
    explicit BitcoinApplication(int &argc, char **argv);
    ~BitcoinApplication();

#ifdef ENABLE_WALLET
    /// Create payment server
    // void createPaymentServer();
#endif
    /// Create options model
    void createOptionsModel();
    /// Create main window
    void createWindow(bool isaTestNet);
    /// Create splash screen
    void createSplashScreen(bool isaTestNet);

    /// Request core initialization
    void requestInitialize();
    /// Request core shutdown
    void requestShutdown();

    /// Get process return value
    int getReturnValue() { return returnValue; }

public slots:
    void initializeResult(int retval);
    void shutdownResult(int retval);
    /// Handle runaway exceptions. Shows a message box with the problem and quits the program.
    void handleRunawayException(const QString &message);

signals:
    void requestedInitialize();
    void requestedShutdown();
    void stopThread();
    void splashFinished(QWidget *window);

private:
    QThread *coreThread;
    OptionsModel *optionsModel;
    ClientModel *clientModel;
    BitcoinGUI *window;
    QTimer *pollShutdownTimer;
#ifdef ENABLE_WALLET
    // PaymentServer* paymentServer;
    WalletModel *walletModel;
#endif
    int returnValue;

    void startThread();
};

#include "bitcoin.moc"

BitcoinCore::BitcoinCore():
    QObject()
{
}

void BitcoinCore::handleRunawayException(std::exception *e)
{
    PrintExceptionContinue(e, "Runaway exception");
    emit runawayException(QString::fromStdString(strMiscWarning));
}

void BitcoinCore::initialize()
{
    try
    {
        LogPrintf("Running AppInit2 in thread\n");
        int rv = AppInit2(threadGroup);
        if(rv)
        {
            /* Start a dummy RPC thread if no RPC thread is active yet
             * to handle timeouts.
             */
            StartDummyRPCThread();
        }
        emit initializeResult(rv);
    } catch (std::exception& e) {
        handleRunawayException(&e);
    } catch (...) {
        handleRunawayException(NULL);
    }
}

void BitcoinCore::shutdown()
{
    try
    {
        LogPrintf("Running Shutdown in thread\n");
        threadGroup.interrupt_all();
        threadGroup.join_all();
        Shutdown();
        LogPrintf("Shutdown finished\n");
        emit shutdownResult(1);
    } catch (std::exception& e) {
        handleRunawayException(&e);
    } catch (...) {
        handleRunawayException(NULL);
    }
}

BitcoinApplication::BitcoinApplication(int &argc, char **argv):
    QApplication(argc, argv),
    coreThread(0),
    optionsModel(0),
    clientModel(0),
    window(0),
    pollShutdownTimer(0),
#ifdef ENABLE_WALLET
    // paymentServer(0),
    walletModel(0),
#endif
    returnValue(0)
{
    setQuitOnLastWindowClosed(false);
    startThread();
}

BitcoinApplication::~BitcoinApplication()
{
    LogPrintf("Stopping thread\n");
    emit stopThread();
    coreThread->wait();
    LogPrintf("Stopped thread\n");

    delete window;
    window = 0;
#ifdef ENABLE_WALLET
    // delete paymentServer;
    // paymentServer = 0;
#endif
    delete optionsModel;
    optionsModel = 0;
}

#ifdef ENABLE_WALLET
/*
void BitcoinApplication::createPaymentServer()
{
    paymentServer = new PaymentServer(this);
}
*/
#endif

void BitcoinApplication::createOptionsModel()
{
    optionsModel = new OptionsModel();
}

void BitcoinApplication::createWindow(bool isaTestNet)
{
    window = new BitcoinGUI(isaTestNet, 0);

    pollShutdownTimer = new QTimer(window);
    connect(pollShutdownTimer, SIGNAL(timeout()), window, SLOT(detectShutdown()));
    pollShutdownTimer->start(200);
}

void BitcoinApplication::createSplashScreen(bool isaTestNet)
{
    SplashScreen *splash = new SplashScreen(QPixmap(), 0, isaTestNet);
    splash->setAttribute(Qt::WA_DeleteOnClose);
#if MAC_OSX
        // QSplashScreen on Mac seems to always stay on top. Ugh.
        splash->setWindowFlags(Qt::FramelessWindowHint);
#endif
    splash->show();
    connect(this, SIGNAL(splashFinished(QWidget*)), splash, SLOT(slotFinish(QWidget*)));
}

void BitcoinApplication::startThread()
{
    coreThread = new QThread(this);
    BitcoinCore *executor = new BitcoinCore();
    executor->moveToThread(coreThread);

    /*  communication to and from thread */
    connect(executor, SIGNAL(initializeResult(int)), this, SLOT(initializeResult(int)));
    connect(executor, SIGNAL(shutdownResult(int)), this, SLOT(shutdownResult(int)));
    connect(executor, SIGNAL(runawayException(QString)), this, SLOT(handleRunawayException(QString)));
    connect(this, SIGNAL(requestedInitialize()), executor, SLOT(initialize()));
    connect(this, SIGNAL(requestedShutdown()), executor, SLOT(shutdown()));
    /*  make sure executor object is deleted in its own thread */
    connect(this, SIGNAL(stopThread()), executor, SLOT(deleteLater()));
    connect(this, SIGNAL(stopThread()), coreThread, SLOT(quit()));

    coreThread->start();
}

void BitcoinApplication::requestInitialize()
{
    LogPrintf("Requesting initialize\n");
    emit requestedInitialize();
}

void BitcoinApplication::requestShutdown()
{
    LogPrintf("Requesting shutdown\n");
    window->hide();
    window->setClientModel(0);
    pollShutdownTimer->stop();

#ifdef ENABLE_WALLET
    window->removeAllWallets();
    delete walletModel;
    walletModel = 0;
#endif
    delete clientModel;
    clientModel = 0;

    // Show a simple window indicating shutdown status
    ShutdownWindow::showShutdownWindow(window);

    // Request shutdown from core thread
    emit requestedShutdown();
}

void BitcoinApplication::initializeResult(int retval)
{
    LogPrintf("Initialization result: %i\n", retval);
    // Set exit result: 0 if successful, 1 if failure
    returnValue = retval ? 0 : 1;
    if(retval)
    {
/*
#ifdef ENABLE_WALLET
        PaymentServer::LoadRootCAs();
        paymentServer->setOptionsModel(optionsModel);
#endif
*/

        emit splashFinished(window);

        clientModel = new ClientModel(optionsModel);
        window->setClientModel(clientModel);

#ifdef ENABLE_WALLET
        if(pwalletMain)
        {
            walletModel = new WalletModel(pwalletMain, optionsModel);

            window->addWallet("~Default", walletModel);
            window->setCurrentWallet("~Default");

/*
            connect(walletModel, SIGNAL(coinsSent(CWallet*,SendCoinsRecipient,QByteArray)),
                             paymentServer, SLOT(fetchPaymentACK(CWallet*,const SendCoinsRecipient&,QByteArray)));
*/
        }
#endif

        // If -min option passed, start window minimized.
        if(GetBoolArg("-min", false))
        {
            window->showMinimized();
        }
        else
        {
            window->show();
        }
#ifdef ENABLE_WALLET
        // Payment server disabled pending future work on specifications

        // Now that initialization/startup is done, process any command-line
        // dogecoin: URIs or payment requests:
        /*
        connect(paymentServer, SIGNAL(receivedPaymentRequest(SendCoinsRecipient)),
                         window, SLOT(handlePaymentRequest(SendCoinsRecipient)));
        connect(window, SIGNAL(receivedURI(QString)),
                         paymentServer, SLOT(handleURIOrFile(QString)));
        connect(paymentServer, SIGNAL(message(QString,QString,unsigned int)),
                         window, SLOT(message(QString,QString,unsigned int)));
        QTimer::singleShot(100, paymentServer, SLOT(uiReady()));
        */
#endif
    } else {
        quit(); // Exit main loop
    }
}

void BitcoinApplication::shutdownResult(int retval)
{
    LogPrintf("Shutdown result: %i\n", retval);
    quit(); // Exit main loop after shutdown finished
}

void BitcoinApplication::handleRunawayException(const QString &message)
{
    QMessageBox::critical(0, "Runaway exception", BitcoinGUI::tr("A fatal error occurred. Dogecoin Core can no longer continue safely and will quit.") + QString("\n\n") + message);
    ::exit(1);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

#ifndef BITCOIN_QT_TEST
int main(int argc, char *argv[])
{
<<<<<<< HEAD
    // Command-line options take precedence:
    ParseParameters(argc, argv);

=======
    /// 1. Parse command-line options. These take precedence over anything else.
    // Command-line options take precedence:
    ParseParameters(argc, argv);

    // Do not refer to data directory yet, this can be overridden by Intro::pickDataDirectory

    /// 2. Basic Qt initialization (not dependent on parameters or configuration)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#if QT_VERSION < 0x050000
    // Internal string conversion is all UTF-8
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForTr());
#endif

    Q_INIT_RESOURCE(bitcoin);
<<<<<<< HEAD
    QApplication app(argc, argv);
=======
    BitcoinApplication app(argc, argv);
#if QT_VERSION > 0x050100
    // Generate high-dpi pixmaps
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif
#ifdef Q_OS_MAC
    QApplication::setAttribute(Qt::AA_DontShowIconsInMenus);
#endif
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    // Register meta types used for QMetaObject::invokeMethod
    qRegisterMetaType< bool* >();

<<<<<<< HEAD
    // Do this early as we don't want to bother initializing if we are just calling IPC
    // ... but do it after creating app, so QCoreApplication::arguments is initialized:
    if (PaymentServer::ipcSendCommandLine())
        exit(0);
    PaymentServer* paymentServer = new PaymentServer(&app);

    // Install global event filter that makes sure that long tooltips can be word-wrapped
    app.installEventFilter(new GUIUtil::ToolTipToRichTextFilter(TOOLTIP_WRAP_THRESHOLD, &app));

    // ... then bitcoin.conf:
    if (!boost::filesystem::is_directory(GetDataDir(false)))
    {
        // This message can not be translated, as translation is not initialized yet
        // (which not yet possible because lang=XX can be overridden in bitcoin.conf in the data directory)
        QMessageBox::critical(0, "Dogecoin",
                              QString("Error: Specified data directory \"%1\" does not exist.").arg(QString::fromStdString(mapArgs["-datadir"])));
        return 1;
    }
    ReadConfigFile(mapArgs, mapMultiArgs);

    // Application identification (must be set before OptionsModel is initialized,
    // as it is used to locate QSettings)
    QApplication::setOrganizationName("Dogecoin");
    QApplication::setOrganizationDomain("dogecoin-noexist-domain.org");
    if(GetBoolArg("-testnet")) // Separate UI settings for testnet
        QApplication::setApplicationName("Dogecoin-Qt-testnet");
    else
        QApplication::setApplicationName("Dogecoin-Qt");

    // ... then GUI settings:
    OptionsModel optionsModel;

    // Get desired locale (e.g. "de_DE") from command line or use system locale
    QString lang_territory = QString::fromStdString(GetArg("-lang", QLocale::system().name().toStdString()));
    QString lang = lang_territory;
    // Convert to "de" only by truncating "_DE"
    lang.truncate(lang_territory.lastIndexOf('_'));

    QTranslator qtTranslatorBase, qtTranslator, translatorBase, translator;
    // Load language files for configured locale:
    // - First load the translator for the base language, without territory
    // - Then load the more specific locale translator

    // Load e.g. qt_de.qm
    if (qtTranslatorBase.load("qt_" + lang, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        app.installTranslator(&qtTranslatorBase);

    // Load e.g. qt_de_DE.qm
    if (qtTranslator.load("qt_" + lang_territory, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        app.installTranslator(&qtTranslator);

    // Load e.g. bitcoin_de.qm (shortcut "de" needs to be defined in bitcoin.qrc)
    if (translatorBase.load(lang, ":/translations/"))
        app.installTranslator(&translatorBase);

    // Load e.g. bitcoin_de_DE.qm (shortcut "de_DE" needs to be defined in bitcoin.qrc)
    if (translator.load(lang_territory, ":/translations/"))
        app.installTranslator(&translator);

    // Subscribe to global signals from core
    uiInterface.ThreadSafeMessageBox.connect(ThreadSafeMessageBox);
    uiInterface.ThreadSafeAskFee.connect(ThreadSafeAskFee);
    uiInterface.InitMessage.connect(InitMessage);
=======
    /// 3. Application identification
    // must be set before OptionsModel is initialized or translations are loaded,
    // as it is used to locate QSettings
    QApplication::setOrganizationName(QAPP_ORG_NAME);
    QApplication::setOrganizationDomain(QAPP_ORG_DOMAIN);
    QApplication::setApplicationName(QAPP_APP_NAME_DEFAULT);

    /// 4. Initialization of translations, so that intro dialog is in user's language
    // Now that QSettings are accessible, initialize translations
    QTranslator qtTranslatorBase, qtTranslator, translatorBase, translator;
    initTranslations(qtTranslatorBase, qtTranslator, translatorBase, translator);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    uiInterface.Translate.connect(Translate);

    // Show help message immediately after parsing command-line options (for "-lang") and setting locale,
    // but before showing splash screen.
    if (mapArgs.count("-?") || mapArgs.count("--help"))
    {
<<<<<<< HEAD
        GUIUtil::HelpMessageBox help;
=======
        HelpMessageDialog help(NULL);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        help.showOrPrint();
        return 1;
    }

<<<<<<< HEAD
#ifdef Q_OS_MAC
    // on mac, also change the icon now because it would look strange to have a testnet splash (green) and a std app icon (orange)
    if(GetBoolArg("-testnet")) {
        MacDockIconHandler::instance()->setIcon(QIcon(":icons/bitcoin_testnet"));
    }
#endif

    SplashScreen splash(QPixmap(), 0);
    if (GetBoolArg("-splash", true) && !GetBoolArg("-min"))
    {
#if MAC_OSX
        // QSplashScreen on Mac seems to always stay on top. Ugh.
        splash.setWindowFlags(Qt::FramelessWindowHint);
#endif
        splash.show();
        splash.setAutoFillBackground(true);
        splashref = &splash;
    }

    app.processEvents();
    app.setQuitOnLastWindowClosed(false);

    try
    {
#ifndef Q_OS_MAC
        // Regenerate startup link, to fix links to old versions
        // OSX: makes no sense on mac and might also scan/mount external (and sleeping) volumes (can take up some secs)
        if (GUIUtil::GetStartOnSystemStartup())
            GUIUtil::SetStartOnSystemStartup(true);
#endif

        boost::thread_group threadGroup;

        BitcoinGUI window;
        guiref = &window;

        QTimer* pollShutdownTimer = new QTimer(guiref);
        QObject::connect(pollShutdownTimer, SIGNAL(timeout()), guiref, SLOT(detectShutdown()));
        pollShutdownTimer->start(200);

        if(AppInit2(threadGroup))
        {
            {
                // Put this in a block, so that the Model objects are cleaned up before
                // calling Shutdown().

                optionsModel.Upgrade(); // Must be done after AppInit2

                if (splashref)
                    splash.finish(&window);

                ClientModel clientModel(&optionsModel);
                WalletModel *walletModel = 0;
                if(pwalletMain)
                    walletModel = new WalletModel(pwalletMain, &optionsModel);

                window.setClientModel(&clientModel);
                if(walletModel)
                {
                    window.addWallet("~Default", walletModel);
                    window.setCurrentWallet("~Default");
                }

                // If -min option passed, start window minimized.
                if(GetBoolArg("-min"))
                {
                    window.showMinimized();
                }
                else
                {
                    window.show();
                }

                // Now that initialization/startup is done, process any command-line
                // bitcoin: URIs
                QObject::connect(paymentServer, SIGNAL(receivedURI(QString)), &window, SLOT(handleURI(QString)));
                QTimer::singleShot(100, paymentServer, SLOT(uiReady()));

                app.exec();

                window.hide();
                window.setClientModel(0);
                window.removeAllWallets();
                guiref = 0;
                delete walletModel;
            }
            // Shutdown the core and its threads, but don't exit Bitcoin-Qt here
            threadGroup.interrupt_all();
            threadGroup.join_all();
            Shutdown();
        }
        else
        {
            threadGroup.interrupt_all();
            threadGroup.join_all();
            Shutdown();
            return 1;
        }
    } catch (std::exception& e) {
        handleRunawayException(&e);
    } catch (...) {
        handleRunawayException(NULL);
    }
    return 0;
=======
    /// 5. Now that settings and translations are available, ask user for data directory
    // User language is set up: pick a data directory
    Intro::pickDataDirectory();

    /// 6. Determine availability of data directory and parse bitcoin.conf
    /// - Do not call GetDataDir(true) before this step finishes
    if (!boost::filesystem::is_directory(GetDataDir(false)))
    {
        QMessageBox::critical(0, QObject::tr("Dogecoin Core"),
                              QObject::tr("Error: Specified data directory \"%1\" does not exist.").arg(QString::fromStdString(mapArgs["-datadir"])));
        return 1;
    }
    ReadConfigFile(mapArgs, mapMultiArgs);

    /// 7. Determine network (and switch to network specific options)
    // - Do not call Params() before this step
    // - Do this after parsing the configuration file, as the network can be switched there
    // - QSettings() will use the new application name after this, resulting in network-specific settings
    // - Needs to be done before createOptionsModel

    // Check for -testnet or -regtest parameter (Params() calls are only valid after this clause)
    if (!SelectParamsFromCommandLine()) {
        QMessageBox::critical(0, QObject::tr("Dogecoin Core"), QObject::tr("Error: Invalid combination of -regtest and -testnet."));
        return 1;
    }
#ifdef ENABLE_WALLET
    // Parse URIs on command line -- this can affect Params()
    if (!PaymentServer::ipcParseCommandLine(argc, argv))
        exit(0);
#endif
    bool isaTestNet = Params().NetworkID() != CChainParams::MAIN;
    // Allow for separate UI settings for testnets
    if (isaTestNet)
        QApplication::setApplicationName(QAPP_APP_NAME_TESTNET);
    else
        QApplication::setApplicationName(QAPP_APP_NAME_DEFAULT);
    // Re-initialize translations after changing application name (language in network-specific settings can be different)
    initTranslations(qtTranslatorBase, qtTranslator, translatorBase, translator);

#ifdef ENABLE_WALLET
    /// 8. URI IPC sending
    // - Do this early as we don't want to bother initializing if we are just calling IPC
    // - Do this *after* setting up the data directory, as the data directory hash is used in the name
    // of the server.
    // - Do this after creating app and setting up translations, so errors are
    // translated properly.
    if (PaymentServer::ipcSendCommandLine())
        exit(0);

    // Start up the payment server early, too, so impatient users that click on
    // dogecoin: links repeatedly have their payment requests routed to this process:
    // app.createPaymentServer();
#endif

    /// 9. Main GUI initialization
    // Install global event filter that makes sure that long tooltips can be word-wrapped
    app.installEventFilter(new GUIUtil::ToolTipToRichTextFilter(TOOLTIP_WRAP_THRESHOLD, &app));
    // Install qDebug() message handler to route to debug.log
#if QT_VERSION < 0x050000
    qInstallMsgHandler(DebugMessageHandler);
#else
    qInstallMessageHandler(DebugMessageHandler);
#endif
    // Load GUI settings from QSettings
    app.createOptionsModel();

    // Subscribe to global signals from core
    uiInterface.InitMessage.connect(InitMessage);

    if (GetBoolArg("-splash", true) && !GetBoolArg("-min", false))
        app.createSplashScreen(isaTestNet);

    try
    {
        app.createWindow(isaTestNet);
        app.requestInitialize();
        app.exec();
        app.requestShutdown();
        app.exec();
    } catch (std::exception& e) {
        PrintExceptionContinue(&e, "Runaway exception");
        app.handleRunawayException(QString::fromStdString(strMiscWarning));
    } catch (...) {
        PrintExceptionContinue(NULL, "Runaway exception");
        app.handleRunawayException(QString::fromStdString(strMiscWarning));
    }
    return app.getReturnValue();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}
#endif // BITCOIN_QT_TEST
