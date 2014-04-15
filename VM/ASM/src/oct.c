/*
** oct.c for ol in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Thu Mar 20 01:51:08 2014 
** Last update Sun Apr 13 19:50:45 2014 dong_n
*/

#include "corewar.h"

static const t_type	param[] =
{
  {T_REG, 1},
  {T_DIR, 2},
  {T_IND, 3},
  {T_LAB, 3}
};

int		get_coding_byte(t_list *list)
{
  int		i;
  int		k;
  char		type;

  i = -1;
  list->coding_byte = 0;
  if (CODING_BYTE(list->num) == TRUE)
    while (++i < MAX_ARGS_NUMBER)
      {
	k = -1;
	type = 0;
	while (++k < 4)
	  if (list->param[i].type == param[k].type)
	    type = param[k].value;
	list->coding_byte = list->coding_byte << 2 | type;
      }
  return (SUCCESS);
}
