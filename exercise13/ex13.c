/*****************************************************************************
 * Filename      : ex13.c
 * Created       : Sat Feb 18 2023
 * Author        : zolodev
 * Github        : https://github.com/zolodev
 * Description   : For-loops and Arrays of Strings
*****************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    // Answer: It is because it is always 
    // the same for all commandline applications
    // in this case it will be (in linux) "./ex13"
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }    

    return 0;
}