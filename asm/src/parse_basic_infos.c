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

int check_name(char *name)
{
    static int i = 0;

    if (i != 0)
        return (84);
    while (name[i++] != '"') {
        if (!name[i])
            return (84);
    }
    if (name[i] == '"' && name[i - 1] == '"')
        return (84);
    while (name[i++] != '"') {
        if (!name[i])
            return (84);
    }
    if (name[i])
        return (84);
    if (i > PROG_NAME_LENGTH + 7)
        return (84);
    return (0);
}

int check_description(char *description)
{
    static int i = 0;

    if (i != 0)
        return (84);
    while (description[i++] != '"') {
        if (!description[i])
            return (84);
    }
    if (description[i] == '"' && description[i - 1] == '"')
        return (84);
    while (description[i++] != '"') {
        if (!description[i])
            return (84);
    }
    if (description[i])
        return (84);
    if (i > COMMENT_LENGTH + 10)
        return (84);
    return (0);
}

int set_basic_info(info_t *info, char *buffer)
{
    if (my_strncmp(buffer, "name", 4) == 1) {
        info->name = my_strdup(buffer + 6);
        info->name[my_strlen(info->name) - 1] = '\0';
        while ((info->name[0] < 'a' || info->name[0] > 'z') && info->name[0] != '\0')
            info->name++;
        if (check_name(buffer) == 84)
            return (84);
        return (0);
    } else if (my_strncmp(buffer, "comment", 7) == 1) {
        info->description = my_strdup(buffer + 9);
        info->description[my_strlen(info->description) - 1] = '\0';
        if (check_description(buffer) == 84)
            return (84);
        return (0);
    } else {
        return (84);
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
    while ((*buffer)[i] && (*buffer)[i++] != ' ');
    while ((*buffer)[0] == ' ')
        (*buffer)++;
}

int parse_infos(int fd, info_t *info)
{
    char *buffer = get_next_line(fd);
    instructions_t *tmp = NULL;

    if (buffer == NULL) {
        write(2, "Error: File is empty.\n", 23);
        return 84;
    }
    do {
        formater(&buffer);
        if (buffer[0] && buffer[0] == '.') {
            if (set_basic_info(info, buffer + 1) == 84)
                return (84);
        }
        else if (buffer[0] && buffer[0] != '#' && line_error(buffer) == 1) {
            tmp = info->instruct;
            if (tmp) while (tmp->next != NULL)
                tmp = tmp->next;
            new_instruction(info->instruct ? &tmp
                            : &info->instruct, buffer, &info->label);
        }
        buffer = get_next_line(fd);
    } while (buffer != NULL);
}
