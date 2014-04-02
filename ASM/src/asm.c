/*
** asm.c for lol in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 18:26:38 2014 
** Last update Thu Apr  3 00:26:17 2014 chalie_a
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

char	*gnl(int);

int	extended = FALSE;

static int	is_legit(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      while (!(str[i] > 32 && str[i] < 127) && str[i])
        i++;
      if (str[i] == '#' || str[i] == ';' || str[i] == '\0')
        return (FALSE);
      else
        return (TRUE);
    }
  return (FALSE);
}

static int	only_label(char *str)
{
  int		i;

  i = my_strlen(str);
  while (--i > 0)
    {
      if (str[i] == ':')
	return (TRUE);
      else if (str[i] != ' ' && str[i] != '\t')
	return (FALSE);
    }
  return (FALSE);
}

static char	*ls_joint(char *str1, char *str2)
{
  char		*tmp;

  if (!str2)
    return (str1);
  tmp = calloc(my_strlen(str1) + my_strlen(str2) + 2, sizeof(char));
  strcpy(tmp, str1);
  strcat(tmp, " ");
  strcat(tmp, str2);
  free(str1);
  free(str2);
  return (tmp);
}

int		main(int ac, char **av)
{
  int		fd;
  char		**stock;
  int		i;
  t_info	*info;
  t_list	*list;

  i = -1;
  info = malloc(sizeof(t_info));
  if ((fd = open_file(av[1])) == FAILURE)
    return (FAILURE);
  stock = calloc(4096, sizeof(char *));
  while ((stock[++i] = gnl(fd)))
    if (is_legit(stock[i]) == FALSE || first_points(stock[i], info) == TRUE)
      {
	free(stock[i]);
	i--;
      }
    else if (only_label(stock[i]) == TRUE)
      stock[i] = ls_joint(stock[i], gnl(fd));
  close(fd);
  asm_parsing(info, list, stock);
}
