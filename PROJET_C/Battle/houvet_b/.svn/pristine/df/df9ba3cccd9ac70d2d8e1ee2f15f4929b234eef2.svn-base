/*
** select_fighter.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 11:27:24 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:24:16 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/structures.h"
#include "header/fonctions_game.h"
#include "header/fonctions_lib.h"

t_creature	*select_fighter(t_player *player)
{
  t_team	*tmp_team;
  int		number_creature;
  int		i;

  i = 1;
  number_creature = 1;
  tmp_team = player->team;
  while (tmp_team != NULL)
    {
      my_put_nbr(number_creature);
      my_putstr(". ");
      print_infos_creature(tmp_team->creature);
      ++number_creature;
      tmp_team = tmp_team->next;
    }
  number_creature = check_number(number_creature - 1, player->name);
  tmp_team = player->team;
  while (i < number_creature && tmp_team != NULL)
    {
      ++i;
      tmp_team = tmp_team->next;
    }
  return (tmp_team->creature);
}

int		check_number(int number_creature, char *prompt)
{
  char		*value;
  int		choice;

  print_enter_number(number_creature);
  value = readEntry(prompt);
  choice = my_getnbr(value);
  while (choice < 1 || choice > number_creature)
    {
      free(value);
      print_invalid_number(number_creature);
      value = readEntry(prompt);
      choice = my_getnbr(value);
    }
  free(value);
  return (choice);
}

void		print_invalid_number(int number_creature)
{
  my_putstr("#--------------------------------------------#\n");
  my_putstr("|             Argument non valide !          |\n");
  my_putstr("|  Vous devez entrez un nombre entre 1 et ");
  my_put_nbr(number_creature);
  if (number_creature < 10)
    my_putstr(" ");
  my_putstr(" |\n");
  my_putstr("#--------------------------------------------#\n");
}
