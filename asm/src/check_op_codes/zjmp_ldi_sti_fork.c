/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** zjmp_ldi_sti_fork
*/

#include "opcode_fptr.h"

int check_zjmp(char *opcode, p_type_t types[4])
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

int check_ldi(char *opcode, p_type_t types[4])
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

int check_sti(char *opcode, p_type_t types[4])
{
    if (types[0] != reg) {
        return 1;
    }
    if (types[1] == nope) {
        return 1;
    }
    if (types[2] != direct && types[2] != lil_dir && types[2] != reg) {
        return 1;
    }
    if (types[3] != nope) {
        return 1;
    }
    return 0;
}

int check_fork(char *opcode, p_type_t types[4])
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