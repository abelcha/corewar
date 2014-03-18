/*
** parsing.c for lolo in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 17:30:55 2014 
** Last update Tue Mar 18 19:27:55 2014 
*/

#include "op.h"
#include "corewar.h"

int	line_parsing(t_args *args, t_list *list)
{
  int	ins_num;

  ins_num = which_instruction(args->args[0]);
  if (ins_num == UNKNOWN)
    return (FAILURE);
  fill_list(args, list);
 return (SUCCESS);
}

int	asm_parsing(t_list *list, char **stock)
{
  int		i;
  int		cmp;
  t_args	*args;
  t_list        *list;

  if (!(args = malloc(sizeof(t_args))))
    return (FAILURE);
  i = -1;
  while (stock[++i])
    {
      stock[i] = epur_str(stock[i]);
      if (split_list(stock[i], args, list->label) == FAILURE)
	return (FAILURE);
      line_parsing(args, list);
    }
}
