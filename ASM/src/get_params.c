/*
** get_params.c for coreware in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 02:14:38 2014 
** Last update Thu Mar 20 22:49:19 2014 
*/

#include "corewar.h"
#include "op.h"
#include "x_error.h"

int	is_num(char *str)
{
  int	i;

  i = -1;
  if (str[i + 1] == '-')
    i++;
  while (str[++i])
    if (str[i] < '0' || str[i] > '9')
      return (FALSE);
  return (TRUE);
}

int     my_atoi(char *str)
{
  int   res;

  if (str[0] == ':')
    return (42);
  if (str == NULL)
    return (0);
  if (*str == '-')
    return (-my_atoi(str + 1));
  if (*str == '+')
    return (my_atoi(str + 1));
  res = 0;
  while (*str)
    {
      res = res * 10;
      res = res + *str - '0';
      str = str + 1;
    }
  return (res);
}

int		get_coding_size(t_list *list)
{
  int		i;

  list->size = (list->coding_byte == 0 ? 1 : 2);
  i = -1;
  while (++i < MAX_ARGS_NUMBER)
    {
      printf("lolo = %d\n", list->size);
      list->size += list->param[i].type;
    }
  return (SUCCESS);
}

int		get_param_info(t_list *list, t_args *args, int i)
{
  list->param[i].type = get_type(args->args[i + 1], list->num);
  list->param[i].param = get_value(args->args[i + 1], list->param[i].type);
  if (list->param[i].param == FAILURE || list->param[i].type == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

int		get_value(char *str, int type)
{
  if (type == T_IND || type == T_LAB)
    return (my_atoi(str));
  else
    return (my_atoi(&str[1])); 
}

int		get_type(char *str, int num)
{
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
