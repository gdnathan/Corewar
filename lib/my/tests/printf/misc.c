/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Tests for printf defs involving numbers
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(my_printf, misc_unk)
{
    cr_redirect_stdout();
    my_printf("%z is not implemented.");
    cr_assert_stdout_eq_str("%z is not implemented.");
}

Test(my_printf, misc_unk_chained)
{
    cr_redirect_stdout();
    my_printf("%c don't know what %z is!", 'I');
    cr_assert_stdout_eq_str("I don't know what %z is!");
}

Test(my_printf, misc_noflag)
{
    cr_redirect_stdout();
    my_printf("Flags? Ah, ain't seen no flags 'round, mate.");
    cr_assert_stdout_eq_str("Flags? Ah, ain't seen no flags 'round, mate.");
}

Test(my_printf, misc_overflow)
{
    cr_redirect_stdout();
    my_printf("Most printfs crash when they see this: %");
    cr_assert_stdout_eq_str("Most printfs crash when they see this: %");
}
