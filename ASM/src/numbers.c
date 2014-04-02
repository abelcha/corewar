/*
** numbers.c for yoyo in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr  3 00:05:17 2014 chalie_a
** Last update Thu Apr  3 00:39:52 2014 chalie_a
*/

#include "corewar.h"

int	get_real_size(int type, int num)
{
  if (type == T_DIR)
    if (num == OP_ZJMP || num == OP_LDI || num == OP_STI
        || num == OP_LLDI || num == OP_FORK
        || num == OP_LFORK || num == OP_AFF)
      return (IND_SIZE);
  if (type == T_REG)
    return (REG_SIZE);
  if (type == T_DIR)
    return (DIR_SIZE);
  if (type == T_IND)
    return (IND_SIZE);
  if (type == T_LAB)
    return (IND_SIZE);
  return (0);
}

int		get_coding_size(t_list *list, int *w_size)
{
  int		i;

  i = -1;
  list->size = (list->coding_byte == 0 ? 1 : 2);
  while (++i < MAX_ARGS_NUMBER)
    {
      *w_size = get_real_size(list->param[i].type, list->num);
      list->size += *w_size;
    }
  return (SUCCESS);
}

int	my_atoi(char *str)
{
  int	res;

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
