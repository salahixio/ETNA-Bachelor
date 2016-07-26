/*
** fonctions_game.h for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 18:40:44 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 17:24:09 2015 DELAPLACE Antoine
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
t_team		*catch_creature(t_creature *ennemi, t_player *player, int nbr);
t_team		*add_creature(t_team *team, t_creature *ennemi, int nbr);
int		check_choices(char *prompt);
void		print_out_of_battle();
t_creature	*out_of_battle(t_player *player, t_creature *chosen_creature);
int             check_number(int number_creature, char *prompt);
void            print_invalid_number(int number_creature);
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
int		check_attack(t_creature *player, int attack, int magic);
void            soin(t_creature *creature);
void		print_start_battle();
void            ia(t_creature *ennemi, t_creature *player, int catch);
void		print_cbt_creature(t_creature *creature, int ennemi);
void            print_damage(char *attack,
			     t_creature *aggresor, t_creature *defender,
			     int pvloose, int pmloose);
void		print_victory(t_creature *creature);
void		init_player(t_player *player, char *name);
int		is_a_valid_choice(char *value);
void		print_invalid_arguments();
int		select_choice(char *value);
void            rupee(t_player *player);
int             rand_rupee();
void		print_new_rupee(int nbr_rupee, int nbr_rupee_player);
void		print_items_player(t_player *player);
void		print_start_shop();
void		in_shop(t_player *player);
int		check_choices_shop(t_player *player);
void		print_choices_shop(t_player *player);
void		print_invalid_arguments_shop(t_player *player);
int             magic_box(t_creature *ennemi, t_creature *player);
void		print_fail_capture_ennemi(t_creature *ennemi);
void		print_capture_ennemi(t_creature *ennemi, t_creature *player);
void		print_no_money();
void            remove_team(t_player *player);
void		print_select(int max);
int		check_number_items(t_player *player, int max);
void		add_items_for_player(t_player *player, int item, int nbr);
void		mushrooms(t_player *player);
void		print_no_mushroom();
void		print_start_mushroom();
int             randpv(int pvmax);
void            print_more_pv(char *name, int nb_pvmore, int pv);
void            print_no_magic();
void            free_creature(t_creature *creature);
void            free_list_creatures(t_team *team);

#endif /* !FONCTIONS_GAME_H_ */
