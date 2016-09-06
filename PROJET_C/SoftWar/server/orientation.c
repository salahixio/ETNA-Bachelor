/*
** orientation.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Aug 23 11:33:41 2016 DELAPLACE Antoine
** Last update Wed Aug 24 05:03:15 2016 DELAPLACE Antoine
*/

#include "../header/lib.h"
#include "../header/functions.h"

void	right(t_game *game, int player)
{
  if (game->players[player].orientation == 'N')
    game->players[player].orientation = 'E';
  else if (game->players[player].orientation == 'E')
    game->players[player].orientation = 'S';
  else if (game->players[player].orientation == 'S')
    game->players[player].orientation = 'W';
  else
    game->players[player].orientation = 'N';
  game->players[player].action = (game->players[player].action - 1);
  write_ok(game->players[player].socket);
}

void    left(t_game *game, int player)
{
  if (game->players[player].orientation == 'N')
    game->players[player].orientation = 'W';
  else if (game->players[player].orientation == 'E')
    game->players[player].orientation = 'N';
  else if (game->players[player].orientation == 'S')
    game->players[player].orientation = 'E';
  else
    game->players[player].orientation = 'S';
  game->players[player].action = (game->players[player].action - 1);
  write_ok(game->players[player].socket);
}

void	orientation(t_game *game, int player_number)
{
  char	orientation[2];

  orientation[0] = game->players[player_number].orientation;
  orientation[1] = '\0';
  write(game->players[player_number].socket, orientation, sizeof(char));
}
