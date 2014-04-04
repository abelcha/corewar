##
## Makefile for epur in /home/dong_n/rendu/epur
## 
## Made by dong_n
## Login   <dong_n@epitech.net>
## 
## Started on  Mon Mar 17 18:59:53 2014 dong_n
## Last update Thu Apr  3 13:24:20 2014 dong_n
##

CC	=	clang -O3 -g3

NAME	=	vm

SRC	=	src/main.c \
		src/convert_base.c

LIB	=	../lib/my_putchar.c	\
		../lib/my_put_nbr.c	\
		../lib/convert_indian.c	\
		../lib/x_error.c	\
		../lib/my_getnbr.c	\
		../lib/my_strcmp.c	\
		../lib/my_strdup.c	\
		../lib/my_strcpy.c	\
		../lib/gnl.c		\
		../lib/xmalloc.c	\
		../my_printf/printf1.c	\
		../my_printf/printf2.c

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

CFLAGS	=	-I../includes/ -W -Wall -Wextra -pedantic

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
