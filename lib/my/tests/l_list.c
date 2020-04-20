/*
** EPITECH PROJECT, 2019
** LIBMY TESTS
** File description:
** Unit tests for the linked list system
*/

#include <criterion/criterion.h>
#include "../include/l_list.h"

Test(l_list, l_push)
{
    l_elem_t *sample = l_create(NULL);

    l_push(sample, "Hello");
    l_push(sample, "Middle");
    cr_assert_str_eq(l_walk(sample, 2)->prev->value, "Middle");
}

Test(l_list, l_pop)
{
    l_elem_t *sample = l_create(NULL);

    l_push(sample, "Hello");
    l_push(sample->next, "World");
    l_pop(sample->next);
    cr_assert_str_eq(sample->next->value, "World");
}

Test(l_list, l_walk)
{
    l_elem_t *sample = l_create(NULL);

    l_push(sample, "Hello");
    l_push(sample->next, "World");
    cr_assert_str_eq(l_walk(sample, 1)->value, "Hello");
}

Test(l_list, l_walk_neg)
{
    l_elem_t *sample = l_create(NULL);
    l_elem_t *source;

    l_push(sample, "Hello");
    l_push(sample->next, "World");
    source = l_walk(sample, 2);
    cr_assert_eq(l_walk(source, -2), sample);
}

Test(l_list, l_walk_overrun)
{
    l_elem_t *sample = l_create(NULL);

    l_push(sample, "Hello");
    l_push(sample->next, "World");
    cr_assert_str_eq(l_walk(sample, 4)->value, "World");
}
