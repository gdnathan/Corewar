/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** opcode_fptr
*/

#include "asm.h"

#ifndef OPCODE_FPTR_H_
#define OPCODE_FPTR_H_

int check_live(char *opcode, p_type_t types[4]);
int check_ld(char *opcode, p_type_t types[4]);
int check_st(char *opcode, p_type_t types[4]);
int check_add(char *opcode, p_type_t types[4]);
int check_lld(char *opcode, p_type_t types[4]);
int check_lldi(char *opcode, p_type_t types[4]);
int check_lfork(char *opcode, p_type_t types[4]);
int check_aff(char *opcode, p_type_t types[4]);
int check_sub(char *opcode, p_type_t types[4]);
int check_and(char *opcode, p_type_t types[4]);
int check_or(char *opcode, p_type_t types[4]);
int check_xor(char *opcode, p_type_t types[4]);
int check_zjmp(char *opcode, p_type_t types[4]);
int check_ldi(char *opcode, p_type_t types[4]);
int check_sti(char *opcode, p_type_t types[4]);
int check_fork(char *opcode, p_type_t types[4]);

static int (*op_codes_error[])(char *, p_type_t *) =
{
    check_live,    
    check_ld,
    check_st,
    check_add,
    check_sub,
    check_and,
    check_or,
    check_xor,
    check_zjmp,
    check_ldi,
    check_sti,
    check_fork,
    check_lld,
    check_lldi,
    check_lfork,
    check_aff
};
#endif /* !OPCODE_FPTR_H_ */
