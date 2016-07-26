/*
** print_manche.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Sat Oct 31 10:59:55 2015 DELAPLACE Antoine
** Last update Sat Oct 31 11:31:32 2015 DELAPLACE Antoine
*/

#include "header/struct_manche.h"
#include "header/fonction_lib.h"

void	print_manche(t_manche *manches, char **choices, int winner)
{
  my_putstr("\nRound : ");
  my_put_nbr(manches->numero_manche);
  my_putstr("\nVous avez choisi : ");
  my_putstr(choices[manches->coup_joueur1]);
  my_putstr("\nL'ordinateur a choisi : ");
  my_putstr(choices[manches->coup_joueur2]);
  if (winner == 0)
    my_putstr("\nEgalité !");
  else if (winner == 1)
    my_putstr("\nVous avez remporté la manche.");
  else
    my_putstr("\nVous avez perdu la manche.");
  my_putstr("\nLe score est maintenant de : ");
  my_put_nbr(manches->score_joueur1);
  my_putstr(" : ");
  my_put_nbr(manches->score_joueur2);
  my_putstr("\n");
}
