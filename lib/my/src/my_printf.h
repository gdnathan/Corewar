/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Definitions for printf flags
*/

#ifndef __MY_PRINTF_H
#define __MY_PRINTF_H

#include "../include/my.h"
#include "../include/selector.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

struct flag_runnable {
    char flags[32];
    bool isucase;
    int padding;
    int precision;
    int argpos;
};

int def_putchar(struct flag_runnable opts, va_list args);
int def_puts   (struct flag_runnable opts, va_list args);
int def_int_dec(struct flag_runnable opts, va_list args);
int def_int_hex(struct flag_runnable opts, va_list args);
int def_int_bin(struct flag_runnable opts, va_list args);
int def_int_oct(struct flag_runnable opts, va_list args);

#endif //__MY_PRINTF_H
