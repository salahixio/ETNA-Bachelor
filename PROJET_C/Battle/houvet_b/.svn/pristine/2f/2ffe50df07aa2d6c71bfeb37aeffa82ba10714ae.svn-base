/*
** check_attack.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 17:54:15 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 17:01:20 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_game.h"
#include "../header/fonctions_lib.h"
#include<stdlib.h>

int		check_attack(t_creature *player, int attack, int magic)
{
  if (attack == 1)
    if (player->pm >= 3)
      return (1);
    else
      return (0);
  else if (attack == 2)
    if (player->pm >= 7)
      return (1);
    else
      return (0);
  else if (attack == 5)
    if (magic >= 1)
      return (1);
    else
      return (0);
  else
    return (1);
}
