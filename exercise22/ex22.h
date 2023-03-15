/*****************************************************************************
 * Filename      : ex22.h
 * Created       : Wed Mar 15 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Exercise 22 - The Stack, Scope and Globals
 *****************************************************************************/

#ifndef _ex22_h
#define _ex22_h

#include "dbg.h"

// makes THE_SIZE in ex22.c available to other .c files
extern int THE_SIZE;

// gets and sets  an internal static variable in ex22.c
int get_age();
void set_age(int age);

// updates a static variable that's inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif // closes the #ifndef _ex22_h