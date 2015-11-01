/*
** infnb_mod.c for infnb_mod in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Sat Oct 31 12:55:43 2015 Nicolas Gautherin
** Last update Sat Oct 31 19:34:58 2015 Nicolas Gautherin
*/

#include "infnb.h"
#include "bistro.h"

int	infnb_mod_p(t_eval_data *d, t_infnb *result,
		     t_infnb *left, t_infnb *right)
{
  t_infnb       tmp;

  if (infnb_new(&tmp, (left->len - left->offset)) == 2)
    return (2);
  if ((right->offset + 1 == right->len) &&
       (right->data[right->offset] == d->base[0]))
    return (3);
  if ((right->offset + 1 == right->len) && (right->data[right->offset] == d->base[1]))
    {
      infnb_cpy(d, result, left);
      return (0);
    }
  preset_tmp(d, &tmp, (left->len - right->len));
  my_putstr("tmp: ");
  infnb_print(d, &tmp);
  my_putchar('A');
  usleep(300000);
  while (infnb_is_biggest(d, left, &tmp) >= 0)
    {
      infnb_sub_p(d, result, left, &tmp);
      infnb_add_p(d, &tmp, &tmp, right);
    
    }
  infnb_free(&tmp);
  return (0);
}
