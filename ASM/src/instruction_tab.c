/*
** instruction_tab.c for lol in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Tue Mar 18 12:12:34 2014 
** Last update Tue Mar 18 20:46:23 2014 
*/

#include "op.h"
#include "corewar.h"

int	which_instruction(char *str)
{
  int	i;

  i = -1;
  while (++i < 16)
    {
      X
      if (!strcmp(op_tab[i].name, str))
	return (i);
    }
  return (UNKNOWN);
}