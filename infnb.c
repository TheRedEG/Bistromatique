/*
** infnb.c for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Tue Oct 27 18:50:32 2015 denuit mathieu
** Last update Fri Oct 30 21:34:36 2015 denuit mathieu
*/

#include "infnb.h"
#include "bistro.h"
#include "eval.h"
#include "my.h"

static const t_infop	g_inf_ops[] = {0, 0, infnb_add, infnb_sub, infnb_mul,
				        infnb_div, infnb_mod};

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

void	infnb_skip_zero(t_infnb *nb, const char *base)
{
  char	*ptr;

  ptr = nb->data;
  while (nb->offset < nb->len && ptr[nb->offset] == base[0])
    nb->offset += 1;
  if (nb->offset == nb->len)
    nb->offset -= 1;
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

int	infnb_new(t_infnb *nb, int size)
{
  nb->data = malloc(sizeof(char) * size);
  if (!nb->data)
    return (E_ERR_MALLOC);
  nb->len = size;
  nb->offset = 0;
  nb->allocated = 1;
  nb->is_neg = 0;
  return (E_NO_ERR);
}

void	infnb_move(t_infnb *dest, t_infnb *src)
{
  *dest = *src;
  src->len = 0;
  src->data = 0;
  src->offset = 0;
}

void	infnb_negate(t_infnb *nb)
{
  if (nb)
  {
    nb->is_neg = !nb->is_neg;
  }
}

int	infnb_iszero(t_infnb *nb, const char *base)
{
  int	index;

  if (!nb || nb->len == 0 || nb->data == 0)
    return (0);
  index = char_index(nb->data[nb->offset], base);
  return (nb->len - nb->offset == 1 && index == 0);
}

int	infnb_swap_biggest(t_infnb *left, t_infnb *right, const char *base)
{
  t_infnb	tmp;
  t_infnb	*max;

  max = infnb_max(left, right, base);
  if (max == right)
  {
    infnb_move(&tmp, left);
    infnb_move(left, right);
    infnb_move(right, &tmp);
    return (1);
  }
  return (0);
}

int		infnb_operation(int op, t_eval_data *d, t_infnb *l, t_infnb *r)
{
  t_infnb	result;
  int		size;
  int		err;
  t_infop	func_op;

  result.data = 0;
  result.is_neg = 0;
  result.offset = 0;
  size = infnb_op_result_size(op, l, r);
  if ((err = infnb_new(&result, size)) != E_NO_ERR)
    return (err);
  func_op = g_inf_ops[op];
  err = func_op(d, &result, l, r);
  if (err != E_NO_ERR)
    return (eval_error_free(err, &result));
  infnb_free(l);
  infnb_free(r);
  infnb_move(l, &result);
  return (E_NO_ERR);
}

void	infnb_print(t_eval_data *data, t_infnb *nb)
{
  int	i;

  if (!nb)
    return ;
  if (infnb_iszero(nb, data->base))
    my_putchar(nb->data[nb->offset]);
  else
  {
    if (nb->is_neg)
      my_putchar('-');
    i = nb->offset;
    while (i < nb->len)
    {
      my_putchar(nb->data[i]);
      i += 1;
    }
  }
}

void	infnb_free(t_infnb *nb)
{
  if (!nb)
    return ;
  if (nb->allocated)
  {
    free(nb->data);
  }
  nb->data = 0;
  nb->len = 0;
  nb->offset = 0;
  nb->allocated = 0;
}

