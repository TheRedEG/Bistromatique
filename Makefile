##
## Makefile for do-op in /home/denuit_m
## 
## Made by denuit mathieu
## Login   <denuit_m@epitech.net>
## 
## Started on  Fri Oct  9 09:26:08 2015 denuit mathieu
## Last update Mon Oct 26 16:44:41 2015 denuit mathieu
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall
CFLAGS	+= -Iinclude -g

LDFLAGS	= -Llib -lmy

NAME	= calc

SRCS	= main.c \
	  parser.c \
	  str_to_ulong.c

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
