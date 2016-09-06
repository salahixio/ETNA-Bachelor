/*
** action.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Aug 23 11:29:39 2016 DELAPLACE Antoine
** Last update Wed Aug 24 11:23:27 2016 DELAPLACE Antoine
*/

#include "../header/lib.h"
#include "../header/functions.h"

void	next(t_game *game, int player)
{
  game->players[player].action = 0;
}

void	jump(t_game *game, int player)
{
  int	x;
  int	y;
  int	flag;

  flag = 1;
  x = game->players[player].x;
  y = game->players[player].y;
  if (game->players[player].orientation == 'N' && y > 1)
    y -= 2;
  else if (game->players[player].orientation == 'E' && x < (game->size - 2))
    x += 2;
  else if (game->players[player].orientation == 'S' && y < (game->size - 2))
    y += 2;
  else if (game->players[player].orientation == 'W' && x > 1)
    x -= 2;
  else
    {
      write(game->players[player].socket, "ko\n", my_strlen("ko\n"));
      flag = 0;
    }
  if (flag == 1 && colision(game, player, x, y, 2) == 0)
    coord_action(game, player, x, y, 2);
  game->players[player].energy = game->players[player].energy - 2;
  write_ok(game->players[player].socket);
}

void	attack(t_game *game, int player)
{
  int	*cord;

  cord = malloc(sizeof(int) * 8);
  if (cord == NULL)
    write_ko(game->players[player].socket);
  else
    {
      coord(game, player, cord);
      degats(game, player, cord);
      free(cord);
    }
  write_ok(game->players[player].socket);
}

void	degats(t_game *game, int player, int *tab)
{
  int	i;
  int	j;

  for (i = 0; i < 7; i += 2)
    {
      for (j = 0; j < 4; j++)
	{
	  if (tab[i] == game->players[j].x && tab[i + 1] == game->players[j].y)
	    game->players[j].action = -2;
	}
    }
  decrement(game, player, 2);
  game->players[player].energy = game->players[player].energy - 1;
}

void	gather(t_game *game, int player)
{
  int   pos_x;
  int   pos_y;
  int   value;

  pos_x = game->players[player].x;
  pos_y = game->players[player].y;
  value = game->map[pos_x][pos_y];
  game->map[pos_x][pos_y] = 0;
  game->players[player].energy += value;
  game->players[player].action = (game->players[player].action - 2);
  write_ok(game->players[player].socket);
}
