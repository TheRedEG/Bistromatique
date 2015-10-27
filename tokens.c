/*
** tokens.c for Bistromathique in 
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Tue Oct 27 14:30:41 2015 denuit mathieu
** Last update Tue Oct 27 14:35:55 2015 denuit mathieu
*/

#include "parser.h"
#include "bistro.h"

t_tokens	*new_token_after(t_tokens *last)
{
  t_tokens	*node;

  node = malloc(sizeof(t_tokens));
  if (!node)
    return (0);
  node->type = -1;
  node->value = 0;
  node->next = 0;
  if (last)
    last->next = node;
  return (node);
}

void		free_tokens(t_tokens *root)
{
  t_tokens	*next_tok;

  while (root)
  {
    next_tok = root->next;
    free(root);
    root = next_tok;
  }
}

void	tokens_error(t_tokens *root)
{
  free_tokens(root);
  my_putstr(ERROR_MSG);
  exit(1);
}
