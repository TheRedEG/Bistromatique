/*
** parser.c for eval_expr in /home/denuit_m
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Wed Oct 21 14:16:34 2015 denuit mathieu
** Last update Wed Oct 28 13:20:51 2015 denuit mathieu
*/

#include "my.h"
#include "eval.h"
#include "infnb.h"

void eval_error(char *str)
{
  my_putstr("Eval error: ");
  my_putstr(str);
  my_putchar('\n');
  exit(2);
}

void		eval_expr(t_tokens *root, t_infnb *nb_out)
{
  e_expression(&root, nb_out, 0);
}

void		e_expression(t_tokens **node, t_infnb *nb_out, int r_par)
{
  t_infnb	right;
  int		type;

  e_factor(node, nb_out);
  type = (*node)->type;
  while (type == TOK_ADD || type == TOK_SUB)
  {
    *node = (*node)->next;
    e_factor(node, &right);
    do_expression_op(nb_out, type, &right);
    infnb_free(&right);
    type = (*node)->type;
  }
  if ((r_par && type != TOK_R_PAREN) || (!r_par && type != -1))
  {
    if (r_par && type == -1)
      eval_error("expression missing ')'");
    else
      eval_error("expression can't continue with %data");
  }
}

void		e_factor(t_tokens **node, t_infnb *nb_out)
{
  t_infnb	right;
  int		type;

  e_number(node, nb_out);
  type = (*node)->type;
  while (type == TOK_MUL || type == TOK_DIV || type == TOK_MOD)
  {
    *node = (*node)->next;
    e_number(node, &right);
    do_factor_op(nb_out, type, &right);
    infnb_free(&right);
    type = (*node)->type;
  }
}

int		e_number_neg(t_tokens **node)
{
  int		sign;
  int		type;

  sign = 1;
  type = (*node)->type;
  while (type == TOK_ADD || type == TOK_SUB)
  {
    if (type == TOK_SUB)
      sign *= -1;
    *node = (*node)->next;
    type = (*node)->type;
  }
  return ((sign < 0) ? 1 : 0);
}

void		e_number(t_tokens **node, t_infnb *nb_out)
{
  int		neg;

  neg = e_number_neg(node);
  if ((*node)->type == TOK_NUMBER)
  {
    nb_out->allocated = 0;
    nb_out->data = (char*) (*node)->data;
    nb_out->len = (*node)->len;
    nb_out->neg = neg;
  }
  else if ((*node)->type == TOK_L_PAREN)
  {
    *node = (*node)->next;
    e_expression(node, nb_out, 1);
    if (neg && nb_out->neg)
      nb_out->neg = 0;
    else if (neg && !nb_out->neg)
      nb_out->neg = 1;
  }
  else
    eval_error("expected number or '('");
  *node = (*node)->next;
}
