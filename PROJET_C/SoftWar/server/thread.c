/*
** surchage.c for SoftWar in /home/tonio/SoftWar/houvet_b/server
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Tue Jul 12 16:45:17 2016 HOUVET Benoît - Xavier
** Last update Thu Sep  1 22:44:03 2016 HOUVET Benoît - Xavier
*/

#include "../header/lib.h"
#include "../header/functions.h"

void	*cycle(void *tmp_game)
{
  t_game	*game;
  int		i;
  int		time_cycle;

  time_cycle = 5000000;
  game = (t_game *) tmp_game;
  while (game->condition == 1)
    {
      init_charge(game);
      for (i = 0; i < 4; i++)
	{
	  if (game->players[i].energy > 2 && game->players[i].energy < 100)
	    game->players[i].energy = (game->players[i].energy - 2);
	  else
	    die(game, i);
	  if (game->players[i].action <= 0)
	    game->players[i].action = (game->players[i].action + 2);
	  else if (game->players[i].action == 1)
	    game->players[i].action = (game->players[i].action + 1);
	}
      //      alive(game);
      show_all(game);
      usleep(time_cycle);
    }
  return (NULL);
}

void	show_all(t_game *game)
{
  show_players(*game);
  show_map(game->map, game->size);
}

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

void	init_charge(t_game *game)
{
  int	rand_x;
  int	rand_y;
  int	rand_charge;

  rand_x = rand() % game->size;
  rand_y = rand() % game->size;
  while (have_player(game, rand_x, rand_y))
    {
      rand_x = rand() % game->size;
      rand_y = rand() % game->size;
    }
  rand_charge = (rand() % 10) + 5;
  game->map[rand_x][rand_y] += rand_charge;
}

int	have_player(t_game *game, int x, int y)
{
  int	i;
  int	flag;

  flag = 0;
  for (i = 0; i < 4; i++)
    {
      if (game->players[i].x == x && game->players[i].y == y)
	flag = 1;
    }
  return (flag);
}
