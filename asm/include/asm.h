/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

int fd_error(char *file, int fd);

typedef enum p_type {
    nope = 0,
    reg = 1,
    direct = 4,
    lil_dir = 3,
    indirect = 2
} p_type_t;

typedef struct instructions
{
    char *op_code;
    char *parameters[4];
    p_type_t type[4];
    int size;
    struct instructions *next;
    struct instructions *prev;
} instructions_t;


typedef struct label
{
    char *name;
    int adress;
    struct label *next;
} labels_t;

typedef struct info
{
    char *name;
    char *description;
    instructions_t *instruct;
    labels_t *label;
} info_t;

#endif /* !ASM_H_ */