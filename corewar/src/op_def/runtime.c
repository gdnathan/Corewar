/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** runtime
*/

#include "../cpu.h"

INST(op_live)
{
    ctxt->ttl = 10;
    my_puts("alive\n");
}

INST(op_fork)
{
    exec_t *new;
    int n = 0;

    ctxt->heads = realloc(ctxt->heads, sizeof(exec_t) + (++ctxt->nheads));
    new = ctxt->heads + ctxt->nheads;
    while (n < 10) {
        new->regs[n] = ex->regs[n];
        n++;
    }
    new->ptr = (ex->ptr + D_ARG(0)) % INDEX_MOD;
    new->carry = ex->carry;
    new->nhead = ctxt->nheads;
}

INST(op_lfork)
{
    exec_t *new;
    int n = 0;

    ctxt->heads = realloc(ctxt->heads, sizeof(exec_t) + (++ctxt->nheads));
    new = ctxt->heads + ctxt->nheads;
    while (n < 10) {
        new->regs[n] = ex->regs[n];
        n++;
    }
    new->ptr = ex->ptr + D_ARG(0);
    new->carry = ex->carry;
    new->nhead = ctxt->nheads;
}

INST(op_zjmp)
{
    if (ex->carry)
        ex->ptr += D_ARG(0) % INDEX_MOD;
}

INST(op_aff)
{
    my_putchar(ex->regs[R_ARG(0)] % 256);
}