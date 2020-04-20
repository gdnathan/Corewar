/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Tests for char_type function
*/

#include <criterion/criterion.h>
#include "../include/my_str.h"

Test(char_type, check_simple)
{
    char sample = 'A';

    cr_assert_eq(is_char_type(sample, C_UPPER), 1);
}

Test(char_type, check_compound)
{
    char sample = '?';

    cr_assert_eq(is_char_type(sample, C_LOWER | C_UPPER | C_SPECIAL), 0);
}
