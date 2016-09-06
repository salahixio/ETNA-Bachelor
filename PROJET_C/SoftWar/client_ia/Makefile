##
## Makefile for client in /home/romain/softwar/houvet_b/client_ia
## 
## Made by LEJMAN Romain
## Login   <lejman_r@etna-alternance.net>
## 
## Started on  Thu Sep  1 14:03:12 2016 LEJMAN Romain
## Last update Thu Sep  1 14:19:38 2016 LEJMAN Romain
##

CC	=	gcc
NAME 	= 	client
SRC 	= main.c \
	 ia.c \
	 commande.c
OBJ 	=	$(SRC:%.c=%.o)
CFLAGS 	= -W -Werror -Wall -Wextra
LDFLAGS	= -L ../lib -lmy
RM	= rm -f
MAKE	= make -C ../lib/

all:		makelib $(NAME)

makelib:
		$(MAKE)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(MAKE) fclean

re:		fclean all

rm:		makelib $(NAME)
		$(RM) $(OBJ)

.PHONY:		clean
