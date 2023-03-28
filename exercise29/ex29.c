/*****************************************************************************
 * Filename      : ex29.c
 * Created       : Tue Mar 28 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Exercise 29 - Test loading in static and dynamic libs
 *****************************************************************************/

#include <dlfcn.h>
#include <stdio.h>

#include "dbg.h"

typedef int (*lib_function)(const char *data);

int main(int argc, char *argv[]) {
  int rc = 0;
  check(argc == 4, "USAGE: ex29 ./libex29.so <function_name> message");

  char *lib_file = argv[1];
  char *func_to_run = argv[2];
  char *data = argv[3];

  void *lib = dlopen(lib_file, RTLD_NOW);
  check(lib != NULL, "Failed to load library %s: %s", lib_file, dlerror());

  lib_function func = dlsym(lib, func_to_run);
  check(rc == 0, "Did not find %s function in library: %s: %s", func_to_run,
        lib_file, dlerror());

  rc = func(data);
  check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

  rc = dlclose(lib);
  check(rc == 0, "Failed to close %s", lib_file);

  return 0;
error:
  return 1;
}