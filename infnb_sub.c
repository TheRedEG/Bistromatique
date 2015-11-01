/*
** addinf.c for addinf.c in 
** 
** Made by Thomas Girolet
** Login   <girole_t@epitech.net>
** 
** Started on  Wed Oct 28 15:21:15 2015 Thomas Girolet
** Last update Sun Nov  1 15:53:37 2015 denuit mathieu
*/

#include "bistro.h"
#include "infnb.h"
#include "infnb_it.h"

void	do_subinf_carry(t_infnb *result, t_infnb_it *it)
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
    dig_res = dig_l - dig_r - carry;
    carry = (dig_res < 0) ? 1 : 0;
    if (carry)
      dig_res += it->base_len;
    result->data[i] = it->base[dig_res];
    i -= 1;
  }
  result->offset = i + 1;
  infnb_skip_zero(result, it->base);
}

int		infnb_sub_p(t_eval_data *data, t_infnb *result,
			     t_infnb *left, t_infnb *right)
{
  t_infnb_it	it;
  int		swapped;
  
  swapped = infnb_swap_biggest(left, right, data->base);
  if (!infnb_iszero(right, data->base))
  {
    infnb_it_init(&it, data, left, right);
    do_subinf_carry(result, &it);
  }
  else
  {
    result->offset = left->offset + (result->len - left->len);
    if (result->data != left->data)
      infnb_copy(result, left);
  }
  if (swapped)
    infnb_negate(result);
  return (E_NO_ERR);
}
