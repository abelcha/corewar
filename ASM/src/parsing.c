/*
** parsing.c for lolo in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 17:30:55 2014 
** Last update Mon Mar 17 21:33:15 2014 
*/

#include "op.h"

int	asm_parsing(t_list *list, char **stock)
{
  int		i;
  int		cmp;
  t_args	*args;

  i = -1;
  while (stock[++i])
    {
      epur_str(stock[i]);
      split_list(stock[i], args);
      /*      if ((cmp = compare) == UNKNOWN)
	return (FAILURE);
	fill_list[cmp](list, args)*/
   }
  //free shit
  //return (list);
}
