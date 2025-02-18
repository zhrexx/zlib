/*
* License Notice:
* 
* This project uses code originally written by Marcus Geelnard (2012) and Evan Nemerson (2013-2016) and was modificated by Jan Moretz (i.e. zhrexx 2025). The code is provided "as-is" without any express or implied warranty. The authors are not liable for any damages arising from the use of this code.
* 
* You may use, modify, and redistribute this code for any purpose, including commercial use, as long as you do not misrepresent the origin of the code. If you modify the code, you must clearly mark it as altered and cannot present it as the original. This license notice must remain intact in any redistributed source code. 
*/
#ifndef TINYCTHREAD_SINGLE_H_INCLUDED
#define TINYCTHREAD_SINGLE_H_INCLUDED
typedef long unsigned int size_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct {
    int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};
struct timex {
    unsigned int modes;
    __syscall_slong_t offset;
    __syscall_slong_t freq;
    __syscall_slong_t maxerror;
    __syscall_slong_t esterror;
    int status;
    __syscall_slong_t constant;
    __syscall_slong_t precision;
    __syscall_slong_t tolerance;
    struct timeval time;
    __syscall_slong_t tick;
    __syscall_slong_t ppsfreq;
    __syscall_slong_t jitter;
    int shift;
    __syscall_slong_t stabil;
    __syscall_slong_t jitcnt;
    __syscall_slong_t calcnt;
    __syscall_slong_t errcnt;
    __syscall_slong_t stbcnt;
    int tai;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
};
extern int clock_adjtime(__clockid_t __clock_id, struct timex *__utx)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
typedef __clock_t clock_t;
typedef __time_t time_t;
struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long int tm_gmtoff;
    const char *tm_zone;
};
struct timespec {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
};
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
struct itimerspec {
    struct timespec it_interval;
    struct timespec it_value;
};
struct sigevent;
typedef __pid_t pid_t;
struct __locale_struct {
    struct __locale_data *__locales[13];
    const unsigned short int *__ctype_b;
    const int *__ctype_tolower;
    const int *__ctype_toupper;
    const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern clock_t clock(void) __attribute__((__nothrow__, __leaf__));
extern time_t time(time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern double difftime(time_t __time1, time_t __time0);
extern time_t mktime(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern size_t strftime(char *__restrict __s, size_t __maxsize, const char *__restrict __format,
                       const struct tm *__restrict __tp) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3, 4)));
extern char *strptime(const char *__restrict __s, const char *__restrict __fmt, struct tm *__tp)
    __attribute__((__nothrow__, __leaf__));
extern size_t strftime_l(char *__restrict __s, size_t __maxsize, const char *__restrict __format,
                         const struct tm *__restrict __tp, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));
extern char *strptime_l(const char *__restrict __s, const char *__restrict __fmt, struct tm *__tp,
                        locale_t __loc) __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime(const time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime(const time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime_r(const time_t *__restrict __timer, struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime_r(const time_t *__restrict __timer, struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime(const struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern char *ctime(const time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern char *asctime_r(const struct tm *__restrict __tp, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *ctime_r(const time_t *__restrict __timer, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset(void) __attribute__((__nothrow__, __leaf__));
extern int daylight;
extern long int timezone;
extern time_t timegm(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern time_t timelocal(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern int dysize(int __year) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int nanosleep(const struct timespec *__requested_time, struct timespec *__remaining);
extern int clock_getres(clockid_t __clock_id, struct timespec *__res)
    __attribute__((__nothrow__, __leaf__));
extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int clock_settime(clockid_t __clock_id, const struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int clock_nanosleep(clockid_t __clock_id, int __flags, const struct timespec *__req,
                           struct timespec *__rem);
extern int clock_getcpuclockid(pid_t __pid, clockid_t *__clock_id)
    __attribute__((__nothrow__, __leaf__));
extern int timer_create(clockid_t __clock_id, struct sigevent *__restrict __evp,
                        timer_t *__restrict __timerid) __attribute__((__nothrow__, __leaf__));
extern int timer_delete(timer_t __timerid) __attribute__((__nothrow__, __leaf__));
extern int timer_settime(timer_t __timerid, int __flags,
                         const struct itimerspec *__restrict __value,
                         struct itimerspec *__restrict __ovalue)
    __attribute__((__nothrow__, __leaf__));
extern int timer_gettime(timer_t __timerid, struct itimerspec *__value)
    __attribute__((__nothrow__, __leaf__));
extern int timer_getoverrun(timer_t __timerid) __attribute__((__nothrow__, __leaf__));
extern int timespec_get(struct timespec *__ts, int __base) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int timespec_getres(struct timespec *__ts, int __base)
    __attribute__((__nothrow__, __leaf__));
extern int getdate_err;
extern struct tm *getdate(const char *__string);
extern int getdate_r(const char *__restrict __string, struct tm *__restrict __resbufp);
struct sched_param {
    int sched_priority;
};
extern int clone(int (*__fn)(void *__arg), void *__child_stack, int __flags, void *__arg, ...)
    __attribute__((__nothrow__, __leaf__));
extern int unshare(int __flags) __attribute__((__nothrow__, __leaf__));
extern int sched_getcpu(void) __attribute__((__nothrow__, __leaf__));
extern int getcpu(unsigned int *, unsigned int *) __attribute__((__nothrow__, __leaf__));
extern int setns(int __fd, int __nstype) __attribute__((__nothrow__, __leaf__));
typedef unsigned long int __cpu_mask;
typedef struct {
    __cpu_mask __bits[1024 / (8 * sizeof(__cpu_mask))];
} cpu_set_t;
extern int __sched_cpucount(size_t __setsize, const cpu_set_t *__setp)
    __attribute__((__nothrow__, __leaf__));
extern cpu_set_t *__sched_cpualloc(size_t __count) __attribute__((__nothrow__, __leaf__));
extern void __sched_cpufree(cpu_set_t *__set) __attribute__((__nothrow__, __leaf__));
extern int sched_setparam(__pid_t __pid, const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getparam(__pid_t __pid, struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_setscheduler(__pid_t __pid, int __policy, const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getscheduler(__pid_t __pid) __attribute__((__nothrow__, __leaf__));
extern int sched_yield(void) __attribute__((__nothrow__, __leaf__));
extern int sched_get_priority_max(int __algorithm) __attribute__((__nothrow__, __leaf__));
extern int sched_get_priority_min(int __algorithm) __attribute__((__nothrow__, __leaf__));
extern int sched_rr_get_interval(__pid_t __pid, struct timespec *__t)
    __attribute__((__nothrow__, __leaf__));
extern int sched_setaffinity(__pid_t __pid, size_t __cpusetsize, const cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getaffinity(__pid_t __pid, size_t __cpusetsize, cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__));
typedef union {
    __extension__ unsigned long long int __value64;
    struct {
        unsigned int __low;
        unsigned int __high;
    } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist {
    struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    short __spins;
    short __elision;
    __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t {
    unsigned int __readers;
    unsigned int __writers;
    unsigned int __wrphase_futex;
    unsigned int __writers_futex;
    unsigned int __pad3;
    unsigned int __pad4;
    int __cur_writer;
    int __shared;
    signed char __rwelision;
    unsigned char __pad1[7];
    unsigned long int __pad2;
    unsigned int __flags;
};
struct __pthread_cond_s {
    __atomic_wide_counter __wseq;
    __atomic_wide_counter __g1_start;
    unsigned int __g_refs[2];
    unsigned int __g_size[2];
    unsigned int __g1_orig_size;
    unsigned int __wrefs;
    unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct {
    int __data;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union {
    char __size[4];
    int __align;
} pthread_mutexattr_t;
typedef union {
    char __size[4];
    int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t {
    char __size[56];
    long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union {
    struct __pthread_mutex_s __data;
    char __size[40];
    long int __align;
} pthread_mutex_t;
typedef union {
    struct __pthread_cond_s __data;
    char __size[48];
    __extension__ long long int __align;
} pthread_cond_t;
typedef union {
    struct __pthread_rwlock_arch_t __data;
    char __size[56];
    long int __align;
} pthread_rwlock_t;
typedef union {
    char __size[8];
    long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union {
    char __size[32];
    long int __align;
} pthread_barrier_t;
typedef union {
    char __size[4];
    int __align;
} pthread_barrierattr_t;
typedef long int __jmp_buf[8];
typedef struct {
    unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;
struct __jmp_buf_tag {
    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
};
extern long int __sysconf(int __name) __attribute__((__nothrow__, __leaf__));
enum { PTHREAD_CREATE_JOINABLE, PTHREAD_CREATE_DETACHED };
enum {
    PTHREAD_MUTEX_TIMED_NP,
    PTHREAD_MUTEX_RECURSIVE_NP,
    PTHREAD_MUTEX_ERRORCHECK_NP,
    PTHREAD_MUTEX_ADAPTIVE_NP,
    PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
    PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
    PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
    PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL,
    PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP
};
enum {
    PTHREAD_MUTEX_STALLED,
    PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
    PTHREAD_MUTEX_ROBUST,
    PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
enum { PTHREAD_PRIO_NONE, PTHREAD_PRIO_INHERIT, PTHREAD_PRIO_PROTECT };
enum {
    PTHREAD_RWLOCK_PREFER_READER_NP,
    PTHREAD_RWLOCK_PREFER_WRITER_NP,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
    PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum { PTHREAD_INHERIT_SCHED, PTHREAD_EXPLICIT_SCHED };
enum { PTHREAD_SCOPE_SYSTEM, PTHREAD_SCOPE_PROCESS };
enum { PTHREAD_PROCESS_PRIVATE, PTHREAD_PROCESS_SHARED };
struct _pthread_cleanup_buffer {
    void (*__routine)(void *);
    void *__arg;
    int __canceltype;
    struct _pthread_cleanup_buffer *__prev;
};
enum { PTHREAD_CANCEL_ENABLE, PTHREAD_CANCEL_DISABLE };
enum { PTHREAD_CANCEL_DEFERRED, PTHREAD_CANCEL_ASYNCHRONOUS };
extern int pthread_create(pthread_t *__restrict __newthread,
                          const pthread_attr_t *__restrict __attr, void *(*__start_routine)(void *),
                          void *__restrict __arg) __attribute__((__nothrow__))
__attribute__((__nonnull__(1, 3)));
extern void pthread_exit(void *__retval) __attribute__((__noreturn__));
extern int pthread_join(pthread_t __th, void **__thread_return);
extern int pthread_tryjoin_np(pthread_t __th, void **__thread_return)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_timedjoin_np(pthread_t __th, void **__thread_return,
                                const struct timespec *__abstime);
extern int pthread_clockjoin_np(pthread_t __th, void **__thread_return, clockid_t __clockid,
                                const struct timespec *__abstime);
extern int pthread_detach(pthread_t __th) __attribute__((__nothrow__, __leaf__));
extern pthread_t pthread_self(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int pthread_equal(pthread_t __thread1, pthread_t __thread2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int pthread_attr_init(pthread_attr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_destroy(pthread_attr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_getdetachstate(const pthread_attr_t *__attr, int *__detachstate)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setdetachstate(pthread_attr_t *__attr, int __detachstate)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getguardsize(const pthread_attr_t *__attr, size_t *__guardsize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setguardsize(pthread_attr_t *__attr, size_t __guardsize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getschedparam(const pthread_attr_t *__restrict __attr,
                                      struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setschedparam(pthread_attr_t *__restrict __attr,
                                      const struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_getschedpolicy(const pthread_attr_t *__restrict __attr,
                                       int *__restrict __policy)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setschedpolicy(pthread_attr_t *__attr, int __policy)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getinheritsched(const pthread_attr_t *__restrict __attr,
                                        int *__restrict __inherit)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setinheritsched(pthread_attr_t *__attr, int __inherit)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getscope(const pthread_attr_t *__restrict __attr, int *__restrict __scope)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setscope(pthread_attr_t *__attr, int __scope)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getstackaddr(const pthread_attr_t *__restrict __attr,
                                     void **__restrict __stackaddr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__deprecated__));
extern int pthread_attr_setstackaddr(pthread_attr_t *__attr, void *__stackaddr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__));
extern int pthread_attr_getstacksize(const pthread_attr_t *__restrict __attr,
                                     size_t *__restrict __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setstacksize(pthread_attr_t *__attr, size_t __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getstack(const pthread_attr_t *__restrict __attr,
                                 void **__restrict __stackaddr, size_t *__restrict __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2, 3)));
extern int pthread_attr_setstack(pthread_attr_t *__attr, void *__stackaddr, size_t __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_setaffinity_np(pthread_attr_t *__attr, size_t __cpusetsize,
                                       const cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_attr_getaffinity_np(const pthread_attr_t *__attr, size_t __cpusetsize,
                                       cpu_set_t *__cpuset) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern int pthread_getattr_default_np(pthread_attr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_setsigmask_np(pthread_attr_t *__attr, const __sigset_t *sigmask);
extern int pthread_attr_getsigmask_np(const pthread_attr_t *__attr, __sigset_t *sigmask);
extern int pthread_setattr_default_np(const pthread_attr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_getattr_np(pthread_t __th, pthread_attr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_setschedparam(pthread_t __target_thread, int __policy,
                                 const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_getschedparam(pthread_t __target_thread, int *__restrict __policy,
                                 struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int pthread_setschedprio(pthread_t __target_thread, int __prio)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_getname_np(pthread_t __target_thread, char *__buf, size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_setname_np(pthread_t __target_thread, const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_getconcurrency(void) __attribute__((__nothrow__, __leaf__));
extern int pthread_setconcurrency(int __level) __attribute__((__nothrow__, __leaf__));
extern int pthread_yield(void) __attribute__((__nothrow__, __leaf__));
extern int pthread_yield(void) __asm__(""
                                       "sched_yield") __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("pthread_yield is deprecated, use sched_yield instead")));
extern int pthread_setaffinity_np(pthread_t __th, size_t __cpusetsize, const cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_getaffinity_np(pthread_t __th, size_t __cpusetsize, cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_once(pthread_once_t *__once_control, void (*__init_routine)(void))
    __attribute__((__nonnull__(1, 2)));
extern int pthread_setcancelstate(int __state, int *__oldstate);
extern int pthread_setcanceltype(int __type, int *__oldtype);
extern int pthread_cancel(pthread_t __th);
extern void pthread_testcancel(void);
struct __cancel_jmp_buf_tag {
    __jmp_buf __cancel_jmp_buf;
    int __mask_was_saved;
};
typedef struct {
    struct __cancel_jmp_buf_tag __cancel_jmp_buf[1];
    void *__pad[4];
} __pthread_unwind_buf_t __attribute__((__aligned__));
struct __pthread_cleanup_frame {
    void (*__cancel_routine)(void *);
    void *__cancel_arg;
    int __do_it;
    int __cancel_type;
};
extern void __pthread_register_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_unregister_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_register_cancel_defer(__pthread_unwind_buf_t *__buf);
extern void __pthread_unregister_cancel_restore(__pthread_unwind_buf_t *__buf);
extern void __pthread_unwind_next(__pthread_unwind_buf_t *__buf) __attribute__((__noreturn__))
__attribute__((__weak__));
extern int __sigsetjmp_cancel(struct __cancel_jmp_buf_tag __env[1],
                              int __savemask) __asm__(""
                                                      "__sigsetjmp") __attribute__((__nothrow__))
__attribute__((__returns_twice__));
extern int pthread_mutex_init(pthread_mutex_t *__mutex, const pthread_mutexattr_t *__mutexattr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_destroy(pthread_mutex_t *__mutex) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_trylock(pthread_mutex_t *__mutex) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_lock(pthread_mutex_t *__mutex) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_timedlock(pthread_mutex_t *__restrict __mutex,
                                   const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutex_clocklock(pthread_mutex_t *__restrict __mutex, clockid_t __clockid,
                                   const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_mutex_unlock(pthread_mutex_t *__mutex) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_getprioceiling(const pthread_mutex_t *__restrict __mutex,
                                        int *__restrict __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutex_setprioceiling(pthread_mutex_t *__restrict __mutex, int __prioceiling,
                                        int *__restrict __old_ceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_mutex_consistent(pthread_mutex_t *__mutex) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_consistent_np(pthread_mutex_t *) __asm__(""
                                                                  "pthread_mutex_consistent")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1))) __attribute__((
        __deprecated__("pthread_mutex_consistent_np is deprecated, use pthread_mutex_consistent")));
extern int pthread_mutexattr_init(pthread_mutexattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_destroy(pthread_mutexattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getpshared(const pthread_mutexattr_t *__restrict __attr,
                                        int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setpshared(pthread_mutexattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_gettype(const pthread_mutexattr_t *__restrict __attr,
                                     int *__restrict __kind) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_settype(pthread_mutexattr_t *__attr, int __kind)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *__restrict __attr,
                                         int *__restrict __protocol)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setprotocol(pthread_mutexattr_t *__attr, int __protocol)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *__restrict __attr,
                                            int *__restrict __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *__attr, int __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getrobust(const pthread_mutexattr_t *__attr, int *__robustness)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_getrobust_np(pthread_mutexattr_t *,
                                          int *) __asm__(""
                                                         "pthread_mutexattr_getrobust")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__(
        "pthread_mutexattr_getrobust_np is deprecated, use pthread_mutexattr_getrobust")));
extern int pthread_mutexattr_setrobust(pthread_mutexattr_t *__attr, int __robustness)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_setrobust_np(pthread_mutexattr_t *,
                                          int) __asm__(""
                                                       "pthread_mutexattr_setrobust")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__(
        "pthread_mutexattr_setrobust_np is deprecated, use pthread_mutexattr_setrobust")));
extern int pthread_rwlock_init(pthread_rwlock_t *__restrict __rwlock,
                               const pthread_rwlockattr_t *__restrict __attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_destroy(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_tryrdlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_timedrdlock(pthread_rwlock_t *__restrict __rwlock,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlock_clockrdlock(pthread_rwlock_t *__restrict __rwlock, clockid_t __clockid,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_trywrlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_timedwrlock(pthread_rwlock_t *__restrict __rwlock,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlock_clockwrlock(pthread_rwlock_t *__restrict __rwlock, clockid_t __clockid,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_init(pthread_rwlockattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_destroy(pthread_rwlockattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *__restrict __attr,
                                         int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *__restrict __attr,
                                         int *__restrict __pref)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *__attr, int __pref)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_init(pthread_cond_t *__restrict __cond,
                             const pthread_condattr_t *__restrict __cond_attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_destroy(pthread_cond_t *__cond) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_cond_signal(pthread_cond_t *__cond) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_cond_broadcast(pthread_cond_t *__cond) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_cond_wait(pthread_cond_t *__restrict __cond, pthread_mutex_t *__restrict __mutex)
    __attribute__((__nonnull__(1, 2)));
extern int pthread_cond_timedwait(pthread_cond_t *__restrict __cond,
                                  pthread_mutex_t *__restrict __mutex,
                                  const struct timespec *__restrict __abstime)
    __attribute__((__nonnull__(1, 2, 3)));
extern int pthread_cond_clockwait(pthread_cond_t *__restrict __cond,
                                  pthread_mutex_t *__restrict __mutex, __clockid_t __clock_id,
                                  const struct timespec *__restrict __abstime)
    __attribute__((__nonnull__(1, 2, 4)));
extern int pthread_condattr_init(pthread_condattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_condattr_destroy(pthread_condattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_condattr_getpshared(const pthread_condattr_t *__restrict __attr,
                                       int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_condattr_setpshared(pthread_condattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_condattr_getclock(const pthread_condattr_t *__restrict __attr,
                                     __clockid_t *__restrict __clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_condattr_setclock(pthread_condattr_t *__attr, __clockid_t __clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_init(pthread_spinlock_t *__lock, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_destroy(pthread_spinlock_t *__lock) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_spin_lock(pthread_spinlock_t *__lock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_spin_trylock(pthread_spinlock_t *__lock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_spin_unlock(pthread_spinlock_t *__lock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_barrier_init(pthread_barrier_t *__restrict __barrier,
                                const pthread_barrierattr_t *__restrict __attr,
                                unsigned int __count) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_barrier_destroy(pthread_barrier_t *__barrier)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrier_wait(pthread_barrier_t *__barrier) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_barrierattr_init(pthread_barrierattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrierattr_destroy(pthread_barrierattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrierattr_getpshared(const pthread_barrierattr_t *__restrict __attr,
                                          int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_barrierattr_setpshared(pthread_barrierattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_key_create(pthread_key_t *__key, void (*__destr_function)(void *))
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_key_delete(pthread_key_t __key) __attribute__((__nothrow__, __leaf__));
extern void *pthread_getspecific(pthread_key_t __key) __attribute__((__nothrow__, __leaf__));
extern int pthread_setspecific(pthread_key_t __key, const void *__pointer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__access__(__none__, 2)));
extern int pthread_getcpuclockid(pthread_t __thread_id, __clockid_t *__clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_atfork(void (*__prepare)(void), void (*__parent)(void), void (*__child)(void))
    __attribute__((__nothrow__, __leaf__));
typedef pthread_mutex_t mtx_t;
int mtx_init(mtx_t *mtx, int type);
void mtx_destroy(mtx_t *mtx);
int mtx_lock(mtx_t *mtx);
int mtx_timedlock(mtx_t *mtx, const struct timespec *ts);
int mtx_trylock(mtx_t *mtx);
int mtx_unlock(mtx_t *mtx);
typedef pthread_cond_t cnd_t;
int cnd_init(cnd_t *cond);
void cnd_destroy(cnd_t *cond);
int cnd_signal(cnd_t *cond);
int cnd_broadcast(cnd_t *cond);
int cnd_wait(cnd_t *cond, mtx_t *mtx);
int cnd_timedwait(cnd_t *cond, mtx_t *mtx, const struct timespec *ts);
typedef pthread_t thrd_t;
typedef int (*thrd_start_t)(void *arg);
int thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
thrd_t thrd_current(void);
int thrd_detach(thrd_t thr);
int thrd_equal(thrd_t thr0, thrd_t thr1);
_Noreturn void thrd_exit(int res);
int thrd_join(thrd_t thr, int *res);
int thrd_sleep(const struct timespec *duration, struct timespec *remaining);
void thrd_yield(void);
typedef pthread_key_t tss_t;
typedef void (*tss_dtor_t)(void *val);
int tss_create(tss_t *key, tss_dtor_t dtor);
void tss_delete(tss_t key);
void *tss_get(tss_t key);
int tss_set(tss_t key, void *val);
#ifdef IMPLEMENTATION
typedef long unsigned int size_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct {
    int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};
struct timex {
    unsigned int modes;
    __syscall_slong_t offset;
    __syscall_slong_t freq;
    __syscall_slong_t maxerror;
    __syscall_slong_t esterror;
    int status;
    __syscall_slong_t constant;
    __syscall_slong_t precision;
    __syscall_slong_t tolerance;
    struct timeval time;
    __syscall_slong_t tick;
    __syscall_slong_t ppsfreq;
    __syscall_slong_t jitter;
    int shift;
    __syscall_slong_t stabil;
    __syscall_slong_t jitcnt;
    __syscall_slong_t calcnt;
    __syscall_slong_t errcnt;
    __syscall_slong_t stbcnt;
    int tai;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
    int : 32;
};
extern int clock_adjtime(__clockid_t __clock_id, struct timex *__utx)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
typedef __clock_t clock_t;
typedef __time_t time_t;
struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long int tm_gmtoff;
    const char *tm_zone;
};
struct timespec {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
};
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
struct itimerspec {
    struct timespec it_interval;
    struct timespec it_value;
};
struct sigevent;
typedef __pid_t pid_t;
struct __locale_struct {
    struct __locale_data *__locales[13];
    const unsigned short int *__ctype_b;
    const int *__ctype_tolower;
    const int *__ctype_toupper;
    const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern clock_t clock(void) __attribute__((__nothrow__, __leaf__));
extern time_t time(time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern double difftime(time_t __time1, time_t __time0);
extern time_t mktime(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern size_t strftime(char *__restrict __s, size_t __maxsize, const char *__restrict __format,
                       const struct tm *__restrict __tp) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3, 4)));
extern char *strptime(const char *__restrict __s, const char *__restrict __fmt, struct tm *__tp)
    __attribute__((__nothrow__, __leaf__));
extern size_t strftime_l(char *__restrict __s, size_t __maxsize, const char *__restrict __format,
                         const struct tm *__restrict __tp, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));
extern char *strptime_l(const char *__restrict __s, const char *__restrict __fmt, struct tm *__tp,
                        locale_t __loc) __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime(const time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime(const time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime_r(const time_t *__restrict __timer, struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime_r(const time_t *__restrict __timer, struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime(const struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern char *ctime(const time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern char *asctime_r(const struct tm *__restrict __tp, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *ctime_r(const time_t *__restrict __timer, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset(void) __attribute__((__nothrow__, __leaf__));
extern int daylight;
extern long int timezone;
extern time_t timegm(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern time_t timelocal(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern int dysize(int __year) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int nanosleep(const struct timespec *__requested_time, struct timespec *__remaining);
extern int clock_getres(clockid_t __clock_id, struct timespec *__res)
    __attribute__((__nothrow__, __leaf__));
extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int clock_settime(clockid_t __clock_id, const struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int clock_nanosleep(clockid_t __clock_id, int __flags, const struct timespec *__req,
                           struct timespec *__rem);
extern int clock_getcpuclockid(pid_t __pid, clockid_t *__clock_id)
    __attribute__((__nothrow__, __leaf__));
extern int timer_create(clockid_t __clock_id, struct sigevent *__restrict __evp,
                        timer_t *__restrict __timerid) __attribute__((__nothrow__, __leaf__));
extern int timer_delete(timer_t __timerid) __attribute__((__nothrow__, __leaf__));
extern int timer_settime(timer_t __timerid, int __flags,
                         const struct itimerspec *__restrict __value,
                         struct itimerspec *__restrict __ovalue)
    __attribute__((__nothrow__, __leaf__));
extern int timer_gettime(timer_t __timerid, struct itimerspec *__value)
    __attribute__((__nothrow__, __leaf__));
extern int timer_getoverrun(timer_t __timerid) __attribute__((__nothrow__, __leaf__));
extern int timespec_get(struct timespec *__ts, int __base) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int timespec_getres(struct timespec *__ts, int __base)
    __attribute__((__nothrow__, __leaf__));
extern int getdate_err;
extern struct tm *getdate(const char *__string);
extern int getdate_r(const char *__restrict __string, struct tm *__restrict __resbufp);
struct sched_param {
    int sched_priority;
};
extern int clone(int (*__fn)(void *__arg), void *__child_stack, int __flags, void *__arg, ...)
    __attribute__((__nothrow__, __leaf__));
extern int unshare(int __flags) __attribute__((__nothrow__, __leaf__));
extern int sched_getcpu(void) __attribute__((__nothrow__, __leaf__));
extern int getcpu(unsigned int *, unsigned int *) __attribute__((__nothrow__, __leaf__));
extern int setns(int __fd, int __nstype) __attribute__((__nothrow__, __leaf__));
typedef unsigned long int __cpu_mask;
typedef struct {
    __cpu_mask __bits[1024 / (8 * sizeof(__cpu_mask))];
} cpu_set_t;
extern int __sched_cpucount(size_t __setsize, const cpu_set_t *__setp)
    __attribute__((__nothrow__, __leaf__));
extern cpu_set_t *__sched_cpualloc(size_t __count) __attribute__((__nothrow__, __leaf__));
extern void __sched_cpufree(cpu_set_t *__set) __attribute__((__nothrow__, __leaf__));
extern int sched_setparam(__pid_t __pid, const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getparam(__pid_t __pid, struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_setscheduler(__pid_t __pid, int __policy, const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getscheduler(__pid_t __pid) __attribute__((__nothrow__, __leaf__));
extern int sched_yield(void) __attribute__((__nothrow__, __leaf__));
extern int sched_get_priority_max(int __algorithm) __attribute__((__nothrow__, __leaf__));
extern int sched_get_priority_min(int __algorithm) __attribute__((__nothrow__, __leaf__));
extern int sched_rr_get_interval(__pid_t __pid, struct timespec *__t)
    __attribute__((__nothrow__, __leaf__));
extern int sched_setaffinity(__pid_t __pid, size_t __cpusetsize, const cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getaffinity(__pid_t __pid, size_t __cpusetsize, cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__));
typedef union {
    __extension__ unsigned long long int __value64;
    struct {
        unsigned int __low;
        unsigned int __high;
    } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist {
    struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    short __spins;
    short __elision;
    __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t {
    unsigned int __readers;
    unsigned int __writers;
    unsigned int __wrphase_futex;
    unsigned int __writers_futex;
    unsigned int __pad3;
    unsigned int __pad4;
    int __cur_writer;
    int __shared;
    signed char __rwelision;
    unsigned char __pad1[7];
    unsigned long int __pad2;
    unsigned int __flags;
};
struct __pthread_cond_s {
    __atomic_wide_counter __wseq;
    __atomic_wide_counter __g1_start;
    unsigned int __g_refs[2];
    unsigned int __g_size[2];
    unsigned int __g1_orig_size;
    unsigned int __wrefs;
    unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct {
    int __data;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union {
    char __size[4];
    int __align;
} pthread_mutexattr_t;
typedef union {
    char __size[4];
    int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t {
    char __size[56];
    long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union {
    struct __pthread_mutex_s __data;
    char __size[40];
    long int __align;
} pthread_mutex_t;
typedef union {
    struct __pthread_cond_s __data;
    char __size[48];
    __extension__ long long int __align;
} pthread_cond_t;
typedef union {
    struct __pthread_rwlock_arch_t __data;
    char __size[56];
    long int __align;
} pthread_rwlock_t;
typedef union {
    char __size[8];
    long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union {
    char __size[32];
    long int __align;
} pthread_barrier_t;
typedef union {
    char __size[4];
    int __align;
} pthread_barrierattr_t;
typedef long int __jmp_buf[8];
typedef struct {
    unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;
struct __jmp_buf_tag {
    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
};
extern long int __sysconf(int __name) __attribute__((__nothrow__, __leaf__));
enum { PTHREAD_CREATE_JOINABLE, PTHREAD_CREATE_DETACHED };
enum {
    PTHREAD_MUTEX_TIMED_NP,
    PTHREAD_MUTEX_RECURSIVE_NP,
    PTHREAD_MUTEX_ERRORCHECK_NP,
    PTHREAD_MUTEX_ADAPTIVE_NP,
    PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
    PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
    PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
    PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL,
    PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP
};
enum {
    PTHREAD_MUTEX_STALLED,
    PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
    PTHREAD_MUTEX_ROBUST,
    PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
enum { PTHREAD_PRIO_NONE, PTHREAD_PRIO_INHERIT, PTHREAD_PRIO_PROTECT };
enum {
    PTHREAD_RWLOCK_PREFER_READER_NP,
    PTHREAD_RWLOCK_PREFER_WRITER_NP,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
    PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum { PTHREAD_INHERIT_SCHED, PTHREAD_EXPLICIT_SCHED };
enum { PTHREAD_SCOPE_SYSTEM, PTHREAD_SCOPE_PROCESS };
enum { PTHREAD_PROCESS_PRIVATE, PTHREAD_PROCESS_SHARED };
struct _pthread_cleanup_buffer {
    void (*__routine)(void *);
    void *__arg;
    int __canceltype;
    struct _pthread_cleanup_buffer *__prev;
};
enum { PTHREAD_CANCEL_ENABLE, PTHREAD_CANCEL_DISABLE };
enum { PTHREAD_CANCEL_DEFERRED, PTHREAD_CANCEL_ASYNCHRONOUS };
extern int pthread_create(pthread_t *__restrict __newthread,
                          const pthread_attr_t *__restrict __attr, void *(*__start_routine)(void *),
                          void *__restrict __arg) __attribute__((__nothrow__))
__attribute__((__nonnull__(1, 3)));
extern void pthread_exit(void *__retval) __attribute__((__noreturn__));
extern int pthread_join(pthread_t __th, void **__thread_return);
extern int pthread_tryjoin_np(pthread_t __th, void **__thread_return)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_timedjoin_np(pthread_t __th, void **__thread_return,
                                const struct timespec *__abstime);
extern int pthread_clockjoin_np(pthread_t __th, void **__thread_return, clockid_t __clockid,
                                const struct timespec *__abstime);
extern int pthread_detach(pthread_t __th) __attribute__((__nothrow__, __leaf__));
extern pthread_t pthread_self(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int pthread_equal(pthread_t __thread1, pthread_t __thread2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int pthread_attr_init(pthread_attr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_destroy(pthread_attr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_getdetachstate(const pthread_attr_t *__attr, int *__detachstate)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setdetachstate(pthread_attr_t *__attr, int __detachstate)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getguardsize(const pthread_attr_t *__attr, size_t *__guardsize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setguardsize(pthread_attr_t *__attr, size_t __guardsize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getschedparam(const pthread_attr_t *__restrict __attr,
                                      struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setschedparam(pthread_attr_t *__restrict __attr,
                                      const struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_getschedpolicy(const pthread_attr_t *__restrict __attr,
                                       int *__restrict __policy)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setschedpolicy(pthread_attr_t *__attr, int __policy)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getinheritsched(const pthread_attr_t *__restrict __attr,
                                        int *__restrict __inherit)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setinheritsched(pthread_attr_t *__attr, int __inherit)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getscope(const pthread_attr_t *__restrict __attr, int *__restrict __scope)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setscope(pthread_attr_t *__attr, int __scope)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getstackaddr(const pthread_attr_t *__restrict __attr,
                                     void **__restrict __stackaddr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__deprecated__));
extern int pthread_attr_setstackaddr(pthread_attr_t *__attr, void *__stackaddr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__));
extern int pthread_attr_getstacksize(const pthread_attr_t *__restrict __attr,
                                     size_t *__restrict __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setstacksize(pthread_attr_t *__attr, size_t __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getstack(const pthread_attr_t *__restrict __attr,
                                 void **__restrict __stackaddr, size_t *__restrict __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2, 3)));
extern int pthread_attr_setstack(pthread_attr_t *__attr, void *__stackaddr, size_t __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_setaffinity_np(pthread_attr_t *__attr, size_t __cpusetsize,
                                       const cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_attr_getaffinity_np(const pthread_attr_t *__attr, size_t __cpusetsize,
                                       cpu_set_t *__cpuset) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern int pthread_getattr_default_np(pthread_attr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_setsigmask_np(pthread_attr_t *__attr, const __sigset_t *sigmask);
extern int pthread_attr_getsigmask_np(const pthread_attr_t *__attr, __sigset_t *sigmask);
extern int pthread_setattr_default_np(const pthread_attr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_getattr_np(pthread_t __th, pthread_attr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_setschedparam(pthread_t __target_thread, int __policy,
                                 const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_getschedparam(pthread_t __target_thread, int *__restrict __policy,
                                 struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int pthread_setschedprio(pthread_t __target_thread, int __prio)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_getname_np(pthread_t __target_thread, char *__buf, size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_setname_np(pthread_t __target_thread, const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_getconcurrency(void) __attribute__((__nothrow__, __leaf__));
extern int pthread_setconcurrency(int __level) __attribute__((__nothrow__, __leaf__));
extern int pthread_yield(void) __attribute__((__nothrow__, __leaf__));
extern int pthread_yield(void) __asm__(""
                                       "sched_yield") __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("pthread_yield is deprecated, use sched_yield instead")));
extern int pthread_setaffinity_np(pthread_t __th, size_t __cpusetsize, const cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_getaffinity_np(pthread_t __th, size_t __cpusetsize, cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_once(pthread_once_t *__once_control, void (*__init_routine)(void))
    __attribute__((__nonnull__(1, 2)));
extern int pthread_setcancelstate(int __state, int *__oldstate);
extern int pthread_setcanceltype(int __type, int *__oldtype);
extern int pthread_cancel(pthread_t __th);
extern void pthread_testcancel(void);
struct __cancel_jmp_buf_tag {
    __jmp_buf __cancel_jmp_buf;
    int __mask_was_saved;
};
typedef struct {
    struct __cancel_jmp_buf_tag __cancel_jmp_buf[1];
    void *__pad[4];
} __pthread_unwind_buf_t __attribute__((__aligned__));
struct __pthread_cleanup_frame {
    void (*__cancel_routine)(void *);
    void *__cancel_arg;
    int __do_it;
    int __cancel_type;
};
extern void __pthread_register_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_unregister_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_register_cancel_defer(__pthread_unwind_buf_t *__buf);
extern void __pthread_unregister_cancel_restore(__pthread_unwind_buf_t *__buf);
extern void __pthread_unwind_next(__pthread_unwind_buf_t *__buf) __attribute__((__noreturn__))
__attribute__((__weak__));
extern int __sigsetjmp_cancel(struct __cancel_jmp_buf_tag __env[1],
                              int __savemask) __asm__(""
                                                      "__sigsetjmp") __attribute__((__nothrow__))
__attribute__((__returns_twice__));
extern int pthread_mutex_init(pthread_mutex_t *__mutex, const pthread_mutexattr_t *__mutexattr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_destroy(pthread_mutex_t *__mutex) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_trylock(pthread_mutex_t *__mutex) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_lock(pthread_mutex_t *__mutex) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_timedlock(pthread_mutex_t *__restrict __mutex,
                                   const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutex_clocklock(pthread_mutex_t *__restrict __mutex, clockid_t __clockid,
                                   const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_mutex_unlock(pthread_mutex_t *__mutex) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_getprioceiling(const pthread_mutex_t *__restrict __mutex,
                                        int *__restrict __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutex_setprioceiling(pthread_mutex_t *__restrict __mutex, int __prioceiling,
                                        int *__restrict __old_ceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_mutex_consistent(pthread_mutex_t *__mutex) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_consistent_np(pthread_mutex_t *) __asm__(""
                                                                  "pthread_mutex_consistent")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1))) __attribute__((
        __deprecated__("pthread_mutex_consistent_np is deprecated, use pthread_mutex_consistent")));
extern int pthread_mutexattr_init(pthread_mutexattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_destroy(pthread_mutexattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getpshared(const pthread_mutexattr_t *__restrict __attr,
                                        int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setpshared(pthread_mutexattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_gettype(const pthread_mutexattr_t *__restrict __attr,
                                     int *__restrict __kind) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_settype(pthread_mutexattr_t *__attr, int __kind)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *__restrict __attr,
                                         int *__restrict __protocol)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setprotocol(pthread_mutexattr_t *__attr, int __protocol)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *__restrict __attr,
                                            int *__restrict __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *__attr, int __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getrobust(const pthread_mutexattr_t *__attr, int *__robustness)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_getrobust_np(pthread_mutexattr_t *,
                                          int *) __asm__(""
                                                         "pthread_mutexattr_getrobust")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__(
        "pthread_mutexattr_getrobust_np is deprecated, use pthread_mutexattr_getrobust")));
extern int pthread_mutexattr_setrobust(pthread_mutexattr_t *__attr, int __robustness)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_setrobust_np(pthread_mutexattr_t *,
                                          int) __asm__(""
                                                       "pthread_mutexattr_setrobust")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__(
        "pthread_mutexattr_setrobust_np is deprecated, use pthread_mutexattr_setrobust")));
extern int pthread_rwlock_init(pthread_rwlock_t *__restrict __rwlock,
                               const pthread_rwlockattr_t *__restrict __attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_destroy(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_tryrdlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_timedrdlock(pthread_rwlock_t *__restrict __rwlock,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlock_clockrdlock(pthread_rwlock_t *__restrict __rwlock, clockid_t __clockid,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_trywrlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_timedwrlock(pthread_rwlock_t *__restrict __rwlock,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlock_clockwrlock(pthread_rwlock_t *__restrict __rwlock, clockid_t __clockid,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_init(pthread_rwlockattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_destroy(pthread_rwlockattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *__restrict __attr,
                                         int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *__restrict __attr,
                                         int *__restrict __pref)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *__attr, int __pref)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_init(pthread_cond_t *__restrict __cond,
                             const pthread_condattr_t *__restrict __cond_attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_destroy(pthread_cond_t *__cond) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_cond_signal(pthread_cond_t *__cond) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_cond_broadcast(pthread_cond_t *__cond) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_cond_wait(pthread_cond_t *__restrict __cond, pthread_mutex_t *__restrict __mutex)
    __attribute__((__nonnull__(1, 2)));
extern int pthread_cond_timedwait(pthread_cond_t *__restrict __cond,
                                  pthread_mutex_t *__restrict __mutex,
                                  const struct timespec *__restrict __abstime)
    __attribute__((__nonnull__(1, 2, 3)));
extern int pthread_cond_clockwait(pthread_cond_t *__restrict __cond,
                                  pthread_mutex_t *__restrict __mutex, __clockid_t __clock_id,
                                  const struct timespec *__restrict __abstime)
    __attribute__((__nonnull__(1, 2, 4)));
extern int pthread_condattr_init(pthread_condattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_condattr_destroy(pthread_condattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_condattr_getpshared(const pthread_condattr_t *__restrict __attr,
                                       int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_condattr_setpshared(pthread_condattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_condattr_getclock(const pthread_condattr_t *__restrict __attr,
                                     __clockid_t *__restrict __clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_condattr_setclock(pthread_condattr_t *__attr, __clockid_t __clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_init(pthread_spinlock_t *__lock, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_destroy(pthread_spinlock_t *__lock) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_spin_lock(pthread_spinlock_t *__lock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_spin_trylock(pthread_spinlock_t *__lock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_spin_unlock(pthread_spinlock_t *__lock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_barrier_init(pthread_barrier_t *__restrict __barrier,
                                const pthread_barrierattr_t *__restrict __attr,
                                unsigned int __count) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_barrier_destroy(pthread_barrier_t *__barrier)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrier_wait(pthread_barrier_t *__barrier) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_barrierattr_init(pthread_barrierattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrierattr_destroy(pthread_barrierattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrierattr_getpshared(const pthread_barrierattr_t *__restrict __attr,
                                          int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_barrierattr_setpshared(pthread_barrierattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_key_create(pthread_key_t *__key, void (*__destr_function)(void *))
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_key_delete(pthread_key_t __key) __attribute__((__nothrow__, __leaf__));
extern void *pthread_getspecific(pthread_key_t __key) __attribute__((__nothrow__, __leaf__));
extern int pthread_setspecific(pthread_key_t __key, const void *__pointer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__access__(__none__, 2)));
extern int pthread_getcpuclockid(pthread_t __thread_id, __clockid_t *__clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_atfork(void (*__prepare)(void), void (*__parent)(void), void (*__child)(void))
    __attribute__((__nothrow__, __leaf__));
typedef pthread_mutex_t mtx_t;
int mtx_init(mtx_t *mtx, int type);
void mtx_destroy(mtx_t *mtx);
int mtx_lock(mtx_t *mtx);
int mtx_timedlock(mtx_t *mtx, const struct timespec *ts);
int mtx_trylock(mtx_t *mtx);
int mtx_unlock(mtx_t *mtx);
typedef pthread_cond_t cnd_t;
int cnd_init(cnd_t *cond);
void cnd_destroy(cnd_t *cond);
int cnd_signal(cnd_t *cond);
int cnd_broadcast(cnd_t *cond);
int cnd_wait(cnd_t *cond, mtx_t *mtx);
int cnd_timedwait(cnd_t *cond, mtx_t *mtx, const struct timespec *ts);
typedef pthread_t thrd_t;
typedef int (*thrd_start_t)(void *arg);
int thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
thrd_t thrd_current(void);
int thrd_detach(thrd_t thr);
int thrd_equal(thrd_t thr0, thrd_t thr1);
_Noreturn void thrd_exit(int res);
int thrd_join(thrd_t thr, int *res);
int thrd_sleep(const struct timespec *duration, struct timespec *remaining);
void thrd_yield(void);
typedef pthread_key_t tss_t;
typedef void (*tss_dtor_t)(void *val);
int tss_create(tss_t *key, tss_dtor_t dtor);
void tss_delete(tss_t key);
void *tss_get(tss_t key);
int tss_set(tss_t key, void *val);
typedef int wchar_t;
typedef struct {
    int quot;
    int rem;
} div_t;
typedef struct {
    long int quot;
    long int rem;
} ldiv_t;
__extension__ typedef struct {
    long long int quot;
    long long int rem;
} lldiv_t;
extern size_t __ctype_get_mb_cur_max(void) __attribute__((__nothrow__, __leaf__));
extern double atof(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern int atoi(const char *__nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
extern long int atol(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
__extension__ extern long long int atoll(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern double strtod(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern float strtof(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long double strtold(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float32 strtof32(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float64 strtof64(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float128 strtof128(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float32x strtof32x(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float64x strtof64x(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int strtol(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern unsigned long int strtoul(const char *__restrict __nptr, char **__restrict __endptr,
                                 int __base) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
__extension__ extern long long int strtoq(const char *__restrict __nptr, char **__restrict __endptr,
                                          int __base) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
__extension__ extern unsigned long long int strtouq(const char *__restrict __nptr,
                                                    char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern long long int strtoll(const char *__restrict __nptr,
                                           char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern unsigned long long int strtoull(const char *__restrict __nptr,
                                                     char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int strtol(const char *__restrict __nptr, char **__restrict __endptr,
                       int __base) __asm__(""
                                           "__isoc23_strtol") __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern unsigned long int strtoul(const char *__restrict __nptr, char **__restrict __endptr,
                                 int __base) __asm__(""
                                                     "__isoc23_strtoul")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern long long int strtoq(const char *__restrict __nptr, char **__restrict __endptr,
                                          int __base) __asm__(""
                                                              "__isoc23_strtoll")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern unsigned long long int strtouq(const char *__restrict __nptr,
                                                    char **__restrict __endptr,
                                                    int __base) __asm__(""
                                                                        "__isoc23_strtoull")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern long long int strtoll(const char *__restrict __nptr,
                                           char **__restrict __endptr,
                                           int __base) __asm__(""
                                                               "__isoc23_strtoll")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern unsigned long long int strtoull(const char *__restrict __nptr,
                                                     char **__restrict __endptr,
                                                     int __base) __asm__(""
                                                                         "__isoc23_strtoull")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int strfromd(char *__dest, size_t __size, const char *__format, double __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf(char *__dest, size_t __size, const char *__format, float __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfroml(char *__dest, size_t __size, const char *__format, long double __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf32(char *__dest, size_t __size, const char *__format, _Float32 __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf64(char *__dest, size_t __size, const char *__format, _Float64 __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf128(char *__dest, size_t __size, const char *__format, _Float128 __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf32x(char *__dest, size_t __size, const char *__format, _Float32x __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf64x(char *__dest, size_t __size, const char *__format, _Float64x __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern long int strtol_l(const char *__restrict __nptr, char **__restrict __endptr, int __base,
                         locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 4)));
extern unsigned long int strtoul_l(const char *__restrict __nptr, char **__restrict __endptr,
                                   int __base, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
__extension__ extern long long int strtoll_l(const char *__restrict __nptr,
                                             char **__restrict __endptr, int __base, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
__extension__ extern unsigned long long int
strtoull_l(const char *__restrict __nptr, char **__restrict __endptr, int __base, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
extern long int strtol_l(const char *__restrict __nptr, char **__restrict __endptr, int __base,
                         locale_t __loc) __asm__(""
                                                 "__isoc23_strtol_l")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
extern unsigned long int strtoul_l(const char *__restrict __nptr, char **__restrict __endptr,
                                   int __base, locale_t __loc) __asm__(""
                                                                       "__isoc23_strtoul_l")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
__extension__ extern long long int strtoll_l(const char *__restrict __nptr,
                                             char **__restrict __endptr, int __base,
                                             locale_t __loc) __asm__(""
                                                                     "__isoc23_strtoll_l")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
__extension__ extern unsigned long long int
strtoull_l(const char *__restrict __nptr, char **__restrict __endptr, int __base,
           locale_t __loc) __asm__(""
                                   "__isoc23_strtoull_l") __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 4)));
extern double strtod_l(const char *__restrict __nptr, char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern float strtof_l(const char *__restrict __nptr, char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern long double strtold_l(const char *__restrict __nptr, char **__restrict __endptr,
                             locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern _Float32 strtof32_l(const char *__restrict __nptr, char **__restrict __endptr,
                           locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern _Float64 strtof64_l(const char *__restrict __nptr, char **__restrict __endptr,
                           locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern _Float128 strtof128_l(const char *__restrict __nptr, char **__restrict __endptr,
                             locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern _Float32x strtof32x_l(const char *__restrict __nptr, char **__restrict __endptr,
                             locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern _Float64x strtof64x_l(const char *__restrict __nptr, char **__restrict __endptr,
                             locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern char *l64a(long int __n) __attribute__((__nothrow__, __leaf__));
extern long int a64l(const char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __ino64_t ino64_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __off64_t off64_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __useconds_t useconds_t;
typedef __suseconds_t suseconds_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t __attribute__((__mode__(__word__)));
static __inline __uint16_t __bswap_16(__uint16_t __bsx) { return __builtin_bswap16(__bsx); }
static __inline __uint32_t __bswap_32(__uint32_t __bsx) { return __builtin_bswap32(__bsx); }
__extension__ static __inline __uint64_t __bswap_64(__uint64_t __bsx) {
    return __builtin_bswap64(__bsx);
}
static __inline __uint16_t __uint16_identity(__uint16_t __x) { return __x; }
static __inline __uint32_t __uint32_identity(__uint32_t __x) { return __x; }
static __inline __uint64_t __uint64_identity(__uint64_t __x) { return __x; }
typedef __sigset_t sigset_t;
typedef long int __fd_mask;
typedef struct {
    __fd_mask fds_bits[1024 / (8 * (int)sizeof(__fd_mask))];
} fd_set;
typedef __fd_mask fd_mask;
extern int select(int __nfds, fd_set *__restrict __readfds, fd_set *__restrict __writefds,
                  fd_set *__restrict __exceptfds, struct timeval *__restrict __timeout);
extern int pselect(int __nfds, fd_set *__restrict __readfds, fd_set *__restrict __writefds,
                   fd_set *__restrict __exceptfds, const struct timespec *__restrict __timeout,
                   const __sigset_t *__restrict __sigmask);
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
extern long int random(void) __attribute__((__nothrow__, __leaf__));
extern void srandom(unsigned int __seed) __attribute__((__nothrow__, __leaf__));
extern char *initstate(unsigned int __seed, char *__statebuf, size_t __statelen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern char *setstate(char *__statebuf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
struct random_data {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
};
extern int random_r(struct random_data *__restrict __buf, int32_t *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int srandom_r(unsigned int __seed, struct random_data *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int initstate_r(unsigned int __seed, char *__restrict __statebuf, size_t __statelen,
                       struct random_data *__restrict __buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 4)));
extern int setstate_r(char *__restrict __statebuf, struct random_data *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int rand(void) __attribute__((__nothrow__, __leaf__));
extern void srand(unsigned int __seed) __attribute__((__nothrow__, __leaf__));
extern int rand_r(unsigned int *__seed) __attribute__((__nothrow__, __leaf__));
extern double drand48(void) __attribute__((__nothrow__, __leaf__));
extern double erand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern long int lrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int nrand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern long int mrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int jrand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern void srand48(long int __seedval) __attribute__((__nothrow__, __leaf__));
extern unsigned short int *seed48(unsigned short int __seed16v[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void lcong48(unsigned short int __param[7]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
struct drand48_data {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
};
extern int drand48_r(struct drand48_data *__restrict __buffer, double *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int erand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer,
                     double *__restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int lrand48_r(struct drand48_data *__restrict __buffer, long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int nrand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer,
                     long int *__restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int mrand48_r(struct drand48_data *__restrict __buffer, long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int jrand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer,
                     long int *__restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int srand48_r(long int __seedval, struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int seed48_r(unsigned short int __seed16v[3], struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int lcong48_r(unsigned short int __param[7], struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern __uint32_t arc4random(void) __attribute__((__nothrow__, __leaf__));
extern void arc4random_buf(void *__buf, size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern __uint32_t arc4random_uniform(__uint32_t __upper_bound)
    __attribute__((__nothrow__, __leaf__));
extern void *malloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)));
extern void *calloc(size_t __nmemb, size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1, 2)));
extern void *realloc(void *__ptr, size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2)));
extern void free(void *__ptr) __attribute__((__nothrow__, __leaf__));
extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__warn_unused_result__))
    __attribute__((__alloc_size__(2, 3))) __attribute__((__malloc__(__builtin_free, 1)));
extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__(reallocarray, 1)));
extern void *alloca(size_t __size) __attribute__((__nothrow__, __leaf__));
extern void *valloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)));
extern int posix_memalign(void **__memptr, size_t __alignment, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void *aligned_alloc(size_t __alignment, size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_align__(1))) __attribute__((__alloc_size__(2)));
extern void abort(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern int atexit(void (*__func)(void)) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int at_quick_exit(void (*__func)(void)) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int on_exit(void (*__func)(int __status, void *__arg), void *__arg)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void exit(int __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void quick_exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
extern void _Exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
extern char *getenv(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern char *secure_getenv(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int putenv(char *__string) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int setenv(const char *__name, const char *__value, int __replace)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int unsetenv(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int clearenv(void) __attribute__((__nothrow__, __leaf__));
extern char *mktemp(char *__template) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int mkstemp(char *__template) __attribute__((__nonnull__(1)));
extern int mkstemp64(char *__template) __attribute__((__nonnull__(1)));
extern int mkstemps(char *__template, int __suffixlen) __attribute__((__nonnull__(1)));
extern int mkstemps64(char *__template, int __suffixlen) __attribute__((__nonnull__(1)));
extern char *mkdtemp(char *__template) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int mkostemp(char *__template, int __flags) __attribute__((__nonnull__(1)));
extern int mkostemp64(char *__template, int __flags) __attribute__((__nonnull__(1)));
extern int mkostemps(char *__template, int __suffixlen, int __flags)
    __attribute__((__nonnull__(1)));
extern int mkostemps64(char *__template, int __suffixlen, int __flags)
    __attribute__((__nonnull__(1)));
extern int system(const char *__command);
extern char *canonicalize_file_name(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__malloc__))
__attribute__((__malloc__(__builtin_free, 1)));
extern char *realpath(const char *__restrict __name, char *__restrict __resolved)
    __attribute__((__nothrow__, __leaf__));
typedef int (*__compar_fn_t)(const void *, const void *);
typedef __compar_fn_t comparison_fn_t;
typedef int (*__compar_d_fn_t)(const void *, const void *, void *);
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb, size_t __size,
                     __compar_fn_t __compar) __attribute__((__nonnull__(1, 2, 5)));
extern void qsort(void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar)
    __attribute__((__nonnull__(1, 4)));
extern void qsort_r(void *__base, size_t __nmemb, size_t __size, __compar_d_fn_t __compar,
                    void *__arg) __attribute__((__nonnull__(1, 4)));
extern int abs(int __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern long int labs(long int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
__extension__ extern long long int llabs(long long int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern div_t div(int __numer, int __denom) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern ldiv_t ldiv(long int __numer, long int __denom) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
__extension__ extern lldiv_t lldiv(long long int __numer, long long int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern char *ecvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *fcvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *gcvt(double __value, int __ndigit, char *__buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));
extern char *qecvt(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4)));
extern char *qfcvt(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4)));
extern char *qgcvt(long double __value, int __ndigit, char *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int ecvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign,
                  char *__restrict __buf, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));
extern int fcvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign,
                  char *__restrict __buf, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));
extern int qecvt_r(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4, 5)));
extern int qfcvt_r(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4, 5)));
extern int mblen(const char *__s, size_t __n) __attribute__((__nothrow__, __leaf__));
extern int mbtowc(wchar_t *__restrict __pwc, const char *__restrict __s, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern int wctomb(char *__s, wchar_t __wchar) __attribute__((__nothrow__, __leaf__));
extern size_t mbstowcs(wchar_t *__restrict __pwcs, const char *__restrict __s, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__access__(__read_only__, 2)));
extern size_t wcstombs(char *__restrict __s, const wchar_t *__restrict __pwcs, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__access__(__write_only__, 1, 3)))
    __attribute__((__access__(__read_only__, 2)));
extern int rpmatch(const char *__response) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int getsubopt(char **__restrict __optionp, char *const *__restrict __tokens,
                     char **__restrict __valuep) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2, 3)));
extern int posix_openpt(int __oflag);
extern int grantpt(int __fd) __attribute__((__nothrow__, __leaf__));
extern int unlockpt(int __fd) __attribute__((__nothrow__, __leaf__));
extern char *ptsname(int __fd) __attribute__((__nothrow__, __leaf__));
extern int ptsname_r(int __fd, char *__buf, size_t __buflen) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2))) __attribute__((__access__(__write_only__, 2, 3)));
extern int getpt(void);
extern int getloadavg(double __loadavg[], int __nelem) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
typedef __sig_atomic_t sig_atomic_t;
union sigval {
    int sival_int;
    void *sival_ptr;
};
typedef union sigval __sigval_t;
typedef struct {
    int si_signo;
    int si_errno;
    int si_code;
    int __pad0;
    union {
        int _pad[((128 / sizeof(int)) - 4)];
        struct {
            __pid_t si_pid;
            __uid_t si_uid;
        } _kill;
        struct {
            int si_tid;
            int si_overrun;
            __sigval_t si_sigval;
        } _timer;
        struct {
            __pid_t si_pid;
            __uid_t si_uid;
            __sigval_t si_sigval;
        } _rt;
        struct {
            __pid_t si_pid;
            __uid_t si_uid;
            int si_status;
            __clock_t si_utime;
            __clock_t si_stime;
        } _sigchld;
        struct {
            void *si_addr;
            short int si_addr_lsb;
            union {
                struct {
                    void *_lower;
                    void *_upper;
                } _addr_bnd;
                __uint32_t _pkey;
            } _bounds;
        } _sigfault;
        struct {
            long int si_band;
            int si_fd;
        } _sigpoll;
        struct {
            void *_call_addr;
            int _syscall;
            unsigned int _arch;
        } _sigsys;
    } _sifields;
} siginfo_t;
enum {
    SI_ASYNCNL = -60,
    SI_DETHREAD = -7,
    SI_TKILL,
    SI_SIGIO,
    SI_ASYNCIO,
    SI_MESGQ,
    SI_TIMER,
    SI_QUEUE,
    SI_USER,
    SI_KERNEL = 0x80
};
enum {
    ILL_ILLOPC = 1,
    ILL_ILLOPN,
    ILL_ILLADR,
    ILL_ILLTRP,
    ILL_PRVOPC,
    ILL_PRVREG,
    ILL_COPROC,
    ILL_BADSTK,
    ILL_BADIADDR
};
enum {
    FPE_INTDIV = 1,
    FPE_INTOVF,
    FPE_FLTDIV,
    FPE_FLTOVF,
    FPE_FLTUND,
    FPE_FLTRES,
    FPE_FLTINV,
    FPE_FLTSUB,
    FPE_FLTUNK = 14,
    FPE_CONDTRAP
};
enum {
    SEGV_MAPERR = 1,
    SEGV_ACCERR,
    SEGV_BNDERR,
    SEGV_PKUERR,
    SEGV_ACCADI,
    SEGV_ADIDERR,
    SEGV_ADIPERR,
    SEGV_MTEAERR,
    SEGV_MTESERR,
    SEGV_CPERR
};
enum { BUS_ADRALN = 1, BUS_ADRERR, BUS_OBJERR, BUS_MCEERR_AR, BUS_MCEERR_AO };
enum { TRAP_BRKPT = 1, TRAP_TRACE, TRAP_BRANCH, TRAP_HWBKPT, TRAP_UNK };
enum { CLD_EXITED = 1, CLD_KILLED, CLD_DUMPED, CLD_TRAPPED, CLD_STOPPED, CLD_CONTINUED };
enum { POLL_IN = 1, POLL_OUT, POLL_MSG, POLL_ERR, POLL_PRI, POLL_HUP };
typedef __sigval_t sigval_t;
typedef struct sigevent {
    __sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    union {
        int _pad[((64 / sizeof(int)) - 4)];
        __pid_t _tid;
        struct {
            void (*_function)(__sigval_t);
            pthread_attr_t *_attribute;
        } _sigev_thread;
    } _sigev_un;
} sigevent_t;
enum { SIGEV_SIGNAL = 0, SIGEV_NONE, SIGEV_THREAD, SIGEV_THREAD_ID = 4 };
typedef void (*__sighandler_t)(int);
extern __sighandler_t __sysv_signal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__, __leaf__));
extern __sighandler_t sysv_signal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__, __leaf__));
extern __sighandler_t signal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__, __leaf__));
extern int kill(__pid_t __pid, int __sig) __attribute__((__nothrow__, __leaf__));
extern int killpg(__pid_t __pgrp, int __sig) __attribute__((__nothrow__, __leaf__));
extern int raise(int __sig) __attribute__((__nothrow__, __leaf__));
extern __sighandler_t ssignal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__, __leaf__));
extern int gsignal(int __sig) __attribute__((__nothrow__, __leaf__));
extern void psignal(int __sig, const char *__s);
extern void psiginfo(const siginfo_t *__pinfo, const char *__s);
extern int sigpause(int __sig) __asm__("__xpg_sigpause")
    __attribute__((__deprecated__("Use the sigsuspend function instead")));
extern int sigblock(int __mask) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__));
extern int sigsetmask(int __mask) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__));
extern int siggetmask(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
typedef __sighandler_t sighandler_t;
typedef __sighandler_t sig_t;
extern int sigemptyset(sigset_t *__set) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int sigfillset(sigset_t *__set) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int sigaddset(sigset_t *__set, int __signo) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int sigdelset(sigset_t *__set, int __signo) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int sigismember(const sigset_t *__set, int __signo) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int sigisemptyset(const sigset_t *__set) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int sigandset(sigset_t *__set, const sigset_t *__left, const sigset_t *__right)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2, 3)));
extern int sigorset(sigset_t *__set, const sigset_t *__left, const sigset_t *__right)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2, 3)));
struct sigaction {
    union {
        __sighandler_t sa_handler;
        void (*sa_sigaction)(int, siginfo_t *, void *);
    } __sigaction_handler;
    __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
};
extern int sigprocmask(int __how, const sigset_t *__restrict __set, sigset_t *__restrict __oset)
    __attribute__((__nothrow__, __leaf__));
extern int sigsuspend(const sigset_t *__set) __attribute__((__nonnull__(1)));
extern int sigaction(int __sig, const struct sigaction *__restrict __act,
                     struct sigaction *__restrict __oact) __attribute__((__nothrow__, __leaf__));
extern int sigpending(sigset_t *__set) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int sigwait(const sigset_t *__restrict __set, int *__restrict __sig)
    __attribute__((__nonnull__(1, 2)));
extern int sigwaitinfo(const sigset_t *__restrict __set, siginfo_t *__restrict __info)
    __attribute__((__nonnull__(1)));
extern int sigtimedwait(const sigset_t *__restrict __set, siginfo_t *__restrict __info,
                        const struct timespec *__restrict __timeout)
    __attribute__((__nonnull__(1)));
extern int sigqueue(__pid_t __pid, int __sig, const union sigval __val)
    __attribute__((__nothrow__, __leaf__));
struct _fpx_sw_bytes {
    __uint32_t magic1;
    __uint32_t extended_size;
    __uint64_t xstate_bv;
    __uint32_t xstate_size;
    __uint32_t __glibc_reserved1[7];
};
struct _fpreg {
    unsigned short significand[4];
    unsigned short exponent;
};
struct _fpxreg {
    unsigned short significand[4];
    unsigned short exponent;
    unsigned short __glibc_reserved1[3];
};
struct _xmmreg {
    __uint32_t element[4];
};
struct _fpstate {
    __uint16_t cwd;
    __uint16_t swd;
    __uint16_t ftw;
    __uint16_t fop;
    __uint64_t rip;
    __uint64_t rdp;
    __uint32_t mxcsr;
    __uint32_t mxcr_mask;
    struct _fpxreg _st[8];
    struct _xmmreg _xmm[16];
    __uint32_t __glibc_reserved1[24];
};
struct sigcontext {
    __uint64_t r8;
    __uint64_t r9;
    __uint64_t r10;
    __uint64_t r11;
    __uint64_t r12;
    __uint64_t r13;
    __uint64_t r14;
    __uint64_t r15;
    __uint64_t rdi;
    __uint64_t rsi;
    __uint64_t rbp;
    __uint64_t rbx;
    __uint64_t rdx;
    __uint64_t rax;
    __uint64_t rcx;
    __uint64_t rsp;
    __uint64_t rip;
    __uint64_t eflags;
    unsigned short cs;
    unsigned short gs;
    unsigned short fs;
    unsigned short __pad0;
    __uint64_t err;
    __uint64_t trapno;
    __uint64_t oldmask;
    __uint64_t cr2;
    __extension__ union {
        struct _fpstate *fpstate;
        __uint64_t __fpstate_word;
    };
    __uint64_t __reserved1[8];
};
struct _xsave_hdr {
    __uint64_t xstate_bv;
    __uint64_t __glibc_reserved1[2];
    __uint64_t __glibc_reserved2[5];
};
struct _ymmh_state {
    __uint32_t ymmh_space[64];
};
struct _xstate {
    struct _fpstate fpstate;
    struct _xsave_hdr xstate_hdr;
    struct _ymmh_state ymmh;
};
extern int sigreturn(struct sigcontext *__scp) __attribute__((__nothrow__, __leaf__));
typedef struct {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
} stack_t;
__extension__ typedef long long int greg_t;
typedef greg_t gregset_t[23];
enum {
    REG_R8 = 0,
    REG_R9,
    REG_R10,
    REG_R11,
    REG_R12,
    REG_R13,
    REG_R14,
    REG_R15,
    REG_RDI,
    REG_RSI,
    REG_RBP,
    REG_RBX,
    REG_RDX,
    REG_RAX,
    REG_RCX,
    REG_RSP,
    REG_RIP,
    REG_EFL,
    REG_CSGSFS,
    REG_ERR,
    REG_TRAPNO,
    REG_OLDMASK,
    REG_CR2
};
struct _libc_fpxreg {
    unsigned short int significand[4];
    unsigned short int exponent;
    unsigned short int __glibc_reserved1[3];
};
struct _libc_xmmreg {
    __uint32_t element[4];
};
struct _libc_fpstate {
    __uint16_t cwd;
    __uint16_t swd;
    __uint16_t ftw;
    __uint16_t fop;
    __uint64_t rip;
    __uint64_t rdp;
    __uint32_t mxcsr;
    __uint32_t mxcr_mask;
    struct _libc_fpxreg _st[8];
    struct _libc_xmmreg _xmm[16];
    __uint32_t __glibc_reserved1[24];
};
typedef struct _libc_fpstate *fpregset_t;
typedef struct {
    gregset_t gregs;
    fpregset_t fpregs;
    __extension__ unsigned long long __reserved1[8];
} mcontext_t;
typedef struct ucontext_t {
    unsigned long int uc_flags;
    struct ucontext_t *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
    __extension__ unsigned long long int __ssp[4];
} ucontext_t;
extern int siginterrupt(int __sig, int __interrupt) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("Use sigaction with SA_RESTART instead")));
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access(const char *__name, int __type) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int euidaccess(const char *__name, int __type) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int eaccess(const char *__name, int __type) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int execveat(int __fd, const char *__path, char *const __argv[], char *const __envp[],
                    int __flags) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 3)));
extern int faccessat(int __fd, const char *__file, int __type, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern __off_t lseek(int __fd, __off_t __offset, int __whence)
    __attribute__((__nothrow__, __leaf__));
extern __off64_t lseek64(int __fd, __off64_t __offset, int __whence)
    __attribute__((__nothrow__, __leaf__));
extern int close(int __fd);
extern void closefrom(int __lowfd) __attribute__((__nothrow__, __leaf__));
extern ssize_t read(int __fd, void *__buf, size_t __nbytes)
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t write(int __fd, const void *__buf, size_t __n)
    __attribute__((__access__(__read_only__, 2, 3)));
extern ssize_t pread(int __fd, void *__buf, size_t __nbytes, __off_t __offset)
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t pwrite(int __fd, const void *__buf, size_t __n, __off_t __offset)
    __attribute__((__access__(__read_only__, 2, 3)));
extern ssize_t pread64(int __fd, void *__buf, size_t __nbytes, __off64_t __offset)
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t pwrite64(int __fd, const void *__buf, size_t __n, __off64_t __offset)
    __attribute__((__access__(__read_only__, 2, 3)));
extern int pipe(int __pipedes[2]) __attribute__((__nothrow__, __leaf__));
extern int pipe2(int __pipedes[2], int __flags) __attribute__((__nothrow__, __leaf__));
extern unsigned int alarm(unsigned int __seconds) __attribute__((__nothrow__, __leaf__));
extern unsigned int sleep(unsigned int __seconds);
extern __useconds_t ualarm(__useconds_t __value, __useconds_t __interval)
    __attribute__((__nothrow__, __leaf__));
extern int usleep(__useconds_t __useconds);
extern int pause(void);
extern int chown(const char *__file, __uid_t __owner, __gid_t __group)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int fchown(int __fd, __uid_t __owner, __gid_t __group)
    __attribute__((__nothrow__, __leaf__));
extern int lchown(const char *__file, __uid_t __owner, __gid_t __group)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int fchownat(int __fd, const char *__file, __uid_t __owner, __gid_t __group, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int chdir(const char *__path) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int fchdir(int __fd) __attribute__((__nothrow__, __leaf__));
extern char *getcwd(char *__buf, size_t __size) __attribute__((__nothrow__, __leaf__));
extern char *get_current_dir_name(void) __attribute__((__nothrow__, __leaf__));
extern char *getwd(char *__buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__deprecated__))
__attribute__((__access__(__write_only__, 1)));
extern int dup(int __fd) __attribute__((__nothrow__, __leaf__));
extern int dup2(int __fd, int __fd2) __attribute__((__nothrow__, __leaf__));
extern int dup3(int __fd, int __fd2, int __flags) __attribute__((__nothrow__, __leaf__));
extern char **__environ;
extern char **environ;
extern int execve(const char *__path, char *const __argv[], char *const __envp[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int fexecve(int __fd, char *const __argv[], char *const __envp[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int execv(const char *__path, char *const __argv[]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int execle(const char *__path, const char *__arg, ...) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int execl(const char *__path, const char *__arg, ...) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int execvp(const char *__file, char *const __argv[]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int execlp(const char *__file, const char *__arg, ...) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int execvpe(const char *__file, char *const __argv[], char *const __envp[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int nice(int __inc) __attribute__((__nothrow__, __leaf__));
extern void _exit(int __status) __attribute__((__noreturn__));
enum {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
};
enum {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT,
    _SC_MINSIGSTKSZ,
    _SC_SIGSTKSZ
};
enum {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
    _CS_V6_ENV,
    _CS_V7_ENV
};
extern long int pathconf(const char *__path, int __name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern long int fpathconf(int __fd, int __name) __attribute__((__nothrow__, __leaf__));
extern long int sysconf(int __name) __attribute__((__nothrow__, __leaf__));
extern size_t confstr(int __name, char *__buf, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__write_only__, 2, 3)));
extern __pid_t getpid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getppid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getpgrp(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t __getpgid(__pid_t __pid) __attribute__((__nothrow__, __leaf__));
extern __pid_t getpgid(__pid_t __pid) __attribute__((__nothrow__, __leaf__));
extern int setpgid(__pid_t __pid, __pid_t __pgid) __attribute__((__nothrow__, __leaf__));
extern int setpgrp(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t setsid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getsid(__pid_t __pid) __attribute__((__nothrow__, __leaf__));
extern __uid_t getuid(void) __attribute__((__nothrow__, __leaf__));
extern __uid_t geteuid(void) __attribute__((__nothrow__, __leaf__));
extern __gid_t getgid(void) __attribute__((__nothrow__, __leaf__));
extern __gid_t getegid(void) __attribute__((__nothrow__, __leaf__));
extern int getgroups(int __size, __gid_t __list[]) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__write_only__, 2, 1)));
extern int group_member(__gid_t __gid) __attribute__((__nothrow__, __leaf__));
extern int setuid(__uid_t __uid) __attribute__((__nothrow__, __leaf__));
extern int setreuid(__uid_t __ruid, __uid_t __euid) __attribute__((__nothrow__, __leaf__));
extern int seteuid(__uid_t __uid) __attribute__((__nothrow__, __leaf__));
extern int setgid(__gid_t __gid) __attribute__((__nothrow__, __leaf__));
extern int setregid(__gid_t __rgid, __gid_t __egid) __attribute__((__nothrow__, __leaf__));
extern int setegid(__gid_t __gid) __attribute__((__nothrow__, __leaf__));
extern int getresuid(__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
    __attribute__((__nothrow__, __leaf__));
extern int getresgid(__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
    __attribute__((__nothrow__, __leaf__));
extern int setresuid(__uid_t __ruid, __uid_t __euid, __uid_t __suid)
    __attribute__((__nothrow__, __leaf__));
extern int setresgid(__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
    __attribute__((__nothrow__, __leaf__));
extern __pid_t fork(void) __attribute__((__nothrow__));
extern __pid_t vfork(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t _Fork(void) __attribute__((__nothrow__, __leaf__));
extern char *ttyname(int __fd) __attribute__((__nothrow__, __leaf__));
extern int ttyname_r(int __fd, char *__buf, size_t __buflen) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2))) __attribute__((__access__(__write_only__, 2, 3)));
extern int isatty(int __fd) __attribute__((__nothrow__, __leaf__));
extern int ttyslot(void) __attribute__((__nothrow__, __leaf__));
extern int link(const char *__from, const char *__to) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int linkat(int __fromfd, const char *__from, int __tofd, const char *__to, int __flags)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));
extern int symlink(const char *__from, const char *__to) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern ssize_t readlink(const char *__restrict __path, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__access__(__write_only__, 2, 3)));
extern int symlinkat(const char *__from, int __tofd, const char *__to)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern ssize_t readlinkat(int __fd, const char *__restrict __path, char *__restrict __buf,
                          size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 3))) __attribute__((__access__(__write_only__, 3, 4)));
extern int unlink(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int unlinkat(int __fd, const char *__name, int __flag) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int rmdir(const char *__path) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern __pid_t tcgetpgrp(int __fd) __attribute__((__nothrow__, __leaf__));
extern int tcsetpgrp(int __fd, __pid_t __pgrp_id) __attribute__((__nothrow__, __leaf__));
extern char *getlogin(void);
extern int getlogin_r(char *__name, size_t __name_len) __attribute__((__nonnull__(1)))
__attribute__((__access__(__write_only__, 1, 2)));
extern int setlogin(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt(int ___argc, char *const *___argv, const char *__shortopts)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int gethostname(char *__name, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__access__(__write_only__, 1, 2)));
extern int sethostname(const char *__name, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__access__(__read_only__, 1, 2)));
extern int sethostid(long int __id) __attribute__((__nothrow__, __leaf__));
extern int getdomainname(char *__name, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__access__(__write_only__, 1, 2)));
extern int setdomainname(const char *__name, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__access__(__read_only__, 1, 2)));
extern int vhangup(void) __attribute__((__nothrow__, __leaf__));
extern int revoke(const char *__file) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int profil(unsigned short int *__sample_buffer, size_t __size, size_t __offset,
                  unsigned int __scale) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int acct(const char *__name) __attribute__((__nothrow__, __leaf__));
extern char *getusershell(void) __attribute__((__nothrow__, __leaf__));
extern void endusershell(void) __attribute__((__nothrow__, __leaf__));
extern void setusershell(void) __attribute__((__nothrow__, __leaf__));
extern int daemon(int __nochdir, int __noclose) __attribute__((__nothrow__, __leaf__));
extern int chroot(const char *__path) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern char *getpass(const char *__prompt) __attribute__((__nonnull__(1)));
extern int fsync(int __fd);
extern int syncfs(int __fd) __attribute__((__nothrow__, __leaf__));
extern long int gethostid(void);
extern void sync(void) __attribute__((__nothrow__, __leaf__));
extern int getpagesize(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int getdtablesize(void) __attribute__((__nothrow__, __leaf__));
extern int truncate(const char *__file, __off_t __length) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int truncate64(const char *__file, __off64_t __length) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int ftruncate(int __fd, __off_t __length) __attribute__((__nothrow__, __leaf__));
extern int ftruncate64(int __fd, __off64_t __length) __attribute__((__nothrow__, __leaf__));
extern int brk(void *__addr) __attribute__((__nothrow__, __leaf__));
extern void *sbrk(intptr_t __delta) __attribute__((__nothrow__, __leaf__));
extern long int syscall(long int __sysno, ...) __attribute__((__nothrow__, __leaf__));
extern int lockf(int __fd, int __cmd, __off_t __len);
extern int lockf64(int __fd, int __cmd, __off64_t __len);
ssize_t copy_file_range(int __infd, __off64_t *__pinoff, int __outfd, __off64_t *__poutoff,
                        size_t __length, unsigned int __flags);
extern int fdatasync(int __fildes);
extern char *crypt(const char *__key, const char *__salt) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern void swab(const void *__restrict __from, void *__restrict __to, ssize_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__access__(__read_only__, 1, 3)))
    __attribute__((__access__(__write_only__, 2, 3)));
int getentropy(void *__buffer, size_t __length) __attribute__((__access__(__write_only__, 1, 2)));
extern int close_range(unsigned int __fd, unsigned int __max_fd, int __flags)
    __attribute__((__nothrow__, __leaf__));
extern __pid_t gettid(void) __attribute__((__nothrow__, __leaf__));
enum { SS_ONSTACK = 1, SS_DISABLE };
extern int sigaltstack(const stack_t *__restrict __ss, stack_t *__restrict __oss)
    __attribute__((__nothrow__, __leaf__));
struct sigstack {
    void *ss_sp;
    int ss_onstack;
};
extern int sigstack(struct sigstack *__ss, struct sigstack *__oss)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
extern int sighold(int __sig) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("Use the sigprocmask function instead")));
extern int sigrelse(int __sig) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("Use the sigprocmask function instead")));
extern int sigignore(int __sig) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("Use the signal function instead")));
extern __sighandler_t sigset(int __sig, __sighandler_t __disp)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__deprecated__("Use the signal and sigprocmask functions instead")));
extern int pthread_sigmask(int __how, const __sigset_t *__restrict __newmask,
                           __sigset_t *__restrict __oldmask) __attribute__((__nothrow__, __leaf__));
extern int pthread_kill(pthread_t __threadid, int __signo) __attribute__((__nothrow__, __leaf__));
extern int pthread_sigqueue(pthread_t __threadid, int __signo, const union sigval __value)
    __attribute__((__nothrow__, __leaf__));
extern int __libc_current_sigrtmin(void) __attribute__((__nothrow__, __leaf__));
extern int __libc_current_sigrtmax(void) __attribute__((__nothrow__, __leaf__));
extern int tgkill(__pid_t __tgid, __pid_t __tid, int __signal);
struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};
extern int gettimeofday(struct timeval *__restrict __tv, void *__restrict __tz)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int settimeofday(const struct timeval *__tv, const struct timezone *__tz)
    __attribute__((__nothrow__, __leaf__));
extern int adjtime(const struct timeval *__delta, struct timeval *__olddelta)
    __attribute__((__nothrow__, __leaf__));
enum __itimer_which { ITIMER_REAL = 0, ITIMER_VIRTUAL = 1, ITIMER_PROF = 2 };
struct itimerval {
    struct timeval it_interval;
    struct timeval it_value;
};
typedef enum __itimer_which __itimer_which_t;
extern int getitimer(__itimer_which_t __which, struct itimerval *__value)
    __attribute__((__nothrow__, __leaf__));
extern int setitimer(__itimer_which_t __which, const struct itimerval *__restrict __new,
                     struct itimerval *__restrict __old) __attribute__((__nothrow__, __leaf__));
extern int utimes(const char *__file, const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int lutimes(const char *__file, const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int futimes(int __fd, const struct timeval __tvp[2]) __attribute__((__nothrow__, __leaf__));
extern int futimesat(int __fd, const char *__file, const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__));
extern int *__errno_location(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern char *program_invocation_name;
extern char *program_invocation_short_name;
typedef int error_t;
int mtx_init(mtx_t *mtx, int type) {
    int ret;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    if (type & 2) {
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    }
    ret = pthread_mutex_init(mtx, &attr);
    pthread_mutexattr_destroy(&attr);
    return ret == 0 ? 1 : 0;
}
void mtx_destroy(mtx_t *mtx) { pthread_mutex_destroy(mtx); }
int mtx_lock(mtx_t *mtx) { return pthread_mutex_lock(mtx) == 0 ? 1 : 0; }
int mtx_timedlock(mtx_t *mtx, const struct timespec *ts) {
    switch (pthread_mutex_timedlock(mtx, ts)) {
    case 0:
        return 1;
    case 110:
        return 2;
    default:
        return 0;
    }
}
int mtx_trylock(mtx_t *mtx) { return (pthread_mutex_trylock(mtx) == 0) ? 1 : 3; }
int mtx_unlock(mtx_t *mtx) {
    return pthread_mutex_unlock(mtx) == 0 ? 1 : 0;
    ;
}
int cnd_init(cnd_t *cond) { return pthread_cond_init(cond, ((void *)0)) == 0 ? 1 : 0; }
void cnd_destroy(cnd_t *cond) { pthread_cond_destroy(cond); }
int cnd_signal(cnd_t *cond) { return pthread_cond_signal(cond) == 0 ? 1 : 0; }
int cnd_broadcast(cnd_t *cond) { return pthread_cond_broadcast(cond) == 0 ? 1 : 0; }
int cnd_wait(cnd_t *cond, mtx_t *mtx) { return pthread_cond_wait(cond, mtx) == 0 ? 1 : 0; }
int cnd_timedwait(cnd_t *cond, mtx_t *mtx, const struct timespec *ts) {
    int ret;
    ret = pthread_cond_timedwait(cond, mtx, ts);
    if (ret == 110) {
        return 2;
    }
    return ret == 0 ? 1 : 0;
}
typedef struct {
    thrd_start_t mFunction;
    void *mArg;
} _thread_start_info;
static void *_thrd_wrapper_function(void *aArg) {
    thrd_start_t fun;
    void *arg;
    int res;
    _thread_start_info *ti = (_thread_start_info *)aArg;
    fun = ti->mFunction;
    arg = ti->mArg;
    free((void *)ti);
    res = fun(arg);
    return (void *)(intptr_t)res;
}
int thrd_create(thrd_t *thr, thrd_start_t func, void *arg) {
    _thread_start_info *ti = (_thread_start_info *)malloc(sizeof(_thread_start_info));
    if (ti == ((void *)0)) {
        return 4;
    }
    ti->mFunction = func;
    ti->mArg = arg;
    if (pthread_create(thr, ((void *)0), _thrd_wrapper_function, (void *)ti) != 0) {
        *thr = 0;
    }
    if (!*thr) {
        free(ti);
        return 0;
    }
    return 1;
}
thrd_t thrd_current(void) { return pthread_self(); }
int thrd_detach(thrd_t thr) { return pthread_detach(thr) == 0 ? 1 : 0; }
int thrd_equal(thrd_t thr0, thrd_t thr1) { return pthread_equal(thr0, thr1); }
void thrd_exit(int res) { pthread_exit((void *)(intptr_t)res); }
int thrd_join(thrd_t thr, int *res) {
    void *pres;
    if (pthread_join(thr, &pres) != 0) {
        return 0;
    }
    if (res != ((void *)0)) {
        *res = (int)(intptr_t)pres;
    }
    return 1;
}
int thrd_sleep(const struct timespec *duration, struct timespec *remaining) {
    int res = nanosleep(duration, remaining);
    if (res == 0) {
        return 0;
    } else if ((*__errno_location()) == 4) {
        return -1;
    } else {
        return -2;
    }
}
void thrd_yield(void) { sched_yield(); }
int tss_create(tss_t *key, tss_dtor_t dtor) {
    if (pthread_key_create(key, dtor) != 0) {
        return 0;
    }
    return 1;
}
void tss_delete(tss_t key) { pthread_key_delete(key); }
void *tss_get(tss_t key) { return pthread_getspecific(key); }
int tss_set(tss_t key, void *val) {
    if (pthread_setspecific(key, val) != 0) {
        return 0;
    }
    return 1;
}
#endif
#endif
