/*
** get_params.c for coreware in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 02:14:38 2014 
** Last update Sun Apr 13 22:11:44 2014 dong_n
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_error.h"
#include "my.h"

static const t_type	type_size[] =
{
  {'r', T_REG},
  {DIRECT_CHAR, T_DIR},
  {LABEL_CHAR, T_LAB}
};

static int	is_num(const char *str)
{
  int		i;

  i = -1;
  if (str[i + 1] == '-')
    i++;
  while (str[++i])
    if (str[i] < '0' || str[i] > '9')
      return (FALSE);
  return (TRUE);
}

static char	*get_l_flag(char *str, int type, int *err)
{
  if ((type == T_DIR || type == T_REG) && str[1] == LABEL_CHAR)
    {
      if (my_verif_label(&str[2]) == FAILURE)
	*err = 1;
      return (my_strdup(&str[1]));
    }
  if (type == T_LAB)
    {
      if (my_verif_label(&str[1]) == FAILURE)
	*err = 1;
      return (my_strdup(str));
    }
  return (NULL);
}

static int	get_type(char *str)
{
  int		i;

  i = -1;
  if (!str)
    return (0);
  while (++i < 3)
    if (str[0] == type_size[i].type)
      return (type_size[i].value);
  if (is_num(str) == TRUE)
    return (T_IND);
  return (X_ERROR(str, INV_PAR));
}

int		get_param_info(t_list *list, t_args *args, int i)
{
  int		err;

  err = 0;
  list->param[i].type = get_type(args->args[i + 1]);
  list->param[i].param = GET_VALUE(args->args[i + 1], list->param[i].type);
  list->param[i].l_flag = get_l_flag(args->args[i + 1],
				     list->param[i].type, &err);
  if (err == 1)
    {
      free(list->param[i].l_flag);
      return (FAILURE);
    }
  return (SUCCESS);
}
