/*
** fill_champs.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 31 17:30:06 2014 chalie_a
** Last update Wed Apr  2 00:47:05 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_colors.h"
#include "vm.h"

int	rd_open(char *name, int *fd)
{
  if ((*fd = open(name, O_RDONLY)) != -1)
    return (SUCCESS);
  printf("Error : cannot open '%s'\n", name);
  return (FAILURE);
}

int	read_header(t_champ *champ, int fd)
{
  int	nb_read;

  nb_read = read(fd, champ->header, sizeof(t_hd));
  if (nb_read != sizeof(t_hd))
    {
      printf("Error : Corrupted header\n");
      return (FAILURE);
    }
  convert_indian(&(champ->header->prog_size), 4);
  convert_indian(&(champ->header->magic), 4);
  if (champ->header->magic != COREWAR_EXEC_MAGIC)
    {
      printf("Error : Wrong magic code\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

int	read_code(t_champ *champ, int fd)
{
 int	nb_read;

 champ->code = calloc(champ->header->prog_size + 2, sizeof(char));
 nb_read = read(fd, champ->code, champ->header->prog_size + 1);

 if (nb_read != champ->header->prog_size)
   {
     printf("Error : Invalid program size\n");
     return (FAILURE);
   }
 return (SUCCESS);
}

int	fill_champs(t_champ *champ)
{
  int	fd;

  if (rd_open(champ->line->filename, &fd) == FAILURE)
    return (FAILURE);
  if (read_header(champ, fd) == FAILURE)
    return (FAILURE);
  if (read_code(champ, fd) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
