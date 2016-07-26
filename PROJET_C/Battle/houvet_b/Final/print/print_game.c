/*
** print_game.c for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 18:38:51 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 10:33:35 2015 HOUVET Benoît - Xavier
*/

#include "../header/structures.h"
#include "../header/fonctions_lib.h"

void	print_game(char *name)
{
  my_putstr("Bonjour ");
  my_putstr(name);
  my_putstr(" et bienvenue dans PokETNA !\n");
}

void	print_start_battle()
{
  my_putstr("*******************************************************\n");
  my_putstr("*           Vous entrez en combat !!!                 *\n");
}

void	print_out_of_battle()
{
  my_putstr("");
  my_putstr("\nQue souhaitez vous faire ?\n");
  my_putstr("Voir votre équipe ? 'team'\n");
  my_putstr("Choisir la créature qui va attaquer ? 'you are the chosen one'\n");
  my_putstr("Lancer un combat contre un monstre ? 'let's fight'\n");
  my_putstr("Aller dans la boutique ? 'shop'\n");
  my_putstr("Utiliser un champignon ? 'mushroom'\n");
  my_putstr("Quitter le jeu ? 'quit'\n");
}

void	print_enter_number()
{
  my_putstr("\nQuellle créature voulez-vous choisir ?\n");
}

void	print_victory(t_creature *creature)
{
  my_putstr(creature->name);
  my_putstr(" a gagné le combat.\n");
}
