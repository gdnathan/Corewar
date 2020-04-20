/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Compare strings
*/

#include "../include/my_str.h"

int my_strcmp(char const *s1, char const *s2)
{
    int match = 0;

    while ((s1[match] == s2[match]) && (s1[match] && s2[match]))
        match++;
    return ((match == my_strlen(s1)) && (match == my_strlen(s2)));
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int match = 0;

    while ((s1[match] == s2[match]) && (s1[match] && s2[match]) && match < n)
        match++;
    return (match == n);
}

char *my_strstr(char *str, char const *sub)
{
    int index = 0;
    int checki = 0;

    while (str[index]) {
        if (str[index + checki] == sub[checki]) {
            checki++;
        } else if (!sub[checki]) {
            return (str + index);
        } else {
            checki = 0;
            ++index;
        }
    }
    return (0);
}

int str_contains(char const *str, char c)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}
