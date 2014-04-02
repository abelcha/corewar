/*
** error_parsing.c for yoko in /home/tovazm/rendu/corewar/ASM/src
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 13:39:47 2014 
** Last update Thu Apr  3 00:36:38 2014 chalie_a
*/

#include <fcntl.h>
#include "x_error.h"
#include "corewar.h"
#include "my.h"

int		open_file(char *str)
{
  int		fd;
  int		len;

  len = my_strlen(str) - 1;
  if (len < 3 || str[len] != 's' || str[len - 1] != '.')
    return (X_ERROR(str, FILE_EXT));
  fd = open(str, O_RDONLY);
  if (fd == -1)
    return (X_ERROR(str, NO_FILE));
  return (fd);
}
