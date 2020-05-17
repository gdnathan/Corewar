/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** labels
*/

#include "asm.h"
#include "my_str.h"
#include <stdio.h>
#include "my_macros.h"

void label_path(instructions_t *tmp, instructions_t *instruct, labels_t *new)
{
    while (tmp->prev != NULL)
        tmp = tmp->prev;
    while (tmp != NULL) {
        new->adress += tmp->size;
        tmp = tmp->next;
    }
}

void new_label(labels_t **label, char *buffer, instructions_t *instruct)
{
    labels_t *new = malloc(sizeof(labels_t));
    instructions_t *tmp = instruct;
    labels_t *cpy = *label;

    _malloc_error(new);
    new->name = my_strdup_to_char(buffer, ':');
    new->adress = 0;
    new->next = NULL;

    if (instruct != NULL) {
        label_path(tmp, instruct, new);
    }
    if (*label == NULL)
        *label = new;
    else {
        while (cpy->next != NULL)
            cpy = cpy->next;
        cpy->next = new;
    }
}
