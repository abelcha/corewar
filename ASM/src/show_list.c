/*
** show_list.c for YOLOSWAG in /home/tovazm/rendu/corewar/ASM
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Wed Mar 19 03:46:23 2014 
** Last update Thu Mar 20 22:50:36 2014 
*/

#include "op.h"
#include "corewar.h"
#include "x_error.h"
#include "x_colors.h"

void		show_list(t_list *list)
{
  t_list	*tmp;
  int		i;
  int		j = -1;
  tmp = list->next;
  printf("===============================\n");
  while (tmp != list)
    {
      printf("line = %s%d%s\n", YELLOW, ++j, ENDOF); 
      printf("linesize = %s%d%s\n", CYAN, tmp->size, ENDOF);
      printf("	Num =%s %d %s(%s)",RED, tmp->num, ENDOF, op_tab[tmp->num - 1].name);
      if (tmp->label)
	printf("		label =%s %s\n%s", BLUE,tmp->label, ENDOF);
      else
	printf("	\n");
      printf("Coding Byte = %s%x%s\n", BLUE , tmp->coding_byte, ENDOF );

      i = 0;
      while (i < op_tab[tmp->num - 1].nbr_args)
	{
	  printf("	");
	  if (tmp->param[i].type == T_REG)
	    printf("Type = Register (%s01%s)",GREEN ,ENDOF );
	  else if (tmp->param[i].type == T_IND)
	    printf("Type = Indirect (%s11%s), ", GREEN ,ENDOF );
	  else if (tmp->param[i].type == T_DIR)
	    printf("Type = Direct(%s10%s), ", GREEN ,ENDOF );
	  else
	    printf("Type = Label(%s:%s), ", GREEN ,ENDOF );
	  printf("	");
	  printf("value = %s%d\n%s", MAGENTA,tmp->param[i].param, ENDOF);
	  i++;
	}
      printf("\n\n");
      tmp = tmp->next;
    }
  printf("================================\n");
}
