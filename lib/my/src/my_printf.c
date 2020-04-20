/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Standard Print Format function
*/

#include "my_printf.h"
#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"

selector_t defs[] = {
    {   .exec = &def_putchar,
        .cond = 'c' },
    {   .exec = &def_puts,
        .cond = 's' },
    {   .exec = &def_int_dec,
        .cond = 'i' },
    {   .exec = &def_int_hex,
        .cond = 'x' },
    {   .exec = &def_int_bin,
        .cond = 'b' },
    {   .exec = &def_int_oct,
        .cond = 'o' },
    {   .exec = 0 }
};

static void pass_flags(char **fstart, struct flag_runnable *dest)
{
    int i = 0;

    while ((!is_char_type(**fstart, C_LOWER | C_UPPER | C_NUMBER | C_SPECIAL))
        || **fstart == 'l' || **fstart == 'h' || **fstart == '0') {
        dest->flags[i] = **fstart;
        (*fstart)++;
        i++;
    }
}

static void parse_offsets(char **fstart, struct flag_runnable *dest)
{
    if ((*fstart)[-1] == '.')
        dest->precision = my_getnbr(*fstart);
    else if ((*fstart)[-1] == '-')
        dest->padding = my_getnbr(*fstart - 1);
    else if (is_char_type(**fstart, C_NUMBER))
        dest->padding = my_getnbr(*fstart);
    while (is_char_type(**fstart, C_NUMBER))
        (*fstart)++;
    if (**fstart == '.') {
        dest->precision = my_getnbr(*fstart + 1);
        (*fstart)++;
        while (is_char_type(**fstart, C_NUMBER))
            (*fstart)++;
    }
}

static int exec_flag(char **flag_start, va_list args)
{
    struct flag_runnable options = {
        .padding = 0, .precision = 0, .argpos = 0
    };

    if (**flag_start == '%') {
        my_putchar('%');
        return (0);
    }
    pass_flags(flag_start, &options);
    parse_offsets(flag_start, &options);
    if (is_char_type(**flag_start, C_UPPER)) {
        options.isucase = 1;
        SELECT(**flag_start + 0x20, (options, args), defs);
    } else {
        options.isucase = 0;
        SELECT(**flag_start, (options, args), defs);
    }
    return (-1);
}

void my_printf(char const *format, ...)
{
    int i = 0;
    char *fpars;
    va_list args;

    va_start(args, format);
    while (format[i]) {
        if (format[i] == '%') {
            fpars = format + i + 1;
            if (!exec_flag(&fpars, args))
                i = fpars - format;
            else
                my_putchar('%');
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
}
