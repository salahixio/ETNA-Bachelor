/*
** print_attack.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 15:55:44 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:32:26 2015 DELAPLACE Antoine
*/

#include "../header/fonctions_lib.h"
#include "../header/fonctions_game.h"
#include<stdlib.h>

int		check_battle(char *prompt)
{
  char		*value;
  int		attack;

  attack = -1;
  value = readEntry(prompt);
  while ((my_strcmp(value, "slash") != 0) && (my_strcmp(value, "fire") != 0) &&
	 (my_strcmp(value, "gamble") != 0) && (my_strcmp(value, "rest") != 0) &&
	 (my_strcmp(value, "magic catch") != 0) &&
	 (my_strcmp(value, "quit") != 0)) {
    free(value);
    print_attack_invalid();
    value = readEntry(prompt);
  }
  if (my_strcmp(value, "slash") == 0)
    attack = 1;
  else if (my_strcmp(value, "fire") == 0)
    attack = 2;
  else if (my_strcmp(value, "gamble") == 0)
    attack = 3;
  else if (my_strcmp(value, "rest") == 0)
    attack = 4;
  else if (my_strcmp(value, "magic catch") == 0)
    attack = 5;
  free(value);
  return (attack);
}
