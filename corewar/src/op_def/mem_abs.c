/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** mem_abs
*/

#include "../cpu.h"

INST(op_lld)
{
    ex->regs[R_ARG(1)] = mem[ex->ptr + D_ARG(0)];
}

INST(op_lldi)
{
    int dst = mem[ex->ptr + I_ARG(0)] + D_ARG(1);

    ex->regs[R_ARG(2)] = mem[ex->ptr + dst];
}