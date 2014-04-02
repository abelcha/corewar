/*
** verif.c for verif in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 21 22:39:28 2014 chalie_a
** Last update Thu Apr  3 00:45:24 2014 chalie_a
*/

#include <unistd.h>
#include "op.h"
#include "corewar.h"

int		live_check(t_param *param, t_list *list)
{
  if (param[line].type == T_DIR)
    {
      param->w_size += 4;
      return (SUCCESS);
    }
  my_fprintf(STDERR_FILENO, " ERROR : line #%d, Bad Argument : %d\n",
	     line, param[0].param);
  return (FAILURE);
}

int		ld_check(t_param *param, t_list *list)
{
  if (param[line].type == T_REG)
    {
      my_fprintf(STDERR_FILENO, " ERROR : line #%d, Bad Argument : %d\n",
		 line, param[0].param);
      return (FAILURE);
    }
 param->w_size += 4;
 return (SUCCESS);

}

int		param_type_verif(t_param *param, t_list *list)
{
  int		i;

  i = -1;
  return (SUCCESS);
  if (list->num == OP_LIVE)
    return (live_check(param, list));
}
 
