<<<<<<< HEAD
=======
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>

/** class for the splashscreen with information of the running client
 */
class SplashScreen : public QSplashScreen
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit SplashScreen(const QPixmap &pixmap = QPixmap(), Qt::WindowFlags f = 0);
=======
    explicit SplashScreen(const QPixmap &pixmap, Qt::WindowFlags f, bool isTestNet);
    ~SplashScreen();

public slots:
    /** Slot to call finish() method as it's not defined as slot */
    void slotFinish(QWidget *mainWin);

private:
    /** Connect core signals to splash screen */
    void subscribeToCoreSignals();
    /** Disconnect core signals to splash screen */
    void unsubscribeFromCoreSignals();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
};

#endif // SPLASHSCREEN_H
