/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Tests for string-display related functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(my_printf, puts)
{
    cr_redirect_stdout();
    my_printf("%s, %corld", "Hello", 'w');
    cr_assert_stdout_eq_str("Hello, world");
}

Test(my_printf, showstr)
{
    cr_redirect_stdout();
    my_printf("%S, %%world", "H\x2llo");
    cr_assert_stdout_eq_str("H\\002llo, %world");
}

Test(my_printf, puts_padded)
{
    cr_redirect_stdout();
    my_printf("%-6s", "Hello");
    cr_assert_stdout_eq_str("Hello ");
}
