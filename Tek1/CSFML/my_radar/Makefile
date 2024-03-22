##
## EPITECH PROJECT, 2023
## my_radar
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -g -Werror -pedantic

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

SRC =   main.c									\
		src/load/load_radar.c					\
		src/draw/draw_radar.c					\
		src/draw/draw_planes.c					\
		src/draw/draw_towers.c					\
		src/event/event_radar.c					\
		src/create/create_text.c				\
		src/create/create_radar.c				\
		src/create/create_planes.c				\
		src/create/create_towers.c				\
		src/planes/radar_planes.c				\
		src/towers/radar_towers.c				\
		src/utilities/my_split.c				\
		src/utilities/my_script.c				\
		src/utilities/my_string.c				\
		src/utilities/my_revstr.c				\
		src/utilities/my_number.c				\
		src/utilities/processing.c				\
		src/utilities/parse_lines.c				\
		src/utilities/radar_helper.c			\
		src/boarding/radar_start.c				\
		src/airport/update_radar.c				\
		src/airport/update_planes.c				\
		src/airport/update_status.c				\
		src/airport/collision_manager.c			\
		src/destroy/destroy_radar.c				\
		src/destroy/destroy_entities.c			\

OBJ_DIR = object

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

NAME = my_radar

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
