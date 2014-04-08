##
## Makefile for epur in /home/dong_n/rendu/epur
## 
## Made by dong_n
## Login   <dong_n@epitech.net>
## 
## Started on  Mon Mar 17 18:59:53 2014 dong_n
## Last update Tue Apr  8 17:11:31 2014 chalie_a
##

CC	=	clang -g3

NAME	=	vm

SRC	=	src/main.c			\
		src/fill_champs.c	\
		src/add_champs.c	\
		src/vm_error.c		\
		src/fill_arena.c	\
		src/start_battle.c	\
		src/show.c			\

LIB	=	../lib/my_put_nbr.c	\
		../lib/x_error.c	\
		../lib/my_getnbr.c	\
		../lib/my_strcmp.c	\
		../lib/my_strdup.c	\
		../lib/my_strcpy.c	\
		../lib/gnl.c		\
		../lib/to_tab.c		\
		../lib/my_putchar.c	\
		../lib/convert_indian.c	\
		../lib/xmalloc.c	\
		../my_printf/printf1.c	\
		../my_printf/printf2.c

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

CFLAGS	=	-I../includes/	-W -Wall -Wextra -pedantic

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
