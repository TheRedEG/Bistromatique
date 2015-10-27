/*
** parser.c for Bistromathique in /home/denuit_m
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Wed Oct 21 12:10:23 2015 denuit mathieu
** Last update Tue Oct 27 14:49:44 2015 denuit mathieu
*/

#include "my.h"
#include "parser.h"

void	parse_operator(t_parser_state *state, char **buf)
{
  state->last_node->type = char_index(**buf, state->operators);
  state->last_node->nb_id = -1;
  state->last_node = new_token_after(state->last_node);
  state->size_left -= 1;
  *buf += 1;
}

void	parse_whitespace(t_parser_state *state, char **buf)
{
  while (**buf == ' ' || **buf == '\t' || **buf == '\n')
  {
    *buf += 1;
    state->size_left -= 1;
  }
}

int	parse_block_number(t_parser_state *state, char **buf)
{
  if (state->current_nb_id == -1)
  {
    state->type = TOK_NUMBER;
    state->nb_id = infnb_create();
    state->current_nb_id = state->nb_id;
  }
  while (char_index(**buf, state->base) != -1)
  {
    infnb_add_digit(state->current_nb_id, **buf);
    *buf += 1;
    state->size_left -= 1;
  }
  if (**buf)
  {
    state->last_node = new_token_after(state->last_node);
    state->current_nb_id = -1;
    return (1);
  }
  return (0);
}

int	parse_block(t_parser_state *state, char *buf)
{
  int	result;

  if (state->current_nb_id != -1)
  {
    result = parse_block_number(state, &buf);
    if (result)
      return (parse_block(state, buf));
    else if (result == 0)
      return (1);
  }
  else
  {
    while (*buf)
    {
      parse_whitespace(state, &buf);
      if (char_index(*buf, state->base) >= 0 && parse_block_number(state, &buf) == 0)
	return (1);
      else if (char_index(*buf, state->operators) >= 0)
	parse_operator(state, &buf);
    }
  }
  return (1);
}

t_tokens		*parse_expr(char *base, char *operators, unsigned long size)
{
  t_parser_state	state;
  t_tokens		*root;
  char			buf[PARSER_BUFFER_SIZE + 1];
  int			len;

  root = new_token_after(0);
  state.current_nb_id = -1;
  state.size_left = size;
  state.last_node = root;
  state.base = base;
  state.operators = operators;
  while (state.size_left > 0)
  {
    len = read(0, buf, PARSER_BUFFER_SIZE);
    if (len == 0)
      tokens_error();
    buf[(len > state.size_left) ? state.size_left : len] = 0;
    if (!parse_block(&state, buf))
      return (0);
  }
  return (root);
}
