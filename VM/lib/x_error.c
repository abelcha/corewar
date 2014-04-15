/*
** x_error.c for xerroe in /home/chalie_a/PSU_2013_my_select/lib
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Mon Jan 13 07:21:37 2014 chalie_a
** Last update Sun Apr 13 17:14:30 2014 dong_n
*/

#include <unistd.h>
#include "x_error.h"
#include "corewar.h"
#include "my.h"

int	put_error(char *str)
{
  write(STDERR_FILENO, "Error : ", 8);
  write(STDERR_FILENO, str, my_strlen(str));
  return (FAILURE);
}

void	*put_null_error(char *str)
{
  write(STDERR_FILENO, "Error : ", 8);
  write(STDERR_FILENO, str, my_strlen(str));
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
