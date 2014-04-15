/*
** x_open.c for open in /home/dong_n/rendu/corewar/ASM
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Apr 13 17:24:36 2014 dong_n
** Last update Sun Apr 13 17:25:58 2014 dong_n
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "x_error.h"
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
