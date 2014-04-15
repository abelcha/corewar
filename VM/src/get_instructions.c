/*
** main.c for main in /home/dong_n/rendu/corewar/VM/src
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Mar 30 17:55:36 2014 dong_n
** Last update Sun Apr 13 22:11:45 2014 chalie_a
*/

#include "vm.h"

void		get_params_value2(char *buff, int *i,
				  const int j, t_cmd *instruct)
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
	  instruct->args_value[j] = ((instruct->args_value[j] << 8
				      & 0xFFFFFF00) |
				     (unsigned char)buff[(*i)++]);
	}
      instruct->args_value[j] = (short int)instruct->args_value[j];
    }
}

void		get_params_value4(char *buff, int *i,
				  const int j, t_cmd *instruct)
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
	  instruct->args_value[j] = ((instruct->args_value[j] << 8
				      & 0xFFFFFF00) |
				     (unsigned char)buff[(*i)++]);
	}
    }
}

void		get_ld_params(char *buff, int *i,
			      const int j, t_cmd *instruct)
{
  int		k;

  k = 0;
  if (j == 0)
    {
      instruct->args_value[0] = 0;
      while (k++ < 4)
	{
	  instruct->args_value[0] = ((instruct->args_value[0] << 8
				      & 0xFFFFFF00) |
				     (unsigned char)buff[(*i)++]);
	}
    }
  else
    get_params_value2(buff, i, j, instruct);
}

static void		get_args(char *buff, t_cmd *instruct, int *i)
{
  int			k;

  k = 0;
  if (instruct->op == 1)
    {
      instruct->args_type[0] = 2;
      instruct->args_value[0] = 0;
      while (k++ < 4)
	{
	  instruct->args_value[0] = ((instruct->args_value[0] << 8
				      & 0xFFFFFF00) |
				     (unsigned char)buff[(*i)++]);
	}
    }
  else
    {
      instruct->args_type[0] = 2;
      get_params_value2(buff, i, 0, instruct);
    }
}

int		get_instruction(char *arena, t_champ *champ)
{
  int		i;

  i = champ->pc;
  if ((champ->cmd->op = arena[i++]) > 16
      || champ->cmd->op < 1)
    return (FAILURE);
  if (CODING_BYTE(champ->cmd->op) == TRUE)
    get_args_oct(arena, champ->cmd, &i);
  else
    get_args(arena, champ->cmd, &i);
  champ->new_pc = i;
  return (SUCCESS);
}
