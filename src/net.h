// Copyright (c) 2009-2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_NET_H
#define BITCOIN_NET_H

#include <deque>
#include <boost/array.hpp>
#include <boost/foreach.hpp>
#include <openssl/rand.h>
=======
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_NET_H
#define BITCOIN_NET_H

#include "bloom.h"
#include "compat.h"
#include "hash.h"
#include "limitedmap.h"
#include "mruset.h"
#include "netbase.h"
#include "protocol.h"
#include "sync.h"
#include "uint256.h"
#include "util.h"

#include <deque>
#include <stdint.h>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

#ifndef WIN32
#include <arpa/inet.h>
#endif

<<<<<<< HEAD
#include "mruset.h"
#include "limitedmap.h"
#include "netbase.h"
#include "protocol.h"
#include "addrman.h"
#include "hash.h"
#include "bloom.h"

class CNode;
class CBlockIndex;
extern int nBestHeight;


=======
#include <boost/foreach.hpp>
#include <boost/signals2/signal.hpp>
#include <openssl/rand.h>

class CAddrMan;
class CBlockIndex;
class CNode;

namespace boost {
    class thread_group;
}

/** The maximum number of entries in an 'inv' protocol message */
static const unsigned int MAX_INV_SZ = 50000;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

inline unsigned int ReceiveFloodSize() { return 1000*GetArg("-maxreceivebuffer", 5*1000); }
inline unsigned int SendBufferSize() { return 1000*GetArg("-maxsendbuffer", 1*1000); }

void AddOneShot(std::string strDest);
bool RecvLine(SOCKET hSocket, std::string& strLine);
bool GetMyExternalIP(CNetAddr& ipRet);
void AddressCurrentlyConnected(const CService& addr);
CNode* FindNode(const CNetAddr& ip);
CNode* FindNode(const CService& ip);
CNode* ConnectNode(CAddress addrConnect, const char *strDest = NULL);
void MapPort(bool fUseUPnP);
unsigned short GetListenPort();
bool BindListenPort(const CService &bindAddr, std::string& strError=REF(std::string()));
void StartNode(boost::thread_group& threadGroup);
bool StopNode();
void SocketSendData(CNode *pnode);

<<<<<<< HEAD
=======
typedef int NodeId;

// Signals for message handling
struct CNodeSignals
{
    boost::signals2::signal<int ()> GetHeight;
    boost::signals2::signal<bool (CNode*)> ProcessMessages;
    boost::signals2::signal<bool (CNode*, bool)> SendMessages;
    boost::signals2::signal<void (NodeId, const CNode*)> InitializeNode;
    boost::signals2::signal<void (NodeId)> FinalizeNode;
};


CNodeSignals& GetNodeSignals();


>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
enum
{
    LOCAL_NONE,   // unknown
    LOCAL_IF,     // address a local interface listens on
    LOCAL_BIND,   // address explicit bound to
    LOCAL_UPNP,   // address reported by UPnP
    LOCAL_HTTP,   // address reported by whatismyip.com and similar
    LOCAL_MANUAL, // address explicitly specified (-externalip=)

    LOCAL_MAX
};

void SetLimited(enum Network net, bool fLimited = true);
bool IsLimited(enum Network net);
bool IsLimited(const CNetAddr& addr);
bool AddLocal(const CService& addr, int nScore = LOCAL_NONE);
bool AddLocal(const CNetAddr& addr, int nScore = LOCAL_NONE);
bool SeenLocal(const CService& addr);
bool IsLocal(const CService& addr);
bool GetLocal(CService &addr, const CNetAddr *paddrPeer = NULL);
bool IsReachable(const CNetAddr &addr);
void SetReachable(enum Network net, bool fFlag = true);
CAddress GetLocalAddress(const CNetAddr *paddrPeer = NULL);


extern bool fDiscover;
<<<<<<< HEAD
extern uint64 nLocalServices;
extern uint64 nLocalHostNonce;
=======
extern uint64_t nLocalServices;
extern uint64_t nLocalHostNonce;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
extern CAddrMan addrman;
extern int nMaxConnections;

extern std::vector<CNode*> vNodes;
extern CCriticalSection cs_vNodes;
extern std::map<CInv, CDataStream> mapRelay;
<<<<<<< HEAD
extern std::deque<std::pair<int64, CInv> > vRelayExpiration;
extern CCriticalSection cs_mapRelay;
extern limitedmap<CInv, int64> mapAlreadyAskedFor;
=======
extern std::deque<std::pair<int64_t, CInv> > vRelayExpiration;
extern CCriticalSection cs_mapRelay;
extern limitedmap<CInv, int64_t> mapAlreadyAskedFor;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

extern std::vector<std::string> vAddedNodes;
extern CCriticalSection cs_vAddedNodes;

<<<<<<< HEAD

=======
extern NodeId nLastNodeId;
extern CCriticalSection cs_nLastNodeId;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917


class CNodeStats
{
public:
<<<<<<< HEAD
    uint64 nServices;
    int64 nLastSend;
    int64 nLastRecv;
    int64 nTimeConnected;
=======
    NodeId nodeid;
    uint64_t nServices;
    int64_t nLastSend;
    int64_t nLastRecv;
    int64_t nTimeConnected;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    std::string addrName;
    int nVersion;
    std::string cleanSubVer;
    bool fInbound;
    int nStartingHeight;
<<<<<<< HEAD
    int nMisbehavior;
    uint64 nSendBytes;
    uint64 nRecvBytes;
    uint64 nBlocksRequested;
    bool fSyncNode;
=======
    uint64_t nSendBytes;
    uint64_t nRecvBytes;
    bool fSyncNode;
    double dPingTime;
    double dPingWait;
    std::string addrLocal;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
};




class CNetMessage {
public:
    bool in_data;                   // parsing header (false) or data (true)

    CDataStream hdrbuf;             // partially received header
    CMessageHeader hdr;             // complete header
    unsigned int nHdrPos;

    CDataStream vRecv;              // received message data
    unsigned int nDataPos;

    CNetMessage(int nTypeIn, int nVersionIn) : hdrbuf(nTypeIn, nVersionIn), vRecv(nTypeIn, nVersionIn) {
        hdrbuf.resize(24);
        in_data = false;
        nHdrPos = 0;
        nDataPos = 0;
    }

    bool complete() const
    {
        if (!in_data)
            return false;
        return (hdr.nMessageSize == nDataPos);
    }

    void SetVersion(int nVersionIn)
    {
        hdrbuf.SetVersion(nVersionIn);
        vRecv.SetVersion(nVersionIn);
    }

    int readHeader(const char *pch, unsigned int nBytes);
    int readData(const char *pch, unsigned int nBytes);
};





/** Information about a peer */
class CNode
{
public:
    // socket
<<<<<<< HEAD
    uint64 nServices;
=======
    uint64_t nServices;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    SOCKET hSocket;
    CDataStream ssSend;
    size_t nSendSize; // total size of all vSendMsg entries
    size_t nSendOffset; // offset inside the first vSendMsg already sent
<<<<<<< HEAD
    uint64 nSendBytes;
=======
    uint64_t nSendBytes;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    std::deque<CSerializeData> vSendMsg;
    CCriticalSection cs_vSend;

    std::deque<CInv> vRecvGetData;
    std::deque<CNetMessage> vRecvMsg;
    CCriticalSection cs_vRecvMsg;
<<<<<<< HEAD
    uint64 nRecvBytes;
    int nRecvVersion;

    int64 nLastSend;
    int64 nLastRecv;
    int64 nLastSendEmpty;
    int64 nTimeConnected;
    uint64 nBlocksRequested;
=======
    uint64_t nRecvBytes;
    int nRecvVersion;

    int64_t nLastSend;
    int64_t nLastRecv;
    int64_t nLastSendEmpty;
    int64_t nTimeConnected;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    CAddress addr;
    std::string addrName;
    CService addrLocal;
    int nVersion;
<<<<<<< HEAD
    // strSubVer is whatever byte array we read from the wire. However, this field is intended 
=======
    // strSubVer is whatever byte array we read from the wire. However, this field is intended
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // to be printed out, displayed to humans in various forms and so on. So we sanitize it and
    // store the sanitized version in cleanSubVer. The original should be used when dealing with
    // the network or wire types and the cleaned string used when displayed or logged.
    std::string strSubVer, cleanSubVer;
    bool fOneShot;
    bool fClient;
    bool fInbound;
    bool fNetworkNode;
    bool fSuccessfullyConnected;
    bool fDisconnect;
    // We use fRelayTxes for two purposes -
    // a) it allows us to not relay tx invs before receiving the peer's version message
    // b) the peer may tell us in their version message that we should not relay tx invs
    //    until they have initialized their bloom filter.
    bool fRelayTxes;
    CSemaphoreGrant grantOutbound;
    CCriticalSection cs_filter;
    CBloomFilter* pfilter;
    int nRefCount;
<<<<<<< HEAD
=======
    NodeId id;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
protected:

    // Denial-of-service detection/prevention
    // Key is IP address, value is banned-until-time
<<<<<<< HEAD
    static std::map<CNetAddr, int64> setBanned;
    static CCriticalSection cs_setBanned;
    int nMisbehavior;
=======
    static std::map<CNetAddr, int64_t> setBanned;
    static CCriticalSection cs_setBanned;

    // Basic fuzz-testing
    void Fuzz(int nChance); // modifies ssSend
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

public:
    uint256 hashContinue;
    CBlockIndex* pindexLastGetBlocksBegin;
    uint256 hashLastGetBlocksEnd;
    int nStartingHeight;
    bool fStartSync;

    // flood relay
    std::vector<CAddress> vAddrToSend;
    std::set<CAddress> setAddrKnown;
    bool fGetAddr;
    std::set<uint256> setKnown;

    // inventory based relay
    mruset<CInv> setInventoryKnown;
    std::vector<CInv> vInventoryToSend;
    CCriticalSection cs_inventory;
<<<<<<< HEAD
    std::multimap<int64, CInv> mapAskFor;
=======
    std::multimap<int64_t, CInv> mapAskFor;

    // Ping time measurement
    uint64_t nPingNonceSent;
    int64_t nPingUsecStart;
    int64_t nPingUsecTime;
    bool fPingQueued;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    CNode(SOCKET hSocketIn, CAddress addrIn, std::string addrNameIn = "", bool fInboundIn=false) : ssSend(SER_NETWORK, INIT_PROTO_VERSION)
    {
        nServices = 0;
        hSocket = hSocketIn;
        nRecvVersion = INIT_PROTO_VERSION;
        nLastSend = 0;
        nLastRecv = 0;
        nSendBytes = 0;
        nRecvBytes = 0;
        nLastSendEmpty = GetTime();
        nTimeConnected = GetTime();
<<<<<<< HEAD
        nBlocksRequested = 0;
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        addr = addrIn;
        addrName = addrNameIn == "" ? addr.ToStringIPPort() : addrNameIn;
        nVersion = 0;
        strSubVer = "";
        fOneShot = false;
        fClient = false; // set by version message
        fInbound = fInboundIn;
        fNetworkNode = false;
        fSuccessfullyConnected = false;
        fDisconnect = false;
        nRefCount = 0;
        nSendSize = 0;
        nSendOffset = 0;
        hashContinue = 0;
        pindexLastGetBlocksBegin = 0;
        hashLastGetBlocksEnd = 0;
        nStartingHeight = -1;
        fStartSync = false;
        fGetAddr = false;
<<<<<<< HEAD
        nMisbehavior = 0;
        fRelayTxes = false;
        setInventoryKnown.max_size(SendBufferSize() / 1000);
        pfilter = new CBloomFilter();
=======
        fRelayTxes = false;
        setInventoryKnown.max_size(SendBufferSize() / 1000);
        pfilter = new CBloomFilter();
        nPingNonceSent = 0;
        nPingUsecStart = 0;
        nPingUsecTime = 0;
        fPingQueued = false;

        {
            LOCK(cs_nLastNodeId);
            id = nLastNodeId++;
        }
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

        // Be shy and don't send version until we hear
        if (hSocket != INVALID_SOCKET && !fInbound)
            PushVersion();
<<<<<<< HEAD
=======

        GetNodeSignals().InitializeNode(GetId(), this);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }

    ~CNode()
    {
        if (hSocket != INVALID_SOCKET)
        {
            closesocket(hSocket);
            hSocket = INVALID_SOCKET;
        }
        if (pfilter)
            delete pfilter;
<<<<<<< HEAD
    }

private:
    CNode(const CNode&);
    void operator=(const CNode&);
public:

=======
        GetNodeSignals().FinalizeNode(GetId());
    }

private:
    // Network usage totals
    static CCriticalSection cs_totalBytesRecv;
    static CCriticalSection cs_totalBytesSent;
    static uint64_t nTotalBytesRecv;
    static uint64_t nTotalBytesSent;

    CNode(const CNode&);
    void operator=(const CNode&);

public:

    NodeId GetId() const {
      return id;
    }
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    int GetRefCount()
    {
        assert(nRefCount >= 0);
        return nRefCount;
    }

    // requires LOCK(cs_vRecvMsg)
    unsigned int GetTotalRecvSize()
    {
        unsigned int total = 0;
<<<<<<< HEAD
        BOOST_FOREACH(const CNetMessage &msg, vRecvMsg) 
=======
        BOOST_FOREACH(const CNetMessage &msg, vRecvMsg)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            total += msg.vRecv.size() + 24;
        return total;
    }

    // requires LOCK(cs_vRecvMsg)
    bool ReceiveMsgBytes(const char *pch, unsigned int nBytes);

    // requires LOCK(cs_vRecvMsg)
    void SetRecvVersion(int nVersionIn)
    {
        nRecvVersion = nVersionIn;
        BOOST_FOREACH(CNetMessage &msg, vRecvMsg)
            msg.SetVersion(nVersionIn);
    }

    CNode* AddRef()
    {
        nRefCount++;
        return this;
    }

    void Release()
    {
        nRefCount--;
    }



    void AddAddressKnown(const CAddress& addr)
    {
        setAddrKnown.insert(addr);
    }

    void PushAddress(const CAddress& addr)
    {
        // Known checking here is only to save space from duplicates.
        // SendMessages will filter it again for knowns that were added
        // after addresses were pushed.
        if (addr.IsValid() && !setAddrKnown.count(addr))
            vAddrToSend.push_back(addr);
    }


    void AddInventoryKnown(const CInv& inv)
    {
        {
            LOCK(cs_inventory);
            setInventoryKnown.insert(inv);
        }
    }

    void PushInventory(const CInv& inv)
    {
        {
            LOCK(cs_inventory);
            if (!setInventoryKnown.count(inv))
                vInventoryToSend.push_back(inv);
        }
    }

    void AskFor(const CInv& inv)
    {
        // We're using mapAskFor as a priority queue,
        // the key is the earliest time the request can be sent
<<<<<<< HEAD
        int64 nRequestTime;
        limitedmap<CInv, int64>::const_iterator it = mapAlreadyAskedFor.find(inv);
=======
        int64_t nRequestTime;
        limitedmap<CInv, int64_t>::const_iterator it = mapAlreadyAskedFor.find(inv);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        if (it != mapAlreadyAskedFor.end())
            nRequestTime = it->second;
        else
            nRequestTime = 0;
<<<<<<< HEAD
        if (fDebugNet)
            printf("askfor %s   %"PRI64d" (%s)\n", inv.ToString().c_str(), nRequestTime, DateTimeStrFormat("%H:%M:%S", nRequestTime/1000000).c_str());

        // Make sure not to reuse time indexes to keep things in the same order
        int64 nNow = (GetTime() - 1) * 1000000;
        static int64 nLastTime;
=======
        LogPrint("net", "askfor %s   %d (%s)\n", inv.ToString().c_str(), nRequestTime, DateTimeStrFormat("%H:%M:%S", nRequestTime/1000000).c_str());

        // Make sure not to reuse time indexes to keep things in the same order
        int64_t nNow = (GetTime() - 1) * 1000000;
        static int64_t nLastTime;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        ++nLastTime;
        nNow = std::max(nNow, nLastTime);
        nLastTime = nNow;

        // Each retry is 2 minutes after the last
        nRequestTime = std::max(nRequestTime + 2 * 60 * 1000000, nNow);
        if (it != mapAlreadyAskedFor.end())
            mapAlreadyAskedFor.update(it, nRequestTime);
        else
            mapAlreadyAskedFor.insert(std::make_pair(inv, nRequestTime));
        mapAskFor.insert(std::make_pair(nRequestTime, inv));
    }



    // TODO: Document the postcondition of this function.  Is cs_vSend locked?
    void BeginMessage(const char* pszCommand) EXCLUSIVE_LOCK_FUNCTION(cs_vSend)
    {
        ENTER_CRITICAL_SECTION(cs_vSend);
        assert(ssSend.size() == 0);
        ssSend << CMessageHeader(pszCommand, 0);
<<<<<<< HEAD
        if (fDebug)
            printf("sending: %s ", pszCommand);
=======
        LogPrint("net", "sending: %s ", pszCommand);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }

    // TODO: Document the precondition of this function.  Is cs_vSend locked?
    void AbortMessage() UNLOCK_FUNCTION(cs_vSend)
    {
        ssSend.clear();

        LEAVE_CRITICAL_SECTION(cs_vSend);

<<<<<<< HEAD
        if (fDebug)
            printf("(aborted)\n");
=======
        LogPrint("net", "(aborted)\n");
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }

    // TODO: Document the precondition of this function.  Is cs_vSend locked?
    void EndMessage() UNLOCK_FUNCTION(cs_vSend)
    {
<<<<<<< HEAD
        if (mapArgs.count("-dropmessagestest") && GetRand(atoi(mapArgs["-dropmessagestest"])) == 0)
        {
            printf("dropmessages DROPPING SEND MESSAGE\n");
            AbortMessage();
            return;
        }
=======
        // The -*messagestest options are intentionally not documented in the help message,
        // since they are only used during development to debug the networking code and are
        // not intended for end-users.
        if (mapArgs.count("-dropmessagestest") && GetRand(GetArg("-dropmessagestest", 2)) == 0)
        {
            LogPrint("net", "dropmessages DROPPING SEND MESSAGE\n");
            AbortMessage();
            return;
        }
        if (mapArgs.count("-fuzzmessagestest"))
            Fuzz(GetArg("-fuzzmessagestest", 10));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

        if (ssSend.size() == 0)
            return;

        // Set the size
        unsigned int nSize = ssSend.size() - CMessageHeader::HEADER_SIZE;
        memcpy((char*)&ssSend[CMessageHeader::MESSAGE_SIZE_OFFSET], &nSize, sizeof(nSize));

        // Set the checksum
        uint256 hash = Hash(ssSend.begin() + CMessageHeader::HEADER_SIZE, ssSend.end());
        unsigned int nChecksum = 0;
        memcpy(&nChecksum, &hash, sizeof(nChecksum));
        assert(ssSend.size () >= CMessageHeader::CHECKSUM_OFFSET + sizeof(nChecksum));
        memcpy((char*)&ssSend[CMessageHeader::CHECKSUM_OFFSET], &nChecksum, sizeof(nChecksum));

<<<<<<< HEAD
        if (fDebug) {
            printf("(%d bytes)\n", nSize);
        }
=======
        LogPrint("net", "(%d bytes)\n", nSize);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

        std::deque<CSerializeData>::iterator it = vSendMsg.insert(vSendMsg.end(), CSerializeData());
        ssSend.GetAndClear(*it);
        nSendSize += (*it).size();

        // If write queue empty, attempt "optimistic write"
        if (it == vSendMsg.begin())
            SocketSendData(this);

        LEAVE_CRITICAL_SECTION(cs_vSend);
    }

    void PushVersion();


    void PushMessage(const char* pszCommand)
    {
        try
        {
            BeginMessage(pszCommand);
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

    template<typename T1>
    void PushMessage(const char* pszCommand, const T1& a1)
    {
        try
        {
            BeginMessage(pszCommand);
            ssSend << a1;
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

    template<typename T1, typename T2>
    void PushMessage(const char* pszCommand, const T1& a1, const T2& a2)
    {
        try
        {
            BeginMessage(pszCommand);
            ssSend << a1 << a2;
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

    template<typename T1, typename T2, typename T3>
    void PushMessage(const char* pszCommand, const T1& a1, const T2& a2, const T3& a3)
    {
        try
        {
            BeginMessage(pszCommand);
            ssSend << a1 << a2 << a3;
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

    template<typename T1, typename T2, typename T3, typename T4>
    void PushMessage(const char* pszCommand, const T1& a1, const T2& a2, const T3& a3, const T4& a4)
    {
        try
        {
            BeginMessage(pszCommand);
            ssSend << a1 << a2 << a3 << a4;
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5>
    void PushMessage(const char* pszCommand, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5)
    {
        try
        {
            BeginMessage(pszCommand);
            ssSend << a1 << a2 << a3 << a4 << a5;
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void PushMessage(const char* pszCommand, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5, const T6& a6)
    {
        try
        {
            BeginMessage(pszCommand);
            ssSend << a1 << a2 << a3 << a4 << a5 << a6;
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    void PushMessage(const char* pszCommand, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5, const T6& a6, const T7& a7)
    {
        try
        {
            BeginMessage(pszCommand);
            ssSend << a1 << a2 << a3 << a4 << a5 << a6 << a7;
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    void PushMessage(const char* pszCommand, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5, const T6& a6, const T7& a7, const T8& a8)
    {
        try
        {
            BeginMessage(pszCommand);
            ssSend << a1 << a2 << a3 << a4 << a5 << a6 << a7 << a8;
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    void PushMessage(const char* pszCommand, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5, const T6& a6, const T7& a7, const T8& a8, const T9& a9)
    {
        try
        {
            BeginMessage(pszCommand);
            ssSend << a1 << a2 << a3 << a4 << a5 << a6 << a7 << a8 << a9;
            EndMessage();
        }
        catch (...)
        {
            AbortMessage();
            throw;
        }
    }

<<<<<<< HEAD
    void PushGetBlocks(CBlockIndex* pindexBegin, uint256 hashEnd);
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    bool IsSubscribed(unsigned int nChannel);
    void Subscribe(unsigned int nChannel, unsigned int nHops=0);
    void CancelSubscribe(unsigned int nChannel);
    void CloseSocketDisconnect();
    void Cleanup();


    // Denial-of-service detection/prevention
    // The idea is to detect peers that are behaving
    // badly and disconnect/ban them, but do it in a
    // one-coding-mistake-won't-shatter-the-entire-network
    // way.
    // IMPORTANT:  There should be nothing I can give a
    // node that it will forward on that will make that
    // node's peers drop it. If there is, an attacker
    // can isolate a node and/or try to split the network.
    // Dropping a node for sending stuff that is invalid
    // now but might be valid in a later version is also
    // dangerous, because it can cause a network split
    // between nodes running old code and nodes running
    // new code.
    static void ClearBanned(); // needed for unit testing
    static bool IsBanned(CNetAddr ip);
<<<<<<< HEAD
    bool Misbehaving(int howmuch); // 1 == a little, 100 == a lot
    void copyStats(CNodeStats &stats);
=======
    static bool Ban(const CNetAddr &ip);
    void copyStats(CNodeStats &stats);

    // Network stats
    static void RecordBytesRecv(uint64_t bytes);
    static void RecordBytesSent(uint64_t bytes);

    static uint64_t GetTotalBytesRecv();
    static uint64_t GetTotalBytesSent();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
};



class CTransaction;
void RelayTransaction(const CTransaction& tx, const uint256& hash);
void RelayTransaction(const CTransaction& tx, const uint256& hash, const CDataStream& ss);

<<<<<<< HEAD
=======
/** Access to the (IP) address database (peers.dat) */
class CAddrDB
{
private:
    boost::filesystem::path pathAddr;
public:
    CAddrDB();
    bool Write(const CAddrMan& addr);
    bool Read(CAddrMan& addr);
};

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#endif
