##
## Makefile for ok$ in /home/antoine/Libmy/delapl_b/libmy_01
## 
## Made by DELAPLACE Antoine
## Login   <delapl_b@etna-alternance.net>
## 
## Started on  Fri Oct 23 18:47:05 2015 DELAPLACE Antoine
## Last update Mon Oct 26 18:17:49 2015 DELAPLACE Antoine
##

CC	= gcc
NAME	= libmy.a
AR	= ar -r
RANLIB	= ranlib
SRC	= my_putchar.c		\
	  my_isneg.c		\
	  my_put_nbr.c		\
	  my_swap.c		\
	  my_putstr.c		\
	  my_strlen.c		\
	  my_getnbr.c		\
	  my_strcpy.c		\
	  my_strncpy.c		\
	  my_strcmp.c		\
	  my_strncmp.c		\
	  my_strcat.c		\
	  my_strncat.c		\
	  my_strstr.c		\
	  my_strdup.c		\
	  my_str_to_wordtab.c
OBJ	= $(SRC:%.c=%.o)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		$(RANLIB) $(NAME) 
all:		$(NAME)

clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
re:		fclean all
