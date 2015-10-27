/*
** main.c for Bistromathique in /home/denuit_m/rendu/bistromatique
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 19 16:08:35 2015 denuit mathieu
** Last update Mon Oct 26 16:48:00 2015 denuit mathieu
*/

#include "bistro.h"
#include "my.h"
#include "str_to_ulong.h"

int	check_base(char *base)
{

}

int	check_ops(char *ops)
{

}

char	*get_expr(unsigned int size)
{
  char	buff[READ_BUFFER_SIZE + 1];
  int	len;

  while ((len = read(0, buff, READ_BUFFER_SIZE)) > 0)
  {
    buff[len] = 0;    
  }
}

void	show_usage(char *argv0)
{
  my_putstr("Usage: ");
  my_putstr(argv0);
  my_putstr(" base ops\"()+-*/%\" exp_len\n");
}

int		main(int argc, char **argv)
{
  unsigned long	size;

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
  if (!check_ops(argv[2]))
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
  return (eval_expr(argv[1], argv[2], size));
}

