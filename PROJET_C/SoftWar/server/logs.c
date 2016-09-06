/*
** logs.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Aug 23 07:15:50 2016 DELAPLACE Antoine
** Last update Thu Sep  1 04:14:34 2016 HOUVET Benoît - Xavier
*/

#include "../header/lib.h"
#include "../header/functions.h"

void            show_map(int **map, int size)
{
  int           i;
  int           j;

  for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
	{
	  my_put_nbr(map[i][j]);
	  my_putstr(" ");
	}
      my_putstr("\n");
    }
  my_putstr("\n");
}

void		show_players(t_game game)
{
  int		i;

  for (i=0; i < 4; i++)
    {
      my_putstr("Player ");
      my_putstr(game.players[i].digit);
      my_putstr(" : \n");
      my_putstr("position: [");
      my_put_nbr(game.players[i].x);
      my_putstr(", ");
      my_put_nbr(game.players[i].y);
      my_putstr(", ");
      my_putchar(game.players[i].orientation);
      my_putstr("]\nEnergy : ");
      my_put_nbr(game.players[i].energy);
      my_putstr("\nAction : ");
      my_put_nbr(game.players[i].action);
      my_putstr("\n\n");
    }
}

void		write_ok(int socket)
{
  write(socket, "ok\n", my_strlen("ok\n"));
}

void		write_n(int socket)
{
  write(socket, "\n", my_strlen("\n"));
}

void		write_ko(int socket)
{
  write(socket, "ko\n", my_strlen("ko\n"));
}
