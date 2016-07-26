/*
** remove_team.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Final/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Thu Dec 17 03:56:06 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 05:05:25 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_lib.h"
#include "../header/fonctions_game.h"
#include <stdlib.h>

void		remove_team(t_player *player)
{
  t_team	*team;
  t_team	*team_tmp;

  team_tmp = NULL;
  team = player->team;
  while (team)
    {
      if (team->creature->pv <= 0)
	team = team->next;
      else
	{
	  team_tmp = add_creature(team_tmp, team->creature, 1);
	  team = team->next;
	}
    }
  player->team = team_tmp;
}
