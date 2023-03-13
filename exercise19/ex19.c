/*****************************************************************************
 * Filename      : ex19.c
 * Created       : Mon Mar 13 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Exercise 19 - Awsome debug macros
 *****************************************************************************/

#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
    // notice you don't need the \n
    debug("I have Brown Hair.");

    // passing in arguments like printf
    debug("I am %d years old.", 39);
}

void test_log_err()
{
    log_err("I believe everything is broken.");
    log_err("There are %d problems in %s.", 0, "space");
}

void test_log_warn()
{
    log_warn("You can safely ignore this.");
    log_warn("There are %d problems in %s.", 0, "space");
}

void test_log_info()
{
    log_info("Well I did something mundane.");
    log_info("It happend %f times today.", 1.3f);
}

int test_check(char *file_name)
{
    FILE *input = NULL;
    char *block = NULL;

    block = malloc(100);
    check_mem(block); // check malloc works

    input = fopen(file_name, "r");
    check(input, "Failed to open %s.", file_name);

    free(block);
    fclose(input);

    return 0;

error:
    if (block)
        free(block);
    if (input)
        fclose(input);

    // printf("Error reading file, returning -1.");

    return -1;
}

int test_sentinel(int code)
{
    char *temp = malloc(100);
    check_mem(temp);

    switch (code)
    {
    case 1:
        log_err("It worked.");
        break;
    default:
        sentinel("I should't run.");
        break;
    }

    free(temp);
    return 0;

error:
    if (temp)
        free(temp);
    return -1;
}

int test_check_mem()
{
    char *test = NULL;
    check_mem(test);

    free(test);
    return 0;

error:
    return -1;
}

int test_check_debug()
{
    int i = 0;
    check_debug(i != 0, "Oops, I was 0,");

    return 0;

error:
    return -1;
}

int main(int argc, char *argv[])
{
    // Check to make sure we have at least one argument from the user
    check(argc == 2, "Need an argument.");

    test_debug();
    test_log_err();
    test_log_warn();
    test_log_info();

    check(test_check("ex19.c") == 0, "failed with ex19.c");
    check(test_check(argv[1]) == -1, "failed with argv");
    check(test_sentinel(1) == 0, "test_sentinel failed.");
    check(test_sentinel(100) == -1, "test_sentinel failed.");
    check(test_check_mem() == -1, "test_check_mem failed");
    check(test_check_debug() == -1, "test_check_debug failed");

    return 0;

// check() needs an error label in case of error
error:
    return 1;
}