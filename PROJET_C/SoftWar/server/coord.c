/*
** coord.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Aug 31 21:10:28 2016 HOUVET Benoît - Xavier
** Last update Thu Sep  1 02:43:17 2016 HOUVET Benoît - Xavier
*/

#include "../header/lib.h"
#include "../header/functions.h"

void	north(t_game *game, int player, int *tab)
{
  int	x;
  int	y;

  x = game->players[player].x;
  y = game->players[player].y;
  tab[0] = x;
  tab[1] = y - 1;
  tab[2] = x - 1;
  tab[3] = y - 2;
  tab[4] = x;
  tab[5] = y - 2;
  tab[6] = x + 1;
  tab[7] = y - 2;
}

void	west(t_game *game, int player, int *tab)
{
  int	x;
  int	y;

  x = game->players[player].x;
  y = game->players[player].y;
  tab[0] = x - 1;
  tab[1] = y;
  tab[2] = x - 2;
  tab[3] = y - 1;
  tab[4] = x - 2;
  tab[5] = y;
  tab[6] = x - 2;
  tab[7] = y + 1;
}

void    south(t_game *game, int player, int *tab)
{
  int   x;
  int   y;

  x = game->players[player].x;
  y = game->players[player].y;
  tab[0] = x;
  tab[1] = y + 1;
  tab[2] = x + 1;
  tab[3] = y + 2;
  tab[4] = x;
  tab[5] = y + 2;
  tab[6] = x - 1;
  tab[7] = y + 2;
}

void    east(t_game *game, int player, int *tab)
{
  int   x;
  int   y;

  x = game->players[player].x;
  y = game->players[player].y;
  tab[0] = x + 1;
  tab[1] = y;
  tab[2] = x + 2;
  tab[3] = y - 1;
  tab[4] = x + 2;
  tab[5] = y;
  tab[6] = x + 2;
  tab[7] = y + 1;
}
