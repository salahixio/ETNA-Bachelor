/*
** magic_catch.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 16:10:32 2015 HOUVET Benoît - Xavier
** Last update Wed Dec 16 23:46:01 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_lib.h"
#include "../header/fonctions_game.h"
#include<stdlib.h>

int		magic_catch(t_player *player, t_creature *ennemi)
{
  int		rnd;

  rnd = rand() % ennemi->pvmax;
  if (rnd >= ennemi->pv)
    {
      if ((catch_creature(ennemi, player)) == NULL)
	return (0);
      print_capture(ennemi);
      return (1);
    }
  else
    {
      print_fail_capture(ennemi);
      return (0);
    }
}
