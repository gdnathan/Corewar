/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** error_handling
*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define USAGE "Usage: ./asm file_name[.s] ....\n"

int main_error(int ac, char **av)
{
    if (ac == 1) {
        write(2 ,USAGE, 33);
        exit (84);
    }
    return 0;
}

int fd_error(char *file, int fd)
{
    write(2, file, my_strlen(file));
    switch errno {
        case EACCES:
            write(2, ": Permission Denied.\n", 22);
            break;
        case EISDIR:
            write(2, ": Is a directory.\n", 19);
            break;
        case ENOENT:
            write(2, ": No such file or directory.\n", 30);
            break;
        default:
            write(2, ": Error opening file. No debug information\n", 44);
    }
    return 84;
}

int line_error(char *buffer)
{
    return 1;
}
