/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Tests for number output
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_math.h"

Test(my_putnbr_base, base_denary)
{
    cr_redirect_stdout();
    my_putnbr_base(4242, "0123456789");
    cr_assert_stdout_eq_str("4242");
}

Test(my_putnbr_base, base_bin)
{
    cr_redirect_stdout();
    my_putnbr_base(0b100101, "ol");
    cr_assert_stdout_eq_str("loolol");
}

Test(my_putnbr_base, base_denary_neg)
{
    cr_redirect_stdout();
    my_putnbr_base(-234, "0123456789");
    cr_assert_stdout_eq_str("-234");
}

Test(put_padded_nbr_base, base_hex)
{
    cr_redirect_stdout();
    put_padded_nbr_base(0xcafe, "0123456789abcdef", 6);
    cr_assert_stdout_eq_str("00cafe");
}
