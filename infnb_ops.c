/*
** infnb_ops.c for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Thu Oct 29 23:44:09 2015 denuit mathieu
** Last update Fri Oct 30 21:32:50 2015 denuit mathieu
*/

#include "infnb.h"

void	print_op(t_eval_data *d, char op, t_infnb *left, t_infnb *right)
{
  my_putstr("Computing ");
  infnb_print(d, left);
  my_putchar(' ');
  my_putchar(op);
  my_putchar(' ');
  infnb_print(d, right);
  my_putchar('\n');
}

int	infnb_add(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  //print_op(d, '+', left, right);
  if (left->is_neg && !right->is_neg) // -a + b  =>  b - a
    return (infnb_sub_p(d, res, right, left));
  else if (!left->is_neg && right->is_neg) // a + -b  =>  a - b
    return (infnb_sub_p(d, res, left, right));
  else if (left->is_neg && right->is_neg) // -a + -b  =>  -(a + b)
  {
    err = infnb_add_p(d, res, left, right);
    infnb_negate(res);
    return (err);
  }
  else
    return (infnb_add_p(d, res, left, right)); // a + b  =>  a + b
}

int	infnb_sub(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  //print_op(d, '-', left, right);
  if (left->is_neg && !right->is_neg) // -a - b  =>  -(a + b)
  {
    err = infnb_add_p(d, res, left, right);
    infnb_negate(res);
    return (err);
  }
  else if (!left->is_neg && right->is_neg) // a - -b  =>  a + b
    return (infnb_add_p(d, res, left, right));
  else if (left->is_neg && right->is_neg) // -a - -b  =>  b - a
    return (infnb_sub_p(d, res, right, left));
  else
    return (infnb_sub_p(d, res, left, right)); // a - b  =>  a - b
}

int	infnb_mul(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  //print_op(d, '*', left, right);
  err = infnb_mul_p(d, res, left, right);
  if ((left->is_neg && !right->is_neg) || (!left->is_neg && right->is_neg))
    infnb_negate(res);
  return (err);
}

int	infnb_div(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  //print_op(d, '/', left, right);
  err = infnb_div_p(d, res, left, right);
  if ((left->is_neg && !right->is_neg) || (!left->is_neg && right->is_neg))
    infnb_negate(res);
  return (err);
}

int	infnb_mod(t_eval_data *d, t_infnb *res, t_infnb *left, t_infnb *right)
{
  int	err;

  //print_op(d, '%', left, right);
  err = infnb_mod_p(d, res, left, right);
  if (left->is_neg)
    infnb_negate(res);
  return (err);
}
