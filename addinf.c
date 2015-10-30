/*
** addinf.c for addinf.c in 
** 
** Made by Thomas Girolet
** Login   <girole_t@epitech.net>
** 
** Started on  Wed Oct 28 15:21:15 2015 Thomas Girolet
** Last update Fri Oct 30 13:18:10 2015 Thomas Girolet
*/

#include "bistro.h"
#include "infnb.h"
#include "addinf.h"

int	decimal_at(char *s, int index, int len)
{
  if (index < 0 || index >= len)
    return (0);
  else
    return (s[index] - '0');
}

char	do_addinf_carry(t_infnb *result, int *s1c, int *s2c, int *carry)
{
  char	res;
  
  res = decimal_at(left->data, *s1c, left->len) + *carry;
  res += decimal_at(right->data, *s2c, right->len) + *carry;
  *carry = res >= g_base_len ? 1 : 0; 
  if (*carry)
    res -= 10;
  res += '0';
  *s1c -= 1;
  *s2c -= 1;
  return (res);
}

int	infnb_add_p(t_eval_data *d, t_infnb *result, t_infnb *left, t_infnb *right)
{
  int	s1;
  int	s2;
  int	carry;
  
  s1 = left->len - 1;
  s2 = right->len - 1;
  carry = 0;
  while(s1 >= 0)
    {
      result->data[] = do_addinf_carry(result ,&s1, &s2, &carry);
    }
}
