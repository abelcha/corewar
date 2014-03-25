/*
** instruction_tab.c for lol in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Tue Mar 18 12:12:34 2014 
** Last update Tue Mar 25 06:59:34 2014 chalie_a
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include "x_error.h"

int	which_instruction(char *str)
{
  int	i;

  i = -1;
  while (++i < 16)
    {
      if (!my_strcmp(op_tab[i].name, str))
	return (i + 1);
    }
  return (X_ERROR(str, INV_INST));
}
