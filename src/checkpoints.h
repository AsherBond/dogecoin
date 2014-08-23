<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
=======
// Copyright (c) 2009-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifndef BITCOIN_CHECKPOINT_H
#define BITCOIN_CHECKPOINT_H

#include <map>

<<<<<<< HEAD
class uint256;
class CBlockIndex;
=======
class CBlockIndex;
class uint256;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

/** Block-chain checkpoints are compiled-in sanity checks.
 * They are updated every release or three.
 */
namespace Checkpoints
{
    // Returns true if block passes checkpoint checks
    bool CheckBlock(int nHeight, const uint256& hash);

    // Return conservative estimate of total number of blocks, 0 if unknown
    int GetTotalBlocksEstimate();

    // Returns last CBlockIndex* in mapBlockIndex that is a checkpoint
    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex);

    double GuessVerificationProgress(CBlockIndex *pindex);
<<<<<<< HEAD
=======

    extern bool fEnabled;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

#endif
