/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Test for substring detector
*/

#include <criterion/criterion.h>
#include "../include/my_str.h"

Test(my_strstr, match)
{
    cr_assert_str_eq(my_strstr("Hello world", "lo"), "lo world");    
}

Test(my_strstr, no_match)
{
    cr_assert_eq(my_strstr("Hello world", "Hi"), 0);
}

Test(my_strstr, no_match_underrun)
{
    cr_assert_eq(my_strstr("Hello", "low"), 0);
}
