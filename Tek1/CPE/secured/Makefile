##
## EPITECH PROJECT, 2024
## B-CPE-110-STG-1-1-secured-raphael.petrequin
## File description:
## Makefile
##

SRC	=	src/mini_printf/mini_printf.c		\
		src/mini_printf/my_putchar.c		\
		src/mini_printf/my_put_nbr.c		\
		src/mini_printf/my_putstr.c			\
		src/mini_printf/my_strlen.c			\
		src/handle_table/ht_search.c		\
		src/handle_table/ht_insert.c		\
		src/handle_table/ht_delete.c		\
		src/handle_table/ht_dump.c			\
		src/handle_hash/hash.c				\
		src/handle_hash/new_hashtable.c		\
		src/handle_hash/delete_hashtable.c	\

CFLAGS = -g -pedantic

OBJ	=	$(SRC:.c=.o)

NAME	=	libhashtable.a

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
