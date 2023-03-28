/*****************************************************************************
 * Filename      : libex29_tests.c
 * Created       : Tue Mar 28 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Unit tests
 *****************************************************************************/

#include <dlfcn.h>

#include "minunit.h"

typedef int (*lib_function)(const char *data);
char *lib_file = "build/libex29.so";
void *lib = NULL;

int check_function(const char *func_to_run, const char *data, int expected) {
  lib_function func = dlsym(lib, func_to_run);
  check(func != NULL, "Did not find %s function in the library %s: %s",
        func_to_run, lib_file, dlerror());

  int rc = func(data);
  check(rc == expected, "Function %s return %d for data: %s", func_to_run, rc,
        data);

  return 1;
error:
  return 0;
}

char *test_it_works() { return NULL; }

char *test_functions() {
  mu_assert(check_function("print_message", "Hi!", 0), "print_message failed.");

  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_it_works);
  mu_run_test(test_functions);

  return NULL;
}

RUN_TESTS(all_tests);