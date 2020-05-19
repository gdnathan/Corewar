##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for infadd prog
##

all:
	$(MAKE) -C asm/

clean:
	$(MAKE) clean -C asm/

fclean:
	$(MAKE) fclean -C asm/

re:
	$(MAKE) re -C asm/

.PHONY: all clean fclean re
