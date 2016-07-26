##
## Makefile for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
##
## Made by DELAPLACE Antoine
## Login   <delapl_b@etna-alternance.net>
##
## Started on  Thu Oct 29 20:42:18 2015 DELAPLACE Antoine
## Last update Sat Oct 31 15:51:31 2015 DELAPLACE Antoine
##

CC	= gcc
NAME	= chifumi
SRC	= check_arguments.c	\
	  print_start.c		\
	  ./lib/my_putstr.c	\
	  ./lib/my_put_nbr.c	\
	  ./lib/my_putchar.c	\
	  ./lib/my_is_odd.c	\
	  ./lib/my_getnbr.c	\
	  ./lib/my_strcmp.c	\
	  play_manche.c		\
	  play_game.c		\
	  read_line.c		\
	  fill_tab.c		\
	  fill_rules.c		\
	  init_manches.c	\
	  add_manche.c		\
	  check_victory.c	\
	  print_manche.c	\
	  check_replay.c	\
	  print_histo.c		\
	  check_version.c	\
	  check_nb_parties.c	\
	  main.c
OBJ	= $(SRC:%.c=%.o)
CFLAGS  = -W -Wall -Werror
RM	= rm -f

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)
all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
