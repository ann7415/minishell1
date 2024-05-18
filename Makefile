##
## EPITECH PROJECT, 2024
## stump
## File description:
## Makefile
##

CC	=	gcc

NAME	=	mysh

UNIT_TESTS	=	test

CFLAGS	=	-I./include -Wall -Wshadow

LDFLAGS	=	libmy.a

CRITERION	=	tests/test_libc.c tests/test_minish.c --coverage -lcriterion

SRC	=	src/main.c									\
		src/parse.c									\
		src/main_loop.c								\
		src/execute_builtin.c						\
		src/linked_lists/list.c						\
		src/linked_lists/manage_list.c				\
		src/linked_lists/node.c						\
		src//linked_lists/array_2_linked_list.c 	\
		src//linked_lists/linked_list_2_array.c		\
		src/env_variable/env_variable.c 			\
		src/env_variable/manage_env_variable.c 		\
		src/execute_command.c						\
		src/builtin_commands/cd.c					\
		src/builtin_commands/env.c					\
		src/builtin_commands/setenv.c				\
		src/builtin_commands/unsetenv.c				\
		src/builtin_commands/exit.c					\

SRCTEST	=	lib/my/mini_printf.c						\
			lib/my/my_getnbr.c							\
			lib/my/my_put_nbr.c							\
			lib/my/my_putchar.c							\
			lib/my/my_putstr.c							\
			lib/my/my_strcmp.c							\
			lib/my/my_strdup.c							\
			lib/my/my_strlen.c							\
			lib/my/my_strcpy.c							\
			lib/my/my_strcat.c							\
			lib/my/my_count_char.c						\
			lib/my/my_check_malloc.c					\
			lib/my/my_calloc.c							\
			lib/my/is_arg_correct.c						\
			lib/my/my_list_len.c						\
			src/linked_lists/list.c						\
			src/linked_lists/manage_list.c				\
			src/linked_lists/node.c						\
			src/env_variable/env_variable.c 			\
			src/env_variable/manage_env_variable.c 		\


OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	@echo -e "\e[1m\e[36mBuilding $(NAME)...\e[0m"
	@$(MAKE) -C ./lib/my > /dev/null 2>&1
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	@echo -e "\e[1m\e[37mBinary ready!\e[0m"

$(UNIT_TESTS):	fclean
	@$(CC) -o $(UNIT_TESTS) $(SRCTEST) $(CRITERION) $(CFLAGS)

tests_run:	$(UNIT_TESTS)
	@echo -e "\e[1m\e[32m$(UNIT_TESTS) ready !\e[0m"
	@./$(UNIT_TESTS)
	@gcovr --exclude tests/

clean:
	@$(MAKE) clean -C ./lib/my > /dev/null 2>&1
	@rm -f $(OBJ)
	@rm -f *.gc*
	@rm -f coding-style-reports.log
	@rm -f vgcore.*

fclean: clean
	@$(MAKE) fclean -C ./lib/my > /dev/null 2>&1
	@rm -f $(NAME)
	@rm -f $(UNIT_TESTS)

re: fclean all
