/*****************************************************************************
 * Filename      : ex9.c
 * Created       : Sat Feb 18 2023
 * Author        : zolodev
 * Github        : https://github.com/zolodev
 * Description   : 
*****************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    while (i < 25)
    {
        printf("%d", i);
        i++;
    }

    // need this to add a final newline
    printf("\n");

    return 0;

}