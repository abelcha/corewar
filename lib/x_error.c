/*
** x_error.c for xerroe in /home/chalie_a/PSU_2013_my_select/lib
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Mon Jan 13 07:21:37 2014 chalie_a
** Last update Wed Mar 19 02:24:44 2014 
*/

#include <unistd.h>
#include "x_error.h"
#include "corewar.h"

int	my_strlen(char *str);

void	write_err(char *str)
{
  write(STDERR_FILENO, "Error : ", 8);
  write(STDERR_FILENO, str, my_strlen(str));
}
int	put_error(char *str)
{
  write_err(str);
  return (FAILURE);
}

void	*put_null_error(char *str)
{
  write_err(str);
  return (NULL);
}

void	my_puterr(char *str)
{
  write(STDERR_FILENO, str, my_strlen(str));
}

int	putxerr(char *name, char *str)
{
  write(STDERR_FILENO, "Error : '", 9);
  write(STDERR_FILENO, name, my_strlen(name));
  write(STDERR_FILENO, "'", 1);
  write(STDERR_FILENO, str, my_strlen(str));
  return (FAILURE);
}
