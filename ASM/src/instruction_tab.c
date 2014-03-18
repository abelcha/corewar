/*
** instruction_tab.c for lol in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Tue Mar 18 12:12:34 2014 
** Last update Tue Mar 18 21:34:22 2014 dong_n
*/

#include "op.h"
#include "corewar.h"

int	which_instruction(char *str)
{
  int	i;

  i = -1;
  while (++i < 16)
    {
      if (!strcmp(op_tab[i].name, str))
	return (i + 1);
    }
  return (UNKNOWN);
}
