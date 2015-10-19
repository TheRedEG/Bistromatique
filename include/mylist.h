/*
** mylist.h for Piscine_C_J11 in /home/denuit_m/rendu/Piscine_C_J11/include
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 12 11:06:25 2015 denuit mathieu
** Last update Mon Oct 12 11:07:50 2015 denuit mathieu
*/

#ifndef MYLIST_H_
#define MYLIST_H_

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

#endif
