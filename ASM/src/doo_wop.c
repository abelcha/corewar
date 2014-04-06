/*
** doo_wop.c for lol in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 26 00:11:34 2014 chalie_a
** Last update Sun Apr  6 21:30:37 2014 chalie_a
*/

#include <stdlib.h>
#include <stdio.h>
#include "corewar.h"



int		cut_nbr(char *str, int *i)
{
  static char	buffer[128];
  int		j;

  j = -1;
  memset(buffer, 0, 128);
  if (*i == -1)
    while (str && str[*i] && IS_OP(str[*i]))
      ++(*i);
  while (str[*i] && str[++(*i)] && !IS_OP(str[*i]))
    buffer[++j] = str[(*i)];
  --(*i);
  return (atoi(buffer));
}

int	evalxpr(char *str)
{
  int	i;
  int	sec;
  int	res;
  char	op;

  i = -1;

  //  if (!str)
  // return (0);
  i = -1;
  res = cut_nbr(str, &i);
  while (str && str[++i])
    {
      if (IS_OP(str[i]))
	{
	  op = str[i];
	  sec = cut_nbr(str, &i);
	  res = DOO_OP(res, op, sec);
	}
    }
  return (res);
}
