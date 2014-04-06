/*
** main.c for test in /home/dong_n/rendu/epur
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Mon Mar 17 19:00:51 2014 dong_n
** Last update Sun Apr  6 13:39:53 2014 chalie_a
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "x_error.h"
#include "my.h"

char	*epur_str(char *str)
{
  char	*ret;
  int	k;
  int	i;

  if (!(ret = calloc(sizeof(*ret), (my_strlen(str) + 4))))
    return (ERROR_(MALLOC_FAIL));
  i = 0;
  k = 0;
  while (str[i] != '\0' && str[i] != '#' && str[i] != ';')
    {
      while (!(str[i] > 32 && str[i] < 127) && str[i] != '\0')
	i++;
      while (str[i] > 32 && str[i] < 127 && str[i] != '#' && str[i] != ';')
	ret[k++] = str[i++];
      ret[k++] = ' ';
      if (str[i - 1] == ',')
	k--;
    }
  if (k != 0)
    ret[k - 1] = '\0';
  else
    ret[k] = '\0';
  return (ret);
}
