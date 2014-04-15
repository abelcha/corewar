/*
** asm.c for lol in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 18:26:38 2014 
** Last update Sun Apr 13 22:57:19 2014 dong_n
*/

#include "my.h"
#include "corewar.h"

void		my_print_info(char *file, header_t *header)
{
  my_putstr("Assembling ");
  my_putstr(file);
  my_putstr(":\n           ");
  my_putstr(header->prog_name);
  my_putstr("\n           ");
  my_putstr(header->comment);
  my_putchar('\n');
}

int		main(int ac, char **av)
{
  char		**stock;
  header_t	*header;
  int		i;

  if (ac < 2)
    {
      my_put_error("Usage: ./asm [champ]\n");
      return (-1);
    }
  i = 1;
  while (i < ac)
    {
      if (!(header = my_calloc(1, sizeof(*header))))
	return (FAILURE);
      if (!(stock = my_getfile(av[i], header)))
	return (FAILURE);
      my_print_info(av[i], header);
      if (asm_parsing(header, stock, av[i]) == FAILURE)
	return (FAILURE);
      i++;
    }
  return (0);
}
