/*
** main.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Oct 29 20:55:08 2015 DELAPLACE Antoine
** Last update Sat Oct 31 13:57:48 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/fonction_lib.h"
#include "header/struct_manche.h"

int		check_arguments(int argc, char **argv);
t_manche	*play_game(int mode, int nb_parties, t_manche *manches);
int		check_replay(t_manche *manches);
int		check_version();
int		check_nb_parties();

int		main(int argc, char **argv)
{
  t_manche	*manches;
  int		version;
  int		nb_parties;

  manches = malloc(sizeof(t_manche *));
  if (manches != 0)
    {
      if (check_arguments(argc, argv))
	{
	  version = my_getnbr(argv[2]);
	  nb_parties = my_getnbr(argv[4]);
	  manches = play_game(version, nb_parties, manches);
	  while (manches != NULL && check_replay(manches))
	    {
	      version = check_version();
	      nb_parties = check_nb_parties();
	      manches = play_game(version, nb_parties, manches);
	    }
	}
      free(manches);
    }
  else
    my_putstr("L'allocation mémoire de la liste a échouée");
  return (0);
}
