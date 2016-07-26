/*
** main.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 18:34:46 2015 HOUVET Benoît - Xavier
** Last update Tue Dec 15 17:27:31 2015 DELAPLACE Antoine
*/

#include "header/fonctions_lib.h"
#include "header/fonctions_game.h"
#include "header/structures.h"

int		main(int argc, char **argv)
{
  t_player	player;

  if (check_args(argc, argv))
    {
      player.name = argv[2];
      print_game(player.name);
      play_game();
    }
  return (0);
}
