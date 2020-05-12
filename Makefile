##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for infadd prog
##

all:
	$(MAKE) -C generator/
	$(MAKE) -C corewar/

clean:
	$(MAKE) clean -C asm/
	$(MAKE) clean -C corewar/

fclean:
	$(MAKE) fclean -C asm/
	$(MAKE) fclean -C corewar/

re:
	$(MAKE) re -C asm/
	$(MAKE) re -C corewar/

.PHONY: all clean fclean re