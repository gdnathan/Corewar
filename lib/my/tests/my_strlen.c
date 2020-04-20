/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Measure the length of a string
*/

#include <criterion/criterion.h>
#include "../include/my_str.h"

Test(my_strlen, length)
{
    char *sample = "Hello!";

    cr_assert_eq(my_strlen(sample), 6);
}

Test(my_strlen, length_zero)
{
    char *sample = "";

    cr_assert_eq(my_strlen(sample), 0);
}
