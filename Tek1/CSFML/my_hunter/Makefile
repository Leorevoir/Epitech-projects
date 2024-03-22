##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile hunter
##

LIB_DIR =   ./lib/my

SRC =	main.c				\
		src/menu.c			\
		src/bird.c			\
		src/event.c			\
		src/window.c		\
		src/menu_event.c	\
		src/string_score.c	\

OBJ =   $(SRC:.c=.o)

NAME    =   libmy.a

GAME	=	my_hunter

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -g -o $(GAME) $(SRC) -lcsfml-window -lcsfml-graphics -lcsfml-system

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(GAME)

re:	fclean all
