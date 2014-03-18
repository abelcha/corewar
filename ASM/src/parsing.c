/*
** parsing.c for lolo in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Mon Mar 17 17:30:55 2014 
** Last update Tue Mar 18 21:18:24 2014 dong_n
*/

#include "op.h"
#include "corewar.h"

int	line_parsing(t_args *args, t_list *list)
{
  int	ins_num;

  printf("%s\n", args->args[0]);
  puts("hueheuhu\n");
  ins_num = which_instruction(args->args[0]);
  puts("ruru\n");
  if (ins_num == UNKNOWN)
      return (FAILURE);
  printf("inst = %s, num = %d\n",args->args[0], ins_num);
  /*
    fill_list(args, list);
  */
  return (SUCCESS);
}

int	asm_parsing(t_list *list, char **stock)
{
  int		i;
  int		cmp;
  t_args	*args;

  if (!(args = malloc(sizeof(t_args))))
    return (FAILURE);
  i = -1;
  while (stock[++i])
    {
      stock[i] = epur_str(stock[i]);
      printf("--%s--\n", stock[i]);
      if (split_list(stock[i], args) == FAILURE)
	{
	  printf("stock[i] = null\n");
	  return (FAILURE);
	}
	  //line_parsing(args, list);
      printf("<<%s>>\n", args->args[0]);
    }
  return (SUCCESS);
}
