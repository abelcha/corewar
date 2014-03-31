/*
** my_strcpy.c for my_strcpy in /home/dong_n/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Mon Oct  7 10:27:58 2013 david$
** Last update Fri Mar 28 07:08:14 2014 chalie_a
*/

#include "stdlib.h"

char	 *my_strcpy(char *dest, char *src, int flag)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  if (flag == 1)
    free(src);
  return (dest);
}
