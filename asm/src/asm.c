/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** asm
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my_str.h"
#include "my_macros.h"
#include "asm.h"
#include "opcodes.h"
#include <unistd.h>

// private prototypes
int parse_infos(int fd, info_t *info);

int create_binary(info_t *info)
{
    int fd = open(my_strcat(info->name, ".cor"), O_CREAT | O_WRONLY, 0666);
    int i = 0;

    write(fd, MAGIC, 4);
    write(fd, info->name, my_strlen(info->name));
    while (i++ < PROG_NAME_LENGTH - my_strlen(info->name))
        write(fd, "\0", 1);
    write(fd, info->description, my_strlen(info->description));
    while (i++ < COMMENT_LENGTH - my_strlen(info->description))
        write(fd, "\0", 1);
}

int my_asm(char *file)
{
    int fd = open(file, O_RDONLY);
    info_t *info = malloc(sizeof(info_t));
    info->instruct = NULL;

    if (fd == -1)
        return fd_error(file, fd);
    _malloc_error(info);
    parse_infos(fd, info);
    create_binary(info);
}