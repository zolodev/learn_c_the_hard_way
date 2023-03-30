/*****************************************************************************
 * Filename      : list_tests.c
 * Created       : Thu Mar 30 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Unit tests to cover the Double linked lists
 *****************************************************************************/

#include <assert.h>

#include "lcthw/list.h"
#include "minunit.h"

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create() {
  list = List_create();
  check_mem(list);
  mu_assert(list != NULL, "Failed to create list.");

  /* FALLTHROUGH */
error:
  return NULL;
}

char *test_push() {
  List_push(list, test1);
  mu_assert(List_last(list) == test1, "Wrong last value.");

  return NULL;
}

char *test_destroy() {
  List_clear_destroy(list);
  //   debug("destroy_list count? %d", list->count);
  //   mu_assert(list->count == 0, "Failed to clear list");

  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_create);
  mu_run_test(test_push);
  mu_run_test(test_destroy);

  return NULL;
}

RUN_TESTS(all_tests);