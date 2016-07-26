/*
** print_histo.c for  in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Sat Oct 31 12:14:18 2015 DELAPLACE Antoine
** Last update Sat Oct 31 14:07:42 2015 DELAPLACE Antoine
*/

#include "header/fonction_lib.h"
#include "header/struct_manche.h"

void	fill_tab(int mode, char **choices);
void	my_rev_list(t_manche *manches);

void	print_histo(t_manche *manches)
{
  char	*choices[6];

  fill_tab(5, choices);
  while (manches->numero_manche != 0)
    {
      my_putstr("\n--------Round ");
      my_put_nbr(manches->numero_manche);
      my_putstr("\nVous : (");
      my_putstr(choices[manches->coup_joueur1]);
      my_putstr(")");
      my_putstr(" : Ordi : (");
      my_putstr(choices[manches->coup_joueur2]);
      my_putstr(")\nScore : ");
      my_put_nbr(manches->score_joueur1);
      my_putstr(" : ");
      my_put_nbr(manches->score_joueur2);
      my_putstr("\n");
      manches = manches->next;
    }
}
