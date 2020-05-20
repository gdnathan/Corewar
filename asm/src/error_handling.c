/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** error_handling
*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#define USAGE "Usage: ./asm file_name[.s] ....\n"

int main_error(int ac, char **av)
{
    if (ac == 1) {
        dprintf(2 , USAGE);
        exit (84);
    }
    return 0;
}

int fd_error(char *file, int fd)
{
    switch errno {
        case EACCES:
            write(2, "%s: Permission Denied.\n", file);
            break;
        case EISDIR:
            dprintf(2, "%s: Is a directory.\n", file);
            break;
        case ENOENT:
            dprintf(2, "%s: No such file or directory.\n", file);
            break;
        default:
            dprintf(2, "%s: Error opening file. No debug information\n", file);
    }
    return 84;
}

int line_error(char *buffer)
{
    return 1;
}