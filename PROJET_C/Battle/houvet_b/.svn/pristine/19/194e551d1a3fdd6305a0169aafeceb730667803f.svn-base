/*
** display_team.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 10:47:37 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 04:52:42 2015 HOUVET Benoît - Xavier
*/

#include<stdio.h>
#include "header/structures.h"
#include "header/fonctions_game.h"
#include "header/fonctions_lib.h"

void            display_team(t_player *player)
{
  t_player      *play;
  t_team        *team;

  play = player;
  team = play->team;
  if (team == NULL)
    print_empty_team();
  else
    {
      while (team)
	{
	  print_infos_creature(team->creature);
	  team = team->next;
	}
    }
}
