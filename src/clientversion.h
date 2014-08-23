<<<<<<< HEAD
// Copyright (c) 2013-2014 Dogecoin Developers

#ifndef CLIENTVERSION_H
#define CLIENTVERSION_H

=======
#ifndef CLIENTVERSION_H
#define CLIENTVERSION_H

#if defined(HAVE_CONFIG_H)
#include "bitcoin-config.h"
#else
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
//
// client versioning and copyright year
//

<<<<<<< HEAD
// These need to be macros, as version.cpp's and bitcoin-qt.rc's voodoo requires it
#define CLIENT_VERSION_MAJOR       1
#define CLIENT_VERSION_MINOR       6
#define CLIENT_VERSION_REVISION    1
=======
// These need to be macros, as version.cpp's and dogecoin-qt.rc's voodoo requires it
#define CLIENT_VERSION_MAJOR       1
#define CLIENT_VERSION_MINOR       7
#define CLIENT_VERSION_REVISION    0
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#define CLIENT_VERSION_BUILD       0

// Set to true for release, false for prerelease or test build
#define CLIENT_VERSION_IS_RELEASE  true

// Copyright year (2009-this)
// Todo: update this when changing our copyright comments in the source
#define COPYRIGHT_YEAR 2014

<<<<<<< HEAD
=======
#endif //HAVE_CONFIG_H

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
// Converts the parameter X to a string after macro replacement on X has been performed.
// Don't merge these into one macro!
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X

#endif // CLIENTVERSION_H
