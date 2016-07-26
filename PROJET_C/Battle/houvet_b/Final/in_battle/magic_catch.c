/*
** magic_catch.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 16:10:32 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 17:07:04 2015 DELAPLACE Antoine
*/

#include "../header/structures.h"
#include "../header/fonctions_lib.h"
#include "../header/fonctions_game.h"
#include<stdlib.h>
#include<time.h>
int		magic_catch(t_player *player, t_creature *ennemi)
{
  int		rnd;

  srand(time(NULL));
  rnd = rand() % ennemi->pvmax;
  if (rnd >= ennemi->pv)
    {
      if((catch_creature(ennemi, player, 2)) == NULL)
	return (0);
      print_capture(ennemi);
      player->items[0] -= 1;
      return (1);
    }
  else
    {
      print_fail_capture(ennemi);
      player->items[0] -= 1;
      return (0);
    }
}

int		magic_box(t_creature *ennemi, t_creature *player)
{
  int		rnd;

  srand(time(NULL));
  rnd = rand() % player->pvmax;
  if (rnd >= ennemi->pv)
    {
      print_capture_ennemi(ennemi, player);
      return (1);
    }
  else
    {
      print_fail_capture_ennemi(ennemi);
      return (0);
    }
}
