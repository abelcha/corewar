/*
** get_params.c for coreware in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 02:14:38 2014 
** Last update Wed Mar 19 04:26:50 2014 
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

int		get_param_value(char *str, int type)
{
  if (type == T_IND || type == T_LAB)
    return (my_atoi(str));
  else
    return (my_atoi(&str[1])); 
}

int		get_param_type(char *str, int num)
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
