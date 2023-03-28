/*****************************************************************************
 * Filename      : minunit.h
 * Created       : Tue Mar 28 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Original by Jera Design and extended by Zed A. Shaw
 *****************************************************************************/

#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <dbg.h>
#include <stdio.h>
#include <stdlib.h>

#define mu_suite_start() char *message = NULL

#define mu_assert(test, message) \
  if (!(test)) {                 \
    log_err(message);            \
    return message;              \
  }

#define mu_run_test(test)      \
  debug("---->%s", " " #test); \
  message = test();            \
  tests_run++;                 \
  if (message) return message;

#define RUN_TESTS(name)                     \
  int main(int argc, char *argv[]) {        \
    argc = 1;                               \
    log_info("----- RUNNING: %s", argv[0]); \
    char *result = name();                  \
    if (result != 0) {                      \
      log_err("FAILED: %s", result);        \
    } else {                                \
      printf("\n");                         \
      log_info("ALL TESTS PASSED");         \
    }                                       \
    log_info("Tests run: %d", tests_run);   \
    exit(result != 0);                      \
  }

int tests_run = 0;

#endif