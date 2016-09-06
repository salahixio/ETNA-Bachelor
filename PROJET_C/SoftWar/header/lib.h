/*
** lib.h for softwar in /home/tonio/SoftWar/houvet_b/header
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Wed Jul  6 13:49:49 2016 DELAPLACE Antoine
** Last update Tue Aug 23 12:15:11 2016 DELAPLACE Antoine
*/

#ifndef LIB_H_
# define LIB_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

int		my_strlen(char *str);
void		my_putstr(char *str);
void		my_put_nbr(int i);
void		my_putchar(char c);
char		*my_strdup(char *str);
int		my_strcmp(char *s1, char *s2);

#endif /* !LIB_H_ */
