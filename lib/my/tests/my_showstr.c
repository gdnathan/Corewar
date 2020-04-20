/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Function to display strings with only printable chars
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_io.h"

Test(my_showstr, str_printable)
{
    cr_redirect_stdout();
    my_showstr("a reality");
    cr_assert_stdout_eq_str("a reality");
}

Test(my_showstr, str_nonprintable)
{
    cr_redirect_stdout();
    my_showstr("i\nam\tinvisibl\e");
    cr_assert_stdout_eq_str("i\\012am\\011invisibl\\033");
}
