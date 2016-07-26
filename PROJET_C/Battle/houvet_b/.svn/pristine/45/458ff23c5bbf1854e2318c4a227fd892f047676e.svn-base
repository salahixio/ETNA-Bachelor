/*
** main.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 18:34:46 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 10:58:00 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/fonctions_lib.h"
#include "header/fonctions_game.h"
#include "header/structures.h"

int		main(int argc, char **argv)
{
  t_player	player;
  int		quit;
  t_creature	*chosen_creature;

  if (check_args(argc, argv))
    {
      player.team = NULL;
      player.name = argv[2];
      print_game(player.name);
      quit = play_game(&player);
      if (quit != -1)
	{
	  chosen_creature = player.team->creature;
	  while (chosen_creature != NULL)
	    chosen_creature = out_of_battle(&player, chosen_creature);
	}
    }
  free_list_creatures(player.team);
  return (0);
}
