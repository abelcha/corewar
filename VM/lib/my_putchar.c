/*
** my_putchar.c for loo in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Apr  2 14:39:13 2014 chalie_a
** Last update Sun Apr 13 20:59:31 2014 dong_n
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putchar_err(char c)
{
  write(2, &c, 1);
}
