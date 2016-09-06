/*
** watch.c for softwar in /home/tonio/SoftWar/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Thu Sep  1 02:35:36 2016 HOUVET Benoît - Xavier
** Last update Wed Aug 24 11:27:51 2016 DELAPLACE Antoine
*/

#include "../header/lib.h"
#include "../header/functions.h"

void	traduct(t_game *game, int player, int *tab)
{
  int	i;
  int	j;
  int	flag;

  write(game->players[player].socket, "[\"", my_strlen("[\""));
  for (i = 0; i < 7; i += 2)
    {
      flag = 1;
      for (j = 0; j < 4; j++)
	{
	  if (game->players[j].x == tab[i] && game->players[j].y == tab[i + 1])
	    flag = do_write(game, player);
	}
      if (flag == 1 && out_map(tab[i], tab[i + 1], game->size))
	flag = 0;
      else if (flag == 1 && game->map[tab[i]][tab[i + 1]] > 0)
	write(game->players[player].socket, "energy", my_strlen("energy"));
      else if (flag == 1)
	write(game->players[player].socket, "empty", my_strlen("empty"));
      if (i < 5)
	write(game->players[player].socket, "\", \"", my_strlen("\", \""));
    }
  write(game->players[player].socket, "\"]\n", my_strlen("\"]\n"));
}

int	out_map(int x, int y, int size)
{
  if (x < 0 || x >= size)
    return (1);
  else if (y < 0 || y >= size)
    return (1);
  else
    return (0);
}

void	coord(t_game *game, int player, int *tab)
{
  if (game->players[player].orientation == 'N')
    north(game, player, tab);
  else if (game->players[player].orientation == 'E')
    east(game, player, tab);
  else if (game->players[player].orientation == 'S')
    south(game, player, tab);
  else
    west(game, player, tab);
}

int	do_write(t_game *game, int player)
{
  write(game->players[player].socket, game->players[player].digit,
	my_strlen(game->players[player].digit));
  return (0);
}
