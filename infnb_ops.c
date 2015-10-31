/*
** infnb_ops.c for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Thu Oct 29 23:44:09 2015 denuit mathieu
** Last update Sat Oct 31 15:47:59 2015 denuit mathieu
*/

#include "infnb.h"

int	infnb_add(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  if (left->is_neg && !right->is_neg)
    return (infnb_sub_p(d, res, right, left));
  else if (!left->is_neg && right->is_neg)
    return (infnb_sub_p(d, res, left, right));
  else if (left->is_neg && right->is_neg)
  {
    err = infnb_add_p(d, res, left, right);
    infnb_negate(res);
    return (err);
  }
  else
    return (infnb_add_p(d, res, left, right));
}

int	infnb_sub(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  if (left->is_neg && !right->is_neg)
  {
    err = infnb_add_p(d, res, left, right);
    infnb_negate(res);
    return (err);
  }
  else if (!left->is_neg && right->is_neg)
    return (infnb_add_p(d, res, left, right));
  else if (left->is_neg && right->is_neg)
    return (infnb_sub_p(d, res, right, left));
  else
    return (infnb_sub_p(d, res, left, right));
}

int	infnb_mul(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  err = infnb_mul_p(d, res, left, right);
  if ((left->is_neg && !right->is_neg) || (!left->is_neg && right->is_neg))
    infnb_negate(res);
  return (err);
}

int	infnb_div(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  err = infnb_div_p(d, res, left, right);
  if ((left->is_neg && !right->is_neg) || (!left->is_neg && right->is_neg))
    infnb_negate(res);
  return (err);
}

int	infnb_mod(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  err = infnb_mod_p(d, res, left, right);
  if (left->is_neg)
    infnb_negate(res);
  return (err);
}
