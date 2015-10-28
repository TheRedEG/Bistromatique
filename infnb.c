/*
** infnb.c for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Tue Oct 27 18:50:32 2015 denuit mathieu
** Last update Wed Oct 28 01:54:30 2015 denuit mathieu
*/

#include "infnb.h"
#include "bistro.h"

int	char_index(char c, const char *str)
{
  int	i;

  i = 0;
  while (str[i])
  {
    if (str[i] == c)
      return (i);
    i += 1;
  }
  return (-1);
}

int	infnb_nbrlen(const char *str, const char *base)
{
  int	i;

  i = 0;
  while (char_index(str[i], base) >= 0)
    i += 1;
  return (i);
}

void	do_expression_op(t_infnb *left, int op, t_infnb *right)
{
  int leftnb;
  int rightnb;
  int result;

  leftnb = my_getnbr_base(left->data, "0123456789");
  leftnb = left->neg ? -leftnb : leftnb;
  rightnb = my_getnbr_base(right->data, "0123456789");
  rightnb = right->neg ? -rightnb : rightnb;
  if (op == OP_ADD){printf("calculating %d + %d\n", leftnb, rightnb);
    leftnb += rightnb;}
  else if (op == OP_SUB){printf("calculating %d - %d\n", leftnb, rightnb);
    leftnb -= rightnb;}
  infnb_free(left);
  left->allocated = 1;
  left->neg = leftnb < 0;
  leftnb = leftnb < 0 ? -leftnb : leftnb;
  left->data = my_itoa_base(leftnb, "0123456789", 0);
  left->len = my_strlen(left->data);
}

void	do_factor_op(t_infnb *left, int op, t_infnb *right)
{
  int leftnb;
  int rightnb;
  int result;

  leftnb = my_getnbr_base(left->data, "0123456789");
  leftnb = left->neg ? -leftnb : leftnb;
  rightnb = my_getnbr_base(right->data, "0123456789");
  rightnb = right->neg ? -rightnb : rightnb;
  if (op == OP_MUL){printf("calculating %d * %d\n", leftnb, rightnb);
    leftnb *= rightnb;}
  else if (op == OP_DIV){printf("calculating %d / %d\n", leftnb, rightnb);
    leftnb /= rightnb;}
  else if (op == OP_MOD){printf("calculating %d mod %d\n", leftnb, rightnb);
    leftnb = leftnb % rightnb;}
  infnb_free(left);
  left->allocated = 1;
  left->neg = leftnb < 0;
  leftnb = leftnb < 0 ? -leftnb : leftnb;
  left->data = my_itoa_base(leftnb, "0123456789", 0);
  left->len = my_strlen(left->data);
}

void	infnb_free(t_infnb *nb)
{
  if (nb && nb->allocated)
  {
    free(nb->data);
    nb->data = 0;
  }
}
