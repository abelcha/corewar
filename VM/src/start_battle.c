/*
** start_battle.c for yoloswag in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Apr  2 18:04:47 2014 chalie_a
** Last update Tue Apr  8 17:33:41 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"

#define DUMP	542639

int		print_map(t_arena *arena)
{
  /*
  **	PRINT SHITS
  */
  return (DUMP);
}

int		exec_command(t_champ *champ, t_arena *arena)
{
  if (get_instruction(&(arena->arena[pc]), champ) == FAILURE)
    {
      champ->cycle = 1;
      return (FAILURE):
    }

  return (SUCCESS);
}

int		who_is_alive(t_champ *champ, t_arena *arena)
{
  /*
  **	COUNT SHIT
  */
  return (1);
}

int		actualise_cycles(t_arena *arena)
{
  ++(arena->cycle_to_die);
  if (arena->nbr_live >= NBR_LIVE)
    {
      arena->cycle_to_die -= CYCLE_DELTA;
      arena->nbr_live = 0;
    }
  return (SUCCESS);
  
}

int		handle_cycles(t_arena *arena, t_champ *champ)
{
  if (--(champ->cycle) == 0)
    exec_command(champ, arena);
  return (actualise_cycles(arena));
}

int		start_battle(t_champ *root, t_arena *arena, t_settings *sets)
{
  int		cpt;
  t_champ	*champ;

  while (arena->cycle_to_die > 0 && who_is_alive(champ, arena) > 1)
    {
      champ = root;
      while ((champ = champ->next) != root)
	{
	  if (handle_cycles(arena, champ) == DUMP)
	    return (SUCCESS);
	  if (++(arena->current_cycle) == sets->dump)
	    return (print_map(arena));
	}
    }
   return (SUCCESS);
}

