/*
** check_args.c for SoftWar in /home/tonio/SoftWar/houvet_b/server
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Tue Jul 12 16:40:25 2016 HOUVET Benoît - Xavier
** Last update Mon Aug 29 19:50:28 2016 HOUVET Benoît - Xavier
*/

#include "../header/lib.h"
#include "../header/functions.h"

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
