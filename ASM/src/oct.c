/*
** oct.c for ol in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Thu Mar 20 01:51:08 2014 
** Last update Fri Mar 21 22:40:21 2014 chalie_a
*/
#include "corewar.h"
#include "op.h"


int		get_coding_byte(t_list *list)
{
  int		i;
  char		type;

  if (list->num != OP_LIVE && list->num != OP_ZJMP &&
      list->num != OP_FORK && list->num != OP_LFORK)
    {
      i = -1;
      list->coding_byte = 0;
      while (++i < MAX_ARGS_NUMBER)
	{
	  if (list->param[i].type == T_REG)
	    type = 1;
	  else if (list->param[i].type == T_DIR)
	    type = 2;
	  else if (list->param[i].type == T_IND)
	    type = 3;
	  else
	    type = 0;
	  list->coding_byte |= (type << ((MAX_ARGS_NUMBER - 1 - i) << 1));
	}
    }
  else
    list->coding_byte = 0;
  return (SUCCESS);
}
