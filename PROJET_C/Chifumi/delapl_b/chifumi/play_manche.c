/*
** play_manche.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Fri Oct 30 00:52:55 2015 DELAPLACE Antoine
** Last update Sat Oct 31 13:54:40 2015 DELAPLACE Antoine
*/

#include <stdlib.h>
#include <time.h>
#include "header/fonction_lib.h"
#include "header/struct_manche.h"

int		random_choice(int mode);
int		calculate_winner(int joueur, int ordi, int rules[6][2]);
void		fill_tab(int mode, char **choices);
t_manche	*add_manche(t_manche *manches, int winner,
			    int coup_joueur1, int coup_joueur2);
void		print_manche(t_manche *manches, char**choices, int winner);

t_manche	*play_manche(int choice, int mode, t_manche *manches, int rules[6][2])
{
  int	ordi;
  int	winner;
  char	*choices[mode + 1];

  fill_tab(mode, choices);
  ordi = random_choice(mode);
  winner = calculate_winner(choice, ordi, rules);
  manches = add_manche(manches, winner, choice, ordi);
  if (manches != NULL)
    print_manche(manches, choices, winner);
  return manches;
}

int	random_choice(int mode)
{
  int	random;

  srand (time (NULL));
  random = rand() % mode + 1;
  return (random);
}

int	calculate_winner(int joueur, int ordi, int rules[6][2])
{
  if (joueur == ordi)
    return (0);
  else if (rules[joueur][0] == ordi || rules[joueur][1] == ordi)
    return (1);
  else
    return (-1);
}
