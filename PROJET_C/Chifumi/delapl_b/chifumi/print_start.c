/*
** print_start.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Oct 29 22:51:37 2015 DELAPLACE Antoine
** Last update Sat Oct 31 14:06:38 2015 DELAPLACE Antoine
*/

#include "header/fonction_lib.h"

void	print_start(int mode, int parties)
{
  int	first;

  my_putstr("\nVous avez choisi le mode : ");
  my_putstr("pierre - feuille - ciseaux");
  if (mode == 5)
    my_putstr(" - lezard - spock");
  my_putstr("\n");
  my_putstr("Le premier avec ");
  first = (parties / 2) + 1;
  my_put_nbr(first);
  if (first == 1)
    my_putstr(" point");
  else
    my_putstr(" points");
  my_putstr(" a gagné");
}
