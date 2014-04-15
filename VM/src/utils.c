/*
** utils.c for lo in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 10 17:27:34 2014 chalie_a
** Last update Sun Apr 13 22:33:33 2014 chalie_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"
#include "my.h"
#include "corewar.h"
#include "x_error.h"

int		is_number(char *str)
{
  int		i;

  i = -1;
  if (!str)
    return (FALSE);
  while (str[++i])
    if (str[i] > '9' || str[i] < '0')
      return (FALSE);
  return (TRUE);
}

int		delete_elem(t_champ *champ, t_arena *arena)
{
  char		*str;

  champ->prev->next = champ->next;
  champ->next->prev = champ->prev;
  if (champ == arena->winner)
    {
      my_putstr("The player : ");
      str = arena->winner->line->filename;
      while (*str != '.' && *str)
        write(1, str++, 1);
      my_putstr(" won the game\n");
      arena->total_size = 0;
      arena->winner = NULL;
    }
  x_free(champ->code);
  x_free(champ->line);
  x_free(champ->cmd);
  x_free(champ->header);
  x_free(champ);
  return (SUCCESS);
}

t_champ		*init_champ()
{
  t_champ	*champ;

  champ = malloc(sizeof(t_champ));
  champ->line = malloc(sizeof(t_line));
  champ->header = malloc(sizeof(t_hd));
  champ->cmd = malloc(sizeof(t_champ));
  if (!champ || !champ->line || !champ->cmd || !champ->header)
    return (ERROR_("Error : Malloc Failed\n"));
  my_memset(champ->reg, 0, REG_NUMBER * sizeof(int));
  my_memset(champ->cmd->args_type, 0, 3);
  my_memset(champ->cmd->args_value, 0, 3);
  champ->pc = 0;
  champ->cmd->op = 0;
  champ->line->prog_number = -1;
  champ->line->filename = NULL;
  champ->line->load_a = -1;
  champ->cycle = 1;
  champ->cycle_to_die = 0;
  champ->code = NULL;
  return (champ);
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
