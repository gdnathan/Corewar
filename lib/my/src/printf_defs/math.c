/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** printf flag functions for number display and manipulation
*/

#include "../my_printf.h"

void my_putchar_n(int, char);
int get_ndigits(int, int, int);

int def_int_dec(struct flag_runnable opts, va_list args)
{
    int i;

    opts.flags[31] = 0;
    if (str_contains(opts.flags, 'l') != -1)
        i = va_arg(args, long);
    else if (str_contains(opts.flags, 's') != -1)
        i = va_arg(args, int);
    else
        i = va_arg(args, int);
    if (opts.padding > 0)
        my_putchar_n(opts.padding - get_ndigits(i, 10, opts.precision), ' ');
    put_padded_nbr_base(i, "0123456789", opts.precision);
    if (opts.padding < 0)
        my_putchar_n((-opts.padding) - get_ndigits(i, 10, opts.precision), ' ');
    return (0);
}

int def_int_hex(struct flag_runnable opts, va_list args)
{
    int i = va_arg(args, int);

    opts.flags[31] = 0;
    if (str_contains(opts.flags, '#') != -1)
        my_puts(opts.isucase?"0X":"0x");
    if (opts.padding > 0)
        my_putchar_n(opts.padding - get_ndigits(i, 16, opts.precision), ' ');
    put_padded_nbr_base(i, opts.isucase?"0123456789ABCDEF":"0123456789abcdef",
        opts.precision);
    if (opts.padding < 0)
        my_putchar_n((-opts.padding) - get_ndigits(i, 16, opts.precision), ' ');
    return (0);
}

int def_int_oct(struct flag_runnable opts, va_list args)
{
    int i = va_arg(args, int);

    opts.flags[31] = 0;
    if (str_contains(opts.flags, '#') != -1)
        my_puts("0");
    if (opts.padding > 0)
        my_putchar_n(opts.padding - get_ndigits(i, 8, opts.precision), ' ');
    put_padded_nbr_base(i, "01234567", opts.precision);
    if (opts.padding < 0)
        my_putchar_n((-opts.padding) - get_ndigits(i, 8, opts.precision), ' ');
    return (0);
}

int def_int_bin(struct flag_runnable opts, va_list args)
{
    int i = va_arg(args, int);

    opts.flags[31] = 0;
    if (str_contains(opts.flags, '#') != -1)
        my_puts(opts.isucase?"0B":"0b");
    if (opts.padding > 0)
        my_putchar_n(opts.padding - get_ndigits(i, 2, opts.precision), ' ');
    put_padded_nbr_base(i, "01", opts.precision);
    if (opts.padding < 0)
        my_putchar_n((-opts.padding) - get_ndigits(i, 2, opts.precision), ' ');
    return (0);
}
