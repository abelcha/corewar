/*
** get_params.c for lol in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Apr  2 23:32:07 2014 chalie_a
** Last update Sun Apr 13 19:57:21 2014 dong_n
*/

#include "corewar.h"
#include "op.h"
#include "x_error.h"
#include "my.h"

int		get_label_value(t_list *list, int origin, int target)
{
  int		i;
  int		final_size;
  t_list	*tmp;

  i = -1;
  final_size = 0;
  tmp = list->next;
  while (++i < origin)
    tmp = tmp->next;
  if (origin < target)
    while (++i < target)
      {
	final_size += tmp->size;
	tmp = tmp->next;
      }
  else
    return (-get_label_value(list, target - 1, origin + 1));
  return (final_size);
}

int		get_every_label_value(t_list *list)
{
  t_list	*tmp;
  int		i;
  int		j;

  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      j = -1;
      while (++j < op_tab[tmp->num - 1].nbr_args)
	if (tmp->param[j].l_flag)
	  tmp->param[j].param = get_label_value(list, i, tmp->param[j].param + 1);
      ++i;
      tmp = tmp->next;
    }
  return (SUCCESS);
}
