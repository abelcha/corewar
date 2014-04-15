/*
** parsing.c for lolo in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 17:30:55 2014 
** Last update Sun Apr 13 22:19:55 2014 dong_n
*/

#include "op.h"
#include "corewar.h"
#include "x_error.h"
#include "x_colors.h"
#include "my.h"

int		line_parsing(t_args *args, t_list *list, char *name)
{
  int		ins_num;

  ins_num = which_instruction(args->args[0]);
  if (ins_num == UNKNOWN)
    return (FAILURE);
  if (add_elem_prev(list, args, ins_num, name) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

int		asm_parsing(header_t *header, char **stock, char *name)
{
  int		i;
  t_args	*args;
  t_list	*list;

  i = -1;
  if (!(args = my_calloc(1, sizeof(*args))))
    return (FAILURE);
  if (!(list = init_list()))
    return (FAILURE);
  while (stock[++i])
    {
      stock[i] = epur_str(stock[i]);
      if (split_list(stock[i], args) == FAILURE)
	return (FAILURE);
      if (line_parsing(args, list, name) == FAILURE)
	return (FAILURE);
    }
  double_free(stock);
  remplace_label(list);
  get_every_label_value(list);
  write_in_file(list, header, name);
  return (SUCCESS);
}
