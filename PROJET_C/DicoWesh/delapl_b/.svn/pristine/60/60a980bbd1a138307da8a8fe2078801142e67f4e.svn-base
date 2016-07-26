##
## Makefile for dico in /home/antoine/ALGO/DicoWesh/delapl_b/DicoWESH
##
## Made by DELAPLACE Antoine
## Login   <delapl_b@etna-alternance.net>
##
## Started on  Thu Nov  5 10:01:25 2015 DELAPLACE Antoine
## Last update Sat Nov  7 13:17:00 2015 DELAPLACE Antoine
##

CC	= gcc
NAME	= DicoWesh
SRC	= main.c			\
	  print.c			\
	  check_saisie.c		\
	  lib/my_putstr.c		\
	  lib/my_strcmp.c		\
	  lib/my_putchar.c		\
	  lib/readLine.c		\
	  my_free.c			\
	  tri_dico.c			\
	  fill_dico.c			\
	  load_dico.c			\
	  aff_dico.c			\
	  play_sound_for_word.c
OBJ	= $(SRC:%.c=%.o)
RM	= rm -rf
CFLAGS  = -W -Wall -Werror
LDFLAGS = -lSDL -lSDL_mixer
$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
