/*
** x_error.h for  in /home/chalie_a/rendu/PSU_2013_minishell2/includes
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:53:19 2014 chalie_a
** Last update Sun Apr 13 17:16:15 2014 dong_n
*/

#ifndef X_ERROR_H_
# define X_ERROR_H_

# define X_ERROR(s, g)	putxerr(s, g)
# define ERROR(s)	put_error(s)
# define ERROR_(s)      put_null_error(s)
# define NO_FILE	" No such file or directory.\n"
# define MALLOC_FAIL	"Malloc Fail\n"
# define INV_PAR	" invalid parameter type.\n"
# define INV_INST	" is not a valid instruction.\n"
# define FILE_EXT	" Unknown file extension.\n"

int			put_error(char *str);
void			*put_null_error(char *str);
void			my_puterr(char *str);
int			putxerr(char *name, char *str);

#endif /* !X_ERROR_H_ */
