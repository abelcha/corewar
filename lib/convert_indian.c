/*
** convert_indian.c for conv in /home/tovazm/rendu/corewar
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Mar 28 12:56:09 2014 chalie_a
** Last update Fri Mar 28 12:56:44 2014 chalie_a
*/

void            convert_indian(void *source, int size)
{
  typedef unsigned char TwoBytes[2];
  typedef unsigned char FourBytes[4];
  typedef unsigned char EightBytes[8];
  FourBytes     *src4;
  unsigned char temp;
  TwoBytes      *src2;

  if(size == 2)
    {
      src2 = (TwoBytes *)source;
      temp = (*src2)[0];
      (*src2)[0] = (*src2)[1];
      (*src2)[1] = temp;
      return;
    }
  if(size == 4)
    {
      src4 = (FourBytes *)source;
      temp = (*src4)[0];
      (*src4)[0] = (*src4)[3];
      (*src4)[3] = temp;
      temp = (*src4)[1];
      (*src4)[1] = (*src4)[2];
      (*src4)[2] = temp;
      return ;
    }
  return ;
}
