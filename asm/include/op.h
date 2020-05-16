/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** op
*/

#ifndef OP_H_
#define OP_H_

// header

# define PROG_NAME_LENGTH        128
# define COMMENT_LENGTH          2048
// end <header>


static const char *no_params[4] = {
    "live",
    "zjmp",
    "fork",
    "lfork"
};

static const char *lil_ind[6] = {
    "ldi",
    "zjmp",
    "sti",
    "fork",
    "lldi",
    "lfork"
};

#endif /* !OP_H_ */
