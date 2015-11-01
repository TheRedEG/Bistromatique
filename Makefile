##
## Makefile for do-op in /home/denuit_m
## 
## Made by denuit mathieu
## Login   <denuit_m@epitech.net>
## 
## Started on  Fri Oct  9 09:26:08 2015 denuit mathieu
## Last update Sun Nov  1 23:42:00 2015 denuit mathieu
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -g
CFLAGS	+= -Iinclude

LDFLAGS	= -Llib -lmy

NAME	= calc

SRCS	= main.c \
	  token.c \
	  eval.c \
	  eval_rules.c \
	  str_to_ulong.c \
	  infnb.c \
	  infnb2.c \
	  infnb_ops.c \
	  infnb_utils.c \
	  infnb_action.c \
	  infnb_it.c \
	  infnb_add.c \
	  infnb_sub.c \
	  infnb_mul.c \
	  infnb_mul2.c \
	  infnb_div.c \
	  infnb_mod.c \
	  infnb_is_biggest.c

OBJS	= $(SRCS:.c=.o)

all: makemylib $(NAME)

makemylib:
	(cd lib/my && make)
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
