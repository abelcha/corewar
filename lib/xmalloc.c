/*
** xmalloc.c for xmalloc in /home/dong_n/Documents/library
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Mon Feb  3 10:56:36 2014 david$
** Last update Wed Mar 12 20:03:20 2014 dong_n
*/

#include <stdlib.h>
#include "my.h"

void	*xmalloc(unsigned long size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr)
    return (ptr);
  my_put_error("Error: Malloc failed\n");
  return (NULL);
}
