/*
** infnb_mod.c for infnb_mod in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Sat Oct 31 12:55:43 2015 Nicolas Gautherin
** Last update Sun Nov  1 21:25:40 2015 Nicolas Gautherin
*/

#include "infnb.h"
#include "bistro.h"

int	infnb_mod_p(t_eval_data *d, t_infnb *result,
		     t_infnb *left, t_infnb *right)
{
  t_infnb       tmp;

  if (infnb_new(&tmp, (left->len - left->offset)) == E_ERR_MALLOC)
    return (E_ERR_MALLOC);
  infnb_clear(d, &tmp);
  if ((right->offset + 1 == right->len) &&
       (right->data[right->offset] == d->base[0]))
    return (E_ERR_MOD_BY_ZERO);
  infnb_cpy(d, result, left);
  while (infnb_is_biggest(d, result, right) >= 0)
    {
      infnb_sub_p(d, &tmp, result, right);
      infnb_cpy(d, result, &tmp);
    }
  infnb_free(&tmp);
  return (E_NO_ERR);
}
