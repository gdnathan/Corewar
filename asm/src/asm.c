/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** asm
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my_str.h"
#include "my_macros.h"
#include "asm.h"
#include <unistd.h>

// !ARCHITECTURE:
// *
/*
* main->asm
* asm->parse_info->
* asm->compile_header
* asm->compile_instruction
*/

// private prototypes

int parse_infos(int fd, info_t *info);

int compile_header(info_t *info, FILE *fp);

int compile_instruction(info_t *infos, FILE *fp);

int my_asm(char *file)
{
    int fd = open(file, O_RDONLY);
    info_t *info = malloc(sizeof(info_t));
    info->instruct = NULL;
    FILE *fp = NULL;
    char *tmp = NULL;

    info->label = NULL;
    if (fd == -1)
        return fd_error(file, fd);
    _malloc_error(info);
    if (parse_infos(fd, info) == 84)
        return 84;
    tmp = info->name;
    close(fd);
    if (tmp[0] >= 'A' && tmp[0] <= 'Z')
        tmp[0] += 32;
    fp = fopen(my_strcat(tmp, ".cor"), "w");
    compile_header(info, fp);
    compile_instruction(info, fp);
}
