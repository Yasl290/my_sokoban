##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makethefile for my_sokoban
##

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):
	@echo "start program"
	make -C lib/my
	gcc -o $(NAME) sokoban.c -Llib/my -lmy -lncurses
	@echo "end program"

clean:
	make clean -C lib/my
	rm -f ./lib/my/*.a

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re: fclean all
