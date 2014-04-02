/*
** oct.c for ol in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Thu Mar 20 01:51:08 2014 
** Last update Thu Apr  3 01:49:55 2014 chalie_a
*/

#include "corewar.h"

int		get_coding_byte(t_list *list)
{
  int		i;
  char		type;

  i = -1;
  list->coding_byte = 0;
  if (HAVE_CODING_BYTE(list->num) == TRUE)
    while (++i < MAX_ARGS_NUMBER)
      {
	type = (list->param[i].type == T_REG ? 1 : list->param[i].type == T_DIR ? 2 :
		list->param[i].type == T_IND ? 3 : 0);
	list->coding_byte |= (type << ((MAX_ARGS_NUMBER - 1 - i) << 1));
      }
  return (SUCCESS);
}
