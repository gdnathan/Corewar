/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** instruction_parsing
*/

#include "my_str.h"
#include "my_io.h"
#include "my_macros.h"
#include "asm.h"
#include "op.h"

// private prototypes
void new_label(labels_t **label, char *buffer, instructions_t *instruct);

int compute_size(instructions_t *new)
{
    int i = 0;
    int size = 1;
    int passed = 0;

    while (i < 4) {
        if (my_strcmp(new->op_code, no_params[i]) == 1)
            passed = 1;
        i += 1;
    }
    i = 0;
    if (passed == 0) {
        size += 1;
    }
    while (i < 4) {
        size += (new->type[i] == lil_dir ? indirect : new->type[i]);
        i += 1;
    }
    return size;
}

enum p_type direct_size(char *opcode)
{
    int i = 0;

    while (lil_ind[i]) {
        if (my_strcmp(opcode, lil_ind[i]) == 1)
            return lil_dir;
        i += 1;
    }
    return direct;
}

int parse_parameters(instructions_t *new, char *buffer)
{
    char **args = my_str_to_word_array(buffer);
    int i = 0;

    while (i < 4) {
        if (args[i] && args[i][0] == ' ')
            args[i]++;
        if (!args[i]) {
            new->type[i] = nope;
            new->parameters[i++] = NULL;
            break;
        }
        if (args[i][0] == 'r') {
            new->type[i] = reg;
        } else if (args[i][0] == '%') {
            new->type[i] = direct_size(new->op_code);
        } else
            new->type[i] = indirect;
        new->parameters[i] = my_strdup(args[i]);
        i += 1;
    }
    return compute_size(new);
}

void new_instruction(instructions_t **instruction, char *buffer, labels_t **label)
{
    instructions_t *new = malloc(sizeof(instructions_t));
    int i = 0;

    _malloc_error(new);
    while (buffer[i] != '\0' && buffer[i] != ':')
        i += 1;
    if (buffer[i] != '\0' && buffer[i - 1] != '%') {
        new_label(label, buffer, *instruction);
        i += 2;
    } else
        i = 0;
    new->op_code = my_strdup_to_char(buffer + i, ' ');
    i += my_strlen(new->op_code);
    new->size = parse_parameters(new, my_strdup(buffer + ++i));
    new->next = NULL;
    new->prev = *instruction;
    if (*instruction == NULL)
        *instruction = new;
    else
        (*instruction)->next = new;
}
