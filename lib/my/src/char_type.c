/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Function to categorize chars into types
*/

#include "../include/my_str.h"

int is_char_type(char c, int mask)
{
    return ((c >= 'A' && c <= 'Z' && mask&C_UPPER)
        ||  (c >= 'a' && c <= 'z' && mask&C_LOWER)
        ||  (c >= '0' && c <= '9' && mask&C_NUMBER)
        ||  ((c > '~' || c < ' ') && mask&C_SPECIAL));
}
