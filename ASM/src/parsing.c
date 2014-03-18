/*
** parsing.c for lolo in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 17:30:55 2014 
** Last update Tue Mar 18 12:53:58 2014 
*/

#include "op.h"
#include "corewar.h"

int	line_parsing(int num, t_args *args)
{
  return (SUCCESS);
}

int	asm_parsing(t_list *list, char **stock)
{
  int		i;
  int		cmp;
  t_args	*args;

  if (!(args = malloc(sizeof(t_args))))
    return (FAILURE);
  i = -1;
  while (stock[++i])
    {
      stock[i] = epur_str(stock[i]);
      if (split_list(stock[i], args) == FAILURE)
	return (FAILURE);
   }
  return (line_parsing(args));
}
