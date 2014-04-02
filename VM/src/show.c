/*
** main.c for trul in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:20:06 2014 chalie_a
** Last update Wed Apr  2 21:14:07 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"

/*
** TEMPORARY FUNCTIONS
*/

int		shw_list(t_champ *root)
{
  t_champ	*list;

  list = root->next;
  printf("\n============================\n");
  while (list != root)
    {
      printf("name = %s\n", list->line->filename);
      printf("load_a = %d, prog_nbr = %d\n",
	     list->line->load_a, list->line->prog_number);
      list = list->next;
    }
  printf("===============================\n");
  printf("===============================\n");
  return (SUCCESS);
}

void			display_arena(char *str, int mem_size)
{
  int			i;

  i = -1;
  while (++i < mem_size)
    if (str[i] == 0 && str[i + 1] == 0 
	&& str[i + 2] == 0  && str[i + 3] == 0 && str[i + 4] == 0)
      printf("%s%d%s", BLUE, str[i], ENDOF);
      else
    printf("%s%d%s", RED, str[i], ENDOF);
  printf("mem size = %d\n", mem_size);
}

void			display_sets(t_settings *sets)
{
  printf("\n=====================================\n");
  printf("dump = %d, mem_size = %d, ctmo = %d\n", 
	 sets->dump, sets->mem_size, sets->ctmo);
  printf("================================\n");
}

/*
** ! TEMPORARY FUNCTIONS
*/

