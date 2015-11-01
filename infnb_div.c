/*
** infnb_div.c for infnb_div in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Wed Oct 28 13:43:50 2015 Nicolas Gautherin
** Last update Sun Nov  1 22:23:54 2015 denuit mathieu
*/

#include "infnb.h"
#include "bistro.h"

int	div_return_error(int err, t_infnb *free1)
{
  free(free1);
  return (err);
}

void	infnb_setzero(t_infnb *nb, const char *base)
{
  int	i;

  i = 0;
  while (i < nb->len)
  {
    nb->data[i] = base[0];
    i += 1;
  }
  nb->offset = nb->len - 1;
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
  int		err;

  if (infnb_iszero(right, d->base))
    return (E_ERR_DIV_BY_ZERO);
  if ((err = infnb_new(&acc, left->len - left->offset + 1)) != E_NO_ERR)
    return (div_return_error(err, &acc));
  infnb_setzero(result, d->base);
  infnb_setzero(&acc, d->base);
  const_nb_init(&const_nb, 1, d->base);
  while (infnb_max(&acc, left, d->base) == left)
  {
    infnb_add_p(d, &acc, &acc, right);
    infnb_add_p(d, result, result, &const_nb);
  }
  my_putchar(' ');
  infnb_print(d, &acc);
  my_putchar(' ');
  infnb_print(d, left);
  my_putchar(' ');
  infnb_print(d, result);
  my_putchar('\n');
  if (acc.len - acc.offset > left->len - left->offset ||
      infnb_nbrcmp(&acc, left, d->base) > 0)
    infnb_sub_p(d, result, result, &const_nb);
  infnb_free(&acc);
  return (E_NO_ERR);
}
