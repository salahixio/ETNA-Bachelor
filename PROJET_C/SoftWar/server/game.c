/*
** game.c for softwar in /home/tonio/SoftWar/houvet_b/server
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Mon Aug 22 21:32:48 2016 DELAPLACE Antoine
** Last update Wed Aug 24 12:40:24 2016 DELAPLACE Antoine
*/

#include "../header/lib.h"
#include "../header/functions.h"

void			play_game(t_game *game)
{
  int			played;
  fd_set		readfs;
  int			i;
  char			**name_cmds;

  played = 1;
  if ((name_cmds = init_name_cmds()) == NULL)
    played = -1;
  while (played)
    {
      FD_ZERO(&readfs);
      for (i = 0; i < 4; i++)
	FD_SET(game->players[i].socket, &readfs);
      FD_SET(0, &readfs);
      select(8, &readfs, NULL, NULL, NULL);
      for (i = 0; i < 4; i++)
	{
	  if (game->nbralive == 1)
	    {
	      played = 0;
	    }
	  if (FD_ISSET(game->players[i].socket, &readfs))
	    wait_cmd(game, i, name_cmds, &readfs);
	}
    }
}

void			wait_cmd(t_game *game, int i,
				 char **name_cmds, fd_set *readfs)
{
  void                  (*list_cmds[14])(t_game *game, int player) =
    {orientation, watch, selfid,
     selfstatus, left, right, forward,
     backward, attack, next,
     jump, leftfwd, rightfwd, gather};
  char			buffer[42];
  int			nread;

  memset(buffer, 0, 20);
  nread = recv(game->players[i].socket, buffer, 42, 0);
  buffer[nread] = '\0';
  if (game->players[i].action > 0)
    play_cmd(game, i, buffer, name_cmds, list_cmds);
  else
    write_ko(game->players[i].socket);
  FD_CLR(game->players[i].socket, readfs);
}

void			play_cmd(t_game *game, int player_number,
				 char *cmd, char **name_cmds,
				 void (*list_cmds[14])(t_game *game, int player))
{
  int			ok;
  int			i;
  int			nb_action_available;

  nb_action_available = (game->players[player_number].action == 1) ? 7 : 14;
  ok = 0;
  i = 0;
  while (i < nb_action_available && ok == 0)
    {
      if (my_strcmp(cmd, name_cmds[i]) == 0)
	{
	  list_cmds[i](game, player_number);
	  ok = 1;
	}
      i++;
    }
  if (ok == 0)
    {
      if (my_strcmp(cmd, "inspect\n") == 0)
	inspect(game, "#0x90", player_number);
      else
	write(game->players[player_number].socket, "ko\n", sizeof("ko\n"));
    }
}

char			**init_name_cmds()
{
  char			**name_cmds;

  if ((name_cmds = malloc(sizeof(char *) * 14)) == NULL)
    return (NULL);
  name_cmds[0] = my_strdup("orientation\n");
  name_cmds[1] = my_strdup("watch\n");
  name_cmds[2] = my_strdup("selfid\n");
  name_cmds[3] = my_strdup("selfstatus\n");
  name_cmds[4] = my_strdup("left\n");
  name_cmds[5] = my_strdup("right\n");
  name_cmds[6] = my_strdup("forward\n");
  name_cmds[7] = my_strdup("backward\n");
  name_cmds[8] = my_strdup("attack\n");
  name_cmds[9] = my_strdup("next\n");
  name_cmds[10] = my_strdup("jump\n");
  name_cmds[11] = my_strdup("leftfwd\n");
  name_cmds[12] = my_strdup("rightfwd\n");
  name_cmds[13] = my_strdup("gather\n");
  return (name_cmds);
}
