/*
** main.c for main in /home/dong_n/rendu/corewar/VM/src
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Mar 30 17:55:36 2014 dong_n
** Last update Tue Apr  8 19:02:38 2014 chalie_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "corewar.h"
#include "my.h"
#include "vm.h"
#include "op.h"

void		get_params_value2(char *buff, int *i, int j, t_cmd *instruct)
{
  int		k;

  k = 0;
  if (instruct->args_type[j] == 1)
    instruct->args_value[j] = buff[(*i)++];
  else
    {
      instruct->args_value[j] = 0;
      while (k++ < 2)
	{
	  instruct->args_value[j] = ((instruct->args_value[j] << 8 & 0xFFFFFF00) |
			       (unsigned char)buff[(*i)++]);
	}
      instruct->args_value[j] = (short int)instruct->args_value[j];
    }
}

void		get_params_value4(char *buff, int *i, int j, t_cmd *instruct)
{
  int		k;

  k = 0;
  if (instruct->args_type[j] != 2)
    get_params_value2(buff, i, j, instruct);
  else
    {
      instruct->args_value[j] = 0;
      while (k++ < 4)
	{
	  instruct->args_value[j] = ((instruct->args_value[j] << 8 & 0xFFFFFF00) |
			       (unsigned char)buff[(*i)++]);
	}
    }
}

void		get_ld_params(char *buff, int *i, int j, t_cmd *instruct)
{
  int		k;

  k = 0;
  if (j == 0)
    {
      instruct->args_value[0] = 0;
      while (k++ < 4)
	{
	  instruct->args_value[0] = ((instruct->args_value[0] << 8 & 0xFFFFFF00) |
			       (unsigned char)buff[(*i)++]);
	}
    }
  else
    get_params_value2(buff, i, j, instruct);
}

void		get_args_oct(char *buff, t_cmd *instruct, int *i)
{
  char		oct;
  int		k;
  int		j;

  k = 6;
  j = 0;
  oct = buff[(*i)++];
  while (k >= 0 && j < op_tab[instruct->op - 1].nbr_args)
    {
      instruct->args_type[j] = (oct >> k) & 3;
      if (instruct->op == 2 || instruct->op == 13)
	get_ld_params(buff, i, j, instruct);
      else if (instruct->op == 3 || (instruct->op > 5 && instruct->op < 9))
	get_params_value4(buff, i, j, instruct);
      else if (instruct->op == 16 || instruct->op == 14 ||
	       (instruct->op > 3 && instruct->op < 6) || instruct->op == 10 ||
	       instruct->op == 11)
	get_params_value2(buff, i, j, instruct);
      else
	(*i)++;
      k = k - 2;
      j++;
    }
}

void		get_args(char *buff, t_cmd *instruct, int *i)
{
  int		k;

  k = 0;
  if (instruct->op == 1)
    {
      instruct->args_type[0] = 2;
      instruct->args_value[0] = 0;
      while (k++ < 4)
	{
	  instruct->args_value[0] = ((instruct->args_value[0] << 8 & 0xFFFFFF00) |
				     (unsigned char)buff[(*i)++]);
	}
    }
  else
    {
      instruct->args_type[0] = 2;
      get_params_value2(buff, i, 0, instruct);
    }
}

int		get_instruction(char *arena, t_cmd *cmd)
{
  int		i;

  i = 0;
  if ((cmd->op = arena[i++]) > 16
      || cmd->op < 1)
    return (FAILURE);
  if (HAVE_CODING_BYTE(cmd->op) == TRUE)
    get_args_oct(arena, cmd, &i);
  else
    get_args(arena, cmd, &i);
  printf("TAMERE = %d\n", cmd->args_type[0]);
  return (SUCCESS);
}
