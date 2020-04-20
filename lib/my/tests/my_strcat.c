/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Tests for concatenation of two strings.
*/

#include <criterion/criterion.h>
#include "../include/my_str.h"

Test(my_strcat, concat)
{
    cr_assert_str_eq(my_strcat("Hello, ", "world!"), "Hello, world!");
}

Test(str_append, concat)
{
    char *dest = my_strdup("Hello");

    str_append(&dest, " world!");
    cr_assert_str_eq(dest, "Hello world!");
}
