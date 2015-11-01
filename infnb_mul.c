/*
** infnb_mul.c for infnb_mul in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Wed Oct 21 15:43:19 2015 Nicolas Gautherin
** Last update Sun Nov  1 18:01:24 2015 Nicolas Gautherin
*/

#include "infnb.h"
#include "bistro.h"

void	newtmp(t_eval_data *d, t_infnb *tmp, t_infnb *left, int rank)
{
  int	index;
  int	i;

    
  tmp->offset = tmp->len - (left->len - left->offset);

  my_putstr("  tmp->offset: ");
  my_put_nbr(tmp->offset);
  my_putstr("  tmp->len: ");
  my_put_nbr(tmp->len);
  index = tmp->len - 1;
  my_putstr("\nleft: ");
  infnb_print(d, left); 
  my_putstr("  rank1: ");
  my_put_nbr(rank);

  while (rank != 0)
    {
      my_putstr(" index0: ");
      my_put_nbr(index);
      my_putchar('_');
      tmp->data[index] = d->base[0];
      my_putchar(tmp->data[index]);
      index = index - 1;
      rank = rank - 1;
    }
  rank = left->len;
  my_putstr("  rank2: ");
  my_put_nbr(rank);
  while (rank > left->offset)
    {
      my_putstr("   tmp->data[index1(");
      my_put_nbr(index);
      my_putstr(")]=");
      tmp->data[index] = left->data[rank - 1];
      my_putchar(tmp->data[index]);
      rank = rank - 1;
      index = index - 1;
    }
  my_putstr("\ntmp1: ");
  infnb_print(d, tmp);
}

void	m(t_infnb *a)
{
  int	i;

  i = 0;
  while (i < a->len)
    {
      a->data[i] = '0';
      i = i + 1;
    }
}

int		do_multinf(t_eval_data *d, t_infnb *result,
			     t_infnb *left, t_infnb *right)
{
  int		index;
  int		j;
  t_infnb	tmp;
  t_infnb	tmp2;
 
  if (infnb_new(&tmp, (left->len - left->offset) +
                (right->len - right->offset)) == 2)
    return (2);
  if (infnb_new(&tmp2, (tmp.len)) == 2)
      return (2);
  index = right->len - 1;
  result->offset =result->len - (left->len - left->offset);
  while (index >= right->offset)
    {
      my_putstr("\n###########################\n");
      newtmp(d, &tmp, left, (right->len - 1 - index));

      my_putstr("  index: ");
      my_putchar(index + 48);
      j = char_index(right->data[index], d->base);
      my_putstr("   j:(right->data[index]=");
      my_putchar(right->data[index]);
      my_putstr(") = ");
      my_put_nbr(j);
      while (j > 0)
	{
	  my_putstr("\nj: ");
	  my_put_nbr(j);
	  my_putstr("   tmpA: ");
	  infnb_print(d, &tmp);
	  infnb_cpy(d, &tmp2, &tmp);
	  my_putstr("   tmp2A: ");
	  infnb_print(d, &tmp2);  
	  my_putstr("  offsetA: ");
	  my_put_nbr(tmp2.offset);
	  my_putstr("   result->offsetA: ");
	  my_put_nbr(result->offset);
	  infnb_add_p(d, result, result, &tmp2);
	  my_putstr("\nresult->offsetB: ");
	  my_put_nbr(result->offset);
	  my_putstr("  offsetB: ");
	  my_put_nbr(tmp2.offset);	  
	  //	  my_putstr("   tmp2B: ");
	  //infnb_print(d, &tmp2);
	  my_putstr("   tmpB: ");
	  infnb_print(d, &tmp);
	  my_putstr("   resultB: ");
	  infnb_print(d, result);
	  my_putstr("   tmpC: ");
	  infnb_print(d, &tmp);
	  j = j - 1;
	}
      my_putchar('\n');
      index = index - 1;
    }
  infnb_free(&tmp);
  infnb_free(&tmp2);
  return (0);
}

void	infnb_cpy(t_eval_data *d, t_infnb *new, t_infnb *src)
{
  int	index;

  new->is_neg = src->is_neg;
  index = 0;
  while (src->len - index > src->offset)
    {
      new->data[new->len - 1 - index] = src->data[src->len - 1 - index];
      index = index + 1;
    }
  new->offset = new->len - (src->len - src->offset);
}

int	infnb_mul_p(t_eval_data *d, t_infnb *result,
		     t_infnb *left, t_infnb *right)
{
  //  infnb_swap_biggest(left, right, d->base);
  my_putstr("left: [");
  my_putstr("data: ");
  infnb_print(d, left);
  my_putstr("  len: ");
  my_put_nbr(left->len);
  my_putstr("  offset: ");
  my_put_nbr(left->offset);  
  my_putstr("]\nright:[");
  my_putstr("data: ");
  infnb_print(d, right);
  my_putstr("  len: ");
  my_put_nbr(right->len);
  my_putstr("  offset: ");
  my_put_nbr(right->offset);  
  my_putstr("]\n");




  if ((char_index(left->data[left->offset], d->base) == 0) &&
       (left->len - left->offset == 1))
    {
      infnb_cpy(d, result, left);      
      return (0);
    }
  if ((char_index(right->data[right->offset], d->base) == 0) &&
       (right->len - right->offset == 1))
    {
      infnb_cpy(d, result, right);      
      return (0);
    }
  if (do_multinf(d, result, left, right) == 2)
    return (2);
  my_putchar('\n');
  return (0);
}
