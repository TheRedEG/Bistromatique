/*
** infnb_mul2.c for infnb_mul2 in /home/gauthe_n/rendu/bistromatique
** 
** Made by Nicolas Gautherin
** Login   <gauthe_n@epitech.net>
** 
** Started on  Sun Nov  1 23:06:09 2015 Nicolas Gautherin
** Last update Sun Nov  1 23:06:44 2015 Nicolas Gautherin
*/

#include "infnb.h"
#include "bistro.h"

void    infnb_mul_free_tmp(t_infnb *s1, t_infnb *s2)
{
  infnb_free(s1);
  infnb_free(s2);
}

int     infnb_mulcreate_tmp(t_infnb *tmp, t_infnb *tmp2,
			    t_infnb *left, t_infnb *right)
{
  if (infnb_new(tmp, (left->len - left->offset) +
                (right->len - right->offset)) == E_ERR_MALLOC)
    return (E_ERR_MALLOC);
  if (infnb_new(tmp2, (tmp->len)) == E_ERR_MALLOC)
    return (E_ERR_MALLOC);
}
