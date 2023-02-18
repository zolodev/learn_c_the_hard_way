/*****************************************************************************
 * Filename      : ex8.c
 * Created       : Sat Feb 18 2023
 * Author        : zolodev
 * Github        : https://github.com/zolodev
 * Description   : 
*****************************************************************************/

#include <stdio.h>

// Note: argc (arguments count) & argv (arguments values)
int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 1) {
        printf("You only have one argument. You suck.\n");
    } else if(argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        // In order to show the users argument
        // we need to start from 1 in the array
        // because index 0 is always the application it self
        // For extra credit
        for(i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many arguments. You suck.\n");
    }

    return 0;
}