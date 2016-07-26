/*
** print_creature.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 19:46:10 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:27:03 2015 DELAPLACE Antoine
*/

#include "../header/structures.h"
#include "../header/fonctions_game.h"
#include "../header/fonctions_lib.h"

void	print_creature(t_creature *creature)
{
  my_putstr(creature->name);
  my_putstr(" est apparu !\n");
}

void	print_infos_creature(t_creature *creature)
{
  my_putstr(creature->name);
  my_putstr(" -> lvl : ");
  my_put_nbr(creature->lvl);
  my_putstr(" -> pv : ");
  my_put_nbr(creature->pv);
  my_putstr("/");
  my_put_nbr(creature->pvmax);
  my_putstr(" -> pm : ");
  my_put_nbr(creature->pm);
  my_putstr("/");
  my_put_nbr(creature->pmmax);
  my_putstr("\n");
}

void	print_empty_team()
{
  my_putstr("Votre team est actuellement vide.\n");
}

void	print_infos_creatures(t_creature *chosen_creature, t_creature *ennemi)
{
  my_putstr("*******************************************************\n");
  my_putstr("                              Ennemi : ");
  print_cbt_creature(ennemi, 1);
  my_putstr("\nVous : ");
  print_cbt_creature(chosen_creature, 0);
  my_putstr("\n*******************************************************\n");
}

void	print_cbt_creature(t_creature *creature, int ennemi)
{
  my_putstr(creature->name); my_putstr("\n");
  if (ennemi)
    my_putstr("                                       ");
  else
    my_putstr("       ");
  my_putstr("LVL ");
  my_put_nbr(creature->lvl);
  my_putstr("\n");
  if (ennemi)
    my_putstr("                                       ");
  else
    my_putstr("       ");
  my_putstr("PV ");
  my_put_nbr(creature->pv);
  my_putstr("/");
  my_put_nbr(creature->pvmax);
  my_putstr("\n");
  if (ennemi)
    my_putstr("                                       ");
  else
    my_putstr("       ");
  my_putstr("PM ");
  my_put_nbr(creature->pm);
  my_putstr("/");
  my_put_nbr(creature->pmmax);
}
