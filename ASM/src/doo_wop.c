/*
** doo_wop.c for lol in /home/tovazm/rendu/corewar/ASM
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 26 00:11:34 2014 chalie_a
** Last update Wed Mar 26 11:23:54 2014 chalie_a
*/

#define IS_OP(c)	(c == '+' || c == '-' || c == '/' || c == '*' || c == '%' ? 1 : 0)


int	doo_op(int r, char o, int n)
{
  return (o == '+' ? r + n : o == '-' ? r - n : o == '*' ? r * n : r / n);
}

int	evalxpr(char *str, int *res)
{
  int	i;
  int	x;
  int	op;

  x = 0;
  i = -1;
  while (str[++i])
    {
      if (str[i] == ':')
	while (str[i] && IS_OP(str[++i]) == 0);
      op = str[i];
      str[i] = '\0';
      if (IS_OP(str[i]) == 1)
	res = do_op(res, op, );
    }
  return (0);
}

int	main(int ac, char **av)
{
  int	res;

  evalxpr(av[1], &res);
  printf("res  = %d\n", res);
}
