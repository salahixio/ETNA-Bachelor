/*
** mushrooms.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Final
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Thu Dec 17 05:50:29 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 17:29:52 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/fonctions_lib.h"
#include "header/fonctions_game.h"
#include "header/structures.h"
#include <time.h>

void		mushrooms(t_player *player)
{
  t_creature	*creature;
  int		number;
  int		nb_choice;
  int		nb_pvmore;

  nb_choice = 1;
  if (player->items[1] == 0)
    print_no_mushroom();
  else
    {
      creature = select_fighter(player);
      number = check_number_items(player, player->items[1]);
      while (nb_choice <= number)
	{
	  nb_pvmore = randpv(creature->pvmax);
	  if ((creature->pv + nb_pvmore) >= creature->pvmax)
	    creature->pv = creature->pvmax;
	  else
	    creature->pv += nb_pvmore;
	  print_more_pv(creature->name, nb_pvmore, creature->pv);
	  nb_choice++;
	  player->items[1] -= 1;
	}
    }
}

int		randpv(int pvmax)
{
  int		alea;

  srand(time(NULL));
  alea = (rand() % 11) + 15;
  alea = (alea * pvmax) / 100;
  return (alea);
}

void		print_more_pv(char *name, int nb_pvmore, int pv)
{
  my_putstr("Votre créature ");
  my_putstr(name);
  my_putstr(" a récupéré ");
  my_put_nbr(nb_pvmore);
  my_putstr(" en plus, ce qui lui fait maintenant ");
  my_put_nbr(pv);
  my_putstr(" pv au total\n");
}
