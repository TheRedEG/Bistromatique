/*
** infnb_div.c for infnb_div in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Wed Oct 28 13:43:50 2015 Nicolas Gautherin
** Last update Sat Oct 31 18:53:21 2015 Nicolas Gautherin
*/

#include "infnb.h"
#include "bistro.h"

void	preset_tmp(t_eval_data *d, t_infnb *result, int size)
{
  int	index;

  index = result->len - 1;
  result->offset = result->len - size;
  result->data[result->offset] = d->base[1];
  while (index >= result->offset)
    {
      result->data[index] = d->base[0];
      index = index - 1;
    }
}

int		infnb_div_p(t_eval_data *d, t_infnb *result,
			     t_infnb *left, t_infnb *right)
{  
  t_infnb	const_nb;
  t_infnb	tmp;

  if (infnb_new(&tmp, (left->len - left->offset)) == 2)
    return (2);
  const_nb.allocated = 0;
  const_nb.len = 1;
  const_nb.offset = 0;
  const_nb.data = "1";
  const_nb.is_neg = 0;
  if ((right->offset + 1 == right->len) && (right->data[right->offset] == d->base[0]))
      return (3);
  if ((right->offset + 1 == right->len) && (right->data[right->offset] == d->base[1]))
    {
      infnb_cpy(d, result, left);
      return (0);
    }
  preset_tmp(d, &tmp, (left->len - right->len));
  while (infnb_is_biggest(d, left, &tmp) >= 0)
    {
      infnb_add_p(d, &tmp, &tmp, right);
      infnb_add_p(d, result, result, &const_nb);
    }
  infnb_free(&tmp);
  return (0);
}
