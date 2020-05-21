/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** printf flag functions pertaining to display of strings
*/

#include "../my_printf.h"

void my_putchar_n(int, char);

int def_putchar(struct flag_runnable opts, va_list args)
{
    char c = (char) va_arg(args, int);

    my_putchar(c);
    return (0);
}

int def_puts(struct flag_runnable opts, va_list args)
{
    char *s = va_arg(args, char *);

    if (opts.padding > 0)
        my_putchar_n(opts.padding - my_strlen(s), ' ');
    if (opts.isucase)
        my_showstr(s);
    else
        my_puts(s);
    if (opts.padding < 0)
        my_putchar_n((-opts.padding) - my_strlen(s), ' ');
    return (0);
}
