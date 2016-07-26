/*
** ia.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 19:22:58 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 17:01:23 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_game.h"
#include "../header/fonctions_lib.h"
#include <stdlib.h>
#include <time.h>

void		ia(t_creature *ennemi, t_creature *player, int catch)
{
  int		value;

  srand(time(NULL));
  value = rand() % 6;
  while (!check_attack(ennemi, value, 1))
    value = (rand() % 4) + 1;
  if (value == 1)
    slash(ennemi, player);
  else if (value == 2)
    fire(ennemi, player);
  else if (value == 3)
    gamble(ennemi, player);
  else if (value == 4)
    rest(ennemi);
  else
    catch = magic_box(ennemi, player);
  if (catch == 1)
    player->pv = 0;
}
