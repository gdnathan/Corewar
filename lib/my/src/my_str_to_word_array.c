/*
** EPITECH PROJECT, 2020
** library
** File description:
** my lib
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strndup(char const *str, int n);

char **finished_mstwa(char **new_array, int i)
{
    new_array[i - 1][my_strlen(new_array[i - 1])] = '\0';
    new_array[i] = NULL;
    return (new_array);

}

int mstwa_getsize(char *str)
{
    int size = 0;

    while (str[size] != '\0' && str[size] != ','){
        size += 1;
    }
    return (size);
}

int mstwa_nb_arg(char *str)
{
    int i = 0;
    int nb = 1;

    if (!str)
        return (0);
    while (str[i] != '\0') {
        if (str[i] == ',')
            nb += 1;
        i += 1;
    }
    return (nb);
}

char **my_str_to_word_array(char *str)
{
    char **new_array = malloc(sizeof(char *) * (mstwa_nb_arg(str) + 1));
    int size = 0;
    int i = 0;

    while (str[0] != '\0') {
        new_array[i] = my_strndup(str, mstwa_getsize(str));
        i += 1;
        while (str[0] != '\0' && str[0] != ',')
            str++;
        if (str[0] == '\0')
            continue;
        str++;
    }
    return (finished_mstwa(new_array, i));
}
