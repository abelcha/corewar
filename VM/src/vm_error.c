/*
** main.c for trul in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:20:06 2014 chalie_a
** Last update Mon Mar 31 22:19:41 2014 chalie_a
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
  my_printf("syntax Error : \n");
  my_printf("Usage : ./corewar [-dumb nbr_cycle] [[-n prog_number]");
  my_printf("[-a load_address] prog_name]\n");
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
  printf("Error : number expected after '%s' statement\n", str);
  return (FAILURE);
}
