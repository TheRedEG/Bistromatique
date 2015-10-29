/*
** eval_rules.c for Bistromathique in 
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Thu Oct 29 19:33:21 2015 denuit mathieu
** Last update Fri Oct 30 00:26:43 2015 denuit mathieu
*/

#include "eval.h"
#include "infnb.h"
#include "bistro.h"

int	e_check_expression_end(int type, int r_par)
{
  if ((r_par && type != TOK_R_PAREN) || (!r_par && type != -1))
  {
    if (r_par && type == -1)
      return (E_ERR_SYNTAX); /*eval_error("expression missing ')'");*/
    else
      return (E_ERR_SYNTAX); /*eval_error("expression can't continue with %data");*/
  }
  return (E_NO_ERR);
}

int		e_expression(t_eval_data *data, t_infnb *nb_out, int r_par)
{
  t_infnb	right;
  int		type;
  int		err;

  if ((err = e_factor(data, nb_out)) != E_NO_ERR)
    return (err);
  type = data->token.type;
  while (type == TOK_ADD || type == TOK_SUB)
  {
    if ((err = token_next(data)) != E_NO_ERR)
      return (eval_error_free(err, &right));
    if ((err = e_factor(data, &right)) != E_NO_ERR)
      return (eval_error_free(err, &right));
    if ((err = infnb_operation(data, nb_out, &right)) != E_NO_ERR)
      return (eval_error_free(err, &right));
    type = data->token.type;
  }
  return (e_check_expression_end(type, r_par));
}

int		e_factor(t_eval_data *data, t_infnb *nb_out)
{
  t_infnb	right;
  int		type;
  int		err;

  if ((err = e_number(data, nb_out)) != E_NO_ERR)
    return (err);
  type = data->token.type;
  while (type == TOK_MUL || type == TOK_DIV || type == TOK_MOD)
  {
    if ((err = token_next(data)) != E_NO_ERR)
      return (eval_error_free(err, &right));
    if ((err = e_number(data, &right)) != E_NO_ERR)
      return (eval_error_free(err, &right));
    if ((err = infnb_operation(data, nb_out, &right)) != E_NO_ERR)
      return (eval_error_free(err, &right));
    type = data->token.type;
  }
  return (E_NO_ERR);
}

int	e_number_neg(t_eval_data *data, int *neg_out)
{
  int	sign;
  int	err;

  sign = 1;
  while (data->token.type == TOK_ADD || data->token.type == TOK_SUB)
  {
    if (data->token.type == TOK_SUB)
      sign *= -1;
    err = token_next(data);
    if (err != E_NO_ERR)
      return (err);
  }
  *neg_out = (sign < 0);
  return (E_NO_ERR);
}

int	e_number(t_eval_data *data, t_infnb *nb_out)
{
  int	neg;
  int	err;

  if ((err = e_number_neg(data, &neg)) != E_NO_ERR)
    return (err);
  if (data->token.type == TOK_NUMBER)
    eval_copy_token_in_nb(neg, &data->token, nb_out);
  else if (data->token.type == TOK_L_PAREN)
  {
    if ((err = token_next(data)) != E_NO_ERR)
      return (err);
    if ((err = e_expression(data, nb_out, 1)) != E_NO_ERR)
      return (err);
    if (neg && nb_out->is_neg)
      nb_out->is_neg = 0;
    else if (neg && !nb_out->is_neg)
      nb_out->is_neg = 1;
  }
  else
    return (E_ERR_SYNTAX); /*eval_error("expected number or '('");*/
  return (token_next(data));
}
