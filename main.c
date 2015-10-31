/*
** main.c for Bistromathique in /home/denuit_m/rendu/bistromatique
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 19 16:08:35 2015 denuit mathieu
<<<<<<< HEAD
** Last update Sat Oct 31 19:14:53 2015 Thomas Girolet
=======
** Last update Sat Oct 31 18:30:57 2015 denuit mathieu
>>>>>>> f0015279b7266fe649ce85c54e811398f1afcb99
*/

#include "bistro.h"
#include "my.h"
#include "str_to_ulong.h"

int	check_base(char *base)
{
  int	i;
  int	x;
  
  if (my_strlen(base) < 2 || my_strlen(base) > 250)
    return (0);
  i = 0;
  while (base[i] != '\0')
    {
      x = i + 1;
      while (base[x] != '\0')
	{
	  if (base[i] == base[x])
	    return (0);
	  x = x + 1;
	}
      i = i + 1;
    }
  return (1);
}

int	check_ops(char *ops, char *base)
{
  int	i;
  int	x;

  if (my_strlen(ops) != 5)
    return (0);
  i = 0;
  while (ops[i] != '\0')
    {
      x = i + 1;
      while (ops[x] != '\0')
	{
	  if (ops[i] == ops[x])
	    return (0);
	  x = x + 1;
	}
      i = i + 1;
    }
  i = 0;
  while (ops[i] != '\0')
    {
      x = 0;
      while (base[x] != '\0')
	{
	  if (ops[i] == base[x])
	    {
	      return (0);
	    }
	  x = x + 1;
	}
      i = i + 1;
    }
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
  if (err == E_ERR_SYNTAX)
    my_putstr("syntax error");
  else if (err != E_NO_ERR)
  {
    my_putstr("Error: ");
    my_put_nbr(err);
  }
  return (err);
}

