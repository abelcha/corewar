/*
** start_battle.c for yoloswag in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Apr  2 18:04:47 2014 chalie_a
** Last update Fri Apr 11 01:17:42 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"

int			print_map(t_arena *arena)
{
  return (DUMP);
}

static int		actualise_cycles(t_arena *arena)
{

  if (arena->nbr_live >= NBR_LIVE)
    {
      printf("cycle_to_die = %d nbr_live = %d\n", arena->cycle_to_die, arena->nbr_live);
      arena->cycle_to_die -= CYCLE_DELTA;
      arena->nbr_live = 0;
    }
  return (SUCCESS);
}

static int		handle_cycles(t_arena *arena, t_champ *champ)
{
  if (champ->cycle_to_die > arena->cycle_to_die)
    {
      delete_elem(champ);
      return (DEAD);
    }
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
    if (tmp->reg[0]!= tmp->next->reg[0])
      ++i;
  return (i);
}

int		start_battle(t_champ *root, t_arena *arena, t_settings *sets)
{
  int		cpt;
  t_champ	*champ;

  while (arena->cycle_to_die > 0 && still_alive(root) > 1)
    {
      champ = root;
      while ((champ = champ->next) != root)
	{
	  if (handle_cycles(arena, champ) == DUMP)
	    return (SUCCESS);
	  if (++(arena->current_cycle) == sets->dump)
	    return (print_map(arena));
	  ++(champ->cycle_to_die);
	}
    }
  return (SUCCESS);
}
