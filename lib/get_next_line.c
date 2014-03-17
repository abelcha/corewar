/*
** get_next_line.c for get_next_line in /home/dong_n/rendu/get_next_line
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Wed Nov 13 18:26:05 2013 david$
** Last update Sun Jan 12 22:23:38 2014 david$
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*my_realloc(char *ret, int size, int rd)
{
  char	*str;
  int	i;

  ret[size] = '\0';
  if (size == 0)
    return (ret);
  if (!(str = malloc((size + rd + 2) * sizeof(*str))))
    return (NULL);
  i = 0;
  while (ret[i] != '\0')
    {
      str[i] = ret[i];
      i++;
    }
  str[i] = '\0';
  free(ret);
  return (str);
}

char	*ret_next_line(char *ret, int i, int k)
{
  if (i > 0 || k == 1)
    {
      ret = my_realloc(ret, i, 0);
      return (ret);
    }
  free(ret);
  return (NULL);
}

char	*my_verif_read(char *ret, int rd, int i)
{
  if (rd == -1)
    return (NULL);
  ret = my_realloc(ret, i, rd);
  return (ret);
}

char		*get_next_line(const int fd)
{
  static int	rd;
  static int	j = 0;
  static char	buffer[ABS(BUFF_SIZE)];
  int		i;
  char		*ret;

  i = 0;
  if (!(ret = malloc((BUFF_SIZE + 1) * sizeof(*ret))))
    return (NULL);
  if (j != 0)
    while (j < rd && buffer[j] != '\n')
      ret[i++] = buffer[j++];
  if (j < rd && buffer[j++] == '\n')
    return (ret_next_line(ret, i, 1));
  while ((rd = read(fd, buffer, BUFF_SIZE)) != 0)
    {
      j = 0;
      if (!(ret = my_verif_read(ret, rd, i)))
	return (NULL);
      while (j < rd && buffer[j] != '\n')
	ret[i++] = buffer[j++];
      if ((j < rd && buffer[j++] == '\n') || i == 0 || i > 500)
	return (ret_next_line(ret, i, 1));
    }
  return (ret_next_line(ret, i, 0));
}
