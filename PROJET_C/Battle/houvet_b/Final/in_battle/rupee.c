/*
** rupee.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Final/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Thu Dec 17 01:41:49 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 02:18:14 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_game.h"
#include "../header/fonctions_lib.h"
#include <time.h>
#include <stdlib.h>

void		rupee(t_player *player)
{
  int		nbr_rupee;

  nbr_rupee = rand_rupee();
  player->rupees += nbr_rupee;
  print_new_rupee(nbr_rupee, player->rupees);
}

int		rand_rupee()
{
  int		rupee;

  srand(time(NULL));
  rupee = (rand() % 31) + 90;
  return (rupee);
}
