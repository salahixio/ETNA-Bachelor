/*
** out_of_battle.c for sta in /Users/antoine/Documents/ETNA/C/Battle/houvet_b/Battle
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Dec 15 18:04:35 2015 DELAPLACE Antoine
** Last update Thu Dec 17 17:14:36 2015 HOUVET Benoît - Xavier
*/

#include "header/structures.h"
#include "header/fonctions_game.h"
#include "header/fonctions_lib.h"
#include<stdlib.h>

t_creature	*out_of_battle(t_player *player, t_creature *chosen_creature)
{
  int		choice;

  choice = check_choices(player->name);
  if (choice == 1)
    display_team(player);
  else if ((choice == 2) && (player->team != NULL))
    chosen_creature = select_fighter(player);
  else if ((choice == 2) && (player->team == NULL))
    my_putstr("Votre team est actuellement vide, vous ne pouvez pas choisir\n");
  else if (choice == 3)
    {
      print_start_battle();
      in_battle(chosen_creature, player);
    }
  else if (choice == 4)
    in_shop(player);
  else if (choice == 5)
    mushrooms(player);
  else
    return (NULL);
  return (chosen_creature);
}
