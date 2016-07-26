##
## Makefile for ok$ in /home/antoine/Libmy/delapl_b/libmy_01
## 
## Made by DELAPLACE Antoine
## Login   <delapl_b@etna-alternance.net>
## 
## Started on  Fri Oct 23 18:47:05 2015 DELAPLACE Antoine
## Last update Mon Oct 26 10:05:18 2015 DELAPLACE Antoine
##

CC	= gcc
NAME	= aff_up
SRC	= my_putchar.c	  \
	  my_putstr.c	  \
	  my_strupcase.c  \
	  my_aff_params.c \
	  main.c
OBJ	= $(SRC:%.c=%.o)
CFLAGS	= -W -Wall -Werror

$(NAME):	$(OBJ)
		$(CC) $() $(OBJ) -o $(NAME)
all:		$(NAME)

clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
re:		fclean all
