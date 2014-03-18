/*
** asm.c for lol in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 18:26:38 2014 
** Last update Tue Mar 18 21:15:31 2014 dong_n
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "my.h"
#include "corewar.h"

char	*gnl(int);

typedef struct s_info
{
  char	filename[128];
  char	comment[2048];
} t_info;

int		is_legit(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      while (!(str[i] > 32 && str[i] < 127) && str[i] != '\0')
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

int		get_info(char **stock, t_info **info)
{
  int		i;
  int		j;

  if (!(*info = malloc(sizeof(t_info))))
    return (FAILURE);
  memset((*info)->filename, 0, 128);
  memset((*info)->comment, 0, 2048);
  i = -1;
  while (stock[++i] && (j = -1))
    while (stock[i][++j])
      if (stock[i][j] == '.')
	{
	  if (!strncmp(&(stock[i][j + 1]), "name", 4))
	    strcpy((*info)->filename, cut_double_quotes(&(stock[i][j + 1])));
	  else if (!strncmp(&(stock[i][j + 1]), "comment", 6))
	    strcpy((*info)->comment, cut_double_quotes(&stock[i][j + 1]));
	}
  return (SUCCESS);
}

void		header_handler(t_info *info)
{
  int	i;

  i = -1;
  printf("0xea83f3");
  while (++i < 128)
    printf("%x", info->filename[i]);
  i = -1;
  while (++i < 2048)
    printf("%x", info->comment[i]);
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
  t_list        *list;
  i = -1;
  stock = calloc(4096, sizeof(char *));
  fd = open(av[1], O_RDONLY);
  if (fd == -1)
    {
      printf("no such file\n");
      return (FAILURE);
    }
  while ((stock[++i] = gnl(fd)))
    if (is_legit(stock[i]) == FALSE)
      {
	free(stock[i]);
	i--;
      }
    else if (only_label(stock[i]) == TRUE)
      {
	stock[i] = ls_joint(stock[i], gnl(fd));
      }
  //  info = get_info(stock, info);
  asm_parsing(list, stock);
}
