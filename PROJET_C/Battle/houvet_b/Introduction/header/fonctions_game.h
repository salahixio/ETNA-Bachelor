/*
** fonctions_game.h for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 18:40:44 2015 HOUVET Benoît - Xavier
** Last update Wed Dec 16 16:50:51 2015 HOUVET Benoît - Xavier
*/

#include "structures.h"

#ifndef FONCTIONS_GAME_H_
# define FONCTIONS_GAME_H_

void		print_game(char *name);
int		check_args(int argc, char **argv);
int		check_actions();
void		print_creature(t_creature *creature);
void		play_game();
t_creature	*getCreature();
int		capture_creature();
void		print_capture(t_creature *creature);
char		*readEntry();
void		print_invalid();

#endif /* !FONCTIONS_GAME_H_ */
