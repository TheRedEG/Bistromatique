/*
** addinf.c for addinf.c in 
** 
** Made by Thomas Girolet
** Login   <girole_t@epitech.net>
** 
** Started on  Wed Oct 28 15:21:15 2015 Thomas Girolet
** Last update Fri Oct 30 13:45:30 2015 Thomas Girolet
*/

#include "bistro.h"
#include "infnb.h"
#include "addinf.h"

char	do_addinf_carry(t_infnb *result, t_infnb_it *it)
{
  int	dig_r;
  int	dig_l;
  
  if (infnb_it_next_digit(it, &dig_l, &dig_r))
    {	  
      int result = dig_r + dig_l;
      if (result = )
    }
}

int	infnb_add_p(t_eval_data *d, t_infnb *result, t_infnb *left, t_infnb *right)
{
  t_infnb_it	it;
  int	s1;
  int	s2;
  int	carry;
  
  intnb_it_init(&it, d, left, right);
  s1 = left->len - 1;
  s2 = right->len - 1;
  carry = 0;
  while(s1 >= 0)
    {
      result->data[] = do_addinf_carry(result , &it);
    }
}
