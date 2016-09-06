/*
** ia.c for ia in /home/romain/softwar/houvet_b/client
** 
** Made by LEJMAN Romain
** Login   <lejman_r@etna-alternance.net>
** 
** Started on  Wed Aug 31 17:24:33 2016 LEJMAN Romain
** Last update Thu Sep  1 15:18:41 2016 LEJMAN Romain
*/

#include "../header/client.h"

int			ia(int fd, int client_rand){
  char			**commande;
  int			nb_commande;
  char			*reponse;
  int			fin;

  fin = 1;
  if ((commande = malloc(sizeof(commande)*11)) == NULL){
    my_putstr("malloc()");
    return (-1);
  }
  while (1 && fin){
    init_commande(commande);
    if ((nb_commande = tri_commande(commande, fd)) == -1)
      fin = 0;
    reponse = choix_commande(commande, nb_commande, client_rand);
    if ((reponse = exec_commande(reponse, fd)) == NULL)
      fin = 0;
    free(reponse);
  }
  return (0);
}
