/*
** corewar.h for COREWARE in /home/tovazm/rendu/corewar
** 
** Made by 
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar 16 16:21:13 2014 
** Last update Tue Mar 18 21:37:11 2014 dong_n
*/

#ifndef _COREWAR_H_
# define _COREWAR_H_

#define SUCCESS	1
#define FAILURE	-1
#define TRUE	1
#define FALSE	0
#define UNKNOWN	-1
/*
** TEMPORARY DEFINES
*/
#define X printf("lol\n");
#define Z printf("HERE\n");
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	line_parsing(t_args *args, t_list *list);
int	asm_parsing(t_list *list, char **stock);
int	split_list(char *line, t_args *args);
int	which_instruction(char *str);
char	*epur_str(char *str);


#endif /* !COREWAR_H_ */
