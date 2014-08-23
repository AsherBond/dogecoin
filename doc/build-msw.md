<<<<<<< HEAD
Copyright (c) 2009-2013 Bitcoin Developers
Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.


See readme-qt.rst for instructions on building Litecoin-Qt, the
graphical user interface.

WINDOWS BUILD NOTES
===================

Compilers Supported
-------------------
TODO: What works?
Note: releases are cross-compiled using mingw running on Linux.
=======
WINDOWS BUILD NOTES
===================


Compilers Supported
-------------------
Compilation under Windows is supported using MinGW (http://www.mingw.org/)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917


Dependencies
------------
<<<<<<< HEAD
Libraries you need to download separately and build:

                default path               download
OpenSSL         \openssl-1.0.1g-mgw        http://www.openssl.org/source/
Berkeley DB     \db-4.8.30.NC-mgw          http://www.oracle.com/technology/software/products/berkeley-db/index.html
Boost           \boost-1.50.0-mgw          http://www.boost.org/users/download/
miniupnpc       \miniupnpc-1.6-mgw         http://miniupnp.tuxfamily.org/files/
=======
To build Dogecoin for Windows, there are number of libraries you need to download
separately and build. Note that, for those used to a Linux/UNIX background, the search
paths for include files is not the conventional UNIX directories, see
http://www.mingw.org/wiki/IncludePathHOWTO for more details. Library files can be placed
in the more conventional /usr/local/lib directory, but see
http://www.mingw.org/wiki/HOWTO_Specify_the_Location_of_Libraries_for_use_with_MinGW in
case of difficulties.

In both cases, include and library files will need to be placed in the relevant directories
for the build process to succeed.

	name            default path               download
	--------------------------------------------------------------------------------------------------------------------
	OpenSSL         \openssl-1.0.1c-mgw        http://www.openssl.org/source/
	Berkeley DB     \db-5.1.29.NC-mgw          http://www.oracle.com/technology/software/products/berkeley-db/index.html
	Boost           \boost-1.55.0-mgw          http://www.boost.org/users/download/
	miniupnpc       \miniupnpc-1.6-mgw         http://miniupnp.tuxfamily.org/files/
    qt                                         http://download.qt-project.org/official_releases/qt/5.2/5.2.1/
    protobuf                                   http://protobuf.googlecode.com/files/protobuf-2.5.0.zip
    libpng                                     http://prdownloads.sourceforge.net/libpng/libpng-1.6.9.tar.gz?download
    libqrencode                                http://fukuchi.org/works/qrencode/qrencode-3.4.3.tar.gz
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

Their licenses:

	OpenSSL        Old BSD license with the problematic advertising requirement
	Berkeley DB    New BSD license with additional requirement that linked software must be free open source
	Boost          MIT-like license
	miniupnpc      New (3-clause) BSD license
<<<<<<< HEAD

Versions used in this release:

	OpenSSL      1.0.1g
	Berkeley DB  4.8.30.NC
	Boost        1.50.0
	miniupnpc    1.6
=======
    qt             
    protobuf       
    libpng         
    libqrencode    

Versions used in this release:

	OpenSSL      1.0.1c
	Berkeley DB  5.1.29.NC
	Boost        1.55.0
	miniupnpc    1.6
    qt           4.8.3
    protobuf     2.5.0
    libpng       1.6.9
    libqrencode  3.2.0
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917


OpenSSL
-------
MSYS shell:

un-tar sources with MSYS 'tar xfz' to avoid issue with symlinks (OpenSSL ticket 2377)
change 'MAKE' env. variable from 'C:\MinGW32\bin\mingw32-make.exe' to '/c/MinGW32/bin/mingw32-make.exe'

<<<<<<< HEAD
	cd /c/openssl-1.0.1g-mgw
=======
	cd /c/openssl-1.0.1c-mgw
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
	./config
	make

Berkeley DB
-----------
MSYS shell:

<<<<<<< HEAD
	cd /c/db-4.8.30.NC-mgw/build_unix
	sh ../dist/configure --enable-mingw --enable-cxx
	make

Boost
-----
DOS prompt:

	downloaded boost jam 3.1.18
	cd \boost-1.50.0-mgw
	bjam toolset=gcc --build-type=complete stage
=======
	cd /c/db-5.1.29.NC-mgw/build_unix
	sh ../dist/configure --enable-mingw --enable-cxx
	make

Include and library files files should then be placed into MinGW search paths, for example:

Include: C:\MinGW\lib\gcc\mingw32\4.8.1\include\c++
Library: C:\MinGW\lib
    
Boost
-----
MSYS shell:

	cd boost_1_55_0/tools/build/v2/engine
    ./build.sh mingw
    cp bin.ntx86/bjam.exe ../../../../
    cd ../../../../
    bjam --toolset=gcc
    
In case of problems, http://stackoverflow.com/questions/13256788/building-boost-1-52-with-mingw may be useful
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

MiniUPnPc
---------
UPnP support is optional, make with `USE_UPNP=` to disable it.

MSYS shell:

	cd /c/miniupnpc-1.6-mgw
	make -f Makefile.mingw
	mkdir miniupnpc
	cp *.h miniupnpc/

<<<<<<< HEAD
Litecoin
-------
DOS prompt:

	cd \dogecoin\src
	mingw32-make -f makefile.mingw
=======
Dogecoin
-------
MSYS shell:

	dogecoin
	./autogen.sh
	BOOST_ROOT=../boost_1_55_0 ./configure --disable-tests
	mingw32-make
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
	strip dogecoind.exe
