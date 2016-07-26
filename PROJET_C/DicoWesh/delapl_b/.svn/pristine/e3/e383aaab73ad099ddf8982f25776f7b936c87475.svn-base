/*
** main.c for dico in /home/antoine/ALGO/DicoWesh/delapl_b/DicoWESH
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Nov  5 10:01:48 2015 DELAPLACE Antoine
** Last update Sat Nov  7 13:20:33 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/struct_dico.h"
#include "header/fonction_lib.h"

void		print_start();
void		print_choices();
void		print_error();
int		check_saisie(char *str);
char		*readLine();
t_dico		*fill_dico(t_dico *dico);
t_dico		*load_dico(t_dico *dico, char *entry);
void		my_free(t_dico *dico);

int		main()
{
  char          *entry;
  t_dico        *dico;
  char          choice;

  entry = "";
  choice = '\0';
  print_start();
  if ((dico = malloc(sizeof(t_dico))) == 0)
    return (-1);
  if ((dico = fill_dico(dico)) == 0)
    return (-1);
  while (choice != 'q')
    {
      print_choices();
      entry = readLine();
      if (!check_saisie(entry))
	print_error();
      else
	dico = load_dico(dico, entry);
      choice = entry[0];
      free(entry);
    }
  my_free(dico);
  return (0);
}
