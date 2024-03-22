##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile compilation for my_ls
##

SRC		=	src/my_ls.c					\
			src/my_put.c				\
			src/my_sort.c				\
			src/my_strcmp.c				\
			src/my_strdup.c				\
			src/my_details.c			\
			src/my_smart_ls.c			\
			src/my_printf.c				\

CFLAGS	=	-pedantic -Wall -w -Wextra -Werror

OBJ		=	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)

$(NAME):
		@gcc $(SRC) $(CFLAGS) -o $(NAME)

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)

re:	fclean all
