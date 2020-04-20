/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Support functions for printf
*/

#include "../../include/my_io.h"

void my_putchar_n(int n, char c)
{
    int i = 0;

    if (n < 0)
        return;
    while (i < n) {
        my_putchar(c);
        i++;
    }
}

int get_ndigits(int n, int base, int precision)
{
    int count = 0;
    int workn = n;

    while (workn) {
        workn /= base;
        count++;
    }
    if (count < precision)
        return (precision);
    return (count);
}
