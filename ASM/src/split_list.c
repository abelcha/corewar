/*
** split_list.c for coreware in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 19:08:43 2014 
** Last update Wed Mar 19 01:23:12 2014 
*/

#include "op.h"
#include "corewar.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	cut_label(char *line, t_args *args/* char **label */)
{
  int	i;

  i = -1;
  while (line[++i])
    {
      if (line[i] == ':')
	{
	  args->label = strndup(line, i);
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
    if (str[i] == ' ' || str[i] == ',')
      j++;
  return (j + 1);
}

int		split_list(char *line, t_args *args)
{
  int		i;
  int		j;
  char		x;
  char		**stock;

  j = -1;
  if (!line)
    return (FAILURE);
  args->label = NULL;
  x = cut_label(line, args/* ->label) */);
  i = x;
  args->args = calloc(count_sep(line), sizeof(char *));
  while (line[++i])
    {
      if (line[i] == ' ' || line[i] == ',')
	{
	  line[i] = '\0';
	  args->args[++j] = strdup(&line[x]);
	  x = i + 1;
	}
      if (line[i + 1] == 0)
	args->args[++j] = strdup(&line[x]);
    }
  return (SUCCESS);
}
