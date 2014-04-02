/*
** main.c for trul in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:20:06 2014 chalie_a
** Last update Wed Apr  2 21:55:08 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"

int		syntax_error()
{
  my_fprintf(STDERR_FILENO, "syntax Error : \n");
  my_fprintf(STDERR_FILENO, "Usage : ./corewar [-dumb nbr_cycle] [[-n prog_number]");
  my_fprintf(STDERR_FILENO, "[-a load_a] prog_name]\n");
  return (FAILURE);
}

int		option_error(int cmp)
{
  static char	*tab[3] = {"dump", "load address", "set program number"};

  my_fprintf(STDERR_FILENO, "Error : Cannot %s with a negative number\n", tab[cmp]);
  return (FAILURE);
}

int		not_a_number(char *str)
{
  my_fprintf(STDERR_FILENO, "Error : number expected after '%s' statement\n", str);
  return (FAILURE);
}
