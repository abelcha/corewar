/*
** instructions_tab.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue Apr  8 20:16:41 2014 chalie_a
** Last update Thu Apr 10 19:29:40 2014 chalie_a
*/

#include <unistd.h>
#include "corewar.h"
#include "vm.h"

int	ins_zjmp(t_champ *champ, t_arena *arena)
{
  if (champ->carry)
    champ->pc += ABS(champ->cmd->args_value[0], IDX_MOD);
  return (SUCCESS);
}

int	ins_aff(t_champ *champ, t_arena *arena)
{
  char	c;

  c = champ->reg[champ->cmd->args_value[0]] % 256;
  ABS(champ->cmd->args_value[0], 16);
  write(1, &c, 1);
  return (SUCCESS);
}
