/*
** my_putstr.c for my_putstr in /home/dong_n/rendu/Piscine-C-Jour_04
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Thu Oct  3 10:22:53 2013 david$
** Last update Wed Mar 12 02:03:04 2014 dong_n
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(char *str)
{
  int	size;

  size = my_strlen(str);
  write(1, str, size);
}

void	my_put_error(char *str)
{
  int	size;

  if (!str)
    return ;
  size = my_strlen(str);
  write(2, str, size);
}
