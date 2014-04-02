/*
** my_printf.c for pf in /home/tovazm/rendu/Printf
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 19:21:06 2014 chalie_a
** Last update Wed Apr  2 14:38:13 2014 chalie_a
*/

#include "my_printf.h"

#define ISFLAG(c)	(c == 'c' || c == 'd' || c == 's') ? 1 : 0

int	my_strlen(const char *str)
{
  int	i;

  i = -1;
  if (!str)
    return (0);
  while (str[++i]);
  return (i);
}

ptrft	*my_init_tab(ptrft *init)
{
  if (!(init = malloc(sizeof(ptrft) * 128)))
    return (0);
  init['s'] = my_printstr;
  init['d'] = my_printnb;
  init['c'] = my_printchar;
  return (init);
}

void	my_printchar(size_t len, va_list arg, int fdp)
{
  char	c;

  len = 0;
  c = va_arg(arg, int);
  x_putchar(c, fdp);
}

int			my_fprintf(int fds, const char *format, ...)
{
  ptrft			*tab;
  va_list       	arg;
  size_t		counters[2] = {0, 0};

  tab = NULL;
  va_start(arg, format);
  tab = my_init_tab(tab);
  while (format[counters[0]])
    {
      while (format[counters[0]] == '%')
	{
	  counters[0]++;
	  if (ISFLAG(format[counters[0]]))
	    {
	      tab[(int)format[counters[0]]](counters[1], arg, fds);
	      counters[0]++;
	    }
	}
      x_putchar(format[counters[0]], fdp);
      counters[0]++;
    }
  va_end(arg);
  return (counters[1]);
}

int			my_printf(const char *format, ...)
{
  ptrft			*tab;
  va_list       	arg;
  size_t		counters[2] = {0, 0};

  tab = NULL;
  va_start(arg, format);
  tab = my_init_tab(tab);
  while (format[counters[0]])
    {
      while (format[counters[0]] == '%')
	{
	  counters[0]++;
	  if (ISFLAG(format[counters[0]]))
	    {
	      tab[(int)format[counters[0]]](counters[1], arg, STDOUT_FILENO);
	      counters[0]++;
	    }
	}
      x_putchar(format[counters[0]], fdp);
      counters[0]++;
    }
  va_end(arg);
  return (counters[1]);
}
