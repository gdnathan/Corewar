/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Output a character
*/

#include "../include/my_io.h"

void my_putchar(char c)
{
    my_dputchar(1, c);
}

void my_dputchar(int fd, char c)
{
    write(fd, &c, 1);
}
