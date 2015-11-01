/*
** infnb_action.c for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Sat Oct 31 15:36:14 2015 denuit mathieu
** Last update Sun Nov  1 23:40:22 2015 denuit mathieu
*/

#include "infnb.h"
#include "bistro.h"
#include "eval.h"

static const t_infop	g_inf_ops[] = {0, 0, infnb_add, infnb_sub, infnb_mul,
				        infnb_div, infnb_mod};

void	infnb_skip_zero(t_infnb *nb, const char *base)
{
  char	*ptr;

  ptr = nb->data;
  while (nb->offset < nb->len && ptr[nb->offset] == base[0])
    nb->offset += 1;
  if (nb->offset == nb->len)
    nb->offset -= 1;
}

void	infnb_move(t_infnb *dest, t_infnb *src)
{
  *dest = *src;
  infnb_init(src);
}

void	infnb_negate(t_infnb *nb)
{
  if (nb)
  {
    nb->is_neg = !nb->is_neg;
  }
}

int	infnb_swap_biggest(t_infnb **left, t_infnb **right, const char *base)
{
  t_infnb	*tmp;
  t_infnb	*max;

  max = infnb_max(*left, *right, base);
  if (max == *right)
  {
    tmp = *left;
    *left = *right;
    *right = tmp;
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

  infnb_init(&result);
  size = infnb_op_result_size(op, l, r);
  if (!infnb_reuse(size, &result, l) && !infnb_reuse(size, &result, r))
  {
    err = infnb_new(&result, size);
    if (err != E_NO_ERR)
      return (err);
  }
  func_op = g_inf_ops[op];
  err = func_op(d, &result, l, r);
  if (err != E_NO_ERR)
    return (eval_error_free(err, &result));
  infnb_free(l);
  infnb_free(r);
  infnb_move(l, &result);
  return (E_NO_ERR);
}
