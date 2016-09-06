/*
** struct.h for softwar in /home/tonio/SoftWar/houvet_b/header
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Aug 23 06:18:17 2016 DELAPLACE Antoine
** Last update Thu Sep  1 22:46:23 2016 HOUVET Benoît - Xavier
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct s_player {
  int   socket;
  char  *digit;
  int   x;
  int   y;
  char  orientation;
  int   energy;
  int	action;
} t_player;

typedef struct s_game {
  int           **map;
  int           size;
  int           condition;
  int		nbralive;
  t_player	players[4];
} t_game;

#endif /* !STRUCT_H_ */
