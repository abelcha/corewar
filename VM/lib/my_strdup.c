/*
** my_strdup.c for my_strdup in /home/dong_n/rendu/corewar/lib
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Apr 13 15:17:06 2014 dong_n
** Last update Sun Apr 13 15:17:09 2014 dong_n
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*ret;

  if (!(ret = xmalloc((my_strlen(src) + 1) * sizeof(*ret))))
    return (NULL);
  my_strcpy(ret, src);
  return (ret);
}
