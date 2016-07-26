/*
** add_manches.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Sat Oct 31 09:57:06 2015 DELAPLACE Antoine
** Last update Sat Oct 31 13:44:54 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/struct_manche.h"

t_manche	*add_manche(t_manche *manches, int winner,
			    int coup_joueur1, int coup_joueur2)
{
  t_manche	*manche;

  manche = malloc(sizeof(*manche));
  if (manche == 0)
    return (NULL);
  manche->next = manches;
  manche->coup_joueur1 = coup_joueur1;
  manche->coup_joueur2 = coup_joueur2;
  manche->numero_manche = manches->numero_manche + 1;
  if (winner == 1)
    {
      manche->score_joueur1 = manches->score_joueur1 + 1;
      manche->score_joueur2 = manches->score_joueur2;
    }
  else if (winner == (-1))
    {
      manche->score_joueur2 = manches->score_joueur2 + 1;
      manche->score_joueur1 = manches->score_joueur1;
    }
  else
    {
      manche->score_joueur2 = manches->score_joueur2;
      manche->score_joueur1 = manches->score_joueur1;
    }
  return (manche);
}
