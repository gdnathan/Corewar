/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Outcome selector
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/selector.h"
#include "../include/my_io.h"
#include "../include/my_math.h"

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

void success(int);
void failure(int);

selector_t sample[] = {
    {
        .cond = 10,
        .exec = success
    },
    {
        .cond = 8,
        .exec = failure
    },
    {   .exec = 0 }
};

void success(int arg)
{
    if (arg == 42)
        my_puts("correct");
    else
        my_dputs(2, "arg miss\n");
}

void failure(int arg)
{
    my_dputs(2, "failure\n");
}

Test(selector, outcome_simple)
{
    cr_redirect_stdout();
    SELECT(10, (42), sample);
    cr_assert_stdout_eq_str("correct");
}

Test(selector, outcome_func)
{
    cr_redirect_stdout();
    SELECT(my_getnbr("10"), (42), sample);
    cr_assert_stdout_eq_str("correct");
}
