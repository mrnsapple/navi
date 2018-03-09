##
## EPITECH PROJECT, 2017
##
## File description:
##
##

SRC 	=	navi.c			\
		my_puts.c		\
		my_put_nbr.c		\
		my_puts2.c		\
		get_next_line2.c	\
		get_next_line.c		\
		put_in_array.c		\
		main.c			\
		open_read_file.c	\
		print_map.c		\
		main_loop_parts.c	\
		main2.c			\
		create_map_base.c



OBJ	=	$(SRC:.c=.o)

NAME 	=	navy

RM	=	rm -f

all:	$(NAME)


$(NAME):	$(OBJ)
	gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	$(RM) $(NAME)

fclean:	clean
	rm -f $(OBJ) $(NAME) *~ *#

re:	fclean all
