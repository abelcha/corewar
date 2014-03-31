/*
** main.c for trul in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:20:06 2014 chalie_a
** Last update Mon Mar 31 17:54:00 2014 chalie_a
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

int		syntax_error()
{
  my_printf("syntax Error : \n");
  my_printf("Usage : ./corewar [-dumb nbr_cycle] [[-n prog_number]");
  my_printf("[-a load_address] prog_name]\n");
  return (FAILURE);
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

int		option_error(int cmp)
{
  static char	*tab[3] = {"dump", "load address", "set program number"};

  my_fprintf(STDERR_FILENO, "Error : Cannot %s with a negative number\n", tab[cmp]);
  return (FAILURE);
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

int		not_a_number(char *str)
{
  printf("Error : number expected after '%s' statement\n", str);
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
      list = list->next;
    }
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  t_champ	*champ;
  int		status;
  int		i = -1;

  champ = init_root();
  while ((status = add_champs_in_list(champ, &av[1])) != SUCCESS)
    if (status == FAILURE)
      return (FAILURE);
    else
      if (fill_champs(champ->prev) == FAILURE)
	return (FAILURE);
  shw_list(champ);
  //swap elem to good number
  //START FIGHT
  return (SUCCESS);
}
