/*
** corewar.h for COREWARE in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 16:21:13 2014 
** Last update Sun Apr 13 22:18:39 2014 dong_n
*/

#ifndef _COREWAR_H_
# define _COREWAR_H_

# include "op.h"

# define SUCCESS		1
# define FAILURE		-1
# define TRUE			1
# define FALSE			0
# define UNKNOWN		-1
# define GET_VALUE(s, type)	my_atoi(type >= T_IND ? s : &s[1])
# define SWAP(nbr)		convert_indian(&nbr, sizeof(nbr));
# define CODING_BYTE(n)		n != 1 && n != 9 && n != 12 && n != 14 ? 1 : 0
# define BAD_CHAR		"Error : '%c' is not a valid character.\n"

/*
** Structures
*/

typedef struct	s_param
{
  char		type;
  int		w_size;
  int		param;
  char		*l_flag;
}		t_param;

typedef struct	s_list
{
  t_param	param[MAX_ARGS_NUMBER];
  int		coding_byte;
  int		size;
  int		num;
  char		*label;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_args
{
  char		**args;
  char		*label;
}		t_args;

typedef struct	s_type
{
  char		type;
  char		value;
}		t_type;

void	convert_indian(void *, int);
int	get_coding_size(t_list *, int *);
int	get_real_size(int, int);
int	my_atoi(char *);
int	first_points(char *, header_t *);
char	**to_tab(char *, int, char);
void	double_free(char **ptr);
int	x_free(void *ptr);
int	param_type_verif(t_list *list, char *name);
int	get_every_label_value(t_list *list);
int	write_in_file(t_list *list, header_t *header, char *name);
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
int	add_elem_prev(t_list *elem, t_args *args, int num, char *name);
int	my_delete_elem(t_list *list);
int	line_parsing(t_args *args, t_list *list, char *name);
int	asm_parsing(header_t *, char **stock, char *name);
int	split_list(char *line, t_args *args);
int	which_instruction(char *str);
char	*epur_str(char *str);
char	**my_getfile(char *file, header_t *header);
int	my_verif_label(char *str);

#endif /* !COREWAR_H_ */
