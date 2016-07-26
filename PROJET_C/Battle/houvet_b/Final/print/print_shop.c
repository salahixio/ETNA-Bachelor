/*
** print_shop.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Final/print
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Thu Dec 17 01:50:46 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 04:32:28 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_lib.h"

void	print_start_shop()
{
  my_putstr("Bienvenue dans la boutique.\n");
}

void	print_items_player(t_player *player)
{
  my_putstr("Vous possédez ");
  my_put_nbr(player->rupees);
  my_putstr(" rupees, ");
  my_put_nbr(player->items[0]);
  my_putstr(" magic box et ");
  my_put_nbr(player->items[1]);
  my_putstr(" champignon(s).\n");
}

void	print_choices_shop(t_player *player)
{
  my_putstr("Que souhaitez vous acheter ?\n");
  if (player->rupees >= 90)
    my_putstr("> magic box (90 Rupees)\n");
  my_putstr("> mushrooms (30 Rupees)\n");
  my_putstr("> quit\n");
}

void	print_select(int max)
{
  my_putstr("Combien en voulez vous ?");
  my_putstr(" (");
  my_put_nbr(max);
  my_putstr(" max)\n");
}
