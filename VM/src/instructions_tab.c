/*
** instructions_tab.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue Apr  8 20:16:41 2014 chalie_a
** Last update Thu Apr 10 16:22:02 2014 chalie_a
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
  arena->winner = champ;
  my_printf("The Champ %s is alive.\n",
  	    champ->line->filename);
}

int		ins_live(t_champ *champ, t_arena *arena)
{ 
  t_champ	*tmp;
  char		flag;
   

  if (champ->cmd->args_value[0] == champ->reg[0])
    do_live(champ, arena);
       return (0);
   tmp = champ->next;
   while (tmp != champ)
     {
       printf("arg = %d , reg [0] = %d\n", champ->cmd->args_value[0], tmp->reg[0]);
       if (champ->cmd->args_value[0] == tmp->reg[0])
	 do_live(tmp, arena); 
       tmp = tmp->next;
     }
   return (SUCCESS);
}

int     my_pow(int nb, int power)
{
  if (power == 0)
    return (1);
  else if (power > 1)
    nb = nb * my_pow(nb, power - 1);
  return (nb);
}

void	write_on_arena(t_arena *arena, int pos, int size, int result)
{
  int	k;
  int	i;

  i = -1;
  k = size - 1;
  while (k >= 0)
    {
      pos++;
      arena->arena[ABS(pos, arena->mem_size)] = (result / my_pow(256, k));
      k--;
    }
}

//**************************************//

int	ins_sti(t_champ *champ, t_arena *arena)
{
   int	op1;
   int	op2;
   int  op3;
   int	result;

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
//*************************************//

int	ins_st(t_champ *champ, t_arena *arena)
{
   int	op1;
   int	op2;
   int	result;

   op1 = champ->cmd->args_value[0];
   op2 = champ->cmd->args_value[1];

   if (champ->cmd->args_type[0] == T_REG)
	  op1 = champ->reg[REG_VALUE(1)];
   if (champ->cmd->args_type[1] == T_REG)
	  REG_NBR(2) = op1;
   else
	  write_on_arena(arena, champ->pc + op2, 4, op1);
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
     REG_NBR(2) = result % mod;
   champ->carry = (result ? 0 : 1);
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
     op2 = champ->reg[REG_VALUE(2)];
   
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

void champ_dup(t_champ *champ, t_champ *fork)
{
   fork->champ_nbr = champ->champ_nbr;
   fork->carry = 0;
   memset(fork->reg, 0, 16);
   memset(fork->cmd->args_type, 0, 4);
   memset(fork->cmd->args_value, 0, 4);
   fork->reg[0] = champ->reg[0];
   fork->cycle_to_die = champ->cycle_to_die;
   fork->cycle = champ->cycle;
   fork->line->filename = strdup(champ->line->filename);
   fork->code = calloc(champ->header->prog_size + 4, sizeof(char));
   if (!fork)
     exit(0); 
   int	i;
   i = -1;
   while (++i < champ->header->prog_size)
     fork->code[i] = champ->code[i];
   fork->header->prog_size = champ->header->prog_size;
   fork->champ_nbr = champ->champ_nbr;

}

void	dup_in_arena(t_champ *fork, t_arena *arena, int pos, int mod)
{
   int	i;
   int	j;

   j = -1;
   ABS(pos, arena->mem_size);
   i = pos;
   while (++j < fork->header->prog_size - 1)
     {
       ++i;
       arena->arena[i % arena->mem_size] = fork->code[j];
       //  printf("i = %d\n", i);
       //  usleep(5000);
     }
   //sleep(1);
}

int	ins_fork(t_champ *champ, t_arena *arena)
{
   t_champ   *fork;
   int       op1;
   int       mod;

   mod = champ->cmd->op == 15 ? arena->mem_size : IDX_MOD;
   op1 = champ->cmd->args_value[0];
   if (!(fork = init_champ()))
     return (FAILURE);
   champ_dup(champ, fork);
   champ->pc = op1 % arena->mem_size;
   dup_in_arena(fork, arena, op1, mod);
   fork->prev = champ->prev;
   fork->next = champ;
   champ->prev->next = fork;
   champ->prev = fork;
}

int	ins_lfork(t_champ *champ, t_arena *arena)
{
   return (SUCCESS);
}

int	ins_aff(t_champ *champ, t_arena *arena)
{
   ABS(champ->cmd->args_value[0], 16);
   //my_printf("%c", (champ->reg[champ->cmd->args_value[0]]) % 256);
   return (SUCCESS);
}
