##
## Makefile for ok$ in /home/antoine/Libmy/delapl_b/libmy_01
## 
## Made by DELAPLACE Antoine
## Login   <delapl_b@etna-alternance.net>
## 
## Started on  Fri Oct 23 18:47:05 2015 DELAPLACE Antoine
## Last update Tue Oct 27 17:39:42 2015 DELAPLACE Antoine
##

CC	= gcc
NAME	= do-op
SRC	= ../lib_src/my_putchar.c				\
	  ../lib_src/my_isneg.c					\
	  ../lib_src/my_put_nbr.c				\
	  ../lib_src/my_swap.c					\
	  ../lib_src/my_putstr.c				\
	  ../lib_src/my_strlen.c				\
	  ../lib_src/my_getnbr.c				\
	  ../lib_src/my_strcpy.c				\
	  ../lib_src/my_strncpy.c				\
	  ../lib_src/my_strcmp.c				\
	  ../lib_src/my_strncmp.c				\
	  ../lib_src/my_strcat.c				\
	  ../lib_src/my_strncat.c				\
	  ../lib_src/my_strstr.c				\
	  ../lib_src/my_strdup.c				\
	  ../lib_src/my_str_to_wordtab.c			\
	  operation.c						\
	  main.c
OBJ	= $(SRC:%.c=%.o)
CFLAGS = -W -Wall -Werror
LFLAGS = -lmy

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)
all:		$(NAME)

clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
re:		fclean all
