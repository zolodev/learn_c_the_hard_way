/*****************************************************************************
 * Filename      : list.c
 * Created       : Thu Mar 30 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Double linked lists
 *****************************************************************************/

#include "lcthw/list.h"

#include "dbg.h"

List *List_create() { return calloc(1, sizeof(List)); }

void List_destroy(List *list) {
  LIST_FOREACH(list, first, next, cur) {
    if (cur->prev) {
      free(cur->prev);
    }
  }

  free(list->last);
  free(list);

  // Need to reset the count to zero to
  // mitigating "free(): invalid pointer" error
  // on Windows and Linux
  list->count = 0;
}

void List_clear(List *list) {
  LIST_FOREACH(list, first, next, cur) { free(cur); }
}

void List_clear_destroy(List *list) {
  List_clear(list);
  List_destroy(list);
}

void List_push(List *list, void *value) {
  ListNode *node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if (list->last == NULL) {
    list->first = node;
    list->last = node;
  } else {
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
  }

  list->count++;

error:
  return;
}

void *List_remove(List *list, ListNode *node) {
  void *result = NULL;

  check(list, "Can not remove from the list, List is NULL.");
  check(list->first && list->last || list->count == 0, "List is empty");
  check(node, "node can't be NULL");

  if (node == list->first && node == list->last) {
    list->first = NULL;
    list->last = NULL;
  } else if (node == list->first) {
    list->first = node->next;
    check(list->first != NULL, "Invalid node, got a first that is NULL.");

    list->first->prev = NULL;
  } else if (node == list->last) {
    list->last = node->prev;
    check(list->last != NULL, "Invalid node, got a last that is NULL.");

    list->last->next = NULL;
  } else {
    ListNode *after = node->next;
    ListNode *before = node->prev;
    after->prev = before;
    before->next = after;
  }

  if (list->count > 0) list->count--;
  result = node->value;
  free(node);

error:
  return result;
}

void *List_pop(List *list) {
  check(list, "Can not pop last from the list, List is NULL.");
  ListNode *node = list->last;

  return node != NULL ? List_remove(list, node) : NULL;
error:
  return NULL;
}

void *List_shift(List *list) {
  check(list, "Can not pop first from the list, List is NULL.");
  ListNode *node = list->first;

  return node != NULL ? List_remove(list, node) : NULL;
error:
  return NULL;
}

int List_print(List *list) {
  check(list, "Can not print from the list, List is NULL.");
  LIST_FOREACH(list, first, next, cur) { printf("%s\n", cur->value); }

  return list->count;
error:
  return -1;
}