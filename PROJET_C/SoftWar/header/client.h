/*
** header.h for client in /home/romain/softwar/houvet_b/client_ia
** 
** Made by LEJMAN Romain
** Login   <lejman_r@etna-alternance.net>
** 
** Started on  Thu Sep  1 13:41:18 2016 LEJMAN Romain
** Last update Thu Sep  1 14:01:28 2016 LEJMAN Romain
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

char                    *readline();
int                     my_strcmp(char *str1, char *str2);
int                     my_strlen(char *str);
void                    *my_putstr(char *str);
int                     my_getnbr(char *str);
void                    my_put_nbr(int n);
char			*choix_commande(char **cmd, int nbcmd, int clt_rd);
char                    *exec_commande(char *commande, int fd);
int                     supp_commande(char **cmd, char *supp, int nb_cmd);
int                     tri_commande(char **commande, int fd);
void                    init_commande(char **commande);
int			ia(int fd, int rand);
