/*
** fill_arena.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 31 22:51:32 2014 chalie_a
** Last update Tue Apr  1 12:48:56 2014 chalie_a
*/

#include <stdlib.h>
#include "corewar.h"
#include "vm.h"

int		write_in_arena(char *arena, char *code, int size, int pos)
{
  int	i;

  i = 0;
  while (pos < size)
    {
      arena[pos] = code[i];
      ++pos;
      ++i;
    }
}

t_arena		*init_arena(t_champ *root, int nb_champs)
{
  t_champ	*champ;
  t_arena	*arena;
  int		i;

  i = 0;
  if (!(arena = malloc(sizeof(t_arena))))
    return (NULL);
  champ = root->next;
  memset(arena->arena, 0, MEM_SIZE);
  while (champ != root)
    {
      write_in_arena(arena->arena, champ->code, i + champ->header->prog_size, i);
      i = i + (MEM_SIZE / nb_champs);
      champ = champ->next;
    }
  return (arena);
}
