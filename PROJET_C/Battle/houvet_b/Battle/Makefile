##
## Makefile for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
##
## Made by HOUVET Benoît - Xavier
## Login   <houvet_b@etna-alternance.net>
##
## Started on  Mon Dec 14 18:25:04 2015 HOUVET Benoît - Xavier
## Last update Wed Dec 16 19:46:41 2015 HOUVET Benoît - Xavier
##

CC	= gcc
NAME	= sta
SRC	= check_args.c			\
	  check_actions.c		\
	  readline.c			\
	  print/print_game.c		\
	  getCreature.c			\
	  print/print_creature.c	\
	  play_game.c			\
	  capture_creature.c		\
	  display_team.c		\
	  print/print_capture.c		\
	  print/print_attack.c		\
	  check_choices.c		\
	  out_of_battle.c		\
	  select_fighter.c		\
	  in_battle/in_battle.c		\
	  in_battle/check_battle.c	\
	  in_battle/attack.c		\
	  in_battle/magic_catch.c	\
	  in_battle/check_attack.c	\
	  in_battle/ia.c		\
	  free_items.c			\
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

rm:		makelib $(NAME)
		$(RM) $(OBJ)
