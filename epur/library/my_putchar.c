/*
** my_putchar.c for my_putchar in /home/dong_n/rendu/Piscine-C-lib/my
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Tue Oct  8 20:26:03 2013 david$
** Last update Tue Jan 14 17:42:51 2014 david$
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
