<<<<<<< HEAD
# Dogecoin [DOGE, Ð]
Dogecoin is an open source peer-to-peer cryptocurrency, favored by Shiba Inus worldwide.

![DogeCoin](http://static.tumblr.com/ppdj5y9/Ae9mxmxtp/300coin.png)

## Such coin (What is Dogecoin?)
Dogecoin is like Bitcoin, but based on Litecoin, and also much more wow.
http://dogecoin.com/

## Much license (License)
Dogecoin is released under the terms of the MIT license. See [COPYING](COPYING)
for more information or see http://opensource.org/licenses/MIT.

## Omg developers (Development and contributions)
Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

## Very Much Asked Questions (FAQ)

### How much coin? (Release of new Dogecoins)
Early 2015 (approximately a year and a half after release) there will be approximately 100,000,000,000 coins.
Each subsequent block will grant 10,000 coins to encourage miners to continue to secure the network and make up for lost wallets on hard drives/phones/lost encryption passwords/etc.
For the block schedule, see http://en.wikipedia.org/wiki/Dogecoin#Block_schedule

### How get many doge? (How to mine)
Scrypt Proof of Work

1 Minute Block Targets, 4 Hour Diff Readjustments

Special reward system: Random block rewards before block 145,000. Static block reward afterwards according to chart:

1-100,000: 0-1,000,000 Dogecoin Reward (random)

100,001 —144,999: 0-500,000 Dogecoin Reward (random)

145,000 — 200,000: 250,000 Dogecoin Reward (flat)

200,001 — 300,000: 125,000 Dogecoin Reward (flat)

300,001 — 400,000: 62,500 Dogecoin Reward (flat)

400,001 - 500,000: 31,250 Dogecoin Reward (flat)

500,001 - 600,000: 15,625 Dogecoin Reward (flat)

600,001+ — 10,000 Reward (flat)

### Wow - Plz make dogecoind (How to build `dogecoind`)
```bash
sudo apt-get install build-essential \
                     libssl-dev \
                     libdb5.1++-dev \
                     libboost-all-dev \
                     libqrencode-dev \
                     libminiupnpc-dev

cd src/
make -f makefile.unix USE_UPNP=1 USE_IPV6=1 USE_QRCODE=1
```
### Such ports (Ports)
=======
# Dogecoin Core [DOGE, Ð]
==========================

![Dogecoin](http://static.tumblr.com/ppdj5y9/Ae9mxmxtp/300coin.png)

[![Build Status](https://travis-ci.org/dogecoin/dogecoin.svg?branch=1.7-dev)](https://travis-ci.org/dogecoin/dogecoin)

## What is Dogecoin? – Such coin
Dogecoin is a cryptocurrency like Bitcoin, although it does not use SHA256 as its proof of work (POW). Taking development cues from Tenebrix and Litecoin, Dogecoin currently employs a simplified variant of scrypt.

http://dogecoin.com/

## License – Much license
Dogecoin is released under the terms of the MIT license. See [COPYING](COPYING)
for more information or see http://opensource.org/licenses/MIT.

## Development and contributions – omg developers
Development is ongoing and the development team as well as other volunteers can freely work in their own trees and submit pull requests when features or bug fixes are ready.

## Very Much Frequently Asked Questions

### How much doge can exist? – So many puppies!
Early 2015 (approximately a year and a half after release) there will be approximately 100,000,000,000 coins.
Each subsequent block will grant 10,000 coins to encourage miners to continue to secure the network and make up for lost wallets on hard drives/phones/lost encryption passwords/etc.

### How to get doge? – To the moon!
Dogecoin uses a simplified variant of the scrypt key derivation function as its proof of work with a target time of one minute per block and difficulty readjustment after every block. The block rewards are fixed and halve every 100,000 blocks. Starting with the 600,000th block, a permanent reward of 10,000 Dogecoin per block will be paid. 

Originally, a different payout scheme was envisioned with block rewards being determined by taking the maximum reward as per the block schedule and applying the result of a Mersenne Twister pseudo-random number generator to arrive at a number between 0 and the maximum reward. This was changed, starting with block 145,000, to prevent large pools from gaming the system and mining only high reward blocks. At the same time, the difficulty retargeting was also changed from four hours to once per block (every minute), implementing an algorithm courtesy of the DigiByte Coin development team, to lessen the impact of sudden increases and decreases of network hashing rate.

The current block reward schedule:

1–99,000: 0–1,000,000 Dogecoin 

100,000–144,999: 0–500,000 Dogecoin

145,000–199,999: 250,000 Dogecoin

200,000–299,999: 125,000 Dogecoin

300,000–399,999: 62,500 Dogecoin

400,000–499,999: 31,250 Dogecoin

500,000–599,999: 15,625 Dogecoin

600,000+: 10,000 Dogecoin

The original block reward schedule with one-minute block targets and four-hour difficulty readjustment:

1–99,000: 0–1,000,000 Dogecoin 

100,000–199,999: 0–500,000 Dogecoin

200,000–299,999: 0–250,000 Dogecoin

300,000–399,999: 0–125,000 Dogecoin

400,000–499,999: 0–62,500 Dogecoin

500,000–599,999: 0–31,250 Dogecoin

600,000+: 10,000 Dogecoin

### Wow plz make dogecoind/dogecoin-cli/dogecoin-qt

  The following are developer notes on how to build Dogecoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

  - [OSX Build Notes](doc/build-osx.md)
  - [Unix Build Notes](doc/build-unix.md)
  - [Windows Build Notes](doc/build-msw.md)

### Such ports
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
RPC 22555
P2P 22556

![](http://dogesay.com/wow//////such/coin)
