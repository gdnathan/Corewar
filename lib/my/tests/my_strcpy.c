/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Bitwise string copy functions
*/

#include <criterion/criterion.h>
#include "../include/my_str.h"

Test(my_strcpy, copy)
{
    char *sample = "Hello, world!";
    char *target = malloc(my_strlen(sample) + 1);

    my_strcpy(target, sample);
    cr_assert_str_eq(target, sample);
}

Test(my_strncpy, copy_trunc)
{
    char *sample = "Hello, world!";
    char *target = malloc(4);

    my_strncpy(target, sample, 3);
    cr_assert_str_eq(target, "Hel");
}

Test(my_strncpy, copy_underrun)
{
    char *sample = "Hello!";
    char *target = malloc(10);

    my_strncpy(target, sample, 10);
    cr_assert_str_eq(target, sample);
}
