/*
** main.c for main in /home/dong_n/rendu/corewar/VM/src
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sun Mar 30 17:55:36 2014 dong_n
** Last update Tue Apr  8 17:11:15 2014 dong_n
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "vm.h"
#include "op.h"
int		my_getnbr_base(char *nbr, char *base_from);
void		convert_indian(void *input, int n);

t_op	op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
  };

void		show_inst(t_cmd instruct)
{
  int		i;

  i = 0;
  printf("Instruction n°%d\n", instruct.op);
  printf("Number of arguments : %d\n\n", op_tab[instruct.op - 1].nbr_args);
  while (i < op_tab[instruct.op - 1].nbr_args)
    {
      printf("Param N°%d\n", i + 1);
      printf("Type : %d\n", instruct.args_type[i]);
      printf("Args : %d\n\n", instruct.args_value[i]);
      i++;
    }
  printf("\n\n\n");
}

void		get_params_value2(char *buff, int *i, int j, t_cmd *instruct)
{
  int		k;

  k = 0;
  if (instruct->args_type[j] == 1)
    instruct->args_value[j] = buff[(*i)++];
  else
    {
      instruct->args_value[j] = 0;
      while (k++ < 2)
	{
	  instruct->args_value[j] = ((instruct->args_value[j] << 8 & 0xFFFFFF00) |
			       (unsigned char)buff[(*i)++]);
	}
      instruct->args_value[j] = (short int)instruct->args_value[j];
    }
}

void		get_params_value4(char *buff, int *i, int j, t_cmd *instruct)
{
  int		k;

  k = 0;
  if (instruct->args_type[j] != 2)
    get_params_value2(buff, i, j, instruct);
  else
    {
      instruct->args_value[j] = 0;
      while (k++ < 4)
	{
	  instruct->args_value[j] = ((instruct->args_value[j] << 8 & 0xFFFFFF00) |
			       (unsigned char)buff[(*i)++]);
	}
    }
}

void		get_ld_params(char *buff, int *i, int j, t_cmd *instruct)
{
  int		k;

  k = 0;
  if (j == 0)
    {
      instruct->args_value[0] = 0;
      while (k++ < 4)
	{
	  instruct->args_value[0] = ((instruct->args_value[0] << 8 & 0xFFFFFF00) |
			       (unsigned char)buff[(*i)++]);
	}
    }
  else
    get_params_value2(buff, i, j, instruct);
}

void		get_args_oct(char *buff, t_cmd *instruct, int *i)
{
  char		oct;
  int		k;
  int		j;

  k = 6;
  j = 0;
  oct = buff[(*i)++];
  while (k >= 0 && j < op_tab[instruct->op - 1].nbr_args)
    {
      instruct->args_type[j] = (oct >> k) & 3;
      if (instruct->op == 2 || instruct->op == 13)
	get_ld_params(buff, i, j, instruct);
      else if (instruct->op == 3 || (instruct->op > 5 && instruct->op < 9))
	get_params_value4(buff, i, j, instruct);
      else if (instruct->op == 16 || instruct->op == 14 ||
	       (instruct->op > 3 && instruct->op < 6) || instruct->op == 10 ||
	       instruct->op == 11)
	get_params_value2(buff, i, j, instruct);
      else
	(*i)++;
      k = k - 2;
      j++;
    }
}

void		get_args(char *buff, t_cmd *instruct, int *i)
{
  int		k;

  k = 0;
  if (instruct->op == 1)
    {
      instruct->args_type[0] = 2;
      instruct->args_value[0] = 0;
      while (k++ < 4)
	{
	  instruct->args_value[0] = ((instruct->args_value[0] << 8 & 0xFFFFFF00) |
			       (unsigned char)buff[(*i)++]);
	}
    }
  else
    {
      instruct->args_type[0] = 2;
      get_params_value2(buff, i, 0, instruct);
    }
}

int		my_get_file(int fd, int prog_size)
{
  char		*buff;
  int		i;
  t_cmd		instruct;

  if (!(buff = xmalloc(sizeof(*buff) * prog_size)))
    return (-1);
  if (read(fd, buff, prog_size) == -1)
    return (-1);
  i = 0;
  while (i < prog_size)
    {
      instruct.op = buff[i++];
      if (HAVE_CODING_BYTE(instruct.op) == TRUE)
	get_args_oct(buff, &instruct, &i);
      else
	get_args(buff, &instruct, &i);
      show_inst(instruct);
    }
  return (0);
}

int		get_file(char *filename)
{
  int		fd;
  int		name_len;
  header_t	header;

  if ((name_len = my_strlen(filename)) < 5)
    return (-1);
  if (my_strcmp(&filename[name_len - 4], ".cor") != 0)
    return (-1);
  if ((fd = open(filename, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, &header, sizeof(header)) == -1)
    return (-1);
  printf("Prog name : %s\n", header.prog_name);
  printf("Comment : %s\n", header.comment);
  convert_indian(&(header.prog_size), sizeof(int));
  printf("Prog size : %d\n", header.prog_size);
  if (my_get_file(fd, header.prog_size) == -1)
    return (-1);
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc < 2)
    return (-1);
  if (!(get_file(argv[1])))
    return (-1);
  return (0);
}
