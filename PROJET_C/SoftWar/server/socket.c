/*
** create_socket.c for softwar in /home/tonio/SoftWar/houvet_b/src
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Wed Jul  6 13:11:14 2016 DELAPLACE Antoine
** Last update Wed Aug 24 11:09:17 2016 DELAPLACE Antoine
*/

#include "../header/lib.h"
#include "../header/functions.h"

struct sockaddr_in	init_structure(struct sockaddr_in server_address);

int			create_socket(t_game *game)
{
  struct protoent       *protocole;
  int			sock;
  struct sockaddr_in	server_address;
  socklen_t		socket_length;
  struct sockaddr_in    client_address;

  server_address = init_structure(server_address);
  socket_length = sizeof(client_address);
  if ((protocole = getprotobyname("TCP")) == NULL)
    {
      perror("getprotobyname(TCP) failed");
      return (-1);
    }
  if ((sock = socket(AF_INET, SOCK_STREAM, protocole->p_proto)) == -1 ||
      bind(sock, (struct sockaddr *)&server_address,
	   sizeof(server_address)) == -1)
    {
      perror("socket failed");
      return (-1);
    }
  if (wait_connection(game, sock, socket_length, client_address) == -1)
    return (-1);
  return (1);
}

int			wait_connection(t_game *game, int sock,
					socklen_t socket_length, struct sockaddr_in client_address)
{
  int			i;

  if (listen(sock, 5) == -1)
    {
      perror("listen() failed");
      return (-1);
    }
  for (i = 0; i < 4; i++)
    {
      if ((game->players[i].socket =
	   accept(sock, (struct sockaddr *)&client_address, &socket_length)) == -1)
	{
	  perror("client connection failed");
	  return (-1);
	}
      if (init_player(game, i) == -1)
	{
	  perror("malloc for digit fail");
	  return (-1);
	}
    }
  for (i = 0; i < 4; i++)
    write(game->players[i].socket, "go\n", my_strlen("go\n"));
  return (1);
}

struct sockaddr_in	init_structure(struct sockaddr_in server_address)
{
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(4242);

  return (server_address);
}

void			close_socket(t_game game)
{
  int			i;

  for (i = 0; i < 4; i++)
    {
      close(game.players[i].socket);
    }
}
