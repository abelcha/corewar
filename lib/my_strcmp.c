/*
** strings.c for minish in /home/chalie_a/rendu/PSU_2013_minishell1
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Wed Jan  1 03:15:53 2014 chalie_a
** Last update Sat Mar 22 05:33:19 2014 chalie_a
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	error;
  int	nbs1;
  int	nbs2;

  nbs1 = 0;
  nbs2 = 0;
  error = 0;
  i = 0;
  nbs1 = my_strlen(s1);
  nbs2 = my_strlen(s2);
  while (s1 && s2 && s1[i] == s2[i] && (i != nbs1 || i !=nbs2))
    {
      i = i + 1;
      if (nbs1 - nbs2 == 0 && i == nbs1)
        return (0);
    }
  if (s1 && s2 && s1[i] != s2[i])
    {
      error = s1[i] - s2[i];
      return (error);
    }
  return (0);
}
