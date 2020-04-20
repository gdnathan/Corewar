/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** String duplication tests
*/

#include <criterion/criterion.h>
#include "../include/my_str.h"

Test(my_strdup, copy)
{
    char *sample = "Hello, world!";
    char *target;

    target = my_strdup(sample);
    cr_assert_str_eq(target, sample);
}

Test(my_strndup, copy_trunc)
{
    char *sample = "Hello, world!";
    char *target;

    target = my_strndup(sample, 5);
    cr_assert_str_eq(target, "Hello");
}

Test(my_strndup, copy_underrun)
{
    char *sample = "hello";
    char *target;

    target = my_strndup(sample, 10);
    cr_assert_str_eq(target, sample);
}
