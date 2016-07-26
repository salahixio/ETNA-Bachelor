/*
** check.c for foundations in /Users/antoine/Documents/ETNA/C/C/Foundations/delapl_b/src
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Wed Apr 27 15:43:11 2016 DELAPLACE Antoine
** Last update Wed Apr 27 18:14:08 2016 DELAPLACE Antoine
*/

#include "../header/lib.h"

int	check_args(int nbr_args, char **args)
{
  int	check;

  check = 1;
  if (nbr_args != 5) {
    check = -1;
    my_putstr("Le nombre d'arguments n'est pas correct\n");
  }
  else {
    if (my_strcmp(args[1], "--ip") != 0) {
      check = -1;
      my_putstr("Option --ip manquante\n");
    }
    if (my_strcmp(args[3], "--port") != 0) {
      check = -1;
      my_putstr("Option --port manquante\n");
    }
    if (!my_getnbr(args[4])) {
      check = -1;
      my_putstr("Le port est incorrect\n");
    }
  }
  return (check);
}
