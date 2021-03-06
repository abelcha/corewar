/*
** instructions_tab.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue Apr  8 20:16:41 2014 chalie_a
** Last update Sun Apr 13 18:43:16 2014 chalie_a
*/

#include "vm.h"

static int	my_pow(int nb, int power)
{
  if (power == 0)
    return (1);
  else if (power > 1)
    nb = nb * my_pow(nb, power - 1);
  return (nb);
}

static void	write_on_arena(t_arena *arena, int pos, int size, int result)
{
  int		k;
  int		i;

  i = -1;
  k = size - 1;
  while (k >= 0)
    {
      arena->arena[ABS(pos, arena->mem_size)] = (result / my_pow(256, k));
      pos++;
      k--;
    }
}

int		ins_sti(t_champ *champ, t_arena *arena)
{
   int		op1;
   int		op2;
   int		op3;
   int		result;

   op1 = champ->cmd->args_value[0];
   op2 = champ->cmd->args_value[1];
   op3 = champ->cmd->args_value[2];
   if (champ->cmd->args_type[1] == T_REG)
     op2 = champ->reg[REG_VALUE(2)];
   if (champ->cmd->args_type[2] == T_REG)
     op3 = champ->reg[REG_VALUE(3)];
   result = champ->reg[REG_VALUE(1)];
   write_on_arena(arena, champ->pc + op2 + op1, 4, result);
   return (SUCCESS);
}

int	ins_st(t_champ *champ, t_arena *arena)
{
   int	op1;
   int	op2;

   op1 = champ->cmd->args_value[0];
   op2 = champ->cmd->args_value[1];
   if (champ->cmd->args_type[0] == 1)
     op1 = champ->reg[op1 - 1];
   if (champ->cmd->args_type[1] == T_REG)
     champ->reg[op2] = op1;
   else
     write_on_arena(arena, champ->pc + op2, 4, op1);
   return (SUCCESS);
}
