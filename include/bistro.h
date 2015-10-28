/*
** bistro.h for Bistromathique in /home/denuit_m/rendu/bistromatique
** 
** Made by denuit mathieu
** Login   <denuit_m@epitech.net>
** 
** Started on  Mon Oct 19 16:04:11 2015 denuit mathieu
** Last update Wed Oct 28 01:13:27 2015 denuit mathieu
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

char	*eval_expr(char *base, char *ops, unsigned long size);
