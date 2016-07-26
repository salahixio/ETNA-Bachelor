/*
** my_find_elm_eq_in_list.c for ok in /home/antoine/C/Jour10-C/delapl_b/my_find_elm_eq_in_list
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 28 23:34:05 2015 DELAPLACE Antoine
** Last update Thu Oct 29 03:24:35 2015 DELAPLACE Antoine
*/

#include <stdlib.h>
#include "my_list.h"

void		*my_find_elm_eq_in_list(t_list *begin,
					void *data_ref, int (*cmp)())
{
  t_list	*save;

  save = malloc(sizeof(t_list *));
  save = begin;
  while (save != 0)
    {
      if (cmp(save->data, data_ref) == 0)
	return save->data;
      save = save->next;
    }
  return (NULL);
}
