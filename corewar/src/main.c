/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "opcodes.h"

op_t opdefs[23] = {
    { "live",  0x1,  1, { T_DIR } },
    { "ld",    0x2,  2, { T_DIR, T_REG } },
    { "st",    0x3,  2, { T_REG, T_REG } },
    { "st",    0x3,  2, { T_REG, T_IND } },
    { "add",   0x4,  3, { T_REG, T_REG, T_REG } },
    { "sub",   0x5,  3, { T_REG, T_REG, T_REG } },
    { "and",   0x6,  3, { T_REG, T_DIR, T_REG } },
    { "or",    0x7,  3, { T_REG, T_DIR, T_REG } },
    { "xor",   0x8,  3, { T_REG, T_DIR, T_REG } },
    { "zjmp",  0x9,  1, { T_IND } },
    { "ldi",   0xa,  3, { T_IND, T_IND, T_REG } },
    { "sti",   0xb,  3, { T_REG, T_IND, T_IND } },
    { "sti",   0xb,  3, { T_REG, T_IND, T_REG } },
    { "sti",   0xb,  3, { T_REG, T_REG, T_IND } },
    { "sti",   0xb,  3, { T_REG, T_REG, T_REG } },
    { "fork",  0xc,  1, { T_IND } },
    { "lld",   0xd,  2, { T_DIR, T_REG } },
    { "lldi",  0xe,  3, { T_REG, T_IND, T_IND } },
    { "lldi",  0xe,  3, { T_REG, T_IND, T_REG } },
    { "lldi",  0xe,  3, { T_REG, T_REG, T_IND } },
    { "lldi",  0xe,  3, { T_REG, T_REG, T_REG } },
    { "lfork", 0xf,  1, { T_IND } },
    { "aff",   0x10, 1, { T_REG } }
};

#ifndef __TESTS
int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    return (0);
}
#endif //__TESTS
