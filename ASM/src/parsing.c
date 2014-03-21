/*
** parsing.c for lolo in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 17:30:55 2014 
** Last update Fri Mar 21 05:53:07 2014 chalie_a
*/

#include "op.h"
#include "corewar.h"
#include "x_error.h"
#include "x_colors.h"

int		line_parsing(t_args *args, t_list *list)
{
  int		ins_num;

  ins_num = which_instruction(args->args[0]);
  if (ins_num == UNKNOWN)
    return (FAILURE);
  if (add_elem_prev(list, args, ins_num) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

int		asm_parsing(t_list *list, char **stock)
{
  int		i;
  int		cmp;
  t_args	*args;

  i = -1;
  args = malloc(sizeof(t_args));
  list = init_list();
  if (!list || !args)
    return (ERROR(MALLOC_FAIL));
  while (stock[++i])
    {
      stock[i] = epur_str(stock[i]);
      if (split_list(stock[i], args) == FAILURE)
	return (FAILURE);
      if (line_parsing(args, list) == FAILURE)
	return (FAILURE);
    }
  remplace_label(list);
  get_every_label_value(list);
  show_list(list);
  return (SUCCESS);
}
