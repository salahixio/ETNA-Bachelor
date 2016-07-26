/*
** check_actions.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 18:07:02 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:59:50 2015 DELAPLACE Antoine
*/

#include "header/fonctions_lib.h"
#include "header/fonctions_game.h"
#include <stdlib.h>

int	check_choices(char *prompt)
{
  char	*value;
  int	choice;

  print_out_of_battle();
  value = readEntry(prompt);
  choice = -1;
  while (is_a_valid_choice(value) == 0)
    {
      free(value);
      print_invalid_arguments();
      value = readEntry(prompt);
    }
  choice = select_choice(value);
  free(value);
  return (choice);
}

void	print_invalid_arguments()
{
  my_putstr("#--------------------------------------------#\n");
  my_putstr("|             Argument non valide !          |\n");
  my_putstr("|       Les six arguments valides sont :     |\n");
  my_putstr("|                    team                    |\n");
  my_putstr("|           you are the chosen one           |\n");
  my_putstr("|                 let's fight                |\n");
  my_putstr("|                    shop                    |\n");
  my_putstr("|                  mushrooms                 |\n");
  my_putstr("|                    quit                    |\n");
  my_putstr("#--------------------------------------------#\n");
}

int	is_a_valid_choice(char *value)
{
  if (my_strcmp(value, "team") == 0 ||
      my_strcmp(value, "you are the chosen one") == 0 ||
      my_strcmp(value, "let's fight") == 0 ||
      my_strcmp(value, "quit") == 0 ||
      my_strcmp(value, "shop") == 0 ||
      my_strcmp(value, "mushroom") == 0)
    return (1);
  else
    return (0);
}

int	select_choice(char *value)
{
  int choice;

  if (my_strcmp(value, "team") == 0)
    choice = 1;
  else if (my_strcmp(value, "you are the chosen one") == 0)
    choice = 2;
  else if (my_strcmp(value, "let's fight") == 0)
    choice = 3;
  else if (my_strcmp(value, "shop") == 0)
    choice = 4;
  else if (my_strcmp(value, "mushroom") == 0)
    choice = 5;
  else
    choice = -1;
  return (choice);
}
