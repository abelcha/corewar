/*
** my_strndup.c for my_strndup in /home/dong_n/rendu/corewar
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Apr 13 15:15:01 2014 dong_n
** Last update Sun Apr 13 15:21:38 2014 dong_n
*/

#include <stdlib.h>
#include "my.h"

char	*my_strndup(char *src, int n)
{
  char	*ret;

  if (!(ret = xmalloc(n + 1 * sizeof(*ret))))
    return (NULL);
  my_strncpy(ret, src, n);
  return (ret);
}
