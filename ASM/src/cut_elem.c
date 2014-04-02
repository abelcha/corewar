/*
** asm.c for lol in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 18:26:38 2014 
** Last update Thu Apr  3 00:37:55 2014 chalie_a
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "op.h"
#include "my.h"
#include "corewar.h"
#include "x_error.h"

char		*gnl(int);

extern int	extended;

char		*cut_double_quotes(char	*str)
{
  int		i;
  char		*tmp;

  i = -1;
  while (str[++i] != '"');
  tmp = strdup(&str[i + 1]);
  i = -1;
  while (tmp[i++ + 1] != '"');
  tmp[i] = '\0';
  return (tmp);
}

int		get_info(char *stock, t_info *info)
{
  int		j;

  j = -1;
  while (stock[++j])
    if (stock[j] == '.')
      {
	if (!strncmp(&(stock[j + 1]), "name", 4))
	  my_strcpy(info->filename, cut_double_quotes(&(stock[j + 1])), 1);
	else if (!strncmp(&(stock[j + 1]), "comment", 6))
	  my_strcpy(info->comment, cut_double_quotes(&(stock[j + 1])), 1);
	else if (!strncmp(&(stock[j + 1]), "extended", 6))
	  extended = TRUE;
	else
	  my_fprintf(STDERR_FILENO, "Warning : Unknown extension '%s'\n", stock);
	break ;
      }
  return (TRUE);
}

int		first_points(char *str, t_info *info)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] == '\t' || str[i] == ' ');
    else if (str[i] == '.')
      return (get_info(str, info));
    else
      return (FALSE);
  return (FALSE);
}
