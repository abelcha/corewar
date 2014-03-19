/*
** my_getnbr.c for my_getnbr in /home/dong_n/rendu/Piscine-C-colles-Semaine_02
** 
** Made by david
** Login   <dong_n@epitech.net>
** 
** Started on  Sat Oct 12 16:42:56 2013 david$
** Last update Wed Mar 19 01:34:59 2014 
*/

int	limits(int c, int sign, int *nbr)
{
  if (c == 8 && sign == -1 && *nbr == 2147483640)
    {
      *nbr = -2147483648;
      return (1);
    }
  else if (c < 8 && sign == 1 && *nbr == 2147483640)
    {
      *nbr = 2147483640 + c;
      return (1);
    }
  else if (*nbr == 2147483640 && c > 7)
    {
      *nbr = 0;
      return (1);
    }
  return (0);
}

int	posneg(char *str, int *i)
{
  int	sign;

  sign = 1;
  while (str && (str[*i] == '+' || str[*i] == '-'))
    {
      if (str[*i] == '-')
	sign = -sign;
      *i = *i + 1;
    }
  return (sign);
}

int	my_getnbr(char *str)
{
  int	i;
  int	sign;
  int	nbr;

  i = 0;
  sign = posneg(str, &i);
  nbr = 0;
  while (str && str[i] > 47 && str[i] < 58)
    {
      if (limits(str[i] - 48, sign, &nbr) == 1)
	return (nbr);
      nbr = nbr + str[i] - 48;
      if (str[i + 1] > 47 && str[i + 1] < 58)
	{
	  if (nbr < 214748365)
	    nbr = nbr * 10;
	  else
	    return (0);
	}
      i = i + 1;
    }
  if (sign == 1)
    return (nbr);
  return (-nbr);
}
