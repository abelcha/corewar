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
		src/get_params.c	\
		src/op.c		\
		src/my_list.c		\
		src/parsing.c		\
		src/oct.c		\
		src/show_list.c		\
		src/x_open.c		\
		src/instruction_tab.c	\
		src/split_list.c

LIB	=	../lib/my_put_nbr.c	\
		../lib/x_error.c	\
		../lib/my_getnbr.c	\
		../lib/my_strcmp.c	\
		../lib/my_strcpy.c	\
		../lib/gnl.c		\
		../lib/xmalloc.c	\
		../my_printf/printf1.c	\
		../my_printf/printf2.c
	
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
