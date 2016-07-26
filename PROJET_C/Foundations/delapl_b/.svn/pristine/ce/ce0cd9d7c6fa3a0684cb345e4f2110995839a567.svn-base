/*
** lib.h for foundations in /Users/antoine/Documents/ETNA/C/C/Foundations/delapl_b/header
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Wed Apr 27 15:13:42 2016 DELAPLACE Antoine
** Last update Wed Apr 27 17:14:10 2016 DELAPLACE Antoine
*/

#ifndef LIB_H_
# define LIB_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

void                    my_putstr(char *str);
int			my_strcmp(char *s1, char *s2);
int			my_getnbr(char *str);
int			my_strlen(char *str);
void			print_errors();
void			print_usage();
int			connect_socket(char *addr, int port);
int			check_args(int nbr_args, char **args);
char			*readLine();
int			play_cmd(int sock);

#endif /* !LIB_H_ */
