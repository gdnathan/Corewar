/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Get a number from a string
*/

#include "../include/my_math.h"
#include "../include/my_str.h"

int my_getnbr_n(char const *str, int n)
{
    int buf = 0;
    int len = n;
    char in = 0;
    int c = 0;
    int i = 0;

    while (str[c] && c < n) {
        if (str[c] == '-' && !in)
            i++;
        else if ((!is_char_type(str[c], C_NUMBER)) && str[c] != '+' && len == n)
            len = c;
        else
            in = 1;
        c++;
    }
    c = (i - 1);
    while ((++c) < len)
        buf = (buf * 10) + str[c] - '0';
    return ((i % 2)?-buf:buf);
}

int my_getnbr(char const *str)
{
    return (my_getnbr_n(str, my_strlen(str)));
}
