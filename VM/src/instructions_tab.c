/*
** instructions_tab.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue Apr  8 20:16:41 2014 chalie_a
** Last update Wed Apr  9 21:48:34 2014 chalie_a
*/

#include "corewar.h"
#include "vm.h"
#define  ABS(x, s) x = (x < 0 ? -x : x) % s
// Ce qui est contenu dans le registre X
#define REG_VALUE(x) ABS(champ->cmd->args_value[x - 1], 16)
// Le registre cité dans le Xeme argument
#define REG_NBR(x) champ->reg[ABS(champ->cmd->args_value[x - 1], 16)]


int		what_op(int a, int b, int x)
{
  return (x == 4 ? a + b : x == 5 ? a - b : x == 6 ?
	  a & b : x == 7 ? a | b : a ^ b);
}

int		do_live(t_champ *champ, t_arena *arena)
{
  champ->cycle_to_die = -1;
  arena->nbr_live++;
  my_printf("The Champ n:%d (%s) is alive.\n",
	    champ->champ_nbr, champ->line->filename);
}

int		ins_live(t_champ *champ, t_arena *arena)
{
   t_champ	*tmp;
   char		flag;
   
   //   if (champ->cmd->args_value[0] == champ->reg[0])
     do_live(champ, arena);
     return (0);
   tmp = champ->next;
   while (tmp != champ)
     {
	 printf("arg = %d , reg [0] = %d\n", champ->cmd->args_value[0],  tmp->reg[0]);
      if (champ->cmd->args_value[0] == tmp->reg[0])
	 do_live(tmp, arena); 
       tmp = tmp->next;
     }
   return (SUCCESS);
}

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
	  REG_NBR(2) = champ->cmd->args_value[0] % mod;
   champ->carry = (result ? 0 : 1);
   return (SUCCESS);
}

int	ins_st(t_champ *champ, t_arena *arena)
{
  return (SUCCESS);
}

int	ins_operation(t_champ *champ, t_arena *arena)
{
  int	op1;
  int	op2;
  int	result;
  
   op1 = champ->cmd->args_value[0];
   op2 = champ->cmd->args_value[1];
   if (champ->cmd->args_type[0] == T_REG)
     op1 = champ->reg[REG_VALUE(1)];
   if (champ->cmd->args_type[1] == T_REG)
     op1 = champ->reg[REG_VALUE(1)];
   result = what_op(op1, op2, champ->cmd->op);
   champ->carry = (result ? 0 : 1);
   REG_NBR(3) = result;
   return (SUCCESS);
}

int	ins_zjmp(t_champ *champ, t_arena *arena)
{
  if (champ->carry)
    champ->pc += ABS(champ->cmd->args_value[0], IDX_MOD);
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

int	ins_sti(t_champ *champ, t_arena *arena)
{
   return (SUCCESS);
}

int	ins_fork(t_champ *champ, t_arena *arena)
{
   return (SUCCESS);
}

int	ins_lfork(t_champ *champ, t_arena *arena)
{
   return (SUCCESS);
}

int	ins_aff(t_champ *champ, t_arena *arena)
{
   ABS(champ->cmd->args_value[0], 16);
   my_printf("%c", (champ->reg[champ->cmd->args_value[0]]) % 256);
   return (SUCCESS);
}
