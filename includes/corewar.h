/*
** corewar.h for COREWARE in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 16:21:13 2014 
** Last update Fri Mar 21 04:53:28 2014 chalie_a
*/

#ifndef _COREWAR_H_
# define _COREWAR_H_

#define SUCCESS	1
#define FAILURE	-1
#define TRUE	1
#define FALSE	0
#define UNKNOWN	-1
/*
** TEMPORARY DEFINES
*/
#define X printf("lol\n");
#define Z printf("HERE\n");
#define VALID_CHAR	"\t :%;#,"
#define EXT_CHAR	"+-*/%"
#define NO_EXT		"Error : \".extended\" needed to use %c operation.\n"
#define BAD_CHAR	"Error : '%c' is not a valid character.\n"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
# include "op.h"


typedef struct s_info
{
  char  filename[128];
  char  comment[2048];
} t_info;


int	get_type(char *, int);
int	get_value(char *, int);
int	remplace_label(t_list *);
int	get_coding_size(t_list *);
int	get_param_info(t_list *, t_args *, int);
int	get_coding_byte(t_list *list);
t_list	*init_list(void);
void	show_list(t_list *);
int	open_file(char *);
int	my_printf(const char *format, ...);
int	my_fprintf(int fds, const char *format, ...);
int     get_param_value(char *str, int num);
int     get_param_type(char *str, int num);
int	add_elem_prev(t_list *elem, t_args *args, int num);
int	add_elem_next(t_list *elem, t_args *args, int num);
int	my_delete_elem(t_list *list);
int	line_parsing(t_args *args, t_list *list);
int	asm_parsing(t_list *list, char **stock);
int	split_list(char *line, t_args *args);
int	which_instruction(char *str);
char	*epur_str(char *str);


#endif /* !COREWAR_H_ */
