/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** cpu
*/

#include "cpu.h"
#include "op_def.h"

static void (*ops[16])(op_t op, ctxt_t *ctxt, exec_t *ex, void *args[4]) = {
    &op_live,
    &op_ld,
    &op_st,
    &op_add,
    &op_sub,
    &op_and,
    &op_or,
    &op_xor,
    &op_zjmp,
    &op_ldi,
    &op_sti,
    &op_fork,
    &op_lld,
    &op_lldi,
    &op_lfork,
    &op_aff
};

char mem[MEM_SIZE];

static int get_typesz(arg_t type)
{
    if (type == T_NIL)
        return (0);
    else if (type == T_REG)
        return (sizeof(reg_t));
    if (type == T_DIR)
        return (sizeof(dir_t));
    else if (type == T_IND)
        return (sizeof(ind_t));
}

static int get_off(int pos, op_t op)
{
    if (pos)
        return (get_off(pos - 1, op) + get_typesz(op.ops[pos]));
    else
        return (2);
}

void do_op(op_t op, ctxt_t *ctxt, exec_t *ex)
{
    int i = 0;
    void *args[4];

    while (i < 4) {
        args[i] = mem + ex->ptr + get_off(i, op);
        i++;
    }
    ctxt->ttl--;
    (ops[mem[ex->ptr] - 1])(op, ctxt, ex, args);
}
