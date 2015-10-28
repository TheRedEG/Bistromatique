/*
** addinf.h for addinf.h in 
** 
** Made by Thomas Girolet
** Login   <girole_t@epitech.net>
** 
** Started on  Wed Oct 28 12:11:13 2015 Thomas Girolet
** Last update Wed Oct 28 12:11:25 2015 Thomas Girolet
*/

#ifndef	ADDINF_H_
#define	ADDINF_H_

#include <stdlib.h>

typedef struct	s_add_data
{
  int	len1;
  int	len2;
  int	isneg1;
  int	isneg2;
}		t_add_data;

typedef struct	s_add_op
{
  char	*s1;
  int	s1len;
  char	*s2;
  int	s2len;
  int	negate;
  int	nblen;
  int	add;
  char	*result;
}		t_add_op;

void	fill_add_data(char **s1, char **s2, t_add_data *d);
int	nb_greater(char *s1, char *s2);
void	make_add_op(char *s1, char *s2, t_add_data *d, t_add_op *op);
int	swap(char **s1, char **s2);
int	decimal_at(char *s, int index, int len);
char	do_addinf_carry(t_add_op *op, int *s1c, int *s2c, int *carry);
char	do_subinf_carry(t_add_op *op, int *s1c, int *s2c, int *carry);
int	do_addinf(t_add_op *op, int res_c, int add);
char	*addinf(char *s1, char *s2);

#endif
