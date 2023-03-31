/*****************************************************************************
 * Filename      : list.h
 * Created       : Thu Mar 30 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Double linked list
 *****************************************************************************/

#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
  void *value;
} ListNode;

typedef struct List {
  int count;
  ListNode *first;
  ListNode *last;
} List;

List *List_create();
void List_clear(List *list);
void List_destroy(List *list);
void List_clear_destroy(List *list);

void List_push(List *list, void *value);

#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

#define LIST_FOREACH(L, S, M, V) \
  ListNode *_node = NULL;        \
  ListNode *V = NULL;            \
  for (V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif