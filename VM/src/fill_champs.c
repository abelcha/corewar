/*
** fill_champs.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 31 17:30:06 2014 chalie_a
** Last update Sun Apr 13 22:06:29 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include "x_error.h"
#include "my.h"
#include "vm.h"

static int		rd_open(char *name, int *fd)
{
  if ((*fd = open(name, O_RDONLY)) != -1)
    return (SUCCESS);
  write(2, "Error : cannot open '", 20);
  write(2, name, my_strlen(name));
  write(2, "'\n", 2);
  return (FAILURE);
}

static int		read_header(t_champ *champ, const int fd)
{
  unsigned short	nb_read;

  nb_read = read(fd, champ->header, sizeof(t_hd));
  if (nb_read <= 0 || nb_read != sizeof(t_hd))
    return (ERROR("Error : Corrupted header\n"));
  SWAP(champ->header->prog_size);
  SWAP(champ->header->magic);
  if (champ->header->magic != COREWAR_EXEC_MAGIC)
    return (ERROR("Error : Wrong magic code\n"));
  return (SUCCESS);
}

static int		read_code(t_champ *champ, const int fd)
{
 unsigned short		nb_read;

 champ->code = my_calloc(champ->header->prog_size + 2, sizeof(char));
 nb_read = read(fd, champ->code, champ->header->prog_size + 1);
 if (nb_read <= 0 || nb_read != champ->header->prog_size)
   return (ERROR("Error : Invalid program size\n"));
 return (SUCCESS);
}

int			fill_champs(t_champ *champ)
{
  int			fd;

  if (rd_open(champ->line->filename, &fd) == FAILURE)
    return (FAILURE);
  if (read_header(champ, fd) == FAILURE)
    return (FAILURE);
  if (read_code(champ, fd) == FAILURE)
    return (FAILURE);
  close(fd);
  return (SUCCESS);
}
