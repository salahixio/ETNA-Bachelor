/*
** print_capture.c for sta in /Users/antoine/Documents/ETNA/C/Battle/houvet_b
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Dec 15 10:15:27 2015 DELAPLACE Antoine
** Last update Wed Dec 16 23:25:03 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_lib.h"
#include "../header/fonctions_game.h"

void	print_capture(t_creature *creature)
{
  my_putstr("Vous avez capturé ");
  my_putstr(creature->name);
  my_putstr("! Il est maintenant dans votre team !\n");
  my_putstr("Il est niveau ");
  my_put_nbr(creature->lvl);
  my_putstr(".\nIl a ");
  my_put_nbr(creature->pvmax);
  my_putstr(" points de vies ");
  my_putstr("et ");
  my_put_nbr(creature->pmmax);
  my_putstr(" points de magie.\n");
}

void	print_fail_capture(t_creature *creature)
{
  my_putstr("La capture de ");
  my_putstr(creature->name);
  my_putstr(" sauvage a échouée.\n");
}
