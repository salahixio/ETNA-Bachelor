/*
** print_attack.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b/Battle/print
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 16 17:43:01 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:17:22 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_game.h"
#include "../header/fonctions_lib.h"
#include<stdlib.h>

void            print_attack()
{
  my_putstr("> slash (-15PV & -3PM)   > fire (-30PV & -7PM)\n");
  my_putstr("> gamble (-[0-20]PV ?)   > rest (+10PM)\n");
  my_putstr("> magic catch            > quit\n\n");
}

void            print_attack_invalid()
{
  my_putstr("#--------------------------------------------#\n");
  my_putstr("|             Argument non valide !          |\n");
  my_putstr("|       Les six arguments valides sont :     |\n");
  my_putstr("|                   slash                    |\n");
  my_putstr("|                   fire                     |\n");
  my_putstr("|                  gamble                    |\n");
  my_putstr("|                    rest                    |\n");
  my_putstr("|                magic catch                 |\n");
  my_putstr("|                    quit                    |\n");
  my_putstr("#--------------------------------------------#\n");
}

void		print_no_pm()
{
  my_putstr("Vous n'avez pas assez de PM pour executer cette attaque\n");
  my_putstr("Veuillez en choisir une autre !");
}

void		print_damage(char *attack,
			     t_creature *aggresor, t_creature *defender,
			     int pvloose, int pmloose)
{
  my_putstr(aggresor->name);
  my_putstr(" lance ");
  my_putstr(attack);
  my_putstr(". ");
  if (my_strcmp(attack, "rest") != 0)
    {
      my_putstr(defender->name);
      my_putstr(" perd ");
      my_put_nbr(pvloose);
      my_putstr("PV");
      if (pmloose != 0)
	{
	  my_putstr(" et ");
	  my_putstr(aggresor->name);
	  my_putstr(" perd ");
	  my_put_nbr(pmloose);
	  my_putstr("PM");
	}
      my_putstr(".\n\n");
    }
  else
    {
      my_putstr(aggresor->name);
      my_putstr(" gagne 10PM.\n\n");
    }
}

void		print_no_magic()
{
  my_putstr("Vous n'avez pas de Magic Box pour executer cette attaque\n");
  my_putstr("Veuillez en choisir une autre !");
}
