// Copyright (c) 2009-2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
=======
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c)      2014 The Dogecoin developers
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "wallet.h"
<<<<<<< HEAD
#include "walletdb.h"
#include "crypter.h"
#include "ui_interface.h"
#include "base58.h"
#include "coincontrol.h"
#include <boost/algorithm/string/replace.hpp>

using namespace std;

=======

#include "base58.h"
#include "coincontrol.h"
#include "net.h"
#include "checkpoints.h"

#include <boost/algorithm/string/replace.hpp>
#include <openssl/rand.h>

using namespace std;

// Settings
int64_t nTransactionFee = 0;
bool bSpendZeroConfChange = true;
static std::vector<CKeyID> vChangeAddresses;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

//////////////////////////////////////////////////////////////////////////////
//
// mapWallet
//

struct CompareValueOnly
{
<<<<<<< HEAD
    bool operator()(const pair<int64, pair<const CWalletTx*, unsigned int> >& t1,
                    const pair<int64, pair<const CWalletTx*, unsigned int> >& t2) const
=======
    bool operator()(const pair<int64_t, pair<const CWalletTx*, unsigned int> >& t1,
                    const pair<int64_t, pair<const CWalletTx*, unsigned int> >& t2) const
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        return t1.first < t2.first;
    }
};

<<<<<<< HEAD
CPubKey CWallet::GenerateNewKey()
{
=======
const CWalletTx* CWallet::GetWalletTx(const uint256& hash) const
{
    LOCK(cs_wallet);
    std::map<uint256, CWalletTx>::const_iterator it = mapWallet.find(hash);
    if (it == mapWallet.end())
        return NULL;
    return &(it->second);
}

CPubKey CWallet::GenerateNewKey()
{
    AssertLockHeld(cs_wallet); // mapKeyMetadata
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    bool fCompressed = CanSupportFeature(FEATURE_COMPRPUBKEY); // default to compressed public keys if we want 0.6.0 wallets

    RandAddSeedPerfmon();
    CKey secret;
    secret.MakeNewKey(fCompressed);

    // Compressed public keys were introduced in version 0.6.0
    if (fCompressed)
        SetMinVersion(FEATURE_COMPRPUBKEY);

    CPubKey pubkey = secret.GetPubKey();
<<<<<<< HEAD
=======

    // Create new metadata
    int64_t nCreationTime = GetTime();
    mapKeyMetadata[pubkey.GetID()] = CKeyMetadata(nCreationTime);
    if (!nTimeFirstKey || nCreationTime < nTimeFirstKey)
        nTimeFirstKey = nCreationTime;

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    if (!AddKeyPubKey(secret, pubkey))
        throw std::runtime_error("CWallet::GenerateNewKey() : AddKey failed");
    return pubkey;
}

bool CWallet::AddKeyPubKey(const CKey& secret, const CPubKey &pubkey)
{
<<<<<<< HEAD
=======
    AssertLockHeld(cs_wallet); // mapKeyMetadata
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    if (!CCryptoKeyStore::AddKeyPubKey(secret, pubkey))
        return false;
    if (!fFileBacked)
        return true;
    if (!IsCrypted()) {
<<<<<<< HEAD
        return CWalletDB(strWalletFile).WriteKey(pubkey, secret.GetPrivKey());
=======
        return CWalletDB(strWalletFile).WriteKey(pubkey,
                                                 secret.GetPrivKey(),
                                                 mapKeyMetadata[pubkey.GetID()]);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
    return true;
}

<<<<<<< HEAD
bool CWallet::AddCryptedKey(const CPubKey &vchPubKey, const vector<unsigned char> &vchCryptedSecret)
=======
bool CWallet::AddCryptedKey(const CPubKey &vchPubKey,
                            const vector<unsigned char> &vchCryptedSecret)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    if (!CCryptoKeyStore::AddCryptedKey(vchPubKey, vchCryptedSecret))
        return false;
    if (!fFileBacked)
        return true;
    {
        LOCK(cs_wallet);
        if (pwalletdbEncryption)
<<<<<<< HEAD
            return pwalletdbEncryption->WriteCryptedKey(vchPubKey, vchCryptedSecret);
        else
            return CWalletDB(strWalletFile).WriteCryptedKey(vchPubKey, vchCryptedSecret);
=======
            return pwalletdbEncryption->WriteCryptedKey(vchPubKey,
                                                        vchCryptedSecret,
                                                        mapKeyMetadata[vchPubKey.GetID()]);
        else
            return CWalletDB(strWalletFile).WriteCryptedKey(vchPubKey,
                                                            vchCryptedSecret,
                                                            mapKeyMetadata[vchPubKey.GetID()]);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
    return false;
}

<<<<<<< HEAD
=======
bool CWallet::LoadKeyMetadata(const CPubKey &pubkey, const CKeyMetadata &meta)
{
    AssertLockHeld(cs_wallet); // mapKeyMetadata
    if (meta.nCreateTime && (!nTimeFirstKey || meta.nCreateTime < nTimeFirstKey))
        nTimeFirstKey = meta.nCreateTime;

    mapKeyMetadata[pubkey.GetID()] = meta;
    return true;
}

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
bool CWallet::LoadCryptedKey(const CPubKey &vchPubKey, const std::vector<unsigned char> &vchCryptedSecret)
{
    return CCryptoKeyStore::AddCryptedKey(vchPubKey, vchCryptedSecret);
}

bool CWallet::AddCScript(const CScript& redeemScript)
{
    if (!CCryptoKeyStore::AddCScript(redeemScript))
        return false;
    if (!fFileBacked)
        return true;
    return CWalletDB(strWalletFile).WriteCScript(Hash160(redeemScript), redeemScript);
}

bool CWallet::Unlock(const SecureString& strWalletPassphrase)
{
<<<<<<< HEAD
    if (!IsLocked())
        return false;

=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    CCrypter crypter;
    CKeyingMaterial vMasterKey;

    {
        LOCK(cs_wallet);
        BOOST_FOREACH(const MasterKeyMap::value_type& pMasterKey, mapMasterKeys)
        {
            if(!crypter.SetKeyFromPassphrase(strWalletPassphrase, pMasterKey.second.vchSalt, pMasterKey.second.nDeriveIterations, pMasterKey.second.nDerivationMethod))
                return false;
            if (!crypter.Decrypt(pMasterKey.second.vchCryptedKey, vMasterKey))
<<<<<<< HEAD
                return false;
=======
                continue; // try another master key
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            if (CCryptoKeyStore::Unlock(vMasterKey))
                return true;
        }
    }
    return false;
}

bool CWallet::ChangeWalletPassphrase(const SecureString& strOldWalletPassphrase, const SecureString& strNewWalletPassphrase)
{
    bool fWasLocked = IsLocked();

    {
        LOCK(cs_wallet);
        Lock();

        CCrypter crypter;
        CKeyingMaterial vMasterKey;
        BOOST_FOREACH(MasterKeyMap::value_type& pMasterKey, mapMasterKeys)
        {
            if(!crypter.SetKeyFromPassphrase(strOldWalletPassphrase, pMasterKey.second.vchSalt, pMasterKey.second.nDeriveIterations, pMasterKey.second.nDerivationMethod))
                return false;
            if (!crypter.Decrypt(pMasterKey.second.vchCryptedKey, vMasterKey))
                return false;
            if (CCryptoKeyStore::Unlock(vMasterKey))
            {
<<<<<<< HEAD
                int64 nStartTime = GetTimeMillis();
=======
                int64_t nStartTime = GetTimeMillis();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                crypter.SetKeyFromPassphrase(strNewWalletPassphrase, pMasterKey.second.vchSalt, pMasterKey.second.nDeriveIterations, pMasterKey.second.nDerivationMethod);
                pMasterKey.second.nDeriveIterations = pMasterKey.second.nDeriveIterations * (100 / ((double)(GetTimeMillis() - nStartTime)));

                nStartTime = GetTimeMillis();
                crypter.SetKeyFromPassphrase(strNewWalletPassphrase, pMasterKey.second.vchSalt, pMasterKey.second.nDeriveIterations, pMasterKey.second.nDerivationMethod);
                pMasterKey.second.nDeriveIterations = (pMasterKey.second.nDeriveIterations + pMasterKey.second.nDeriveIterations * 100 / ((double)(GetTimeMillis() - nStartTime))) / 2;

                if (pMasterKey.second.nDeriveIterations < 25000)
                    pMasterKey.second.nDeriveIterations = 25000;

<<<<<<< HEAD
                printf("Wallet passphrase changed to an nDeriveIterations of %i\n", pMasterKey.second.nDeriveIterations);
=======
                LogPrintf("Wallet passphrase changed to an nDeriveIterations of %i\n", pMasterKey.second.nDeriveIterations);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

                if (!crypter.SetKeyFromPassphrase(strNewWalletPassphrase, pMasterKey.second.vchSalt, pMasterKey.second.nDeriveIterations, pMasterKey.second.nDerivationMethod))
                    return false;
                if (!crypter.Encrypt(vMasterKey, pMasterKey.second.vchCryptedKey))
                    return false;
                CWalletDB(strWalletFile).WriteMasterKey(pMasterKey.first, pMasterKey.second);
                if (fWasLocked)
                    Lock();
                return true;
            }
        }
    }

    return false;
}

void CWallet::SetBestChain(const CBlockLocator& loc)
{
    CWalletDB walletdb(strWalletFile);
    walletdb.WriteBestBlock(loc);
}

<<<<<<< HEAD
// This class implements an addrIncoming entry that causes pre-0.4
// clients to crash on startup if reading a private-key-encrypted wallet.
class CCorruptAddress
{
public:
    IMPLEMENT_SERIALIZE
    (
        if (nType & SER_DISK)
            READWRITE(nVersion);
    )
};

bool CWallet::SetMinVersion(enum WalletFeature nVersion, CWalletDB* pwalletdbIn, bool fExplicit)
{
=======
bool CWallet::SetMinVersion(enum WalletFeature nVersion, CWalletDB* pwalletdbIn, bool fExplicit)
{
    LOCK(cs_wallet); // nWalletVersion
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    if (nWalletVersion >= nVersion)
        return true;

    // when doing an explicit upgrade, if we pass the max version permitted, upgrade all the way
    if (fExplicit && nVersion > nWalletMaxVersion)
            nVersion = FEATURE_LATEST;

    nWalletVersion = nVersion;

    if (nVersion > nWalletMaxVersion)
        nWalletMaxVersion = nVersion;

    if (fFileBacked)
    {
        CWalletDB* pwalletdb = pwalletdbIn ? pwalletdbIn : new CWalletDB(strWalletFile);
<<<<<<< HEAD
        if (nWalletVersion >= 40000)
        {
            // Versions prior to 0.4.0 did not support the "minversion" record.
            // Use a CCorruptAddress to make them crash instead.
            CCorruptAddress corruptAddress;
            pwalletdb->WriteSetting("addrIncoming", corruptAddress);
        }
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        if (nWalletVersion > 40000)
            pwalletdb->WriteMinVersion(nWalletVersion);
        if (!pwalletdbIn)
            delete pwalletdb;
    }

    return true;
}

bool CWallet::SetMaxVersion(int nVersion)
{
<<<<<<< HEAD
=======
    LOCK(cs_wallet); // nWalletVersion, nWalletMaxVersion
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // cannot downgrade below current version
    if (nWalletVersion > nVersion)
        return false;

    nWalletMaxVersion = nVersion;

    return true;
}

<<<<<<< HEAD
=======
set<uint256> CWallet::GetConflicts(const uint256& txid) const
{
    set<uint256> result;
    AssertLockHeld(cs_wallet);

    std::map<uint256, CWalletTx>::const_iterator it = mapWallet.find(txid);
    if (it == mapWallet.end())
        return result;
    const CWalletTx& wtx = it->second;

    std::pair<TxSpends::const_iterator, TxSpends::const_iterator> range;

    BOOST_FOREACH(const CTxIn& txin, wtx.vin)
    {
        if (mapTxSpends.count(txin.prevout) <= 1)
            continue;  // No conflict if zero or one spends
        range = mapTxSpends.equal_range(txin.prevout);
        for (TxSpends::const_iterator it = range.first; it != range.second; ++it)
            result.insert(it->second);
    }
    return result;
}

void CWallet::SyncMetaData(pair<TxSpends::iterator, TxSpends::iterator> range)
{
    // We want all the wallet transactions in range to have the same metadata as
    // the oldest (smallest nOrderPos).
    // So: find smallest nOrderPos:

    int nMinOrderPos = std::numeric_limits<int>::max();
    const CWalletTx* copyFrom = NULL;
    for (TxSpends::iterator it = range.first; it != range.second; ++it)
    {
        const uint256& hash = it->second;
        int n = mapWallet[hash].nOrderPos;
        if (n < nMinOrderPos)
        {
            nMinOrderPos = n;
            copyFrom = &mapWallet[hash];
        }
    }
    // Now copy data from copyFrom to rest:
    for (TxSpends::iterator it = range.first; it != range.second; ++it)
    {
        const uint256& hash = it->second;
        CWalletTx* copyTo = &mapWallet[hash];
        if (copyFrom == copyTo) continue;
        copyTo->mapValue = copyFrom->mapValue;
        copyTo->vOrderForm = copyFrom->vOrderForm;
        // fTimeReceivedIsTxTime not copied on purpose
        // nTimeReceived not copied on purpose
        copyTo->nTimeSmart = copyFrom->nTimeSmart;
        copyTo->fFromMe = copyFrom->fFromMe;
        copyTo->strFromAccount = copyFrom->strFromAccount;
        // nOrderPos not copied on purpose
        // cached members not copied on purpose
    }
}

// Outpoint is spent if any non-conflicted transaction
// spends it:
bool CWallet::IsSpent(const uint256& hash, unsigned int n) const
{
    const COutPoint outpoint(hash, n);
    pair<TxSpends::const_iterator, TxSpends::const_iterator> range;
    range = mapTxSpends.equal_range(outpoint);

    for (TxSpends::const_iterator it = range.first; it != range.second; ++it)
    {
        const uint256& wtxid = it->second;
        std::map<uint256, CWalletTx>::const_iterator mit = mapWallet.find(wtxid);
        if (mit != mapWallet.end() && mit->second.GetDepthInMainChain() >= 0)
            return true; // Spent
    }
    return false;
}

void CWallet::AddToSpends(const COutPoint& outpoint, const uint256& wtxid)
{
    mapTxSpends.insert(make_pair(outpoint, wtxid));

    pair<TxSpends::iterator, TxSpends::iterator> range;
    range = mapTxSpends.equal_range(outpoint);
    SyncMetaData(range);
}


void CWallet::AddToSpends(const uint256& wtxid)
{
    assert(mapWallet.count(wtxid));
    CWalletTx& thisTx = mapWallet[wtxid];
    if (thisTx.IsCoinBase()) // Coinbases don't spend anything!
        return;

    BOOST_FOREACH(const CTxIn& txin, thisTx.vin)
        AddToSpends(txin.prevout, wtxid);
}

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
bool CWallet::EncryptWallet(const SecureString& strWalletPassphrase)
{
    if (IsCrypted())
        return false;

    CKeyingMaterial vMasterKey;
    RandAddSeedPerfmon();

    vMasterKey.resize(WALLET_CRYPTO_KEY_SIZE);
    RAND_bytes(&vMasterKey[0], WALLET_CRYPTO_KEY_SIZE);

    CMasterKey kMasterKey;

    RandAddSeedPerfmon();
    kMasterKey.vchSalt.resize(WALLET_CRYPTO_SALT_SIZE);
    RAND_bytes(&kMasterKey.vchSalt[0], WALLET_CRYPTO_SALT_SIZE);

    CCrypter crypter;
<<<<<<< HEAD
    int64 nStartTime = GetTimeMillis();
=======
    int64_t nStartTime = GetTimeMillis();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    crypter.SetKeyFromPassphrase(strWalletPassphrase, kMasterKey.vchSalt, 25000, kMasterKey.nDerivationMethod);
    kMasterKey.nDeriveIterations = 2500000 / ((double)(GetTimeMillis() - nStartTime));

    nStartTime = GetTimeMillis();
    crypter.SetKeyFromPassphrase(strWalletPassphrase, kMasterKey.vchSalt, kMasterKey.nDeriveIterations, kMasterKey.nDerivationMethod);
    kMasterKey.nDeriveIterations = (kMasterKey.nDeriveIterations + kMasterKey.nDeriveIterations * 100 / ((double)(GetTimeMillis() - nStartTime))) / 2;

    if (kMasterKey.nDeriveIterations < 25000)
        kMasterKey.nDeriveIterations = 25000;

<<<<<<< HEAD
    printf("Encrypting Wallet with an nDeriveIterations of %i\n", kMasterKey.nDeriveIterations);
=======
    LogPrintf("Encrypting Wallet with an nDeriveIterations of %i\n", kMasterKey.nDeriveIterations);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    if (!crypter.SetKeyFromPassphrase(strWalletPassphrase, kMasterKey.vchSalt, kMasterKey.nDeriveIterations, kMasterKey.nDerivationMethod))
        return false;
    if (!crypter.Encrypt(vMasterKey, kMasterKey.vchCryptedKey))
        return false;

    {
        LOCK(cs_wallet);
        mapMasterKeys[++nMasterKeyMaxID] = kMasterKey;
        if (fFileBacked)
        {
            pwalletdbEncryption = new CWalletDB(strWalletFile);
            if (!pwalletdbEncryption->TxnBegin())
                return false;
            pwalletdbEncryption->WriteMasterKey(nMasterKeyMaxID, kMasterKey);
        }

        if (!EncryptKeys(vMasterKey))
        {
            if (fFileBacked)
                pwalletdbEncryption->TxnAbort();
            exit(1); //We now probably have half of our keys encrypted in memory, and half not...die and let the user reload their unencrypted wallet.
        }

        // Encryption was introduced in version 0.4.0
        SetMinVersion(FEATURE_WALLETCRYPT, pwalletdbEncryption, true);

        if (fFileBacked)
        {
            if (!pwalletdbEncryption->TxnCommit())
                exit(1); //We now have keys encrypted in memory, but no on disk...die to avoid confusion and let the user reload their unencrypted wallet.

            delete pwalletdbEncryption;
            pwalletdbEncryption = NULL;
        }

        Lock();
        Unlock(strWalletPassphrase);
        NewKeyPool();
        Lock();

        // Need to completely rewrite the wallet file; if we don't, bdb might keep
        // bits of the unencrypted private key in slack space in the database file.
        CDB::Rewrite(strWalletFile);

    }
    NotifyStatusChanged(this);

    return true;
}

<<<<<<< HEAD
int64 CWallet::IncOrderPosNext(CWalletDB *pwalletdb)
{
    int64 nRet = nOrderPosNext++;
=======
int64_t CWallet::IncOrderPosNext(CWalletDB *pwalletdb)
{
    AssertLockHeld(cs_wallet); // nOrderPosNext
    int64_t nRet = nOrderPosNext++;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    if (pwalletdb) {
        pwalletdb->WriteOrderPosNext(nOrderPosNext);
    } else {
        CWalletDB(strWalletFile).WriteOrderPosNext(nOrderPosNext);
    }
    return nRet;
}

CWallet::TxItems CWallet::OrderedTxItems(std::list<CAccountingEntry>& acentries, std::string strAccount)
{
<<<<<<< HEAD
=======
    AssertLockHeld(cs_wallet); // mapWallet
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    CWalletDB walletdb(strWalletFile);

    // First: get all CWalletTx and CAccountingEntry into a sorted-by-order multimap.
    TxItems txOrdered;

    // Note: maintaining indices in the database of (account,time) --> txid and (account, time) --> acentry
    // would make this much faster for applications that do this a lot.
    for (map<uint256, CWalletTx>::iterator it = mapWallet.begin(); it != mapWallet.end(); ++it)
    {
        CWalletTx* wtx = &((*it).second);
        txOrdered.insert(make_pair(wtx->nOrderPos, TxPair(wtx, (CAccountingEntry*)0)));
    }
    acentries.clear();
    walletdb.ListAccountCreditDebit(strAccount, acentries);
    BOOST_FOREACH(CAccountingEntry& entry, acentries)
    {
        txOrdered.insert(make_pair(entry.nOrderPos, TxPair((CWalletTx*)0, &entry)));
    }

    return txOrdered;
}

<<<<<<< HEAD
void CWallet::WalletUpdateSpent(const CTransaction &tx)
{
    // Anytime a signature is successfully verified, it's proof the outpoint is spent.
    // Update the wallet spent flag if it doesn't know due to wallet.dat being
    // restored from backup or the user making copies of wallet.dat.
    {
        LOCK(cs_wallet);
        BOOST_FOREACH(const CTxIn& txin, tx.vin)
        {
            map<uint256, CWalletTx>::iterator mi = mapWallet.find(txin.prevout.hash);
            if (mi != mapWallet.end())
            {
                CWalletTx& wtx = (*mi).second;
                if (txin.prevout.n >= wtx.vout.size())
                    printf("WalletUpdateSpent: bad wtx %s\n", wtx.GetHash().ToString().c_str());
                else if (!wtx.IsSpent(txin.prevout.n) && IsMine(wtx.vout[txin.prevout.n]))
                {
                    printf("WalletUpdateSpent found spent coin %sbc %s\n", FormatMoney(wtx.GetCredit()).c_str(), wtx.GetHash().ToString().c_str());
                    wtx.MarkSpent(txin.prevout.n);
                    wtx.WriteToDisk();
                    NotifyTransactionChanged(this, txin.prevout.hash, CT_UPDATED);
                }
            }
        }
    }
}

=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
void CWallet::MarkDirty()
{
    {
        LOCK(cs_wallet);
        BOOST_FOREACH(PAIRTYPE(const uint256, CWalletTx)& item, mapWallet)
            item.second.MarkDirty();
    }
}

<<<<<<< HEAD
bool CWallet::AddToWallet(const CWalletTx& wtxIn)
{
    uint256 hash = wtxIn.GetHash();
=======
bool CWallet::AddToWallet(const CWalletTx& wtxIn, bool fFromLoadWallet)
{
    uint256 hash = wtxIn.GetHash();

    if (fFromLoadWallet)
    {
        mapWallet[hash] = wtxIn;
        AddToSpends(hash);
    }
    else
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        LOCK(cs_wallet);
        // Inserts only if not already there, returns tx inserted or tx found
        pair<map<uint256, CWalletTx>::iterator, bool> ret = mapWallet.insert(make_pair(hash, wtxIn));
        CWalletTx& wtx = (*ret.first).second;
        wtx.BindWallet(this);
        bool fInsertedNew = ret.second;
        if (fInsertedNew)
        {
            wtx.nTimeReceived = GetAdjustedTime();
            wtx.nOrderPos = IncOrderPosNext();

            wtx.nTimeSmart = wtx.nTimeReceived;
            if (wtxIn.hashBlock != 0)
            {
                if (mapBlockIndex.count(wtxIn.hashBlock))
                {
                    unsigned int latestNow = wtx.nTimeReceived;
                    unsigned int latestEntry = 0;
                    {
                        // Tolerate times up to the last timestamp in the wallet not more than 5 minutes into the future
<<<<<<< HEAD
                        int64 latestTolerated = latestNow + 300;
=======
                        int64_t latestTolerated = latestNow + 300;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                        std::list<CAccountingEntry> acentries;
                        TxItems txOrdered = OrderedTxItems(acentries);
                        for (TxItems::reverse_iterator it = txOrdered.rbegin(); it != txOrdered.rend(); ++it)
                        {
                            CWalletTx *const pwtx = (*it).second.first;
                            if (pwtx == &wtx)
                                continue;
                            CAccountingEntry *const pacentry = (*it).second.second;
<<<<<<< HEAD
                            int64 nSmartTime;
=======
                            int64_t nSmartTime;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                            if (pwtx)
                            {
                                nSmartTime = pwtx->nTimeSmart;
                                if (!nSmartTime)
                                    nSmartTime = pwtx->nTimeReceived;
                            }
                            else
                                nSmartTime = pacentry->nTime;
                            if (nSmartTime <= latestTolerated)
                            {
                                latestEntry = nSmartTime;
                                if (nSmartTime > latestNow)
                                    latestNow = nSmartTime;
                                break;
                            }
                        }
                    }

                    unsigned int& blocktime = mapBlockIndex[wtxIn.hashBlock]->nTime;
                    wtx.nTimeSmart = std::max(latestEntry, std::min(blocktime, latestNow));
                }
                else
<<<<<<< HEAD
                    printf("AddToWallet() : found %s in block %s not in index\n",
                           wtxIn.GetHash().ToString().c_str(),
                           wtxIn.hashBlock.ToString().c_str());
            }
=======
                    LogPrintf("AddToWallet() : found %s in block %s not in index\n",
                             wtxIn.GetHash().ToString(),
                             wtxIn.hashBlock.ToString());
            }
            AddToSpends(hash);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }

        bool fUpdated = false;
        if (!fInsertedNew)
        {
            // Merge
            if (wtxIn.hashBlock != 0 && wtxIn.hashBlock != wtx.hashBlock)
            {
                wtx.hashBlock = wtxIn.hashBlock;
                fUpdated = true;
            }
            if (wtxIn.nIndex != -1 && (wtxIn.vMerkleBranch != wtx.vMerkleBranch || wtxIn.nIndex != wtx.nIndex))
            {
                wtx.vMerkleBranch = wtxIn.vMerkleBranch;
                wtx.nIndex = wtxIn.nIndex;
                fUpdated = true;
            }
            if (wtxIn.fFromMe && wtxIn.fFromMe != wtx.fFromMe)
            {
                wtx.fFromMe = wtxIn.fFromMe;
                fUpdated = true;
            }
<<<<<<< HEAD
            fUpdated |= wtx.UpdateSpent(wtxIn.vfSpent);
        }

        //// debug print
        printf("AddToWallet %s  %s%s\n", wtxIn.GetHash().ToString().c_str(), (fInsertedNew ? "new" : ""), (fUpdated ? "update" : ""));
=======
        }

        //// debug print
        LogPrintf("AddToWallet %s  %s%s\n", wtxIn.GetHash().ToString(), (fInsertedNew ? "new" : ""), (fUpdated ? "update" : ""));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

        // Write to disk
        if (fInsertedNew || fUpdated)
            if (!wtx.WriteToDisk())
                return false;
<<<<<<< HEAD
#ifndef QT_GUI
        // If default receiving address gets used, replace it with a new one
        if (vchDefaultKey.IsValid()) {
            CScript scriptDefaultKey;
            scriptDefaultKey.SetDestination(vchDefaultKey.GetID());
            BOOST_FOREACH(const CTxOut& txout, wtx.vout)
            {
                if (txout.scriptPubKey == scriptDefaultKey)
                {
                    CPubKey newDefaultKey;
                    if (GetKeyFromPool(newDefaultKey, false))
                    {
                        SetDefaultKey(newDefaultKey);
                        SetAddressBookName(vchDefaultKey.GetID(), "");
                    }
                }
            }
        }
#endif
        // since AddToWallet is called directly for self-originating transactions, check for consumption of own coins
        WalletUpdateSpent(wtx);
=======

        // Break debit/credit balance caches:
        wtx.MarkDirty();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

        // Notify UI of new or updated transaction
        NotifyTransactionChanged(this, hash, fInsertedNew ? CT_NEW : CT_UPDATED);

        // notify an external script when a wallet transaction comes in or is updated
        std::string strCmd = GetArg("-walletnotify", "");

        if ( !strCmd.empty())
        {
            boost::replace_all(strCmd, "%s", wtxIn.GetHash().GetHex());
            boost::thread t(runCommand, strCmd); // thread runs free
        }

    }
    return true;
}

// Add a transaction to the wallet, or update it.
// pblock is optional, but should be provided if the transaction is known to be in a block.
// If fUpdate is true, existing transactions will be updated.
<<<<<<< HEAD
bool CWallet::AddToWalletIfInvolvingMe(const uint256 &hash, const CTransaction& tx, const CBlock* pblock, bool fUpdate, bool fFindBlock)
=======
bool CWallet::AddToWalletIfInvolvingMe(const uint256 &hash, const CTransaction& tx, const CBlock* pblock, bool fUpdate)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    {
        LOCK(cs_wallet);
        bool fExisted = mapWallet.count(hash);
        if (fExisted && !fUpdate) return false;
        if (fExisted || IsMine(tx) || IsFromMe(tx))
        {
            CWalletTx wtx(this,tx);
            // Get merkle branch if transaction was found in a block
            if (pblock)
                wtx.SetMerkleBranch(pblock);
            return AddToWallet(wtx);
        }
<<<<<<< HEAD
        else
            WalletUpdateSpent(tx);
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
    return false;
}

<<<<<<< HEAD
bool CWallet::EraseFromWallet(uint256 hash)
{
    if (!fFileBacked)
        return false;
=======
void CWallet::SyncTransaction(const uint256 &hash, const CTransaction& tx, const CBlock* pblock)
{
    AddToWalletIfInvolvingMe(hash, tx, pblock, true);

    if (mapWallet.count(hash) == 0)
        return; // Not one of ours

    // If a transaction changes 'conflicted' state, that changes the balance
    // available of the outputs it spends. So force those to be
    // recomputed, also:
    BOOST_FOREACH(const CTxIn& txin, tx.vin)
    {
        if (mapWallet.count(txin.prevout.hash))
            mapWallet[txin.prevout.hash].MarkDirty();
    }
}

void CWallet::EraseFromWallet(const uint256 &hash)
{
    if (!fFileBacked)
        return;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        LOCK(cs_wallet);
        if (mapWallet.erase(hash))
            CWalletDB(strWalletFile).EraseTx(hash);
    }
<<<<<<< HEAD
    return true;
=======
    return;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}


bool CWallet::IsMine(const CTxIn &txin) const
{
    {
        LOCK(cs_wallet);
        map<uint256, CWalletTx>::const_iterator mi = mapWallet.find(txin.prevout.hash);
        if (mi != mapWallet.end())
        {
            const CWalletTx& prev = (*mi).second;
            if (txin.prevout.n < prev.vout.size())
                if (IsMine(prev.vout[txin.prevout.n]))
                    return true;
        }
    }
    return false;
}

<<<<<<< HEAD
int64 CWallet::GetDebit(const CTxIn &txin) const
=======
int64_t CWallet::GetDebit(const CTxIn &txin) const
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    {
        LOCK(cs_wallet);
        map<uint256, CWalletTx>::const_iterator mi = mapWallet.find(txin.prevout.hash);
        if (mi != mapWallet.end())
        {
            const CWalletTx& prev = (*mi).second;
            if (txin.prevout.n < prev.vout.size())
                if (IsMine(prev.vout[txin.prevout.n]))
                    return prev.vout[txin.prevout.n].nValue;
        }
    }
    return 0;
}

<<<<<<< HEAD
bool CWallet::HasAddress(const CTxDestination &txDest) const
{
	bool	hasAddress = false;
	
	LOCK(cs_wallet);
	if (mapAddressBook.count(txDest))
		hasAddress = true;
	
	return hasAddress;
}

=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
bool CWallet::IsChange(const CTxOut& txout) const
{
    CTxDestination address;

    // TODO: fix handling of 'change' outputs. The assumption is that any
    // payment to a TX_PUBKEYHASH that is mine but isn't in the address book
    // is change. That assumption is likely to break when we implement multisignature
    // wallets that return change back into a multi-signature-protected address;
    // a better way of identifying which outputs are 'the send' and which are
    // 'the change' will need to be implemented (maybe extend CWalletTx to remember
    // which output, if any, was change).
    if (ExtractDestination(txout.scriptPubKey, address) && ::IsMine(*this, address))
    {
        LOCK(cs_wallet);
        if (!mapAddressBook.count(address))
            return true;
    }
    return false;
}

<<<<<<< HEAD
int64 CWalletTx::GetTxTime() const
{
    int64 n = nTimeSmart;
=======
#pragma mark - CWalletTx

bool CWalletTx::IsTrusted() const
{
    // Quick answer in most cases
    if (!IsFinalTx(*this))
        return false;
    int nDepth = GetDepthInMainChain();
    if (nDepth >= 1)
        return true;
    if (nDepth < 0)
        return false;
    if (!bSpendZeroConfChange || !IsFromMe()) // using wtx's cached debit
        return false;
    
    // Trusted if all inputs are from us and are in the mempool:
    BOOST_FOREACH(const CTxIn& txin, vin)
    {
        // Transactions not sent by us: not trusted
        const CWalletTx* parent = pwallet->GetWalletTx(txin.prevout.hash);
        if (parent == NULL)
            return false;
        const CTxOut& parentOut = parent->vout[txin.prevout.n];
        if (!pwallet->IsMine(parentOut))
            return false;
    }
    return true;
}

int64_t CWalletTx::GetAvailableCredit(bool fUseCache) const
{
    if (pwallet == 0)
        return 0;
    
    // Must wait until coinbase is safely deep enough in the chain before valuing it
    if (IsCoinBase() && GetBlocksToMaturity() > 0)
        return 0;
    
    if (fUseCache && fAvailableCreditCached)
        return nAvailableCreditCached;
    
    int64_t nCredit = 0;
    uint256 hashTx = GetHash();
    for (unsigned int i = 0; i < vout.size(); i++)
    {
        if (!pwallet->IsSpent(hashTx, i))
        {
            const CTxOut &txout = vout[i];
            nCredit += pwallet->GetCredit(txout);
            if (!MoneyRange(nCredit))
                throw std::runtime_error("CWalletTx::GetAvailableCredit() : value out of range");
        }
    }
    
    nAvailableCreditCached = nCredit;
    fAvailableCreditCached = true;
    return nCredit;
}


int64_t CWalletTx::GetChange() const
{
    if (fChangeCached)
        return nChangeCached;
    nChangeCached = pwallet->GetChange(*this);
    fChangeCached = true;
    return nChangeCached;
}


int64_t CWalletTx::GetCredit(bool fUseCache) const
{
    // Must wait until coinbase is safely deep enough in the chain before valuing it
    if (IsCoinBase() && GetBlocksToMaturity() > 0)
        return 0;
    
    // GetBalance can assume transactions in mapWallet won't change
    if (fUseCache && fCreditCached)
        return nCreditCached;
    nCreditCached = pwallet->GetCredit(*this);
    fCreditCached = true;
    return nCreditCached;
}

int64_t CWalletTx::GetImmatureCredit(bool fUseCache) const
{
    if (IsCoinBase() && GetBlocksToMaturity() > 0 && IsInMainChain())
    {
        if (fUseCache && fImmatureCreditCached)
            return nImmatureCreditCached;
        nImmatureCreditCached = pwallet->GetCredit(*this);
        fImmatureCreditCached = true;
        return nImmatureCreditCached;
    }
    
    return 0;
}

int64_t CWalletTx::GetDebit() const
{
    if (vin.empty())
        return 0;
    if (fDebitCached)
        return nDebitCached;
    nDebitCached = pwallet->GetDebit(*this);
    fDebitCached = true;
    return nDebitCached;
}


int64_t CWalletTx::GetTxTime() const
{
    int64_t n = nTimeSmart;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    return n ? n : nTimeReceived;
}

int CWalletTx::GetRequestCount() const
{
    // Returns -1 if it wasn't being tracked
    int nRequests = -1;
    {
        LOCK(pwallet->cs_wallet);
        if (IsCoinBase())
        {
            // Generated block
            if (hashBlock != 0)
            {
                map<uint256, int>::const_iterator mi = pwallet->mapRequestCount.find(hashBlock);
                if (mi != pwallet->mapRequestCount.end())
                    nRequests = (*mi).second;
            }
        }
        else
        {
            // Did anyone request this transaction?
            map<uint256, int>::const_iterator mi = pwallet->mapRequestCount.find(GetHash());
            if (mi != pwallet->mapRequestCount.end())
            {
                nRequests = (*mi).second;

                // How about the block it's in?
                if (nRequests == 0 && hashBlock != 0)
                {
                    map<uint256, int>::const_iterator mi = pwallet->mapRequestCount.find(hashBlock);
                    if (mi != pwallet->mapRequestCount.end())
                        nRequests = (*mi).second;
                    else
                        nRequests = 1; // If it's in someone else's block it must have got out
                }
            }
        }
    }
    return nRequests;
}

<<<<<<< HEAD
void CWalletTx::GetAmounts(list<pair<CTxDestination, int64> >& listReceived,
                           list<pair<CTxDestination, int64> >& listSent, int64& nFee, string& strSentAccount) const
{
	CTxDestination	address;
	
=======
void CWalletTx::GetAmounts(list<pair<CTxDestination, int64_t> >& listReceived,
                           list<pair<CTxDestination, int64_t> >& listSent, int64_t& nFee, string& strSentAccount) const
{
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    nFee = 0;
    listReceived.clear();
    listSent.clear();
    strSentAccount = strFromAccount;

    // Compute fee:
<<<<<<< HEAD
    int64 nDebit = GetDebit();
    if (nDebit > 0) // debit>0 means we signed/sent this transaction
    {
        int64 nValueOut = GetValueOut();
=======
    int64_t nDebit = GetDebit();
    if (nDebit > 0) // debit>0 means we signed/sent this transaction
    {
        int64_t nValueOut = GetValueOut();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        nFee = nDebit - nValueOut;
    }

    // Sent/received.
<<<<<<< HEAD
	for (unsigned int i = 0; i < vout.size(); i++) {
		const CTxOut	&txout = vout[i];
		bool			isMine = false;
		bool			warnUnkownTX = false;
		
		warnUnkownTX = !ExtractDestinationAndMine(*pwallet, txout.scriptPubKey, address, &isMine);
		if (warnUnkownTX) {
            printf("CWalletTx::GetAmounts: Unknown transaction type found, txid %s\n", this->GetHash().ToString().c_str());
        }

		if (nDebit > 0) {
			if (isMine && !pwallet->HasAddress(address))			// Don't report 'change' txouts
				continue;

            listSent.push_back(make_pair(address, txout.nValue));
		}

        if (isMine)
            listReceived.push_back(make_pair(address, txout.nValue));
    }
}

void CWalletTx::GetAccountAmounts(const string& strAccount, int64& nReceived,
                                  int64& nSent, int64& nFee) const
{
    nReceived = nSent = nFee = 0;

    int64 allFee;
    string strSentAccount;
    list<pair<CTxDestination, int64> > listReceived;
    list<pair<CTxDestination, int64> > listSent;
=======
    BOOST_FOREACH(const CTxOut& txout, vout)
    {
        bool fIsMine;
        // Only need to handle txouts if AT LEAST one of these is true:
        //   1) they debit from us (sent)
        //   2) the output is to us (received)
        if (nDebit > 0)
        {
            // Don't report 'change' txouts
            if (pwallet->IsChange(txout))
                continue;
            fIsMine = pwallet->IsMine(txout);
        }
        else if (!(fIsMine = pwallet->IsMine(txout)))
            continue;

        // In either case, we need to get the destination address
        CTxDestination address;
        if (!ExtractDestination(txout.scriptPubKey, address))
        {
            LogPrintf("CWalletTx::GetAmounts: Unknown transaction type found, txid %s\n",
                     this->GetHash().ToString());
            address = CNoDestination();
        }

        // If we are debited by the transaction, add the output as a "sent" entry
        if (nDebit > 0)
            listSent.push_back(make_pair(address, txout.nValue));

        // If we are receiving the output, add it as a "received" entry
        if (fIsMine)
            listReceived.push_back(make_pair(address, txout.nValue));
    }

}

void CWalletTx::GetAccountAmounts(const string& strAccount, int64_t& nReceived,
                                  int64_t& nSent, int64_t& nFee) const
{
    nReceived = nSent = nFee = 0;

    int64_t allFee;
    string strSentAccount;
    list<pair<CTxDestination, int64_t> > listReceived;
    list<pair<CTxDestination, int64_t> > listSent;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    GetAmounts(listReceived, listSent, allFee, strSentAccount);

    if (strAccount == strSentAccount)
    {
<<<<<<< HEAD
        BOOST_FOREACH(const PAIRTYPE(CTxDestination,int64)& s, listSent)
=======
        BOOST_FOREACH(const PAIRTYPE(CTxDestination,int64_t)& s, listSent)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            nSent += s.second;
        nFee = allFee;
    }
    {
        LOCK(pwallet->cs_wallet);
<<<<<<< HEAD
        BOOST_FOREACH(const PAIRTYPE(CTxDestination,int64)& r, listReceived)
        {
            if (pwallet->mapAddressBook.count(r.first))
            {
                map<CTxDestination, string>::const_iterator mi = pwallet->mapAddressBook.find(r.first);
                if (mi != pwallet->mapAddressBook.end() && (*mi).second == strAccount)
=======
        BOOST_FOREACH(const PAIRTYPE(CTxDestination,int64_t)& r, listReceived)
        {
            if (pwallet->mapAddressBook.count(r.first))
            {
                map<CTxDestination, CAddressBookData>::const_iterator mi = pwallet->mapAddressBook.find(r.first);
                if (mi != pwallet->mapAddressBook.end() && (*mi).second.name == strAccount)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    nReceived += r.second;
            }
            else if (strAccount.empty())
            {
                nReceived += r.second;
            }
        }
    }
}

<<<<<<< HEAD
void CWalletTx::AddSupportingTransactions()
{
    vtxPrev.clear();

    const int COPY_DEPTH = 3;
    if (SetMerkleBranch() < COPY_DEPTH)
    {
        vector<uint256> vWorkQueue;
        BOOST_FOREACH(const CTxIn& txin, vin)
            vWorkQueue.push_back(txin.prevout.hash);

        {
            LOCK(pwallet->cs_wallet);
            map<uint256, const CMerkleTx*> mapWalletPrev;
            set<uint256> setAlreadyDone;
            for (unsigned int i = 0; i < vWorkQueue.size(); i++)
            {
                uint256 hash = vWorkQueue[i];
                if (setAlreadyDone.count(hash))
                    continue;
                setAlreadyDone.insert(hash);

                CMerkleTx tx;
                map<uint256, CWalletTx>::const_iterator mi = pwallet->mapWallet.find(hash);
                if (mi != pwallet->mapWallet.end())
                {
                    tx = (*mi).second;
                    BOOST_FOREACH(const CMerkleTx& txWalletPrev, (*mi).second.vtxPrev)
                        mapWalletPrev[txWalletPrev.GetHash()] = &txWalletPrev;
                }
                else if (mapWalletPrev.count(hash))
                {
                    tx = *mapWalletPrev[hash];
                }
                else
                {
                    continue;
                }

                int nDepth = tx.SetMerkleBranch();
                vtxPrev.push_back(tx);

                if (nDepth < COPY_DEPTH)
                {
                    BOOST_FOREACH(const CTxIn& txin, tx.vin)
                        vWorkQueue.push_back(txin.prevout.hash);
                }
            }
        }
    }

    reverse(vtxPrev.begin(), vtxPrev.end());
}
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

bool CWalletTx::WriteToDisk()
{
    return CWalletDB(pwallet->strWalletFile).WriteTx(GetHash(), *this);
}

// Scan the block chain (starting in pindexStart) for transactions
// from or to us. If fUpdate is true, found transactions that already
// exist in the wallet will be updated.
int CWallet::ScanForWalletTransactions(CBlockIndex* pindexStart, bool fUpdate)
{
    int ret = 0;
<<<<<<< HEAD
=======
    int64_t nNow = GetTime();
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    CBlockIndex* pindex = pindexStart;
    {
        LOCK(cs_wallet);
        while (pindex)
        {
<<<<<<< HEAD
            CBlock block;
            block.ReadFromDisk(pindex);
=======
            // no need to read and scan block, if block was created before
            // our wallet birthday (as adjusted for block time variability)
            if (nTimeFirstKey && (pindex->nTime < (nTimeFirstKey - 7200))) {
                pindex = chainActive.Next(pindex);
                continue;
            }

            CBlock block;
            ReadBlockFromDisk(block, pindex);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            BOOST_FOREACH(CTransaction& tx, block.vtx)
            {
                if (AddToWalletIfInvolvingMe(tx.GetHash(), tx, &block, fUpdate))
                    ret++;
            }
<<<<<<< HEAD
            pindex = pindex->pnext;
=======
            pindex = chainActive.Next(pindex);
            if (GetTime() >= nNow + 60) {
                nNow = GetTime();
                LogPrintf("Still rescanning. At block %d. Progress=%f\n", pindex->nHeight, Checkpoints::GuessVerificationProgress(pindex));
            }
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
    }
    return ret;
}

void CWallet::ReacceptWalletTransactions()
{
<<<<<<< HEAD
    bool fRepeat = true;
    while (fRepeat)
    {
        LOCK(cs_wallet);
        fRepeat = false;
        bool fMissing = false;
        BOOST_FOREACH(PAIRTYPE(const uint256, CWalletTx)& item, mapWallet)
        {
            CWalletTx& wtx = item.second;
            if (wtx.IsCoinBase() && wtx.IsSpent(0))
                continue;

            CCoins coins;
            bool fUpdated = false;
            bool fFound = pcoinsTip->GetCoins(wtx.GetHash(), coins);
            if (fFound || wtx.GetDepthInMainChain() > 0)
            {
                // Update fSpent if a tx got spent somewhere else by a copy of wallet.dat
                for (unsigned int i = 0; i < wtx.vout.size(); i++)
                {
                    if (wtx.IsSpent(i))
                        continue;
                    if ((i >= coins.vout.size() || coins.vout[i].IsNull()) && IsMine(wtx.vout[i]))
                    {
                        wtx.MarkSpent(i);
                        fUpdated = true;
                        fMissing = true;
                    }
                }
                if (fUpdated)
                {
                    printf("ReacceptWalletTransactions found spent coin %sbc %s\n", FormatMoney(wtx.GetCredit()).c_str(), wtx.GetHash().ToString().c_str());
                    wtx.MarkDirty();
                    wtx.WriteToDisk();
                }
            }
            else
            {
                // Re-accept any txes of ours that aren't already in a block
                if (!wtx.IsCoinBase())
                    wtx.AcceptWalletTransaction(false);
            }
        }
        if (fMissing)
        {
            // TODO: optimize this to scan just part of the block chain?
            if (ScanForWalletTransactions(pindexGenesisBlock))
                fRepeat = true;  // Found missing transactions: re-do re-accept.
=======
    LOCK(cs_wallet);
    BOOST_FOREACH(PAIRTYPE(const uint256, CWalletTx)& item, mapWallet)
    {
        const uint256& wtxid = item.first;
        CWalletTx& wtx = item.second;
        assert(wtx.GetHash() == wtxid);

        int nDepth = wtx.GetDepthInMainChain();

        if (!wtx.IsCoinBase() && nDepth < 0)
        {
            // Try to add to memory pool
            LOCK(mempool.cs);
            wtx.AcceptToMemoryPool(false);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
    }
}

void CWalletTx::RelayWalletTransaction()
{
<<<<<<< HEAD
    BOOST_FOREACH(const CMerkleTx& tx, vtxPrev)
    {
        // Important: versions of bitcoin before 0.8.6 had a bug that inserted
        // empty transactions into the vtxPrev, which will cause the node to be
        // banned when retransmitted, hence the check for !tx.vin.empty()
        if (!tx.IsCoinBase() && !tx.vin.empty())
            if (tx.GetDepthInMainChain() == 0)
                RelayTransaction((CTransaction)tx, tx.GetHash());
    }
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    if (!IsCoinBase())
    {
        if (GetDepthInMainChain() == 0) {
            uint256 hash = GetHash();
<<<<<<< HEAD
            printf("Relaying wtx %s\n", hash.ToString().c_str());
=======
            LogPrintf("Relaying wtx %s\n", hash.ToString());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            RelayTransaction((CTransaction)*this, hash);
        }
    }
}

<<<<<<< HEAD
=======
set<uint256> CWalletTx::GetConflicts() const
{
    set<uint256> result;
    if (pwallet != NULL)
    {
        uint256 myHash = GetHash();
        result = pwallet->GetConflicts(myHash);
        result.erase(myHash);
    }
    return result;
}

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
void CWallet::ResendWalletTransactions()
{
    // Do this infrequently and randomly to avoid giving away
    // that these are our transactions.
<<<<<<< HEAD
    static int64 nNextTime;
    if (GetTime() < nNextTime)
        return;
    bool fFirst = (nNextTime == 0);
    nNextTime = GetTime() + GetRand(30 * 60);
=======
    if (GetTime() < nNextResend)
        return;
    bool fFirst = (nNextResend == 0);
    nNextResend = GetTime() + GetRand(30 * 60);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    if (fFirst)
        return;

    // Only do it if there's been a new block since last time
<<<<<<< HEAD
    static int64 nLastTime;
    if (nTimeBestReceived < nLastTime)
        return;
    nLastTime = GetTime();

    // Rebroadcast any of our txes that aren't in a block yet
    printf("ResendWalletTransactions()\n");
=======
    if (nTimeBestReceived < nLastResend)
        return;
    nLastResend = GetTime();

    // Rebroadcast any of our txes that aren't in a block yet
    LogPrintf("ResendWalletTransactions()\n");
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        LOCK(cs_wallet);
        // Sort them in chronological order
        multimap<unsigned int, CWalletTx*> mapSorted;
        BOOST_FOREACH(PAIRTYPE(const uint256, CWalletTx)& item, mapWallet)
        {
            CWalletTx& wtx = item.second;
            // Don't rebroadcast until it's had plenty of time that
            // it should have gotten in already by now.
<<<<<<< HEAD
            if (nTimeBestReceived - (int64)wtx.nTimeReceived > 5 * 60)
=======
            if (nTimeBestReceived - (int64_t)wtx.nTimeReceived > 5 * 60)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                mapSorted.insert(make_pair(wtx.nTimeReceived, &wtx));
        }
        BOOST_FOREACH(PAIRTYPE(const unsigned int, CWalletTx*)& item, mapSorted)
        {
            CWalletTx& wtx = *item.second;
            wtx.RelayWalletTransaction();
        }
    }
}






//////////////////////////////////////////////////////////////////////////////
//
// Actions
//


<<<<<<< HEAD
int64 CWallet::GetBalance() const
{
    int64 nTotal = 0;
=======
int64_t CWallet::GetBalance() const
{
    int64_t nTotal = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        LOCK(cs_wallet);
        for (map<uint256, CWalletTx>::const_iterator it = mapWallet.begin(); it != mapWallet.end(); ++it)
        {
            const CWalletTx* pcoin = &(*it).second;
<<<<<<< HEAD
            if (pcoin->IsConfirmed())
=======
            if (pcoin->IsTrusted())
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                nTotal += pcoin->GetAvailableCredit();
        }
    }

    return nTotal;
}

<<<<<<< HEAD
int64 CWallet::GetUnconfirmedBalance() const
{
    int64 nTotal = 0;
=======
int64_t CWallet::GetUnconfirmedBalance() const
{
    int64_t nTotal = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        LOCK(cs_wallet);
        for (map<uint256, CWalletTx>::const_iterator it = mapWallet.begin(); it != mapWallet.end(); ++it)
        {
            const CWalletTx* pcoin = &(*it).second;
<<<<<<< HEAD
            if (!pcoin->IsFinal() || !pcoin->IsConfirmed())
=======
            if (!IsFinalTx(*pcoin) || (!pcoin->IsTrusted() && pcoin->GetDepthInMainChain() == 0))
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                nTotal += pcoin->GetAvailableCredit();
        }
    }
    return nTotal;
}

<<<<<<< HEAD
int64 CWallet::GetImmatureBalance() const
{
    int64 nTotal = 0;
=======
int64_t CWallet::GetImmatureBalance() const
{
    int64_t nTotal = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        LOCK(cs_wallet);
        for (map<uint256, CWalletTx>::const_iterator it = mapWallet.begin(); it != mapWallet.end(); ++it)
        {
            const CWalletTx* pcoin = &(*it).second;
            nTotal += pcoin->GetImmatureCredit();
        }
    }
    return nTotal;
}

// populate vCoins with vector of spendable COutputs
void CWallet::AvailableCoins(vector<COutput>& vCoins, bool fOnlyConfirmed, const CCoinControl *coinControl) const
{
    vCoins.clear();

    {
        LOCK(cs_wallet);
        for (map<uint256, CWalletTx>::const_iterator it = mapWallet.begin(); it != mapWallet.end(); ++it)
        {
<<<<<<< HEAD
            const CWalletTx* pcoin = &(*it).second;

            if (!pcoin->IsFinal())
                continue;

            if (fOnlyConfirmed && !pcoin->IsConfirmed())
=======
            const uint256& wtxid = it->first;
            const CWalletTx* pcoin = &(*it).second;

            if (!IsFinalTx(*pcoin))
                continue;

            if (fOnlyConfirmed && !pcoin->IsTrusted())
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                continue;

            if (pcoin->IsCoinBase() && pcoin->GetBlocksToMaturity() > 0)
                continue;

<<<<<<< HEAD
            for (unsigned int i = 0; i < pcoin->vout.size(); i++) {
                if (!(pcoin->IsSpent(i)) && IsMine(pcoin->vout[i]) && !IsLockedCoin((*it).first, i) &&
                    (!coinControl || !coinControl->HasSelected() || coinControl->IsSelected((*it).first, i))) 
                        vCoins.push_back(COutput(pcoin, i, pcoin->GetDepthInMainChain()));
=======
            int nDepth = pcoin->GetDepthInMainChain();
            if (nDepth < 0)
                continue;

            for (unsigned int i = 0; i < pcoin->vout.size(); i++) {
                if (!(IsSpent(wtxid, i)) && IsMine(pcoin->vout[i]) &&
                    !IsLockedCoin((*it).first, i) && pcoin->vout[i].nValue > 0 &&
                    (!coinControl || !coinControl->HasSelected() || coinControl->IsSelected((*it).first, i)))
                        vCoins.push_back(COutput(pcoin, i, nDepth));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            }
        }
    }
}

<<<<<<< HEAD
static void ApproximateBestSubset(vector<pair<int64, pair<const CWalletTx*,unsigned int> > >vValue, int64 nTotalLower, int64 nTargetValue,
                                  vector<char>& vfBest, int64& nBest, int iterations = 1000)
=======
static void ApproximateBestSubset(vector<pair<int64_t, pair<const CWalletTx*,unsigned int> > >vValue, int64_t nTotalLower, int64_t nTargetValue,
                                  vector<char>& vfBest, int64_t& nBest, int iterations = 1000)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    vector<char> vfIncluded;

    vfBest.assign(vValue.size(), true);
    nBest = nTotalLower;

    seed_insecure_rand();

    for (int nRep = 0; nRep < iterations && nBest != nTargetValue; nRep++)
    {
        vfIncluded.assign(vValue.size(), false);
<<<<<<< HEAD
        int64 nTotal = 0;
=======
        int64_t nTotal = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        bool fReachedTarget = false;
        for (int nPass = 0; nPass < 2 && !fReachedTarget; nPass++)
        {
            for (unsigned int i = 0; i < vValue.size(); i++)
            {
                //The solver here uses a randomized algorithm,
                //the randomness serves no real security purpose but is just
                //needed to prevent degenerate behavior and it is important
                //that the rng fast. We do not use a constant random sequence,
                //because there may be some privacy improvement by making
                //the selection random.
                if (nPass == 0 ? insecure_rand()&1 : !vfIncluded[i])
                {
                    nTotal += vValue[i].first;
                    vfIncluded[i] = true;
                    if (nTotal >= nTargetValue)
                    {
                        fReachedTarget = true;
                        if (nTotal < nBest)
                        {
                            nBest = nTotal;
                            vfBest = vfIncluded;
                        }
                        nTotal -= vValue[i].first;
                        vfIncluded[i] = false;
                    }
                }
            }
        }
    }
}

<<<<<<< HEAD
bool CWallet::SelectCoinsMinConf(int64 nTargetValue, int nConfMine, int nConfTheirs, vector<COutput> vCoins,
                                 set<pair<const CWalletTx*,unsigned int> >& setCoinsRet, int64& nValueRet) const
=======
bool CWallet::SelectCoinsMinConf(int64_t nTargetValue, int nConfMine, int nConfTheirs, vector<COutput> vCoins,
                                 set<pair<const CWalletTx*,unsigned int> >& setCoinsRet, int64_t& nValueRet) const
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    setCoinsRet.clear();
    nValueRet = 0;

    // List of values less than target
<<<<<<< HEAD
    pair<int64, pair<const CWalletTx*,unsigned int> > coinLowestLarger;
    coinLowestLarger.first = std::numeric_limits<int64>::max();
    coinLowestLarger.second.first = NULL;
    vector<pair<int64, pair<const CWalletTx*,unsigned int> > > vValue;
    int64 nTotalLower = 0;
=======
    pair<int64_t, pair<const CWalletTx*,unsigned int> > coinLowestLarger;
    coinLowestLarger.first = std::numeric_limits<int64_t>::max();
    coinLowestLarger.second.first = NULL;
    vector<pair<int64_t, pair<const CWalletTx*,unsigned int> > > vValue;
    int64_t nTotalLower = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    random_shuffle(vCoins.begin(), vCoins.end(), GetRandInt);

    BOOST_FOREACH(COutput output, vCoins)
    {
        const CWalletTx *pcoin = output.tx;

        if (output.nDepth < (pcoin->IsFromMe() ? nConfMine : nConfTheirs))
            continue;

        int i = output.i;
<<<<<<< HEAD
        int64 n = pcoin->vout[i].nValue;

        pair<int64,pair<const CWalletTx*,unsigned int> > coin = make_pair(n,make_pair(pcoin, i));
=======
        int64_t n = pcoin->vout[i].nValue;

        pair<int64_t,pair<const CWalletTx*,unsigned int> > coin = make_pair(n,make_pair(pcoin, i));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

        if (n == nTargetValue)
        {
            setCoinsRet.insert(coin.second);
            nValueRet += coin.first;
            return true;
        }
<<<<<<< HEAD
        else if (n < nTargetValue + COIN)
        {
=======
        else if (n < nTargetValue + DUST_SOFT_LIMIT)
        {
            // This coin is not sufficient to cover the target plus change above the dust
            // limit. The dust limit is important here, as we don't want to leave change
            // which cannot be spent (is below the network transaction fee).
            
            // Push the coin into an array for potential matching later, but keep trying to find
            // an exact match
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            vValue.push_back(coin);
            nTotalLower += n;
        }
        else if (n < coinLowestLarger.first)
        {
            coinLowestLarger = coin;
        }
    }

    if (nTotalLower == nTargetValue)
    {
        for (unsigned int i = 0; i < vValue.size(); ++i)
        {
            setCoinsRet.insert(vValue[i].second);
            nValueRet += vValue[i].first;
        }
        return true;
    }

    if (nTotalLower < nTargetValue)
    {
        if (coinLowestLarger.second.first == NULL)
            return false;
        setCoinsRet.insert(coinLowestLarger.second);
        nValueRet += coinLowestLarger.first;
        return true;
    }

    // Solve subset sum by stochastic approximation
    sort(vValue.rbegin(), vValue.rend(), CompareValueOnly());
    vector<char> vfBest;
<<<<<<< HEAD
    int64 nBest;

    ApproximateBestSubset(vValue, nTotalLower, nTargetValue, vfBest, nBest, 1000);
    if (nBest != nTargetValue && nTotalLower >= nTargetValue + COIN)
        ApproximateBestSubset(vValue, nTotalLower, nTargetValue + COIN, vfBest, nBest, 1000);
=======
    int64_t nBest;

    ApproximateBestSubset(vValue, nTotalLower, nTargetValue, vfBest, nBest, 1000);
    if (nBest != nTargetValue && nTotalLower >= nTargetValue + DUST_SOFT_LIMIT)
        ApproximateBestSubset(vValue, nTotalLower, nTargetValue + DUST_SOFT_LIMIT, vfBest, nBest, 1000);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    // If we have a bigger coin and (either the stochastic approximation didn't find a good solution,
    //                                   or the next bigger coin is closer), return the bigger coin
    if (coinLowestLarger.second.first &&
<<<<<<< HEAD
        ((nBest != nTargetValue && nBest < nTargetValue + COIN) || coinLowestLarger.first <= nBest))
=======
        ((nBest != nTargetValue && nBest < nTargetValue + DUST_SOFT_LIMIT) || coinLowestLarger.first <= nBest))
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        setCoinsRet.insert(coinLowestLarger.second);
        nValueRet += coinLowestLarger.first;
    }
    else {
        for (unsigned int i = 0; i < vValue.size(); i++)
            if (vfBest[i])
            {
                setCoinsRet.insert(vValue[i].second);
                nValueRet += vValue[i].first;
            }

<<<<<<< HEAD
        //// debug print
        printf("SelectCoins() best subset: ");
        for (unsigned int i = 0; i < vValue.size(); i++)
            if (vfBest[i])
                printf("%s ", FormatMoney(vValue[i].first).c_str());
        printf("total %s\n", FormatMoney(nBest).c_str());
=======
        LogPrint("selectcoins", "SelectCoins() best subset: ");
        for (unsigned int i = 0; i < vValue.size(); i++)
            if (vfBest[i])
                LogPrint("selectcoins", "%s ", FormatMoney(vValue[i].first));
        LogPrint("selectcoins", "total %s\n", FormatMoney(nBest));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }

    return true;
}

<<<<<<< HEAD
bool CWallet::SelectCoins(int64 nTargetValue, set<pair<const CWalletTx*,unsigned int> >& setCoinsRet, int64& nValueRet, const CCoinControl* coinControl) const
{
    vector<COutput> vCoins;
    AvailableCoins(vCoins, true, coinControl);
    
=======
bool CWallet::SelectCoins(int64_t nTargetValue, set<pair<const CWalletTx*,unsigned int> >& setCoinsRet, int64_t& nValueRet, const CCoinControl* coinControl) const
{
    vector<COutput> vCoins;
    AvailableCoins(vCoins, true, coinControl);

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    // coin control -> return all selected outputs (we want all selected to go into the transaction for sure)
    if (coinControl && coinControl->HasSelected())
    {
        BOOST_FOREACH(const COutput& out, vCoins)
        {
            nValueRet += out.tx->vout[out.i].nValue;
            setCoinsRet.insert(make_pair(out.tx, out.i));
        }
        return (nValueRet >= nTargetValue);
    }

    return (SelectCoinsMinConf(nTargetValue, 1, 6, vCoins, setCoinsRet, nValueRet) ||
            SelectCoinsMinConf(nTargetValue, 1, 1, vCoins, setCoinsRet, nValueRet) ||
<<<<<<< HEAD
            SelectCoinsMinConf(nTargetValue, 0, 1, vCoins, setCoinsRet, nValueRet));
=======
            (bSpendZeroConfChange && SelectCoinsMinConf(nTargetValue, 0, 1, vCoins, setCoinsRet, nValueRet)));
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}




<<<<<<< HEAD
bool CWallet::CreateTransaction(const vector<pair<CScript, int64> >& vecSend,
                                CWalletTx& wtxNew, CReserveKey& reservekey, int64& nFeeRet, std::string& strFailReason, const CCoinControl* coinControl)
{
    int64 nValue = 0;
    BOOST_FOREACH (const PAIRTYPE(CScript, int64)& s, vecSend)
=======
bool CWallet::CreateTransaction(const vector<pair<CScript, int64_t> >& vecSend,
                                CWalletTx& wtxNew, CReserveKey& reservekey, int64_t& nFeeRet, std::string& strFailReason, const CCoinControl* coinControl)
{
    int64_t nValue = 0;
    BOOST_FOREACH (const PAIRTYPE(CScript, int64_t)& s, vecSend)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        if (nValue < 0)
        {
            strFailReason = _("Transaction amounts must be positive");
            return false;
        }
        nValue += s.second;
    }
    if (vecSend.empty() || nValue < 0)
    {
        strFailReason = _("Transaction amounts must be positive");
        return false;
    }

    wtxNew.BindWallet(this);

    {
        LOCK2(cs_main, cs_wallet);
        {
            nFeeRet = nTransactionFee;
<<<<<<< HEAD
            loop
=======
            while (true)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            {
                wtxNew.vin.clear();
                wtxNew.vout.clear();
                wtxNew.fFromMe = true;

<<<<<<< HEAD
                int64 nTotalValue = nValue + nFeeRet;
                double dPriority = 0;
                // vouts to the payees
                BOOST_FOREACH (const PAIRTYPE(CScript, int64)& s, vecSend)
                {
                    CTxOut txout(s.second, s.first);
                    if (txout.IsDust())
=======
                int64_t nTotalValue = nValue + nFeeRet;
                double dPriority = 0;
                // vouts to the payees
                BOOST_FOREACH (const PAIRTYPE(CScript, int64_t)& s, vecSend)
                {
                    CTxOut txout(s.second, s.first);
                    if (txout.IsDust(CTransaction::nMinRelayTxFee))
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    {
                        strFailReason = _("Transaction amount too small");
                        return false;
                    }
                    wtxNew.vout.push_back(txout);
                }

                // Choose coins to use
                set<pair<const CWalletTx*,unsigned int> > setCoins;
<<<<<<< HEAD
                int64 nValueIn = 0;
=======
                int64_t nValueIn = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                if (!SelectCoins(nTotalValue, setCoins, nValueIn, coinControl))
                {
                    strFailReason = _("Insufficient funds");
                    return false;
                }
                BOOST_FOREACH(PAIRTYPE(const CWalletTx*, unsigned int) pcoin, setCoins)
                {
<<<<<<< HEAD
                    int64 nCredit = pcoin.first->vout[pcoin.second].nValue;
                    // Dogecoin: Set priority to current block
                    dPriority += (double)nCredit * pcoin.first->GetDepthInMainChain();
                }

                int64 nChange = nValueIn - nValue - nFeeRet;
                // if sub-cent change is required, the fee must be raised to at least nMinTxFee
                // or until nChange becomes zero
                // NOTE: this depends on the exact behaviour of GetMinFee
                if (nFeeRet < CTransaction::nMinTxFee && nChange > 0 && nChange < COIN)
                {
                    int64 nMoveToFee = min(nChange, CTransaction::nMinTxFee - nFeeRet);
=======
                    int64_t nCredit = pcoin.first->vout[pcoin.second].nValue;
                    //The priority after the next block (depth+1) is used instead of the current,
                    //reflecting an assumption the user would accept a bit more delay for
                    //a chance at a free transaction.
                    dPriority += (double)nCredit * (pcoin.first->GetDepthInMainChain()+1);
                }

                int64_t nChange = nValueIn - nValue - nFeeRet;
                // The following if statement should be removed once enough miners
                // have upgraded to the 0.9 GetMinFee() rules. Until then, this avoids
                // creating free transactions that have change outputs less than
                // COIN dogecoins.
                if (nFeeRet < CTransaction::nMinTxFee && nChange > 0 && nChange < COIN)
                {
                    int64_t nMoveToFee = min(nChange, CTransaction::nMinTxFee - nFeeRet);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    nChange -= nMoveToFee;
                    nFeeRet += nMoveToFee;
                }

                if (nChange > 0)
                {
                    // Fill a vout to ourself
                    // TODO: pass in scriptChange instead of reservekey so
<<<<<<< HEAD
                    // change transaction isn't always pay-to-bitcoin-address
                    CScript scriptChange;
                    
=======
                    // change transaction isn't always pay-to-dogecoin-address
                    CScript scriptChange;

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    // coin control: send change to custom address
                    if (coinControl && !boost::get<CNoDestination>(&coinControl->destChange))
                        scriptChange.SetDestination(coinControl->destChange);
                        
<<<<<<< HEAD
                    // send change to one of the specified change addresses
                    else if (mapArgs.count("-change") && mapMultiArgs["-change"].size() > 0)
                    {
                        CBitcoinAddress address(mapMultiArgs["-change"][GetRandInt(mapMultiArgs["-change"].size())]);

                        CKeyID keyID;
                        if (!address.GetKeyID(keyID)) {
                            strFailReason = _("Bad change address");
                            return false;
                        }

                        scriptChange.SetDestination(keyID);
                    }
                    // no coin control: send change to newly generated address
=======
                    // send change to one of the specified change addresses, if specified at init
                    else if (vChangeAddresses.size())
                    {
                        CKeyID keyID = vChangeAddresses[GetRandInt(vChangeAddresses.size())];
                        scriptChange.SetDestination(keyID);
                    }

                    // send change to newly generated address
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    else
                    {
                        // Note: We use a new key here to keep it from being obvious which side is the change.
                        //  The drawback is that by not reusing a previous key, the change may be lost if a
                        //  backup is restored, if the backup doesn't have the new private key for the change.
                        //  If we reused the old key, it would be possible to add code to look for and
                        //  rediscover unknown transactions that were written with keys of ours to recover
                        //  post-backup change.

                        // Reserve a new key pair from key pool
                        CPubKey vchPubKey;
<<<<<<< HEAD
                        assert(reservekey.GetReservedKey(vchPubKey)); // should never fail, as we just unlocked
=======
                        bool ret;
                        ret = reservekey.GetReservedKey(vchPubKey);
                        assert(ret); // should never fail, as we just unlocked
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

                        scriptChange.SetDestination(vchPubKey.GetID());
                    }

                    CTxOut newTxOut(nChange, scriptChange);

                    // Never create dust outputs; if we would, just
                    // add the dust to the fee.
<<<<<<< HEAD
                    if (newTxOut.IsDust())
=======
                    if (newTxOut.IsDust(CTransaction::nMinRelayTxFee))
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                    {
                        nFeeRet += nChange;
                        reservekey.ReturnKey();
                    }
                    else
                    {
                        // Insert change txn at random position:
                        vector<CTxOut>::iterator position = wtxNew.vout.begin()+GetRandInt(wtxNew.vout.size()+1);
                        wtxNew.vout.insert(position, newTxOut);
                    }
                }
                else
                    reservekey.ReturnKey();

                // Fill vin
                BOOST_FOREACH(const PAIRTYPE(const CWalletTx*,unsigned int)& coin, setCoins)
                    wtxNew.vin.push_back(CTxIn(coin.first->GetHash(),coin.second));

                // Sign
                int nIn = 0;
                BOOST_FOREACH(const PAIRTYPE(const CWalletTx*,unsigned int)& coin, setCoins)
                    if (!SignSignature(*this, *coin.first, wtxNew, nIn++))
                    {
                        strFailReason = _("Signing transaction failed");
                        return false;
                    }

                // Limit size
                unsigned int nBytes = ::GetSerializeSize(*(CTransaction*)&wtxNew, SER_NETWORK, PROTOCOL_VERSION);
                if (nBytes >= MAX_STANDARD_TX_SIZE)
                {
                    strFailReason = _("Transaction too large");
                    return false;
                }
<<<<<<< HEAD
                dPriority /= nBytes;

                // Check that enough fee is included
                int64 nPayFee = nTransactionFee * (1 + (int64)nBytes / 1000);
                bool fAllowFree = CTransaction::AllowFree(dPriority);
                int64 nMinFee = wtxNew.GetMinFee(1, fAllowFree, GMF_SEND);
=======
                dPriority = wtxNew.ComputePriority(dPriority, nBytes);

                // Check that enough fee is included
                int64_t nPayFee = nTransactionFee * (1 + (int64_t)nBytes / 1000);
                bool fAllowFree = AllowFree(dPriority);
                int64_t nMinFee = GetMinFee(wtxNew, nBytes, fAllowFree, GMF_SEND);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                if (nFeeRet < max(nPayFee, nMinFee))
                {
                    nFeeRet = max(nPayFee, nMinFee);
                    continue;
                }

<<<<<<< HEAD
                // Fill vtxPrev by copying from previous transactions vtxPrev
                wtxNew.AddSupportingTransactions();
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                wtxNew.fTimeReceivedIsTxTime = true;

                break;
            }
        }
    }
    return true;
}

<<<<<<< HEAD
bool CWallet::CreateTransaction(CScript scriptPubKey, int64 nValue,
                                CWalletTx& wtxNew, CReserveKey& reservekey, int64& nFeeRet, std::string& strFailReason, const CCoinControl* coinControl)
{
    vector< pair<CScript, int64> > vecSend;
=======
bool CWallet::CreateTransaction(CScript scriptPubKey, int64_t nValue,
                                CWalletTx& wtxNew, CReserveKey& reservekey, int64_t& nFeeRet, std::string& strFailReason, const CCoinControl* coinControl)
{
    vector< pair<CScript, int64_t> > vecSend;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    vecSend.push_back(make_pair(scriptPubKey, nValue));
    return CreateTransaction(vecSend, wtxNew, reservekey, nFeeRet, strFailReason, coinControl);
}

// Call after CreateTransaction unless you want to abort
bool CWallet::CommitTransaction(CWalletTx& wtxNew, CReserveKey& reservekey)
{
    {
        LOCK2(cs_main, cs_wallet);
<<<<<<< HEAD
        printf("CommitTransaction:\n%s", wtxNew.ToString().c_str());
=======
        LogPrintf("CommitTransaction:\n%s", wtxNew.ToString());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        {
            // This is only to keep the database open to defeat the auto-flush for the
            // duration of this scope.  This is the only place where this optimization
            // maybe makes sense; please don't do it anywhere else.
            CWalletDB* pwalletdb = fFileBacked ? new CWalletDB(strWalletFile,"r") : NULL;

            // Take key pair from key pool so it won't be used again
            reservekey.KeepKey();

            // Add tx to wallet, because if it has change it's also ours,
            // otherwise just for transaction history.
            AddToWallet(wtxNew);

<<<<<<< HEAD
            // Mark old coins as spent
=======
            // Notify that old coins are spent
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            set<CWalletTx*> setCoins;
            BOOST_FOREACH(const CTxIn& txin, wtxNew.vin)
            {
                CWalletTx &coin = mapWallet[txin.prevout.hash];
                coin.BindWallet(this);
<<<<<<< HEAD
                coin.MarkSpent(txin.prevout.n);
                coin.WriteToDisk();
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                NotifyTransactionChanged(this, coin.GetHash(), CT_UPDATED);
            }

            if (fFileBacked)
                delete pwalletdb;
        }

        // Track how many getdata requests our transaction gets
        mapRequestCount[wtxNew.GetHash()] = 0;

        // Broadcast
<<<<<<< HEAD
        if (!wtxNew.AcceptToMemoryPool(true, false))
        {
            // This must not fail. The transaction has already been signed and recorded.
            printf("CommitTransaction() : Error: Transaction not valid");
=======
        if (!wtxNew.AcceptToMemoryPool(false))
        {
            // This must not fail. The transaction has already been signed and recorded.
            LogPrintf("CommitTransaction() : Error: Transaction not valid");
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            return false;
        }
        wtxNew.RelayWalletTransaction();
    }
    return true;
}




<<<<<<< HEAD
string CWallet::SendMoney(CScript scriptPubKey, int64 nValue, CWalletTx& wtxNew, bool fAskFee)
{
    CReserveKey reservekey(this);
    int64 nFeeRequired;
=======
string CWallet::SendMoney(CScript scriptPubKey, int64_t nValue, CWalletTx& wtxNew)
{
    CReserveKey reservekey(this);
    int64_t nFeeRequired;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    if (IsLocked())
    {
        string strError = _("Error: Wallet locked, unable to create transaction!");
<<<<<<< HEAD
        printf("SendMoney() : %s", strError.c_str());
=======
        LogPrintf("SendMoney() : %s", strError);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        return strError;
    }
    string strError;
    if (!CreateTransaction(scriptPubKey, nValue, wtxNew, reservekey, nFeeRequired, strError))
    {
        if (nValue + nFeeRequired > GetBalance())
<<<<<<< HEAD
            strError = strprintf(_("Error: This transaction requires a transaction fee of at least %s because of its amount, complexity, or use of recently received funds!"), FormatMoney(nFeeRequired).c_str());
        printf("SendMoney() : %s\n", strError.c_str());
        return strError;
    }

    if (fAskFee && !uiInterface.ThreadSafeAskFee(nFeeRequired))
        return "ABORTED";

=======
            strError = strprintf(_("Error: This transaction requires a transaction fee of at least %s because of its amount, complexity, or use of recently received funds!"), FormatMoney(nFeeRequired));
        LogPrintf("SendMoney() : %s\n", strError);
        return strError;
    }

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    if (!CommitTransaction(wtxNew, reservekey))
        return _("Error: The transaction was rejected! This might happen if some of the coins in your wallet were already spent, such as if you used a copy of wallet.dat and coins were spent in the copy but not marked as spent here.");

    return "";
}



<<<<<<< HEAD
string CWallet::SendMoneyToDestination(const CTxDestination& address, int64 nValue, CWalletTx& wtxNew, bool fAskFee)
=======
string CWallet::SendMoneyToDestination(const CTxDestination& address, int64_t nValue, CWalletTx& wtxNew)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    // Check amount
    if (nValue <= 0)
        return _("Invalid amount");
    if (nValue + nTransactionFee > GetBalance())
        return _("Insufficient funds");

    // Parse Bitcoin address
    CScript scriptPubKey;
    scriptPubKey.SetDestination(address);

<<<<<<< HEAD
    return SendMoney(scriptPubKey, nValue, wtxNew, fAskFee);
=======
    return SendMoney(scriptPubKey, nValue, wtxNew);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}




DBErrors CWallet::LoadWallet(bool& fFirstRunRet)
{
    if (!fFileBacked)
        return DB_LOAD_OK;
    fFirstRunRet = false;
    DBErrors nLoadWalletRet = CWalletDB(strWalletFile,"cr+").LoadWallet(this);
    if (nLoadWalletRet == DB_NEED_REWRITE)
    {
        if (CDB::Rewrite(strWalletFile, "\x04pool"))
        {
<<<<<<< HEAD
=======
            LOCK(cs_wallet);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            setKeyPool.clear();
            // Note: can't top-up keypool here, because wallet is locked.
            // User will be prompted to unlock wallet the next operation
            // the requires a new key.
        }
    }

    if (nLoadWalletRet != DB_LOAD_OK)
        return nLoadWalletRet;
    fFirstRunRet = !vchDefaultKey.IsValid();

    return DB_LOAD_OK;
}


<<<<<<< HEAD
bool CWallet::SetAddressBookName(const CTxDestination& address, const string& strName)
{
    std::map<CTxDestination, std::string>::iterator mi = mapAddressBook.find(address);
    mapAddressBook[address] = strName;
    NotifyAddressBookChanged(this, address, strName, ::IsMine(*this, address), (mi == mapAddressBook.end()) ? CT_NEW : CT_UPDATED);
    if (!fFileBacked)
        return false;
    return CWalletDB(strWalletFile).WriteName(CBitcoinAddress(address).ToString(), strName);
}

bool CWallet::DelAddressBookName(const CTxDestination& address)
{
    mapAddressBook.erase(address);
    NotifyAddressBookChanged(this, address, "", ::IsMine(*this, address), CT_DELETED);
    if (!fFileBacked)
        return false;
    return CWalletDB(strWalletFile).EraseName(CBitcoinAddress(address).ToString());
}


void CWallet::PrintWallet(const CBlock& block)
{
    {
        LOCK(cs_wallet);
        if (mapWallet.count(block.vtx[0].GetHash()))
        {
            CWalletTx& wtx = mapWallet[block.vtx[0].GetHash()];
            printf("    mine:  %d  %d  %"PRI64d"", wtx.GetDepthInMainChain(), wtx.GetBlocksToMaturity(), wtx.GetCredit());
        }
    }
    printf("\n");
}

bool CWallet::GetTransaction(const uint256 &hashTx, CWalletTx& wtx)
{
    {
        LOCK(cs_wallet);
        map<uint256, CWalletTx>::iterator mi = mapWallet.find(hashTx);
        if (mi != mapWallet.end())
        {
            wtx = (*mi).second;
            return true;
        }
    }
    return false;
=======
DBErrors CWallet::ZapWalletTx()
{
    if (!fFileBacked)
        return DB_LOAD_OK;
    DBErrors nZapWalletTxRet = CWalletDB(strWalletFile,"cr+").ZapWalletTx(this);
    if (nZapWalletTxRet == DB_NEED_REWRITE)
    {
        if (CDB::Rewrite(strWalletFile, "\x04pool"))
        {
            LOCK(cs_wallet);
            setKeyPool.clear();
            // Note: can't top-up keypool here, because wallet is locked.
            // User will be prompted to unlock wallet the next operation
            // the requires a new key.
        }
    }

    if (nZapWalletTxRet != DB_LOAD_OK)
        return nZapWalletTxRet;

    return DB_LOAD_OK;
}


bool CWallet::SetAddressBook(const CTxDestination& address, const string& strName, const string& strPurpose)
{
    bool fUpdated = false;
    {
        LOCK(cs_wallet); // mapAddressBook
        std::map<CTxDestination, CAddressBookData>::iterator mi = mapAddressBook.find(address);
        fUpdated = mi != mapAddressBook.end();
        mapAddressBook[address].name = strName;
        if (!strPurpose.empty()) /* update purpose only if requested */
            mapAddressBook[address].purpose = strPurpose;
    }
    NotifyAddressBookChanged(this, address, strName, ::IsMine(*this, address),
                             strPurpose, (fUpdated ? CT_UPDATED : CT_NEW) );
    if (!fFileBacked)
        return false;
    if (!strPurpose.empty() && !CWalletDB(strWalletFile).WritePurpose(CBitcoinAddress(address).ToString(), strPurpose))
        return false;
    return CWalletDB(strWalletFile).WriteName(CBitcoinAddress(address).ToString(), strName);
}

bool CWallet::DelAddressBook(const CTxDestination& address)
{
    {
        LOCK(cs_wallet); // mapAddressBook

        if(fFileBacked)
        {
            // Delete destdata tuples associated with address
            std::string strAddress = CBitcoinAddress(address).ToString();
            BOOST_FOREACH(const PAIRTYPE(string, string) &item, mapAddressBook[address].destdata)
            {
                CWalletDB(strWalletFile).EraseDestData(strAddress, item.first);
            }
        }
        mapAddressBook.erase(address);
    }

    NotifyAddressBookChanged(this, address, "", ::IsMine(*this, address), "", CT_DELETED);

    if (!fFileBacked)
        return false;
    CWalletDB(strWalletFile).ErasePurpose(CBitcoinAddress(address).ToString());
    return CWalletDB(strWalletFile).EraseName(CBitcoinAddress(address).ToString());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

bool CWallet::SetDefaultKey(const CPubKey &vchPubKey)
{
    if (fFileBacked)
    {
        if (!CWalletDB(strWalletFile).WriteDefaultKey(vchPubKey))
            return false;
    }
    vchDefaultKey = vchPubKey;
    return true;
}

<<<<<<< HEAD
bool GetWalletFile(CWallet* pwallet, string &strWalletFileOut)
{
    if (!pwallet->fFileBacked)
        return false;
    strWalletFileOut = pwallet->strWalletFile;
    return true;
}

=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
//
// Mark old keypool keys as used,
// and generate all new keys
//
bool CWallet::NewKeyPool()
{
    {
        LOCK(cs_wallet);
        CWalletDB walletdb(strWalletFile);
<<<<<<< HEAD
        BOOST_FOREACH(int64 nIndex, setKeyPool)
=======
        BOOST_FOREACH(int64_t nIndex, setKeyPool)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            walletdb.ErasePool(nIndex);
        setKeyPool.clear();

        if (IsLocked())
            return false;

<<<<<<< HEAD
        int64 nKeys = max(GetArg("-keypool", 100), (int64)0);
        for (int i = 0; i < nKeys; i++)
        {
            int64 nIndex = i+1;
            walletdb.WritePool(nIndex, CKeyPool(GenerateNewKey()));
            setKeyPool.insert(nIndex);
        }
        printf("CWallet::NewKeyPool wrote %"PRI64d" new keys\n", nKeys);
=======
        int64_t nKeys = max(GetArg("-keypool", 100), (int64_t)0);
        for (int i = 0; i < nKeys; i++)
        {
            int64_t nIndex = i+1;
            walletdb.WritePool(nIndex, CKeyPool(GenerateNewKey()));
            setKeyPool.insert(nIndex);
        }
        LogPrintf("CWallet::NewKeyPool wrote %d new keys\n", nKeys);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
    return true;
}

<<<<<<< HEAD
bool CWallet::TopUpKeyPool()
=======
bool CWallet::TopUpKeyPool(unsigned int kpSize)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    {
        LOCK(cs_wallet);

        if (IsLocked())
            return false;

        CWalletDB walletdb(strWalletFile);

        // Top up key pool
<<<<<<< HEAD
        unsigned int nTargetSize = max(GetArg("-keypool", 100), 0LL);
        while (setKeyPool.size() < (nTargetSize + 1))
        {
            int64 nEnd = 1;
=======
        unsigned int nTargetSize;
        if (kpSize > 0)
            nTargetSize = kpSize;
        else
            nTargetSize = max(GetArg("-keypool", 100), (int64_t) 0);

        while (setKeyPool.size() < (nTargetSize + 1))
        {
            int64_t nEnd = 1;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            if (!setKeyPool.empty())
                nEnd = *(--setKeyPool.end()) + 1;
            if (!walletdb.WritePool(nEnd, CKeyPool(GenerateNewKey())))
                throw runtime_error("TopUpKeyPool() : writing generated key failed");
            setKeyPool.insert(nEnd);
<<<<<<< HEAD
            printf("keypool added key %"PRI64d", size=%"PRIszu"\n", nEnd, setKeyPool.size());
=======
            LogPrintf("keypool added key %d, size=%" PRIszu"\n", nEnd, setKeyPool.size());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
    }
    return true;
}

<<<<<<< HEAD
void CWallet::ReserveKeyFromKeyPool(int64& nIndex, CKeyPool& keypool)
=======
void CWallet::ReserveKeyFromKeyPool(int64_t& nIndex, CKeyPool& keypool)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    nIndex = -1;
    keypool.vchPubKey = CPubKey();
    {
        LOCK(cs_wallet);

        if (!IsLocked())
            TopUpKeyPool();

        // Get the oldest key
        if(setKeyPool.empty())
            return;

        CWalletDB walletdb(strWalletFile);

        nIndex = *(setKeyPool.begin());
        setKeyPool.erase(setKeyPool.begin());
        if (!walletdb.ReadPool(nIndex, keypool))
            throw runtime_error("ReserveKeyFromKeyPool() : read failed");
        if (!HaveKey(keypool.vchPubKey.GetID()))
            throw runtime_error("ReserveKeyFromKeyPool() : unknown key in key pool");
        assert(keypool.vchPubKey.IsValid());
<<<<<<< HEAD
        printf("keypool reserve %"PRI64d"\n", nIndex);
    }
}

int64 CWallet::AddReserveKey(const CKeyPool& keypool)
=======
        LogPrintf("keypool reserve %d\n", nIndex);
    }
}

int64_t CWallet::AddReserveKey(const CKeyPool& keypool)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    {
        LOCK2(cs_main, cs_wallet);
        CWalletDB walletdb(strWalletFile);

<<<<<<< HEAD
        int64 nIndex = 1 + *(--setKeyPool.end());
=======
        int64_t nIndex = 1 + *(--setKeyPool.end());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        if (!walletdb.WritePool(nIndex, keypool))
            throw runtime_error("AddReserveKey() : writing added key failed");
        setKeyPool.insert(nIndex);
        return nIndex;
    }
    return -1;
}

<<<<<<< HEAD
void CWallet::KeepKey(int64 nIndex)
=======
void CWallet::KeepKey(int64_t nIndex)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    // Remove from key pool
    if (fFileBacked)
    {
        CWalletDB walletdb(strWalletFile);
        walletdb.ErasePool(nIndex);
    }
<<<<<<< HEAD
    printf("keypool keep %"PRI64d"\n", nIndex);
}

void CWallet::ReturnKey(int64 nIndex)
=======
    LogPrintf("keypool keep %d\n", nIndex);
}

void CWallet::ReturnKey(int64_t nIndex)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    // Return to key pool
    {
        LOCK(cs_wallet);
        setKeyPool.insert(nIndex);
    }
<<<<<<< HEAD
    printf("keypool return %"PRI64d"\n", nIndex);
}

bool CWallet::GetKeyFromPool(CPubKey& result, bool fAllowReuse)
{
    int64 nIndex = 0;
=======
    LogPrintf("keypool return %d\n", nIndex);
}

bool CWallet::GetKeyFromPool(CPubKey& result)
{
    int64_t nIndex = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    CKeyPool keypool;
    {
        LOCK(cs_wallet);
        ReserveKeyFromKeyPool(nIndex, keypool);
        if (nIndex == -1)
        {
<<<<<<< HEAD
            if (fAllowReuse && vchDefaultKey.IsValid())
            {
                result = vchDefaultKey;
                return true;
            }
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
            if (IsLocked()) return false;
            result = GenerateNewKey();
            return true;
        }
        KeepKey(nIndex);
        result = keypool.vchPubKey;
    }
    return true;
}

<<<<<<< HEAD
int64 CWallet::GetOldestKeyPoolTime()
{
    int64 nIndex = 0;
=======
int64_t CWallet::GetOldestKeyPoolTime()
{
    int64_t nIndex = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    CKeyPool keypool;
    ReserveKeyFromKeyPool(nIndex, keypool);
    if (nIndex == -1)
        return GetTime();
    ReturnKey(nIndex);
    return keypool.nTime;
}

<<<<<<< HEAD
std::map<CTxDestination, int64> CWallet::GetAddressBalances()
{
    map<CTxDestination, int64> balances;
=======
std::map<CTxDestination, int64_t> CWallet::GetAddressBalances()
{
    map<CTxDestination, int64_t> balances;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    {
        LOCK(cs_wallet);
        BOOST_FOREACH(PAIRTYPE(uint256, CWalletTx) walletEntry, mapWallet)
        {
            CWalletTx *pcoin = &walletEntry.second;

<<<<<<< HEAD
            if (!pcoin->IsFinal() || !pcoin->IsConfirmed())
=======
            if (!IsFinalTx(*pcoin) || !pcoin->IsTrusted())
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                continue;

            if (pcoin->IsCoinBase() && pcoin->GetBlocksToMaturity() > 0)
                continue;

            int nDepth = pcoin->GetDepthInMainChain();
            if (nDepth < (pcoin->IsFromMe() ? 0 : 1))
                continue;

            for (unsigned int i = 0; i < pcoin->vout.size(); i++)
            {
                CTxDestination addr;
                if (!IsMine(pcoin->vout[i]))
                    continue;
                if(!ExtractDestination(pcoin->vout[i].scriptPubKey, addr))
                    continue;

<<<<<<< HEAD
                int64 n = pcoin->IsSpent(i) ? 0 : pcoin->vout[i].nValue;
=======
                int64_t n = IsSpent(walletEntry.first, i) ? 0 : pcoin->vout[i].nValue;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

                if (!balances.count(addr))
                    balances[addr] = 0;
                balances[addr] += n;
            }
        }
    }

    return balances;
}

set< set<CTxDestination> > CWallet::GetAddressGroupings()
{
<<<<<<< HEAD
=======
    AssertLockHeld(cs_wallet); // mapWallet
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    set< set<CTxDestination> > groupings;
    set<CTxDestination> grouping;

    BOOST_FOREACH(PAIRTYPE(uint256, CWalletTx) walletEntry, mapWallet)
    {
        CWalletTx *pcoin = &walletEntry.second;

        if (pcoin->vin.size() > 0)
        {
            bool any_mine = false;
            // group all input addresses with each other
            BOOST_FOREACH(CTxIn txin, pcoin->vin)
            {
                CTxDestination address;
                if(!IsMine(txin)) /* If this input isn't mine, ignore it */
                    continue;
                if(!ExtractDestination(mapWallet[txin.prevout.hash].vout[txin.prevout.n].scriptPubKey, address))
                    continue;
                grouping.insert(address);
                any_mine = true;
            }

            // group change with input addresses
            if (any_mine)
            {
               BOOST_FOREACH(CTxOut txout, pcoin->vout)
                   if (IsChange(txout))
                   {
                       CTxDestination txoutAddr;
                       if(!ExtractDestination(txout.scriptPubKey, txoutAddr))
                           continue;
                       grouping.insert(txoutAddr);
                   }
            }
            if (grouping.size() > 0)
            {
                groupings.insert(grouping);
                grouping.clear();
            }
        }

        // group lone addrs by themselves
        for (unsigned int i = 0; i < pcoin->vout.size(); i++)
            if (IsMine(pcoin->vout[i]))
            {
                CTxDestination address;
                if(!ExtractDestination(pcoin->vout[i].scriptPubKey, address))
                    continue;
                grouping.insert(address);
                groupings.insert(grouping);
                grouping.clear();
            }
    }

    set< set<CTxDestination>* > uniqueGroupings; // a set of pointers to groups of addresses
    map< CTxDestination, set<CTxDestination>* > setmap;  // map addresses to the unique group containing it
    BOOST_FOREACH(set<CTxDestination> grouping, groupings)
    {
        // make a set of all the groups hit by this new group
        set< set<CTxDestination>* > hits;
        map< CTxDestination, set<CTxDestination>* >::iterator it;
        BOOST_FOREACH(CTxDestination address, grouping)
            if ((it = setmap.find(address)) != setmap.end())
                hits.insert((*it).second);

        // merge all hit groups into a new single group and delete old groups
        set<CTxDestination>* merged = new set<CTxDestination>(grouping);
        BOOST_FOREACH(set<CTxDestination>* hit, hits)
        {
            merged->insert(hit->begin(), hit->end());
            uniqueGroupings.erase(hit);
            delete hit;
        }
        uniqueGroupings.insert(merged);

        // update setmap
        BOOST_FOREACH(CTxDestination element, *merged)
            setmap[element] = merged;
    }

    set< set<CTxDestination> > ret;
    BOOST_FOREACH(set<CTxDestination>* uniqueGrouping, uniqueGroupings)
    {
        ret.insert(*uniqueGrouping);
        delete uniqueGrouping;
    }

    return ret;
}

<<<<<<< HEAD
=======
set<CTxDestination> CWallet::GetAccountAddresses(string strAccount) const
{
    AssertLockHeld(cs_wallet); // mapWallet
    set<CTxDestination> result;
    BOOST_FOREACH(const PAIRTYPE(CTxDestination, CAddressBookData)& item, mapAddressBook)
    {
        const CTxDestination& address = item.first;
        const string& strName = item.second.name;
        if (strName == strAccount)
            result.insert(address);
    }
    return result;
}

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
bool CReserveKey::GetReservedKey(CPubKey& pubkey)
{
    if (nIndex == -1)
    {
        CKeyPool keypool;
        pwallet->ReserveKeyFromKeyPool(nIndex, keypool);
        if (nIndex != -1)
            vchPubKey = keypool.vchPubKey;
        else {
            if (pwallet->vchDefaultKey.IsValid()) {
<<<<<<< HEAD
                printf("CReserveKey::GetReservedKey(): Warning: Using default key instead of a new key, top up your keypool!");
=======
                LogPrintf("CReserveKey::GetReservedKey(): Warning: Using default key instead of a new key, top up your keypool!");
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                vchPubKey = pwallet->vchDefaultKey;
            } else
                return false;
        }
    }
    assert(vchPubKey.IsValid());
    pubkey = vchPubKey;
    return true;
}

void CReserveKey::KeepKey()
{
    if (nIndex != -1)
        pwallet->KeepKey(nIndex);
    nIndex = -1;
    vchPubKey = CPubKey();
}

void CReserveKey::ReturnKey()
{
    if (nIndex != -1)
        pwallet->ReturnKey(nIndex);
    nIndex = -1;
    vchPubKey = CPubKey();
}

<<<<<<< HEAD
void CWallet::GetAllReserveKeys(set<CKeyID>& setAddress)
=======
void CWallet::GetAllReserveKeys(set<CKeyID>& setAddress) const
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    setAddress.clear();

    CWalletDB walletdb(strWalletFile);

    LOCK2(cs_main, cs_wallet);
<<<<<<< HEAD
    BOOST_FOREACH(const int64& id, setKeyPool)
=======
    BOOST_FOREACH(const int64_t& id, setKeyPool)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    {
        CKeyPool keypool;
        if (!walletdb.ReadPool(id, keypool))
            throw runtime_error("GetAllReserveKeyHashes() : read failed");
        assert(keypool.vchPubKey.IsValid());
        CKeyID keyID = keypool.vchPubKey.GetID();
        if (!HaveKey(keyID))
            throw runtime_error("GetAllReserveKeyHashes() : unknown key in key pool");
        setAddress.insert(keyID);
    }
}

void CWallet::UpdatedTransaction(const uint256 &hashTx)
{
    {
        LOCK(cs_wallet);
        // Only notify UI if this transaction is in this wallet
        map<uint256, CWalletTx>::const_iterator mi = mapWallet.find(hashTx);
        if (mi != mapWallet.end())
            NotifyTransactionChanged(this, hashTx, CT_UPDATED);
    }
}

void CWallet::LockCoin(COutPoint& output)
{
<<<<<<< HEAD
=======
    AssertLockHeld(cs_wallet); // setLockedCoins
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    setLockedCoins.insert(output);
}

void CWallet::UnlockCoin(COutPoint& output)
{
<<<<<<< HEAD
=======
    AssertLockHeld(cs_wallet); // setLockedCoins
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    setLockedCoins.erase(output);
}

void CWallet::UnlockAllCoins()
{
<<<<<<< HEAD
=======
    AssertLockHeld(cs_wallet); // setLockedCoins
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    setLockedCoins.clear();
}

bool CWallet::IsLockedCoin(uint256 hash, unsigned int n) const
{
<<<<<<< HEAD
=======
    AssertLockHeld(cs_wallet); // setLockedCoins
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    COutPoint outpt(hash, n);

    return (setLockedCoins.count(outpt) > 0);
}

void CWallet::ListLockedCoins(std::vector<COutPoint>& vOutpts)
{
<<<<<<< HEAD
=======
    AssertLockHeld(cs_wallet); // setLockedCoins
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    for (std::set<COutPoint>::iterator it = setLockedCoins.begin();
         it != setLockedCoins.end(); it++) {
        COutPoint outpt = (*it);
        vOutpts.push_back(outpt);
    }
}

<<<<<<< HEAD
=======
void CWallet::GetKeyBirthTimes(std::map<CKeyID, int64_t> &mapKeyBirth) const {
    AssertLockHeld(cs_wallet); // mapKeyMetadata
    mapKeyBirth.clear();

    // get birth times for keys with metadata
    for (std::map<CKeyID, CKeyMetadata>::const_iterator it = mapKeyMetadata.begin(); it != mapKeyMetadata.end(); it++)
        if (it->second.nCreateTime)
            mapKeyBirth[it->first] = it->second.nCreateTime;

    // map in which we'll infer heights of other keys
    CBlockIndex *pindexMax = chainActive[std::max(0, chainActive.Height() - 144)]; // the tip can be reorganised; use a 144-block safety margin
    std::map<CKeyID, CBlockIndex*> mapKeyFirstBlock;
    std::set<CKeyID> setKeys;
    GetKeys(setKeys);
    BOOST_FOREACH(const CKeyID &keyid, setKeys) {
        if (mapKeyBirth.count(keyid) == 0)
            mapKeyFirstBlock[keyid] = pindexMax;
    }
    setKeys.clear();

    // if there are no such keys, we're done
    if (mapKeyFirstBlock.empty())
        return;

    // find first block that affects those keys, if there are any left
    std::vector<CKeyID> vAffected;
    for (std::map<uint256, CWalletTx>::const_iterator it = mapWallet.begin(); it != mapWallet.end(); it++) {
        // iterate over all wallet transactions...
        const CWalletTx &wtx = (*it).second;
        std::map<uint256, CBlockIndex*>::const_iterator blit = mapBlockIndex.find(wtx.hashBlock);
        if (blit != mapBlockIndex.end() && chainActive.Contains(blit->second)) {
            // ... which are already in a block
            int nHeight = blit->second->nHeight;
            BOOST_FOREACH(const CTxOut &txout, wtx.vout) {
                // iterate over all their outputs
                ::ExtractAffectedKeys(*this, txout.scriptPubKey, vAffected);
                BOOST_FOREACH(const CKeyID &keyid, vAffected) {
                    // ... and all their affected keys
                    std::map<CKeyID, CBlockIndex*>::iterator rit = mapKeyFirstBlock.find(keyid);
                    if (rit != mapKeyFirstBlock.end() && nHeight < rit->second->nHeight)
                        rit->second = blit->second;
                }
                vAffected.clear();
            }
        }
    }

    // Extract block timestamps for those keys
    for (std::map<CKeyID, CBlockIndex*>::const_iterator it = mapKeyFirstBlock.begin(); it != mapKeyFirstBlock.end(); it++)
        mapKeyBirth[it->first] = it->second->nTime - 7200; // block times can be 2h off
}

bool CWallet::AddDestData(const CTxDestination &dest, const std::string &key, const std::string &value)
{
    if (boost::get<CNoDestination>(&dest))
        return false;

    mapAddressBook[dest].destdata.insert(std::make_pair(key, value));
    if (!fFileBacked)
        return true;
    return CWalletDB(strWalletFile).WriteDestData(CBitcoinAddress(dest).ToString(), key, value);
}

bool CWallet::EraseDestData(const CTxDestination &dest, const std::string &key)
{
    if (!mapAddressBook[dest].destdata.erase(key))
        return false;
    if (!fFileBacked)
        return true;
    return CWalletDB(strWalletFile).EraseDestData(CBitcoinAddress(dest).ToString(), key);
}

bool CWallet::LoadDestData(const CTxDestination &dest, const std::string &key, const std::string &value)
{
    mapAddressBook[dest].destdata.insert(std::make_pair(key, value));
    return true;
}

bool CWallet::GetDestData(const CTxDestination &dest, const std::string &key, std::string *value) const
{
    std::map<CTxDestination, CAddressBookData>::const_iterator i = mapAddressBook.find(dest);
    if(i != mapAddressBook.end())
    {
        CAddressBookData::StringMap::const_iterator j = i->second.destdata.find(key);
        if(j != i->second.destdata.end())
        {
            if(value)
                *value = j->second;
            return true;
        }
    }
    return false;
}

// Add an address to the list of fixed change addresses to use. Fixed
// addresses can be used to reduce the pace at which wallets expand
// due to number of change addresses
void AddFixedChangeAddress(const CKeyID &changeAddress)
{
    vChangeAddresses.push_back(changeAddress);
}
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
