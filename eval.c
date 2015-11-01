/*
** parser.c for eval_expr in /home/denuit_m
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Wed Oct 21 14:16:34 2015 denuit mathieu
** Last update Sun Nov  1 23:38:51 2015 denuit mathieu
*/

#include "my.h"
#include "eval.h"
#include "infnb.h"
#include "bistro.h"

void	eval_copy_token_in_nb(int is_neg, t_token *token, t_infnb *nb_out)
{
  nb_out->allocated = 0;
  nb_out->data = (char*) token->data;
  nb_out->len = token->len;
  nb_out->is_neg = is_neg;
  nb_out->offset = 0;
}

int	eval_error_free(int error, t_infnb *nb)
{
  infnb_free(nb);
  return (error);
}

int	eval_read_buffer(int size, char **buf_out)
{
  int	len;
  int	total_len;

  *buf_out = malloc(sizeof(char) * (size + 1));
  if (!*buf_out)
    return (E_ERR_MALLOC);
  total_len = 0;
  while ((len = read(0, *buf_out + total_len, 1024)) > 0)
  {
    total_len += len;
    if (total_len >= size)
    {
      (*buf_out)[size] = 0;
      break;
    }
  }
  if (total_len < size)
  {
    free(*buf_out);
    return (E_ERR_READ);
  }
  return (E_NO_ERR);
}

int		eval_expr(char *base, char *ops, int size)
{
  t_eval_data	data;
  char		*in_buf;
  int		err;
  t_infnb	nb_out;

  infnb_init(&nb_out);
  data.base = base;
  data.base_len = my_strlen(data.base);
  data.operators = ops;
  if ((err = eval_read_buffer(size, &in_buf)) != E_NO_ERR)
    return (err);
  data.in_buf = in_buf;
  if ((err = token_next(&data)) != E_NO_ERR)
  {
    free(in_buf);
    return (err);
  }
  if ((err = e_expression(&data, &nb_out, 0)) == E_NO_ERR)
    infnb_print(&data, &nb_out);
  infnb_free(&nb_out);
  free(in_buf);
  return (err);
}
