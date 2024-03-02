##
## EPITECH PROJECT, 2023
## sokoban
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -Iinclude -L. -l:./libmy.a -ggdb3

SRC_PATH = src/

SRC = \
	$(SRC_PATH)main.c \
	$(SRC_PATH)args_handler.c \
	$(SRC_PATH)system_cmd.c \
	$(SRC_PATH)commands.c \
	$(SRC_PATH)bin_path_handler.c \
	$(SRC_PATH)error_handling.c \

OBJ = $(SRC:.c=.o)

LIB_PATH = ./lib/my/

NAME = mysh

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[32m[OK]\033[0m": $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f coding-style-reports.log
	@rm -f *.gcno *.gcda *.gcov vgcore.*
	@echo -e "\033[31m[RM]\033[0m": $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) $@
	@echo -e "\033[31m[RM]\033[0m": $(NAME)

re: fclean all

.PHONY: all clean fclean re
