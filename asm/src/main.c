/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "main.h"
#ifndef __TESTS

int main(int argc, char **argv)
{
    int status = main_error(argc, argv);
    int i = 1;

    if (status != 0)
        return status;
    do {
        if (my_asm(argv[i]) == 84)
            return (84);
    } while (argv[++i]);
    return (0);
}

#endif //__TESTS
