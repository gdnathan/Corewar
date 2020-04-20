/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Output a number as a string
*/

#include "../include/my_math.h"
#include "../include/my_io.h"
#include "../include/my_str.h"

void put_padded_nbr_base(int n, char const *base, int pad)
{
    int bn = my_strlen(base);
    int worknbr = n;
    int ndigits = 0;

    if (n < 0) {
        my_putchar('-');
        worknbr = -n;
        n = -n;
    }
    while (worknbr) {
        ndigits++;
        worknbr /= bn;
    }
    if (ndigits < pad)
        ndigits = pad;
    while (ndigits) {
        my_putchar(base[(n/my_ipow(bn, ndigits - 1)) % bn]);
        ndigits--;
    }
}

void my_putnbr_base(int n, char const *base)
{
    put_padded_nbr_base(n, base, 1);
}
