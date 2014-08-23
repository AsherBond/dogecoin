// Copyright (c) 2009-2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
=======
// Copyright (c) 2009-2013 The Bitcoin developers
// Copyright (c) 2011-2013 The Litecoin developers
// Copyright (c) 2013-2014 The Dogecoin developers
// Copyright (c)      2014 The Inutoshi developers
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef __cplusplus
# error This header can only be compiled as C++.
#endif

#ifndef __INCLUDED_PROTOCOL_H__
#define __INCLUDED_PROTOCOL_H__

<<<<<<< HEAD
#include "serialize.h"
#include "netbase.h"
#include <string>
#include "uint256.h"

extern bool fTestNet;
static inline unsigned short GetDefaultPort(const bool testnet = fTestNet)
{
    return testnet ? 44556 : 22556;
}


extern unsigned char pchMessageStart[4];
=======
#include "chainparams.h"
#include "netbase.h"
#include "serialize.h"
#include "uint256.h"

#include <stdint.h>
#include <string>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

/** Message header.
 * (4) message start.
 * (12) command.
 * (4) size.
 * (4) checksum.
 */
class CMessageHeader
{
    public:
        CMessageHeader();
        CMessageHeader(const char* pszCommand, unsigned int nMessageSizeIn);

        std::string GetCommand() const;
        bool IsValid() const;

        IMPLEMENT_SERIALIZE
            (
             READWRITE(FLATDATA(pchMessageStart));
             READWRITE(FLATDATA(pchCommand));
             READWRITE(nMessageSize);
             READWRITE(nChecksum);
            )

    // TODO: make private (improves encapsulation)
    public:
        enum {
<<<<<<< HEAD
            MESSAGE_START_SIZE=sizeof(::pchMessageStart),
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            COMMAND_SIZE=12,
            MESSAGE_SIZE_SIZE=sizeof(int),
            CHECKSUM_SIZE=sizeof(int),

            MESSAGE_SIZE_OFFSET=MESSAGE_START_SIZE+COMMAND_SIZE,
            CHECKSUM_OFFSET=MESSAGE_SIZE_OFFSET+MESSAGE_SIZE_SIZE,
            HEADER_SIZE=MESSAGE_START_SIZE+COMMAND_SIZE+MESSAGE_SIZE_SIZE+CHECKSUM_SIZE
        };
        char pchMessageStart[MESSAGE_START_SIZE];
        char pchCommand[COMMAND_SIZE];
        unsigned int nMessageSize;
        unsigned int nChecksum;
};

/** nServices flags */
enum
{
    NODE_NETWORK = (1 << 0),
    NODE_BLOOM = (1 << 1),
};

/** A CService with information about it as peer */
class CAddress : public CService
{
    public:
        CAddress();
<<<<<<< HEAD
        explicit CAddress(CService ipIn, uint64 nServicesIn=NODE_NETWORK);
=======
        explicit CAddress(CService ipIn, uint64_t nServicesIn=NODE_NETWORK);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

        void Init();

        IMPLEMENT_SERIALIZE
            (
             CAddress* pthis = const_cast<CAddress*>(this);
             CService* pip = (CService*)pthis;
             if (fRead)
                 pthis->Init();
             if (nType & SER_DISK)
                 READWRITE(nVersion);
             if ((nType & SER_DISK) ||
                 (nVersion >= CADDR_TIME_VERSION && !(nType & SER_GETHASH)))
                 READWRITE(nTime);
             READWRITE(nServices);
             READWRITE(*pip);
            )

        void print() const;

    // TODO: make private (improves encapsulation)
    public:
<<<<<<< HEAD
        uint64 nServices;
=======
        uint64_t nServices;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

        // disk and network only
        unsigned int nTime;

        // memory only
<<<<<<< HEAD
        int64 nLastTry;
=======
        int64_t nLastTry;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
};

/** inv message data */
class CInv
{
    public:
        CInv();
        CInv(int typeIn, const uint256& hashIn);
        CInv(const std::string& strType, const uint256& hashIn);

        IMPLEMENT_SERIALIZE
        (
            READWRITE(type);
            READWRITE(hash);
        )

        friend bool operator<(const CInv& a, const CInv& b);

        bool IsKnownType() const;
        const char* GetCommand() const;
        std::string ToString() const;
        void print() const;

    // TODO: make private (improves encapsulation)
    public:
        int type;
        uint256 hash;
};

enum
{
    MSG_TX = 1,
    MSG_BLOCK,
    // Nodes may always request a MSG_FILTERED_BLOCK in a getdata, however,
    // MSG_FILTERED_BLOCK should not appear in any invs except as a part of getdata.
    MSG_FILTERED_BLOCK,
};

#endif // __INCLUDED_PROTOCOL_H__
