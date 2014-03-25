/*
** my_list.c for corewar in /home/dong_n/rendu/corewar/ASM
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Tue Mar 18 19:46:13 2014 dong_n
** Last update Tue Mar 25 07:12:26 2014 chalie_a
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

void		memset_struct(t_list *list)
{
  int		i;

  i = -1;
  while (++i < MAX_ARGS_NUMBER)
    {
      list->param[i].w_size = 0;
      list->param[i].type = 0;
      list->param[i].param = 0;
      list->param[i].l_flag = NULL;
    }
}

int		fill_list(t_list *list, t_args *args, int num)
{
  int		i;

  i = -1;
  list->num = num;
  list->label = args->label;
  memset_struct(list);
  while (++i < op_tab[num - 1].nbr_args)
    if (get_param_info(list, args, i) == FAILURE)
      return (FAILURE); 
 get_coding_byte(list);
  get_coding_size(list, &(list->param[i].w_size));
  if (param_type_verif(list->param, list) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

int		add_elem_prev(t_list *elem, t_args *args, int num)
{
  t_list	*newelem;

  if (!(newelem = xmalloc(sizeof(*newelem))))
    return (FAILURE);
  if (fill_list(newelem, args, num) == FAILURE)
    return (FAILURE);
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (SUCCESS);
}

int		add_elem_next(t_list *elem, t_args *args, int num)
{
  int		i;
  t_list	*newelem;

  i = 0;
  if (!(newelem = xmalloc(sizeof(*newelem))))
    return (FAILURE);
  while (i < op_tab[num - 1].nbr_args)
    {
      newelem->param[i].type = op_tab[num - 1].type[i];
      newelem->param[i].param = my_getnbr(args->args[i + 1]);
      i++;
    }
  newelem->num = num;
  newelem->label = args->label;
  newelem->prev = elem;
  newelem->next = elem->next;
  elem->next->prev = newelem;
  elem->next = newelem;
  return (SUCCESS);
}

int		my_delete_elem(t_list *list)
{
  list->prev->next = list->next;
  list->next->prev = list->prev;
  if (!list)
    free(list);
  return (SUCCESS);
}

t_list		*init_list()
{
  t_list	*init;

  if (!(init = xmalloc(sizeof(*init))))
    return (NULL);
  init->prev = init;
  init->next = init;
  return (init);
}

void		my_freelist(t_list *list)
{
  t_list	*elem;

  elem = list->next;
  while (elem != list)
    {
      elem = elem->next;
      my_delete_elem(elem->prev);
    }
  free(list);
}
