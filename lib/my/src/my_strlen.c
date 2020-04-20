/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** How many letters in this string, I wonder...
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
