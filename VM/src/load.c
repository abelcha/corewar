/*
** instructions_tab.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue Apr  8 20:16:41 2014 chalie_a
** Last update Thu Apr 10 17:20:17 2014 chalie_a
*/

#include "corewar.h"
#include "vm.h"

int	read_in_arena(char *buff,int pos, int size)
{
   int	k;
   int	result;
   
   result = 0;
   k = 0;
   while (k++ < size)
     result = ((result << 8 & 0xFFFFFF00) | (unsigned char)buff[pos++]);
   return (result);
}

int	ins_ld(t_champ *champ, t_arena *arena)
{
   int	result;
   int	mod;
 
   mod = champ->cmd->op == 10 ? IDX_MOD : arena->mem_size;
   result = champ->cmd->args_value[0];
   if (result != 0)
     REG_NBR(2) = result % mod;
   champ->carry = (result ? 0 : 1);
   return (SUCCESS);
}

int	ins_ldi(t_champ *champ, t_arena *arena)
{
  int	op1;
  int	op2;
  int	result;
  int	mod;

  mod = champ->cmd->op == 10 ? IDX_MOD : arena->mem_size;
  op1 = champ->cmd->args_value[0];
  op2 = champ->cmd->args_value[1];
  if (champ->cmd->args_type[0] == T_REG)
    op1 = champ->reg[REG_VALUE(1)];
   if (champ->cmd->args_type[1] == T_REG)
     op1 = champ->reg[REG_VALUE(1)];
   result = read_in_arena(arena->arena, (champ->pc + op1 + 1) % mod, 2);
   result = read_in_arena(arena->arena, (champ->pc + result + 1) % mod, 4);
   champ->carry = (result ? 0 : 1);
   REG_NBR(3) = result;
   return (SUCCESS);
}
