##
## EPITECH PROJECT, 2024
## Epitech-projects
## File description:
## Makefile
##

SRC	=	*.c

CFLAGS = -g -pedantic

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

%.o:	%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "[\033[1;32mSUCCESS\033[0m] Compiled %s\n" $(NAME)

clean:
	@rm -f $(OBJ)
	@printf "[\033[1;32mCLEAN\033[0m] Removed object directory\n"

fclean:	clean
	@rm -f $(NAME)
	@rm -f coding-style-reports.log
	@printf "[\033[1;32mFCLEAN\033[0m] Removed %s\n" $(NAME)

re:		all clean
