/*
** instructions_tab.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue Apr  8 20:16:41 2014 chalie_a
** Last update Sun Apr 13 20:12:13 2014 chalie_a
*/

#include "vm.h"

int		what_op(const int a, const int b, const int x)
{
  return (x == 4 ? a + b : x == 5 ? a - b : x == 6 ?
	  a & b : x == 7 ? a | b : a ^ b);
}

int		ins_operation(t_champ *champ, t_arena *arena)
{
  int		op1;
  int		op2;
  int		result;

   op1 = champ->cmd->args_value[0];
   op2 = champ->cmd->args_value[1];
   if (champ->cmd->args_type[0] == T_REG)
     op1 = champ->reg[REG_VALUE(1)];
   if (champ->cmd->args_type[1] == T_REG)
     op2 = champ->reg[REG_VALUE(2)];
   result = what_op(op1, op2, champ->cmd->op);
   champ->carry = (result ? 0 : 1);
   REG_NBR(3) = result;
   return (SUCCESS);
}
