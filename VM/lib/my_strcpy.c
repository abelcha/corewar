/*
** my_strcpy.c for my_strcpy in /home/dong_n/rendu/corewar/ASM
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Apr 13 00:05:23 2014 dong_n
** Last update Sun Apr 13 15:18:44 2014 dong_n
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
