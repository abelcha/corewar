/*
** start_battle.c for yoloswag in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Apr  2 18:04:47 2014 chalie_a
** Last update Sun Apr 13 20:38:25 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"

static int		actualise_cycles(t_arena *arena)
{

  if (arena->nbr_live >= NBR_LIVE)
    {
      arena->cycle_to_die -= CYCLE_DELTA;
      arena->nbr_live = 0;
    }
  return (SUCCESS);
}

static int		handle_cycles(t_arena *arena, t_champ *champ)
{
  if (champ->cycle_to_die > arena->cycle_to_die)
    return (DEAD);
  if (--(champ->cycle) == 0)
    exec_command(champ, arena);
  return (actualise_cycles(arena));
}

static int	still_alive(t_champ *root)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = root;
  while ((tmp = tmp->next) != root)
    ++i;
  return (i);
}

int		start_battle(t_champ *root, t_arena *arena, t_settings *sets)
{
  int		cpt;
  t_champ	*champ;

  while (arena->cycle_to_die > 0 && still_alive(root) > 1)
    {
      champ = root->next;
      while ((champ) != root && arena->current_cycle > sets->ctmo)
	{
	  if (handle_cycles(arena, champ) == DEAD)
            {
              champ = champ->next;
              delete_elem(champ->prev, arena);
            }
          else
            champ = champ->next;
          ++(champ->cycle_to_die);
	}
      if (++(arena->current_cycle) == sets->dump)
	return (print_map(champ, arena));
    }
  return (SUCCESS);
}
