/*
** eval.c for Bistromathique in 
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 26 16:51:35 2015 denuit mathieu
** Last update Tue Oct 27 11:47:23 2015 denuit mathieu
*/

#include "parser.h"

int		eval_expr(char *base, char *operators, unsigned long size)
{
  t_tokens	*tokens;

  tokens = parse_expr(base, operators, size);
}
