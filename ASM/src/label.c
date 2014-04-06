/*
&** get_params.c for coreware in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 02:14:38 2014 
** Last update Fri Apr  4 17:29:56 2014 chalie_a
*/

#include "corewar.h"
#include "op.h"
#include "x_error.h"

static int	is_num(char *str)
{
  int		i;

  i = -1;
  if (str[i + 1] == '-')
    i++;
  while (str[++i])
    if ((str[i] < '0' || str[i] > '9') && !IS_OP(str[i]))
      return (FALSE);
  return (TRUE);
}

static char	*get_l_flag(char *str, int type)
{
  if ((type == T_DIR || type == T_REG) && str[1] == ':')
    return (strdup(&str[1]));
  if (type == T_LAB)
    return (strdup(str));
  return (NULL);
}

static int	get_type(char *str, int num)
{
  if (!str)
    return (0);
  if (str[0] == 'r')
    return (T_REG);
  else if (str[0] == '%')
    return (T_DIR);
  else if (str[0] == ':')
      return (T_LAB);
  else if (is_num(str) == TRUE)
    return (T_IND);
  else
    return (X_ERROR(str, INV_PAR));
}

int		get_param_info(t_list *list, t_args *args, int i)
{
  list->param[i].type = get_type(args->args[i + 1], list->num);
  list->param[i].param = GET_VALUE(args->args[i + 1], list->param[i].type);
  list->param[i].l_flag = get_l_flag(args->args[i + 1], list->param[i].type);
  return (SUCCESS);
}
