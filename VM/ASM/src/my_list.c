/*
** my_list.c for corewar in /home/dong_n/rendu/corewar/ASM
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Tue Mar 18 19:46:13 2014 dong_n
** Last update Sun Apr 13 22:17:29 2014 dong_n
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

int		fill_list(t_list *list, t_args *args, int num, char *name)
{
  int		i;

  i = -1;
  list->num = num;
  list->label = args->label;
  my_memset(list->param, 0, sizeof(list->param));
  while (++i < op_tab[num - 1].nbr_args)
    {
      if (get_param_info(list, args, i) == FAILURE)
	return (FAILURE);
      x_free(args->args[i]);
    }
  x_free(args->args);
  get_coding_byte(list);
  get_coding_size(list, &(list->param[i].w_size));
  if (param_type_verif(list, name) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

int		add_elem_prev(t_list *elem, t_args *args, int num, char *name)
{
  t_list	*newelem;

  if (!(newelem = xmalloc(sizeof(*newelem))))
    return (FAILURE);
  if (fill_list(newelem, args, num, name) == FAILURE)
    return (FAILURE);
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (SUCCESS);
}

int		my_delete_elem(t_list *list)
{
  list->prev->next = list->next;
  list->next->prev = list->prev;
  if (list)
    free(list);
  return (SUCCESS);
}

t_list		*init_list(void)
{
  t_list	*init;

  if (!(init = xmalloc(sizeof(*init))))
    return (NULL);
  init->prev = init;
  init->next = init;
  return (init);
}
