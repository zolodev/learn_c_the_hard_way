/*****************************************************************************
 * Filename      : ex22.c
 * Created       : Wed Mar 15 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   :
 *****************************************************************************/

#include "dbg.h"
#include "ex22.h"

#include <stdio.h>

int THE_SIZE = 1000;

static int THE_AGE = 37;

int get_age()
{
    return THE_AGE;
}

void set_age(int age)
{
    THE_AGE = age;
}

double update_ratio(double new_ratio)
{
    static double ratio = 1.0;

    double old_ratio = ratio;
    ratio = new_ratio;

    // not sure if this is intentionally or if it should be ratio.
    // Logical speaking this feels wrong for me.
    // Becaise I see old_ratio as a "temp" variable.
    return old_ratio;
}

void print_size()
{
    log_info("I think size is: %d", THE_SIZE);
}