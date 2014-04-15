/*
** my.h for my.h in /home/dong_n/rendu/Piscine-C-include
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Fri Oct 11 09:56:48 2013 david$
** Last update Sun Apr 13 20:59:13 2014 dong_n
*/

#ifndef MY_H_
# define MY_H_

void		my_putchar(char c);
void		my_putchar_err(char c);
void		my_putstr(char *str);
void		my_put_error(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_strcat(char *dest, char *src);
char		*my_strdup(char *src);
char		*my_strndup(char *src, int n);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
int		my_put_nbr(int nbr);
int		my_put_nbr_error(int nbr);
char		*gnl(int fd);
void		*xmalloc(unsigned long size);
void		*my_memset(void *s, int c, int n);
void		*my_calloc(int nmemb, int size);

#endif /* !MY_H_ */
