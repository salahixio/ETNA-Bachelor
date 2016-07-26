/*
** check_nb_parties.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Sat Oct 31 13:26:51 2015 DELAPLACE Antoine
** Last update Sat Oct 31 15:55:37 2015 DELAPLACE Antoine
*/

#include "header/fonction_lib.h"
#include "header/struct_manche.h"

char	*readLine();

int	check_nb_parties()
{
  char	*entry;

  entry = "";
  while (my_getnbr(entry) <= 0 || !my_is_odd(my_getnbr(entry)))
    {
      my_putstr("\nCombien de parties voulez vous jouer ?(chiffre impair)\n");
      entry = readLine();
      if(my_getnbr(entry) > 0 && my_is_odd(my_getnbr(entry)))
	return my_getnbr(entry);
    }
  return (0);
}
