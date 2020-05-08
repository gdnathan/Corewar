/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

int fd_error(char *file, int fd);

typedef struct instructions
{
    char *optional_label;
    char *op_code;
    char *parameters;
    struct instructions *next;
    struct instructions *prev;
} instructions_t;

typedef struct info
{
    char *name;
    char *description;
    instructions_t *instruct;
} info_t;

#endif /* !ASM_H_ */