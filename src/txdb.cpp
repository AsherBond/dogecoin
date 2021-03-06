// Copyright (c) 2009-2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
=======
// Copyright (c) 2009-2014 The Bitcoin developers
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "txdb.h"
<<<<<<< HEAD
#include "main.h"
#include "hash.h"
=======

#include "core.h"
#include "uint256.h"

#include <stdint.h>
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

using namespace std;

void static BatchWriteCoins(CLevelDBBatch &batch, const uint256 &hash, const CCoins &coins) {
    if (coins.IsPruned())
        batch.Erase(make_pair('c', hash));
    else
        batch.Write(make_pair('c', hash), coins);
}

void static BatchWriteHashBestChain(CLevelDBBatch &batch, const uint256 &hash) {
    batch.Write('B', hash);
}

CCoinsViewDB::CCoinsViewDB(size_t nCacheSize, bool fMemory, bool fWipe) : db(GetDataDir() / "chainstate", nCacheSize, fMemory, fWipe) {
}

<<<<<<< HEAD
bool CCoinsViewDB::GetCoins(const uint256 &txid, CCoins &coins) { 
    return db.Read(make_pair('c', txid), coins); 
=======
bool CCoinsViewDB::GetCoins(const uint256 &txid, CCoins &coins) {
    return db.Read(make_pair('c', txid), coins);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

bool CCoinsViewDB::SetCoins(const uint256 &txid, const CCoins &coins) {
    CLevelDBBatch batch;
    BatchWriteCoins(batch, txid, coins);
    return db.WriteBatch(batch);
}

bool CCoinsViewDB::HaveCoins(const uint256 &txid) {
<<<<<<< HEAD
    return db.Exists(make_pair('c', txid)); 
}

CBlockIndex *CCoinsViewDB::GetBestBlock() {
    uint256 hashBestChain;
    if (!db.Read('B', hashBestChain))
        return NULL;
    std::map<uint256, CBlockIndex*>::iterator it = mapBlockIndex.find(hashBestChain);
    if (it == mapBlockIndex.end())
        return NULL;
    return it->second;
}

bool CCoinsViewDB::SetBestBlock(CBlockIndex *pindex) {
    CLevelDBBatch batch;
    BatchWriteHashBestChain(batch, pindex->GetBlockHash()); 
    return db.WriteBatch(batch);
}

bool CCoinsViewDB::BatchWrite(const std::map<uint256, CCoins> &mapCoins, CBlockIndex *pindex) {
    printf("Committing %u changed transactions to coin database...\n", (unsigned int)mapCoins.size());
=======
    return db.Exists(make_pair('c', txid));
}

uint256 CCoinsViewDB::GetBestBlock() {
    uint256 hashBestChain;
    if (!db.Read('B', hashBestChain))
        return uint256(0);
    return hashBestChain;
}

bool CCoinsViewDB::SetBestBlock(const uint256 &hashBlock) {
    CLevelDBBatch batch;
    BatchWriteHashBestChain(batch, hashBlock);
    return db.WriteBatch(batch);
}

bool CCoinsViewDB::BatchWrite(const std::map<uint256, CCoins> &mapCoins, const uint256 &hashBlock) {
    LogPrint("coindb", "Committing %u changed transactions to coin database...\n", (unsigned int)mapCoins.size());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    CLevelDBBatch batch;
    for (std::map<uint256, CCoins>::const_iterator it = mapCoins.begin(); it != mapCoins.end(); it++)
        BatchWriteCoins(batch, it->first, it->second);
<<<<<<< HEAD
    if (pindex)
        BatchWriteHashBestChain(batch, pindex->GetBlockHash());
=======
    if (hashBlock != uint256(0))
        BatchWriteHashBestChain(batch, hashBlock);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

    return db.WriteBatch(batch);
}

<<<<<<< HEAD
CBlockTreeDB::CBlockTreeDB(size_t nCacheSize, bool fMemory, bool fWipe) : CLevelDB(GetDataDir() / "blocks" / "index", nCacheSize, fMemory, fWipe) {
=======
CBlockTreeDB::CBlockTreeDB(size_t nCacheSize, bool fMemory, bool fWipe) : CLevelDBWrapper(GetDataDir() / "blocks" / "index", nCacheSize, fMemory, fWipe) {
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

bool CBlockTreeDB::WriteBlockIndex(const CDiskBlockIndex& blockindex)
{
    return Write(make_pair('b', blockindex.GetBlockHash()), blockindex);
}

<<<<<<< HEAD
bool CBlockTreeDB::ReadBestInvalidWork(CBigNum& bnBestInvalidWork)
{
    return Read('I', bnBestInvalidWork);
}

bool CBlockTreeDB::WriteBestInvalidWork(const CBigNum& bnBestInvalidWork)
{
=======
bool CBlockTreeDB::WriteBestInvalidWork(const CBigNum& bnBestInvalidWork)
{
    // Obsolete; only written for backward compatibility.
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    return Write('I', bnBestInvalidWork);
}

bool CBlockTreeDB::WriteBlockFileInfo(int nFile, const CBlockFileInfo &info) {
    return Write(make_pair('f', nFile), info);
}

bool CBlockTreeDB::ReadBlockFileInfo(int nFile, CBlockFileInfo &info) {
    return Read(make_pair('f', nFile), info);
}

bool CBlockTreeDB::WriteLastBlockFile(int nFile) {
    return Write('l', nFile);
}

bool CBlockTreeDB::WriteReindexing(bool fReindexing) {
    if (fReindexing)
        return Write('R', '1');
    else
        return Erase('R');
}

bool CBlockTreeDB::ReadReindexing(bool &fReindexing) {
    fReindexing = Exists('R');
    return true;
}

bool CBlockTreeDB::ReadLastBlockFile(int &nFile) {
    return Read('l', nFile);
}

bool CCoinsViewDB::GetStats(CCoinsStats &stats) {
    leveldb::Iterator *pcursor = db.NewIterator();
    pcursor->SeekToFirst();

    CHashWriter ss(SER_GETHASH, PROTOCOL_VERSION);
<<<<<<< HEAD
    stats.hashBlock = GetBestBlock()->GetBlockHash();
    ss << stats.hashBlock;
    int64 nTotalAmount = 0;
=======
    stats.hashBlock = GetBestBlock();
    ss << stats.hashBlock;
    int64_t nTotalAmount = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    while (pcursor->Valid()) {
        boost::this_thread::interruption_point();
        try {
            leveldb::Slice slKey = pcursor->key();
            CDataStream ssKey(slKey.data(), slKey.data()+slKey.size(), SER_DISK, CLIENT_VERSION);
            char chType;
            ssKey >> chType;
            if (chType == 'c') {
                leveldb::Slice slValue = pcursor->value();
                CDataStream ssValue(slValue.data(), slValue.data()+slValue.size(), SER_DISK, CLIENT_VERSION);
                CCoins coins;
                ssValue >> coins;
                uint256 txhash;
                ssKey >> txhash;
                ss << txhash;
                ss << VARINT(coins.nVersion);
<<<<<<< HEAD
                ss << (coins.fCoinBase ? 'c' : 'n'); 
=======
                ss << (coins.fCoinBase ? 'c' : 'n');
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
                ss << VARINT(coins.nHeight);
                stats.nTransactions++;
                for (unsigned int i=0; i<coins.vout.size(); i++) {
                    const CTxOut &out = coins.vout[i];
                    if (!out.IsNull()) {
                        stats.nTransactionOutputs++;
                        ss << VARINT(i+1);
                        ss << out;
                        nTotalAmount += out.nValue;
                    }
                }
                stats.nSerializedSize += 32 + slValue.size();
                ss << VARINT(0);
            }
            pcursor->Next();
        } catch (std::exception &e) {
<<<<<<< HEAD
            return error("%s() : deserialize error", __PRETTY_FUNCTION__);
        }
    }
    delete pcursor;
    stats.nHeight = GetBestBlock()->nHeight;
=======
            return error("%s : Deserialize or I/O error - %s", __PRETTY_FUNCTION__, e.what());
        }
    }
    delete pcursor;
    stats.nHeight = mapBlockIndex.find(GetBestBlock())->second->nHeight;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    stats.hashSerialized = ss.GetHash();
    stats.nTotalAmount = nTotalAmount;
    return true;
}

bool CBlockTreeDB::ReadTxIndex(const uint256 &txid, CDiskTxPos &pos) {
    return Read(make_pair('t', txid), pos);
}

bool CBlockTreeDB::WriteTxIndex(const std::vector<std::pair<uint256, CDiskTxPos> >&vect) {
    CLevelDBBatch batch;
    for (std::vector<std::pair<uint256,CDiskTxPos> >::const_iterator it=vect.begin(); it!=vect.end(); it++)
        batch.Write(make_pair('t', it->first), it->second);
    return WriteBatch(batch);
}

bool CBlockTreeDB::WriteFlag(const std::string &name, bool fValue) {
    return Write(std::make_pair('F', name), fValue ? '1' : '0');
}

bool CBlockTreeDB::ReadFlag(const std::string &name, bool &fValue) {
    char ch;
    if (!Read(std::make_pair('F', name), ch))
        return false;
    fValue = ch == '1';
    return true;
}

bool CBlockTreeDB::LoadBlockIndexGuts()
{
    leveldb::Iterator *pcursor = NewIterator();

    CDataStream ssKeySet(SER_DISK, CLIENT_VERSION);
    ssKeySet << make_pair('b', uint256(0));
    pcursor->Seek(ssKeySet.str());

    // Load mapBlockIndex
    while (pcursor->Valid()) {
        boost::this_thread::interruption_point();
        try {
            leveldb::Slice slKey = pcursor->key();
            CDataStream ssKey(slKey.data(), slKey.data()+slKey.size(), SER_DISK, CLIENT_VERSION);
            char chType;
            ssKey >> chType;
            if (chType == 'b') {
                leveldb::Slice slValue = pcursor->value();
                CDataStream ssValue(slValue.data(), slValue.data()+slValue.size(), SER_DISK, CLIENT_VERSION);
                CDiskBlockIndex diskindex;
                ssValue >> diskindex;

                // Construct block index object
                CBlockIndex* pindexNew = InsertBlockIndex(diskindex.GetBlockHash());
                pindexNew->pprev          = InsertBlockIndex(diskindex.hashPrev);
                pindexNew->nHeight        = diskindex.nHeight;
                pindexNew->nFile          = diskindex.nFile;
                pindexNew->nDataPos       = diskindex.nDataPos;
                pindexNew->nUndoPos       = diskindex.nUndoPos;
                pindexNew->nVersion       = diskindex.nVersion;
                pindexNew->hashMerkleRoot = diskindex.hashMerkleRoot;
                pindexNew->nTime          = diskindex.nTime;
                pindexNew->nBits          = diskindex.nBits;
                pindexNew->nNonce         = diskindex.nNonce;
                pindexNew->nStatus        = diskindex.nStatus;
                pindexNew->nTx            = diskindex.nTx;

<<<<<<< HEAD
                // Watch for genesis block
                if (pindexGenesisBlock == NULL && diskindex.GetBlockHash() == hashGenesisBlock)
                    pindexGenesisBlock = pindexNew;

                if (!pindexNew->CheckIndex())
                    return error("LoadBlockIndex() : CheckIndex failed: %s", pindexNew->ToString().c_str());
=======
                if (!pindexNew->CheckIndex())
                    return error("LoadBlockIndex() : CheckIndex failed: %s", pindexNew->ToString());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

                pcursor->Next();
            } else {
                break; // if shutdown requested or finished loading block index
            }
        } catch (std::exception &e) {
<<<<<<< HEAD
            return error("%s() : deserialize error", __PRETTY_FUNCTION__);
=======
            return error("%s : Deserialize or I/O error - %s", __PRETTY_FUNCTION__, e.what());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
        }
    }
    delete pcursor;

    return true;
}
