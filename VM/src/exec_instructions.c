/*
 ** show_list.c for YOLOSWAG in /home/tovazm/rendu/corewar/ASM
 **
 ** Made by
 ** Login   <abel@chalier.me>
 **
 ** Started on  Wed Mar 19 03:46:23 2014
** Last update Fri Apr 11 00:58:21 2014 chalie_a
 */

#include "vm.h"
#include "corewar.h"

static void		show_inst(t_champ *champ)
{
   int			i;
   
   i = -1;
   my_printf("\n\nchampname = %s\n", champ->line->filename);
   my_printf("Istruction = %d\n", champ->cmd->op);
   while (++i < 3)
     my_printf("argtype = %d, argvalue = %d\n", champ->cmd->args_type[i], champ->cmd->args_value[i]);
}

static int		exec_instruction(t_champ *champ, t_arena *arena)
{
   static const ptrft	ins_tab[16] = {ins_live, ins_ld,
				       ins_st, ins_operation,
				       ins_operation, ins_operation,
				       ins_operation, ins_operation,
				       ins_zjmp, ins_ldi, ins_sti, ins_fork,
				       ins_ld, ins_ldi, ins_fork, ins_aff};

   //   show_inst(champ);
   return (ins_tab[champ->cmd->op - 1](champ, arena));
}

int			exec_command(t_champ *champ, t_arena *arena)
{
  memset(champ->cmd->args_type, 0, 4);
  memset(champ->cmd->args_value, 0, 4);
  if (get_instruction(&(arena->arena[champ->pc]), champ) == FAILURE)
    {
      champ->pc = (champ->pc + 1) % arena->mem_size;
      champ->cycle = 1;
      return (FAILURE);
    }
  champ->cycle = op_tab[champ->cmd->op - 1].nbr_cycles;
  exec_instruction(champ, arena);
  champ->pc += champ->new_pc % arena->mem_size;
  return (SUCCESS);
}
