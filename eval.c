/*
** eval.c for Bistromathique in 
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 26 16:51:35 2015 denuit mathieu
** Last update Wed Oct 28 01:21:02 2015 denuit mathieu
*/

#include "parser.h"
#include "infnb.h"

int		eval_expr(char *base, char *operators, int size)
{
  t_tokens	*tokens;
  t_infnb	nb;

  tokens = parse_expr(base, operators, size);
  if (tokens == 0)
    return (1);
  eval_tokens(tokens, &nb);
  free_tokens(tokens);
  printf("Eval gives: %s\n", nb.data);
  return (0);
}
