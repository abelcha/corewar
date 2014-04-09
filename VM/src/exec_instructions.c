/*
 ** show_list.c for YOLOSWAG in /home/tovazm/rendu/corewar/ASM
 **
 ** Made by
 ** Login   <abel@chalier.me>
 **
 ** Started on  Wed Mar 19 03:46:23 2014
** Last update Wed Apr  9 20:50:52 2014 chalie_a
 */

#include "vm.h"
#include "corewar.h"

int     ins_live(t_champ *champ, t_arena *arena);
int     ins_ld(t_champ *champ, t_arena *arena);
int     ins_st(t_champ *champ, t_arena *arena);
int     ins_zjmp(t_champ *champ, t_arena *arena);
int     ins_ldi(t_champ *champ, t_arena *arena);
int     ins_sti(t_champ *champ, t_arena *arena);
int     ins_fork(t_champ *champ, t_arena *arena);
int     ins_lld(t_champ *champ, t_arena *arena);
int     ins_lldi(t_champ *champ, t_arena *arena);
int     ins_lfork(t_champ *champ, t_arena *arena);
int     ins_aff(t_champ *champ, t_arena *arena);
int	ins_operation(t_champ *champ, t_arena *arena);

int	show_inst(t_champ *champ)
{
   int	i;
   
   i = -1;
   printf("champnbr = %s\n", champ->line->filename);
   printf("Istruction = %d\n", champ->cmd->op);
   while (++i < 4)
     {
       printf("argtype = %d, argvalue = %d\n", champ->cmd->args_type[i], champ->cmd->args_value[i]);
     }
}

int	exec_instruction(t_champ *champ, t_arena *arena)
{
   static const ptrft	ins_tab[16] = {ins_live, ins_ld, ins_st,
				       ins_operation, ins_operation, 
				       ins_operation, ins_operation, 
				       ins_operation, ins_zjmp, ins_ldi, 
				       ins_sti, ins_fork, ins_ld, ins_ldi,
				       ins_lfork, ins_aff};

   ins_tab[champ->cmd->op  - 1](champ, arena);
   return (SUCCESS);
}
