##
## Makefile for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
##
## Made by HOUVET Benoît - Xavier
## Login   <houvet_b@etna-alternance.net>
##
## Started on  Mon Dec 14 18:25:04 2015 HOUVET Benoît - Xavier
## Last update Tue Dec 15 10:25:50 2015 DELAPLACE Antoine
##

CC	= gcc
NAME	= sta
SRC	= check_args.c		\
	  check_actions.c	\
	  readline.c		\
	  print_game.c		\
	  getCreature.c		\
	  print_creature.c	\
	  play_game.c		\
	  capture_creature.c	\
	  print_capture.c	\
	  main.c
OBJ	= $(SRC:%.c=%.o)
CFLAGS  = -W -Wall -Wextra -Werror
LDFLAGS = -L lib -lmy
RM	= rm -f
MAKE	= make -C lib/

all:		makelib $(NAME)

makelib:
		$(MAKE)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
