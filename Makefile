##
## Makefile for do-op in /home/denuit_m
## 
## Made by denuit mathieu
## Login   <denuit_m@epitech.net>
## 
## Started on  Fri Oct  9 09:26:08 2015 denuit mathieu
## Last update Fri Oct 30 15:57:25 2015 Nicolas Gautherin
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall
CFLAGS	+= -Iinclude -g

LDFLAGS	= -Llib -lmy

NAME	= calc

SRCS	= main.c \
	  token.c \
	  str_to_ulong.c \
	  infnb.c \
	  eval.c \
	  eval_rules.c \
	  infnb_ops.c \
	  infnb_it.c \
	  infnb_p.c \
	  infnb_add_p.c \
	  infnb_sub_p.c \
	  multinf.c \
	  eucldiv.c \
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
