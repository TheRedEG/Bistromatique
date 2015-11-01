/*
** main.c for Bistromathique in /home/denuit_m/rendu/bistromatique
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 19 16:08:35 2015 denuit mathieu
** Last update Sun Nov  1 09:52:11 2015 denuit mathieu
*/

#include "bistro.h"
#include "my.h"
#include "str_to_ulong.h"

int	check_base(char *base)
{
  int	i;
  int	x;
  int	len;
  
  len = my_strlen(base);
  if (len < 2 || len > 250)
    return (0);
  i = 0;
  while (i < len)
    {
      x = 0;
      while (x < len)
	{
	  if (x != i && base[x] == base[i])
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
  int	len;

  len = my_strlen(ops);
  if (len != 7)
    return (0);
  i = 0;
  while (i < len)
    {
      x = 0;
      while (x < len)
	{
	  if (x != i && ops[x] == ops[i])
	    return (0);
	  x = x + 1;
	}
      i = i + 1;
    }
  i = 0;
  while (i < len)
    {
      x = 0;
      while (base[x] != '\0')
	{
	  if (ops[i] == base[x])
	      return (0);
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

