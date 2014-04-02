/*
** ft_putchar.c for printf in /home/tovazm/rendu/Printf
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 19:06:59 2014 
** Last update Wed Apr  2 14:25:22 2014 chalie_a
*/

#include "my_printf.h"

void	x_putchar(char c, int fdp)
{
  write(fdp, &c, 1);
}

void    x_putstr(char *str, int fdp)
{
  write(fdp, str, my_strlen(str));
}

void    my_printnb(size_t len, va_list arg, int fdp)
{
  int             nb;

  len = 0;
  nb = va_arg(arg, int);
  x_atoi(nb, fdp);
}

void    my_printstr(size_t len, va_list arg, int fdp)
{
  char  *tmp;
  int   counter;

  counter = 0;
  tmp = va_arg(arg, char *);
  len += my_strlen(tmp);
  my_putstr(tmp, fdp);
}

void    x_atoi(int nb, int fdp)
{
  if (nb < 0)
    {
      x_putchar('-', fdp);
      nb = - nb;
    }
  if (nb > 9)
    {
      x_atoi(nb / 10, fdp);
      x_atoi(nb % 10 , fdp);
    }
  else
    x_putchar((nb + '0'), fdp);
}
