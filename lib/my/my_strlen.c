/*
** my_strlen.c for Piscine_C_J04 in /home/denuit_m/rendu/pc4
** 
** Made by mathieu denuit
** Login   <denuit_m@epitech.net>
** 
** Started on  Thu Oct  1 09:58:33 2015 mathieu denuit
** Last update Fri Oct 30 00:36:16 2015 denuit mathieu
*/

int	my_strlen(const char *str)
{
  int	len;

  if (str == 0)
    return (0);
  len = 0;
  while (str[len] != 0)
    {
      len = len + 1;
    }
  return (len);
}
