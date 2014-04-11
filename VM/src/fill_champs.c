/*
** fill_champs.c for qdf in /home/tovazm/rendu/corewar/VM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 31 17:30:06 2014 chalie_a
** Last update Thu Apr 10 18:48:27 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "x_error.h"
#include "x_colors.h"
#include "vm.h"

static int		rd_open(const char *name, int *fd)
{
  if ((*fd = open(name, O_RDONLY)) != -1)
    return (SUCCESS);
  my_fprintf(STDERR_FILENO, "Error : cannot open '%s'\n", name);
  return (FAILURE);
}

static int		read_header(t_champ *champ, const int fd)
{
  unsigned short	nb_read;

  nb_read = read(fd, champ->header, sizeof(t_hd));
  if (nb_read != sizeof(t_hd))
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

 champ->code = calloc(champ->header->prog_size + 2, sizeof(char));
 nb_read = read(fd, champ->code, champ->header->prog_size + 1);
 if (nb_read != champ->header->prog_size)
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
  return (SUCCESS);
}
