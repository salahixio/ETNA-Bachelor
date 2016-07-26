/*
** play_game.c for  in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Fri Oct 30 01:06:48 2015 DELAPLACE Antoine
** Last update Sat Oct 31 14:09:26 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/fonction_lib.h"
#include "header/struct_manche.h"

void		print_start(int mode, int nb_parties);
int		check_entry(char **tab, int mode);
void		fill_tab(int mode, char **tab);
int		is_a_available_choice(char *entry, int mode, char **choices);
char		*readLine();
t_manche	*play_manche(int choice, int mode,
			     t_manche *manches, int rules[6][2]);
void		fill_rules(int rules[6][2]);
int		check_victory(int nb_parties, t_manche *manches);
int		init_manches(t_manche *manches);

t_manche	*play_game(int mode, int nb_parties, t_manche *manches)
{
  char		*choices[mode + 1];
  int		choice;
  int		rules[6][2];

  fill_tab(mode, choices);
  fill_rules(rules);
  init_manches(manches);
  print_start(mode, nb_parties);
  while (!check_victory(nb_parties, manches)
	 && (choice = check_entry(choices, mode)) != 0)
    {
      manches = play_manche(choice, mode, manches, rules);
    }
  if (choice == 0)
    return (NULL);
  return (manches);
}

int	check_entry(char **choices, int mode)
{
  char	*entry;
  int	choice;

  my_putstr("\n\nQuel est votre choix ?\n");
  entry = readLine();
  while ((choice = is_a_available_choice(entry, mode, choices)) == (-1))
    {
      my_putstr("Votre saisie est incorrecte\n");
      entry = readLine();
    }
  return (choice);
}

int	is_a_available_choice(char *entry, int mode, char **choices)
{
  int	i;

  i = 0;
  while (i <= mode)
    {
      if (my_strcmp(choices[i], entry) == 0)
	return (i);
      ++i;
    }
  return (-1);
}
