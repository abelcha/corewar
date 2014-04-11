/*
** strings.c for minish in /home/chalie_a/rendu/PSU_2013_minishell1
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Wed Jan  1 03:15:53 2014 chalie_a
** Last update Thu Apr 10 18:31:49 2014 chalie_a
*/

#include "my.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;
  int	error;
  int	nbs1;
  int	nbs2;

  nbs1 = 0;
  nbs2 = 0;
  error = 0;
  i = 0;
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
