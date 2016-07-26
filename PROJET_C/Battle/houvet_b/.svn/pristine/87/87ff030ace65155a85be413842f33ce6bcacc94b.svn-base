/*
** play_game.c for ok in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 20:04:13 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:19:50 2015 DELAPLACE Antoine
*/

#include "header/structures.h"
#include "header/fonctions_lib.h"
#include "header/fonctions_game.h"
#include <stdlib.h>

int		play_game(t_player *player)
{
  int		action;
  t_creature	*ennemi;

  action = 1;
  while ((action != -1) && (action != -2))
    {
      if ((ennemi = getCreature()) == NULL)
	return (-1);
      print_creature(ennemi);
      action = check_actions(player->name);
      if (action == 1 && capture_creature() == 1)
	{
	  if ((catch_creature(ennemi, player)) == NULL)
	    return (-1);
	  print_capture(ennemi);
	  action = -2;
	}
      else if (action == 1) {
	print_fail_capture(ennemi);
	free_creature(ennemi);
      }
      else
	free_creature(ennemi);
    }
  return (action);
}

t_team		*catch_creature(t_creature *ennemi, t_player *player)
{
  t_team	*creature;

  if ((creature = add_creature(player->team, ennemi)) == NULL)
    return (NULL);
  player->team = add_creature(player->team, ennemi);
  return (player->team);
}

t_team		*add_creature(t_team *team, t_creature *ennemi)
{
  t_team	*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  if (new_elem == 0)
    return (NULL);
  ennemi->pvmax = ennemi->pvmax * 2;
  ennemi->pmmax = ennemi->pmmax * 2;
  ennemi->pv = ennemi->pvmax;
  ennemi->pm = ennemi->pmmax;
  new_elem->creature = ennemi;
  if (team == 0)
    new_elem->next = NULL;
  else
    new_elem->next = team;
  return (new_elem);
}
