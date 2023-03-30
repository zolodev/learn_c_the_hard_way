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