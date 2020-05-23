/*
** EPITECH PROJECT, 2019
** COREWAR
** File description:
** Processor defs
*/

#ifndef __CPU_H
#define __CPU_H

#include "main.h"

#define INST(x) void x (op_t op, ctxt_t *ctxt, exec_t *ex, void *args[4])
#define R_ARG(i) *((reg_t *) args[i])
#define D_ARG(i) *((dir_t *) args[i])
#define I_ARG(i) *((ind_t *) args[i])
#define MEM_SIZE (6*1024)
#define INDEX_MOD (512)

extern char mem[MEM_SIZE];

typedef struct {
    long  regs[10];
    long  ptr;
    bool  carry;
    int   nhead;
} exec_t;

typedef struct {
    int nheads;
    exec_t *heads;
    int ttl;
} ctxt_t;

#endif //__CPU_H
