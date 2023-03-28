/*****************************************************************************
 * Filename      : myapp.c
 * Created       : Tue Mar 28 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   :
 *****************************************************************************/

#include <dlfcn.h>
#include <stdio.h>

#include "dbg.h"

typedef int (*lib_function)(const char *data);
char *lib_file = "build/mylib.so";
void *lib = NULL;

int main(void) {
  int rc = 0;
  char *func_to_run = "print_message";
  char *message = "Hello!";

  printf("Hello world!\n");

  void *lib = dlopen(lib_file, RTLD_NOW);
  check(lib != NULL, "Failed to open library %s: %s", lib_file, dlerror());

  lib_function func = dlsym(lib, func_to_run);
  check(func != NULL, "Could't find %s function in library %s: %s.",
        func_to_run, lib_file, dlerror());
  rc = func(message);
  check(rc == 0, "Function %s returen %d for message: %s", func_to_run, rc,
        message);

  return 0;
error:
  return 1;
}