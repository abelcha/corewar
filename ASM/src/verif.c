/*
** verif.c for verif in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 21 22:39:28 2014 chalie_a
** Last update Sat Mar 22 03:20:55 2014 chalie_a
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
  my_fprintf(STDERR_FILENO, " ERROR : line #%d, Bad Argument : %d\n", line, param[0].param);
  return (FAILURE);
}

int		ld_check(t_param *param, t_list *list)
{
  if (param[line].type == T_REG)
    {
      my_fprintf(STDERR_FILENO, " ERROR : line #%d, Bad Argument : %d\n", line, param[0].param);
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
  /*
  if (list->num == OP_LD || list->num == OP_LLD)
    return (ld_check(param, list, line));
  

  if (list->num == OP_LDI || list->num == OP_LLDI)
    return (ldi_check(param, list, line));


  if (list->num == OP_ST)
    return (st_check(param, list, line));

  if (list->num == OP_STI)
    return (sti_check(param, list, line));


  if (list->num == OP_ADD || list->num == OP_SUB)
    return (operation_check(param, list, line));

  if (list->num == OP_AND || list->num == OP_OR || list->num == OP_XOR)
    return (comp_check(param, list, line));


  if (list->num == OP_ZJMP)
    return (zjmp_check(param, list, line));


  if (list->num == OP_FORK || list->num == OP_LFORK || list->num == OP_AFF)
  return (fork_check(param, list, line));*/
}
 
