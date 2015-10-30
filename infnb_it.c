/*
** infnb_it.c for Bistromathique in 
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Fri Oct 30 13:22:51 2015 denuit mathieu
** Last update Fri Oct 30 15:01:09 2015 denuit mathieu
*/

#include "infnb_it.h"

void	infnb_it_init(t_infnb_it *it, t_eval_data *d, t_infnb *l, t_infnb *r)
{
  it->left = l;
  it->right = r;
  it->pos_l = l->len - 1;
  it->pos_r = r->len - 1;
  it->base = d->base;
  it->base_len = d->base_len;
}

int	infnb_it_next_digit(t_infnb_it *it, int *digit_l, int *digit_r)
{
  if (!it || !digit_l || !digit_r)
    return (0);
  if (it->pos_l >= it->left->offset && it->pos_l < it->left->len)
  {
    *digit_l = char_index(it->left->data[it->pos_l], it->base);
    it->pos_l -= 1;
    if (it->pos_r >= it->right->offset && it->pos_r < it->right->len)
    {
      *digit_r = char_index(it->right->data[it->pos_r], it->base);
      it->pos_r -= 1;
    }
    else
      *digit_r = 0;
    return (1);
  }
  return (0);
}
