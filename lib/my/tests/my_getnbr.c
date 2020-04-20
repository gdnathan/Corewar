/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Unit tests for getnbr
*/

#include <criterion/criterion.h>
#include "../include/my_math.h"

Test(my_getnbr, nbr_positive)
{
    cr_assert_eq(my_getnbr("424242"), 424242);
}

Test(my_getnbr, nbr_negative)
{
    cr_assert_eq(my_getnbr("---144"), -144);
}

Test(my_getnbr, nbr_invalid)
{
    cr_assert_eq(my_getnbr("nope"), 0);
}

