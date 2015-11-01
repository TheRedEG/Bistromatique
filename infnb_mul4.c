/*
** infnb_mul.c for infnb_mul in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Wed Oct 21 15:43:19 2015 Nicolas Gautherin
** Last update Sun Nov  1 22:08:42 2015 Nicolas Gautherin
*/

#include "infnb.h"
#include "bistro.h"

void	newtmp(t_eval_data *d, t_infnb *tmp, t_infnb *left, int rank)
{
  int	index;
  int	i;

  tmp->offset = tmp->len - (left->len - left->offset) - rank;
  index = tmp->len - 1;
  while (rank != 0)
    {
      tmp->data[index] = d->base[0];
      index = index - 1;
      rank = rank - 1;
    }
  rank = left->len;
  while (rank > left->offset)
    {
      tmp->data[index] = left->data[rank - 1];
      rank = rank - 1;
      index = index - 1;
    }
}

void	infnb_clear(t_eval_data *d, t_infnb *a)
{
  int	i;

  i = 0;
  while (i < a->len)
    {
      a->data[i] = d->base[0];
      i = i + 1;
    }
}

void	infnb_mul_free_tmp(t_infnb *s1, t_infnb *s2)
{
  infnb_free(s1);
  infnb_free(s2);
}

/*void	infnb_mulcreate_tmp(t_infnb *tmp, t_infnb *tmp2,
			     t_infnb *left, t_infnb rght)
{
  if (infnb_new(&tmp, (left->len - left->offset) +
                (right->len - right->offset)) == E_ERR_MALLOC)
    return (E_ERR_MALLOC);
  if (infnb_new(&tmp2, (tmp.len)) == E_ERR_MALLOC)
    return (E_ERR_MALLOC);
}
*/
int		do_multinf(t_eval_data *d, t_infnb *result,
			     t_infnb *left, t_infnb *right)
{
  int		index;
  int		j;
  t_infnb	tmp;
  t_infnb	tmp2;

  if (infnb_new(&tmp, (left->len - left->offset) +
                 (right->len - right->offset)) == E_ERR_MALLOC)
    return (E_ERR_MALLOC);
  if (infnb_new(&tmp2, (tmp.len)) == E_ERR_MALLOC)
    return (E_ERR_MALLOC);
  index = right->len - 1;
  result->offset = result->len - (left->len - left->offset);
  infnb_clear(d, result);
  while (index >= right->offset)
    {
      newtmp(d, &tmp, left, (right->len - 1 - index));
      j = char_index(right->data[index], d->base);
      while (j > 0)
	{
	  //	  infnb_cpy(d, &tmp2, &tmp);
	  infnb_add_p(d, result, result, &tmp);
	  j = j - 1;
	}
      index = index - 1;
    }
  infnb_mul_free_tmp(&tmp, &tmp2);
  return (0);
}

void	infnb_cpy(t_eval_data *d, t_infnb *new, t_infnb *src)
{
  int	index;

  new->is_neg = src->is_neg;
  index = 0;
  while (src->len - index > src->offset)
    {
      new->data[new->len - 1 - index] = src->data[src->len - 1 - index];
      index = index + 1;
    }
  new->offset = new->len - (src->len - src->offset);
}

int	infnb_mul_p(t_eval_data *d, t_infnb *result,
		     t_infnb *left, t_infnb *right)
{
  if ((char_index(left->data[left->offset], d->base) == 0) &&
       (left->len - left->offset == 1))
    {
      infnb_cpy(d, result, left);      
      return (E_NO_ERR);
    }
  if ((char_index(right->data[right->offset], d->base) == 0) &&
       (right->len - right->offset == 1))
    {
      infnb_cpy(d, result, right);      
      return (E_NO_ERR);
    }
  result->offset = result->len - (left->len - left->offset);
  if (do_multinf(d, result, left, right) == E_ERR_MALLOC)
    return (E_ERR_MALLOC);
  return (E_NO_ERR);
}
