/*
** utils.c for lo in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 10 17:27:34 2014 chalie_a
** Last update Thu Apr 10 19:52:19 2014 chalie_a
*/

#include "vm.h"
#include "corewar.h"
#include "x_error.h"

int		is_number(char *str)
{
  int		i;

  i = -1;
  if (!str)
    return (FALSE);
  while (str[++i])
    if (str[i] > '9' || str[i] < '0')
      return (FALSE);
  return (TRUE);
}

int     delete_elem(t_champ *champ)
{
  champ->prev->next = champ->next;
  champ->next->prev = champ->prev;
  /* free(champ->code);
  free(champ->line->filename);
  free(champ->line);
  free(champ->cmd);
  free(champ);*/
  return (SUCCESS);
}

t_champ         *init_champ()
{
  t_champ       *champ;

  champ = malloc(sizeof(t_champ));
  champ->line = malloc(sizeof(t_line));
  champ->header = malloc(sizeof(t_hd));
  champ->cmd = calloc(sizeof(t_cmd), 1);
  if (!champ || !champ->line || !champ->cmd)
    return (ERROR_("Error : Malloc Failed\n"));
  champ->line->filename = NULL;
  champ->line->load_a = -1;
  champ->cycle = 1;
  champ->cycle_to_die = 0;
  champ->code = NULL;
  return (champ);
}
