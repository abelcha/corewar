/*
** gnl.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:55:09 2014 chalie_a
** Last update Sun Mar 16 18:30:17 2014 
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "get_next_line.h"

int             x_free(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
  ptr = NULL;
  return (54);
}

static char	*my_cat(char *s1, char *s2, const int flag)
{
  char		*new;
  int		i;
  int		j;
  int		len;

  i = -1;
  j = -1;
  if (!s1)
    return (s2);
  if (!s2)
    return (s1);
  len = strlen(s1) +  strlen(s2);
  if ((new = calloc((len + 1), sizeof(char))) == NULL)
    return (NULL);
  while (s1[++i])
    new[i] = s1[i];
  while (s2[++j])
    new[i + j] = s2[j];
  if (flag == 1 || flag == 3)
    x_free(s1);
  if (flag == 2 || flag == 3)
    x_free(s2);
  return (new);
}

static int	my_strchr(const char *str, const char c)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (i);
      ++i;
    }
  return (EOF);
}

static int	get_buffer(const int fd, char **str, int cr)
{
  static char	*buffer;
  static int	pos = -1;
  static int	nb = 0;

  if (pos == -1)
    {
      if (!(buffer = calloc((BUF_SIZE + 2), sizeof(char))))
	return (FAILURE);
      if ((nb = read(fd, buffer, BUF_SIZE)) == 0 && x_free(buffer))
	return (END_OF_FILE);
    }
  if ((cr = my_strchr(&buffer[++pos], CARRIAGE_RET)) == EOF)
    {
      *str = strdup(&buffer[pos]);
      pos = -1;
      return (RUNNING);
    }
  else
    {
      *str = strdup(&buffer[pos]);
      (*str)[cr] = '\0';
      pos = pos + cr;
      return (cr == nb - 1 && (pos = -1) ? x_free(buffer) : END_OF_LINE);
    }
}

char		*gnl(int fd)
{
  char		*tmp;
  char		*str;
  int		status;
  int		cr;

  cr = 0;
  tmp = NULL;
  str = NULL;
  while ((status = get_buffer(fd, &tmp, cr)) != END_OF_FILE)
    {
      str = my_cat(str, tmp, 1);
      if (status == END_OF_LINE)
	return (str);
    }
  x_free(tmp);
  return (NULL);
}
