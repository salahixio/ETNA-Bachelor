/*
** in_shop.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Final
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Thu Dec 17 01:47:13 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 17:00:40 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/structures.h"
#include "header/fonctions_lib.h"
#include "header/fonctions_game.h"

void	in_shop(t_player *player)
{
  int	choice;
  int	max;
  int	nb_item;

  choice = 0;
  if (player->rupees < 30)
    print_no_money();
  else
    {
      print_start_shop();
      while (choice != -1 && player->rupees >= 30)
	{
	  print_items_player(player);
	  print_choices_shop(player);
	  choice = check_choices_shop(player);
	  if (choice == 1)
	    max = player->rupees / 90;
	  else if (choice == 2)
	    max = player->rupees / 30;
	  if (choice != -1)
	    {
	      print_select(max);
	      nb_item = check_number_items(player, max);
	      add_items_for_player(player, choice - 1, nb_item);
	    }
	}
    }
}

int	check_choices_shop(t_player *player)
{
  char  *value;
  int   choice;

  value = readEntry(player->name);
  choice = -1;
  while ((my_strcmp(value, "magic box") != 0 || player->rupees < 90) &&
	 my_strcmp(value, "mushrooms") != 0 &&
	 my_strcmp(value, "quit"))
    {
      free(value);
      print_invalid_arguments_shop(player);
      value = readEntry(player->name);
    }
  if (my_strcmp(value, "magic box") == 0)
    choice = 1;
  else if (my_strcmp(value, "mushrooms") == 0)
    choice = 2;
  free(value);
  return (choice);
}

int	check_number_items(t_player *player, int max)
{
  char	*value;
  int	number;

  value = readEntry(player->name);
  number = my_getnbr(value);
  while (number < 1 || number > max)
    {
      free(value);
      print_invalid_number(max);
      value = readEntry(player->name);
      number = my_getnbr(value);
    }
  free (value);
  return (number);
}

void	add_items_for_player(t_player *player, int item, int nbr)
{
  int price;

  if (item == 0)
    price = 90 * nbr;
  else
    price = 30 * nbr;
  player->rupees -= price;
  player->items[item] += nbr;
}
