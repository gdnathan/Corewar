/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Tests for integer powers
*/

#include <criterion/criterion.h>
#include "../include/my_math.h"

Test(my_ipow, positive)
{
    cr_assert_eq(my_ipow(10, 3), 1000);
}

Test(my_ipow, null)
{
    cr_assert_eq(my_ipow(10, 0), 1);
}

Test(my_ipow, negative)
{
    cr_assert_eq(my_ipow(2, -1), 0);
}

Test(my_ipow_r, positive)
{
    cr_assert_eq(my_ipow_r(10, 3), 1000);
}

Test(my_ipow_r, null)
{
    cr_assert_eq(my_ipow_r(10, 0), 1);
}
