/*
** main.c for Bistromathique in /home/denuit_m/rendu/bistromatique
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 19 16:08:35 2015 denuit mathieu
** Last update Fri Oct 30 16:11:35 2015 Thomas Girolet
*/

#include "bistro.h"
#include "my.h"
#include "str_to_ulong.h"

int	check_base(char *base)
{
  /* Vérifier que la base à 2 chars minimum, 250 maximum, et aucun caractère
  identique (erreur -> return 0) */

  if (my_strlen(b) < 2 || mystrlen(b) > 250)
    return (0);
  return (1);
}

int	check_ops(char *ops, char *base)
{
  /* Vérifier que les opérateurs ont 5 chars précisément, et aucun caractère
  identique, et aucun caractère présent dans la base (erreur -> return 0) */

  return (1);
}

void	show_usage(char *argv0)
{
  my_putstr("Usage: ");
  my_putstr(argv0);
  my_putstr(" base ops\"()+-*/%\" exp_len\n");
}

int	main(int argc, char **argv)
{
  int	size;
  int	err;

  if (argc != 4)
  {
    show_usage(argv[0]);
    return (1);
  }
  if (!check_base(argv[1]))
  {
    my_putstr("Base incorrect.\n");
    return (1);
  }
  if (!check_ops(argv[2], argv[1]))
  {
    my_putstr("Operators incorrect.\n");
    return (1);
  }
  size = str_to_ulong(argv[3]);
  if (size <= 0)
  {
    my_putstr("Size incorrect.\n");
    return (1);
  }
  err = eval_expr(argv[1], argv[2], size);
  printf("Returned error %d\n", err);
  return (-err);
}

