/*
** dump.c for lol in /home/tovazm/rendu/corewar/VM/src
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 13 20:58:52 2014 chalie_a
** Last update Sun Apr 13 22:19:27 2014 chalie_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "vm.h"

static void	convert_base(int nbr, int base)
{
  int		modulo;

  modulo = nbr % base;
  nbr /= base;
  if (nbr)
    convert_base(nbr, base);
  if (modulo > 9)
    my_putchar('A' + (modulo % 10));
  else
    my_put_nbr(modulo);
}

static int	new_line(int i, int line, t_arena *arena)
{
  my_putchar('\n');
  if (i < arena->mem_size)
    {
      convert_base(line, BASE);
      write(1, TAB, 2);
      line++;
    }
  if (i < arena->mem_size)
    my_putchar(' ');
  return (line);
}

static void	to_hex(char c)
{
  if (c <= BASE)
    my_putchar('0');
  convert_base(c, 16);
}

int	print_map(t_champ *champ, t_arena *arena)
{
  int	i;
  int	line;

  i = 0;
  line = 0;
  convert_base(line++, BASE);
  while (i < arena->mem_size)
    {
      if (i == 0)
	write(1, TAB, 2);
      to_hex(arena->arena[i]);
      if (++i % BASE == 0)
	line = new_line(i, line, arena);
    }
  return (DUMP);
}
