##
## Makefile for softwar in /home/tonio/SoftWar/houvet_b
##
## Made by DELAPLACE Antoine
## Login   <delapl_b@etna-alternance.net>
##
## Started on  Wed Jul  6 13:52:33 2016 DELAPLACE Antoine
## Last update Thu Sep  1 14:47:38 2016 LEJMAN Romain
##
CC      = gcc
NAME    = srvSoftWar
SRC     = server/socket.c  \
	  server/main.c \
	 server/map.c \
	 server/game.c \
	 server/thread.c \
	 server/player.c \
	 server/logs.c	\
	 server/analyse.c \
	 server/action.c \
	 server/move.c	\
	 server/orientation.c \
	 server/coord.c \
	 server/watch.c \
	 server/bouge.c
OBJ     = $(SRC:%.c=%.o)
CFLAGS  = -W -Wall -Wextra -Werror
LDFLAGS = -L lib -lmy -lpthread
RM      = rm -f
MAKE    = make -C lib/
MAKECLT	= make -C client_ia/

all:            makelib makeclient $(NAME)

makelib:
		$(MAKE)
makeclient:
		$(MAKECLT)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:         clean
		$(RM) $(NAME)
		$(MAKE) fclean
		$(MAKECLT) fclean

re:             fclean all

rm:             makelib makeclient $(NAME)
		$(RM) $(OBJ)

.PHONY:		clean
