/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Test for GNL-type function
*/

#include <criterion/criterion.h>
#include "../include/my_io.h"

Test(get_next_line, line_empty)
{
    FILE *infd;

    infd = tmpfile();
    fwrite("\n", 1, 1, infd);
    rewind(infd);
    cr_assert_str_eq(get_next_line(fileno(infd)), "");
}

Test(get_next_line, line_null)
{
    FILE *infd;

    infd = tmpfile();
    cr_assert_eq(get_next_line(fileno(infd)), 0);
}

Test(get_next_line, line_end)
{
    FILE *infd;

    infd = tmpfile();
    fwrite("Hello\nworld", 1, 11, infd);
    rewind(infd);
    cr_assert_str_eq(get_next_line(fileno(infd)), "Hello");
}

Test(get_next_line, line_underrun)
{
    FILE *infd;

    infd = tmpfile();
    fwrite("test", 1, 4, infd);
    rewind(infd);
    cr_assert_str_eq(get_next_line(fileno(infd)), "test");
}
