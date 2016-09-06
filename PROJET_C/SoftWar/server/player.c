/*
** player.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Aug 23 06:43:08 2016 DELAPLACE Antoine
** Last update Thu Sep  1 23:18:51 2016 HOUVET Benoît - Xavier
*/

#include "../header/lib.h"
#include "../header/functions.h"

int		init_player(t_game *game, int player_number)
{
  char		unity;
  int		ten;
  char		digit[5];

  game->players[player_number].energy = 50;
  game->players[player_number].action = 2;
  srand(player_number + 1);
  unity = (rand() % 10) + 48;
  ten = (rand() % 10) + 48;
  digit[0] = '#';
  digit[1] = '0';
  digit[2] = 'x';
  digit[3] = ten;
  digit[4] = unity;
  digit[5] = '\0';
  if ((game->players[player_number].digit = my_strdup(digit)) == NULL)
    return (-1);
  init_y(game, player_number);
  init_x(game, player_number);
  write_ok(game->players[player_number].socket);
  return (1);
}

void		init_y(t_game *game, int player_number)
{
  if (player_number < 2)
    {
      game->players[player_number].y = 0;
      game->players[player_number].orientation = 'S';
    }
  else
    {
      game->players[player_number].y = (game->size - 1);
      game->players[player_number].orientation = 'N';
    }
}

void            init_x(t_game *game, int player_number)
{
  if (player_number == 0 || player_number == 3)
    {
      game->players[player_number].x = 0;
    }
  else
    {
      game->players[player_number].x = (game->size - 1);
    }
}

void		decrement(t_game *game, int player, int moins)
{
  game->players[player].action -= moins;
}
