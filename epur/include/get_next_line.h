/*
** get_next_line.h for get_next_line in /home/dong_n/rendu/get_next_line
** 
** Made by david$
** Login   <dong_n@epitech.net>
** 
** Started on  Thu Nov 14 11:35:03 2013 david$
** Last update Sun Dec  8 14:33:08 2013 david$
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define ABS(value) ((value < 0) ? -value : value)
# define BUFF_SIZE (1024)

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
