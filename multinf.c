
/*
** multinf.c for multinf in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Wed Oct 21 15:43:19 2015 Nicolas Gautherin
** Last update Wed Oct 28 12:16:08 2015 Nicolas Gautherin
*/

#include <stdlib.h>
#include "my.h"
#include "addinf.h"

void	newtmp(char *str, t_add_data *data, char *s1, int index)
{
  int	j;

  j = 0;
  while (j < data->len1)
    {
      str[j] = s1[j];
      j = j + 1;
    }
  while (j <data->len2 - index + data->len1 - 1)
    {
      str[j] = '0';
      j = j + 1;
    }
  str[j] = '\0';
}

char		*do_multinf(char *s1, char *s2, t_add_data *data, int index)
{
  char		*tmp;
  char		*result;

  if ((result = malloc(data->len1 + data->len2 + 2)) == NULL)
    return (NULL);
  if ((tmp = malloc(data->len1 + data->len2 + 2)) == NULL)
    return (NULL);
  result = result + 1;
  while (index < data->len2)
    {
      newtmp(tmp, data, s1, index); 
      while (s2[index] != '0')
	{
	  result = addinf(result, tmp);
	  s2[index] = s2[index] - 1;
	}
      index = index + 1;
    }
  if (data->isneg1 != data->isneg2)
    {
      result = result - 1;
      result[0] = '-';
     }
  return (result);
}

char		*multinf(char *s1, char *s2)
{
  t_add_data	data;
  int		index;
  char		*s2prime;

  if ((s2prime = malloc(my_strlen(s2))) == NULL)
    return (NULL);
  if ((s1[0] == 48) && (s1[1] == 0))
    return (s1);
  if ((s2[0] == 48) && (s2[1] == 0))
    return (s2);
  index = 0;
  while(s2[index])
    {
      s2prime[index] = s2[index];
      index = index + 1;
    }
  index = 0;
  fill_add_data(&s1, &s2prime, &data);
  if (data.len1 < data.len2)
    {
      fill_add_data(&s2prime, &s1, &data);
      return (do_multinf(s2prime, s1, &data, index));
    }
  return (do_multinf(s1, s2prime, &data, index));
}
