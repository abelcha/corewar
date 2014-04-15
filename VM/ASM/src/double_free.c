/*
** double_free.c for lol in /home/tovazm/rendu/corewar/ASM/src
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Mar 27 23:27:10 2014 chalie_a
** Last update Sun Apr 13 14:38:25 2014 dong_n
*/

#include <stdlib.h>

void	double_free(char **stock)
{
  int	i;

  i = -1;
  while (stock[++i])
    free(stock[i]);
  free(stock);
}
