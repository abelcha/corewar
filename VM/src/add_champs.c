/*
** main.c for trul in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:20:06 2014 chalie_a
** Last update Tue Apr  1 12:50:57 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"

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

int		line_cmp(char *str)
{
  static char	*tab[3] = {"-dump", "-a", "-n"};
  int		i;

  i = -1;
  while (++i < 3)
    if (!my_strcmp(str, tab[i]))
      return (i);
  return (-1);
}

int		fill_line(t_champ *champ, int cmp, int value)
{
  if (value < 0)
    return (option_error(cmp));
  if (cmp == 0)
    champ->line->dump = value;
  else if (cmp == 1)
    champ->line->load_address = value;
  else
    champ->line->prog_number = value;
  return (SUCCESS);
}

int		add_in_list(t_champ *new_elem, t_champ *champ, char *str)
{
  int		len;

  len = strlen(str);
  if (len > 4)
    if (!strcmp(&str[len - 4], ".cor"))
    {
      new_elem->line->filename = str;
      new_elem->prev = champ->prev;
      new_elem->next = champ;
      champ->prev->next = new_elem;
      champ->prev = new_elem;
      return (54815867);
    }
  printf("Error : '%s' is not a valid filename\n", str);
  return (FAILURE);
}

t_champ		*init_champ()
{
  t_champ	*champ;

  champ = malloc(sizeof(t_champ));
  champ->cmd = malloc(sizeof(t_cmd));
  champ->line = malloc(sizeof(t_line));
  champ->header = malloc(sizeof(t_hd));
  if (!champ || !champ->cmd || !champ->line)
    {
      printf("Error : Malloc Failed\n");
      return (NULL);
    }
  champ->line->filename = NULL;
  champ->line->dump = 0;
  champ->line->prog_number = 0;
  champ->line->load_address = 0;
  champ->code = NULL;
  champ->last_live_call = 0;
  champ->carry = 0;
  champ->pc = 0;
  return (champ);
}

int		add_champs_in_list(t_champ *champ, char **stock)
{
  static int	i = -1;
  int		cmp;
  t_champ	*new_elem;

  if (!(new_elem = init_champ()))
    return (FAILURE);
  while (stock[++i])
    {
      if ((cmp = line_cmp(stock[i])) != -1)
	{
	  if (is_number(stock[i + 1]) == FALSE)
	    return (not_a_number(stock[i]));
	  if (fill_line(new_elem, cmp, my_getnbr(stock[++i])) == FAILURE)
	    return (FAILURE);
	}
      else
	return (add_in_list(new_elem, champ, stock[i])); 
   }
  return (SUCCESS);
}
