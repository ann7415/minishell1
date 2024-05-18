##
## EPITECH PROJECT, 2024
## LIB
## File description:
## Makefile
##

SRC	=	my_getnbr.c				\
		my_put_nbr.c			\
		my_putchar.c			\
		my_putstr.c				\
		my_strlen.c				\
		my_strcmp.c				\
		my_strdup.c				\
		my_strndup.c			\
		my_strcpy.c				\
		my_strcat.c				\
		my_realloc.c			\
		my_array_len.c			\
		my_list_len.c			\
		my_count_char.c			\
		my_check_malloc.c		\
		is_arg_correct.c		\
		my_strncpy.c			\
		my_retrieve_str.c		\
		my_calloc.c				\
		nb_slash.c				\
		mini_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../../$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@cd ../../; rm -f $(NAME)

re:	fclean all
