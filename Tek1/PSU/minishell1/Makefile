##
## EPITECH PROJECT, 2024
## B-PSU-200-STG-2-1-bsminishell1-leo.quinzler
## File description:
## Makefile
##

CC = gcc

CFLAGS = -I./include -Wall -Wextra -Werror -g -pedantic

READ = \
	src/read/read_line.c \
	src/read/add_to_arguments.c

CMD = \
	src/cmd/cd.c \
	src/cmd/path.c \
	src/cmd/maping.c \
	src/cmd/signal.c \
	src/cmd/check_cmd.c \
	src/cmd/process_cmd.c \
	src/cmd/execute_cmd.c

MEMORY = \
	src/memory/free.c \
	src/memory/my_memcpy.c \
	src/memory/my_realloc.c

STDIO = \
	src/stdio/print_my.c \
	src/stdio/my_printf.c \
	src/stdio/my_print_my.c

ENV = \
	src/env/setenv.c \
	src/env/getenv.c \
	src/env/unsetenv.c \
	src/env/env.c

MAIN = \
	main.c

SEGFAULT = \
	src/segfault/no_segfault.c

STRING = \
	src/string/my_strrchr.c \
	src/string/my_strdup.c

LOOP = \
	src/loop/shell_loop.c

SRC = $(READ) $(CMD) $(MEMORY) $(STDIO) $(ENV) $(MAIN) $(SEGFAULT) \
	$(STRING) $(LOOP)

OBJ_DIR = object

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

NAME = mysh

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
