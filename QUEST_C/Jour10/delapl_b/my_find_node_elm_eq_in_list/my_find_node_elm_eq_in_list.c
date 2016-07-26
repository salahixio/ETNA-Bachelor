/*
** my_find_node_elm_eq_in_list.c for ok in /home/antoine/C/Jour10-C/delapl_b/my_find_node_elm_eq_in_list
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Thu Oct 29 00:20:44 2015 DELAPLACE Antoine
** Last update Thu Oct 29 00:39:11 2015 DELAPLACE Antoine
*/

#include <stdlib.h>
#include "my_list.h"

t_list		*my_find_node_elm_eq_in_list(t_list *begin,
				    void *data_ref, int (*cmp)())
{
  t_list	*save;

  save = malloc(sizeof(t_list *));
  save = begin;
  while (save != 0)
    {
      if (cmp(save->data, data_ref) == 0)
	return save;
      save = save->next;
    }
  return (NULL);
}
