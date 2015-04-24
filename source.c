#define _GNU_SOURCE             /* See feature_test_macros(7) */


// ------ MAKE PYCPARSER HAPPY ------
#define __attribute__(...)
#define __inline inline
#define __restrict
#define __extension__
// #define __sighandler_t int

typedef struct __builtin_va_list __builtin_va_list;

#define __asm__(...)
#define __volatile__(...)
#define __signed__ signed
#define __int128_t unsigned long long // Hacky
// ------ MAKE PYCPARSER HAPPY ------


#include <aio.h>
#include <aliases.h>
#include <alloca.h>
#include <argp.h>
#include <argz.h>
#include <assert.h>
#include <byteswap.h>
#include <complex.h>
#include <cpio.h>
#include <crypt.h>
#include <ctype.h>
#include <dirent.h>
#include <dlfcn.h>
#include <elf.h>
#include <endian.h>
#include <envz.h>
#include <err.h>
#include <errno.h>
#include <error.h>
#include <execinfo.h>
#include <fcntl.h>
#include <features.h>
#include <fenv.h>
#include <fmtmsg.h>
#include <fnmatch.h>
#include <fstab.h>
#include <fts.h>
#include <ftw.h>
#include <getopt.h>
#include <glob.h>
#include <grp.h>
#include <gshadow.h>
#include <iconv.h>
#include <ifaddrs.h>
#include <langinfo.h>
#include <lastlog.h>
#include <libgen.h>
#include <libintl.h>
#include <libio.h>
#include <link.h>
#include <locale.h>
// #include <linux/getcpu.h>
#include <malloc.h>
#include <math.h>
#include <mcheck.h>
#include <memory.h>
#include <sched.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <sys/capability.h>
#include <sys/epoll.h>
#include <sys/file.h>
#include <sys/io.h>
#include <sys/ioctl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <sys/sem.h>
#include <sys/sendfile.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/utsname.h>
// #include <sys/vm86.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
