/*
** main.c for softwar in /home/tonio/SoftWar/houvet_b/src
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Wed Jul  6 13:07:36 2016 DELAPLACE Antoine
** Last update Thu Sep  1 23:32:03 2016 HOUVET Benoît - Xavier
*/

#include "../header/lib.h"
#include "../header/functions.h"

int		main()
{
  pthread_t	cycle1;
  t_game	game;

  game.condition = 1;
  game.size = 10;
  game.nbralive = 4;
  if ((game.map = init_map(game.size)) == NULL)
    {
      perror("malloc nul");
      return (-1);
    }
  if (create_socket(&game) == -1) {
    return (-1);
  }
  if (pthread_create(&cycle1, NULL, cycle, (void *) &game))
    {
      perror("pthread_create");
      return (-1);
    }
  play_game(&game);
  game.condition = 0;
  close_socket(game);
  return (0);
}
