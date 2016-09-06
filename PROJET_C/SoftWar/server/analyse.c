/*
** analyse.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Aug 23 11:31:09 2016 DELAPLACE Antoine
** Last update Wed Aug 24 11:31:17 2016 DELAPLACE Antoine
*/

#include "../header/lib.h"
#include "../header/functions.h"

void    my_put_int(t_game *game, int player, int energy);

void    selfid(t_game *game, int player)
{
  char  *digit;

  digit = game->players[player].digit;
  write(game->players[player].socket, digit, my_strlen(digit));
  write_n(game->players[player].socket);
}

void    selfstatus(t_game *game, int player)
{
  my_put_int(game, player, game->players[player].energy);
  write_n(game->players[player].socket);
}

void    inspect(t_game *game, char *digit, int player)
{
  int   i;
  int   flag;

  flag = 1;
  for (i = 0; i < 4; i++)
    {
      if (my_strcmp(game->players[i].digit, digit) == 0)
	{
	  my_put_int(game, player, game->players[player].energy);
	  write_n(game->players[player].socket);
	  game->players[player].action = game->players[player].action - 1;
	  flag = 0;
	}
    }
  if (flag == 1)
    write(game->players[player].socket, "Digit Faux\n",
	  my_strlen("Digit Faux\n"));
}

void	my_put_int(t_game *game, int player, int energy)
{
  char	tmp;

  if (energy < 10)
    {
      tmp = energy + '0';
      write(game->players[player].socket, &tmp, sizeof(char));
    }
  else
    {
      my_put_int(game, player, energy / 10);
      my_put_int(game, player, energy % 10);
    }
}

void	watch(t_game *game, int player)
{
  int	*cord;

  cord = malloc(sizeof(int) * 8);
  if (cord == NULL)
    write_ko(game->players[player].socket);
  else
    {
      coord(game, player, cord);
      traduct(game, player, cord);
      free(cord);
    }
}
