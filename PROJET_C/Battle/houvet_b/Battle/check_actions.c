/*
** check_actions.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 18:07:02 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:21:30 2015 DELAPLACE Antoine
*/

#include "header/fonctions_lib.h"
#include "header/fonctions_game.h"
#include <stdlib.h>

int	check_actions(char *prompt)
{
  char	*value;

  value = readEntry(prompt);
  while ((my_strcmp(value,"magic catch") != 0) &&
	 (my_strcmp(value,"help me !!!") != 0) &&
	 (my_strcmp(value,"Quit") != 0))
    {
      free(value);
      print_invalid();
      value = readEntry(prompt);
    }
  if (my_strcmp(value,"magic catch") == 0)
    {
      free(value);
      return (1);
    }
  else if (my_strcmp(value,"help me !!!") == 0)
    {
      free(value);
      return (0);
    }
  free(value);
  return (-1);
}

void	print_invalid()
{
  my_putstr("#--------------------------------------------#\n");
  my_putstr("|             Argument non valide !          |\n");
  my_putstr("|      Les trois arguments valides sont :    |\n");
  my_putstr("|                 magic catch                |\n");
  my_putstr("|                 help me !!!                |\n");
  my_putstr("|                    Quit                    |\n");
  my_putstr("#--------------------------------------------#\n");
}

char	*readEntry(char *prompt)
{
  char	*entry;

  my_putstr(prompt);
  my_putstr("> ");
  entry = readLine();
  my_putchar('\n');
  return (entry);
}
