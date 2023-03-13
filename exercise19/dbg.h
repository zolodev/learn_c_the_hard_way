/*****************************************************************************
 * Filename      : dbg.h
 * Created       : Mon Mar 13 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Zed A. Shaws Awesome Debug Macros
 *****************************************************************************/

// The usual defense against accidentally including the file twice.
#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

// compile with the CPPFLAGS=-DNDEBUG to set/activate NO DEBUG = "FALSE"
// Using debug() in the code will not be printed unless the flag is removed.
// Example:
// $ make CPPFLAGS=-DNDEBUG ex19
#ifdef NDEBUG
#define debug(M, ...)
#else #define debug(M, ...) fprint(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...)           \
    if (!(A))                      \
    {                              \
        log_err(M, ##__VA_ARGS__); \
        errno = 0;                 \
        goto error;                \
    }

#define sentinel(M, ...)           \
    {                              \
        log_err(M, ##__VA_ARGS__); \
        errno = 0;                 \
        goto error;                \
    }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...)   \
    if (!(A))                    \
    {                            \
        debug(M, ##__VA_ARGS__); \
        errno = 0;               \
        goto error;              \
    }

#endif