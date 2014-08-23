// Copyright (c) 2009-2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
=======
// Copyright (c) 2009-2014 The Bitcoin developers
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "walletdb.h"
<<<<<<< HEAD
#include "wallet.h"
#include <boost/version.hpp>
#include <boost/filesystem.hpp>
=======

#include "base58.h"
#include "protocol.h"
#include "serialize.h"
#include "sync.h"
#include "wallet.h"

#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

using namespace std;
using namespace boost;


<<<<<<< HEAD
static uint64 nAccountingEntryNumber = 0;
=======
static uint64_t nAccountingEntryNumber = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

//
// CWalletDB
//

bool CWalletDB::WriteName(const string& strAddress, const string& strName)
{
    nWalletDBUpdated++;
    return Write(make_pair(string("name"), strAddress), strName);
}

bool CWalletDB::EraseName(const string& strAddress)
{
    // This should only be used for sending addresses, never for receiving addresses,
    // receiving addresses must always have an address book entry if they're not change return.
    nWalletDBUpdated++;
    return Erase(make_pair(string("name"), strAddress));
}

<<<<<<< HEAD
=======
bool CWalletDB::WritePurpose(const string& strAddress, const string& strPurpose)
{
    nWalletDBUpdated++;
    return Write(make_pair(string("purpose"), strAddress), strPurpose);
}

bool CWalletDB::ErasePurpose(const string& strPurpose)
{
    nWalletDBUpdated++;
    return Erase(make_pair(string("purpose"), strPurpose));
}

bool CWalletDB::WriteTx(uint256 hash, const CWalletTx& wtx)
{
    nWalletDBUpdated++;
    return Write(std::make_pair(std::string("tx"), hash), wtx);
}

bool CWalletDB::EraseTx(uint256 hash)
{
    nWalletDBUpdated++;
    return Erase(std::make_pair(std::string("tx"), hash));
}

bool CWalletDB::WriteKey(const CPubKey& vchPubKey, const CPrivKey& vchPrivKey, const CKeyMetadata& keyMeta)
{
    nWalletDBUpdated++;

    if (!Write(std::make_pair(std::string("keymeta"), vchPubKey),
               keyMeta, false))
        return false;

    // hash pubkey/privkey to accelerate wallet load
    std::vector<unsigned char> vchKey;
    vchKey.reserve(vchPubKey.size() + vchPrivKey.size());
    vchKey.insert(vchKey.end(), vchPubKey.begin(), vchPubKey.end());
    vchKey.insert(vchKey.end(), vchPrivKey.begin(), vchPrivKey.end());

    return Write(std::make_pair(std::string("key"), vchPubKey), std::make_pair(vchPrivKey, Hash(vchKey.begin(), vchKey.end())), false);
}

bool CWalletDB::WriteCryptedKey(const CPubKey& vchPubKey,
                                const std::vector<unsigned char>& vchCryptedSecret,
                                const CKeyMetadata &keyMeta)
{
    const bool fEraseUnencryptedKey = true;
    nWalletDBUpdated++;

    if (!Write(std::make_pair(std::string("keymeta"), vchPubKey),
            keyMeta))
        return false;

    if (!Write(std::make_pair(std::string("ckey"), vchPubKey), vchCryptedSecret, false))
        return false;
    if (fEraseUnencryptedKey)
    {
        Erase(std::make_pair(std::string("key"), vchPubKey));
        Erase(std::make_pair(std::string("wkey"), vchPubKey));
    }
    return true;
}

bool CWalletDB::WriteMasterKey(unsigned int nID, const CMasterKey& kMasterKey)
{
    nWalletDBUpdated++;
    return Write(std::make_pair(std::string("mkey"), nID), kMasterKey, true);
}

bool CWalletDB::WriteCScript(const uint160& hash, const CScript& redeemScript)
{
    nWalletDBUpdated++;
    return Write(std::make_pair(std::string("cscript"), hash), redeemScript, false);
}

bool CWalletDB::WriteBestBlock(const CBlockLocator& locator)
{
    nWalletDBUpdated++;
    return Write(std::string("bestblock"), locator);
}

bool CWalletDB::ReadBestBlock(CBlockLocator& locator)
{
    return Read(std::string("bestblock"), locator);
}

bool CWalletDB::WriteOrderPosNext(int64_t nOrderPosNext)
{
    nWalletDBUpdated++;
    return Write(std::string("orderposnext"), nOrderPosNext);
}

bool CWalletDB::WriteDefaultKey(const CPubKey& vchPubKey)
{
    nWalletDBUpdated++;
    return Write(std::string("defaultkey"), vchPubKey);
}

bool CWalletDB::ReadPool(int64_t nPool, CKeyPool& keypool)
{
    return Read(std::make_pair(std::string("pool"), nPool), keypool);
}

bool CWalletDB::WritePool(int64_t nPool, const CKeyPool& keypool)
{
    nWalletDBUpdated++;
    return Write(std::make_pair(std::string("pool"), nPool), keypool);
}

bool CWalletDB::ErasePool(int64_t nPool)
{
    nWalletDBUpdated++;
    return Erase(std::make_pair(std::string("pool"), nPool));
}

bool CWalletDB::WriteMinVersion(int nVersion)
{
    return Write(std::string("minversion"), nVersion);
}

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
bool CWalletDB::ReadAccount(const string& strAccount, CAccount& account)
{
    account.SetNull();
    return Read(make_pair(string("acc"), strAccount), account);
}

bool CWalletDB::WriteAccount(const string& strAccount, const CAccount& account)
{
    return Write(make_pair(string("acc"), strAccount), account);
}

<<<<<<< HEAD
bool CWalletDB::WriteAccountingEntry(const uint64 nAccEntryNum, const CAccountingEntry& acentry)
=======
bool CWalletDB::WriteAccountingEntry(const uint64_t nAccEntryNum, const CAccountingEntry& acentry)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    return Write(boost::make_tuple(string("acentry"), acentry.strAccount, nAccEntryNum), acentry);
}

bool CWalletDB::WriteAccountingEntry(const CAccountingEntry& acentry)
{
    return WriteAccountingEntry(++nAccountingEntryNumber, acentry);
}

<<<<<<< HEAD
int64 CWalletDB::GetAccountCreditDebit(const string& strAccount)
=======
int64_t CWalletDB::GetAccountCreditDebit(const string& strAccount)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    list<CAccountingEntry> entries;
    ListAccountCreditDebit(strAccount, entries);

<<<<<<< HEAD
    int64 nCreditDebit = 0;
=======
    int64_t nCreditDebit = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    BOOST_FOREACH (const CAccountingEntry& entry, entries)
        nCreditDebit += entry.nCreditDebit;

    return nCreditDebit;
}

void CWalletDB::ListAccountCreditDebit(const string& strAccount, list<CAccountingEntry>& entries)
{
    bool fAllAccounts = (strAccount == "*");

    Dbc* pcursor = GetCursor();
    if (!pcursor)
        throw runtime_error("CWalletDB::ListAccountCreditDebit() : cannot create DB cursor");
    unsigned int fFlags = DB_SET_RANGE;
<<<<<<< HEAD
    loop
=======
    while (true)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        // Read next record
        CDataStream ssKey(SER_DISK, CLIENT_VERSION);
        if (fFlags == DB_SET_RANGE)
<<<<<<< HEAD
            ssKey << boost::make_tuple(string("acentry"), (fAllAccounts? string("") : strAccount), uint64(0));
=======
            ssKey << boost::make_tuple(string("acentry"), (fAllAccounts? string("") : strAccount), uint64_t(0));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        CDataStream ssValue(SER_DISK, CLIENT_VERSION);
        int ret = ReadAtCursor(pcursor, ssKey, ssValue, fFlags);
        fFlags = DB_NEXT;
        if (ret == DB_NOTFOUND)
            break;
        else if (ret != 0)
        {
            pcursor->close();
            throw runtime_error("CWalletDB::ListAccountCreditDebit() : error scanning DB");
        }

        // Unserialize
        string strType;
        ssKey >> strType;
        if (strType != "acentry")
            break;
        CAccountingEntry acentry;
        ssKey >> acentry.strAccount;
        if (!fAllAccounts && acentry.strAccount != strAccount)
            break;

        ssValue >> acentry;
        ssKey >> acentry.nEntryNo;
        entries.push_back(acentry);
    }

    pcursor->close();
}


DBErrors
CWalletDB::ReorderTransactions(CWallet* pwallet)
{
    LOCK(pwallet->cs_wallet);
    // Old wallets didn't have any defined order for transactions
    // Probably a bad idea to change the output of this

    // First: get all CWalletTx and CAccountingEntry into a sorted-by-time multimap.
    typedef pair<CWalletTx*, CAccountingEntry*> TxPair;
<<<<<<< HEAD
    typedef multimap<int64, TxPair > TxItems;
=======
    typedef multimap<int64_t, TxPair > TxItems;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    TxItems txByTime;

    for (map<uint256, CWalletTx>::iterator it = pwallet->mapWallet.begin(); it != pwallet->mapWallet.end(); ++it)
    {
        CWalletTx* wtx = &((*it).second);
        txByTime.insert(make_pair(wtx->nTimeReceived, TxPair(wtx, (CAccountingEntry*)0)));
    }
    list<CAccountingEntry> acentries;
    ListAccountCreditDebit("", acentries);
    BOOST_FOREACH(CAccountingEntry& entry, acentries)
    {
        txByTime.insert(make_pair(entry.nTime, TxPair((CWalletTx*)0, &entry)));
    }

<<<<<<< HEAD
    int64& nOrderPosNext = pwallet->nOrderPosNext;
    nOrderPosNext = 0;
    std::vector<int64> nOrderPosOffsets;
=======
    int64_t& nOrderPosNext = pwallet->nOrderPosNext;
    nOrderPosNext = 0;
    std::vector<int64_t> nOrderPosOffsets;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    for (TxItems::iterator it = txByTime.begin(); it != txByTime.end(); ++it)
    {
        CWalletTx *const pwtx = (*it).second.first;
        CAccountingEntry *const pacentry = (*it).second.second;
<<<<<<< HEAD
        int64& nOrderPos = (pwtx != 0) ? pwtx->nOrderPos : pacentry->nOrderPos;
=======
        int64_t& nOrderPos = (pwtx != 0) ? pwtx->nOrderPos : pacentry->nOrderPos;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

        if (nOrderPos == -1)
        {
            nOrderPos = nOrderPosNext++;
            nOrderPosOffsets.push_back(nOrderPos);

            if (pacentry)
                // Have to write accounting regardless, since we don't keep it in memory
                if (!WriteAccountingEntry(pacentry->nEntryNo, *pacentry))
                    return DB_LOAD_FAIL;
        }
        else
        {
<<<<<<< HEAD
            int64 nOrderPosOff = 0;
            BOOST_FOREACH(const int64& nOffsetStart, nOrderPosOffsets)
=======
            int64_t nOrderPosOff = 0;
            BOOST_FOREACH(const int64_t& nOffsetStart, nOrderPosOffsets)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            {
                if (nOrderPos >= nOffsetStart)
                    ++nOrderPosOff;
            }
            nOrderPos += nOrderPosOff;
            nOrderPosNext = std::max(nOrderPosNext, nOrderPos + 1);

            if (!nOrderPosOff)
                continue;

            // Since we're changing the order, write it back
            if (pwtx)
            {
                if (!WriteTx(pwtx->GetHash(), *pwtx))
                    return DB_LOAD_FAIL;
            }
            else
                if (!WriteAccountingEntry(pacentry->nEntryNo, *pacentry))
                    return DB_LOAD_FAIL;
        }
    }

    return DB_LOAD_OK;
}

<<<<<<< HEAD

bool
ReadKeyValue(CWallet* pwallet, CDataStream& ssKey, CDataStream& ssValue,
             int& nFileVersion, vector<uint256>& vWalletUpgrade,
             bool& fIsEncrypted,  bool& fAnyUnordered, string& strType, string& strErr)
=======
class CWalletScanState {
public:
    unsigned int nKeys;
    unsigned int nCKeys;
    unsigned int nKeyMeta;
    bool fIsEncrypted;
    bool fAnyUnordered;
    int nFileVersion;
    vector<uint256> vWalletUpgrade;

    CWalletScanState() {
        nKeys = nCKeys = nKeyMeta = 0;
        fIsEncrypted = false;
        fAnyUnordered = false;
        nFileVersion = 0;
    }
};

bool
ReadKeyValue(CWallet* pwallet, CDataStream& ssKey, CDataStream& ssValue,
             CWalletScanState &wss, string& strType, string& strErr)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    try {
        // Unserialize
        // Taking advantage of the fact that pair serialization
        // is just the two items serialized one after the other
        ssKey >> strType;
        if (strType == "name")
        {
            string strAddress;
            ssKey >> strAddress;
<<<<<<< HEAD
            ssValue >> pwallet->mapAddressBook[CBitcoinAddress(strAddress).Get()];
=======
            ssValue >> pwallet->mapAddressBook[CBitcoinAddress(strAddress).Get()].name;
        }
        else if (strType == "purpose")
        {
            string strAddress;
            ssKey >> strAddress;
            ssValue >> pwallet->mapAddressBook[CBitcoinAddress(strAddress).Get()].purpose;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
        else if (strType == "tx")
        {
            uint256 hash;
            ssKey >> hash;
<<<<<<< HEAD
            CWalletTx& wtx = pwallet->mapWallet[hash];
            ssValue >> wtx;
            CValidationState state;
            if (wtx.CheckTransaction(state) && (wtx.GetHash() == hash) && state.IsValid())
                wtx.BindWallet(pwallet);
            else
            {
                pwallet->mapWallet.erase(hash);
                return false;
            }

            if (wtx.nOrderPos == -1)
                fAnyUnordered = true;

            //// debug print
            //printf("LoadWallet  %s\n", wtx.GetHash().ToString().c_str());
            //printf(" %12"PRI64d"  %s  %s  %s\n",
            //    wtx.vout[0].nValue,
            //    DateTimeStrFormat("%Y-%m-%d %H:%M:%S", wtx.GetBlockTime()).c_str(),
            //    wtx.hashBlock.ToString().c_str(),
            //    wtx.mapValue["message"].c_str());
=======
            CWalletTx wtx;
            ssValue >> wtx;
            CValidationState state;
            if (CheckTransaction(wtx, state) && (wtx.GetHash() == hash) && state.IsValid())
                wtx.BindWallet(pwallet);
            else
                return false;

            if (wtx.nOrderPos == -1)
                wss.fAnyUnordered = true;

            pwallet->AddToWallet(wtx, true);
            //// debug print
            //LogPrintf("LoadWallet  %s\n", wtx.GetHash().ToString());
            //LogPrintf(" %12d  %s  %s  %s\n",
            //    wtx.vout[0].nValue,
            //    DateTimeStrFormat("%Y-%m-%d %H:%M:%S", wtx.GetBlockTime()),
            //    wtx.hashBlock.ToString(),
            //    wtx.mapValue["message"]);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
        else if (strType == "acentry")
        {
            string strAccount;
            ssKey >> strAccount;
<<<<<<< HEAD
            uint64 nNumber;
=======
            uint64_t nNumber;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            ssKey >> nNumber;
            if (nNumber > nAccountingEntryNumber)
                nAccountingEntryNumber = nNumber;

<<<<<<< HEAD
            if (!fAnyUnordered)
=======
            if (!wss.fAnyUnordered)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            {
                CAccountingEntry acentry;
                ssValue >> acentry;
                if (acentry.nOrderPos == -1)
<<<<<<< HEAD
                    fAnyUnordered = true;
=======
                    wss.fAnyUnordered = true;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            }
        }
        else if (strType == "key" || strType == "wkey")
        {
            CPubKey vchPubKey;
            ssKey >> vchPubKey;
            if (!vchPubKey.IsValid())
            {
                strErr = "Error reading wallet database: CPubKey corrupt";
                return false;
            }
            CKey key;
            CPrivKey pkey;
<<<<<<< HEAD
            if (strType == "key")
                ssValue >> pkey;
            else {
=======
            uint256 hash = 0;

            if (strType == "key")
            {
                wss.nKeys++;
                ssValue >> pkey;
            } else {
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                CWalletKey wkey;
                ssValue >> wkey;
                pkey = wkey.vchPrivKey;
            }
<<<<<<< HEAD
            if (!key.SetPrivKey(pkey, vchPubKey.IsCompressed()))
            {
                strErr = "Error reading wallet database: CPrivKey corrupt";
                return false;
            }
            if (key.GetPubKey() != vchPubKey)
            {
                strErr = "Error reading wallet database: CPrivKey pubkey inconsistency";
=======

            // Old wallets store keys as "key" [pubkey] => [privkey]
            // ... which was slow for wallets with lots of keys, because the public key is re-derived from the private key
            // using EC operations as a checksum.
            // Newer wallets store keys as "key"[pubkey] => [privkey][hash(pubkey,privkey)], which is much faster while
            // remaining backwards-compatible.
            try
            {
                ssValue >> hash;
            }
            catch(...){}

            bool fSkipCheck = false;

            if (hash != 0)
            {
                // hash pubkey/privkey to accelerate wallet load
                std::vector<unsigned char> vchKey;
                vchKey.reserve(vchPubKey.size() + pkey.size());
                vchKey.insert(vchKey.end(), vchPubKey.begin(), vchPubKey.end());
                vchKey.insert(vchKey.end(), pkey.begin(), pkey.end());

                if (Hash(vchKey.begin(), vchKey.end()) != hash)
                {
                    strErr = "Error reading wallet database: CPubKey/CPrivKey corrupt";
                    return false;
                }

                fSkipCheck = true;
            }

            if (!key.Load(pkey, vchPubKey, fSkipCheck))
            {
                strErr = "Error reading wallet database: CPrivKey corrupt";
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                return false;
            }
            if (!pwallet->LoadKey(key, vchPubKey))
            {
                strErr = "Error reading wallet database: LoadKey failed";
                return false;
            }
        }
        else if (strType == "mkey")
        {
            unsigned int nID;
            ssKey >> nID;
            CMasterKey kMasterKey;
            ssValue >> kMasterKey;
            if(pwallet->mapMasterKeys.count(nID) != 0)
            {
                strErr = strprintf("Error reading wallet database: duplicate CMasterKey id %u", nID);
                return false;
            }
            pwallet->mapMasterKeys[nID] = kMasterKey;
            if (pwallet->nMasterKeyMaxID < nID)
                pwallet->nMasterKeyMaxID = nID;
        }
        else if (strType == "ckey")
        {
            vector<unsigned char> vchPubKey;
            ssKey >> vchPubKey;
            vector<unsigned char> vchPrivKey;
            ssValue >> vchPrivKey;
<<<<<<< HEAD
=======
            wss.nCKeys++;

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            if (!pwallet->LoadCryptedKey(vchPubKey, vchPrivKey))
            {
                strErr = "Error reading wallet database: LoadCryptedKey failed";
                return false;
            }
<<<<<<< HEAD
            fIsEncrypted = true;
=======
            wss.fIsEncrypted = true;
        }
        else if (strType == "keymeta")
        {
            CPubKey vchPubKey;
            ssKey >> vchPubKey;
            CKeyMetadata keyMeta;
            ssValue >> keyMeta;
            wss.nKeyMeta++;

            pwallet->LoadKeyMetadata(vchPubKey, keyMeta);

            // find earliest key creation time, as wallet birthday
            if (!pwallet->nTimeFirstKey ||
                (keyMeta.nCreateTime < pwallet->nTimeFirstKey))
                pwallet->nTimeFirstKey = keyMeta.nCreateTime;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
        else if (strType == "defaultkey")
        {
            ssValue >> pwallet->vchDefaultKey;
        }
        else if (strType == "pool")
        {
<<<<<<< HEAD
            int64 nIndex;
            ssKey >> nIndex;
            pwallet->setKeyPool.insert(nIndex);
        }
        else if (strType == "version")
        {
            ssValue >> nFileVersion;
            if (nFileVersion == 10300)
                nFileVersion = 300;
=======
            int64_t nIndex;
            ssKey >> nIndex;
            CKeyPool keypool;
            ssValue >> keypool;
            pwallet->setKeyPool.insert(nIndex);

            // If no metadata exists yet, create a default with the pool key's
            // creation time. Note that this may be overwritten by actually
            // stored metadata for that key later, which is fine.
            CKeyID keyid = keypool.vchPubKey.GetID();
            if (pwallet->mapKeyMetadata.count(keyid) == 0)
                pwallet->mapKeyMetadata[keyid] = CKeyMetadata(keypool.nTime);
        }
        else if (strType == "version")
        {
            ssValue >> wss.nFileVersion;
            if (wss.nFileVersion == 10300)
                wss.nFileVersion = 300;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
        else if (strType == "cscript")
        {
            uint160 hash;
            ssKey >> hash;
            CScript script;
            ssValue >> script;
            if (!pwallet->LoadCScript(script))
            {
                strErr = "Error reading wallet database: LoadCScript failed";
                return false;
            }
        }
        else if (strType == "orderposnext")
        {
            ssValue >> pwallet->nOrderPosNext;
        }
<<<<<<< HEAD
=======
        else if (strType == "destdata")
        {
            std::string strAddress, strKey, strValue;
            ssKey >> strAddress;
            ssKey >> strKey;
            ssValue >> strValue;
            if (!pwallet->LoadDestData(CBitcoinAddress(strAddress).Get(), strKey, strValue))
            {
                strErr = "Error reading wallet database: LoadDestData failed";
                return false;
            }
        }
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    } catch (...)
    {
        return false;
    }
    return true;
}

static bool IsKeyType(string strType)
{
    return (strType== "key" || strType == "wkey" ||
            strType == "mkey" || strType == "ckey");
}

DBErrors CWalletDB::LoadWallet(CWallet* pwallet)
{
    pwallet->vchDefaultKey = CPubKey();
<<<<<<< HEAD
    int nFileVersion = 0;
    vector<uint256> vWalletUpgrade;
    bool fIsEncrypted = false;
    bool fAnyUnordered = false;
=======
    CWalletScanState wss;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    bool fNoncriticalErrors = false;
    DBErrors result = DB_LOAD_OK;

    try {
        LOCK(pwallet->cs_wallet);
        int nMinVersion = 0;
        if (Read((string)"minversion", nMinVersion))
        {
            if (nMinVersion > CLIENT_VERSION)
                return DB_TOO_NEW;
            pwallet->LoadMinVersion(nMinVersion);
        }

        // Get cursor
        Dbc* pcursor = GetCursor();
        if (!pcursor)
        {
<<<<<<< HEAD
            printf("Error getting wallet database cursor\n");
            return DB_CORRUPT;
        }

        loop
=======
            LogPrintf("Error getting wallet database cursor\n");
            return DB_CORRUPT;
        }

        while (true)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        {
            // Read next record
            CDataStream ssKey(SER_DISK, CLIENT_VERSION);
            CDataStream ssValue(SER_DISK, CLIENT_VERSION);
            int ret = ReadAtCursor(pcursor, ssKey, ssValue);
            if (ret == DB_NOTFOUND)
                break;
            else if (ret != 0)
            {
<<<<<<< HEAD
                printf("Error reading next record from wallet database\n");
=======
                LogPrintf("Error reading next record from wallet database\n");
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                return DB_CORRUPT;
            }

            // Try to be tolerant of single corrupt records:
            string strType, strErr;
<<<<<<< HEAD
            if (!ReadKeyValue(pwallet, ssKey, ssValue, nFileVersion,
                              vWalletUpgrade, fIsEncrypted, fAnyUnordered, strType, strErr))
=======
            if (!ReadKeyValue(pwallet, ssKey, ssValue, wss, strType, strErr))
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            {
                // losing keys is considered a catastrophic error, anything else
                // we assume the user can live with:
                if (IsKeyType(strType))
                    result = DB_CORRUPT;
                else
                {
                    // Leave other errors alone, if we try to fix them we might make things worse.
                    fNoncriticalErrors = true; // ... but do warn the user there is something wrong.
                    if (strType == "tx")
                        // Rescan if there is a bad transaction record:
                        SoftSetBoolArg("-rescan", true);
                }
            }
            if (!strErr.empty())
<<<<<<< HEAD
                printf("%s\n", strErr.c_str());
=======
                LogPrintf("%s\n", strErr);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
        pcursor->close();
    }
    catch (boost::thread_interrupted) {
        throw;
    }
    catch (...) {
        result = DB_CORRUPT;
    }

    if (fNoncriticalErrors && result == DB_LOAD_OK)
        result = DB_NONCRITICAL_ERROR;

    // Any wallet corruption at all: skip any rewriting or
    // upgrading, we don't want to make it worse.
    if (result != DB_LOAD_OK)
        return result;

<<<<<<< HEAD
    printf("nFileVersion = %d\n", nFileVersion);

    BOOST_FOREACH(uint256 hash, vWalletUpgrade)
        WriteTx(hash, pwallet->mapWallet[hash]);

    if (nFileVersion < CLIENT_VERSION) // Update
        WriteVersion(CLIENT_VERSION);

    if (fAnyUnordered)
=======
    LogPrintf("nFileVersion = %d\n", wss.nFileVersion);

    LogPrintf("Keys: %u plaintext, %u encrypted, %u w/ metadata, %u total\n",
           wss.nKeys, wss.nCKeys, wss.nKeyMeta, wss.nKeys + wss.nCKeys);

    // nTimeFirstKey is only reliable if all keys have metadata
    if ((wss.nKeys + wss.nCKeys) != wss.nKeyMeta)
        pwallet->nTimeFirstKey = 1; // 0 would be considered 'no value'

    BOOST_FOREACH(uint256 hash, wss.vWalletUpgrade)
        WriteTx(hash, pwallet->mapWallet[hash]);

    if (wss.nFileVersion < CLIENT_VERSION) // Update
        WriteVersion(CLIENT_VERSION);

    if (wss.fAnyUnordered)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        result = ReorderTransactions(pwallet);

    return result;
}

<<<<<<< HEAD
void ThreadFlushWalletDB(const string& strFile)
{
    // Make this thread recognisable as the wallet flushing thread
    RenameThread("bitcoin-wallet");
=======
DBErrors CWalletDB::FindWalletTx(CWallet* pwallet, vector<uint256>& vTxHash)
{
    pwallet->vchDefaultKey = CPubKey();
    CWalletScanState wss;
    bool fNoncriticalErrors = false;
    DBErrors result = DB_LOAD_OK;

    try {
        LOCK(pwallet->cs_wallet);
        int nMinVersion = 0;
        if (Read((string)"minversion", nMinVersion))
        {
            if (nMinVersion > CLIENT_VERSION)
                return DB_TOO_NEW;
            pwallet->LoadMinVersion(nMinVersion);
        }

        // Get cursor
        Dbc* pcursor = GetCursor();
        if (!pcursor)
        {
            LogPrintf("Error getting wallet database cursor\n");
            return DB_CORRUPT;
        }

        while (true)
        {
            // Read next record
            CDataStream ssKey(SER_DISK, CLIENT_VERSION);
            CDataStream ssValue(SER_DISK, CLIENT_VERSION);
            int ret = ReadAtCursor(pcursor, ssKey, ssValue);
            if (ret == DB_NOTFOUND)
                break;
            else if (ret != 0)
            {
                LogPrintf("Error reading next record from wallet database\n");
                return DB_CORRUPT;
            }

            string strType;
            ssKey >> strType;
            if (strType == "tx") {
                uint256 hash;
                ssKey >> hash;

                vTxHash.push_back(hash);
            }
        }
        pcursor->close();
    }
    catch (boost::thread_interrupted) {
        throw;
    }
    catch (...) {
        result = DB_CORRUPT;
    }

    if (fNoncriticalErrors && result == DB_LOAD_OK)
        result = DB_NONCRITICAL_ERROR;

    return result;
}

DBErrors CWalletDB::ZapWalletTx(CWallet* pwallet)
{
    // build list of wallet TXs
    vector<uint256> vTxHash;
    DBErrors err = FindWalletTx(pwallet, vTxHash);
    if (err != DB_LOAD_OK)
        return err;

    // erase each wallet TX
    BOOST_FOREACH (uint256& hash, vTxHash) {
        if (!EraseTx(hash))
            return DB_CORRUPT;
    }

    return DB_LOAD_OK;
}

void ThreadFlushWalletDB(const string& strFile)
{
    // Make this thread recognisable as the wallet flushing thread
    RenameThread("dogecoin-wallet");
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    static bool fOneThread;
    if (fOneThread)
        return;
    fOneThread = true;
    if (!GetBoolArg("-flushwallet", true))
        return;

    unsigned int nLastSeen = nWalletDBUpdated;
    unsigned int nLastFlushed = nWalletDBUpdated;
<<<<<<< HEAD
    int64 nLastWalletUpdate = GetTime();
=======
    int64_t nLastWalletUpdate = GetTime();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    while (true)
    {
        MilliSleep(500);

        if (nLastSeen != nWalletDBUpdated)
        {
            nLastSeen = nWalletDBUpdated;
            nLastWalletUpdate = GetTime();
        }

        if (nLastFlushed != nWalletDBUpdated && GetTime() - nLastWalletUpdate >= 2)
        {
            TRY_LOCK(bitdb.cs_db,lockDb);
            if (lockDb)
            {
                // Don't do this if any databases are in use
                int nRefCount = 0;
                map<string, int>::iterator mi = bitdb.mapFileUseCount.begin();
                while (mi != bitdb.mapFileUseCount.end())
                {
                    nRefCount += (*mi).second;
                    mi++;
                }

                if (nRefCount == 0)
                {
                    boost::this_thread::interruption_point();
                    map<string, int>::iterator mi = bitdb.mapFileUseCount.find(strFile);
                    if (mi != bitdb.mapFileUseCount.end())
                    {
<<<<<<< HEAD
                        printf("Flushing wallet.dat\n");
                        nLastFlushed = nWalletDBUpdated;
                        int64 nStart = GetTimeMillis();
=======
                        LogPrint("db", "Flushing wallet.dat\n");
                        nLastFlushed = nWalletDBUpdated;
                        int64_t nStart = GetTimeMillis();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

                        // Flush wallet.dat so it's self contained
                        bitdb.CloseDb(strFile);
                        bitdb.CheckpointLSN(strFile);

                        bitdb.mapFileUseCount.erase(mi++);
<<<<<<< HEAD
                        printf("Flushed wallet.dat %"PRI64d"ms\n", GetTimeMillis() - nStart);
=======
                        LogPrint("db", "Flushed wallet.dat %dms\n", GetTimeMillis() - nStart);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    }
                }
            }
        }
    }
}

bool BackupWallet(const CWallet& wallet, const string& strDest)
{
    if (!wallet.fFileBacked)
        return false;
    while (true)
    {
        {
            LOCK(bitdb.cs_db);
            if (!bitdb.mapFileUseCount.count(wallet.strWalletFile) || bitdb.mapFileUseCount[wallet.strWalletFile] == 0)
            {
                // Flush log data to the dat file
                bitdb.CloseDb(wallet.strWalletFile);
                bitdb.CheckpointLSN(wallet.strWalletFile);
                bitdb.mapFileUseCount.erase(wallet.strWalletFile);

                // Copy wallet.dat
                filesystem::path pathSrc = GetDataDir() / wallet.strWalletFile;
                filesystem::path pathDest(strDest);
                if (filesystem::is_directory(pathDest))
                    pathDest /= wallet.strWalletFile;

                try {
#if BOOST_VERSION >= 104000
                    filesystem::copy_file(pathSrc, pathDest, filesystem::copy_option::overwrite_if_exists);
#else
                    filesystem::copy_file(pathSrc, pathDest);
#endif
<<<<<<< HEAD
                    printf("copied wallet.dat to %s\n", pathDest.string().c_str());
                    return true;
                } catch(const filesystem::filesystem_error &e) {
                    printf("error copying wallet.dat to %s - %s\n", pathDest.string().c_str(), e.what());
=======
                    LogPrintf("copied wallet.dat to %s\n", pathDest.string());
                    return true;
                } catch(const filesystem::filesystem_error &e) {
                    LogPrintf("error copying wallet.dat to %s - %s\n", pathDest.string(), e.what());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    return false;
                }
            }
        }
        MilliSleep(100);
    }
    return false;
}

//
// Try to (very carefully!) recover wallet.dat if there is a problem.
//
bool CWalletDB::Recover(CDBEnv& dbenv, std::string filename, bool fOnlyKeys)
{
    // Recovery procedure:
    // move wallet.dat to wallet.timestamp.bak
    // Call Salvage with fAggressive=true to
    // get as much data as possible.
    // Rewrite salvaged data to wallet.dat
    // Set -rescan so any missing transactions will be
    // found.
<<<<<<< HEAD
    int64 now = GetTime();
    std::string newFilename = strprintf("wallet.%"PRI64d".bak", now);
=======
    int64_t now = GetTime();
    std::string newFilename = strprintf("wallet.%d.bak", now);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    int result = dbenv.dbenv.dbrename(NULL, filename.c_str(), NULL,
                                      newFilename.c_str(), DB_AUTO_COMMIT);
    if (result == 0)
<<<<<<< HEAD
        printf("Renamed %s to %s\n", filename.c_str(), newFilename.c_str());
    else
    {
        printf("Failed to rename %s to %s\n", filename.c_str(), newFilename.c_str());
=======
        LogPrintf("Renamed %s to %s\n", filename, newFilename);
    else
    {
        LogPrintf("Failed to rename %s to %s\n", filename, newFilename);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        return false;
    }

    std::vector<CDBEnv::KeyValPair> salvagedData;
    bool allOK = dbenv.Salvage(newFilename, true, salvagedData);
    if (salvagedData.empty())
    {
<<<<<<< HEAD
        printf("Salvage(aggressive) found no records in %s.\n", newFilename.c_str());
        return false;
    }
    printf("Salvage(aggressive) found %"PRIszu" records\n", salvagedData.size());
=======
        LogPrintf("Salvage(aggressive) found no records in %s.\n", newFilename);
        return false;
    }
    LogPrintf("Salvage(aggressive) found %" PRIszu" records\n", salvagedData.size());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    bool fSuccess = allOK;
    Db* pdbCopy = new Db(&dbenv.dbenv, 0);
    int ret = pdbCopy->open(NULL,               // Txn pointer
                            filename.c_str(),   // Filename
                            "main",             // Logical db name
                            DB_BTREE,           // Database type
                            DB_CREATE,          // Flags
                            0);
    if (ret > 0)
    {
<<<<<<< HEAD
        printf("Cannot create database file %s\n", filename.c_str());
        return false;
    }
    CWallet dummyWallet;
    int nFileVersion = 0;
    vector<uint256> vWalletUpgrade;
    bool fIsEncrypted = false;
    bool fAnyUnordered = false;
=======
        LogPrintf("Cannot create database file %s\n", filename);
        return false;
    }
    CWallet dummyWallet;
    CWalletScanState wss;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    DbTxn* ptxn = dbenv.TxnBegin();
    BOOST_FOREACH(CDBEnv::KeyValPair& row, salvagedData)
    {
        if (fOnlyKeys)
        {
            CDataStream ssKey(row.first, SER_DISK, CLIENT_VERSION);
            CDataStream ssValue(row.second, SER_DISK, CLIENT_VERSION);
            string strType, strErr;
            bool fReadOK = ReadKeyValue(&dummyWallet, ssKey, ssValue,
<<<<<<< HEAD
                                        nFileVersion, vWalletUpgrade,
                                        fIsEncrypted, fAnyUnordered,
                                        strType, strErr);
=======
                                        wss, strType, strErr);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            if (!IsKeyType(strType))
                continue;
            if (!fReadOK)
            {
<<<<<<< HEAD
                printf("WARNING: CWalletDB::Recover skipping %s: %s\n", strType.c_str(), strErr.c_str());
=======
                LogPrintf("WARNING: CWalletDB::Recover skipping %s: %s\n", strType, strErr);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                continue;
            }
        }
        Dbt datKey(&row.first[0], row.first.size());
        Dbt datValue(&row.second[0], row.second.size());
        int ret2 = pdbCopy->put(ptxn, &datKey, &datValue, DB_NOOVERWRITE);
        if (ret2 > 0)
            fSuccess = false;
    }
    ptxn->commit(0);
    pdbCopy->close(0);
    delete pdbCopy;

    return fSuccess;
}

bool CWalletDB::Recover(CDBEnv& dbenv, std::string filename)
{
    return CWalletDB::Recover(dbenv, filename, false);
}
<<<<<<< HEAD
=======

bool CWalletDB::WriteDestData(const std::string &address, const std::string &key, const std::string &value)
{
    nWalletDBUpdated++;
    return Write(boost::make_tuple(std::string("destdata"), address, key), value);
}

bool CWalletDB::EraseDestData(const std::string &address, const std::string &key)
{
    nWalletDBUpdated++;
    return Erase(boost::make_tuple(string("destdata"), address, key));
}
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
