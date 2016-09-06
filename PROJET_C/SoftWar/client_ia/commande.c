/*
** commande.c for clien in /home/romain/softwar/houvet_b/client_ia
** 
** Made by LEJMAN Romain
** Login   <lejman_r@etna-alternance.net>
** 
** Started on  Thu Sep  1 13:51:44 2016 LEJMAN Romain
** Last update Thu Sep  1 14:52:35 2016 LEJMAN Romain
*/

#include "../header/client.h"

char                    *choix_commande(char **cmd, int nbcmd, int clt_rd){
  int nb_rand;

  nb_rand = 0;
  srand(time(NULL));
  nb_rand = rand() * clt_rd;
  if (nb_rand < 0)
    nb_rand = nb_rand * -1;
  nb_rand = nb_rand % nbcmd;
  return (cmd[nb_rand]);
}

char                    *exec_commande(char *commande, int fd){
  int                   n;
  char                  *buff;

  if ((buff = malloc(sizeof(char)*100)) == NULL)
    return NULL;
  write(fd, commande, my_strlen(commande));
  n = recv(fd, buff, (sizeof(buff))-1, 0);
  buff[n] = '\0';
  if (my_strcmp(buff, "die") == 0)
    return NULL;
  return (buff);
}

int                     supp_commande(char **cmd, char *supp, int nb_cmd){
  int                   i;
  int                   j;
  int                   fin;

  fin = 1;
  for (i = 0; (i < nb_cmd) && fin; i++){
    if (my_strcmp(cmd[i], supp) == 0){
      if (i == nb_cmd - 1)
	cmd[i] = '\0';
      else{
	for (j = i; j < nb_cmd - 1; j++){
	  cmd[j] = cmd[j + 1];
	}
	cmd[j] = '\0';
      }
      nb_cmd--;
      fin = 0;
    }
  }
  return (nb_cmd);
}

int                     tri_commande(char **commande, int fd){
  int                   energy;
  int                   nb_commande;
  char                  *reponse;

  nb_commande = 10;
  if ((reponse = exec_commande("selfstatus\n", fd)) == NULL)
    return (-1);
  energy = my_getnbr(reponse);
  if (energy <= 20){
    nb_commande = supp_commande(commande, "jump\n", nb_commande);
    nb_commande = supp_commande(commande, "attack\n", nb_commande);
  }
  nb_commande = supp_commande(commande, "inspect", nb_commande);
  free(reponse);
  return (nb_commande);
}

void                    init_commande(char **commande){
  commande[0] = "forward\n";
  commande[1] = "backward\n";
  commande[2] = "leftfwd\n";
  commande[3] = "rightfwd\n";
  commande[4] = "right\n";
  commande[5] = "left\n";
  commande[6] = "gather\n";
  commande[7] = "attack\n";
  commande[8] = "inspect\n";
  commande[9] = "jump\n";
}
