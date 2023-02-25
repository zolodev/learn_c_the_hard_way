/*****************************************************************************
 * Filename      : ex14.c
 * Created       : Sat Feb 18 2023
 * Author        : zolodev
 * Github        : https://github.com/zolodev
 * Description   : Functions
 * Zeds example file:
 * https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex14/ex14.c
 *****************************************************************************/

#include <stdio.h>
#include <ctype.h>

int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < argc; i++)
    {
        print_letters(argv[i]);
    }
}

void print_letters(char arg[])
{
    int i = 0;
    for (i = 0; arg[i] != '\0'; i++)
    {
        char ch = arg[i];

        if (can_print_it(ch))
        {
            printf("'%c' == %d", ch, ch);
        }
    }

    printf("\n");
}

int can_print_it(char ch)
{
    return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
    // Zed suggest it should be 'argc + 1'
    // if I add +1 to argc I get a "Segmentation fault (core dumped)" error
    // therefore I have removed the +1 from the argument.
    // print_arguments(argc + 1, argv); // Zed's code suggestion
    print_arguments(argc, argv);
    return 0;
}