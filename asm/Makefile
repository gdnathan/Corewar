##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for infadd prog
##

MAKEFLAGS += --no-print-directory

END=\x1b[0m
GREEN=\x1b[32;01m
RED=\x1b[31;01m
YELLOW=\x1b[33;

SRC		=	src/asm.c\
			src/error_handling.c\
			src/get_next_line.c\
			src/parse_basic_infos.c\
			src/parse_instructions.c\
			src/compile.c\
			src/labels.c\

MAIN	=	src/main.c

OBJ	    =	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=	asm

LIB     =	-L../lib/my -lmy

CFLAGS	=	-Iinclude -I../lib/my/include -O2 -g

WFLAGS		=	-W -Wall -Wextra -g

all:	DOLIB $(OBJ) $(NAME) message

message:
	@echo -en "\e[38;5;33m"
	@curl -s http://artii.herokuapp.com/make\?text\=$(NAME) || true
	@echo -e "\e[0m"

$(NAME):
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
	@$(MAKE) CLEAR

CLEAR:
	@mkdir -p build
	@mkdir -p debug
	@mv $(OBJ) build
	@[ -f vgcore* ] && mv vgcore.* debug || true

DOLIB:
	@$(MAKE) -C ../lib/my

clean:
	@rm -fv build/*
	@rm -fv $(OBJ)
	@$(MAKE) clean -C ../lib/my

debug:	fclean DOLIB $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(WFLAGS) $(LIB)
	@$(MAKE) CLEAR

test_run: fclean DOLIB
	$(CC) -o unit_tests $(SRC) $(LIB) $(CFLAGS) tests/test.c --coverage -lcriterion
	./unit_tests
	rm -fv *.gcda && rm *.gcdo
	rm -fv unit_tests

coverage:
	gcovr -exlude tests/
	gcovr -exlude tests/ --branches

fclean:	clean
	@rm -fv $(NAME) *.gc*
	@$(MAKE) fclean -C ../lib/my

re:	fclean all

%.o:    %.c
		@echo -n "Compiling... :"
		@$(CC) $(CFLAGS) -c $< -o $@ -g && echo -e " $< $(GREEN)[ OK ]$(END)" || echo -e " $< $(RED)[ KO ]$(END)"

.PHONY: all clean fclean re debug test DOLIB
