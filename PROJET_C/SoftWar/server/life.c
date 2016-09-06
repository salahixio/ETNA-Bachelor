/*
** life.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Thu Sep  1 23:19:48 2016 HOUVET Benoît - Xavier
** Last update Thu Sep  1 23:20:42 2016 HOUVET Benoît - Xavier
*/

#include "../header/lib.h"
#include "../header/functions.h"

void	die(t_game *game, int player)
{
  if (game->nbralive > 1)
    {
      game->nbralive = game->nbralive - 1;
      game->players[player].y = -10;
      game->players[player].x = -10;
      game->players[player].energy = -10;
      write(game->players[player].socket, "die\n", my_strlen("die\n"));
      close(game->players[player].socket);
    }
  else
    {
      write(game->players[player].socket, "win\n", my_strlen("win\n"));
      close(game->players[player].socket);
    }
}

void	alive(t_game *game)
{
  int	i;

  if (game->nbralive <= 1)
    {
      for (i = 0; i < 4; i++)
	{
	  if (game->players[i].x >= 0)
	    die(game, i);
	}
    }
}
