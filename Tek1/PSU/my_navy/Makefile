##
## EPITECH PROJECT, 2023
## my_radar
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -g -Werror -pedantic

SRC =   main.c										\
		src/my_navy.c								\
		src/my_grid.c								\
		src/read_map.c								\
		src/create_map.c							\
		src/is_finished.c							\
		src/attack_handling.c						\
		src/signal_handling.c 						\
		src/binary_handling.c						\
		src/handle_error.c							\
		src/my_check_file.c							\
		src/my_utilities/my_help.c					\
		src/my_utilities/my_atoi.c					\
		src/my_utilities/print_my.c					\
		src/my_utilities/my_strtok.c				\
		src/my_utilities/my_getnbr.c				\
		src/my_utilities/my_strcmp.c				\
		src/my_utilities/my_printf.c				\
		src/my_utilities/my_putget.c				\

OBJ_DIR = object

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

NAME = my_navy

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
