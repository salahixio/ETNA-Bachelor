/*
** main.c for fondation in /home/romain/Fondation
** 
** Made by LEJMAN Romain
** Login   <lejman_r@etna-alternance.net>
** 
** Started on  Wed Apr 27 16:55:51 2016 LEJMAN Romain
** Last update Thu Sep  1 14:52:12 2016 LEJMAN Romain
*/

#include "../header/client.h"

int			init_co(){
  int			fe;
  struct sockaddr_in    test;

  fe = socket(AF_INET, SOCK_STREAM, 0);
  if (fe != -1){
    test.sin_addr.s_addr = inet_addr("127.0.0.1");
    test.sin_family = AF_INET;
    test.sin_port = htons(4242);
    if (connect(fe, (struct sockaddr *) &test, sizeof(test)) == -1){
      return (-1);
    }
    return (fe);
  }
  return (-1);
}

char			*init_go(int fd){
  int			n;
  char			*buffer_go;

  buffer_go = malloc(sizeof(*buffer_go) * (260 + 1));
  if ((n = recv(fd, buffer_go, sizeof buffer_go - 1, 0)) < 0)
    {
      my_putstr("recv()");
      return 0;
    }
  buffer_go[n] = '\0';
  return (buffer_go);
}

int			main(){
  int			fd;
  int			client_rand;

  client_rand = 0;
  if ((fd = init_co()) == -1){
    my_putstr("Probleme de connexion au serveur\n");
    return (-1);
  }
  srand(time(NULL));
  client_rand = rand() % 30;
  while (my_strcmp(init_go(fd), "go\n") != 0){
    my_putstr("En attente de joueur\n");
  }
  my_putstr("On peux commencer\n");
  ia(fd, client_rand);
  close(fd);
  my_putstr("La partie est finis pour vous.\n");
  return (0);
}
