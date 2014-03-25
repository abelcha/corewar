/*
** split_list.c for coreware in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 19:08:43 2014 
** Last update Sat Mar 22 06:13:27 2014 chalie_a
*/

#include "op.h"
#include "corewar.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "x_error.h"

extern int extended;

int	check_chars(char *label, char c)
{
  int	i;
  i = -1;
  while (label[++i])
    if (label[i] == c)
      return (TRUE);
  return (FALSE);
}

int	valid_char(char c)
{
  if (check_chars(VALID_CHAR, c) == FALSE)
    if (check_chars(VALID_CHAR, c) == FALSE)
      if (check_chars(EXT_CHAR, c) == TRUE || extended == TRUE)
	{
	  my_fprintf(STDERR_FILENO, BAD_CHAR, c);
	    return (FALSE);
	}
  return (TRUE);
}

int		cut_label(char *line, t_args *args)
{
  int		i;

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

  j = -1;
  if (!line)
    return (FAILURE);
  args->label = NULL;
  x = cut_label(line, args);
  i = x;
  if (line[strlen(line)] == ':')
    return (FAILURE);
  args->args = calloc(count_sep(line) + 1, sizeof(char *));
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
