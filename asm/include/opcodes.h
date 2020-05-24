/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Unified spec for instructions
*/

#ifndef __OPCODES_H
#define __OPCODES_H

static const char *opcodes_template[16] = {
    "live",
    "ld",
    "st",
    "add",
    "sub",
    "and",
    "or",
    "xor",
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lld",
    "lldi",
    "lfork",
    "aff"
};

static const char core_opcodes[16] = {
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x10
};

#endif //__OPCODES_H
