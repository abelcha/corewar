/*
** my_strcpy.c for my_strcpy in /home/dong_n/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Mon Oct  7 10:27:58 2013 david$
** Last update Wed Oct  9 12:00:55 2013 david$
*/

char	 *my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
