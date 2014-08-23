// Copyright (c) 2009-2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2013-2014 Dogecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_UTIL_H
#define BITCOIN_UTIL_H

#include "uint256.h"

#include <stdarg.h>

#ifndef WIN32
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#endif
#include <map>
#include <list>
#include <utility>
#include <vector>
#include <string>

#include <boost/version.hpp>
#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#include "netbase.h" // for AddTimeData

typedef long long  int64;
typedef unsigned long long  uint64;

static const int64 COIN = 100000000;
static const int64 CENT = 1000000;

#define loop                for (;;)
=======
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2011-2013 The Litecoin developers
// Copyright (c)      2014 The Inutoshi developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_UTIL_H
#define BITCOIN_UTIL_H

#if defined(HAVE_CONFIG_H)
#include "bitcoin-config.h"
#endif

#include "compat.h"
#include "serialize.h"
#include "tinyformat.h"

#include <cstdio>
#include <exception>
#include <map>
#include <stdarg.h>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

#ifndef WIN32
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#endif

#include <boost/filesystem/path.hpp>
#include <boost/thread.hpp>

class CNetAddr;
class uint256;

static const int64_t COIN = 100000000;
static const int64_t CENT = 1000000;

>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#define BEGIN(a)            ((char*)&(a))
#define END(a)              ((char*)&((&(a))[1]))
#define UBEGIN(a)           ((unsigned char*)&(a))
#define UEND(a)             ((unsigned char*)&((&(a))[1]))
#define ARRAYLEN(array)     (sizeof(array)/sizeof((array)[0]))

<<<<<<< HEAD
#ifndef PRI64d
#if defined(_MSC_VER) || defined(__MSVCRT__)
#define PRI64d  "I64d"
#define PRI64u  "I64u"
#define PRI64x  "I64x"
#else
#define PRI64d  "lld"
#define PRI64u  "llu"
#define PRI64x  "llx"
#endif
#endif

/* Format characters for (s)size_t and ptrdiff_t */
#if defined(_MSC_VER) || defined(__MSVCRT__)
  /* (s)size_t and ptrdiff_t have the same size specifier in MSVC:
     http://msdn.microsoft.com/en-us/library/tcxf1dw6%28v=vs.100%29.aspx
   */
  #define PRIszx    "Ix"
  #define PRIszu    "Iu"
  #define PRIszd    "Id"
  #define PRIpdx    "Ix"
  #define PRIpdu    "Iu"
  #define PRIpdd    "Id"
#else /* C99 standard */
  #define PRIszx    "zx"
  #define PRIszu    "zu"
  #define PRIszd    "zd"
  #define PRIpdx    "tx"
  #define PRIpdu    "tu"
  #define PRIpdd    "td"
#endif
=======
/* Format characters for (s)size_t, ptrdiff_t.
 *
 * Define these as empty as the tinyformat-based formatting system is
 * type-safe, no special format characters are needed to specify sizes.
 */
#define PRIszx    "x"
#define PRIszu    "u"
#define PRIszd    "d"
#define PRIpdx    "x"
#define PRIpdu    "u"
#define PRIpdd    "d"
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

// This is needed because the foreach macro can't get over the comma in pair<t1, t2>
#define PAIRTYPE(t1, t2)    std::pair<t1, t2>

// Align by increasing pointer, must have extra space at end of buffer
template <size_t nBytes, typename T>
T* alignup(T* p)
{
    union
    {
        T* ptr;
        size_t n;
    } u;
    u.ptr = p;
    u.n = (u.n + (nBytes-1)) & ~(nBytes-1);
    return u.ptr;
}

#ifdef WIN32
<<<<<<< HEAD
#define MSG_NOSIGNAL        0
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#define MSG_DONTWAIT        0

#ifndef S_IRUSR
#define S_IRUSR             0400
#define S_IWUSR             0200
#endif
#else
#define MAX_PATH            1024
#endif
<<<<<<< HEAD

inline void MilliSleep(int64 n)
=======
// As Solaris does not have the MSG_NOSIGNAL flag for send(2) syscall, it is defined as 0
#if !defined(HAVE_MSG_NOSIGNAL) && !defined(MSG_NOSIGNAL)
#define MSG_NOSIGNAL 0
#endif

inline void MilliSleep(int64_t n)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
// Boost's sleep_for was uninterruptable when backed by nanosleep from 1.50
// until fixed in 1.52. Use the deprecated sleep method for the broken case.
// See: https://svn.boost.org/trac/boost/ticket/7238
<<<<<<< HEAD

#if BOOST_VERSION >= 105000 && (!defined(BOOST_HAS_NANOSLEEP) || BOOST_VERSION >= 105200)
    boost::this_thread::sleep_for(boost::chrono::milliseconds(n));
#else
    boost::this_thread::sleep(boost::posix_time::milliseconds(n));
#endif
}

/* This GNU C extension enables the compiler to check the format string against the parameters provided.
 * X is the number of the "format string" parameter, and Y is the number of the first variadic parameter.
 * Parameters count from 1.
 */
#ifdef __GNUC__
#define ATTR_WARN_PRINTF(X,Y) __attribute__((format(printf,X,Y)))
#else
#define ATTR_WARN_PRINTF(X,Y)
#endif





=======
#if defined(HAVE_WORKING_BOOST_SLEEP_FOR)
    boost::this_thread::sleep_for(boost::chrono::milliseconds(n));
#elif defined(HAVE_WORKING_BOOST_SLEEP)
    boost::this_thread::sleep(boost::posix_time::milliseconds(n));
#else
//should never get here
#error missing boost sleep implementation
#endif
}
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917



extern std::map<std::string, std::string> mapArgs;
extern std::map<std::string, std::vector<std::string> > mapMultiArgs;
extern bool fDebug;
<<<<<<< HEAD
extern bool fDebugNet;
extern bool fWriteDebugLog;
extern bool fPrintToConsole;
extern bool fPrintToDebugger;
extern bool fDaemon;
extern bool fServer;
extern bool fCommandLine;
extern std::string strMiscWarning;
extern bool fTestNet;
=======
extern bool fPrintToConsole;
extern bool fPrintToDebugLog;
extern bool fServer;
extern std::string strMiscWarning;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
extern bool fBloomFilters;
extern bool fNoListen;
extern bool fLogTimestamps;
extern volatile bool fReopenDebugLog;

void RandAddSeed();
void RandAddSeedPerfmon();
<<<<<<< HEAD
int ATTR_WARN_PRINTF(1,2) OutputDebugStringF(const char* pszFormat, ...);

/*
  Rationale for the real_strprintf / strprintf construction:
    It is not allowed to use va_start with a pass-by-reference argument.
    (C++ standard, 18.7, paragraph 3). Use a dummy argument to work around this, and use a
    macro to keep similar semantics.
*/

/** Overload strprintf for char*, so that GCC format type warnings can be given */
std::string ATTR_WARN_PRINTF(1,3) real_strprintf(const char *format, int dummy, ...);
/** Overload strprintf for std::string, to be able to use it with _ (translation).
 * This will not support GCC format type warnings (-Wformat) so be careful.
 */
std::string real_strprintf(const std::string &format, int dummy, ...);
#define strprintf(format, ...) real_strprintf(format, 0, __VA_ARGS__)
std::string vstrprintf(const char *format, va_list ap);

bool ATTR_WARN_PRINTF(1,2) error(const char *format, ...);

/* Redefine printf so that it directs output to debug.log
 *
 * Do this *after* defining the other printf-like functions, because otherwise the
 * __attribute__((format(printf,X,Y))) gets expanded to __attribute__((format(OutputDebugStringF,X,Y)))
 * which confuses gcc.
 */
#define printf OutputDebugStringF

void LogException(std::exception* pex, const char* pszThread);
void PrintException(std::exception* pex, const char* pszThread);
void PrintExceptionContinue(std::exception* pex, const char* pszThread);
void ParseString(const std::string& str, char c, std::vector<std::string>& v);
std::string FormatMoney(int64 n, bool fPlus=false);
bool ParseMoney(const std::string& str, int64& nRet);
bool ParseMoney(const char* pszIn, int64& nRet);
=======

/* Return true if log accepts specified category */
bool LogAcceptCategory(const char* category);
/* Send a string to the log output */
int LogPrintStr(const std::string &str);

#define strprintf tfm::format
#define LogPrintf(...) LogPrint(NULL, __VA_ARGS__)

/* When we switch to C++11, this can be switched to variadic templates instead
 * of this macro-based construction (see tinyformat.h).
 */
#define MAKE_ERROR_AND_LOG_FUNC(n)                                        \
    /*   Print to debug.log if -debug=category switch is given OR category is NULL. */ \
    template<TINYFORMAT_ARGTYPES(n)>                                          \
    static inline int LogPrint(const char* category, const char* format, TINYFORMAT_VARARGS(n))  \
    {                                                                         \
        if(!LogAcceptCategory(category)) return 0;                            \
        return LogPrintStr(tfm::format(format, TINYFORMAT_PASSARGS(n))); \
    }                                                                         \
    /*   Log error and return false */                                        \
    template<TINYFORMAT_ARGTYPES(n)>                                          \
    static inline bool error(const char* format, TINYFORMAT_VARARGS(n))                     \
    {                                                                         \
        LogPrintStr("ERROR: " + tfm::format(format, TINYFORMAT_PASSARGS(n)) + "\n"); \
        return false;                                                         \
    }

TINYFORMAT_FOREACH_ARGNUM(MAKE_ERROR_AND_LOG_FUNC)

/* Zero-arg versions of logging and error, these are not covered by
 * TINYFORMAT_FOREACH_ARGNUM
 */
static inline int LogPrint(const char* category, const char* format)
{
    if(!LogAcceptCategory(category)) return 0;
    return LogPrintStr(format);
}
static inline bool error(const char* format)
{
    LogPrintStr(std::string("ERROR: ") + format + "\n");
    return false;
}


void LogException(std::exception* pex, const char* pszThread);
void PrintExceptionContinue(std::exception* pex, const char* pszThread);
void ParseString(const std::string& str, char c, std::vector<std::string>& v);
std::string FormatMoney(int64_t n, bool fPlus=false);
bool ParseMoney(const std::string& str, int64_t& nRet);
bool ParseMoney(const char* pszIn, int64_t& nRet);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
std::string SanitizeString(const std::string& str);
std::vector<unsigned char> ParseHex(const char* psz);
std::vector<unsigned char> ParseHex(const std::string& str);
bool IsHex(const std::string& str);
std::vector<unsigned char> DecodeBase64(const char* p, bool* pfInvalid = NULL);
std::string DecodeBase64(const std::string& str);
std::string EncodeBase64(const unsigned char* pch, size_t len);
std::string EncodeBase64(const std::string& str);
std::vector<unsigned char> DecodeBase32(const char* p, bool* pfInvalid = NULL);
std::string DecodeBase32(const std::string& str);
std::string EncodeBase32(const unsigned char* pch, size_t len);
std::string EncodeBase32(const std::string& str);
void ParseParameters(int argc, const char*const argv[]);
bool WildcardMatch(const char* psz, const char* mask);
bool WildcardMatch(const std::string& str, const std::string& mask);
void FileCommit(FILE *fileout);
int GetFilesize(FILE* file);
bool TruncateFile(FILE *file, unsigned int length);
int RaiseFileDescriptorLimit(int nMinFD);
void AllocateFileRange(FILE *file, unsigned int offset, unsigned int length);
bool RenameOver(boost::filesystem::path src, boost::filesystem::path dest);
boost::filesystem::path GetDefaultDataDir();
const boost::filesystem::path &GetDataDir(bool fNetSpecific = true);
boost::filesystem::path GetConfigFile();
boost::filesystem::path GetPidFile();
#ifndef WIN32
void CreatePidFile(const boost::filesystem::path &path, pid_t pid);
#endif
void ReadConfigFile(std::map<std::string, std::string>& mapSettingsRet, std::map<std::string, std::vector<std::string> >& mapMultiSettingsRet);
#ifdef WIN32
boost::filesystem::path GetSpecialFolderPath(int nFolder, bool fCreate = true);
#endif
boost::filesystem::path GetTempPath();
void ShrinkDebugFile();
int GetRandInt(int nMax);
<<<<<<< HEAD
uint64 GetRand(uint64 nMax);
uint256 GetRandHash();
int64 GetTime();
void SetMockTime(int64 nMockTimeIn);
int64 GetAdjustedTime();
int64 GetTimeOffset();
long hex2long(const char* hexString);
std::string FormatFullVersion();
std::string FormatSubVersion(const std::string& name, int nClientVersion, const std::vector<std::string>& comments);
void AddTimeData(const CNetAddr& ip, int64 nTime);
=======
uint64_t GetRand(uint64_t nMax);
uint256 GetRandHash();
int64_t GetTime();
void SetMockTime(int64_t nMockTimeIn);
int64_t GetAdjustedTime();
int64_t GetTimeOffset();
long hex2long(const char* hexString);
std::string FormatFullVersion();
std::string FormatSubVersion(const std::string& name, int nClientVersion, const std::vector<std::string>& comments);
void AddTimeData(const CNetAddr& ip, int64_t nTime);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
void runCommand(std::string strCommand);









<<<<<<< HEAD
inline std::string i64tostr(int64 n)
{
    return strprintf("%"PRI64d, n);
=======
inline std::string i64tostr(int64_t n)
{
    return strprintf("%d", n);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

inline std::string itostr(int n)
{
    return strprintf("%d", n);
}

<<<<<<< HEAD
inline int64 atoi64(const char* psz)
=======
inline int64_t atoi64(const char* psz)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
#ifdef _MSC_VER
    return _atoi64(psz);
#else
    return strtoll(psz, NULL, 10);
#endif
}

<<<<<<< HEAD
inline int64 atoi64(const std::string& str)
=======
inline int64_t atoi64(const std::string& str)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
#ifdef _MSC_VER
    return _atoi64(str.c_str());
#else
    return strtoll(str.c_str(), NULL, 10);
#endif
}

inline int atoi(const std::string& str)
{
    return atoi(str.c_str());
}

inline int roundint(double d)
{
    return (int)(d > 0 ? d + 0.5 : d - 0.5);
}

<<<<<<< HEAD
inline int64 roundint64(double d)
{
    return (int64)(d > 0 ? d + 0.5 : d - 0.5);
}

inline int64 abs64(int64 n)
=======
inline int64_t roundint64(double d)
{
    return (int64_t)(d > 0 ? d + 0.5 : d - 0.5);
}

inline int64_t abs64(int64_t n)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    return (n >= 0 ? n : -n);
}

template<typename T>
std::string HexStr(const T itbegin, const T itend, bool fSpaces=false)
{
    std::string rv;
    static const char hexmap[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                                     '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    rv.reserve((itend-itbegin)*3);
    for(T it = itbegin; it < itend; ++it)
    {
        unsigned char val = (unsigned char)(*it);
        if(fSpaces && it != itbegin)
            rv.push_back(' ');
        rv.push_back(hexmap[val>>4]);
        rv.push_back(hexmap[val&15]);
    }

    return rv;
}

template<typename T>
inline std::string HexStr(const T& vch, bool fSpaces=false)
{
    return HexStr(vch.begin(), vch.end(), fSpaces);
}

template<typename T>
void PrintHex(const T pbegin, const T pend, const char* pszFormat="%s", bool fSpaces=true)
{
<<<<<<< HEAD
    printf(pszFormat, HexStr(pbegin, pend, fSpaces).c_str());
=======
    LogPrintf(pszFormat, HexStr(pbegin, pend, fSpaces).c_str());
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
}

inline void PrintHex(const std::vector<unsigned char>& vch, const char* pszFormat="%s", bool fSpaces=true)
{
<<<<<<< HEAD
    printf(pszFormat, HexStr(vch, fSpaces).c_str());
}

inline int64 GetPerformanceCounter()
{
    int64 nCounter = 0;
=======
    LogPrintf(pszFormat, HexStr(vch, fSpaces).c_str());
}

inline int64_t GetPerformanceCounter()
{
    int64_t nCounter = 0;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifdef WIN32
    QueryPerformanceCounter((LARGE_INTEGER*)&nCounter);
#else
    timeval t;
    gettimeofday(&t, NULL);
<<<<<<< HEAD
    nCounter = (int64) t.tv_sec * 1000000 + t.tv_usec;
=======
    nCounter = (int64_t) t.tv_sec * 1000000 + t.tv_usec;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#endif
    return nCounter;
}

<<<<<<< HEAD
inline int64 GetTimeMillis()
=======
inline int64_t GetTimeMillis()
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    return (boost::posix_time::ptime(boost::posix_time::microsec_clock::universal_time()) -
            boost::posix_time::ptime(boost::gregorian::date(1970,1,1))).total_milliseconds();
}

<<<<<<< HEAD
inline int64 GetTimeMicros()
=======
inline int64_t GetTimeMicros()
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    return (boost::posix_time::ptime(boost::posix_time::microsec_clock::universal_time()) -
            boost::posix_time::ptime(boost::gregorian::date(1970,1,1))).total_microseconds();
}

<<<<<<< HEAD
inline std::string DateTimeStrFormat(const char* pszFormat, int64 nTime)
=======
inline std::string DateTimeStrFormat(const char* pszFormat, int64_t nTime)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
{
    time_t n = nTime;
    struct tm* ptmTime = gmtime(&n);
    char pszTime[200];
    strftime(pszTime, sizeof(pszTime), pszFormat, ptmTime);
    return pszTime;
}

template<typename T>
void skipspaces(T& it)
{
    while (isspace(*it))
        ++it;
}

inline bool IsSwitchChar(char c)
{
#ifdef WIN32
    return c == '-' || c == '/';
#else
    return c == '-';
#endif
}

/**
 * Return string argument or default value
 *
 * @param strArg Argument to get (e.g. "-foo")
 * @param default (e.g. "1")
 * @return command-line argument or default value
 */
std::string GetArg(const std::string& strArg, const std::string& strDefault);

/**
 * Return integer argument or default value
 *
 * @param strArg Argument to get (e.g. "-foo")
 * @param default (e.g. 1)
 * @return command-line argument (0 if invalid number) or default value
 */
<<<<<<< HEAD
int64 GetArg(const std::string& strArg, int64 nDefault);
=======
int64_t GetArg(const std::string& strArg, int64_t nDefault);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

/**
 * Return boolean argument or default value
 *
 * @param strArg Argument to get (e.g. "-foo")
 * @param default (true or false)
 * @return command-line argument or default value
 */
<<<<<<< HEAD
bool GetBoolArg(const std::string& strArg, bool fDefault=false);
=======
bool GetBoolArg(const std::string& strArg, bool fDefault);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

/**
 * Set an argument if it doesn't already have a value
 *
 * @param strArg Argument to set (e.g. "-foo")
 * @param strValue Value (e.g. "1")
 * @return true if argument gets set, false if it already had a value
 */
bool SoftSetArg(const std::string& strArg, const std::string& strValue);

/**
 * Set a boolean argument if it doesn't already have a value
 *
 * @param strArg Argument to set (e.g. "-foo")
 * @param fValue Value (e.g. false)
 * @return true if argument gets set, false if it already had a value
 */
bool SoftSetBoolArg(const std::string& strArg, bool fValue);

/**
 * MWC RNG of George Marsaglia
 * This is intended to be fast. It has a period of 2^59.3, though the
 * least significant 16 bits only have a period of about 2^30.1.
 *
 * @return random value
 */
extern uint32_t insecure_rand_Rz;
extern uint32_t insecure_rand_Rw;
static inline uint32_t insecure_rand(void)
{
    insecure_rand_Rz = 36969 * (insecure_rand_Rz & 65535) + (insecure_rand_Rz >> 16);
    insecure_rand_Rw = 18000 * (insecure_rand_Rw & 65535) + (insecure_rand_Rw >> 16);
    return (insecure_rand_Rw << 16) + insecure_rand_Rz;
}

/**
 * Seed insecure_rand using the random pool.
 * @param Deterministic Use a determinstic seed
 */
void seed_insecure_rand(bool fDeterministic=false);

/**
 * Timing-attack-resistant comparison.
 * Takes time proportional to length
 * of first argument.
 */
template <typename T>
bool TimingResistantEqual(const T& a, const T& b)
{
    if (b.size() == 0) return a.size() == 0;
    size_t accumulator = a.size() ^ b.size();
    for (size_t i = 0; i < a.size(); i++)
        accumulator |= a[i] ^ b[i%b.size()];
    return accumulator == 0;
}

/** Median filter over a stream of values.
 * Returns the median of the last N numbers
 */
template <typename T> class CMedianFilter
{
private:
    std::vector<T> vValues;
    std::vector<T> vSorted;
    unsigned int nSize;
public:
    CMedianFilter(unsigned int size, T initial_value):
        nSize(size)
    {
        vValues.reserve(size);
        vValues.push_back(initial_value);
        vSorted = vValues;
    }

    void input(T value)
    {
        if(vValues.size() == nSize)
        {
            vValues.erase(vValues.begin());
        }
        vValues.push_back(value);

        vSorted.resize(vValues.size());
        std::copy(vValues.begin(), vValues.end(), vSorted.begin());
        std::sort(vSorted.begin(), vSorted.end());
    }

    T median() const
    {
        int size = vSorted.size();
        assert(size>0);
        if(size & 1) // Odd number of elements
        {
            return vSorted[size/2];
        }
        else // Even number of elements
        {
            return (vSorted[size/2-1] + vSorted[size/2]) / 2;
        }
    }

    int size() const
    {
        return vValues.size();
    }

    std::vector<T> sorted () const
    {
        return vSorted;
    }
};

<<<<<<< HEAD
bool NewThread(void(*pfn)(void*), void* parg);

=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#ifdef WIN32
inline void SetThreadPriority(int nPriority)
{
    SetThreadPriority(GetCurrentThread(), nPriority);
}
#else

<<<<<<< HEAD
#define THREAD_PRIORITY_LOWEST          PRIO_MAX
#define THREAD_PRIORITY_BELOW_NORMAL    2
#define THREAD_PRIORITY_NORMAL          0
#define THREAD_PRIORITY_ABOVE_NORMAL    0
=======
// PRIO_MAX is not defined on Solaris
#ifndef PRIO_MAX
#define PRIO_MAX 20
#endif
#define THREAD_PRIORITY_LOWEST          PRIO_MAX
#define THREAD_PRIORITY_BELOW_NORMAL    2
#define THREAD_PRIORITY_NORMAL          0
#define THREAD_PRIORITY_ABOVE_NORMAL    (-2)
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917

inline void SetThreadPriority(int nPriority)
{
    // It's unclear if it's even possible to change thread priorities on Linux,
    // but we really and truly need it for the generation threads.
#ifdef PRIO_THREAD
    setpriority(PRIO_THREAD, 0, nPriority);
#else
    setpriority(PRIO_PROCESS, 0, nPriority);
#endif
}
<<<<<<< HEAD

inline void ExitThread(size_t nExitCode)
{
    pthread_exit((void*)nExitCode);
}
=======
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
#endif

void RenameThread(const char* name);

inline uint32_t ByteReverse(uint32_t value)
{
    value = ((value & 0xFF00FF00) >> 8) | ((value & 0x00FF00FF) << 8);
    return (value<<16) | (value>>16);
}

// Standard wrapper for do-something-forever thread functions.
// "Forever" really means until the thread is interrupted.
// Use it like:
//   new boost::thread(boost::bind(&LoopForever<void (*)()>, "dumpaddr", &DumpAddresses, 900000));
// or maybe:
//    boost::function<void()> f = boost::bind(&FunctionWithArg, argument);
//    threadGroup.create_thread(boost::bind(&LoopForever<boost::function<void()> >, "nothing", f, milliseconds));
<<<<<<< HEAD
template <typename Callable> void LoopForever(const char* name,  Callable func, int64 msecs)
{
    std::string s = strprintf("bitcoin-%s", name);
    RenameThread(s.c_str());
    printf("%s thread start\n", name);
=======
template <typename Callable> void LoopForever(const char* name,  Callable func, int64_t msecs)
{
    std::string s = strprintf("dogecoin-%s", name);
    RenameThread(s.c_str());
    LogPrintf("%s thread start\n", name);
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    try
    {
        while (1)
        {
            MilliSleep(msecs);
            func();
        }
    }
    catch (boost::thread_interrupted)
    {
<<<<<<< HEAD
        printf("%s thread stop\n", name);
        throw;
    }
    catch (std::exception& e) {
        PrintException(&e, name);
    }
    catch (...) {
        PrintException(NULL, name);
=======
        LogPrintf("%s thread stop\n", name);
        throw;
    }
    catch (std::exception& e) {
        PrintExceptionContinue(&e, name);
        throw;
    }
    catch (...) {
        PrintExceptionContinue(NULL, name);
        throw;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
}
// .. and a wrapper that just calls func once
template <typename Callable> void TraceThread(const char* name,  Callable func)
{
<<<<<<< HEAD
    std::string s = strprintf("bitcoin-%s", name);
    RenameThread(s.c_str());
    try
    {
        printf("%s thread start\n", name);
        func();
        printf("%s thread exit\n", name);
    }
    catch (boost::thread_interrupted)
    {
        printf("%s thread interrupt\n", name);
        throw;
    }
    catch (std::exception& e) {
        PrintException(&e, name);
    }
    catch (...) {
        PrintException(NULL, name);
=======
    std::string s = strprintf("dogecoin-%s", name);
    RenameThread(s.c_str());
    try
    {
        LogPrintf("%s thread start\n", name);
        func();
        LogPrintf("%s thread exit\n", name);
    }
    catch (boost::thread_interrupted)
    {
        LogPrintf("%s thread interrupt\n", name);
        throw;
    }
    catch (std::exception& e) {
        PrintExceptionContinue(&e, name);
        throw;
    }
    catch (...) {
        PrintExceptionContinue(NULL, name);
        throw;
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    }
}

#endif
