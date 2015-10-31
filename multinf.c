/*
** multinf.c for multinf in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Wed Oct 21 15:43:19 2015 Nicolas Gautherin
** Last update Fri Oct 30 16:02:47 2015 Nicolas Gautherin
*/

#include "infnb.h"
#include "bistro.h"

void	newtmp(t_eval_data *d, t_infnb *tmp, t_infnb *left, int rank)//chande
{
  int	index;

  index = tmp->len;
  while (rank != 0)
    {
      tmp->data[index] = d->base[0]; //base (= base d'entrée) non definie pour le moment
      index = index - 1;
      rank = rank - 1;
    }
  rank = left->len - 1;
  while (rank >= left->offset)
    {
      tmp->data[index] = left->data[rank];
      rank = rank - 1;
      index = index + 1;
    }
}

t_infnb		*do_multinf(t_eval_data *d, t_infnb *result,
			     t_infnb *left, t_infnb *right)
{
  t_infnb	*tmp;
  int		index;
  int		index2;

  infnb_new(&tmp, (left->len - left->offset) + (right->len - right->offset));
  index = right->len;
  while (index > right->offset)
    {
      newtmp(d, &tmp, left, (right->len - index));
      index2 = base_index(right);
      while (index2 != 0)
	{
	  result = infnb_add_p(d, result, result, &tmp);
	  right->data[index] = right->data[index] - 1;
	  index2 = index2 - 1;
      	}
      index = index - 1;
    }
  infnb_free(&tmp);
  return (result);
}

void	infnb_cpy(t_eval_data *d, t_infnb *newnb, t_infnb *src)
{
  int	index;

  newnb->isneg = src->isneg;
  index = 0;
  while (src->len - index > srcoffset) //tant que "merdeaulolilol(index->)123"
    {
      newnb->data[newnb->len - 1 - index] = src->data[len - 1 index];
      index = index + 1;
    }
  newnb->offset = newnb->len - index;
}

t_infnb	*multinf(t_eval_data *d, t_infnb *result, t_infnb *left, t_infnb *right)
{
  if ((char_index(left->data[0], d->base) == 48) && (left->data[1] == 0))
    {
      infnb_cpy(d, result, left);      
      return (result);
    }
  if ((base_index(right->data[0], d->base) == 0) && (right->data[1] == 0))
    {
      infnb_cpy(d, result, right);      
      return (result);
    }
  return (do_multinf(d, result, left, right));
}
