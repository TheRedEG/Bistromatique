/*
** infnb_div.c for infnb_div in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Wed Oct 28 13:43:50 2015 Nicolas Gautherin
** Last update Sun Nov  1 23:27:21 2015 denuit mathieu
*/

#include "infnb.h"
#include "bistro.h"

int		infnb_mod_p(t_eval_data *d, t_infnb *result,
			     t_infnb *left, t_infnb *right)
{
  t_infnb	acc;
  t_infnb	const_nb;
  t_infnb	resulttmp;
  int		err;
  
  if (infnb_iszero(right, d->base))
    return (E_ERR_MOD_BY_ZERO);
  if ((err = infnb_new(&acc, left->len - left->offset + 1)) != E_NO_ERR)
    return (err);
  if ((err = infnb_new(&resulttmp, left->len - left->offset + 1)) != E_NO_ERR)
    return (div_return_error(err, &acc, 0));
  infnb_copy(&resulttmp, result);
  infnb_setzero(&resulttmp, &acc, d->base);
  const_nb_init(&const_nb, 1, d->base);
  while (infnb_max(&acc, left, d->base) == left)
  {
    infnb_add_p(d, &acc, &acc, right);
    infnb_add_p(d, &resulttmp, &resulttmp, &const_nb);
  }
  if (acc.len - acc.offset > left->len - left->offset ||
      infnb_nbrcmp(&acc, left, d->base) > 0)
    infnb_sub_p(d, &acc, &acc, right);
  infnb_sub_p(d, result, left, &acc);
  return (div_return_error(E_NO_ERR, &acc, &resulttmp));
}
