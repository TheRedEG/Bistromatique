/*
** infnb2.c for Bistromathique in 
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Sun Nov  1 23:40:40 2015 denuit mathieu
** Last update Sun Nov  1 23:42:29 2015 denuit mathieu
*/

#include "infnb.h"
#include "bistro.h"
#include "eval.h"
#include "my.h"

void	infnb_init(t_infnb *nb)
{
  nb->is_neg = 0;
  nb->len = 0;
  nb->offset = 0;
  nb->data = 0;
  nb->allocated = 0;
}

int	infnb_reuse(int size, t_infnb *result, t_infnb *nb)
{
  if (nb->allocated && nb->len >= size)
  {
    result->len = nb->len;
    result->data = nb->data;
    result->is_neg = 0;
    result->allocated = 1;
    nb->allocated = 0;
    return (1);
  }
  return (0);
}
