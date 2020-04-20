/*
** EPITECH PROJECT, 2018
** L_LIST
** File description:
** A linked list system
*/

#include <stdlib.h>
#include "../include/l_list.h"

l_elem_t *l_create(void *value)
{
    l_elem_t *ret = malloc(sizeof(l_elem_t));

    ret->value = value;
    ret->next = 0;
    ret->prev = 0;
    return (ret);
}

l_elem_t *l_walk(l_elem_t *elem, int offset)
{
    l_elem_t *ret = elem;

    while (offset < 0) {
        if (ret->prev)
            ret = ret->prev;
        offset++;
    }
    while (offset > 0) {
        if (ret->next)
            ret = ret->next;
        offset--;
    }
    return (ret);
}

l_elem_t *l_push(l_elem_t *elem, void *value)
{
    l_elem_t *ret = malloc(sizeof(l_elem_t));

    ret->next = elem->next;
    elem->next = ret;
    ret->prev = elem;
    if (ret->next)
        ret->next->prev = ret;
    ret->value = value;
    return (ret);
}

void l_pop(l_elem_t *elem)
{
    if (elem->prev)
        elem->prev->next = elem->next;
    if (elem->next)
        elem->next->prev = elem->prev;
    free(elem);
}

