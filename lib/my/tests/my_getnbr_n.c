/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Extract a number from the first N chars of a str
*/

#include <criterion/criterion.h>
#include "../include/my_math.h"

Test(my_getnbr_n, nbr_positive)
{
    cr_assert_eq(my_getnbr_n("424242", 4), 4242);
}

Test(my_getnbr_n, nbr_negative)
{
    cr_assert_eq(my_getnbr_n("---12345", 4), -1);
}

Test(my_getnbr_n, nbr_invalid)
{
    cr_assert_eq(my_getnbr_n("nope", 3), 0);
}
