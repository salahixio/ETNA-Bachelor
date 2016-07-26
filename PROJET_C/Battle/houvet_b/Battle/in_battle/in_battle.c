/*
** in_battle.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 15:09:06 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:34:38 2015 DELAPLACE Antoine
*/

#include "../header/structures.h"
#include "../header/fonctions_game.h"
#include "../header/fonctions_lib.h"

void            in_the_battle(t_creature *chosen_creature, t_player *player,
			      t_creature *ennemi, int *value, int *catch);

void		in_battle(t_creature *chosen_creature, t_player *player)
{
  t_creature	*ennemi;
  int		value;
  int		catch;

  catch = 0;
  ennemi = getCreature();
  while ((chosen_creature->pv > 0) && (ennemi->pv > 0)
	 && (value != -1) && (catch == 0))
    {
      in_the_battle(chosen_creature, player, ennemi, &value, &catch);
    }
  if (chosen_creature->pv < 0)
    print_victory(ennemi);
  else if (ennemi->pv < 0)
    print_victory(chosen_creature);
  soin(chosen_creature);
  if (catch == 0)
    free_creature(ennemi);
  else
    soin(ennemi);
}

void		in_the_battle(t_creature *chosen_creature, t_player *player,
			      t_creature *ennemi, int *value, int *catch)
{
  print_infos_creatures(chosen_creature, ennemi);
  print_attack();
  *value = check_battle(chosen_creature->name);
  if (check_attack(chosen_creature, *value))
    {
      if (*value == 1)
	slash(chosen_creature, ennemi);
      else if (*value == 2)
	fire(chosen_creature, ennemi);
      else if (*value == 3)
	gamble(chosen_creature, ennemi);
      else if (*value == 4)
	rest(chosen_creature);
      else if (*value == 5)
	*catch = magic_catch(player, ennemi);
      if ((ennemi->pv > 0) && (*catch == 0) && (*value != -1))
	ia(ennemi, chosen_creature);
    }
  else
    print_no_pm();
}
