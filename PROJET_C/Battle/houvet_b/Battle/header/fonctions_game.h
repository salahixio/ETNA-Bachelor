/*
** fonctions_game.h for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 18:40:44 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 16:36:18 2015 DELAPLACE Antoine
*/

#include "structures.h"

#ifndef FONCTIONS_GAME_H_
# define FONCTIONS_GAME_H_

void		print_game(char *name);
int		check_args(int argc, char **argv);
int		check_actions();
void		print_creature(t_creature *creature);
int		play_game(t_player *player);
t_creature	*getCreature();
int		capture_creature();
void		print_capture(t_creature *creature);
void		print_invalid();
t_team		*catch_creature(t_creature *ennemi, t_player *player);
t_team		*add_creature(t_team *team, t_creature *ennemi);
int             check_number(int number_creature, char *prompt);
void            print_invalid_number(int number_creature);
int		check_choices(char *prompt);
void		print_out_of_battle();
t_creature	*out_of_battle(t_player *player, t_creature *chosen_creature);
t_creature	*select_fighter(t_player *player);
void		print_infos_creature(t_creature *creature);
void		print_empty_team();
char		*readEntry(char *prompt);
void		print_enter_number();
void		in_battle(t_creature *chosen_creature, t_player *player);
int             check_battle(char *prompt);
void            print_attack();
void            print_attack_invalid();
void            display_team(t_player *player);
void		print_fail_capture(t_creature *creature);
void            slash(t_creature *chosen_creature, t_creature *ennemi);
void            fire(t_creature *chosen_creature, t_creature *ennemi);
void            gamble(t_creature *chosen_creature, t_creature *ennemi);
void            rest(t_creature *chosen_creature);
int		magic_catch(t_player *player, t_creature *ennemi);
void            print_infos_creatures(t_creature *chosen_creature,
				      t_creature *ennemi);
void		print_no_pm();
int		check_attack(t_creature *player, int attack);
void            soin(t_creature *creature);
void		print_start_battle();
char            *ia(t_creature *ennemi, t_creature *player);
void		print_cbt_creature(t_creature *creature, int ennemi);
void            print_damage(char *attack,
			     t_creature *aggresor, t_creature *defender,
			     int pvloose, int pmloose);
void		print_victory(t_creature *creature);
void		free_creature(t_creature *creature);
void		free_list_creatures(t_team *team);

#endif /* !FONCTIONS_GAME_H_ */
