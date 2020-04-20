/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Append contents of s2 into s1
*/

#include "../include/my_str.h"

char *my_strcat(char const *s1, char const *s2)
{
    char *ret;
    int srclen = my_strlen(s1);

    ret = malloc(sizeof(char) * (srclen + my_strlen(s2) + 1));
    my_strcpy(ret, s1);
    my_strcpy(ret+srclen, s2);
    return (ret);
}

void str_append(char **src, char const *add)
{
    char *ret;

    ret = my_strcat(*src, add);
    free(*src);
    *src = ret;
}
