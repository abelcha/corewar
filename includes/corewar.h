/*
** corewar.h for COREWARE in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 16:21:13 2014 
** Last update Thu Apr  3 00:30:28 2014 chalie_a
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

# define OP_LIVE	1
# define OP_LD		2
# define OP_ST		3
# define OP_ADD		4
# define OP_SUB		5
# define OP_AND		6
# define OP_OR		7
# define OP_XOR		8
# define OP_ZJMP	9
# define OP_LDI		10
# define OP_STI		11
# define OP_FORK	12
# define OP_LLD		13
# define OP_LLDI	14
# define OP_LFORK	15
# define OP_AFF		16


# define		GET_VALUE(s, type) my_atoi(type >= T_IND ? s : &s[1])
# define		SWAP(nbr) convert_indian(&nbr, sizeof(nbr));

void			convert_indian(void *, int);

int	line;

#define A printf("AAAAAAAAA\n");
#define O printf("OOOOOOOOO\n");
#define X printf("XXXXXXX\n");
#define Z printf("ZZZZZZZZZ\n");
#define VALID_CHAR	"\t :%;#,"
#define EXT_CHAR	"+-*/%"
#define NO_EXT		"Error : \".extended\" needed to use %c operation.\n"
#define BAD_CHAR	"Error : '%c' is not a valid character.\n"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
# include "op.h"
#include "my.h"

typedef struct s_info
{
  char  filename[128];
  char  comment[2048];
} t_info;

int	get_coding_size(t_list *, int *);
int	get_real_size(int, int);
int	my_atoi(char *);
int	first_points(char *, t_info *);
char	**to_tab(char *, int, char);
int	my_strcpy(char *, char *, int);
void	double_free(char **);
char	*my_strdup(char *);
int	x_free(void *);
int	param_type_verif(t_param *, t_list *);
int	get_every_label_value(t_list *);
int	write_in_file(t_list *, t_info *);
int	get_value(char *, int);
int	remplace_label(t_list *);
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
int	asm_parsing(t_info *, t_list *list, char **stock);
int	split_list(char *line, t_args *args);
int	which_instruction(char *str);
char	*epur_str(char *str);


#endif /* !COREWAR_H_ */
