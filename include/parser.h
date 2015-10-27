/*
** parser.h for Bistromathique in /home/denuit_m
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Wed Oct 21 12:00:14 2015 denuit mathieu
** Last update Tue Oct 27 13:52:23 2015 denuit mathieu
*/

#ifndef PARSER_H_
#define PARSER_H_

#define TOK_L_PAREN 0
#define TOK_R_PAREN 1
#define TOK_ADD 2
#define TOK_SUB 3
#define TOK_MUL 4
#define TOK_DIV 5
#define TOK_MOD 6
#define TOK_NUMBER 7

#define PARSER_BUFFER_SIZE (4096)

typedef struct	s_tokens
{
  int type;
  int nb_id;
  struct s_tokens *next;
}		t_tokens;

typedef struct	s_parser_state
{
  int current_nb_id;
  unsigned long size_left;
  t_tokens *last_node;
  char *base;
  char *operators;
}		t_parser_state;

#endif /* !PARSER_H_ */
