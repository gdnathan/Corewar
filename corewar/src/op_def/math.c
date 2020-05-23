/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** math
*/

#include "../cpu.h"

INST(op_add)
{
    ex->regs[R_ARG(2)] = ex->regs[R_ARG(0)] + ex->regs[R_ARG(1)];
    ex->carry = ex->regs[R_ARG(2)] - 0xFFFFFFFFFFFFFFFF < ex->regs[R_ARG(0)];
}

INST(op_sub)
{
    ex->regs[R_ARG(2)] = ex->regs[R_ARG(0)] - ex->regs[R_ARG(1)];
}

INST(op_and)
{
    long a;
    long b;

    if (op.ops[0] == T_REG)
        a = ex->regs[R_ARG(0)];
    else
        a = D_ARG(0);
    if (op.ops[1] == T_REG)
        b = ex->regs[R_ARG(1)];
    else
        b = D_ARG(1);
    ex->regs[R_ARG(2)] = a & b;
}

INST(op_or)
{
    long a;
    long b;

    if (op.ops[0] == T_REG)
        a = ex->regs[R_ARG(0)];
    else
        a = D_ARG(0);
    if (op.ops[1] == T_REG)
        b = ex->regs[R_ARG(1)];
    else
        b = D_ARG(1);
    ex->regs[R_ARG(2)] = a | b;
}

INST(op_xor)
{
    long a;
    long b;

    if (op.ops[0] == T_REG)
        a = ex->regs[R_ARG(0)];
    else
        a = D_ARG(0);
    if (op.ops[1] == T_REG)
        b = ex->regs[R_ARG(1)];
    else
        b = D_ARG(1);
    ex->regs[R_ARG(2)] = a ^ b;
}