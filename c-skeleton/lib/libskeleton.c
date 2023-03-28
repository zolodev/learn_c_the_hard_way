/*****************************************************************************
 * Filename      : libex29.c
 * Created       : Tue Mar 28 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Exercise 29 - Dynamic and Static Libraries
 *****************************************************************************/

#include <ctype.h>
#include <stdio.h>

#include "dbg.h"

int print_message(const char *msg)
{
  printf("A STRING: %s\n", msg);

  return 0;
}

int uppercase(const char *msg)
{
  int length = sizeof(length);

  for (int i = 0; i <= length; i++)
  {
    printf("%c", toupper(msg[i]));
  }
  printf("\n");

  return 0;
}
