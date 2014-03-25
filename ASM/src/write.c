/*
** write.c for lol in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sat Mar 22 07:17:03 2014 chalie_a
** Last update Tue Mar 25 06:52:19 2014 chalie_a
*/

#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "corewar.h"

void		sb(void *source, int size)
{
  typedef unsigned char TwoBytes[2];
  typedef unsigned char FourBytes[4];
  typedef unsigned char EightBytes[8];
  FourBytes	*src4;
  unsigned char	temp;
  TwoBytes	*src2;

  if(size == 2)
    {
      src2 = (TwoBytes *)source;
      temp = (*src2)[0];
      (*src2)[0] = (*src2)[1];
      (*src2)[1] = temp;
      return;
    }
  if(size == 4)
    {
      src4 = (FourBytes *)source;
      temp = (*src4)[0];
      (*src4)[0] = (*src4)[3];
      (*src4)[3] = temp;
      temp = (*src4)[1];
      (*src4)[1] = (*src4)[2];
      (*src4)[2] = temp;
      return ;
    }
  return ;
}

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
	  sb(&conv, get_real_size(tmp->param[j].type, tmp->num));
	  write(fd, &(conv), get_real_size(tmp->param[j].type, tmp->num));
	}
      tmp = tmp->next;
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
  sb(&(header->prog_size), sizeof(int));
  printf("total prog_size = %d\n",  header->prog_size);
  memset(header->prog_name, 0, PROG_NAME_LENGTH);
  memset(header->comment, 0, COMMENT_LENGTH);
  strcpy(header->prog_name, info->filename);
  strcpy(header->comment, info->comment);
  header->magic = 15369203;
  sb(&header->magic, sizeof(int));
  write(fd, header, 2192);
  write_data(list, fd);
  return (SUCCESS);
}
