/*
** start_battle.c for yoloswag in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Apr  2 18:04:47 2014 chalie_a
** Last update Thu Apr 10 01:10:48 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"

#define DUMP	542639

int	cycle_tab[17] = {10, 5, 5, 10, 10,
                    6, 6, 6, 20, 25,
                    25, 800, 10, 50,
                    1000, 2};

int		print_map(t_arena *arena)
{
  /*
  **	PRINT SHITS
  */
  return (DUMP);

}
int		exec_command(t_champ *champ, t_arena *arena)
{
  printf("pcbefore = %d\n", champ->pc);
  champ->cmd->op = 0;
  memset(champ->cmd->args_type, 0, 4);
  memset(champ->cmd->args_value, 0, 4);
  if (get_instruction(&(arena->arena[champ->pc]), champ) == FAILURE)
    {
      printf("pclol = %d\n", champ->pc);
      champ->pc = (champ->pc + 1) % arena->mem_size;
      champ->cycle = 1;
      return (FAILURE);
    }
  printf("champ = %s instruction = %d\n", champ->line->filename, champ->cmd->op);
  int	i = -1;
  while (++i < 4)
    {
      printf("%d ", arena->arena[champ->pc + i]);
    }
  printf("\n");
  usleep(500000);
  champ->cycle = cycle_tab[champ->cmd->op - 1];
  printf("pc = %d\n", champ->pc);
  return (exec_instruction(champ, arena));
}

int		who_is_alive(t_champ *champ, t_arena *arena)
{
  static int	i = -1;
  /*
  **	COUNT SHIT
  */
  return (42);
}

int		actualise_cycles(t_arena *arena)
{
  if (arena->nbr_live >= NBR_LIVE)
    {
      printf("cycle_to_die = %d nbr_live = %d\n", arena->cycle_to_die, arena->nbr_live);
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
	  ++(champ->cycle_to_die);
	}
    }
   return (SUCCESS);
}

