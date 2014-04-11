/*
** instructions_tab.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue Apr  8 20:16:41 2014 chalie_a
** Last update Fri Apr 11 01:16:40 2014 chalie_a
*/

#include "corewar.h"
#include "vm.h"

static void	do_live(t_champ *champ, t_arena *arena)
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

  //if (champ->cmd->args_value[0] == champ->reg[0] || arena->current_cycle % 3 < 2)
    do_live(champ, arena);
  //  printf("reg = %d\n", arena->current_cycle);
    // usleep(1000);
    //printf("liveparam = %d reg = %d\n", champ->cmd->args_value[0], champ->reg[0]);
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
