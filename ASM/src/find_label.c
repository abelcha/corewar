/*
** show_list.c for YOLOSWAG in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 03:46:23 2014 
** Last update Sun Apr  6 16:35:52 2014 chalie_a
*/

#include "op.h"
#include "corewar.h"
#include "x_error.h"
#include "x_colors.h"
#include "my.h"

int		find_label(t_list *list, char *label, int *value)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      if (tmp->label)
	if (!my_strcmp(tmp->label, &label[1]))
	  {
	    *value = i;
	    return (SUCCESS);
	  }
      tmp = tmp->next;
      ++i;
    }
  return (FAILURE);
}

int		remplace_label(t_list *list)
{
  t_list	*tmp;
  int		i;
  int		j;

  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      j = -1;
     while (++j < 4)
       if (tmp->param[j].l_flag != NULL)
	 if (find_label(list, tmp->param[j].l_flag,
			&(tmp->param[j].param)) == FAILURE)
	   return (FAILURE);
     tmp = tmp->next;
     ++i;
    }
  return (SUCCESS);
}
