// Copyright (c) 2009-2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
=======
// Copyright (c) 2009-2014 The Bitcoin developers
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "protocol.h"
<<<<<<< HEAD
#include "util.h"
#include "netbase.h"
#include "main.h"
=======

#include "util.h"
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

#ifndef WIN32
# include <arpa/inet.h>
#endif

static const char* ppszTypeName[] =
{
    "ERROR",
    "tx",
    "block",
    "filtered block"
};

CMessageHeader::CMessageHeader()
{
<<<<<<< HEAD
    memcpy(pchMessageStart, ::pchMessageStart, sizeof(pchMessageStart));
=======
    memcpy(pchMessageStart, Params().MessageStart(), MESSAGE_START_SIZE);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    memset(pchCommand, 0, sizeof(pchCommand));
    pchCommand[1] = 1;
    nMessageSize = -1;
    nChecksum = 0;
}

CMessageHeader::CMessageHeader(const char* pszCommand, unsigned int nMessageSizeIn)
{
<<<<<<< HEAD
    memcpy(pchMessageStart, ::pchMessageStart, sizeof(pchMessageStart));
=======
    memcpy(pchMessageStart, Params().MessageStart(), MESSAGE_START_SIZE);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    strncpy(pchCommand, pszCommand, COMMAND_SIZE);
    nMessageSize = nMessageSizeIn;
    nChecksum = 0;
}

std::string CMessageHeader::GetCommand() const
{
    if (pchCommand[COMMAND_SIZE-1] == 0)
        return std::string(pchCommand, pchCommand + strlen(pchCommand));
    else
        return std::string(pchCommand, pchCommand + COMMAND_SIZE);
}

bool CMessageHeader::IsValid() const
{
    // Check start string
<<<<<<< HEAD
    if (memcmp(pchMessageStart, ::pchMessageStart, sizeof(pchMessageStart)) != 0)
=======
    if (memcmp(pchMessageStart, Params().MessageStart(), MESSAGE_START_SIZE) != 0)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        return false;

    // Check the command string for errors
    for (const char* p1 = pchCommand; p1 < pchCommand + COMMAND_SIZE; p1++)
    {
        if (*p1 == 0)
        {
            // Must be all zeros after the first zero
            for (; p1 < pchCommand + COMMAND_SIZE; p1++)
                if (*p1 != 0)
                    return false;
        }
        else if (*p1 < ' ' || *p1 > 0x7E)
            return false;
    }

    // Message size
    if (nMessageSize > MAX_SIZE)
    {
<<<<<<< HEAD
        printf("CMessageHeader::IsValid() : (%s, %u bytes) nMessageSize > MAX_SIZE\n", GetCommand().c_str(), nMessageSize);
=======
        LogPrintf("CMessageHeader::IsValid() : (%s, %u bytes) nMessageSize > MAX_SIZE\n", GetCommand(), nMessageSize);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        return false;
    }

    return true;
}



CAddress::CAddress() : CService()
{
    Init();
}

<<<<<<< HEAD
CAddress::CAddress(CService ipIn, uint64 nServicesIn) : CService(ipIn)
=======
CAddress::CAddress(CService ipIn, uint64_t nServicesIn) : CService(ipIn)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    Init();
    nServices = nServicesIn;
}

void CAddress::Init()
{
    nServices = NODE_NETWORK;
    nTime = 100000000;
    nLastTry = 0;
}

CInv::CInv()
{
    type = 0;
    hash = 0;
}

CInv::CInv(int typeIn, const uint256& hashIn)
{
    type = typeIn;
    hash = hashIn;
}

CInv::CInv(const std::string& strType, const uint256& hashIn)
{
    unsigned int i;
    for (i = 1; i < ARRAYLEN(ppszTypeName); i++)
    {
        if (strType == ppszTypeName[i])
        {
            type = i;
            break;
        }
    }
    if (i == ARRAYLEN(ppszTypeName))
<<<<<<< HEAD
        throw std::out_of_range(strprintf("CInv::CInv(string, uint256) : unknown type '%s'", strType.c_str()));
=======
        throw std::out_of_range(strprintf("CInv::CInv(string, uint256) : unknown type '%s'", strType));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    hash = hashIn;
}

bool operator<(const CInv& a, const CInv& b)
{
    return (a.type < b.type || (a.type == b.type && a.hash < b.hash));
}

bool CInv::IsKnownType() const
{
    return (type >= 1 && type < (int)ARRAYLEN(ppszTypeName));
}

const char* CInv::GetCommand() const
{
    if (!IsKnownType())
        throw std::out_of_range(strprintf("CInv::GetCommand() : type=%d unknown type", type));
    return ppszTypeName[type];
}

std::string CInv::ToString() const
{
<<<<<<< HEAD
    return strprintf("%s %s", GetCommand(), hash.ToString().c_str());
=======
    return strprintf("%s %s", GetCommand(), hash.ToString());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

void CInv::print() const
{
<<<<<<< HEAD
    printf("CInv(%s)\n", ToString().c_str());
=======
    LogPrintf("CInv(%s)\n", ToString());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

