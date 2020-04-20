/*
** EPITECH PROJECT, 2018
** L_LIST
** File description:
** A linked list system
*/

#ifndef __L_LIST_H
#define __L_LIST_H

///
/// \file       l_list.h
/// \brief      General-purpose double-linked list definition
///
/// This file contains function definitions for a general-purpose
/// double-linked list in C. Use the functions provided below as they are
/// guaranteed memory-safe.
///

///
/// This struct represents a general-purpose, double-linked list. The value
/// member is not actively used by the functions in this library, it simply
/// serves as a value store for that element.
///
/// \brief          The defining element of the linked list system
///
typedef struct l_list {
    void *value;         /*!< \brief The value to store in the element.   */
    struct l_list *prev; /*!< \brief The pointer to the previous element. */
    struct l_list *next; /*!< \brief The pointer to the next element.     */
} l_elem_t;

///
/// Creates a new, zeroed linked list element, with the given value.
/// Useful to ensure memory safety when using {@link l_push}, for example.
///
/// \brief          Create a new linked list element
/// \param value    The value to initialize the element with
/// \return         A pointer to the created element
///
l_elem_t *l_create(void *value);

///
/// "Walks" along a given linked list element - that is, follows the next
/// or prev pointer a certain number of times. This function will stop
/// if it reaches the beginning or end of the list.
/// For example, <tt>l_walk(mylist, 3)</tt> will advance by three elements
/// forward, while <tt>l_walk(mylist, -2)</tt> will advance by two elements
/// backwards.
///
/// \brief          Navigate a linked list by a certain offset
/// \param elem     The linked list element from which to navigate
/// \param offset   The number of elements to advance forward or backwards
/// \return         A pointer to the element that the function landed on
///
l_elem_t *l_walk(l_elem_t *elem, int offset);

///
/// Removes a linked list element from its list, and reconnects the
/// previous and next elements to each other. The element is automatically
/// <tt>free()</tt>'d by this function
///
/// \brief          Remove an element from its linked list
/// \param elem     The element to remove
///
void l_pop(l_elem_t *elem);

///
/// Adds a new linked list element to an existing list, inserted right after 
/// the specified element, and reconnects the previous and next elements 
/// to it. The new element inherits the value given as a second argument.
///
/// \brief          Insert a new element into an existing linked list
/// \param elem     The element after which the new value should be added
/// \param value    The value to assign to the new element
/// \return         A pointer to the created element
///
l_elem_t *l_push(l_elem_t *elem, void *value);

#endif //__L_LIST_H
