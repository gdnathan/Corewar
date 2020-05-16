/*
** EPITECH PROJECT, 2020
** asm
** File description:
** compile_parameters
*/

#include "op.h"
#include "asm.h"
#include "my_macros.h"
#include "my_str.h"
#include "my_math.h"
#include <unistd.h>

char *my_memset(char c, int size)
{
    int i = 0;
    char *new = malloc(sizeof(char) * (size + 1));

    _malloc_error(new);
    while (i < size) {
        new[i] = c;
        i += 1;
    }
    return new;
}

char *set_param_bytecode(info_t *infos, instructions_t *tmp,
                                    int i, int bonus)
{
    int size = tmp->type[i] == direct ? 4 : 2;
    char *bytecode = my_memset('\0', size);

    tmp->parameters[i] += bonus;
    if (tmp->parameters[i][0] == ':') {
        printf("printing FF\n");
        static char c = 0xFF;
        return &c;
        //return label_adress();
    }
    bytecode[size] = my_getnbr(tmp->parameters[i]);
    return bytecode;
}

void print_parameters(info_t *infos, instructions_t *tmp, FILE *fp)
{
    int i = 0;
    int nbr = 0;
    char r_bytecode = '\0';
    char *bytecode = NULL;

    while (i < 4) {
        if (tmp->parameters[i] == NULL)
            break;
        if (tmp->parameters[i][0] == 'r') {
            printf("%d\n", my_getnbr(tmp->parameters[i] + 1));
            nbr = my_getnbr(tmp->parameters[i] + 1);
            r_bytecode = nbr;
            printf("btc: %d\n", r_bytecode);
            fwrite(&r_bytecode, 1, 1, fp);
        }
        if (tmp->parameters[i][0] == '$') {
            bytecode = set_param_bytecode(infos, tmp, i, 1);
            fwrite(bytecode, 1, my_strlen(bytecode), fp);
        }
        i += 1;
    }
}