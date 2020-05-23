/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** op_parse
*/

#include "main.h"

static void get_ops(op_t *tgt, char fmt)
{
    (tgt->ops[0] =  fmt       & 0b00000011) && (tgt->nops)++;
    (tgt->ops[1] = (fmt >> 2) & 0b00000011) && (tgt->nops)++;
    (tgt->ops[2] = (fmt >> 4) & 0b00000011) && (tgt->nops)++;
    (tgt->ops[3] = (fmt >> 6) & 0b00000011) && (tgt->nops)++;
}

op_t map_op(char *ptr_mem)
{
    op_t result;

    result.opcode = ptr_mem[0];
    get_ops(&result, ptr_mem[1]);
    return (result);
}
