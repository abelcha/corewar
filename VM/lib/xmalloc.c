/*
** xmalloc.c for xmalloc in /home/dong_n/Documents/library
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Mon Feb  3 10:56:36 2014 david$
** Last update Sun Apr 13 17:04:44 2014 dong_n
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "corewar.h"

void	*xmalloc(unsigned long size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr)
    return (ptr);
  my_put_error("Error : Malloc Failed\n");
  return (NULL);
}
