/*
** main.c for trul in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:20:06 2014 chalie_a
** Last update Sun Apr 13 22:22:21 2014 chalie_a
*/

#include <unistd.h>
#include "my.h"
#include "corewar.h"

int		syntax_error()
{
  write(2, "syntax Error : \n", 17);
  write(2, "Usage : ./corewar [-dumb nbr_cycle] [[-n prog_number]", 53);
  write(2, "[-a load_a] prog_name]\n", 25);
  return (FAILURE);
}

int		option_error(int cmp)
{
  static char	*tab[3] = {"dump", "load address", "set program number"};

  write(2, "Error : Cannot ", 15);
  write(2, tab[cmp], my_strlen(tab[cmp]));
  write(2, "with a negative number\n", 24);
  return (FAILURE);
}

int		not_a_number(char *str)
{
  write(2, "Error : number expected after '", 31);
  write(2, str, my_strlen(str));
  write(2, "' statement\n", 14);
  return (FAILURE);
}
