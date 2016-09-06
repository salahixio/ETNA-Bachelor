/*
** functions.h for softwar in /home/tonio/SoftWar/houvet_b/header
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Wed Jul  6 13:10:37 2016 DELAPLACE Antoine
** Last update Wed Aug 24 11:10:54 2016 DELAPLACE Antoine
*/

#ifndef FUNCTIONS_H_
# define FUNCTIONS_H_

#include "struct.h"

int			wait_connection(t_game *game, int sock,
					socklen_t socket_length,
					struct sockaddr_in client_address);
int			accept_clients(t_game *game, int sock);
struct sockaddr_in	init_structure(struct sockaddr_in server_address);
int			create_socket(t_game *game);
int			**init_map(int size);
void			show_map(int **map, int size);
void			show_players(t_game game);
void			play_game(t_game *game);
void			*cycle(void *test);
void			close_socket(t_game game);
int			init_player(t_game *game, int player_number);
void			orientation(t_game *game, int player_number);
void			right(t_game *game, int player);
void			left(t_game *game, int player);
void			gather(t_game *game, int player);
void			selfid(t_game *game, int player);
void			selfstatus(t_game *game, int player);
void			inspect(t_game *game, char *digit, int player);
void			write_ok(int socket);
void			write_n(int socket);
void			write_ko(int socket);
void			play_cmd(t_game *game, int player_number, char *cmd,
				 char **name_cmds,
				 void (*list_cmds[14])(t_game *game, int player));
void			forward(t_game *game, int player);
void			backward(t_game *game, int player);
int			colision(t_game *game, int player, int x, int y, int value);
void			modify_coord(t_game *game, int player, int x, int y);
void			coord_action(t_game *game, int player, int x,
				     int y, int value);
void			watch(t_game *game, int player);
void			coord(t_game *game, int player, int *tab);
void			north(t_game *game, int player, int *tab);
void			west(t_game *game, int player, int *tab);
void			south(t_game *game, int player, int *tab);
void			east(t_game *game, int player, int *tab);
void			traduct(t_game *game, int player, int *tab);
void			degats(t_game *game, int player, int *tab);
int			out_map(int x, int y, int size);
int			do_write(t_game *game, int player);
void			decrement(t_game *game, int player, int moins);
void			attack(t_game *game, int player);
void			show_all(t_game *game);
void			next(t_game *game, int player);
void			jump(t_game *game, int player);
void			leftfwd(t_game *game, int player);
void			rightfwd(t_game *game, int player);
void			init_y(t_game *game, int player_number);
void			init_x(t_game *game, int player_number);
void			wait_cmd(t_game *game, int i,
				 char **name_cmds, fd_set *readfs);
char			**init_name_cmds();
void			init_charge(t_game *game);
int			have_player(t_game *game, int x, int y);
void			die(t_game *game, int player);
void			alive(t_game *game);
#endif /* !FUNCTIONS_H_ */
