/*****************************************************************************
 * Filename      : dbg.h
 * Created       : Mon Mar 13 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Zed A. Shaws Awesome Debug Macros [modded]
 * For more information about colors and more see:
 * https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
 *****************************************************************************/

// Toggle Disable DEBUG messages
// FALSE = Show debug , TRUE = Hide debug
// #define NDEBUG = FALSE

// The usual defense against accidentally including the file twice.
#ifndef __dbg_h__
#define __dbg_h__

#include <errno.h>
#include <stdio.h>
#include <string.h>

// #define COLORS
#ifdef COLORS
#define C_RED "\x1b[31m"
#define C_BLUE "\x1b[34m"
#define C_CYAN "\x1b[36m"
#define C_GREEN_BOLD "\x1b[32;1m"
#define C_YELLOW "\x1b[93m"
#define C_MAGENTA "\x1b[35m"
#define C_RESET "\x1b[0m"
#else
#define C_RED ""
#define C_BLUE ""
#define C_CYAN ""
#define C_GREEN_BOLD ""
#define C_YELLOW ""
#define C_MAGENTA ""
#define C_RESET ""

#endif

// compile with the CPPFLAGS=-DNDEBUG to set/activate NO DEBUG = "FALSE"
// Using debug() in the code will not be printed unless the flag is removed.
// Example:
// $ make CPPFLAGS=-DNDEBUG ex19
#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...)                                                   \
  fprintf(stderr, C_MAGENTA "[DEBUG](%s:%d) " M "\n" C_RESET, __FILE__, \
          __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...)                                                        \
  fprintf(stderr, C_RED "[ERROR](%s:%d, errno: %s) " M "\n" C_RESET, __FILE__, \
          __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...)                                                \
  fprintf(stderr, C_YELLOW "[WARN] (%s:%d: errno: %s) " M "\n" C_RESET, \
          __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...)                                                       \
  fprintf(stderr, C_BLUE "[INFO] (%s:%d) " M "\n" C_RESET, __FILE__, __LINE__, \
          ##__VA_ARGS__)

#define log_info_green_bold(M, ...)                                        \
  fprintf(stderr, C_GREEN_BOLD "[INFO] (%s:%d) " M "\n" C_RESET, __FILE__, \
          __LINE__, ##__VA_ARGS__)

#define check(A, M, ...)       \
  if (!(A)) {                  \
    log_err(M, ##__VA_ARGS__); \
    errno = 0;                 \
    goto error;                \
  }

#define sentinel(M, ...)       \
  {                            \
    log_err(M, ##__VA_ARGS__); \
    errno = 0;                 \
    goto error;                \
  }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) \
  if (!(A)) {                  \
    debug(M, ##__VA_ARGS__);   \
    errno = 0;                 \
    goto error;                \
  }

#endif