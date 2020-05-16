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
#include "op.h"

// *private prototypes:

void new_instruction(instructions_t **instruction, char *buffer,
                    labels_t **label);

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
            new_instruction(info->instruct ? &tmp
                            : &info->instruct, buffer, &info->label);
        }
        buffer = get_next_line(fd);
    } while (buffer != NULL);
}
