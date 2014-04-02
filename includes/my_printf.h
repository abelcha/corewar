/*
** my_printf.h for printf in /home/tovazm/rendu/Printf
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 19:10:25 2014 
** Last update Wed Apr  2 14:42:49 2014 chalie_a
*/

#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_opt t_opt;
typedef void	(*ptrft)(size_t len, va_list arg, int fdp);

struct		s_opt
{
  char		*printf;
  char		*more;
  size_t	len;
  char		*all;
  struct s_opt	*next;
};

int	fdp;

void    my_printchar(size_t len, va_list arg, int fdp);
void    my_printstr(size_t len, va_list arg, int fdp);
void    my_printnb(size_t len, va_list arg, int fdp);
ptrft	*my_init_ftptr(ptrft *ptr);
int     my_isdigit(int c);
void	my_putstr(char *str, int fdp);
int	my_strlen(const char *str);
char	*my_reverse_str(const char *src);
char	*my_itoa(int nb, int fdp);
void	x_atoi(int nb, int fdp);
void	x_putchar(char c, int fdp);

int	my_printf(const char *format, ...);
void	x_putstr(char *str, int fdp);
#endif /* !MY_PRINTF_H */
