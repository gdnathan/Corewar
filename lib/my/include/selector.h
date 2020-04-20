/*
** EPITECH PROJECT, 2018
** LIBMY
** File description:
** Multiple outcome matching system
*/

#ifndef __SELECTOR_H
#define __SELECTOR_H

///
/// \file       selector.h
/// \brief      Arbitrary outcome selection system
///
/// This module defines a logical branching system which relies on a
/// dynamically defined array of function pointers.
///

///
/// This macro runs through all elements in table (an array of selector_t), 
/// then once it hits a match, executes it with parameters params in brackets.
/// For example, a matching call for <tt>%SELECT(0, (1, 3), mytab)</tt> will
/// result in a function call equivalent to <tt>myfunc(1, 3)</tt>.
///
/// \brief          Select and execute a function from a list of outcomes
/// \param match    The variable to match against when selecting an outcome
/// \param params   In brackets, the parameters to pass to the called function
/// \param table    The array of {@link selector_t} describing 
///                 possible outcomes
/// \see   selector_t for the format of an outcome
///
#define SELECT(match, params, table)              \
    ({                                            \
        for (int sel = 0; table[sel].exec; sel++) \
            if (table[sel].cond == match)         \
                return (table[sel].exec params);  \
    })

///
/// This struct describes a single element in an array of outcomes, used in
/// macro {@link SELECT}. The macro will check against the cond member,
/// then call the exec member if it matches.
///
/// \brief          Description of an outcome in macro {@link SELECT}
/// \see   SELECT   is the macro that this struct is used in.
///
typedef struct {
    int cond;       /*!< \brief The value to match against when parsing.      */
    int (*exec)();  /*!< \brief Pointer to the function to run when matched.  */
} selector_t;

#endif //__SELECTOR_H
