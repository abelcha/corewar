##
## Makefile for make in /home/dong_n/rendu/corewar
## 
## Made by dong_n
## Login   <dong_n@epitech.net>
## 
## Started on  Sun Apr 13 22:38:36 2014 dong_n
## Last update Sun Apr 13 22:38:37 2014 dong_n
##

CC	=	cc

ASM	=	ASM/asm

VM	=	VM/corewar

SRCASM	=	ASM/src/epur.c			\
		ASM/src/main.c			\
		ASM/src/my_getfile.c		\
		ASM/src/get_params.c		\
		ASM/src/my_list.c		\
		ASM/src/write.c			\
		ASM/src/parsing.c		\
		ASM/src/oct.c			\
		ASM/src/cut_elem.c		\
		ASM/src/label.c			\
		ASM/src/x_open.c		\
		ASM/src/double_free.c		\
		ASM/src/numbers.c		\
		ASM/src/find_label.c		\
		ASM/src/verif.c			\
		ASM/src/instruction_tab.c	\
		ASM/src/split_list.c		\
		op.c

SRCVM	=	VM/src/main.c			\
                VM/src/fill_champs.c		\
                VM/src/add_champs.c		\
                VM/src/vm_error.c		\
                VM/src/fill_arena.c		\
                VM/src/start_battle.c		\
                VM/src/get_instructions.c	\
                VM/src/fork.c			\
                VM/src/jump_aff.c		\
                VM/src/live.c			\
                VM/src/utils.c			\
                VM/src/dump.c			\
                VM/src/end_battle.c		\
                VM/src/load.c			\
                VM/src/operations.c		\
		VM/src/store.c			\
                VM/src/exec_instructions.c	\
                op.c

SRCLIB	=	lib/my_putchar.c	\
		lib/my_putstr.c		\
		lib/my_strlen.c		\
		lib/my_put_nbr.c	\
		lib/x_error.c		\
		lib/my_calloc.c		\
		lib/my_getnbr.c		\
		lib/my_strncmp.c	\
		lib/my_strcmp.c		\
		lib/convert_indian.c	\
		lib/my_strcpy.c		\
		lib/my_strncpy.c	\
		lib/my_strdup.c		\
		lib/my_strndup.c	\
		lib/my_strcat.c		\
		lib/gnl.c		\
		lib/xmalloc.c

OBJASM	=	$(SRCASM:.c=.o)

OBJVM	=	$(SRCVM:.c=.o)

OBJLIB	=	$(SRCLIB:.c=.o)

CFLAGS	=	-I./includes/

RM	=	rm -f

all	:	$(ASM) $(VM)

$(ASM)	:	$(OBJASM) $(OBJLIB)
		$(CC) -o $(ASM) $(OBJASM) $(OBJLIB)

$(VM)	:	$(OBJVM) $(OBJLIB)
		$(CC) -o $(VM) $(OBJVM) $(OBJLIB)

clean	:
		$(RM) $(OBJASM)
		$(RM) $(OBJVM)
		$(RM) $(OBJLIB)

fclean	:	clean
		$(RM) $(ASM)
		$(RM) $(VM)

re	:	fclean all

.PHONY	:	all clean fclean re
