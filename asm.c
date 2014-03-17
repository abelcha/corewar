/*
** asm.c for lol in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 18:26:38 2014 
** Last update Mon Mar 17 00:08:10 2014 
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corewar.h"

char	*gnl(int);

typedef struct s_info
{
  char	*filename;
  char	*comment;
} t_info;

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
  i = -1;
  while (stock[++i] && (j = -1))
    while (stock[i][++j])
      if (stock[i][j] == '.')
	if (!strncmp(&(stock[i][j + 1]), "name", 4))
	  (*info)->filename = cut_double_quotes(&(stock[i][j + 1]));
	else if (!strncmp(&(stock[i][j + 1]), "comment", 6))
          (*info)->comment = cut_double_quotes(&stock[i][j + 1]);
  return (SUCCESS);
}

int		main()
{
  int		fd;
  char		**stock;
  int		i;
  t_info        *info;
  i = -1;
  stock = calloc(1024, sizeof(char *));
  fd = open( "sm.s", O_RDONLY);
  while (stock[++i] = gnl(fd));
  get_info(stock, &info);
  printf("filename is '%s'\n", info->filename);
  printf("comment is '%s'\n", info->comment);
}
