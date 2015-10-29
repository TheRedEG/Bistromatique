/*
** eval.h for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Thu Oct 29 19:35:25 2015 denuit mathieu
** Last update Fri Oct 30 00:15:30 2015 denuit mathieu
*/

#ifndef EVAL_H_
# define EVAL_H_

#include "token.h"

typedef struct s_infnb t_infnb;

typedef struct	s_eval_data
{
  const char *base;
  int base_len;
  const char *operators;
  char *in_buf;
  t_token token;
}		t_eval_data;

int	eval_expr(char *base, char *ops, int size);
int	eval_read_buffer(int size, char **buf_out);
int	eval_error_free(int error, t_infnb *nb);
void	eval_copy_token_in_nb(int is_neg, t_token *token, t_infnb *nb_out);
int	e_expression(t_eval_data *data, t_infnb *nb_out, int r_par);
int	e_check_expression_end(int type, int r_par);
int	e_factor(t_eval_data *data, t_infnb *nb_out);
int	e_number_neg(t_eval_data *data, int *neg_out);
int	e_number(t_eval_data *data, t_infnb *nb_out);

#endif /* !EVAL_H_ */
