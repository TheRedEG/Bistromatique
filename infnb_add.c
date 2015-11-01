/*
** infnb_add_p.c for Bistromathique in /girole_t/
** 
** Made by Thomas Girolet
** Login   <girole_t@epitech.net>
** 
** Started on  Wed Oct 28 15:21:15 2015 Thomas Girolet
** Last update Sun Nov  1 22:02:52 2015 denuit mathieu
*/

#include "bistro.h"
#include "infnb.h"
#include "infnb_it.h"

void	do_addinf_carry(t_infnb *result, t_infnb_it *it)
{
  int	dig_res;
  int	dig_r;
  int	dig_l;
  int	i;
  int	carry;
  
  carry = 0;
  i = result->len - 1;
  while (infnb_it_next_digit(it, &dig_l, &dig_r))
  {
    dig_res = dig_l + dig_r + carry;
    carry = (dig_res >= it->base_len) ? 1 : 0;
    if (carry)
      dig_res -= it->base_len;
    result->data[i] = it->base[dig_res];
    i -= 1;
  }
  if (carry)
  {
    result->data[i] = it->base[1];
    i -= 1;
  }
  result->offset = i + 1;
}

void	infnb_copy(t_infnb *dest, t_infnb *src)
{
  int	i;
  int	j;

  i = dest->len - 1;
  j = src->len - 1;
  while (i >= 0 && j >= src->offset)
  {
    dest->data[i] = src->data[j];
    i -= 1;
    j -= 1;
  }
}

void	infnb_swap(t_infnb *left, t_infnb *right)
{
  t_infnb	tmp;

  tmp = *left;
  *left = *right;
  *right = tmp;
}

int		infnb_add_p(t_eval_data *data, t_infnb *result,
			     t_infnb *left, t_infnb *right)
{
  t_infnb_it	it;

  infnb_swap_biggest(&left, &right, data->base);
  if (!infnb_iszero(right, data->base))
  {
    infnb_it_init(&it, data, left, right);
    do_addinf_carry(result, &it);
  }
  else
  {
    result->offset = left->offset + (result->len - left->len);
    infnb_copy(result, left);
  }
  return (E_NO_ERR);
}
