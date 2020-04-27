/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Unified spec for instructions
*/

#ifndef __OPCODES_H
#define __OPCODES_H

typedef enum {
    OP_LIVE     = 0x01,

    OP_LD       = 0x02,
    OP_ST       = 0x03,

    OP_ADD      = 0x04,
    OP_SUB      = 0x05,

    OP_AND      = 0x06,
    OP_OR       = 0x07,
    OP_XOR      = 0x08,

    OP_ZJMP     = 0x09,
    OP_LDI      = 0x0a,
    OP_STI      = 0x0b,
    OP_FORK     = 0x0c,

    OP_LLD      = 0x0d,
    OP_LLDI     = 0x0e,
    OP_LFORK    = 0x0f,

    OP_AFF      = 0x10
} core_opcode_t;

struct core_op_def {
    core_opcode_t code;
    char coding;
};

#endif //__OPCODES_H
