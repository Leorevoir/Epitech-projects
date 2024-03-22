##
## EPITECH PROJECT, 2024
## B-PSU-100-STG-1-1-sokoban-leo.quinzler
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -g -Werror -pedantic

LDFLAGS = -lncurses

SRC = main.c \
      src/my_str.c \
      src/my_game.c \
	  src/init_map.c \
      src/my_sokoban.c \
      src/update_game.c \
      src/destroy_game.c \
	  src/init_positions.c \
	  src/init_character.c \
      src/player_movements.c

OBJ_DIR = object
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

NAME = my_sokoban

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LDFLAGS)
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
