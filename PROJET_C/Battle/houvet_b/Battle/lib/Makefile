##
## Makefile for Makefile in /home/houvet_b/libmy
## 
## Made by HOUVET Benoît - Xavier
## Login   <houvet_b@etna-alternance.net>
## 
## Started on  Sat Oct 24 16:12:17 2015 HOUVET Benoît - Xavier
## Last update Wed Oct 28 14:45:03 2015 HOUVET Benoît - Xavier
##

CC	= gcc
NAME	= libmy.a
AR	= ar -r
RANLIB	= ranlib
SRC	= my_putchar.c  \
	 my_isneg.c    \
         my_put_nbr.c  \
         my_swap.c     \
         my_putstr.c   \
         my_strlen.c   \
         my_getnbr.c   \
         my_strcpy.c   \
         my_strncpy.c  \
         my_strcmp.c   \
         my_strncmp.c  \
         my_strcat.c   \
         my_strncat.c  \
         my_strstr.c   \
	 my_strdup.c   \
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