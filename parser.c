/*
** parser.c for Bistromathique in /home/denuit_m
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Wed Oct 21 12:10:23 2015 denuit mathieu
** Last update Tue Oct 27 21:24:51 2015 denuit mathieu
*/

#include "my.h"
#include "parser.h"
#include "infnb.h"

void	parse_operator(t_parser_data *data, char **buf)
{
  data->last_node->type = char_index(**buf, data->operators);
  data->last_node->len = 1;
  data->last_node->data = *buf;
  *buf += 1;
  data->last_node = new_token_after(data->last_node);
}

void	parse_number(t_parser_data *data, char **buf)
{
  data->last_node->type = TOK_NUMBER;
  data->last_node->len = infnb_nbrlen(*buf, data->base);
  data->last_node->data = *buf;
  *buf += data->last_node->len;
  data->last_node = new_token_after(data->last_node);
}

int	make_tokens(t_parser_data *data, char *buf)
{
  while (*buf)
  {
    while (*buf == ' ' || *buf == '\t' || *buf == '\n')
      buf += 1;
    if (char_index(*buf, data->base) >= 0)
      parse_number(data, &buf);
    else if (char_index(*buf, data->operators) >= 0)
      parse_operator(data, &buf);
    else
      ;
  }
  return (1);
}

char	*read_buffer(int size)
{
  char	*buf;
  int	len;
  int	total_len;

  buf = malloc(sizeof(char) * size);
  if (!buf)
    return (0);
  total_len = 0;
  while ((len = read(0, buf + total_len, size)) > 0)
  {
    total_len += len;
    if (total_len > size)
    {
      buf[size] = 0;
      break;
    }
  }
  if (total_len < size)
    ;
  return (buf);
}

t_tokens	*parse_expr(const char *base, const char *ops, int size)
{
  t_parser_data	data;
  t_tokens	*root;
  char		*buf;

  root = new_token_after(0);
  data.last_node = root;
  data.base = base;
  data.operators = ops;
  buf = read_buffer(size);
  make_tokens(&data, buf);
  return (root);
}
