/*
** structures.h for sta in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 17:55:55 2015 HOUVET Benoît - Xavier
** Last update Thu Dec 17 00:26:52 2015 HOUVET Benoît - Xavier
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
  int			rupees;
  int			items[2];
  struct s_team		*team;
}			t_player;

typedef struct		s_team
{
  struct s_creatures	*creature;
  struct s_team		*next;
}			t_team;

#endif /* !STRUCTURES_H_ */
