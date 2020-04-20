/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Print a string with strictly printable characters
*/

#include "../include/my_str.h"
#include "../include/my_io.h"
#include "../include/my_math.h"

void my_showstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (is_char_type(str[i], C_SPECIAL)) {
            my_putchar('\\');
            put_padded_nbr_base(str[i], "01234567", 3);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
}
