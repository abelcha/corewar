/*
** my_list.c for corewar in /home/dong_n/rendu/corewar/ASM
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Tue Mar 18 19:46:13 2014 dong_n
** Last update Tue Mar 18 20:15:18 2014 dong_n
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"

int		add_elem_prev(t_list *elem, t_args args, int num)
{
  int		i;
  t_list	*newelem;

  i = 0;
  if (!(newelem = xmalloc(sizeof(*newelem))))
    return (-1);
  while (i < op_tab[num].nbr_args)
    {
      newelem->param[i].type = op_tab[num].type[i];
      newelem->param[i].param = args->args[i + 1];
      i++;
    }
  newelem->num = num;
  newelem->label = args.label;
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (0);
}

int		add_elem_next(t_list *elem, int line, int nb_alum)
{
  int		i;
  t_list	*newelem;

  i = 0;
  if (!(newelem = xmalloc(sizeof(*newelem))))
    return (-1);
  while (i < op_tab[num].nbr_args)
    {
      newelem->param[i].type = op_tab[num].type[i];
      newelem->param[i].param = args->args[i + 1];
      i++;
    }
  newelem->num = num;
  newelem->label = args.label;
  newelem->prev = elem;
  newelem->next = elem->next;
  elem->next->prev = newelem;
  elem->next = newelem;
  return (0);
}

int		my_delete_elem(t_list *list)
{
  list->prev->next = list->next;
  list->next->prev = list->prev;
  free(list);
  return (0);
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
