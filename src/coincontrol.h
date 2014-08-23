<<<<<<< HEAD
// Copyright (c) 2013-2014 Dogecoin Developers
=======
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

#ifndef COINCONTROL_H
#define COINCONTROL_H

<<<<<<< HEAD
=======
#include "core.h"

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
/** Coin Control Features. */
class CCoinControl
{
public:
    CTxDestination destChange;

    CCoinControl()
    {
        SetNull();
    }
<<<<<<< HEAD
        
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    void SetNull()
    {
        destChange = CNoDestination();
        setSelected.clear();
    }
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    bool HasSelected() const
    {
        return (setSelected.size() > 0);
    }
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    bool IsSelected(const uint256& hash, unsigned int n) const
    {
        COutPoint outpt(hash, n);
        return (setSelected.count(outpt) > 0);
    }
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    void Select(COutPoint& output)
    {
        setSelected.insert(output);
    }
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    void UnSelect(COutPoint& output)
    {
        setSelected.erase(output);
    }
<<<<<<< HEAD
    
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    void UnSelectAll()
    {
        setSelected.clear();
    }

    void ListSelected(std::vector<COutPoint>& vOutpoints)
    {
        vOutpoints.assign(setSelected.begin(), setSelected.end());
    }
<<<<<<< HEAD
        
=======

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
private:
    std::set<COutPoint> setSelected;

};

#endif // COINCONTROL_H
