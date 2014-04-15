/*
** asm.c for lol in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 18:26:38 2014 
** Last update Sun Apr 13 22:49:20 2014 dong_n
*/

#include <stdlib.h>
#include "my.h"
#include "corewar.h"
#include "x_error.h"

char		*cut_double_quotes(char	*str)
{
  int		i;
  int		k;
  char		*tmp;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  if (str[i] == '"')
    i++;
  k = i;
  while (str[k] != '"' && str[k] != '\0')
    k++;
  if (!(tmp = xmalloc(sizeof(*tmp) * (k - i + 1))))
    return (NULL);
  k = 0;
  while (str[i] != '"' && str[i] != '\0')
    tmp[k++] = str[i++];
  tmp[k] = '\0';
  return (tmp);
}

void		my_error(char *err, char *str)
{
  my_put_error(err);
  my_put_error(str);
  my_put_error("\n");
}

int		get_info(char *str, header_t *header)
{
  char		*info_name;
  int		info_len;

  if (my_strncmp(str, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
    {
      info_len = my_strlen(NAME_CMD_STRING);
      if (!(info_name = cut_double_quotes(&(str[info_len]))))
	return (FALSE);
      my_strcpy(header->prog_name, info_name);
      free(info_name);
    }
  else if (my_strncmp(str, COMMENT_CMD_STRING,
		      my_strlen(COMMENT_CMD_STRING)) == 0)
    {
      info_len = my_strlen(COMMENT_CMD_STRING);
      if (!(info_name = cut_double_quotes(&(str[info_len]))))
	return (FALSE);
      my_strcpy(header->comment, info_name);
      free(info_name);
    }
  else
    my_error("Warning : Unknown extension ", str);
  return (TRUE);
}

int		first_points(char *str, header_t *header)
{
  int		i;

  i = 0;
  while (str[i] == '\t' || str[i] == ' ')
    i++;
  if (str[i] == '.')
    {
      get_info(&str[i], header);
      return (TRUE);
    }
  return (FALSE);
}
