/*
** move.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Aug 23 11:34:37 2016 DELAPLACE Antoine
** Last update Thu Sep  1 15:17:56 2016 HOUVET Benoît - Xavier
*/

#include "../header/lib.h"
#include "../header/functions.h"

void	forward(t_game *game, int player)
{
  char	direction;
  int	x;
  int	y;
  int	flag;

  flag = 1;
  direction = game->players[player].orientation;
  x = game->players[player].x;
  y = game->players[player].y;
  if (direction == 'N' && y > 0)
    y -= 1;
  else if (direction == 'E' && x < (game->size - 1))
    x += 1;
  else if (direction == 'S' && y < (game->size - 1))
    y += 1;
  else if (direction == 'W' && x > 0)
    x -= 1;
  else
    {
      write(game->players[player].socket, "ko\n", my_strlen("ko\n"));
      flag = 0;
    }
  if (flag == 1 && colision(game, player, x, y, 1) == 0)
    coord_action(game, player, x, y, 1);
}

void	backward(t_game *game, int player)
{
  char  direction;
  int   x;
  int   y;
  int   flag;

  flag = 1;
  direction = game->players[player].orientation;
  x = game->players[player].x;
  y = game->players[player].y;
  if (direction == 'S' && y > 0)
    y -= 1;
  else if (direction == 'W' && x < (game->size - 1))
    x += 1;
  else if (direction == 'N' && y < (game->size - 1))
    y += 1;
  else if (direction == 'E' && x > 0)
    x -= 1;
  else
    {
      write(game->players[player].socket, "ko\n", my_strlen("ko\n"));
      flag = 0;
    }
  if (flag == 1 && colision(game, player, x, y, 2) == 0)
    coord_action(game, player, x, y, 2);
}

void	leftfwd(t_game *game, int player)
{
  int	action;

  action = game->players[player].action;
  left(game, player);
  forward(game, player);
  if (game->players[player].action != action - 2)
    {
      right(game, player);
      game->players[player].action = action;
    }
}

void	rightfwd(t_game *game, int player)
{
  int	action;

  action = game->players[player].action;
  right(game, player);
  forward(game, player);
  if (game->players[player].action != action - 2)
    {
      left(game, player);
      game->players[player].action = action;
    }
}
