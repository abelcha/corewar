/*
** vm.h for vm in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 30 12:52:14 2014 chalie_a
** Last update Wed Apr  2 20:19:55 2014 chalie_a
*/

#ifndef _VM_H_
# define _VM_H_

#include "corewar.h"

typedef struct		s_settings
{
  int			dump;
  int			mem_size;
  int			ctmo;
}			t_settings;

typedef struct		s_cmd
{
  int			op;
  int			args_type[MAX_ARGS_NUMBER];
  int			args_value[MAX_ARGS_NUMBER];
}			t_cmd;

typedef struct		s_line
{
  char			*filename;
  int			mem_size;
  int			prog_number;
  int			load_a;
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
  int			champ_nbr;
  char			*code;
  int			reg[REG_NUMBER];
  int			cycle;
  int			carry;
  int			pc;
  t_hd			*header;
  t_cmd			*cmd;
  t_line		*line;
  struct s_champ	*next;
  struct s_champ	*prev;
}                       t_champ;

typedef struct		s_arena
{
  int			total_size;
  int			nb_champs;
  int			mem_size;
  char			*arena;
  int			current_cycle;
  int			cycle_to_die;
  int			nbr_live;
}			t_arena;

t_arena	*init_arena(t_champ *, int);
int	option_error(int);
int	not_a_number(char *);
int	add_champs_in_list(t_champ *, char **, t_settings *);
void	convert_indian(int *, int);
int	is_number(char *);
int	fill_champs(t_champ *);
int	shw_list(t_champ *root);
void	display_arena(char *str, int);
void	display_sets(t_settings *sets);
int	start_battle(t_champ *root, t_arena *arena, t_settings *sets);

#endif /* !VM_H_ */
