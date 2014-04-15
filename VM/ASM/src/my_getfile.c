/*
** my_getfile.c for getfile in /home/dong_n/rendu/corewar/ASM
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Apr 13 17:18:02 2014 dong_n
** Last update Sun Apr 13 22:50:50 2014 dong_n
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static int	is_legit(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      while (!(str[i] > 32 && str[i] < 127) && str[i])
        i++;
      if (str[i] == COMMENT_CHAR || str[i] == ';' || str[i] == '\0')
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
      if (str[i] == LABEL_CHAR)
	return (TRUE);
      else if (str[i] != ' ' && str[i] != '\t')
	return (FALSE);
    }
  return (FALSE);
}

static char	*ls_joint(char *str1, int fd)
{
  char		*str2;
  char		*tmp;

  str2 = gnl(fd);
  while (str2 && str2[0] == '\0')
    str2 = gnl(fd);
  tmp = my_calloc(my_strlen(str1) + my_strlen(str2) + 2, sizeof(*tmp));
  my_strcpy(tmp, str1);
  my_strcat(tmp, " ");
  my_strcat(tmp, str2);
  free(str1);
  free(str2);
  return (tmp);
}

static int	my_filelen(char *file)
{
  int		i;
  int		fd;
  char		*line;

  i = 0;
  if ((fd = open_file(file)) == FAILURE)
    return (FAILURE);
  while ((line = gnl(fd)))
    {
      i++;
      if (is_legit(line) == FALSE)
	i--;
      else if (only_label(line) == TRUE)
	i--;
      free(line);
    }
  close(fd);
  return (i);
}

char		**my_getfile(char *file, header_t *header)
{
  int		i;
  int		fd;
  int		file_len;
  char		**stock;

  i = -1;
  if ((file_len = my_filelen(file)) == FAILURE)
    return (NULL);
  if ((fd = open_file(file)) == FAILURE)
    return (NULL);
  if (!(stock = my_calloc(file_len + 1, sizeof(*stock))))
    return (NULL);
  while ((stock[++i] = gnl(fd)))
    if (is_legit(stock[i]) == FALSE || first_points(stock[i], header) == TRUE)
      {
	free(stock[i]);
	i--;
      }
    else if (only_label(stock[i]) == TRUE)
      stock[i] = ls_joint(stock[i], fd);
  close(fd);
  return (stock);
}
