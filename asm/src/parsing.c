/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parsing
*/

#include <errno.h>
#include "my_str.h"
#include "my_io.h"
#include "my_macros.h"
#include "asm.h"

void set_basic_info(info_t *info, char *buffer)
{
    if (my_strncmp(buffer, "name", 4) == 1) {
        info->name = my_strdup(buffer + 6);
        info->name[my_strlen(info->name) - 1] = '\0';
        return;
    }
    if (my_strncmp(buffer, "comment", 7) == 1) {
        info->description = my_strdup(buffer + 9);
        info->description[my_strlen(info->description) - 1] = '\0';
        return;
    }
}

void formater(char **buffer)
{
    int i = 0;
    int j = 0;

    while ((*buffer)[j]) {
        if ((*buffer)[j] == '\t')
            (*buffer)[j] = ' ';
        j += 1;
    }
    while ((*buffer)[0] == ' ') {
        (*buffer)++;
    }
    while ((*buffer)[i++] != ' ');
    while ((*buffer)[0] == ' ')
        (*buffer)++;
}

void new_instruction(instructions_t **instruction, char *buffer)
{
    instructions_t *new = malloc(sizeof(instructions_t));
    int i = 0;

    _malloc_error(new);
    while (buffer[i] != '\0' && buffer[i] != ':')
        i += 1;
    if (buffer[i] == '\0' || buffer[i - 1] == '%') {
        new->optional_label = NULL;
        i = 0;
    } else {
        new->optional_label = my_strdup_to_char(buffer, ':');
        i += 2;
    }
    new->op_code = my_strdup_to_char(buffer + i, ' ');
    i += my_strlen(new->op_code);
    new->parameters = my_strdup(buffer + ++i);
    new->next = NULL;
    new->prev = *instruction;
    if (*instruction == NULL)
        *instruction = new;
    else
        (*instruction)->next = new;
}

int parse_infos(int fd, info_t *info)
{
    char *buffer = get_next_line(fd);
    instructions_t *tmp = NULL;

    if (buffer == NULL) {
        dprintf(2, "Error: File is empty.\n");
        return 84;
    }
    do {
        formater(&buffer);
        if (buffer[0] && buffer[0] == '.')
            set_basic_info(info, buffer + 1);
        else if (buffer[0] && buffer[0] != '#') {
            tmp = info->instruct;
            if (tmp) while (tmp->next != NULL)
                tmp = tmp->next;
            new_instruction(info->instruct ? &tmp : &info->instruct, buffer);
        }
        buffer = get_next_line(fd);
    } while (buffer != NULL);
}