/*
** parser.c for Bistromathique in /home/denuit_m
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Wed Oct 21 12:10:23 2015 denuit mathieu
** Last update Sat Oct 31 18:33:07 2015 denuit mathieu
*/

#include "my.h"
#include "token.h"
#include "infnb.h"
#include "bistro.h"

void	token_parse_operator(t_eval_data *data)
{
  data->token.type = char_index(*data->in_buf, data->operators);
  data->token.len = 1;
  data->token.data = data->in_buf;
  data->in_buf += 1;
}

void	token_parse_number(t_eval_data *data)
{
  data->token.type = TOK_NUMBER;
  while (*data->in_buf && char_index(*data->in_buf, data->base) == 0)
    data->in_buf += 1;
  if (char_index(*data->in_buf, data->base) == -1)
  {
    data->token.len = 1;
    data->token.data = data->in_buf - 1;
  }
  else
  {
    data->token.len = infnb_nbrlen(data->in_buf, data->base);
    data->token.data = data->in_buf;
    data->in_buf += data->token.len;
  }
}

void	token_set_end(t_token *token)
{
  token->type = -1;
  token->len = 0;
  token->data = 0;
}

int	token_next(t_eval_data *data)
{
  if (*data->in_buf == '\0')
    token_set_end(&data->token);
  else if (char_index(*data->in_buf, data->base) >= 0)
    token_parse_number(data);
  else if (char_index(*data->in_buf, data->operators) >= 0)
    token_parse_operator(data);
  else
    return (E_ERR_INVALID_CHAR);
  return (E_NO_ERR);
}

