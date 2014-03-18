/*
** my_strcmp.c for my_strcmp in /home/dong_n/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Tue Oct  8 15:58:30 2013 david$
** Last update Sun Dec  1 18:13:52 2013 david$
*/

int	my_strcmp(char *s1, char *s2)
{
  while (*s1 != '\0' && *s2 != '\0')
    {
      if (*s1 == *s2)
	{
	  s1 = s1 + 1;
	  s2 = s2 + 1;
	}
      else
	return (*s1 - *s2);
    }
  if (*s1 != '\0' && *s2 == '\0')
    return (1);
  else if (*s1 == '\0' && *s2 != '\0')
    return (-1);
  else
    return (0);
}
