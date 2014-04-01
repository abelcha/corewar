/*
** main.c for trul in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:20:06 2014 chalie_a
** Last update Tue Apr  1 01:19:42 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"

t_champ		*init_root()
{
  t_champ	*init;

  if (!(init = malloc(sizeof(*init))))
    return (NULL);
  init->prev = init;
  init->next = init;
  return (init);
}

int		shw_list(t_champ *root)
{
  t_champ	*list;

  list = root->next;
  while (list != root)
    {
      printf("name = %s\n", list->line->filename);
      printf("dump = %d , load_address = %d, prog_nbr = %d\n",  list->line->dump,
	     list->line->load_address, list->line->prog_number);
      int	i = -1;
      printf(BLUE);
      while (++i < list->header->prog_size)
	printf("%d ", list->code[i]);
      printf(ENDOF);
      list = list->next;
    }
  return (SUCCESS);
}

int		display_arena(char *str)
{
  int		i;

  i = -1;
  while (++i < MEM_SIZE)
    printf("%d ", str[i]);
}

int		main(int ac, char **av)
{
  t_champ	*champ;
  t_arena	*arena;
  int		status;
  int		nb_champs;

  nb_champs = 0;
  champ = init_root();
  while ((status = add_champs_in_list(champ, &av[1])) != SUCCESS)
    {
      if (status == FAILURE)
	return (FAILURE);
      else
	if (fill_champs(champ->prev) == FAILURE)
	  return (FAILURE);
      nb_champs++;
    }
  //shw_list(champ);
  arena = init_arena(champ, nb_champs);
  display_arena(arena->arena);
  //swap elem to good number
  //START FIGHT
  return (SUCCESS);
}
