/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** live_ld_st_add
*/

#include "opcode_fptr.h"

int check_live(char *opcode, p_type_t types[4])
{
    if (types[0] != direct && types[0] != lil_dir) {
        return 1;
    }
    if (types[1] != nope) {
        return 1;
    }
    if (types[2] != nope) {
        return 1;
    }
    if (types[3] != nope) {
        return 1;
    }
    return 0;
}

int check_ld(char *opcode, p_type_t types[4])
{
    if (types[0] != direct && types[0] != lil_dir) {
        return 1;
    }
    if (types[1] != reg) {
        return 1;
    }
    if (types[2] != nope) {
        return 1;
    }
    if (types[3] != nope) {
        return 1;
    }
    return 0;
}

int check_st(char *opcode, p_type_t types[4])
{
    if (types[1] != direct && types[0] != lil_dir && types[0] != reg) {
        return 1;
    }
    if (types[0] != reg) {
        return 1;
    }
    if (types[2] != nope) {
        return 1;
    }
    if (types[3] != nope) {
        return 1;
    }
    return 0;
}

int check_add(char *opcode, p_type_t types[4])
{
    if (types[0] != reg) {
        return 1;
    }
    if (types[1] != reg) {
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