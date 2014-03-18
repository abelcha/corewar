##
## Makefile for epur in /home/dong_n/rendu/epur
## 
## Made by dong_n
## Login   <dong_n@epitech.net>
## 
## Started on  Mon Mar 17 18:59:53 2014 dong_n
## Last update Mon Mar 17 21:06:27 2014 dong_n
##

CC	=	clang -O3

NAME	=	epur

SRC	=	src/main.c \
		library/my_putchar.c \
		library/my_putstr.c \
		library/my_strlen.c \
		library/my_put_nbr.c \
		library/my_getnbr.c \
		library/my_strcmp.c \
		library/my_strcpy.c \
		library/get_next_line.c \
		library/xmalloc.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/ \
		-W -Wall -Wextra -pedantic

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -lefence -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
