/*
** check_victory.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Sat Oct 31 10:50:37 2015 DELAPLACE Antoine
** Last update Sat Oct 31 14:00:41 2015 DELAPLACE Antoine
*/

#include "header/struct_manche.h"
#include "header/fonction_lib.h"

int	check_victory(int nb_parties, t_manche *manches)
{
  if (manches->score_joueur1 == (nb_parties / 2) + 1)
    {
      my_putstr("\nVous avez gagné la partie !\n");
      return (1);
    }
  else if (manches->score_joueur2 == (nb_parties / 2) + 1)
    {
      my_putstr("Vous avez perdu la partie.\n");
      return (1);
    }
  else    return (0);
}
