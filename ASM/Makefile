##
## Makefile for epur in /home/dong_n/rendu/epur
## 
## Made by dong_n
## Login   <dong_n@epitech.net>
## 
## Started on  Mon Mar 17 18:59:53 2014 dong_n
## Last update Mon Mar 17 23:56:07 2014 
##

CC	=	clang -O3 -g3

NAME	=	asm

SRC	=	src/epur.c		\
		src/asm.c		\
		src/op.c		\
		src/my_list.c		\
		src/parsing.c		\
		src/instruction_tab.c	\
		src/split_list.c

LIB	=	../lib/my_putchar.c	\
		../lib/my_putstr.c	\
		../lib/my_strlen.c	\
		../lib/my_put_nbr.c	\
		../lib/my_getnbr.c	\
		../lib/my_strcmp.c	\
		../lib/my_strcpy.c	\
		../lib/gnl.c	\
		../lib/xmalloc.c

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

CFLAGS	=	-I../includes/	#-W -Wall -Wextra -pedantic

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
