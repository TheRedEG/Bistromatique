/*
** my_getnbr.c for Piscine_C_J04 in /home/denuit_m/rendu/pc4
** 
** Made by mathieu denuit
** Login   <denuit_m@epitech.net>
** 
** Started on  Thu Oct  1 11:49:09 2015 mathieu denuit
** Last update Mon Oct 26 16:43:10 2015 denuit mathieu
*/

#include "my.h"
#include "str_to_ulong.h"

int	m_nbrlen(char *str)
{
  int	len;

  len = 0;
  while (str[len] >= '0' && str[len] <= '9')
    len = len + 1;
  return (len);
}

int	nb_fit_ulong(char *str)
{
  if (m_nbrlen(str) == 0 || m_nbrlen(str) > 10)
    {
      return (0);
    }
  else if (m_nbrlen(str) == 10)
    {
      return (my_strncmp(str, "4294967295", 10) <= 0);
    }
  else
    {
      return (1);
    }
}

unsigned long	ulong_nb_make(char *str)
{
  unsigned long	value;
  unsigned long	pow_value;
  int		i;
  int		j;
  int		len;

  value = 0;
  i = 0;
  len = m_nbrlen(str);
  while (i < len)
    {
      pow_value = 1;
      j = 1;
      while (j < (len - i) && (pow_value = pow_value * 10))
	j = j + 1;
      value = value + (str[i] - '0') * pow_value;
      i = i + 1;
    }
  return (value);
}

unsigned long	str_to_ulong(char *str)
{
  int		i;

  if (str == 0)
    return (0);
  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i = i + 1;
    }
  return (nb_fit_ulong(str) ? ulong_nb_make(str) : 0);
}
