/*
** infnb.h for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 26 14:32:22 2015 denuit mathieu
** Last update Wed Oct 28 13:56:29 2015 Thomas Girolet
*/

#ifndef INFNB_H_
# define INFNB_H_

typedef struct	s_infnb
{
  int is_neg;
  int len;
  char *data;
  int allocated;
}		t_infnb;

int	char_index(char c, const char *str);
int	infnb_nbrlen(const char *str, const char *base);

#endif /* !INFNB_H_ */
