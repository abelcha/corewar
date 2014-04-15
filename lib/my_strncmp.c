/*
** my_strncmp.c for my_strncmp in /home/dong_n/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Tue Oct  8 17:17:11 2013 david$
** Last update Sun Dec 22 19:39:30 2013 david$
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  if (*s1 == '\0')
    return (-*s2);
  if (*s2 == '\0')
    return (*s1);
  while (*s1 != '\0' && *s2 != '\0' && n > 0)
    {
      n = n - 1;
      if (*s1 == *s2)
	{
	  s1++;
	  s2++;
	}
      else
	return (*s1 - *s2);
    }
  if (*s2 == '\0' && n == 0)
    return (0);
  return (-1);
}
