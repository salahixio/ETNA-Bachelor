/*
** connect_socket.c for foundations in /Users/antoine/Documents/ETNA/C/C/Foundations/delapl_b
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Wed Apr 27 12:26:02 2016 DELAPLACE Antoine
** Last update Wed Apr 27 18:05:25 2016 DELAPLACE Antoine
*/

#include "../header/lib.h"

int			connect_socket(char *addr, int port)
{
  int			sock;
  struct sockaddr_in	sockaddr;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) != -1) {
    sockaddr.sin_addr.s_addr = inet_addr(addr);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1) {
      sock = -1;
      my_putstr("Impossible de se connecter au socket\n");
    }
  }
  else {
    my_putstr("Impossible de créer le socket\n");
  }
  return (sock);
}
