/*
** fill_arena.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 31 22:51:32 2014 chalie_a
** Last update Wed Apr  2 00:34:18 2014 chalie_a
*/

#include <stdlib.h>
#include "x_error.h"
#include "corewar.h"
#include "vm.h"

int		write_in_arena(char *arena, char *code, int size, int pos)
{
  int	i;
  int	save;

  i = 0;
  save = size + pos;
  while (pos < save)
    {
      if (arena[pos] != 0)
	return (ERROR("Arena is too small\n"));
      arena[pos] = code[i];
      ++pos;
      ++i;
    }
  return (SUCCESS);
}

int		get_size(t_arena *arena, t_champ *root)
{
  t_champ	*champ;

  arena->nb_champs = 0;
  arena->total_size = 0;
  champ = root;
  while ((champ = champ->next) != root)
    {      arena->nb_champs++;
      arena->total_size += champ->header->prog_size;
    }
  if (arena->nb_champs == 0)
    return (ERROR("No champs\n"));
  if (arena->total_size >= MEM_SIZE)
    return (ERROR("Arena is too small\n"));
  return (SUCCESS);
}

t_arena		*init_arena(t_champ *root)
{
  t_champ	*champ;
  t_arena	*arena;
  int		i;

  i = 0;
  champ = root;
  if (!(arena = malloc(sizeof(t_arena))))
    return (NULL);
  if (get_size(arena, root) == FAILURE)
    return (NULL);
  memset(arena->arena, 0, MEM_SIZE);
  while ((champ = champ->next) != root)
    {
      champ->pc = champ->line->load_a != -1 ? champ->line->load_a : i;
      if (write_in_arena(arena->arena, champ->code, 
			 champ->header->prog_size, champ->pc) == FAILURE)
	return (NULL);
      i = i + (MEM_SIZE / arena->nb_champs);
    }
  return (arena);
}
