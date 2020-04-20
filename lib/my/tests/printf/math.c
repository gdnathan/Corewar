/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Tests for printf defs involving numbers
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(my_printf, int_dec_hex)
{
    cr_redirect_stdout();
    my_printf("%.4i and %#x", 21, 0xcafe);
    cr_assert_stdout_eq_str("0021 and 0xcafe");
}

Test(my_printf, int_bin_oct)
{
    cr_redirect_stdout();
    my_printf("%#.8B and %o", 0b1011, 0714);
    cr_assert_stdout_eq_str("0B00001011 and 714");
}

Test(my_printf, int_padded)
{
    cr_redirect_stdout();
    my_printf("%4i", 42);
    cr_assert_stdout_eq_str("  42");
}

Test(my_printf, int_hybrid)
{
    cr_redirect_stdout();
    my_printf("%6.4x", 0x3f);
    cr_assert_stdout_eq_str("  003f");
}
