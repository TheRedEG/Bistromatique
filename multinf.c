/*
** multinf.c for mult in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Wed Oct 21 15:43:19 2015 Nicolas Gautherin
** Last update Tue Oct 27 15:11:30 2015 Nicolas Gautherin
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

char		*multinf(char *s1, char *s2, t_add_data *data, int index)
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

char		*pff(char *s1, char *s2)
{
  t_add_data	data;
  int		index;

  index = 0;
  fill_add_data(&s1, &s2, &data);
  return (multinf(s1, s2, &data, index));
}
