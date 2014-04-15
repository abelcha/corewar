/*
** my_calloc.c for my_calloc in /home/dong_n/rendu/corewar/ASM/src
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sat Apr 12 17:27:02 2014 dong_n
** Last update Sun Apr 13 00:12:28 2014 dong_n
*/

#include <stdlib.h>
#include "my.h"

void	*my_memset(void *s, int c, int n)
{
  char	*tmp;
  int	i;

  tmp = s;
  i = 0;
  while (i < n)
    tmp[i++] = c;
  return (tmp);
}

void	*my_calloc(int nmemb, int size)
{
  void	*ptr;

  if (!(ptr = xmalloc(nmemb * size)))
    return (NULL);
  ptr = my_memset(ptr, 0, nmemb * size);
  return (ptr);
}
