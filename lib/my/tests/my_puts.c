/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Tests for string output
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_io.h"

Test(my_puts, stdout)
{
    cr_redirect_stdout();
    my_puts("a dream");
    cr_assert_stdout_eq_str("a dream");
}

Test(my_dputs, stdout)
{
    cr_redirect_stdout();
    my_dputs(1, "an idea");
    cr_assert_stdout_eq_str("an idea");
}

Test(my_dputs, stderr)
{
    cr_redirect_stderr();
    my_dputs(2, "a project");
    cr_assert_stderr_eq_str("a project");
}
