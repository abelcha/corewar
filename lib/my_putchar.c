/*
** my_putchar.c for loo in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Apr  2 14:39:13 2014 chalie_a
** Last update Wed Apr  2 14:41:52 2014 chalie_a
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(STDOUT_FILENO, &c, 1);
}

void	my_putstr(char *str)
{
  write(STDOUT_FILENO, str, my_strlen(str));
}
