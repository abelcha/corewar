/*
** convert_indian.c for conv in /home/tovazm/rendu/corewar
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:56:09 2014 chalie_a
** Last update Wed Apr  2 13:34:24 2014 chalie_a
*/

void		convert_indian(void *input, int n)
{
  char		tmp;
  char		*output;
  int		low;
  int		hi;

  output = input;
  low = -1;
  hi = n;
  while (--hi > ++low)
    {
      tmp = output[low];
      output[low] = output[hi];
      output[hi] = tmp;
    }
}
