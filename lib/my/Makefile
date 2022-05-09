##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## a
##

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_putstr_2.c	\
		my_strlen.c	\
		my_put_nbr.c	\
		my_put_nbr_u.c	\
		my_convert_base.c	\
		my_revstr.c	\
		my_itoa.c	\
		my_atoi.c	\
		my_strcmp.c	\
		my_swap.c	\
		my_strcat.c	\
		my_strdup.c	\
		my_printf.c	\
		my_str_twa.c	\
		my_tabcat.c	\
		my_show_word_array.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS = -Wall -Wextra -g -Iincludes

all:	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
