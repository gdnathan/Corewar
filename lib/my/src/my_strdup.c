/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Allocate and duplicate strings in memory
*/

#include "../include/my_str.h"

char *my_strdup(char const *str)
{
    return (my_strndup(str, my_strlen(str)));
}

char *my_strndup(char const *str, int n)
{
    char *dest = malloc(n + 1);
    my_strncpy(dest, str, n);
    return dest;
}
