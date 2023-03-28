/*****************************************************************************
 * Filename      : libex29_tests.c
 * Created       : Tue Mar 28 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Unit tests for libex29
 *****************************************************************************/

#include "minunit.h"

char *test_it_works() { return NULL; }

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_it_works);

  return NULL;
}

RUN_TESTS(all_tests);