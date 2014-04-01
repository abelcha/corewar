/*
** vm.h for vm in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 30 12:52:14 2014 chalie_a
** Last update Mon Mar 31 23:01:11 2014 chalie_a
*/

#ifndef _VM_H_
# define _VM_H_

#include "corewar.h"

typedef struct		s_cmd
{
  int			op;
  int			*args_type[MAX_ARGS_NUMBER];
  int			*args_value[MAX_ARGS_NUMBER];
}			t_cmd;


typedef struct		s_line
{
  char			*filename;
  int			dump;
  int			prog_number;
  int			load_address;
}			t_line;

typedef struct		s_hd
{
  int			magic;
  char			prog_name[PROG_NAME_LENGTH + 1];
  int			prog_size;
  char			comment[COMMENT_LENGTH + 1];
}			t_hd;

typedef struct          s_champ
{

  char			*code;
  int			reg[REG_NUMBER];
  int			last_live_call;
  int			carry;
  int			pc;
  int			lol;
  t_hd			*header;
  t_cmd			*cmd;
  t_line		*line;
  struct s_champ	*next;
  struct s_champ	*prev;
}                       t_champ;

typedef struct		s_arena
{
  char			arena[MEM_SIZE + 1];
  int			cycle_delta;
  int			cycle_to_die;
  int			nbr_live;
}			t_arena;

int	option_error(int);
int	not_a_number(char *);
int	add_champs_in_list(t_champ *, char **);
void	convert_indian(int *, int);
int	is_number(char *);
int	fill_champs(t_champ *);

#endif /* !VM_H_ */
