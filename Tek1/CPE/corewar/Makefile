##
## EPITECH PROJECT, 2024
## B-CPE-200-STG-2-1-corewar-raphael.petrequin
## File description:
## Makefile
##

CC = gcc

CFLAGS = -I./include -g3 -pedantic

STDIO_DIR = src/stdio
STDLIB_DIR = src/stdlib
STRING_DIR = src/string
BYTES_DIR = src/bytes
PARSE_DIR = src/parse
CHAMP_DIR = src/champ
INSTRUCTIONS_DIR = src/instructions
DISPLAY_DIR = src/display
OBJ_DIR = object

MAIN =	src/main.c

STDIO =	\
	$(STDIO_DIR)/my_print_my.c \
	$(STDIO_DIR)/my_printf.c \
	$(STDIO_DIR)/print_my.c \
	$(STDIO_DIR)/my_error.c \
	$(STDIO_DIR)/print_hexa.c \
	$(STDIO_DIR)/my_sprintf.c \
	$(STDIO_DIR)/print_binary.c \

STDLIB = \
	$(STDLIB_DIR)/my_atoi.c \
	$(STDLIB_DIR)/my_calloc.c \
	$(STDLIB_DIR)/my_memcpy.c \
	$(STDLIB_DIR)/my_realloc.c

STRING = \
	$(STRING_DIR)/my_memset.c \
	$(STRING_DIR)/my_str_to_word_array.c \
	$(STRING_DIR)/my_str_to_word_array_spaces.c \
	$(STRING_DIR)/my_str.c \
	$(STRING_DIR)/my_strchr.c \
	$(STRING_DIR)/my_strncpy.c \
	$(STRING_DIR)/my_strndup.c \
	$(STRING_DIR)/my_strstr.c \
	$(STRING_DIR)/my_strtok.c \
	$(STRING_DIR)/my_isnum.c \
	$(STRING_DIR)/my_trim.c \
	$(STRING_DIR)/my_int_to_str.c \

BYTES = \
	$(BYTES_DIR)/my_htonl.c \
	$(BYTES_DIR)/my_htons.c \
	$(BYTES_DIR)/my_ntohl.c \
	$(BYTES_DIR)/my_ntohs.c

PARSE = \
	$(PARSE_DIR)/free.c \
	$(PARSE_DIR)/check_cor.c \
	$(PARSE_DIR)/parse_flags.c \
	$(PARSE_DIR)/parse_arguments.c

CHAMP = \
	$(CHAMP_DIR)/champ.c \
	$(CHAMP_DIR)/tools.c

INSTRUCTIONS = \
	$(INSTRUCTIONS_DIR)/tab.c \
	$(INSTRUCTIONS_DIR)/add.c \
	$(INSTRUCTIONS_DIR)/and.c \
	$(INSTRUCTIONS_DIR)/ld.c \
	$(INSTRUCTIONS_DIR)/lfork.c \
	$(INSTRUCTIONS_DIR)/lld.c \
	$(INSTRUCTIONS_DIR)/or.c \
	$(INSTRUCTIONS_DIR)/sti.c \
	$(INSTRUCTIONS_DIR)/xor.c \
	$(INSTRUCTIONS_DIR)/aff.c \
	$(INSTRUCTIONS_DIR)/fork.c \
	$(INSTRUCTIONS_DIR)/ldi.c \
	$(INSTRUCTIONS_DIR)/live.c \
	$(INSTRUCTIONS_DIR)/lldi.c \
	$(INSTRUCTIONS_DIR)/st.c \
	$(INSTRUCTIONS_DIR)/sub.c \
	$(INSTRUCTIONS_DIR)/zjmp.c

DISPLAY = \
	$(DISPLAY_DIR)/print_arena.c \
	$(DISPLAY_DIR)/loop.c \
	$(DISPLAY_DIR)/init_arena.c \
	$(DISPLAY_DIR)/arena_tools.c \
	$(DISPLAY_DIR)/fill_arena.c \
	$(DISPLAY_DIR)/print_info.c

SRC = $(MAIN) $(STDIO) $(STDLIB) $(STRING) op/op.c $(BYTES) $(PARSE) \
	$(CHAMP) $(INSTRUCTIONS) $(DISPLAY)

OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

NAME = corewar

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
