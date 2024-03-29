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

char *test_get_from_empty_list() {
  // Try fetch from empty list
  mu_assert(List_last(list) == NULL, "Expected NULL, got wrong last value.");

  return NULL;
}

char *test_push() {
  List_push(list, test1);
  mu_assert(List_last(list) == test1, "Expected test1, got wrong last value.");

  List_push(list, test2);
  mu_assert(List_last(list) == test2, "Expected test2, got wrong last value.");

  List_push(list, test3);
  mu_assert(List_last(list) == test3, "Expected test3, got wrong last value.");

  // Test NULL value, expect last inserted value
  List_push(list, NULL);
  mu_assert(List_last(list) == test3,
            "Expected test3 not NULL, got wrong last value.");

  return NULL;
}

char *test_pop() {
  char *val = List_pop(list);
  mu_assert(val == test1, "Expected test1, got wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == test2, "Expected test2, got wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == test3, "Expected test3, got wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == NULL, "Expected NULL, got wrong value on pop.");

  return NULL;
}

char *test_shift() {
  char *val = List_shift(list);
  mu_assert(val == test1, "Expected test1, got wrong value on shift.");

  val = List_shift(list);
  mu_assert(val == test3, "Expected test3, got wrong value on shift.");

  val = List_shift(list);
  mu_assert(val == NULL, "Expected NULL, got wrong value on shift.");

  return NULL;
}

char *test_destroy() {
  List_destroy(list);
  mu_assert(list->count == 0, "Expected count = 0, Failed to clear list");

  return NULL;
}

char *test_print_null_list() {
  int count = List_print(list);
  mu_assert(count == -1, "Expected -1 got something else.");

  return NULL;
}

char *test_print_all_items_in_list() {
  int count = List_print(list);
  mu_assert(count >= 0, "Failed to print items in list");

  return NULL;
}

char *test_remove() {
  char *val = List_remove(list, list->first->next);

  mu_assert(val == test2, "Wrong removed item.");
  mu_assert(List_count(list) == 2, "Expected 2 items, got wrong count.");
  mu_assert(List_first(list) == test1, "Expected test1, got wrong first item.");
  mu_assert(List_last(list) == test3, "Expecte test3, got wrong last item.");

  return NULL;
}

char *test_unshift() {
  mu_assert(List_count(list) == 0,
            "Expected 0 (zero), got wrong count in list.");
  mu_assert(List_first(list) == NULL, "Expected NULL, got wrong unshift item.");

  List_unshift(list, test1);
  mu_assert(List_first(list) == test1,
            "Expected test1, got wrong unshift item.");

  List_unshift(list, test2);
  mu_assert(List_first(list) == test2,
            "Expected test2, got wrong unshift item.");

  List_unshift(list, test3);
  mu_assert(List_first(list) == test3,
            "Expected test3, got wrong unshift item.");

  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_print_null_list);

  mu_run_test(test_create);
  mu_run_test(test_print_all_items_in_list);
  mu_run_test(test_get_from_empty_list);
  mu_run_test(test_push);
  mu_run_test(test_remove);
  mu_run_test(test_shift);
  mu_run_test(test_destroy);

  mu_run_test(test_create);
  mu_run_test(test_unshift);
  mu_run_test(test_print_all_items_in_list);
  mu_run_test(test_pop);
  mu_run_test(test_destroy);

  return NULL;
}

RUN_TESTS(all_tests);