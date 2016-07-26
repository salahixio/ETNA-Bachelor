/*
** check_version.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Sat Oct 31 13:21:12 2015 DELAPLACE Antoine
** Last update Sat Oct 31 14:01:25 2015 DELAPLACE Antoine
*/

#include "header/fonction_lib.h"
#include "header/struct_manche.h"

char	*readLine();

int	check_version()
{
  char  *entry;

  entry = "";
  while (my_getnbr(entry) != 3 && my_getnbr(entry) != 5)
    {
      my_putstr("\nA quelle version voulez vous jouer ?(3 ou 5)\n");
      entry = readLine();
      if (my_getnbr(entry) == 3 || my_getnbr(entry) == 5)
	return my_getnbr(entry);
    }
  return (0);
}
