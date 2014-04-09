/*
** fill_arena.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 31 22:51:32 2014 chalie_a
** Last update Wed Apr  2 21:05:50 2014 chalie_a
*/

#include <stdlib.h>
#include "x_error.h"
#include "corewar.h"
#include "vm.h"

int		write_in_arena(t_arena *arena, char *code, int size, int pos)
{
  int	i;
  int	save;

  i = 0;
  save = size + pos;
  while (pos < save)
    {
      if (pos >= (arena->mem_size) || arena->arena[pos] != 0)
	return (ERROR("Arena is too small\n"));
      arena->arena[pos] = code[i];
      ++pos;
      ++i;
    }
  return (SUCCESS);
}

int		get_size(t_arena *arena, t_champ *root, int mem_size)
{
  t_champ	*champ;

  arena->mem_size = mem_size;
  arena->nb_champs = 0;
  arena->total_size = 0;
  arena->cycle_to_die = CYCLE_TO_DIE;
  champ = root;
  while ((champ = champ->next) != root)
    {
      arena->nb_champs++;
      arena->total_size += champ->header->prog_size;
    }
  if (arena->nb_champs == 0)
    return (ERROR("No champs\n"));
  if (arena->total_size >= arena->mem_size)
    return (ERROR("Arena is too small\n"));
  return (SUCCESS);
}

t_arena		*init_arena(t_champ *root, int mem_size)
{
  t_champ	*champ;
  t_arena	*arena;
  int		i;

  i = 0;
  champ = root;
  if (!(arena = malloc(sizeof(t_arena))))
    return (NULL);
  if (get_size(arena, root, mem_size) == FAILURE)
    return (NULL);
  if (!(arena->arena = calloc(mem_size + 10,  sizeof(char))))
    return (NULL);
  while ((champ = champ->next) != root)
    {
      champ->pc = champ->line->load_a != -1 ? champ->line->load_a : i;
      if (write_in_arena(arena, champ->code,
			 champ->header->prog_size, champ->pc) == FAILURE)
	return (NULL);
      i = i + (arena->mem_size / arena->nb_champs);
    }
  return (arena);
}
