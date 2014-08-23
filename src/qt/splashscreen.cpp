<<<<<<< HEAD
#include "splashscreen.h"
#include "clientversion.h"
#include "util.h"

#include <QPainter>
#undef loop /* ugh, remove this when the #define loop is gone from util.h */
#include <QApplication>

SplashScreen::SplashScreen(const QPixmap &pixmap, Qt::WindowFlags f) :
    QSplashScreen(pixmap, f)
{
    // set reference point, paddings
    int paddingLeftCol2         = 230;
    int paddingTopCol2          = 376;
    int line1 = 0;
    int line2 = 13;
    int line3 = 26;
=======
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "splashscreen.h"

#include "clientversion.h"
#include "ui_interface.h"
#include "util.h"

#include <QApplication>
#include <QPainter>
#include <QRectF>

SplashScreen::SplashScreen(const QPixmap &pixmap, Qt::WindowFlags f, bool isTestNet) :
    QSplashScreen(pixmap, f)
{
    setAutoFillBackground(true);

    // set reference point, paddings
    int paddingRight            = 50;
    int paddingTop              = 50;
    int titleVersionVSpace      = 17;
    int titleCopyrightVSpace    = 40;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    float fontFactor            = 1.0;

    // define text to place
<<<<<<< HEAD
    QString titleText       = QString(QApplication::applicationName()).replace(QString("-testnet"), QString(""), Qt::CaseSensitive); // cut of testnet, place it as single object further down
    QString versionText     = QString("Version %1 ").arg(QString::fromStdString(FormatFullVersion()));
    QString copyrightText1   = QChar(0xA9)+QString(" 2009-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The Bitcoin developers"));
    QString copyrightText2   = QChar(0xA9)+QString(" 2011-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The Litecoin developers"));

    QString font            = "Arial";

    // load the bitmap for writing some text over it
    QPixmap newPixmap;
    if(GetBoolArg("-testnet")) {
=======
    QString titleText       = tr("Dogecoin Core");
    QString versionText     = QString("Version %1").arg(QString::fromStdString(FormatFullVersion()));
    QString copyrightText   = QChar(0xA9)+QString(" 2009-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The Bitcoin Core developers\n")) + QChar(0xA9)+QString(" 2013-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The Dogecoin Core developers"));
    QString testnetAddText  = QString(tr("[testnet]")); // define text to place as single text object

    QString font            = "Comic Sans MS";

    // load the bitmap for writing some text over it
    QPixmap newPixmap;
    if(isTestNet) {
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        newPixmap     = QPixmap(":/images/splash_testnet");
    }
    else {
        newPixmap     = QPixmap(":/images/splash");
    }

    QPainter pixPaint(&newPixmap);
<<<<<<< HEAD
    pixPaint.setPen(QColor(70,70,70));

    pixPaint.setFont(QFont(font, 9*fontFactor));
    pixPaint.drawText(paddingLeftCol2,paddingTopCol2+line3,versionText);

    // draw copyright stuff
    pixPaint.setFont(QFont(font, 9*fontFactor));
    pixPaint.drawText(paddingLeftCol2,paddingTopCol2+line1,copyrightText1);
    pixPaint.drawText(paddingLeftCol2,paddingTopCol2+line2,copyrightText2);
=======
    pixPaint.setPen(QColor(100,100,100));

    // check font size and drawing with
    pixPaint.setFont(QFont(font, 33*fontFactor));
    QFontMetrics fm = pixPaint.fontMetrics();
    int titleTextWidth  = fm.width(titleText);
    if(titleTextWidth > 160) {
        // strange font rendering, Arial probably not found
        fontFactor = 0.75;
    }

    pixPaint.setFont(QFont(font, 33*fontFactor));
    fm = pixPaint.fontMetrics();
    titleTextWidth  = fm.width(titleText);
    pixPaint.drawText(newPixmap.width()-titleTextWidth-paddingRight,paddingTop,titleText);

    pixPaint.setFont(QFont(font, 15*fontFactor));

    // if the version string is to long, reduce size
    fm = pixPaint.fontMetrics();
    int versionTextWidth  = fm.width(versionText);
    if(versionTextWidth > titleTextWidth+paddingRight-10) {
        pixPaint.setFont(QFont(font, 10*fontFactor));
        titleVersionVSpace -= 5;
    }
    pixPaint.drawText(newPixmap.width()-titleTextWidth-paddingRight+2,paddingTop+titleVersionVSpace,versionText);

    // draw copyright stuff
    pixPaint.setFont(QFont(font, 10*fontFactor));
    QRect copyrightRect = QRect(newPixmap.width()-titleTextWidth-paddingRight,paddingTop+titleCopyrightVSpace,fm.width(copyrightText),fm.height()*2);
    pixPaint.drawText(copyrightRect,Qt::TextWordWrap,copyrightText);

    // draw testnet string if testnet is on
    if(isTestNet) {
        QFont boldFont = QFont(font, 10*fontFactor);
        boldFont.setWeight(QFont::Bold);
        pixPaint.setFont(boldFont);
        fm = pixPaint.fontMetrics();
        int testnetAddTextWidth  = fm.width(testnetAddText);
        pixPaint.drawText(newPixmap.width()-testnetAddTextWidth-10,15,testnetAddText);
    }
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    pixPaint.end();

    this->setPixmap(newPixmap);
<<<<<<< HEAD
=======

    subscribeToCoreSignals();
}

SplashScreen::~SplashScreen()
{
    unsubscribeFromCoreSignals();
}

void SplashScreen::slotFinish(QWidget *mainWin)
{
    finish(mainWin);
}

static void InitMessage(SplashScreen *splash, const std::string &message)
{
    QMetaObject::invokeMethod(splash, "showMessage",
        Qt::QueuedConnection,
        Q_ARG(QString, QString::fromStdString(message)),
        Q_ARG(int, Qt::AlignBottom|Qt::AlignHCenter),
        Q_ARG(QColor, QColor(55,55,55)));
}

void SplashScreen::subscribeToCoreSignals()
{
    // Connect signals to client
    uiInterface.InitMessage.connect(boost::bind(InitMessage, this, _1));
}

void SplashScreen::unsubscribeFromCoreSignals()
{
    // Disconnect signals from client
    uiInterface.InitMessage.disconnect(boost::bind(InitMessage, this, _1));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}
