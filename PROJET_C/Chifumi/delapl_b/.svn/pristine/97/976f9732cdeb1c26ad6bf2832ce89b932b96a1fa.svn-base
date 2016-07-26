/*
** check_replay.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Sat Oct 31 11:54:40 2015 DELAPLACE Antoine
** Last update Sat Oct 31 14:02:40 2015 DELAPLACE Antoine
*/

#include "header/fonction_lib.h"
#include "header/struct_manche.h"

char	*readLine();
void	print_histo(t_manche *manches);

int	check_replay(t_manche *manches)
{
  char	*entry;

  entry = "";
  while (my_strcmp(entry, "oui") && my_strcmp(entry, "non"))
    {
      my_putstr("\nSouhaitez vous rejouer ? (oui / non / histo)\n");
      entry = readLine();
      if (my_strcmp(entry, "histo") == 0)
	print_histo(manches);
      else if (my_strcmp(entry, "oui") && my_strcmp(entry, "non"))
	my_putstr("Votre saisie est incorrecte. (oui / non / histo)");
      else if (my_strcmp(entry, "oui") == 0)
	return (1);
    }
  return (0);
}
