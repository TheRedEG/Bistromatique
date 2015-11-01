/*
** infnb_is_biggest.c for is_biggest in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Sat Oct 31 17:53:14 2015 Nicolas Gautherin
** Last update Sat Oct 31 23:57:58 2015 Nicolas Gautherin
*/

#include "infnb.h"
#include "my.h"
#include "bistro.h"

int	infnb_is_biggest(t_eval_data *d, t_infnb *s1, t_infnb *s2)
{
  int	index;

  my_putstr("  s1: ");
  infnb_print(d, s1);
  my_putstr("  s2: ");
  infnb_print(d, s2);
  if ((s1->len - s1->offset) != (s2->len - s2->offset))
    return ((s1->len - s1->offset) - (s2->len - s2->offset));
  index = s1->offset;
  while (index <= (s1->len - s1->offset))
    {
      if (s1->data[s1->offset + index] != s2->data[s2->offset + index])
	{
	return (char_index(s1->data[s1->offset + index], d->base) -
		char_index(s2->data[s2->offset + index], d->base));
	}
      index = index + 1;
    }
  return (0);
}
