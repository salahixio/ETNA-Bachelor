/*
** attack.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/in_battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 16:47:27 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:29:36 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "../header/structures.h"
#include "../header/fonctions_game.h"
#include "../header/fonctions_lib.h"
#include <time.h>

void		slash(t_creature *chosen_creature, t_creature *ennemi)
{
  int		pvloose;
  int		pmloose;

  pvloose = 9;
  pmloose = 3;
  chosen_creature->pm = (chosen_creature->pm - pmloose);
  ennemi->pv = (ennemi->pv - pvloose);
  print_damage("slash", chosen_creature, ennemi, pvloose, pmloose);
}

void		fire(t_creature *chosen_creature, t_creature *ennemi)
{
  int		pvloose;
  int		pmloose;

  pvloose = 30;
  pmloose = 7;
  chosen_creature->pm = (chosen_creature->pm - pmloose);
  ennemi->pv = (ennemi->pv - pvloose);
  print_damage("fire", chosen_creature, ennemi, pvloose, pmloose);
}

void		gamble(t_creature *chosen_creature, t_creature *ennemi)
{
  int		rnd;
  int		rnd2;

  srand(time(NULL));
  rnd = rand() % 3;
  rnd2 = ((rand() % 22) - 1);
  if (rnd == 1)
    {
      chosen_creature->pv = (chosen_creature->pv - rnd2);
      print_damage("gamble", chosen_creature, chosen_creature, rnd2, 0);
    }
  else
    {
      ennemi->pv = (ennemi->pv - rnd2);
      print_damage("gamble", chosen_creature, ennemi, rnd2, 0);
    }
}

void		rest(t_creature *chosen_creature)
{
  if ((chosen_creature->pm + 10) >= chosen_creature->pmmax)
    chosen_creature->pm = chosen_creature->pmmax;
  else
    chosen_creature->pm = (chosen_creature->pm + 10);
  print_damage("rest", chosen_creature, chosen_creature, 0, 0);
}

void		soin(t_creature *creature)
{
  creature->pm = creature->pmmax;
  creature->pv = creature->pvmax;
}
