/*
** structures.h for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 17:55:55 2015 HOUVET Benoît - Xavier
** Last update Mon Dec 14 20:19:06 2015 HOUVET Benoît - Xavier
*/

#ifndef STRUCTURES_H_
# define STRUCTURES_H_

typedef struct		s_creatures{
  char			*name;
  int			lvl;
  int			pv;
  int			pvmax;
  int			pm;
  int			pmmax;
}			t_creature;

typedef struct		s_player
{
  char			*name;
  struct s_creatures	*my_creatures;
}			t_player;

#endif /* !STRUCTURES_H_ */
