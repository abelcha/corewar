/*
** xmalloc.c for xmalloc in /home/dong_n/Documents/library
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Mon Feb  3 10:56:36 2014 david$
** Last update Wed Mar 19 20:27:45 2014 
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
my_fprintf(STDERR_FILENO, "Error : Malloc Failed\n");
return (NULL);
}
