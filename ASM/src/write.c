/*
** write.c for lol in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sat Mar 22 07:17:03 2014 chalie_a
** Last update Sun Apr  6 16:39:38 2014 chalie_a
*/

#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "corewar.h"

int		get_prog_size(t_list *list)
{
  int		i;
  int		size;
  t_list	*tmp;

  tmp = list->next;
  size = 0;
  while (tmp != list)
    {
      size += tmp->size;
      tmp = tmp->next;
    }
  return (size);
}

int		write_data(t_list *list, int fd)
{
  t_list	*tmp;
  int		j;
  int		conv;
  int		size;

  tmp = list->next;
  while (list != tmp)
    {
      j = -1;
      write(fd, &(tmp->num), 1);
      if (tmp->coding_byte)
	write(fd, &(tmp->coding_byte), 1);
      while (++j < 4)
	{
	  conv = tmp->param[j].param;
	  convert_indian(&conv, get_real_size(tmp->param[j].type, tmp->num));
	  write(fd, &(conv), get_real_size(tmp->param[j].type, tmp->num));
	  x_free(tmp->param[j].l_flag);
	}
      x_free(tmp->label);
      tmp = tmp->next;
      x_free(tmp->prev);
    }
  return (SUCCESS);
}

int		write_in_file(t_list *list, t_info *info)
{
  int		fd;
  header_t	*header;

  header = calloc(1, sizeof(header_t));
  if (!header)
    return (0);
  fd = open("result.cor", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1)
    return (FAILURE);
  header->prog_size = get_prog_size(list);
  SWAP(header->prog_size);
  memset(header->prog_name, 0, PROG_NAME_LENGTH);
  memset(header->comment, 0, COMMENT_LENGTH);
  strcpy(header->prog_name, info->filename);
  strcpy(header->comment, info->comment);
  header->magic = 15369203;
  SWAP(header->magic);
  write(fd, header, 2192);
  write_data(list, fd);
  x_free(info);
  x_free(header);
  close(fd);
  return (SUCCESS);
}
