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

char *my_strdup_to_char(char *src, char c)
{
    char *new = NULL;
    int i = 0;
    int del = 0;
    int len = 0;

    if (src == NULL)
        return (NULL);
    while (src[len] != c && src[len] != '\0')
        len += 1;
    new = malloc(sizeof(char) * (len + 1));
    while (del != len) {
        new[del] = '\0';
        del += 1;
    }
    while (src[i] != c && src[i] != '\0') {
        new[i] = src[i];
        i += 1;
    }
    new[i] = '\0';
    return (new);
}