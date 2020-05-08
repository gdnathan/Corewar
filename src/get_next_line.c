/*
** EPITECH PROJECT, 2020
** get
** File description:
** ge
*/

#include "../lib/include/get_next_line.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

char *re_alloc(char *str, int size)
{
    char *new = NULL;
    int i = 0;
    int x = 0;

    while (str != NULL && str[x] != '\0')
        x = x + 1;
    new = malloc(sizeof(char) * (x + size + 1));
    if (new == NULL)
        return (NULL);
    if (str != NULL) {
        while (str[i] != '\0') {
            new[i] = str[i];
            i = i + 1;
        }
    }
    free(str);
    new[i] = '\0';
    return (new);
}

char *my_strcatcus(char *str, char *s_str, int size)
{
    char *new = NULL;
    int i = 0;
    int z = 0;
    int start = 0;

    if (s_str != NULL && s_str[0] == '\0')
        return (str);
    while (str != NULL && str[start] != '\0')
        start = start + 1;
    while (s_str != NULL && s_str[z] != '\0')
        z = z + 1;
    new = re_alloc(str, z);
    if (size < 0)
        size = z;
    while (s_str[i] != '\0' && (i < size)) {
        new[start + i] = s_str[i];
        i = i + 1;
    }
    new[start + i] = '\0';
    return (new);
}

char *add_str(char *str, char **save, int *copied)
{
    int i = 0;
    int j = -1;
    int max = 0;

    while (*save != NULL && (*save)[max] != '\n' && (*save)[max] != '\0')
        max = max + 1;
    if (*save == NULL || (*save)[max] == '\0') {
        if (max > 0)
            str = my_strcatcus(str, *save, -1);
        return (str);
    }
    str = my_strcatcus(str, *save, max);
    while (i++ < (max + 1)) {
        while ((*save)[++j] != '\0')
            (*save)[j] = (*save)[j + 1];
        j = -1;
    }
    *copied = 1;
    return (str);
}

int read_file(char **save, int fd, int *copied, char **str)
{
    char *buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    int re = (buffer == NULL) ? -1 : read(fd, buffer, READ_SIZE);
    int i = 0;

    free(*save);
    *save = NULL;
    if (re <= 0) {
        free(buffer);
        return (0);
    }
    buffer[re] = '\0';
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            *save = my_strcatcus(*save, &buffer[i + 1], -1);
            *copied = 1;
            break; }
        i = i + 1;
    }
    *str = my_strcatcus(*str, buffer, i);
    free(buffer);
    return (1);
}

char *get_next_line(int fd)
{
    static char *save = NULL;
    char *str = NULL;
    int copied = 0;

    if (fd < 0 || READ_SIZE <= 0)
        return (NULL);
    str = add_str(str, &save, &copied);
    while (copied == 0) {
        if (read_file(&save, fd, &copied, &str) == 0)
            return (str);
    }
    return (str);
}
