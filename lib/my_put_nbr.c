/*
** my_put_nbr.c for my_put_nbr in /home/dong_n/rendu/Piscine-C-Jour_03
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Wed Oct  2 17:00:14 2013 david$
** Last update Wed Jan 15 10:29:10 2014 david$
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	power;

  power = 1;
  if (nb == -2147483648)
    {
      my_putchar('-');
      my_putchar('2');
      nb = 147483648;
    }
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  while (power <= (nb / 10))
      power = power * 10;
  while (power >= 1)
    {
      my_putchar(nb / power + '0');
      nb = nb % power;
      power = power / 10;
    }
  return (0);
}
