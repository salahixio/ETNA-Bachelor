/*
** init_player.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Thu Dec 17 00:51:31 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 01:04:28 2015 HOUVET Benoît - Xavier
*/

#include "header/structures.h"

void	init_player(t_player *player, char *name)
{
  player->name = name;
  player->rupees = 420;
  player->items[0] = 5;
  player->items[1] = 0;
}
