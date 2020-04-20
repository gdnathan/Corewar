/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Output a NULL-terminated string of characters
*/

#include "../include/my_io.h"
#include "../include/my_str.h"

void my_dputs(int fd, char const *str)
{
    write(fd, str, my_strlen(str));
}

void my_puts(char const *str)
{
    my_dputs(1, str);
}
