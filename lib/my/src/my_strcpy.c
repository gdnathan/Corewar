/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Copy strings around in memory
*/

#include "../include/my_str.h"

char *my_strcpy(char *dest, char const *src)
{
    return (my_strncpy(dest, src, my_strlen(src)));
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
