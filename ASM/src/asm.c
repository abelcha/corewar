/*
** asm.c for lol in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 18:26:38 2014 
** Last update Mon Mar 17 21:31:37 2014 
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "corewar.h"

char	*gnl(int);

typedef struct s_info
{
  char	filename[128];
  char	comment[2048];
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
  memset((*info)->filename, 0, 128);
  memset((*info)->comment, 0, 2048);
  i = -1;
  while (stock[++i] && (j = -1))
    while (stock[i][++j])
      if (stock[i][j] == '.')
	if (!strncmp(&(stock[i][j + 1]), "name", 4))
	  strcpy((*info)->filename, cut_double_quotes(&(stock[i][j + 1])));
	else if (!strncmp(&(stock[i][j + 1]), "comment", 6))
          strcpy((*info)->comment, cut_double_quotes(&stock[i][j + 1]));
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

int		main(int ac, char **av)
{
  int		fd;
  char		**stock;
  int		i;
  t_info	*info;
  t_list	*list;

  i = -1;
  stock = calloc(4096, sizeof(char *));
  fd = open(av[1], O_RDONLY);
  if (fd == -1)
    {
      printf("no such file\n");
      return (FAILURE);
    } 
  while ((stock[++i] = gnl(fd)));
  list = malloc(sizeof(t_list));
  asm_parsing(list, stock);

  //  get_info(stock, &info);
}


