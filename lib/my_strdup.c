/*
** strings.c for minish in /home/chalie_a/rendu/PSU_2013_minishell1
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Wed Jan  1 03:15:53 2014 chalie_a
** Last update Fri Mar 28 07:07:52 2014 chalie_a
*/

#include <stdlib.h>
#include "corewar.h"

char	*my_strdup(char *str)
{
  char	*newstr;

  newstr = calloc((my_strlen(str) + 8), sizeof(char *));
  if (newstr)
    my_strcpy(newstr, str, 0);
  return (newstr);
}
