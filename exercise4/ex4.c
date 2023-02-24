/*****************************************************************************
 * Filename      : ex3.c
 * Created       : Sat Feb 18 2023
 * Author        : zolodev
 * Github        : https://github.com/zolodev
 * Description   : Learn to use GDB, lldb, valgrind and splint (lint)
 *****************************************************************************/

#include <stdio.h>

// Bad code!
void crash()
{
    char *test = NULL;
    int i = 0;

    for (i = 0; i < 1000000; i++)
    {
        printf("%c", test[i]);
    }
}

int main()
{
    int age = 10;
    int height = 72;

    printf("I am %d years old.\n", age);
    printf("I am %d inches tall.\n", height);

    crash();

    return 0;
}
