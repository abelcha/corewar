/*
** split_list.c for coreware in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 19:08:43 2014 
** Last update Sun Apr 13 21:54:59 2014 dong_n
*/

#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "my.h"

int	check_chars(char *label, char c)
{
  int	i;

  i = -1;
  while (label[++i])
    if (label[i] == c)
      return (TRUE);
  return (FALSE);
}

int	cut_label(char *line, t_args *args)
{
  int	i;

  i = -1;
  while (line[++i])
    {
      if (line[i] == LABEL_CHAR)
	{
	  if (my_verif_label(line) == FAILURE)
	    return (0);
	  args->label = my_strndup(line, i);
	  return (i + 2);
	}
      if (line[i] == ' ')
	{
	  args->label = NULL;
	  return (0);
	}
    }
  return (0);
}

int	count_sep(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = -1;
  while (str[++i])
    {
      if (str[i] == ' ' || str[i] == SEPARATOR_CHAR || str[i] == '\t')
	j++;
    }
  return (j + 1);
}

void	split_loop(char *line, t_args *args, int x)
{
  int	i;
  int	j;

  j = -1;
  i = x;
  while (line[++i])
    {
      if (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
	{
	  line[i] = '\0';
	  args->args[++j] = my_strdup(&line[x]);
	  x = i + 1;
	}
      if (line[i + 1] == 0)
	args->args[++j] = my_strdup(&line[x]);
    }
}

int	split_list(char *line, t_args *args)
{
  int	x;

  if (!line || line[0] == '\0')
    return (FAILURE);
  x = cut_label(line, args);
  if (line[my_strlen(line) - 1] == LABEL_CHAR)
    return (FAILURE);
  if (!(args->args = my_calloc(count_sep(line) + 1, sizeof(*(args->args)))))
    return (FAILURE);
  split_loop(line, args, x);
  return (SUCCESS);
}
