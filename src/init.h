// Copyright (c) 2009-2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_INIT_H
#define BITCOIN_INIT_H

#include "wallet.h"
=======
// Copyright (c) 2009-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_INIT_H
#define BITCOIN_INIT_H

#include <string>

class CWallet;

namespace boost {
    class thread_group;
};
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

extern std::string strWalletFile;
extern CWallet* pwalletMain;

void StartShutdown();
bool ShutdownRequested();
void Shutdown();
bool AppInit2(boost::thread_group& threadGroup);
<<<<<<< HEAD
std::string HelpMessage();
=======

/* The help message mode determines what help message to show */
enum HelpMessageMode
{
    HMM_BITCOIND,
    HMM_BITCOIN_QT
};

std::string HelpMessage(HelpMessageMode mode);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

#endif
