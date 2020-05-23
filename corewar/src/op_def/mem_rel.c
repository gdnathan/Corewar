/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** op_def
*/

#include "../cpu.h"

INST(op_ld)
{
    ex->regs[R_ARG(1)] = mem[(ex->ptr + D_ARG(0)) % INDEX_MOD];
}

INST(op_st)
{
    if (op.ops[1] == T_REG)
        ex->regs[R_ARG(1)] = ex->regs[R_ARG(0)];
    else if (op.ops[1] == T_IND)
        mem[(ex->ptr + I_ARG(1)) % INDEX_MOD] = ex->regs[R_ARG(0)];
}

INST(op_ldi)
{
    int dst = mem[(ex->ptr + I_ARG(0)) % INDEX_MOD] + D_ARG(1);

    ex->regs[R_ARG(2)] = mem[(ex->ptr + dst) % INDEX_MOD];
}

INST(op_sti)
{
    mem[ex->ptr + D_ARG(1) + D_ARG(2)] = ex->regs[R_ARG(0)];
}
