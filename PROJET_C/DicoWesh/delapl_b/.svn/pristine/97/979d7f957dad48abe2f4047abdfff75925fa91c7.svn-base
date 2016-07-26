/*
** tri_dico.c for dico in /home/antoine/Documents/ALGO/DicoWesh/delapl_b/DicoWESH
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Nov  5 20:20:38 2015 DELAPLACE Antoine
** Last update Fri Nov  6 03:46:41 2015 DELAPLACE Antoine
*/

#include "header/struct_dico.h"
#include "header/fonction_lib.h"

int		compare_mot(t_dico *first, t_dico *second, int sens);
t_dico		*swap(t_dico **before_first, t_dico **first,
		      t_dico **second, t_dico **dico);
void		next(t_dico **before_first, t_dico **first, t_dico **second);

t_dico		*tri_dico(t_dico *dico, int sens)
{
  int		tri_fini;
  t_dico	*before_first;
  t_dico	*first;
  t_dico	*second;

  tri_fini = 0;
  while (!tri_fini)
    {
      first = dico;
      before_first = dico;
      second = dico->next;
      tri_fini = 1;
      while (second != 0)
	{
	  if (compare_mot(first, second, sens))
	    {
	      tri_fini = 0;
	      swap(&before_first, &first, &second, &dico);
	    }
	  else
	    next(&before_first, &first, &second);
	}
    }
  return (dico);
}

int		compare_mot(t_dico *first, t_dico *second, int sens)
{
  if (!sens && my_strcmp(first->mot_fr, second->mot_fr) == 1)
    return (1);
  else if (sens && my_strcmp(first->mot_wesh, second->mot_wesh) == 1)
    return (1);
  else
    return (0);
}

t_dico		*swap(t_dico **before_first, t_dico **first,
		      t_dico **second, t_dico **dico)
{
  t_dico	**tmp;

  tmp = first;
  (*first)->next = (*second)->next;
  (*second)->next = *first;
  if (*before_first != *first)
    {
      (*before_first)->next = *second;
      *tmp = *first;
      *first = *second;
      *second = *tmp;
    }
  else
    {
      *first = *second;
      *dico = *second;
      *second = *before_first;
      *before_first = *dico;
    }
  return (*first);
}

void		next(t_dico **before_first, t_dico **first, t_dico **second)
{
  if (*before_first != *first)
    *before_first = (*before_first)->next;
  *first = (*first)->next;
  *second = (*second)->next;
}
