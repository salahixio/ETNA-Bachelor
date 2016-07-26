/*
** check_attack.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 17:54:15 2015 HOUVET Benoît - Xavier
** Last update Wed Dec 16 20:08:34 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_game.h"
#include "../header/fonctions_lib.h"
#include<stdlib.h>

int		check_attack(t_creature *player, int attack)
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
  else
    return (1);
}
