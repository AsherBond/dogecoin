<<<<<<< HEAD
#include <QtGlobal>
=======


#include <QtGlobal>

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
// Automatically generated by extract_strings.py
#ifdef __GNUC__
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif
static const char UNUSED *bitcoin_strings[] = {
QT_TRANSLATE_NOOP("bitcoin-core", ""
"%s, you must set a rpcpassword in the configuration file:\n"
"%s\n"
"It is recommended you use the following random password:\n"
"rpcuser=dogecoinrpc\n"
"rpcpassword=%s\n"
"(you do not need to remember this password)\n"
"The username and password MUST NOT be the same.\n"
"If the file does not exist, create it with owner-readable-only file "
"permissions.\n"
"It is also recommended to set alertnotify so you are notified of problems;\n"
<<<<<<< HEAD
"for example: alertnotify=echo %%s | mail -s \"Dogecoin Alert\" admin@foo.com\n"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Acceptable ciphers (default: TLSv1+HIGH:!SSLv2:!aNULL:!eNULL:!AH:!3DES:"
"@STRENGTH)"),
=======
"for example: alertnotify=echo %%s | mail -s \"Dogecoin Alert\" admin@foo."
"com\n"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Acceptable ciphers (default: TLSv1.2+HIGH:TLSv1+HIGH:!SSLv2:!aNULL:!eNULL:!"
"3DES:@STRENGTH)"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", ""
"An error occurred while setting up the RPC port %u for listening on IPv4: %s"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"An error occurred while setting up the RPC port %u for listening on IPv6, "
"falling back to IPv4: %s"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Bind to given address and always listen on it. Use [host]:port notation for "
"IPv6"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Cannot obtain a lock on data directory %s. Dogecoin is probably already "
"running."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
<<<<<<< HEAD
=======
"Enter regression test mode, which uses a special chain in which blocks can "
"be solved instantly. This is intended for regression testing tools and app "
"development."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Enter regression test mode, which uses a special chain in which blocks can "
"be solved instantly."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Error: Listening for incoming connections failed (listen returned error %d)"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
"Error: The transaction was rejected! This might happen if some of the coins "
"in your wallet were already spent, such as if you used a copy of wallet.dat "
"and coins were spent in the copy but not marked as spent here."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Error: This transaction requires a transaction fee of at least %s because of "
"its amount, complexity, or use of recently received funds!"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
<<<<<<< HEAD
"Execute command when a relevant alert is received (%s in cmd is replaced by "
"message)"),
=======
"Execute command when a relevant alert is received or we see a really long "
"fork (%s in cmd is replaced by message)"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Execute command when a wallet transaction changes (%s in cmd is replaced by "
"TxID)"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Execute command when the best block changes (%s in cmd is replaced by block "
"hash)"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Listen for JSON-RPC connections on <port> (default: 22555 or testnet: 44555)"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Number of seconds to keep misbehaving peers from reconnecting (default: "
"86400)"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
<<<<<<< HEAD
"Set maximum size of high-priority/low-fee transactions in bytes (default: "
"27000)"),
=======
"Output debugging information (default: 0, supplying <category> is optional)"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Set maximum size of high-priority/low-fee transactions in bytes (default: %d)"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Set the number of script verification threads (up to 16, 0 = auto, <0 = "
"leave that many cores free, default: 0)"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"This is a pre-release test build - use at your own risk - do not use for "
"mining or merchant applications"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
<<<<<<< HEAD
"Unable to bind to %s on this computer. Dogecoin is probably already running."),
=======
"Unable to bind to %s on this computer. Dogecoin Core Daemon is probably "
"already running."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Use separate SOCKS5 proxy to reach peers via Tor hidden services (default: -"
"proxy)"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Warning: -paytxfee is set very high! This is the transaction fee you will "
"pay if you send a transaction."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Warning: Displayed transactions may not be correct! You may need to upgrade, "
"or other nodes may need to upgrade."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Warning: Please check that your computer's date and time are correct! If "
"your clock is wrong Dogecoin will not work properly."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
<<<<<<< HEAD
=======
"Warning: The network does not appear to fully agree! Some miners appear to "
"be experiencing issues."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
"Warning: error reading wallet.dat! All keys read correctly, but transaction "
"data or address book entries might be missing or incorrect."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Warning: wallet.dat corrupt, data salvaged! Original wallet.dat saved as "
"wallet.{timestamp}.bak in %s; if your balance or transactions are incorrect "
"you should restore from a backup."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
<<<<<<< HEAD
"When creating transactions, ignore inputs with value less than this "
"(default: 1000000)"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
"You must set rpcpassword=<password> in the configuration file:\n"
"%s\n"
"If the file does not exist, create it with owner-readable-only file "
"permissions."),
<<<<<<< HEAD
=======
QT_TRANSLATE_NOOP("bitcoin-core", "<category> can be:"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Accept command line and JSON-RPC commands"),
QT_TRANSLATE_NOOP("bitcoin-core", "Accept connections from outside (default: 1 if no -proxy or -connect)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Add a node to connect to and attempt to keep the connection open"),
QT_TRANSLATE_NOOP("bitcoin-core", "Allow DNS lookups for -addnode, -seednode and -connect"),
QT_TRANSLATE_NOOP("bitcoin-core", "Allow JSON-RPC connections from specified IP address"),
QT_TRANSLATE_NOOP("bitcoin-core", "Allow peers to set bloom filters (default: 1)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Attempt to recover private keys from a corrupt wallet.dat"),
QT_TRANSLATE_NOOP("bitcoin-core", "Block creation options:"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cannot downgrade wallet"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cannot resolve -bind address: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cannot resolve -externalip address: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cannot write default address"),
<<<<<<< HEAD
QT_TRANSLATE_NOOP("bitcoin-core", "Connect only to the specified node(s)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Connect through socks proxy"),
QT_TRANSLATE_NOOP("bitcoin-core", "Connect to a node to retrieve peer addresses, and disconnect"),
QT_TRANSLATE_NOOP("bitcoin-core", "Corrupted block database detected"),
QT_TRANSLATE_NOOP("bitcoin-core", "Discover own IP address (default: 1 when listening and no -externalip)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Do you want to rebuild the block database now?"),
QT_TRANSLATE_NOOP("bitcoin-core", "Dogecoin version"),
=======
QT_TRANSLATE_NOOP("bitcoin-core", "Clear list of wallet transactions (diagnostic tool; implies -rescan)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Connect only to the specified node(s)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Connect through SOCKS proxy"),
QT_TRANSLATE_NOOP("bitcoin-core", "Connect to JSON-RPC on <port> (default: 22555 or testnet: 44555)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Connect to a node to retrieve peer addresses, and disconnect"),
QT_TRANSLATE_NOOP("bitcoin-core", "Corrupted block database detected"),
QT_TRANSLATE_NOOP("bitcoin-core", "Discover own IP address (default: 1 when listening and no -externalip)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Do not load the wallet and disable wallet RPC calls"),
QT_TRANSLATE_NOOP("bitcoin-core", "Do you want to rebuild the block database now?"),
QT_TRANSLATE_NOOP("bitcoin-core", "Dogecoin Core Daemon"),
QT_TRANSLATE_NOOP("bitcoin-core", "Dogecoin RPC client version"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Done loading"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error initializing block database"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error initializing wallet database environment %s!"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error loading block database"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error loading wallet.dat"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error loading wallet.dat: Wallet corrupted"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error loading wallet.dat: Wallet requires newer version of Dogecoin"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error opening block database"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error: Disk space is low!"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error: Wallet locked, unable to create transaction!"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error: system error: "),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to listen on any port. Use -listen=0 if you want this."),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to read block info"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to read block"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to sync block index"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to write block index"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to write block info"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to write block"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to write file info"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to write to coin database"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to write transaction index"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to write undo data"),
<<<<<<< HEAD
QT_TRANSLATE_NOOP("bitcoin-core", "Fee per KB to add to transactions you send"),
QT_TRANSLATE_NOOP("bitcoin-core", "Find peers using DNS lookup (default: 1 unless -connect)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Find peers using internet relay chat (default: 0)"),
=======
QT_TRANSLATE_NOOP("bitcoin-core", "Fee per kB to add to transactions you send"),
QT_TRANSLATE_NOOP("bitcoin-core", "Find peers using DNS lookup (default: 1 unless -connect)"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Generate coins (default: 0)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Get help for a command"),
QT_TRANSLATE_NOOP("bitcoin-core", "How many blocks to check at startup (default: 288, 0 = all)"),
QT_TRANSLATE_NOOP("bitcoin-core", "How thorough the block verification is (0-4, default: 3)"),
<<<<<<< HEAD
=======
QT_TRANSLATE_NOOP("bitcoin-core", "If <category> is not supplied, output all debugging information."),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Imports blocks from external blk000??.dat file"),
QT_TRANSLATE_NOOP("bitcoin-core", "Incorrect or no genesis block found. Wrong datadir for network?"),
QT_TRANSLATE_NOOP("bitcoin-core", "Information"),
QT_TRANSLATE_NOOP("bitcoin-core", "Insufficient funds"),
<<<<<<< HEAD
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid -proxy address: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid -tor address: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount for -mininput=<amount>: '%s'"),
=======
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid -onion address: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid -proxy address: '%s'"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount for -minrelaytxfee=<amount>: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount for -mintxfee=<amount>: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount for -paytxfee=<amount>: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount"),
QT_TRANSLATE_NOOP("bitcoin-core", "List commands"),
QT_TRANSLATE_NOOP("bitcoin-core", "Listen for connections on <port> (default: 22556 or testnet: 44556)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading addresses..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading block index..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading wallet..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Maintain a full transaction index (default: 0)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Maintain at most <n> connections to peers (default: 125)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Maximum per-connection receive buffer, <n>*1000 bytes (default: 5000)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Maximum per-connection send buffer, <n>*1000 bytes (default: 1000)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Not enough file descriptors available."),
QT_TRANSLATE_NOOP("bitcoin-core", "Only accept block chain matching built-in checkpoints (default: 1)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Only connect to nodes in network <net> (IPv4, IPv6 or Tor)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Options:"),
<<<<<<< HEAD
QT_TRANSLATE_NOOP("bitcoin-core", "Output extra debugging information. Implies all other -debug* options"),
QT_TRANSLATE_NOOP("bitcoin-core", "Output extra network debugging information"),
QT_TRANSLATE_NOOP("bitcoin-core", "Password for JSON-RPC connections"),
QT_TRANSLATE_NOOP("bitcoin-core", "Prepend debug output with timestamp (default: 1)"),
=======
QT_TRANSLATE_NOOP("bitcoin-core", "Password for JSON-RPC connections"),
QT_TRANSLATE_NOOP("bitcoin-core", "Prepend debug output with timestamp (default: 1)"),
QT_TRANSLATE_NOOP("bitcoin-core", "RPC client options:"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Rebuild block chain index from current blk000??.dat files"),
QT_TRANSLATE_NOOP("bitcoin-core", "Rescan the block chain for missing wallet transactions"),
QT_TRANSLATE_NOOP("bitcoin-core", "Rescanning..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Run in the background as a daemon and accept commands"),
<<<<<<< HEAD
QT_TRANSLATE_NOOP("bitcoin-core", "SSL options: (see the Dogecoin Wiki for SSL setup instructions)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Select the version of socks proxy to use (4-5, default: 5)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Send command to -server or dogecoind"),
QT_TRANSLATE_NOOP("bitcoin-core", "Send commands to node running on <ip> (default: 127.0.0.1)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Send trace/debug info to console instead of debug.log file"),
QT_TRANSLATE_NOOP("bitcoin-core", "Send trace/debug info to debugger"),
QT_TRANSLATE_NOOP("bitcoin-core", "Server certificate file (default: server.cert)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Server private key (default: server.pem)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Set database cache size in megabytes (default: 25)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Set key pool size to <n> (default: 100)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Set maximum block size in bytes (default: 250000)"),
=======
QT_TRANSLATE_NOOP("bitcoin-core", "SSL options: (see the Bitcoin Wiki for SSL setup instructions)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Select SOCKS version for -proxy (4 or 5, default: 5)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Send command to Dogecoin server"),
QT_TRANSLATE_NOOP("bitcoin-core", "Send commands to node running on <ip> (default: 127.0.0.1)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Send trace/debug info to console instead of debug.log file"),
QT_TRANSLATE_NOOP("bitcoin-core", "Server certificate file (default: server.cert)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Server private key (default: server.pem)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Set database cache size in megabytes (%d to %d, default: %d)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Set key pool size to <n> (default: 100)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Set maximum block size in bytes (default: %d)"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Set minimum block size in bytes (default: 0)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Set the number of threads to service RPC calls (default: 4)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Shrink debug.log file on client startup (default: 1 when no -debug)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Signing transaction failed"),
QT_TRANSLATE_NOOP("bitcoin-core", "Specify configuration file (default: dogecoin.conf)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Specify connection timeout in milliseconds (default: 5000)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Specify data directory"),
QT_TRANSLATE_NOOP("bitcoin-core", "Specify pid file (default: dogecoind.pid)"),
<<<<<<< HEAD
QT_TRANSLATE_NOOP("bitcoin-core", "Specify your own public address"),
QT_TRANSLATE_NOOP("bitcoin-core", "System error: "),
QT_TRANSLATE_NOOP("bitcoin-core", "This help message"),
=======
QT_TRANSLATE_NOOP("bitcoin-core", "Specify wallet file (within data directory)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Specify your own public address"),
QT_TRANSLATE_NOOP("bitcoin-core", "Spend unconfirmed change when sending transactions (default: 1)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Start Dogecoin server"),
QT_TRANSLATE_NOOP("bitcoin-core", "System error: "),
QT_TRANSLATE_NOOP("bitcoin-core", "This help message"),
QT_TRANSLATE_NOOP("bitcoin-core", "This is intended for regression testing tools and app development."),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Threshold for disconnecting misbehaving peers (default: 100)"),
QT_TRANSLATE_NOOP("bitcoin-core", "To use the %s option"),
QT_TRANSLATE_NOOP("bitcoin-core", "Transaction amount too small"),
QT_TRANSLATE_NOOP("bitcoin-core", "Transaction amounts must be positive"),
QT_TRANSLATE_NOOP("bitcoin-core", "Transaction too large"),
QT_TRANSLATE_NOOP("bitcoin-core", "Unable to bind to %s on this computer (bind returned error %d, %s)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Unknown -socks proxy version requested: %i"),
QT_TRANSLATE_NOOP("bitcoin-core", "Unknown network specified in -onlynet: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Upgrade wallet to latest format"),
<<<<<<< HEAD
=======
QT_TRANSLATE_NOOP("bitcoin-core", "Usage (deprecated, use dogecoin-cli):"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Usage:"),
QT_TRANSLATE_NOOP("bitcoin-core", "Use OpenSSL (https) for JSON-RPC connections"),
QT_TRANSLATE_NOOP("bitcoin-core", "Use UPnP to map the listening port (default: 0)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Use UPnP to map the listening port (default: 1 when listening)"),
<<<<<<< HEAD
QT_TRANSLATE_NOOP("bitcoin-core", "Use proxy to reach tor hidden services (default: same as -proxy)"),
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "Use the test network"),
QT_TRANSLATE_NOOP("bitcoin-core", "Username for JSON-RPC connections"),
QT_TRANSLATE_NOOP("bitcoin-core", "Verifying blocks..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Verifying wallet..."),
<<<<<<< HEAD
QT_TRANSLATE_NOOP("bitcoin-core", "Wallet needed to be rewritten: restart Dogecoin to complete"),
QT_TRANSLATE_NOOP("bitcoin-core", "Warning"),
QT_TRANSLATE_NOOP("bitcoin-core", "Warning: This version is obsolete, upgrade required!"),
QT_TRANSLATE_NOOP("bitcoin-core", "You need to rebuild the database using -reindex to change -txindex"),
=======
QT_TRANSLATE_NOOP("bitcoin-core", "Wait for RPC server to start"),
QT_TRANSLATE_NOOP("bitcoin-core", "Wallet %s resides outside data directory %s"),
QT_TRANSLATE_NOOP("bitcoin-core", "Wallet needed to be rewritten: restart Dogecoin Core to complete"),
QT_TRANSLATE_NOOP("bitcoin-core", "Wallet options:"),
QT_TRANSLATE_NOOP("bitcoin-core", "Warning"),
QT_TRANSLATE_NOOP("bitcoin-core", "Warning: Deprecated argument -debugnet ignored, use -debug=net"),
QT_TRANSLATE_NOOP("bitcoin-core", "Warning: This version is obsolete, upgrade required!"),
QT_TRANSLATE_NOOP("bitcoin-core", "You need to rebuild the database using -reindex to change -txindex"),
QT_TRANSLATE_NOOP("bitcoin-core", "Zapping all transactions from wallet..."),
QT_TRANSLATE_NOOP("bitcoin-core", "version"),
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
QT_TRANSLATE_NOOP("bitcoin-core", "wallet.dat corrupt, salvage failed"),
};
