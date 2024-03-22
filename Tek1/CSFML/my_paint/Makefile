##
## EPITECH PROJECT, 2024
## my_paint
## File description:
## Makefile
##

CC = gcc

CFLAGS = -I./include -Wall -Wextra -g3 -Werror -pedantic \

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm \

CC = gcc

SRC_DIR = src

OBJ_DIR = object

MAIN =	main.c \

DESTROY_SRC = \
	$(SRC_DIR)/destroy/free.c \
	$(SRC_DIR)/destroy/destroy.c

SAVE_SRC = \
	$(SRC_DIR)/save/new_file.c \
	$(SRC_DIR)/save/save_draw.c \
	$(SRC_DIR)/save/open_draw.c

DRAW_SRC = \
	$(SRC_DIR)/draw/tools.c \
	$(SRC_DIR)/draw/pencil.c \
	$(SRC_DIR)/draw/size_pixel.c \
	$(SRC_DIR)/draw/algo_pixel.c \
	$(SRC_DIR)/draw/algo_maths.c \
	$(SRC_DIR)/draw/form/trait.c \
	$(SRC_DIR)/draw/form/square.c \
	$(SRC_DIR)/draw/form/circle.c \
	$(SRC_DIR)/draw/update_mouse.c \
	$(SRC_DIR)/draw/file_edit_help.c \
	$(SRC_DIR)/draw/peinture/queue.c \
	$(SRC_DIR)/draw/form/draw_circle.c \
	$(SRC_DIR)/draw/peinture/peinture.c \
	$(SRC_DIR)/draw/form/draw_in_buffer.c

EVENT_SRC = \
	$(SRC_DIR)/event/color.c \
	$(SRC_DIR)/event/event.c \
	$(SRC_DIR)/event/popup.c \
	$(SRC_DIR)/event/key_event.c \
	$(SRC_DIR)/event/form_event.c \
	$(SRC_DIR)/event/open_event.c \
	$(SRC_DIR)/event/save_event.c \
	$(SRC_DIR)/event/mouse_event.c \
	$(SRC_DIR)/event/button_event.c \
	$(SRC_DIR)/event/color/color2.c \
	$(SRC_DIR)/event/color/color3.c \
	$(SRC_DIR)/event/color/color4.c \
	$(SRC_DIR)/event/color/color5.c \
	$(SRC_DIR)/event/color/color6.c

DISPLAY_SRC = \
	$(SRC_DIR)/display/help.c \
	$(SRC_DIR)/display/display.c \
	$(SRC_DIR)/display/is_visible.c \
	$(SRC_DIR)/display/text_prompt.c \
	$(SRC_DIR)/display/display_buttons.c

INIT_SRC = \
	$(SRC_DIR)/init/init_paint.c \
	$(SRC_DIR)/init/init_pencil.c \
	$(SRC_DIR)/init/init_window.c \
	$(SRC_DIR)/init/init_object.c

STRING_SRC = \
	$(SRC_DIR)/string/my_str.c \
	$(SRC_DIR)/string/my_strlen.c \
	$(SRC_DIR)/string/my_strstr.c \
	$(SRC_DIR)/string/my_strcat.c \
	$(SRC_DIR)/string/my_strtok.c \
	$(SRC_DIR)/string/my_strrchr.c \
	$(SRC_DIR)/string/my_strncpy.c \
	$(SRC_DIR)/string/my_strndup.c \
	$(SRC_DIR)/string/my_str_to_word_array_space.c \
	$(SRC_DIR)/string/my_str_to_word_array_line.c \

STDLIB_SRC = \
	$(SRC_DIR)/stdlib/my_getnbr.c \
    $(SRC_DIR)/stdlib/my_memcpy.c \
    $(SRC_DIR)/stdlib/my_realloc.c

PARSE_SRC = \
	$(SRC_DIR)/parse/action.c \
	$(SRC_DIR)/parse/create_circle.c \
	$(SRC_DIR)/parse/create_button.c \
	$(SRC_DIR)/parse/get_buttons_data.c

SRC = $(MAIN) $(DESTROY_SRC) $(DRAW_SRC) $(EVENT_SRC) \
    $(DISPLAY_SRC) $(INIT_SRC) $(STRING_SRC) $(SAVE_SRC) $(STDLIB_SRC) \
	$(PARSE_SRC)

OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

NAME = my_paint

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
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

.PHONY: all clean fclean re
