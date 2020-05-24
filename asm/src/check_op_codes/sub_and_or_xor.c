/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** sub_and_or_xor
*/

#include "opcode_fptr.h"

int check_sub(char *opcode, p_type_t types[4])
{
    if (types[0] != reg) {
        return 1;
    }
    if (types[1]!= reg) {
        return 1;
    }
    if (types[2] != reg) {
        return 1;
    }
    if (types[3] != nope) {
        return 1;
    }
    return 0;
}

int check_and(char *opcode, p_type_t types[4])
{
    if (types[0] == nope) {
        return 1;
    }
    if (types[1] == nope) {
        return 1;
    }
    if (types[2] != reg) {
        return 1;
    }
    if (types[3] != nope) {
        return 1;
    }
    return 0;
}

int check_or(char *opcode, p_type_t types[4])
{
    if (types[0] == nope) {
        return 1;
    }
    if (types[1] == nope) {
        return 1;
    }
    if (types[2] != reg) {
        return 1;
    }
    if (types[3] != nope) {
        return 1;
    }
    return 0;
}

int check_xor(char *opcode, p_type_t types[4])
{
    if (types[0] == nope) {
        return 1;
    }
    if (types[1] == nope) {
        return 1;
    }
    if (types[2] != reg) {
        return 1;
    }
    if (types[3] != nope) {
        return 1;
    }
    return 0;
}