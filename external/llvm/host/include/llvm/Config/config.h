/* include/llvm/Config/config.h.  Generated from config.h.in by configure.  */
/* include/llvm/Config/config.h.in.  Generated from autoconf/configure.ac by autoheader.  */

#ifndef CONFIG_H
#define CONFIG_H

/* Bug report URL. */
#define BUG_REPORT_URL "http://llvm.org/bugs/"

/* Relative directory for resource files */
#define CLANG_RESOURCE_DIR ""

/* Directories clang will search for headers */
#define C_INCLUDE_DIRS ""

/* Default <path> to all compiler invocations for --sysroot=<path>. */
#define DEFAULT_SYSROOT ""

/* Define if you want backtraces on crash */
/* #undef ENABLE_BACKTRACES */

/* Define if position independent code is enabled */
#define ENABLE_PIC 1

/* Define if timestamp information (e.g., __DATE___) is allowed */
#define ENABLE_TIMESTAMPS 1

/* Directory where gcc is installed. */
#define GCC_INSTALL_PREFIX ""

/* Define to 1 if you have the `argz_append' function. */
/* #undef HAVE_ARGZ_APPEND */

/* Define to 1 if you have the `argz_create_sep' function. */
/* #undef HAVE_ARGZ_CREATE_SEP */

/* Define to 1 if you have the <argz.h> header file. */
/* #undef HAVE_ARGZ_H */

/* Define to 1 if you have the `argz_insert' function. */
/* #undef HAVE_ARGZ_INSERT */

/* Define to 1 if you have the `argz_next' function. */
/* #undef HAVE_ARGZ_NEXT */

/* Define to 1 if you have the `argz_stringify' function. */
/* #undef HAVE_ARGZ_STRINGIFY */

/* Define to 1 if you have the `backtrace' function. */
/* #define HAVE_BACKTRACE 1 */ /* Defined by AndroidConfig.h */

/* Define to 1 if you have the `ceilf' function. */
#define HAVE_CEILF 1

/* Define if the neat program is available */
/* #undef HAVE_CIRCO */

/* Define to 1 if you have the `closedir' function. */
#define HAVE_CLOSEDIR 1

/* Define to 1 if you have the <CrashReporterClient.h> header file. */
/* #undef HAVE_CRASHREPORTERCLIENT_H */

/* can use __crashreporter_info__ */
#define HAVE_CRASHREPORTER_INFO 0

/* Define to 1 if you have the <cxxabi.h> header file. */
/* #undef HAVE_CXXABI_H */

/* Define to 1 if you have the declaration of `FE_ALL_EXCEPT', and to 0 if you
   don't. */
/* #undef HAVE_DECL_FE_ALL_EXCEPT */

/* Define to 1 if you have the declaration of `FE_INEXACT', and to 0 if you
   don't. */
/* #undef HAVE_DECL_FE_INEXACT */

/* Define to 1 if you have the <cxxabi.h> header file. */
#define HAVE_CXXABI_H 0

/* Define to 1 if you have the declaration of `strerror_s', and to 0 if you
   don't. */
#define HAVE_DECL_STRERROR_S 0

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the <dld.h> header file. */
/* #undef HAVE_DLD_H */

/* Define to 1 if you have the `dlerror' function. */
#define HAVE_DLERROR 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define if dlopen() is available on this platform. */
#define HAVE_DLOPEN 1

/* Define if the dot program is available */
/* #undef HAVE_DOT */

/* Define if the dotty program is available */
/* #undef HAVE_DOTTY */

/* Define if you have the _dyld_func_lookup function. */
/* #undef HAVE_DYLD */

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if the system has the type `error_t'. */
#define HAVE_ERROR_T 1

/* Define to 1 if you have the <execinfo.h> header file. */
#define HAVE_EXECINFO_H 1

/* Define to 1 if you have the `exp' function. */
/* #undef HAVE_EXP */

/* Define to 1 if you have the `exp2' function. */
/* #undef HAVE_EXP2 */

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define if the neat program is available */
/* #undef HAVE_FDP */

/* Define to 1 if you have the <fenv.h> header file. */
#define HAVE_FENV_H 1

/* Define if libffi is available on this platform. */
/* #undef HAVE_FFI_CALL */

/* Define to 1 if you have the <ffi/ffi.h> header file. */
/* #undef HAVE_FFI_FFI_H */

/* Define to 1 if you have the <ffi.h> header file. */
/* #undef HAVE_FFI_H */

/* Set to 1 if the finite function is found in <ieeefp.h> */
/* #undef HAVE_FINITE_IN_IEEEFP_H */

/* Define to 1 if you have the `floorf' function. */
#define HAVE_FLOORF 1

/* Define to 1 if you have the `fmodf' function. */
#define HAVE_FMODF 1

#ifdef __APPLE__
/* Define to 1 if you have the `futimes' function. */
#define HAVE_FUTIMES 1
#else
/* Define to 1 if you have the `futimens' function. */
#define HAVE_FUTIMENS 1
#endif  // __APPLE__

/* Define to 1 if you have the `getcwd' function. */
#define HAVE_GETCWD 1

/* Define to 1 if you have the `getpagesize' function. */
#define HAVE_GETPAGESIZE 1

/* Define to 1 if you have the `getrlimit' function. */
#define HAVE_GETRLIMIT 1

/* Define to 1 if you have the `getrusage' function. */
#define HAVE_GETRUSAGE 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define if the Graphviz program is available */
/* #undef HAVE_GRAPHVIZ */

/* Define if the gv program is available */
/* #undef HAVE_GV */

/* Define to 1 if the system has the type `int64_t'. */
#define HAVE_INT64_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `isatty' function. */
#define HAVE_ISATTY 1

/* Set to 1 if the isinf function is found in <cmath> */
#define HAVE_ISINF_IN_CMATH 1

/* Set to 1 if the isinf function is found in <math.h> */
#define HAVE_ISINF_IN_MATH_H 1

/* Set to 1 if the isnan function is found in <cmath> */
#define HAVE_ISNAN_IN_CMATH 1

/* Set to 1 if the isnan function is found in <math.h> */
#define HAVE_ISNAN_IN_MATH_H 1

/* Define if you have the libdl library or equivalent. */
#define HAVE_LIBDL 1

/* Define to 1 if you have the `imagehlp' library (-limagehlp). */
/* #undef HAVE_LIBIMAGEHLP */

/* Define to 1 if you have the `m' library (-lm). */
#define HAVE_LIBM 1

/* Define to 1 if you have the `psapi' library (-lpsapi). */
/* #undef HAVE_LIBPSAPI */

/* Define to 1 if you have the `pthread' library (-lpthread). */
#define HAVE_LIBPTHREAD 1

/* Define to 1 if you have the `udis86' library (-ludis86). */
/* #undef HAVE_LIBUDIS86 */

/* Define to 1 if you have the `z' library (-lz). */
#define HAVE_LIBZ 1

/* Define if you can use -rdynamic. */
#define HAVE_LINK_EXPORT_DYNAMIC 1

/* Define to 1 if you have the <link.h> header file. */
#define HAVE_LINK_H 1

/* Define if you can use -Wl,-R. to pass -R. to the linker, in order to add
   the current directory to the dynamic linker search path. */
#define HAVE_LINK_R 1

/* Define to 1 if you have the `log' function. */
#define HAVE_LOG 1

/* Define to 1 if you have the `log10' function. */
#define HAVE_LOG10 1

/* Define to 1 if you have the `log2' function. */
#define HAVE_LOG2 1

/* Define to 1 if you have the `longjmp' function. */
#define HAVE_LONGJMP 1

/* Define to 1 if you have the <mach/mach.h> header file. */
/* #undef HAVE_MACH_MACH_H */

/* Define to 1 if you have the <mach-o/dyld.h> header file. */
/* #undef HAVE_MACH_O_DYLD_H */

/* Define if mallinfo() is available on this platform. */
#if !defined(__APPLE__)
#define HAVE_MALLINFO 1
#else
/* #undef HAVE_MALLINFO */
#endif

/* Define to 1 if you have the <malloc.h> header file. */
/* #define HAVE_MALLOC_H 1 */ /* Defined by AndroidConfig.h */

/* Define to 1 if you have the <malloc/malloc.h> header file. */
/* #undef HAVE_MALLOC_MALLOC_H */

/* Define to 1 if you have the `malloc_zone_statistics' function. */
/* #undef HAVE_MALLOC_ZONE_STATISTICS */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `mkdtemp' function. */
#define HAVE_MKDTEMP 1

/* Define to 1 if you have the `mkstemp' function. */
#define HAVE_MKSTEMP 1

/* Define to 1 if you have the `mktemp' function. */
#define HAVE_MKTEMP 1

/* Define to 1 if you have a working `mmap' system call. */
#define HAVE_MMAP 1

/* Define if mmap() uses MAP_ANONYMOUS to map anonymous pages, or undefine if
   it uses MAP_ANON */
#if !defined(__APPLE__)
#define HAVE_MMAP_ANONYMOUS
#else
/* #undef HAVE_MMAP_ANONYMOUS */
#endif

/* Define if mmap() can map files into memory */
#define HAVE_MMAP_FILE

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the `nearbyintf' function. */
#define HAVE_NEARBYINTF 1

/* Define if the neat program is available */
/* #undef HAVE_NEATO */

/* Define to 1 if you have the `opendir' function. */
#define HAVE_OPENDIR 1

/* Define to 1 if you have the `posix_spawn' function. */
#define HAVE_POSIX_SPAWN 1

/* Define to 1 if you have the `powf' function. */
#define HAVE_POWF 1

/* Define to 1 if you have the `pread' function. */
#if !defined(_WIN32) && !defined(_WIN64)
#define HAVE_PREAD 1
#endif

/* Define if libtool can extract symbol lists from object files. */
#define HAVE_PRELOADED_SYMBOLS 1

/* Define to have the %a format string */
#define HAVE_PRINTF_A 1

#if !defined(_WIN32) && !defined(_WIN64)

/* Have pthread_getspecific */
#define HAVE_PTHREAD_GETSPECIFIC 1

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Have pthread_mutex_lock */
#define HAVE_PTHREAD_MUTEX_LOCK 1

/* Have pthread_rwlock_init */
#define HAVE_PTHREAD_RWLOCK_INIT 1

#endif /* !defined(_WIN32) && !defined(_WIN64) */

/* Define to 1 if srand48/lrand48/drand48 exist in <stdlib.h> */
#define HAVE_RAND48 1

/* Define to 1 if you have the `readdir' function. */
#define HAVE_READDIR 1

/* Define to 1 if you have the `realpath' function. */
#define HAVE_REALPATH 1

/* Define to 1 if you have the `rintf' function. */
#define HAVE_RINTF 1

/* Define to 1 if you have the `round' function. */
#define HAVE_ROUND 1

/* Define to 1 if you have the `roundf' function. */
#define HAVE_ROUNDF 1

/* Define to 1 if you have the `sbrk' function. */
#define HAVE_SBRK 1

/* Define to 1 if you have the `setenv' function. */
#define HAVE_SETENV 1

/* Define to 1 if you have the `setjmp' function. */
#define HAVE_SETJMP 1

/* Define to 1 if you have the <setjmp.h> header file. */
#define HAVE_SETJMP_H 1

/* Define to 1 if you have the `setrlimit' function. */
#define HAVE_SETRLIMIT 1

/* Define if you have the shl_load function. */
/* #undef HAVE_SHL_LOAD */

/* Define to 1 if you have the `siglongjmp' function. */
#define HAVE_SIGLONGJMP 1

/* Define to 1 if you have the <signal.h> header file. */
#define HAVE_SIGNAL_H 1

/* Define to 1 if you have the `sigsetjmp' function. */
/* #undef HAVE_SIGSETJMP */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Set to 1 if the std::isinf function is found in <cmath> */
#define HAVE_STD_ISINF_IN_CMATH 1

/* Set to 1 if the std::isnan function is found in <cmath> */
#define HAVE_STD_ISNAN_IN_CMATH 1

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the `strerror_r' function. */
#ifndef USE_MINGW
#define HAVE_STRERROR_R 1
#endif

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strtof' function. */
#define HAVE_STRTOF 1

/* Define to 1 if you have the `strtoll' function. */
#define HAVE_STRTOLL 1

/* Define to 1 if you have the `strtoq' function. */
#define HAVE_STRTOQ 1

/* Define to 1 if you have the `sysconf' function. */
#define HAVE_SYSCONF 1

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#define HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/mman.h> header file. */
#define HAVE_SYS_MMAN_H 1

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Already defined in system/core/include/arch/darwin-x86/AndroidConfig.h */
#if !defined(HAVE_SYS_UIO_H)

/* Define to 1 if you have the <sys/uio.h> header file. */
#define HAVE_SYS_UIO_H 1

#endif

/* Define to 1 if you have <sys/wait.h> that is POSIX.1 compatible. */
#define HAVE_SYS_WAIT_H 1

/* Define if the setupterm() function is supported this platform. */
#undef HAVE_TERMINFO

/* Define to 1 if you have the <termios.h> header file. */
#define HAVE_TERMIOS_H 1

/* Define if the neat program is available */
/* #undef HAVE_TWOPI */

/* Define to 1 if the system has the type `uint64_t'. */
#define HAVE_UINT64_T 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <utime.h> header file. */
#define HAVE_UTIME_H 1

/* Define to 1 if the system has the type `u_int64_t'. */
/* #undef HAVE_U_INT64_T */

/* Define to 1 if you have the <valgrind/valgrind.h> header file. */
/* #undef HAVE_VALGRIND_VALGRIND_H */

#if defined(_WIN32) || defined(_WIN64)
/* Define to 1 if you have the `writev' function. */
/* #undef HAVE_WRITEV */

#else
/* Define to 1 if you have the `writev' function. */
#define HAVE_WRITEV 1
#endif

/* Define if the xdot program is available */
/* #undef HAVE_XDOT */

/* Define to 1 if you have the <zlib.h> header file. */
/* #undef HAVE_ZLIB_H */

/* Have host's _alloca */
/* #undef HAVE__ALLOCA */

/* Have host's __alloca */
/* #undef HAVE___ALLOCA */

/* Have host's __ashldi3 */
/* #undef HAVE___ASHLDI3 */

/* Have host's __ashrdi3 */
/* #undef HAVE___ASHRDI3 */

/* Have host's __chkstk */
/* #undef HAVE___CHKSTK */

/* Have host's __cmpdi2 */
/* #undef HAVE___CMPDI2 */

/* Have host's __divdi3 */
/* #undef HAVE___DIVDI3 */

/* Define to 1 if you have the `__dso_handle' function. */
#define HAVE___DSO_HANDLE 1

/* Have host's __fixdfdi */
/* #undef HAVE___FIXDFDI */

/* Have host's __fixsfdi */
/* #undef HAVE___FIXSFDI */

/* Have host's __floatdidf */
/* #undef HAVE___FLOATDIDF */

/* Have host's __lshrdi3 */
/* #undef HAVE___LSHRDI3 */

/* Have host's __main */
/* #undef HAVE___MAIN */

/* Have host's __moddi3 */
/* #undef HAVE___MODDI3 */

/* Have host's __udivdi3 */
/* #undef HAVE___UDIVDI3 */

/* Have host's __umoddi3 */
/* #undef HAVE___UMODDI3 */

/* Have host's ___chkstk */
/* #undef HAVE____CHKSTK */

/* Linker version detected at compile time. */
#define HOST_LINK_VERSION "2.20.1"

/* Installation directory for binary executables */
#define LLVM_BINDIR "/opt/llvm-android/bin"

/* Time at which LLVM was configured */
#define LLVM_CONFIGTIME "Tue May  8 14:22:45 CST 2012"

/* Installation directory for data files */
#define LLVM_DATADIR "/opt/llvm-android/share/llvm"

/* Target triple LLVM will generate code for by default */
#define LLVM_DEFAULT_TARGET_TRIPLE "i386-unknown-linux"

/* Installation directory for documentation */
#define LLVM_DOCSDIR "/opt/llvm-android/share/doc/llvm"

/* Define if threads enabled */
#define LLVM_ENABLE_THREADS 1

/* Define if zlib is enabled */
/* #undef LLVM_ENABLE_ZLIB */

/* Installation directory for config files */
#define LLVM_ETCDIR "/opt/llvm-android/etc/llvm"

#if !defined(_WIN32) && !defined(_WIN64)

/* Has gcc/MSVC atomic intrinsics */
#define LLVM_HAS_ATOMICS 1

#else

#define LLVM_HAS_ATOMICS 0

#endif /* !defined(_WIN32) && !defined(_WIN64) */

/* Host triple LLVM will be executed on */
#define LLVM_HOST_TRIPLE "i686-unknown-linux"

/* Installation directory for include files */
#define LLVM_INCLUDEDIR "/opt/llvm-android/include"

/* Installation directory for .info files */
#define LLVM_INFODIR "/opt/llvm-android/info"

/* Installation directory for man pages */
#define LLVM_MANDIR "/opt/llvm-android/man"

/* Define to path to circo program if found or 'echo circo' otherwise */
/* #undef LLVM_PATH_CIRCO */

/* Define to path to dot program if found or 'echo dot' otherwise */
/* #undef LLVM_PATH_DOT */

/* Define to path to dotty program if found or 'echo dotty' otherwise */
/* #undef LLVM_PATH_DOTTY */

/* Define to path to fdp program if found or 'echo fdp' otherwise */
/* #undef LLVM_PATH_FDP */

/* Define to path to Graphviz program if found or 'echo Graphviz' otherwise */
/* #undef LLVM_PATH_GRAPHVIZ */

/* Define to path to gv program if found or 'echo gv' otherwise */
/* #undef LLVM_PATH_GV */

/* Define to path to neato program if found or 'echo neato' otherwise */
/* #undef LLVM_PATH_NEATO */

/* Define to path to twopi program if found or 'echo twopi' otherwise */
/* #undef LLVM_PATH_TWOPI */

/* Define to path to xdot program if found or 'echo xdot' otherwise */
/* #undef LLVM_PATH_XDOT */

/* Installation prefix directory */
#define LLVM_PREFIX "/opt/llvm-android"

/* Define if we have the Intel JIT API runtime support library */
#define LLVM_USE_INTEL_JITEVENTS 0

/* Define if we have the oprofile JIT-support library */
#define LLVM_USE_OPROFILE 0

/* Major version of the LLVM API */
#define LLVM_VERSION_MAJOR 3

/* Minor version of the LLVM API */
#define LLVM_VERSION_MINOR 4

/* Define if the OS needs help to load dependent libraries for dlopen(). */
/* #undef LTDL_DLOPEN_DEPLIBS */

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LTDL_OBJDIR ".libs/"

/* Define to the extension used for shared libraries, say, ".so". */
#define LTDL_SHLIB_EXT ".so"

/* Define to the system default library search path. */
#define LTDL_SYSSEARCHPATH "/lib:/usr/lib:/usr/local/lib:/lib:/usr/lib:/lib64:/usr/lib64:/usr/local/lib64:/lib32:/usr/lib32:/usr/local/lib32:/usr/x86_64-pc-linux-gnu/lib:/usr/lib/gcc/x86_64-pc-linux-gnu/4.3.4:/usr/lib/gcc/x86_64-pc-linux-gnu/4.3.4/32:/usr/lib/gcc/x86_64-pc-linux-gnu/4.1.2:/usr/lib/gcc/x86_64-pc-linux-gnu/4.1.2/32"

/* Define if /dev/zero should be used when mapping RWX memory, or undefine if
   its not necessary */
/* #undef NEED_DEV_ZERO_FOR_MMAP */

/* Define if dlsym() requires a leading underscore in symbol names. */
/* #undef NEED_USCORE */

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "http://llvm.org/bugs/"

/* Define to the full name of this package. */
#define PACKAGE_NAME "LLVM"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "LLVM 3.4svn"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "llvm"

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.4svn"

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* Define to 1 if the `S_IS*' macros in <sys/stat.h> do not work properly. */
/* #undef STAT_MACROS_BROKEN */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* Define if use udis86 library */
#define USE_UDIS86 0

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to a type to use for `error_t' if it is not otherwise available. */
/* #undef error_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef pid_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

#include "llvm/Config/llvm-platform-config.h"

#endif
