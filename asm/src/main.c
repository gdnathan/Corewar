/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "main.h"

int main(int argc, char **argv)
{
    int status = main_error(argc, argv);
    int i = 1;

    if (status != 0)
        return status;
    do {
        my_asm(argv[i]);
    } while (argv[++i]);
}