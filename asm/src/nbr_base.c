/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** put_nbr_base
*/

#include "op.h"
#include "asm.h"
#include "opcodes.h"
#include "my_str.h"
#include "my_macros.h"
#include <stdio.h>
#include <unistd.h>

int my_nbr_base(unsigned int nb, char *base)
{
    int mod;

    if (nb > 0) {
        mod = nb % my_strlen(base);
        my_putnbr_base(nb / my_strlen(base), base);
        my_putchar(base[mod]);
    }
}