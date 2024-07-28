##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/history.c	\
		src/linked_list.c	\
		src/minishell.c	\
		src/builtfonc.c	\
		src/builtins.c	\
		src/str_available.c	\
		src/shell_cmd.c	\
		src/env.c	\
		src/my_cd.c	\
		src/handle_exit.c	\
		src/my_signals.c	\
		src/clean_semicolon.c	\
		src/key_char.c	\
		src/my_pipe.c	\
		src/pipe_list.c	\
		src/pipe_path.c	\
		src/color.c	\
		src/separator_exec.c	\
		tool/my_putstr.c	\
		tool/my_strlen.c	\
		tool/my_strcmp.c	\
		tool/my_strncmp.c	\
		tool/my_strcat.c	\
		tool/my_strdup.c	\
		tool/my_strcpy.c	\
		tool/my_put_nbr.c	\
		tool/my_trim.c		\
		tool/my_str_to_word_array.c	\
		tool/my_str_to_word_array_condition.c \
		src/history_tool.c	\
		src/line_edition/auto_completion.c	\
		src/line_edition/arrow_setup.c	\
		src/line_edition/arrow_detection.c	\
		src/line_edition/tools.c	\
		src/redirections/superior.c \
		src/redirections/inferior.c \
		src/redirections/double_sup.c \
		src/redirections/double_inf.c \
		src/scripting/init_script.c \
		src/scripting/nona.c \
		src/scripting/my_echo.c \
		src/scripting/set_var.c \
		src/scripting/remove_var.c \
		src/scripting/calculator.c \
		src/scripting/calculator_parser.c \
		src/scripting/conditional.c \
		src/scripting/cwdcmd.c \
		src/scripting/scripting_tool.c \
		src/alias/create_alias.c \
		src/alias/remove_alias.c \
		src/alias/find_aliases.c \
		src/alias/bashrc_alias.c \
		src/scripting/mouli_bash/is_if_true.c \
		src/scripting/mouli_bash/parse_bash.c \
		src/scripting/mouli_bash/extract_str.c \
		src/scripting/mouli_bash/bash_scripting.c

OBJ	=	$(SRC:.c=.o)

CFLAGS += -g -I./include/

NAME	=	42sh

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc $(CFLAGS) -g -o $(NAME) $(OBJ) -L.
	@printf "[\033[1;32mSUCCESS\033[0m] Compiled %s\n" $(NAME)

clean:
	@rm -f $(OBJ)
	@printf "[\033[1;32mCLEAN\033[0m] Removed object\n"

fclean: clean
	@rm -f $(NAME)
	@rm -rf coding-style-reports.log
	@printf "[\033[1;32mFCLEAN\033[0m] Removed %s\n" $(NAME)

re: fclean all

.SILENT:
.PHONY: all clean fclean re
