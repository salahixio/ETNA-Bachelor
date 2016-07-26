/*
** ia.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 19:22:58 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:33:35 2015 DELAPLACE Antoine
*/

#include "../header/structures.h"
#include "../header/fonctions_game.h"
#include "../header/fonctions_lib.h"
#include <stdlib.h>
#include <time.h>

char		*ia(t_creature *ennemi, t_creature *player)
{
  int		value;

  srand(time(NULL));
  value = rand() % 5;
  while (!check_attack(ennemi, value))
    value = (rand() % 4) + 1;
  if (value == 1) {
    slash(ennemi, player);
    return ("slash");
  }
  else if (value == 2) {
    fire(ennemi, player);
    return ("fire");
  }
  else if (value == 3) {
    gamble(ennemi, player);
    return ("gamble");
  }
  else {
    rest(ennemi);
    return ("rest");
  }
}
