/*
** parsing.c for lolo in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 17:30:55 2014 
** Last update Wed Mar 19 01:10:18 2014 
*/

#include "op.h"
#include "corewar.h"

int		line_parsing(t_args *args, t_list *list)
{
  int		ins_num;

  ins_num = which_instruction(args->args[0]);
  if (ins_num == UNKNOWN)
    return (FAILURE);
  add_elem_prev(list, args, ins_num);
  return (SUCCESS);
}

int		show_list(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  while (tmp != list)
    {
      printf("Num = %d, label = %s\n", list->num, list->label);
      i = 0;
      while (i < op_tab[list->num - 1].nbr_args)
	{
	  printf("%d", list->param[i].type);
	  printf("%d", list->param[i].param);
	  i++;
	}
    }
}

int		asm_parsing(t_list *list, char **stock)
{
  int		i;
  int		cmp;
  t_args	*args;

  i = -1;
  args = malloc(sizeof(t_args));
  list = init_list(list);
  if (!list || !args)
    return (FAILURE);
  while (stock[++i])
    {
      stock[i] = epur_str(stock[i]);
      if (split_list(stock[i], args) == FAILURE)
	return (FAILURE);
      if (line_parsing(args, list) == FAILURE)
	return (FAILURE);
    }
  show_list(list);
  return (SUCCESS);
}
