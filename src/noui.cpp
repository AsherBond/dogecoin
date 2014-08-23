// Copyright (c) 2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ui_interface.h"
#include "init.h"
#include "bitcoinrpc.h"

=======
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "noui.h"

#include "ui_interface.h"
#include "util.h"

#include <stdint.h>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#include <string>

static bool noui_ThreadSafeMessageBox(const std::string& message, const std::string& caption, unsigned int style)
{
    std::string strCaption;
    // Check for usage of predefined caption
    switch (style) {
    case CClientUIInterface::MSG_ERROR:
        strCaption += _("Error");
        break;
    case CClientUIInterface::MSG_WARNING:
        strCaption += _("Warning");
        break;
    case CClientUIInterface::MSG_INFORMATION:
        strCaption += _("Information");
        break;
    default:
        strCaption += caption; // Use supplied caption (can be empty)
    }

<<<<<<< HEAD
    printf("%s: %s\n", strCaption.c_str(), message.c_str());
=======
    LogPrintf("%s: %s\n", strCaption, message);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    fprintf(stderr, "%s: %s\n", strCaption.c_str(), message.c_str());
    return false;
}

<<<<<<< HEAD
static bool noui_ThreadSafeAskFee(int64 /*nFeeRequired*/)
{
    return true;
}

static void noui_InitMessage(const std::string &message)
{
    printf("init message: %s\n", message.c_str());
=======
static void noui_InitMessage(const std::string &message)
{
    LogPrintf("init message: %s\n", message);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

void noui_connect()
{
    // Connect bitcoind signal handlers
    uiInterface.ThreadSafeMessageBox.connect(noui_ThreadSafeMessageBox);
<<<<<<< HEAD
    uiInterface.ThreadSafeAskFee.connect(noui_ThreadSafeAskFee);
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    uiInterface.InitMessage.connect(noui_InitMessage);
}
