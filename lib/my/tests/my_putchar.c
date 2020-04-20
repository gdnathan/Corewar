/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Tests for my_putchar
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_io.h"

Test(my_putchar, stdout)
{
    cr_redirect_stdout();
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_dputchar, stdout)
{
    cr_redirect_stdout();
    my_dputchar(1, 'a');
    cr_assert_stdout_eq_str("a");
}

Test(my_dputchar, stderr)
{
    cr_redirect_stderr();
    my_dputchar(2, 'a');
    cr_assert_stderr_eq_str("a");
}
