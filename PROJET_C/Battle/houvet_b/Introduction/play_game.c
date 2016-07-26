/*
** play_game.c for ok in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 20:04:13 2015 HOUVET Benoît - Xavier
** Last update Wed Dec 16 16:40:49 2015 HOUVET Benoît - Xavier
*/

#include "header/structures.h"
#include "header/fonctions_lib.h"
#include "header/fonctions_game.h"
#include <stdlib.h>

void		play_game()
{
  int		action;
  t_creature	*ennemi;

  action = 0;
  while (action != -1)
    {
      ennemi = getCreature();
      print_creature(ennemi);
      action = check_actions();
      if (action == 1 && capture_creature() == 1)
	{
	  print_capture(ennemi);
	  action = -1;
	}
      free(ennemi->name);
      free(ennemi);
    }
}
