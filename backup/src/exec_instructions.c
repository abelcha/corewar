/*
** exec_instructions.c for lol in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue Apr  8 18:31:31 2014 chalie_a
** Last update Tue Apr  8 20:46:18 2014 chalie_a
*/

#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"
int     ins_live(t_champ *champ, t_arena *arena);
int     ins_ld(t_champ *champ, t_arena *arena);
int     ins_st(t_champ *champ, t_arena *arena);
int     ins_add(t_champ *champ, t_arena *arena);
int     ins_sub(t_champ *champ, t_arena *arena);
int     ins_and(t_champ *champ, t_arena *arena);
int     ins_or(t_champ *champ, t_arena *arena);
int     ins_xor(t_champ *champ, t_arena *arena);
int     ins_zjmp(t_champ *champ, t_arena *arena);
int     ins_ldi(t_champ *champ, t_arena *arena);
int     ins_sti(t_champ *champ, t_arena *arena);
int     ins_fork(t_champ *champ, t_arena *arena);
int     ins_lld(t_champ *champ, t_arena *arena);
int     ins_lldi(t_champ *champ, t_arena *arena);
int     ins_lfork(t_champ *champ, t_arena *arena);
int     ins_aff(t_champ *champ, t_arena *arena);


int	show_inst(t_champ *champ)
{
  int	i;

  i = -1;
  printf("Istruction = %d\n", champ->cmd->op);
  while (++i < 4)
    {
      printf("argtype = %d, argvalue = %d\n", champ->cmd->args_type[i], champ->cmd->args_value[i]);
    }
}

int	exec_instruction(t_champ *champ, t_arena *arena)
{
  static const ptrft	ins_tab[16] = {ins_live, ins_ld, ins_st, ins_add,
				       ins_sub, ins_and, ins_or, ins_xor,
				       ins_zjmp, ins_ldi, ins_sti, ins_fork,
				       ins_lld, ins_lldi, ins_lfork, ins_aff};
  show_inst(champ);
  return (SUCCESS);
}
