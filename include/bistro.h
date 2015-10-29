/*
** bistro.h for Bistromathique in /home/denuit_m/rendu/bistromatique
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 19 16:04:11 2015 denuit mathieu
** Last update Fri Oct 30 00:31:42 2015 denuit mathieu
*/

#include <stdlib.h>

#define OP_OPEN_PARENT 0
#define OP_CLOSE_PARENT 1
#define OP_ADD 2
#define OP_SUB 3
#define OP_MUL 4
#define OP_DIV 5
#define OP_MOD 6

#define SYNTAXE_ERROR_MSG "syntax error"
#define ERROR_MSG "Error"

#define E_NO_ERR 0
#define E_ERR_SYNTAX 1
#define E_ERR_MALLOC 2
#define E_ERR_DIV_BY_ZERO 2
#define E_ERR_MOD_BY_ZERO 3
#define E_ERR_READ 4
#define E_ERR_INVALID_CHAR 5

int	eval_expr(char *base, char *ops, int size);
int	read(int fd, char *buf, int len);
