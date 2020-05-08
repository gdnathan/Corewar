/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_macros
*/

#ifndef MY_MACROS_H_
#define MY_MACROS_H_

#include <stdio.h>
#include <stdlib.h>

#define _malloc_error(ptr) \
    if (ptr == NULL) {\
        dprintf(2, "An erro occured while allocating memory.\n");\
        exit(84);\
    }\

#endif /* !MY_MACROS_H_ */