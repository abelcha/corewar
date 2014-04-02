/*
** main.c for trul in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:20:06 2014 chalie_a
** Last update Wed Apr  2 00:46:28 2014 chalie_a
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
  while (list != root)
    {
      printf("name = %s\n", list->line->filename);
      printf("dump = %d , load_a = %d, prog_nbr = %d\n",  list->line->dump,
	     list->line->load_a, list->line->prog_number);
      int	i = -1;
      printf(BLUE);
      while (++i < list->header->prog_size)
	printf("%d ", list->code[i]);
      printf(ENDOF);
      list = list->next;
    }
  printf("\n");
  return (SUCCESS);
}

void			display_arena(char *str)
{
  int			i;

  i = -1;
  while (++i < MEM_SIZE)
    if (str[i] == 0 && str[i + 1] == 0 
	&& str[i + 2] == 0  && str[i + 3] == 0 && str[i + 4] == 0)
      printf("%s%d%s", BLUE, str[i], ENDOF);
    else
      printf("%s%d%s", RED, str[i], ENDOF);
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

static t_champ		*init_root()
{
  t_champ		*init;

  if (!(init = malloc(sizeof(*init))))
    return (NULL);
  init->prev = init;
  init->next = init;
  return (init);
}

static t_settings	*init_sets()
{
  t_settings		*init;

  if (!(init = malloc(sizeof(t_settings))) == FAILURE)
    return (NULL);
  init->dump = -1;
  init->mem_size = -1;
  init->ctmo = -1;
  return (init);
}

static t_champ		*parse_commandline(char **cmd, t_settings *sets)
{
  t_champ		*champ;
  int			status;

  champ = init_root();
  while ((status = add_champs_in_list(champ, cmd, sets)) != SUCCESS)
    if (status == FAILURE)
      return (NULL);
    else
      if (fill_champs(champ->prev) == FAILURE)
	return (NULL);
  return (champ);
}

int			main(int ac, char **av)
{
  t_champ		*champ;
  t_arena		*arena;
  t_settings		*sets;

  if (!(sets = init_sets()))
    return (FAILURE);
  champ = parse_commandline(&av[1], sets);
  if (!champ)
    return (FAILURE);
  //shw_list(champ);

  arena = init_arena(champ);
  if (arena == NULL)
    return (FAILURE);
  display_arena(arena->arena);
  display_sets(sets);
  return (SUCCESS);
}
