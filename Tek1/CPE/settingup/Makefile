##
## EPITECH PROJECT, 2023
## my_radar
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -g -Werror -pedantic

SRC =   main.c						\
		src/print_my.c				\
		src/my_printf.c				\
		src/my_functions.c			\
		src/matrix.c				\
		src/indian_square.c			\

OBJ_DIR = object

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

NAME = setting_up

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $^
	@printf "[\033[1;32mSUCCESS\033[0m] Compiled %s\n" $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@printf "[\033[1;32mCLEAN\033[0m] Removed object directory\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f coding-style-reports.log
	@printf "[\033[1;32mFCLEAN\033[0m] Removed %s\n" $(NAME)

re: fclean all

.SILENT:
