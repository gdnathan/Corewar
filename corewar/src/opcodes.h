/*
** EPITECH PROJECT, 2019
** COREWAR
** File description:
** Definitions for operators
*/

#ifndef __OPCODES_H
#define __OPCODES_H

#define PACKED __attribute__((__packed__))
#define COREWAR_MAGIC  0xea83f3
#define PNAME_LENGTH   128
#define COMMENT_LENGTH 2048

typedef char  reg_t;
typedef int   dir_t;
typedef long  ind_t;

typedef enum {
    T_NIL = 0b00,
    T_REG = 0b01,
    T_IND = 0b10,
    T_DIR = 0b11
} arg_t;

typedef struct {
    char  *mnemonic;
    char   opcode;
    int    nops;
    arg_t  ops[4];
} op_t;

typedef struct {
    int magic;
    char pname[PNAME_LENGTH + 1];
    int psize;
    char comment[COMMENT_LENGTH + 1];
} header_t;

extern op_t opdefs[23];

#endif //__OPCODES_H
