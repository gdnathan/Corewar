/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Read one line from a file descriptor
*/

#include "../include/my_io.h"
#include "../include/my_str.h"

char *get_next_line(int fd)
{
    char *tgt = malloc(sizeof(char));
    char *tmp = malloc(sizeof(char) * READ_SIZE);
    char rd = 0;
    int ret = 0;
    int eol = -1;

    while ((ret = read(fd, tmp, READ_SIZE)) > 0
        && (eol = str_contains(tmp, '\n')) == -1) {
        rd = 1;
        str_append(&tgt, tmp);
    }
    if (ret > 0) {
        tmp[eol] = 0;
        rd = 1;
        str_append(&tgt, tmp);
    }
    free(tmp);
    if (!rd)
        free(tgt);
    return (rd?tgt:0);
}
