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

#include "dbg.h"

typedef struct List {
  int count;
} List;

List *List_create() { return calloc(1, sizeof(List)); }

#endif