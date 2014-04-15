/*
** write.c for lol in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sat Mar 22 07:17:03 2014 chalie_a
** Last update Sun Apr 13 17:28:03 2014 dong_n
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "corewar.h"
#include "my.h"

int		get_prog_size(t_list *list)
{
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
      my_delete_elem(tmp->prev);
    }
  return (SUCCESS);
}

int		write_in_file(t_list *list, header_t *header, char *name)
{
  int		fd;
  char		*result;
  int		len;

  len = my_strlen(name);
  if (!(result = xmalloc(len + 3 * sizeof(*name))))
    return (FAILURE);
  my_strcpy(result, name);
  my_strcpy(&result[len - 1], "cor");
  if ((fd = open(result, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    return (FAILURE);
  header->prog_size = get_prog_size(list);
  header->magic = COREWAR_EXEC_MAGIC;
  SWAP(header->prog_size);
  SWAP(header->magic);
  write(fd, header, sizeof(*header));
  write_data(list, fd);
  x_free(header);
  close(fd);
  return (SUCCESS);
}
