/*
** infnb.c for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Tue Oct 27 18:50:32 2015 denuit mathieu
** Last update Sun Nov  1 11:35:13 2015 denuit mathieu
*/

#include "infnb.h"
#include "bistro.h"
#include "eval.h"
#include "my.h"

int	char_index(char c, const char *str)
{
  int	i;

  i = 0;
  while (str[i])
  {
    if (str[i] == c)
      return (i);
    i += 1;
  }
  return (-1);
}

int	infnb_new(t_infnb *nb, int size)
{
  nb->data = my_malloc(sizeof(char) * size);
  if (!nb->data)
    return (E_ERR_MALLOC);
  nb->len = size;
  nb->offset = 0;
  nb->allocated = 1;
  nb->is_neg = 0;
  return (E_NO_ERR);
}

void	infnb_print(t_eval_data *data, t_infnb *nb)
{
  int	i;

  if (!nb)
    return ;
  if (infnb_iszero(nb, data->base))
    my_putchar(nb->data[nb->offset]);
  else
  {
    if (nb->is_neg)
      my_putchar('-');
    i = nb->offset;
    while (i < nb->len)
    {
      my_putchar(nb->data[i]);
      i += 1;
    }
  }
}

void	infnb_free(t_infnb *nb)
{
  if (!nb)
    return ;
  if (nb->allocated)
  {
    my_free(nb->data);
  }
  infnb_init(nb);
}

