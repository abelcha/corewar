/*
** main.c for test in /home/dong_n/rendu/epur
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Mon Mar 17 19:00:51 2014 dong_n
** Last update Wed Mar 19 02:02:46 2014 
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "x_error.h"
#include "my.h"

char	*epur_str(char *str)
{
  char	*ret;
  int	k;
  int	i;

  if (!(ret = malloc(sizeof(*ret) * (my_strlen(str) + 1))))
    return (ERROR_(MALLOC_FAIL));
  i = 0;
  k = 0;
  while (str[i] != '\0' && str[i] != '#' && str[i] != ';')
    {
      while (!(str[i] > 32 && str[i] < 127) && str[i] != '\0')
	i++;
      while (str[i] > 32 && str[i] < 127 && str[i] != '#' && str[i] != ';')
	ret[k++] = str[i++];
      ret[k++] = ' ';
      if (str[i - 1] == ',')
	k--;
    }
  if (k != 0)
    ret[k - 1] = '\0';
  else
    ret[k] = '\0';
  return (ret);
}
/*
int	main(int argc, char **argv)
{
  int	fd;
  char	*line;
  char	*str;
  char	**tab;
  int	i;

  (void)argc;
  (void)argv;
  fd = open("commented.s", O_RDONLY);
  tab = malloc(sizeof(*tab) * 500);
  i = 0;
  while ((line = get_next_line(fd)))
    tab[i++] = line;
  tab[i] = NULL;
  i = 0;
  while (tab[i])
    {
      str = epur_str(tab[i++]);
      my_putstr(str);
      my_putchar('\n');
    }
  return (0);
}
*/
