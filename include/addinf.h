/*
** addinf.h for addinf.h in /home/girole_t/Projects/bistromatique
** 
** Made by Thomas Girolet
** Login   <girole_t@epitech.net>
** 
** Started on  Thu Oct 29 15:53:42 2015 Thomas Girolet
** Last update Thu Oct 29 16:20:29 2015 Thomas Girolet
*/

#ifndef ADDINF_H
# define ADDINF_H

int	decimal_at(char *s, int index, int len);
char	do_addinf_carry(t_infnb *result, int *s1c, int *s2c, int *carry);
int	infnb_add_p(t_infnb *result, t_infnb *left, t_infnb *right);

#endif
