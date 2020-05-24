/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** lld_lldi_lfork_aff
*/

#include "opcode_fptr.h"

int check_lld(char *opcode, p_type_t types[4])
{
    if (types[0] != indirect && types[0] != direct && types[0] != lil_dir) {
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

int check_lldi(char *opcode, p_type_t types[4])
{
    if (types[0] == nope) {
        return 1;
    }
    if (types[1] != reg && types[1] != direct && types[1] != lil_dir) {
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

int check_lfork(char *opcode, p_type_t types[4])
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

int check_aff(char *opcode, p_type_t types[4])
{
    if (types[0] != reg) {
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