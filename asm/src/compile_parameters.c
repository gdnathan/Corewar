/*
** EPITECH PROJECT, 2020
** asm
** File description:
** compile_parameters
*/

#include "op.h"
#include "asm.h"
#include "my_macros.h"
#include "my_str.h"
#include "my_math.h"
#include <unistd.h>

char *my_memset(char c, int size)
{
    int i = 0;
    char *new = malloc(sizeof(char) * (size + 1));

    _malloc_error(new);
    while (i < size) {
        new[i] = c;
        i += 1;
    }
    return new;
}

void fill_0(p_type_t type, FILE *fp)
{
    int i = 1;

    if (type == direct) while (i < 4) {
        fwrite("\0", 1, 1, fp);
        i += 1;
    } else while (i < 2) {
        fwrite("\0", 1, 1, fp);
        i += 1;
    }
}

short label_adress(info_t *infos, instructions_t *tmp, FILE *fp, int i)
{
    instructions_t *pos_scan = infos->instruct;
    labels_t *label_pos = infos->label;
    int pos = 0;
    short relative_pos = 0;

    while (pos_scan != tmp) {
        pos += pos_scan->size;
        pos_scan = pos_scan->next;
    }
    while (my_strcmp(label_pos->name, tmp->parameters[i] + 1) != 1) {
        label_pos = label_pos->next;
    }
    relative_pos = label_pos->adress - pos;
    if (relative_pos >= 0) {
        fwrite("\0", 1, 1, fp);
    } else {
        char c = 0xFF;
        fwrite(&c, 1, 1, fp);
    }
    return relative_pos;
}

char *set_param_bytecode(info_t *infos, instructions_t *tmp,
                                    int i, FILE *fp)
{
    int size = tmp->type[i] == direct ? 4 : 2;
    static char bytecode = '\0';
    short bc = 0;

    if (tmp->parameters[i][0] == '%')
        tmp->parameters[i] += 1;
    if (tmp->parameters[i][0] == ':') {
        bc = label_adress(infos, tmp, fp, i);
        bytecode = bc;
        return &bytecode;
    }
    bytecode = my_getnbr(tmp->parameters[i]);
    fill_0(tmp->type[i], fp);
    return &bytecode;
}

void print_parameters(info_t *infos, instructions_t *tmp, FILE *fp)
{
    int i = 0;
    int nbr = 0;
    char r_bytecode = '\0';
    char *bytecode = NULL;

    while (i < 4) {
        if (tmp->parameters[i] == NULL)
            break;
        if (tmp->parameters[i][0] == 'r') {
            nbr = my_getnbr(tmp->parameters[i] + 1);
            r_bytecode = nbr;
            fwrite(&r_bytecode, 1, 1, fp);
        } else {
            bytecode = set_param_bytecode(infos, tmp, i, fp);
            fwrite(bytecode, 1, 1, fp);
        }
        i += 1;
    }
}