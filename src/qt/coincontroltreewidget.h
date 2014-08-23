<<<<<<< HEAD
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef COINCONTROLTREEWIDGET_H
#define COINCONTROLTREEWIDGET_H

#include <QKeyEvent>
#include <QTreeWidget>

<<<<<<< HEAD
class CoinControlTreeWidget : public QTreeWidget {
Q_OBJECT

public:
    explicit CoinControlTreeWidget(QWidget *parent = 0);
    
protected:
  virtual void  keyPressEvent(QKeyEvent *event);
=======
class CoinControlTreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit CoinControlTreeWidget(QWidget *parent = 0);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
};

#endif // COINCONTROLTREEWIDGET_H