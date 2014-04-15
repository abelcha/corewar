/*
** main.c for test in /home/dong_n/rendu/epur
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Mon Mar 17 19:00:51 2014 dong_n
** Last update Sun Apr 13 18:17:10 2014 dong_n
*/

#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "my.h"

char	*epur_str(char *str)
{
  char	*ret;
  int	k;
  int	i;

  if (!(ret = my_calloc(sizeof(*ret), (my_strlen(str) + 4))))
    return (NULL);
  i = 0;
  k = 0;
  while (str[i] != '\0' && str[i] != COMMENT_CHAR && str[i] != ';')
    {
      while (!(str[i] > 32 && str[i] < 127) && str[i] != '\0')
	i++;
      while (str[i] > 32 && str[i] < 127 &&
	     str[i] != COMMENT_CHAR && str[i] != ';')
	ret[k++] = str[i++];
      ret[k++] = ' ';
      if (str[i - 1] == SEPARATOR_CHAR)
	k--;
    }
  return (ret);
}
