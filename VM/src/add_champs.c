/*
** main.c for trul in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:20:06 2014 chalie_a
** Last update Sun Apr 13 22:14:07 2014 chalie_a
*/

#include <unistd.h>
#include "vm.h"
#include "my.h"

static int		line_cmp(char *str)
{
  static char		*tab[] = {"-dump", "-a", "-n", "-s", "-ctmo"};
  char			i;

  i = -1;
  while (++i < 5)
    if (!my_strcmp(str, tab[i]))
      return (i);
  return (-1);
}

static int		fill_line(t_champ *champ, t_settings *sets,
				  const int cmp, const int value)
{
  if (value < 0)
    return (option_error(cmp));
  if (cmp == 0)
    sets->dump = value;
  else if (cmp == 1)
    champ->line->load_a = value;
  else if (cmp == 2)
    champ->line->prog_number = value;
  else if (cmp == 4)
    sets->ctmo = value;
  else
    sets->mem_size = value;
  return (SUCCESS);
}

static int		add_in_list(t_champ *new_elem, t_champ *champ,
				    char *str)
{
  unsigned short	len;

  len = my_strlen(str);
  if (len > 4)
    if (!my_strcmp(&str[len - 4], ".cor"))
    {
      new_elem->line->filename = str;
      new_elem->prev = champ->prev;
      new_elem->next = champ;
      champ->prev->next = new_elem;
      champ->prev = new_elem;
      return (54815867);
    }
  write(2, "Error : '", 10);
  write(2, str, my_strlen(str));
  write(2, "' is not a valid filename\n", 27);
  return (FAILURE);
}

int			add_champs_in_list(t_champ *champ, char **stock,
					   t_settings *sets)
{
  static int		i = -1;
  static int		cpt = -1;
  int			cmp;
  t_champ		*new_elem;

  if (!(new_elem = init_champ()))
    return (FAILURE);
  new_elem->line->prog_number = ++cpt;
  while (stock[++i])
    if ((cmp = line_cmp(stock[i])) != -1)
      {
	if (is_number(stock[i + 1]) == FALSE)
	  return (not_a_number(stock[i]));
	if (fill_line(new_elem, sets, cmp, my_getnbr(stock[++i])) == FAILURE)
	  return (FAILURE);
      }
    else
      return (add_in_list(new_elem, champ, stock[i]));
  return (SUCCESS);
}
