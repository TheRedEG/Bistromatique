/*
** infnb_it.h for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Fri Oct 30 13:16:00 2015 denuit mathieu
** Last update Fri Oct 30 21:11:08 2015 denuit mathieu
*/

#ifndef INFNB_IT_
# define INFNB_IT_

#include "infnb.h"

typedef struct s_eval_data t_eval_data;

typedef struct	s_infnb_it
{
  t_infnb	*left;
  int		pos_l;
  t_infnb	*right;
  int		pos_r;
  const char	*base;
  int		base_len;
}		t_infnb_it;

void	infnb_it_init(t_infnb_it *it, t_eval_data *d, t_infnb *l, t_infnb *r);
int	infnb_it_next_digit(t_infnb_it *it, int *digit_l, int *digit_r);

#endif /* !INFNB_IT */
