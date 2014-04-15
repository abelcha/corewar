/*
** end_battle.c for lol in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sat Apr 12 19:28:03 2014 chalie_a
** Last update Sun Apr 13 22:41:49 2014 chalie_a
*/

#include <unistd.h>
#include "vm.h"

static void	display_winner(const t_arena *arena)
{
  char		*str;

  if (arena->winner)
    {
      write(1, "The player : ", 13);
      str = arena->winner->line->filename;
      while (*str != '.' && *str)
	write(1, str++, 1);
      write(1, " Won the game !\n", 16);
    }
  else if (arena->total_size && arena->winner)
    write(1, "There is no winner\n", 20);
}

static void	free_champ(t_champ *champ)
{
  t_champ	*tmp;

  tmp = champ->next;
  while ((tmp = tmp->next) != champ)
    {
      x_free(champ->prev->code);
      x_free(champ->prev->line->filename);
      x_free(champ->prev->line);
      x_free(champ->prev->cmd);
      x_free(champ->prev->header);
      x_free(champ->prev);
    }
  x_free(champ);
}

static void	free_all(t_arena *arena, t_champ *champ,
			 t_settings *sets)
{
  free_champ(champ);
  x_free(arena->arena);
  x_free(arena);
  x_free(sets);
}

int		the_game_is_over(t_champ *champ, t_arena *arena,
				 t_settings *sets)
{
  display_winner(arena);
  free_all(arena, champ, sets);
  return (SUCCESS);
}
