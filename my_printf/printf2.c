/*
** ft_putchar.c for printf in /home/tovazm/rendu/Printf
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 19:06:59 2014 
** Last update Wed Mar 19 20:44:43 2014 
*/

#include "my_printf.h"

void	my_putchar(char c)
{
  write(fdp, &c, 1);
}

void    my_putstr(char *str)
{
  write(fdp, str, my_strlen(str));
}

void    my_printnb(size_t len, va_list arg)
{
  int             nb;

  len = 0;
  nb = va_arg(arg, int);
  x_atoi(nb);
}

void    my_printstr(size_t len, va_list arg)
{
  char  *tmp;
  int   counter;

  counter = 0;
  tmp = va_arg(arg, char *);
  len += my_strlen(tmp);
  my_putstr(tmp);
}

void    x_atoi(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = - nb;
    }
  if (nb > 9)
    {
      x_atoi(nb / 10);
      x_atoi(nb % 10);
    }
  else
    my_putchar((nb + '0'));
}
