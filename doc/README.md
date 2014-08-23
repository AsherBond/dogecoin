<<<<<<< HEAD
Dogecoin 0.8.x BETA
====================

Copyright (c) 2009-2013 Bitcoin Developers
Copyright (c) 2011-2013 Litecoin Developers
Copyright (c) 2013- Dogecoin Developers

Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.


Intro
---------------------
Dogecoin is a free open source peer-to-peer electronic cash system that is
completely decentralized, without the need for a central server or trusted
parties.  Users hold the crypto keys to their own money and transact directly
with each other, with the help of a P2P network to check for double-spending.


Setup
---------------------
You need the Qt4 run-time libraries to run Dogecoin-Qt. On Debian or Ubuntu:
        `sudo apt-get install libqtgui4`

Unpack the files into a directory and run:

- bin/32/Dogecoin-qt (GUI, 32-bit)
- bin/32/Dogecoind (headless, 32-bit)
- bin/64/Dogecoin-qt (GUI, 64-bit)
- bin/64/Dogecoind (headless, 64-bit)

See the documentation at (http://www.Dogecoin.com)
for help and more information.
                                                                                                                                                                           
                                                                                                                                                                           
Other Pages                                                                                                                                                                
---------------------                                                                                                                                                      
- [Unix Build Notes](build-unix.md)                                                                                                                                        
- [OSX Build Notes](build-osx.md)                                                                                                                                          
- [Windows Build Notes](build-msw.md)                                                                                                                                      
- [Coding Guidelines](coding.md)                                                                                                                                           
- [Release Process](release-process.md)                                                                                                                                    
- [Release Notes](release-notes.md)                                                                                                                                        
- [Multiwallet Qt Development](multiwallet-qt.md)                                                                                                                          
- [Unit Tests](unit-tests.md)                                                                                                                                              
- [Translation Process](translation_process.md)
=======
Dogecoin 1.7
=====================

* Copyright (c) 2009-2014 Bitcoin Developers
* Copyright (c) 2011-2013 Litecoin Developers
* Copyright (c) 2013-2014 Dogecoin Developers


Setup
---------------------
[Dogecoin Core](http://dogecoin.com/en/download) is the original Dogecoin client and it builds the backbone of the network. However, it downloads and stores the entire history of Dogecoin transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once.

Running
---------------------
The following are some helpful notes on how to run Dogecoin on your native platform. 

### Unix

You need the Qt4 run-time libraries to run Dogecoin-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/dogecoin-qt (GUI, 32-bit) or bin/32/dogecoind (headless, 32-bit)
- bin/64/dogecoin-qt (GUI, 64-bit) or bin/64/dogecoind (headless, 64-bit)



### Windows

Unpack the files into a directory, and then run dogecoin-qt.exe.

### OSX

Drag Dogecoin-Qt to your applications folder, and then run Dogecoin-Qt.

### Need Help?

* See the documentation at the [Dogecoin Wiki](http://dogeco.in/)
for help and more information.
* Ask for help on [#dogecoin](http://webchat.freenode.net?channels=dogecoin) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=dogecoin).
* Ask for help on the [/r/dogeducation subreddit](http://reddit.com/r/dogeducation).

Building
---------------------
The following are developer notes on how to build Dogecoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-msw.md)

Development
---------------------
The Dogecoin repo's [root README](https://github.com/dogecoin/dogecoin/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/bitcoin/doxygen/)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Resources
* Discuss on the [/r/dogecoindev](http://www.reddit.com/r/dogecoindev) subreddit.
* Discuss on [#dogecoin-dev](http://webchat.freenode.net/?channels=dogecoin-dev) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=dogecoin-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
