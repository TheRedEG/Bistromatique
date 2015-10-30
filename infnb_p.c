/*
** infnb_p.c for Bistromathique in /home/denuit_m/rendu
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Thu Oct 29 23:50:06 2015 denuit mathieu
** Last update Fri Oct 30 15:24:18 2015 denuit mathieu
*/

#include "eval.h"
#include "infnb.h"
#include "my.h"
#include "bistro.h"

#include <stdio.h>
#include <string.h>

/*int	infnb_add_p(t_eval_data *d, t_infnb *res, t_infnb *l, t_infnb *r)
{
  char	buf_r[256];
  char	buf_l[256];
  strncpy(buf_l, l->data, l->len);
  buf_l[l->len] = 0;
  strncpy(buf_r, r->data, r->len);
  buf_r[r->len] = 0;
  printf("Computing %s + %s\n", buf_l, buf_r);
  res->data = "0";
  res->len = 1;
  res->offset = 0;
  res->allocated = 0;
  return (E_NO_ERR);
}*/

/*int	infnb_sub_p(t_eval_data *d, t_infnb *res, t_infnb *l, t_infnb *r)
{
  char	buf_r[256];
  char	buf_l[256];
  strncpy(buf_l, l->data, l->len);
  buf_l[l->len] = 0;
  strncpy(buf_r, r->data, r->len);
  buf_r[r->len] = 0;
  printf("Computing %s - %s\n", buf_l, buf_r);
  res->data = "0";
  res->len = 1;
  res->offset = 0;
  res->allocated = 0;
  return (E_NO_ERR);
}*/

int	infnb_mul_p(t_eval_data *d, t_infnb *res, t_infnb *l, t_infnb *r)
{
  char	buf_r[256];
  char	buf_l[256];
  strncpy(buf_l, l->data, l->len);
  buf_l[l->len] = 0;
  strncpy(buf_r, r->data, r->len);
  buf_r[r->len] = 0;
  printf("Computing %s * %s\n", buf_l, buf_r);
  res->data = "0";
  res->len = 1;
  res->offset = 0;
  res->allocated = 0;
  return (E_NO_ERR);
}

int	infnb_div_p(t_eval_data *d, t_infnb *res, t_infnb *l, t_infnb *r)
{
  char	buf_r[256];
  char	buf_l[256];
  strncpy(buf_l, l->data, l->len);
  buf_l[l->len] = 0;
  strncpy(buf_r, r->data, r->len);
  buf_r[r->len] = 0;
  printf("Computing %s / %s\n", buf_l, buf_r);
  res->data = "0";
  res->len = 1;
  res->offset = 0;
  res->allocated = 0;
  return (E_NO_ERR);
}

int	infnb_mod_p(t_eval_data *d, t_infnb *res, t_infnb *l, t_infnb *r)
{
  char	buf_r[256];
  char	buf_l[256];
  strncpy(buf_l, l->data, l->len);
  buf_l[l->len] = 0;
  strncpy(buf_r, r->data, r->len);
  buf_r[r->len] = 0;
  printf("Computing %s mod %s\n", buf_l, buf_r);
  res->data = "0";
  res->len = 1;
  res->offset = 0;
  res->allocated = 0;
  return (E_NO_ERR);
}
