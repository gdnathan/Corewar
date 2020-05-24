;/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fptr_and_aff
*/

#include <stdio.h>
#include "opcodes.h"
#include "opcode_fptr.h"
#include "my_str.h"

void call_fptr_and_error(int i, instructions_t *new)
{
    if (op_codes_error[i](new->op_code, new->type) == 1) {
        write(2, "Error: wrong parameters for this opcode: ", 42);
        write(2, new->op_code, my_strlen(new->op_code));
        write(2, "\n", 1);
        exit(84);
    } 
}

void check_opcode(instructions_t *new)
{
    int i = 0;

    while (opcodes_template[i] != NULL) {
        if (my_strcmp(new->op_code, opcodes_template[i]) == 1) {
            call_fptr_and_error(i, new);
            return;
        }
        i += 1;
    }
    write(2, "Error: unknow opcode: ", 23);
    write(2, new->op_code, my_strlen(new->op_code));
    write(2, "\n", 1);
    exit(84);
}