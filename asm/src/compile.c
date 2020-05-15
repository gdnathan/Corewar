/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** compile
*/

#include "op.h"
#include "asm.h"
#include "opcodes.h"
#include "my_str.h"
#include "my_macros.h"
#include <stdio.h>
#include <unistd.h>

int my_nbr_base(unsigned int nb, char *base);

const char myMAGIC[4] = {0x00, 0xEA, 0x83, 0xF3};

int compile_header(info_t *info, FILE *fp)
{
    int i = 0;

    fwrite(myMAGIC, 1, 4, fp);
    fwrite(info->name, 1,  my_strlen(info->name), fp);
    while (i++ < PROG_NAME_LENGTH - my_strlen(info->name))
        fwrite("\0", 1, 1, fp);
    i = 0;
    while (i++ < 8)
        fwrite("\0", 1, 1, fp);
    fwrite(info->description, 1, my_strlen(info->description), fp);
    i = 0;
    while (i++ < COMMENT_LENGTH - my_strlen(info->description) + 4)
        fwrite("\0", 1, 1, fp);
}

char *found_instruct_code(char *opcode)
{
    int i = 0;
    static char c = '\0';


    while (opcodes_template[i]) {
        if (my_strcmp(opcode, opcodes_template[i]) == 1) {
            c = core_opcodes[i];
            return &c;
        }
        i += 1;
    }
    write(2, "error\n", 6);
}

char *dec_to_hex(int nb)
{
    char *hex = malloc(sizeof(char) * 2);

    _malloc_error(hex);
    hex[0] = (nb / 16 + 48);
    if (nb % 16 > 9) {
        hex[1] = (nb % 16) + 87;
    } else if (nb % 16 >= 0) {
        hex[1] = nb % 16 + 48;
    }
    return hex;
}

char *param_type(p_type_t type[4])
{
    int i = 0;
    unsigned int bits = 0;

    while (i < 4) {
        switch (type[i]) {
            case reg:
                bits += 1;
                break;
            case direct:
            case lil_dir:
                bits += 2;
                break;
            case indirect:
                bits += 3;
                break;
        }
        if (i < 3)
            bits = bits << 2;
        i += 1;
    }
    return dec_to_hex(bits);
}

int compile_instruction(info_t *infos, FILE *fp)
{
    instructions_t *tmp = infos->instruct;
    int i = 0;

    while (tmp != NULL) {
        fwrite(found_instruct_code(tmp->op_code), 1, 1, fp);
        while (i < 4) {
            if (my_strcmp(tmp->op_code, no_params[i]) == 1)
                break;
            i += 1;
        }
        if (i == 4) {
            fwrite(param_type(tmp->type), 1, 1, fp);
        }
        i = 0;
        tmp = tmp->next;
    }
}
