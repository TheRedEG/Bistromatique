/*
** my_itoa_base.c for Libmy in 
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct  5 10:09:26 2015 denuit mathieu
** Last update Thu Oct  8 11:36:16 2015 denuit mathieu
*/

#include <stdlib.h>

static char	next_digit_rev(int *nbr, char *base)
{
  int	len;
  char	digit;

  len = my_strlen(base);
  digit = base[*nbr % len];
  *nbr /= len;
  return (digit);
}

static void	write_rev_digits(char *buf, char *digits, char *base, int pad)
{
  int	i;
  int	j;

  pad -= my_strlen(digits);
  i = 0;
  j = 0;
  while (i < pad)
  {
    buf[j] = base[0];
    i += 1;
    j += 1;
  }
  i = my_strlen(digits) - 1;
  while (i >= 0)
  {
    buf[j] = digits[i];
    i -= 1;
    j += 1;
  }
  buf[j] = 0;
}

static int	write_positive_nbr(char *buf, int nbr, char *base, int pad)
{
  char	digits[256];
  int	i;

  i = 0;
  while (nbr > 0)
  {
    digits[i] = next_digit_rev(&nbr, base);
    i += 1;
  }
  digits[i] = 0;
  write_rev_digits(buf, digits, base, pad);
}

static char	*m_strdup(char *buf)
{
  char	*new_buf;
  int	i;
  int	len;

  len = my_strlen(buf);
  new_buf = (char*) malloc(sizeof(char) * (len + 1));
  if (!new_buf)
    return (NULL);
  i = 0;
  while (i < len)
  {
    new_buf[i] = buf[i];
    i += 1;
  }
  new_buf[i] = 0;
  return (new_buf);
}

char	*my_itoa_base(int nbr, char *base, int pad)
{
  int	i;
  char	buf[256];

  buf[0] = 0;
  if (!base || my_strlen(base) <= 1)
    return (m_strdup(buf));
  if (nbr == 0)
  {
    i = 0;
    while (i < pad)
    {
      buf[i] = base[0];
      i += 1;
    }
    buf[i] = 0;
    return (m_strdup(buf));
  }
  if (nbr < 0)
  {
    buf[0] = '-';
    nbr = -nbr;
    write_positive_nbr(buf + 1, nbr, base, pad);
  }
  else
  {
    write_positive_nbr(buf, nbr, base, pad);
  }
  return m_strdup(buf);
}
