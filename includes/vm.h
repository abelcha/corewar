/*
** vm.h for vm in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 30 12:52:14 2014 chalie_a
** Last update Thu Apr 10 23:53:01 2014 chalie_a
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
  int			cycle_to_die;
  int			cycle;
  int			carry;
  char			new_pc;
  int			pc;
  t_hd			*header;
  t_cmd			*cmd;
  t_line		*line;
  struct s_champ	*next;
  struct s_champ	*prev;
}                       t_champ;

typedef struct		s_arena
{
  t_champ		*winner;
  int			total_size;
  int			nb_champs;
  int			mem_size;
  char			*arena;
  int			current_cycle;
  int			cycle_to_die;
  int			nbr_live;
}			t_arena;

typedef int		(*ptrft)(t_champ *champ, t_arena *arena);

#define DEAD	485123
#define DUMP    542639
#define  ABS(x, s) x = (x < 0 ? -x : x) % s
// Ce qui est contenu dans le registre X                                                                              
#define REG_VALUE(x) ABS(champ->cmd->args_value[x - 1], 16)
// Le registre cité dans le Xeme argument                                                                             
#define REG_NBR(x) champ->reg[ABS(champ->cmd->args_value[x - 1], 16)]


int     ins_live(t_champ *, t_arena *);
int     ins_ld(t_champ *, t_arena *);
int     ins_st(t_champ *, t_arena *);
int     ins_zjmp(t_champ *, t_arena *);
int     ins_ldi(t_champ *, t_arena *);
int     ins_sti(t_champ *, t_arena *);
int     ins_fork(t_champ *, t_arena *);
int     ins_aff(t_champ *, t_arena *);
int     ins_operation(t_champ *, t_arena *);
t_champ	*init_champ();
int	get_instruction(char *, t_champ *);
t_arena	*init_arena(t_champ *, int);
int	option_error(int);
int	not_a_number(char *);
int	add_champs_in_list(t_champ *, char **, t_settings *);
void	convert_indian(void *, int);
int	is_number(char *);
int	fill_champs(t_champ *);
int	shw_list(t_champ *root);
void	display_arena(char *str, int);
void	display_sets(t_settings *sets);
int	start_battle(t_champ *root, t_arena *arena, t_settings *sets);
int	exec_command(t_champ *, t_arena *);
int	delete_elem(t_champ *champ);
#endif /* !VM_H_ */
