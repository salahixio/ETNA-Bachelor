/*
** bouge.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Thu Sep  1 10:55:48 2016 HOUVET Benoît - Xavier
** Last update Thu Sep  1 15:17:54 2016 HOUVET Benoît - Xavier
*/

#include "../header/lib.h"
#include "../header/functions.h"

void	coord_action(t_game *game, int player, int x, int y, int value)
{
  modify_coord(game, player, x, y);
  game->players[player].action = (game->players[player].action - value);
}

int	colision(t_game *game, int player, int x, int y, int value)
{
  int	i;
  int	energy;

  for (i = 0; i < 4; i++)
    {
      if (game->players[i].x == x && game->players[i].y == y)
	{
	  energy = game->players[i].energy;
	  game->players[i].energy = game->players[player].energy;
	  game->players[player].energy = energy;
	  game->players[player].action = game->players[player].action - value;
	  return (1);
	}
    }
  write_ok(game->players[player].socket);
  return (0);
}

void	modify_coord(t_game *game, int player, int x, int y)
{
  game->players[player].x = x;
  game->players[player].y = y;
}
