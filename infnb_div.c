/*
** infnb_div.c for infnb_div in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Wed Oct 28 13:43:50 2015 Nicolas Gautherin
** Last update Sun Nov  1 23:24:00 2015 denuit mathieu
*/

#include "infnb.h"
#include "bistro.h"

int	div_return_error(int err, t_infnb *free1, t_infnb *free2)
{
  infnb_free(free1);
  infnb_free(free2);
  return (err);
}

void	infnb_setzero(t_infnb *nb, t_infnb *nb2, const char *base)
{
  int	i;

  i = 0;
  while (i < nb->len)
  {
    nb->data[i] = base[0];
    i += 1;
  }
  nb->offset = nb->len - 1;
  i = 0;
  while (i < nb2->len)
  {
    nb2->data[i] = base[0];
    i += 1;
  }
  nb2->offset = nb2->len - 1;
}

void	const_nb_init(t_infnb *nb, int digit, const char *base)
{
  nb->allocated = 0;
  nb->offset = 0;
  nb->len = 1;
  nb->data = (char*) (base + digit);
  nb->is_neg = 0;
}

int		infnb_div_p(t_eval_data *d, t_infnb *result,
			     t_infnb *left, t_infnb *right)
{
  t_infnb	acc;
  t_infnb	const_nb;
  t_infnb	resulttmp;
  int		err;
  
  if (infnb_iszero(right, d->base))
    return (E_ERR_DIV_BY_ZERO);
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
    infnb_sub_p(d, &resulttmp, &resulttmp, &const_nb);
  result->offset = resulttmp.offset + (result->len - resulttmp.len);
  infnb_copy(result, &resulttmp);
  return (div_return_error(E_NO_ERR, &acc, &resulttmp));
}
