/*
** asm.c for lol in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 18:26:38 2014 
** Last update Fri Mar 28 12:00:40 2014 chalie_a
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

int		is_legit(char *str)
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
	break;
      }
  return (TRUE);
}

int		only_label(char *str)
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

char		*ls_joint(char *str1, char *str2)
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
  int		flag;

  i = -1;
  flag = 0;
  info = malloc(sizeof(t_info));
  if ((fd = open_file(av[1])) == FAILURE)
    return (FAILURE);
  stock = calloc(4096, sizeof(char *));
  while ((stock[++i] = gnl(fd)))
  {
    if (is_legit(stock[i]) == FALSE || first_points(stock[i], info) == TRUE)
      {
	free(stock[i]);
	  i--;
      }
    else if (only_label(stock[i]) == TRUE)
      stock[i] = ls_joint(stock[i], gnl(fd));
  }
  close(fd);
  asm_parsing(info, list, stock);
}
