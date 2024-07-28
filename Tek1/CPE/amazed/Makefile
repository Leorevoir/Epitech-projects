##
## EPITECH PROJECT, 2024
## B-CPE-200-STG-2-1-amazed-leo.quinzler
## File description:
## Makefile
##

CC = gcc

CFLAGS = -I./include -pedantic -Wall -Wextra -Werror -g3

SRC_DIR = src

OBJ_DIR = object

MAIN =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/matrice.c \
		$(SRC_DIR)/display.c \
		$(SRC_DIR)/create_room.c \
		$(SRC_DIR)/pathfinding.c \
		$(SRC_DIR)/print_moves.c

FREE_SRC = \
	$(SRC_DIR)/free/free.c

PARSE_SRC = \
	$(SRC_DIR)/parse/stock_file.c \
	$(SRC_DIR)/parse/parse_file.c

STRING_SRC = \
	$(SRC_DIR)/string/my_str.c \
	$(SRC_DIR)/string/my_trim.c \
	$(SRC_DIR)/string/my_memset.c \
	$(SRC_DIR)/string/my_strstr.c \
	$(SRC_DIR)/string/my_strtok.c \
	$(SRC_DIR)/string/my_strchr.c \
	$(SRC_DIR)/string/my_strncpy.c \
	$(SRC_DIR)/string/my_strndup.c \
	$(SRC_DIR)/string/str_to_array.c \
	$(SRC_DIR)/string/my_str_to_word_array.c

STDIO_SRC = \
	$(SRC_DIR)/stdio/print_my.c \
	$(SRC_DIR)/stdio/my_printf.c \
	$(SRC_DIR)/stdio/my_print_my.c

STDLIB_SRC = \
	$(SRC_DIR)/stdlib/my_atoi.c \
	$(SRC_DIR)/stdlib/my_memcpy.c \
	$(SRC_DIR)/stdlib/my_calloc.c \
	$(SRC_DIR)/stdlib/my_realloc.c

SRC = $(MAIN) $(STRING_SRC) $(STDIO_SRC) $(STDLIB_SRC) $(PARSE_SRC) \
	$(FREE_SRC)

OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

NAME = amazed

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
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
.PHONY: all clean fclean re
