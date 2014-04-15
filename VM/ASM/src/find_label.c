/*
** find_label.c for find_label in /home/dong_n/rendu/corewar/ASM
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Apr 13 13:22:43 2014 dong_n
** Last update Sun Apr 13 21:10:10 2014 dong_n
*/

#include <stdlib.h>
#include "op.h"
#include "corewar.h"
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
  my_put_error("Label not found\n");
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
