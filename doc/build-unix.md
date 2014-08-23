<<<<<<< HEAD
Copyright (c) 2009-2013 Bitcoin Developers

Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.

UNIX BUILD NOTES
====================
=======
UNIX BUILD NOTES
====================
Some notes on how to build Dogecoin in Unix. 
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

To Build
---------------------

<<<<<<< HEAD
	cd src/
	make -f makefile.unix		# Headless dogecoin

See readme-qt.rst for instructions on building Litecoin-Qt, the graphical user interface.
=======
	./autogen.sh
	./configure
	make

This will build dogecoin-qt as well if the dependencies are met.
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

Dependencies
---------------------

<<<<<<< HEAD
 Library     Purpose           Description
 -------     -------           -----------
 libssl      SSL Support       Secure communications
 libdb4.8    Berkeley DB       Blockchain & wallet storage
 libboost    Boost             C++ Library
 miniupnpc   UPnP Support      Optional firewall-jumping support

[miniupnpc](http://miniupnp.free.fr/) may be used for UPnP port mapping.  It can be downloaded from [here](
http://miniupnp.tuxfamily.org/files/).  UPnP support is compiled in and
turned off by default.  Set USE_UPNP to a different value to control this:

	USE_UPNP=     No UPnP support miniupnp not required
	USE_UPNP=0    (the default) UPnP support turned off by default at runtime
	USE_UPNP=1    UPnP support turned on by default at runtime

IPv6 support may be disabled by setting:

	USE_IPV6=0    Disable IPv6 support
=======
 Library     | Purpose          | Description
 ------------|------------------|----------------------
 libssl      | SSL Support      | Secure communications
 libdb5.1    | Berkeley DB      | Wallet storage
 libboost    | Boost            | C++ Library
 miniupnpc   | UPnP Support     | Optional firewall-jumping support
 qt          | GUI              | GUI toolkit
 protobuf    | Payments in GUI  | Data interchange format used for payment protocol
 libqrencode | QR codes in GUI  | Optional for generating QR codes

[miniupnpc](http://miniupnp.free.fr/) may be used for UPnP port mapping.  It can be downloaded from [here](
http://miniupnp.tuxfamily.org/files/).  UPnP support is compiled in and
turned off by default.  See the configure options for upnp behavior desired:

	--without-miniupnpc      No UPnP support miniupnp not required
	--disable-upnp-default   (the default) UPnP support turned off by default at runtime
	--enable-upnp-default    UPnP support turned on by default at runtime

IPv6 support may be disabled by setting:

	--disable-ipv6           Disable IPv6 support
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

Licenses of statically linked libraries:
 Berkeley DB   New BSD license with additional requirement that linked
               software must be free open source
 Boost         MIT-like license
 miniupnpc     New (3-clause) BSD license

- Versions used in this release:
-  GCC           4.3.3
<<<<<<< HEAD
-  OpenSSL       1.0.1g
-  Berkeley DB   4.8.30.NC
-  Boost         1.37
-  miniupnpc     1.6
=======
-  OpenSSL       1.0.1c
-  Berkeley DB   5.1.29.NC
-  Boost         1.55
-  miniupnpc     1.6
-  qt            4.8.3
-  protobuf      2.5.0
-  libqrencode   3.2.0
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

Dependency Build Instructions: Ubuntu & Debian
----------------------------------------------
Build requirements:

<<<<<<< HEAD
	sudo apt-get install build-essential
	sudo apt-get install libssl-dev

for Ubuntu 12.04:

	sudo apt-get install libboost-all-dev

 db4.8 packages are available [here](https://launchpad.net/~bitcoin/+archive/bitcoin).

 Ubuntu precise has packages for libdb5.1-dev and libdb5.1++-dev,
 but using these will break binary wallet compatibility, and is not recommended.

for other Ubuntu & Debian:

	sudo apt-get install libdb4.8-dev
	sudo apt-get install libdb4.8++-dev
	sudo apt-get install libboost1.37-dev
 (If using Boost 1.37, append -mt to the boost libraries in the makefile)

Optional:

	sudo apt-get install libminiupnpc-dev (see USE_UPNP compile flag)


Notes
-----
The release is built with GCC and then "strip bitcoind" to strip the debug
=======
	sudo apt-get install build-essential pkg-config
	sudo apt-get install libtool autotools-dev autoconf
	sudo apt-get install libssl-dev

for Ubuntu 12.04 and later:

	sudo apt-get install libboost-all-dev libdb5.1-dev libdb5.1++-dev

for Ubuntu 13.10:
	libboost1.54 will not work,
	remove libboost1.54-all-dev and install libboost1.53-all-dev instead.

for other Ubuntu & Debian:

	sudo apt-get install libdb5.1-dev
	sudo apt-get install libdb5.1++-dev
	sudo apt-get install libboost1.55-all-dev

Optional:

	sudo apt-get install libminiupnpc-dev (see --with-miniupnpc and --enable-upnp-default)

Dependencies for the GUI: Ubuntu & Debian
-----------------------------------------

If you want to build Dogecoin-Qt, make sure that the required packages for Qt development
are installed. Either Qt 4 or Qt 5 are necessary to build the GUI.
If both Qt 4 and Qt 5 are installed, Qt 4 will be used. Pass `--with-gui=qt5` to configure to choose Qt5.
To build without GUI pass `--without-gui`.

To build with Qt 4 you need the following:

    sudo apt-get install libqt4-dev libprotobuf-dev protobuf-compiler

For Qt 5 you need the following:

    sudo apt-get install libqt5gui5 libqt5core5 libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev

libqrencode (optional) can be installed with:

    sudo apt-get install libqrencode-dev

Once these are installed, they will be found by configure and a dogecoin-qt executable will be
built by default.

Notes
-----
The release is built with GCC and then "strip dogecoind" to strip the debug
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
symbols, which reduces the executable size by about 90%.


miniupnpc
---------
	tar -xzvf miniupnpc-1.6.tar.gz
	cd miniupnpc-1.6
	make
	sudo su
	make install


Berkeley DB
-----------
<<<<<<< HEAD
You need Berkeley DB 4.8.  If you have to build Berkeley DB yourself:

	../dist/configure --enable-cxx
	make
=======
You need Berkeley DB 5.1.  If you have to build Berkeley DB yourself:

	cd build_unix/
	../dist/configure --enable-cxx
	make
	sudo make install
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917


Boost
-----
If you need to build Boost yourself:

	sudo su
	./bootstrap.sh
	./bjam install


Dependency Build Instructions: Fedora
-------------------------------------

Tested on Fedora 20:

<<<<<<< HEAD
	sudo yum install openssl-devel
	sudo yum install miniupnpc-devel
	sudo yum install boost-devel
	sudo yum install libdb4-cxx-devel
=======
	sudo yum install autoconf automake make gcc-c++
	sudo yum install openssl-devel
	sudo yum install miniupnpc-devel
	sudo yum install boost-devel
	sudo yum install libdb-cxx-devel
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
	sudo yum install libss-devel
	sudo yum install qrencode

Optional:

	sudo yum install miniupnpc-devel (see USE_UPNP compile flag)



Security
--------
<<<<<<< HEAD
To help make your dogecoin installation more secure by making certain attacks impossible to
exploit even if a vulnerability is found, you can take the following measures:
=======
To help make your bitcoin installation more secure by making certain attacks impossible to
exploit even if a vulnerability is found, binaries are hardened by default.
This can be disabled with:

Hardening Flags:

	./configure --enable-hardening
	./configure --disable-hardening


Hardening enables the following features:
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

* Position Independent Executable
    Build position independent code to take advantage of Address Space Layout Randomization
    offered by some kernels. An attacker who is able to cause execution of code at an arbitrary
    memory location is thwarted if he doesn't know where anything useful is located.
    The stack and heap are randomly located by default but this allows the code section to be
    randomly located as well.

    On an Amd64 processor where a library was not compiled with -fPIC, this will cause an error
    such as: "relocation R_X86_64_32 against `......' can not be used when making a shared object;"

<<<<<<< HEAD
    To build with PIE, use:
    make -f makefile.unix ... -e PIE=1

=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    To test that you have built PIE executable, install scanelf, part of paxutils, and use:

    	scanelf -e ./dogecoin

    The output should contain:
     TYPE
    ET_DYN

* Non-executable Stack
    If the stack is executable then trivial stack based buffer overflow exploits are possible if
    vulnerable buffers are found. By default, bitcoin should be built with a non-executable stack
    but if one of the libraries it uses asks for an executable stack or someone makes a mistake
    and uses a compiler extension which requires an executable stack, it will silently build an
    executable without the non-executable stack protection.

    To verify that the stack is non-executable after compiling use:
    `scanelf -e ./dogecoin`

    the output should contain:
	STK/REL/PTL
	RW- R-- RW-

    The STK RW- means that the stack is readable and writeable but not executable.
<<<<<<< HEAD
=======

Disable-wallet mode
--------------------
When the intention is to run only a P2P node without a wallet, bitcoin may be compiled in
disable-wallet mode with:

    ./configure --disable-wallet

In this case there is no dependency on Berkeley DB 5.1.

Mining is also possible in disable-wallet mode, but only using the `getblocktemplate` RPC
call not `getwork`.

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
