/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Tests for comparison of two strings
*/

#include <criterion/criterion.h>
#include "../include/my_str.h"

Test(my_strcmp, match)
{
    cr_assert_eq(my_strcmp("Hello!", "Hello!"), 1);
}

Test(my_strcmp, no_match)
{
    cr_assert_eq(my_strcmp("Hello!", "World!"), 0);
}

Test(my_strcmp, no_match_underrun)
{
    cr_assert_eq(my_strcmp("Hello!", "Hell"), 0);
}
