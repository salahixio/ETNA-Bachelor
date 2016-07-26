/*
** free_items.c for sta in /Users/antoine/Documents/ETNA/C/Battle/houvet_b/Battle
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Dec 17 16:18:08 2015 DELAPLACE Antoine
** Last update Thu Dec 17 16:18:17 2015 DELAPLACE Antoine
*/

#include "header/structures.h"
#include<stdlib.h>

void		free_creature(t_creature *creature)
{
  free(creature->name);
  free(creature);
}

void		free_list_creatures(t_team *team)
{
  t_team	*save_team;

  while (team != NULL)
    {
      save_team = team;
      team = team->next;
      free_creature(save_team->creature);
      free(save_team);
    }
}
