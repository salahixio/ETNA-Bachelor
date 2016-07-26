/*
** check_args.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 17:51:36 2015 HOUVET Benoît - Xavier
** Last update Mon Dec 14 20:01:28 2015 HOUVET Benoît - Xavier
*/

#include "header/fonctions_lib.h"

int	check_args(int nbr_args, char **args)
{
  if ((nbr_args != 3) || (my_strcmp(args[1],"-n") != 0))
    {
      my_putstr("#--------------------------------------------#\n");
      my_putstr("|         Utilisation du programme :         |\n");
      my_putstr("|            ./sta -n [Votre Nom]            |\n");
      my_putstr("#--------------------------------------------#\n");
      return (0);
    }
  else
    return (1);
}
