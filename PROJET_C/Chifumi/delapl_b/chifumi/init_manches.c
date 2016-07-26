/*
** init_manche.c for  in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Sat Oct 31 09:44:57 2015 DELAPLACE Antoine
** Last update Sat Oct 31 13:06:34 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/struct_manche.h"

void	init_manches(t_manche *manches)
{
  manches->score_joueur1 = 0;
  manches->score_joueur2 = 0;
  manches->coup_joueur1 = 0;
  manches->coup_joueur2 = 0;
  manches->numero_manche = 0;
}
