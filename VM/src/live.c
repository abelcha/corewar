/*
** instructions_tab.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue Apr  8 20:16:41 2014 chalie_a
** Last update Sun Apr 13 22:42:48 2014 chalie_a
*/

#include "unistd.h"
#include "vm.h"
#include "my.h"

static int	do_live(t_champ *champ, t_arena *arena)
{
  char		*str;

  champ->cycle_to_die = -1;
  arena->nbr_live++;
  arena->winner = champ;
  write(1, "The Champ ", 10);
  str = champ->line->filename;
  while (*str != '.' && *str)
    write(1, str++, 1);
  write(1, " is alive.\n", 11);
  return (SUCCESS);
}

int		ins_live(t_champ *champ, t_arena *arena)
{
  t_champ	*tmp;
  char		flag;

  if (champ->cmd->args_value[0] == champ->reg[0] || champ->reg[0])
    return (do_live(champ, arena));
  else
    {
      tmp = champ->next;
      while (tmp != champ)
	{
	  if (champ->cmd->args_value[0] == tmp->reg[0])
	    do_live(tmp, arena);
	  tmp = tmp->next;
	}
    }
  return (SUCCESS);
}
