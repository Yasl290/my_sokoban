##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

SRC	=	my_compute_power_rec.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strdup.c	\
		my_revstr.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strncpy.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_unsigned_nbr.c	\
		my_unsigned_o.c	\
		funct_mini_printf.c	\
		my_printf.c	\
		printf_flags.c	\
		unsigned_flags.c	\
		my_unsigned_x.c	\
		my_unsigned_upperx.c	\
		get_flags.c	\
		padding.c	\
		padding_char.c	\
		print_f.c	\
		print_upperf.c	\
		starting_sokoban.c	\
		soko_file.c	\
		display_map.c	\
		pos_map.c	\
		move_elements.c	\
		file_rp.c	\
		map_up.c	\
		handle_char.c	\
		game_loop.c	\
		move_player.c	\
		follow_rp.c	\
		fill_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	+=	-Wall -Wextra -I include/ -Llib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo "start"
	ar rc libmy.a $(OBJ)
	@echo "end"

clean:
	rm  $(OBJ)

fclean:
	rm libmy.a

re:	fclean $(NAME)
