/*
** parser.h for Bistromathique in /home/denuit_m
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Wed Oct 21 12:00:14 2015 denuit mathieu
** Last update Fri Oct 30 00:33:25 2015 denuit mathieu
*/

#ifndef TOKEN_H_
#define TOKEN_H_

#define TOK_L_PAREN 0
#define TOK_R_PAREN 1
#define TOK_ADD 2
#define TOK_SUB 3
#define TOK_MUL 4
#define TOK_DIV 5
#define TOK_MOD 6
#define TOK_NUMBER 7

typedef struct	s_token
{
  int type;
  int len;
  const char *data;
}		t_token;

typedef struct s_eval_data t_eval_data;

int	token_next(t_eval_data *data);

#endif /* !TOKEN_H_ */
