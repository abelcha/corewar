/*
** verif.c for verif in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 21 22:39:28 2014 chalie_a
** Last update Sun Apr 13 22:17:47 2014 dong_n
*/

#include <unistd.h>
#include "op.h"
#include "corewar.h"
#include "my.h"

int		param_type_verif(t_list *list, char *name)
{
  static char	*prev_name = "name.s";
  static int	instruction = 0;
  int		i;

  i = -1;
  if (my_strcmp(prev_name, name) != 0)
    {
      prev_name = name;
      instruction = 0;
    }
  instruction++;
  while (++i < op_tab[list->num - 1].nbr_args)
    if ((list->param[i].type & op_tab[list->num - 1].type[i]) == 0)
      {
	my_put_error(name);
	my_put_error(" : Warning : Wrong argument type at the instruction n°");
	my_put_nbr_error(instruction);
	my_put_error("\n");
      }
  return (SUCCESS);
}

int		my_verif_label(char *str)
{
  int		i;
  int		k;
  int		err;

  i = 0;
  if (str[0] == '\0' || str[0] == LABEL_CHAR)
    return (FAILURE);
  while (str[i] != LABEL_CHAR && str[i] != '\0')
    {
      k = -1;
      err = 1;
      while (LABEL_CHARS[++k] != '\0')
	if (LABEL_CHARS[k] == str[i])
	  err = 0;
      if (err == 1)
	{
	  my_put_error("Invalid label name\n");
	  return (FAILURE);
	}
      i++;
    }
  return (SUCCESS);
}
