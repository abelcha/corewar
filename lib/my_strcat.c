/*
** my_strcat.c for my_strcat in /home/dong_n/rendu/corewar/ASM
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Apr 13 00:05:37 2014 dong_n
** Last update Sun Apr 13 00:07:30 2014 dong_n
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i++;
  while (src[j] != '\0')
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
