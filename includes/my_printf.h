/*
** my_printf.h for printf in /home/tovazm/rendu/Printf
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 19:10:25 2014 
** Last update Wed Mar 19 20:49:53 2014 
*/

#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_opt t_opt;
typedef void	(*ptrft)(size_t len, va_list arg);

struct		s_opt
{
  char		*printf;
  char		*more;
  size_t	len;
  char		*all;
  struct s_opt	*next;
};

int	fdp;

void    my_printchar(size_t len, va_list arg);
void    my_printstr(size_t len, va_list arg);
void    my_printnb(size_t len, va_list arg);
ptrft	*my_init_ftptr(ptrft *ptr);
int     my_isdigit(int c);
void	my_putstr(char *str);
int	my_strlen(const char *str);
char	*my_reverse_str(const char *src);
char	*my_itoa(int nb);
void	x_atoi(int nb);
void	my_putchar(char c);
int	my_printf(const char *format, ...);

#endif /* !MY_PRINTF_H */
