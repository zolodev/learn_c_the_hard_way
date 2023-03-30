#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  int count;
} List;

static List *list = NULL;

List *List_create() { return calloc(1, sizeof(List)); }

void List_unload(List *list) {
  free(list);
  list = NULL;
}

int main(void) {
  printf("list size [BEFORE]: %lu\n", sizeof(list));
  if (list == NULL) printf("List is NULL\n");  // <- Prints OK

  list = List_create();  // Create List
  List_unload(list);

  printf("list count: %d", list->count);
  if (list->count == 0) printf("List is empty\n");  // <- Does not print!

  printf("list size [AFTER]: %lu\n", sizeof(list));
  return 0;
}