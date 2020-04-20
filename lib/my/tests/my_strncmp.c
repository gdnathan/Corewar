/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Compare the first n chars of a string
*/

#include <criterion/criterion.h>
#include "../include/my_str.h"

Test(my_strncmp, match)
{
    cr_assert_eq(my_strncmp("Hello!", "Hell", 4), 1);
}

Test(my_strncmp, no_match)
{
    cr_assert_eq(my_strncmp("Hello!", "World!", 4), 0);
}

Test(my_strncmp, no_match_underrun)
{
    cr_assert_eq(my_strncmp("Hello!", "Hell", 5), 0);
}
