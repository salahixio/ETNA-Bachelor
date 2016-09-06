/*
** map.c for soft war in /home/tonio/SoftWar/houvet_b/server
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Mon Aug 22 19:43:06 2016 DELAPLACE Antoine
** Last update Wed Aug 24 11:14:57 2016 DELAPLACE Antoine
*/

#include "../header/lib.h"
#include "../header/functions.h"

int             **init_map(int size)
{
  int           i;
  int           j;
  int           **map;

  if ((map = malloc(sizeof(int *) * size )) == NULL)
    return (NULL);
  for (i = 0; i < size; i++)
    {
      if ((map[i] = malloc(sizeof(int) * size)) == NULL)
	return (NULL);
      for (j = 0; j < size; j++)
	{
	  map[i][j] = 0;
	}
    }
  return (map);
}
