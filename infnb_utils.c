/*
** infnb_utils.c for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Sat Oct 31 15:39:21 2015 denuit mathieu
** Last update Sat Oct 31 15:46:07 2015 denuit mathieu
*/

#include "infnb.h"
#include "bistro.h"

int	infnb_nbrlen(const char *str, const char *base)
{
  int	i;

  i = 0;
  while (char_index(str[i], base) >= 0)
    i += 1;
  return (i);
}

int	infnb_op_result_size(int op, t_infnb *left, t_infnb *right)
{
  int	max_len;
  int	left_len;
  int	right_len;

  left_len = left->len - left->offset;
  right_len = right->len - right->offset;
  max_len = (left_len > right_len) ? left_len : right_len;
  if (op == OP_ADD || op == OP_SUB)
    return (max_len + 1);
  else if (op == OP_MUL)
    return (left->len + right->len);
  else if (op == OP_MOD)
    return (right->len);
  else if (op == OP_DIV)
    return (left->len);
  else
    return (0);
}

int	infnb_nbrcmp(t_infnb *a, t_infnb *b, const char *base)
{
  int	i;
  int	j;
  int	digit_i;
  int	digit_j;

  i = a->offset;
  j = b->offset;
  while (i < a->len && j < b->len)
  {
    digit_i = char_index(a->data[i], base);
    digit_j = char_index(b->data[j], base);
    if (digit_i != digit_j)
      return (digit_i - digit_j);
    i += 1;
    j += 1;
  }
  return (0);
}

t_infnb	*infnb_max(t_infnb *a, t_infnb *b, const char *base)
{
  int	a_len;
  int	b_len;

  a_len = a->len - a->offset;
  b_len = b->len - b->offset;
  if (!a || !b)
    return (0);
  if (a_len > b_len)
    return (a);
  else if (b_len > a_len)
    return (b);
  else
    return (infnb_nbrcmp(a, b, base) >= 0 ? a : b);
}

int	infnb_iszero(t_infnb *nb, const char *base)
{
  int	index;

  if (!nb || nb->len == 0 || nb->data == 0)
    return (0);
  index = char_index(nb->data[nb->offset], base);
  return (nb->len - nb->offset == 1 && index == 0);
}
