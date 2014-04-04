/*
** convert_base.c for convert_base in /home/dong_n/rendu/Piscine-C-Jour_08/ex_02
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Thu Oct 10 17:17:21 2013 david$
** Last update Sun Mar 23 22:05:28 2014 david$
*/

#include <stdlib.h>
#include "my.h"

int		my_getnbr_base(char *nbr, char *base_from)
{
  int		base;
  int		i;
  int		k;
  int		r;

  r = 0;
  base = my_strlen(base_from);
  i = 0;
  while (nbr[i] != '\0')
    {
      k = 0;
      while (nbr[i] != base_from[k])
	k = k + 1;
      r = r * base + k;
      i = i + 1;
    }
  return (r);
}

char		*my_putnbr_base(unsigned int base_10, char *base_to)
{
  int		i;
  int		k;
  unsigned int	nbr;
  int		size;
  char		*r;

  size = 0;
  nbr = base_10;
  while (nbr > 0)
    {
      nbr = nbr / my_strlen(base_to);
      size = size + 1;
    }
  i = size - 1;
  r = malloc((size + 1) * sizeof(*r));
  r[size] = '\0';
  while (base_10 > 0)
    {
      k = base_10 % my_strlen(base_to);
      r[i] = base_to[k];
      base_10 = base_10 / my_strlen(base_to);
      i = i - 1;
    }
  return (r);
}

char		*convert_to_bin(int base_10)
{
  int		i;
  int		k;
  char		*base_to;
  char		*r;

  if (!(r = xmalloc(sizeof(*r) * 9)))
    return (NULL);
  i = 8;
  r[i--] = '\0';
  base_to = "01";
  while (base_10 > 0)
    {
      k = base_10 % 2;
      r[i] = base_to[k];
      base_10 = base_10 / 2;
      i--;
    }
  while (i >= 0)
    r[i--] = '0';
  return (r);
}
