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
#define __alignof__(...) 0

#define INIT // regex

// Various syscalls
typedef int key_serial_t;
typedef unsigned int key_perm_t;
typedef struct __user_cap_data_struct *cap_user_data_t;
typedef struct __user_cap_header_struct* cap_user_header_t;
typedef unsigned long aio_context_t;
typedef unsigned long long u64;
// ------ MAKE PYCPARSER HAPPY ------



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

// Adding OpenSSL is nice, but adds a huge load time.
#include <openssl/ssl.h>

#include <aio.h>
#include <aliases.h>
#include <alloca.h>
#include <a.out.h>
#include <argp.h>
#include <argz.h>
#include <ar.h>
#include <assert.h>
#include <byteswap.h>
#include <complex.h>
#include <cpio.h>
#include <crypt.h>
#include <ctype.h>
#include <dirent.h>
#include <dlfcn.h>
// #include <elf.h>
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
#include <fpu_control.h>
#include <fstab.h>
#include <fts.h>
#include <ftw.h>
#include <_G_config.h>
#include <gconv.h>
#include <getopt.h>
#include <glob.h>
#include <gnu-versions.h>
#include <grp.h>
#include <gshadow.h>
#include <iconv.h>
#include <ieee754.h>
#include <ifaddrs.h>
#include <inttypes.h>
#include <langinfo.h>
#include <lastlog.h>
#include <libgen.h>
#include <libintl.h>
#include <libio.h>
#include <limits.h>
#include <link.h>
#include <locale.h>
#include <lzma.h>
#include <malloc.h>
#include <math.h>
#include <mcheck.h>
#include <memory.h>
#include <mntent.h>
#include <monetary.h>
#include <mqueue.h>
#include <netdb.h>
#include <nl_types.h>
#include <nss.h>
#include <obstack.h>
#include <paths.h>
#include <poll.h>
#include <printf.h>
#include <pthread.h>
#include <pty.h>
#include <pwd.h>
#include <re_comp.h>
#include <regex.h>
// #include <regexp.h>
#include <resolv.h>
#include <sched.h>
#include <search.h>
#include <semaphore.h>
#include <setjmp.h>
#include <sgtty.h>
#include <shadow.h>
#include <signal.h>
#include <spawn.h>
#include <stab.h>
// #include <stdc-predef.h>
#include <stdint.h>
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stropts.h>
#include <syscall.h>
#include <sysexits.h>
#include <syslog.h>
#include <tar.h>
#include <termio.h>
#include <termios.h>
// #include <tgmath.h>
#include <thread_db.h>
#include <time.h>
#include <ttyent.h>
// #include <uchar.h>
#include <ucontext.h>
#include <ulimit.h>
#include <unistd.h>
#include <ustat.h>
#include <utime.h>
#include <utmp.h>
#include <utmpx.h>
#include <values.h>
#include <wait.h>
#include <wchar.h>
#include <wctype.h>
#include <wordexp.h>
#include <xlocale.h>
#include <zlib.h>

#include <sys/auxv.h>
#include <sys/bitypes.h>
#include <sys/cdefs.h>
#include <sys/debugreg.h>
#include <sys/dir.h>
// #include <sys/elf.h>
#include <sys/epoll.h>
#include <sys/errno.h>
#include <sys/eventfd.h>
#include <sys/fanotify.h>
#include <sys/fcntl.h>
#include <sys/file.h>
#include <sys/fsuid.h>
#include <sys/gmon.h>
#include <sys/gmon_out.h>
#include <sys/inotify.h>
#include <sys/ioctl.h>
#include <sys/io.h>
#include <sys/ipc.h>
#include <sys/kd.h>
#include <sys/klog.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <sys/msg.h>
#include <sys/mtio.h>
#include <sys/param.h>
#include <sys/pci.h>
#include <sys/perm.h>
#include <sys/personality.h>
#include <sys/poll.h>
#include <sys/prctl.h>
#include <sys/procfs.h>
#include <sys/profil.h>
#include <sys/ptrace.h>
#include <sys/queue.h>
#include <sys/quota.h>
#include <sys/raw.h>
#include <sys/reboot.h>
#include <sys/reg.h>
#include <sys/resource.h>
#include <sys/select.h>
#include <sys/sem.h>
#include <sys/sendfile.h>
#include <sys/shm.h>
#include <sys/signalfd.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/socketvar.h>
#include <sys/soundcard.h>
#include <sys/statfs.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/stropts.h>
#include <sys/swap.h>
#include <sys/syscall.h>
#include <sys/sysctl.h>
#include <sys/sysinfo.h>
#include <sys/syslog.h>
#include <sys/sysmacros.h>
#include <sys/termios.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <sys/timerfd.h>
#include <sys/times.h>
#include <sys/timex.h>
#include <sys/ttychars.h>
#include <sys/ttydefaults.h>
#include <sys/types.h>
#include <sys/ucontext.h>
#include <sys/uio.h>
#include <sys/ultrasound.h>
#include <sys/un.h>
#include <sys/unistd.h>
#include <sys/user.h>
#include <sys/ustat.h>
#include <sys/utsname.h>
#include <sys/vfs.h>
#include <sys/vlimit.h>
// #include <sys/vm86.h>
#include <sys/vt.h>
#include <sys/vtimes.h>
#include <sys/wait.h>
#include <sys/xattr.h>

#include "missing.h"
