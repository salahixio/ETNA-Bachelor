/*
** my_rm_all_eq_from_list.c for ok in /home/antoine/C/Jour10-C/delapl_b/my_rm_all_eq_from_list
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Thu Oct 29 00:49:34 2015 DELAPLACE Antoine
** Last update Thu Oct 29 03:57:34 2015 DELAPLACE Antoine
*/

#include <stdlib.h>
#include "my_list.h"

void		my_rm_all_eq_from_list(t_list **begin,
			    void *data_ref, int (*cmp)())
{
   t_list	*save_begin;

   while ((*begin) != 0 && cmp((*begin)->data, data_ref) == 0)
    (*begin) = (*begin)->next;
  save_begin = malloc(sizeof(t_list *));
  save_begin = (*begin);
  if ((*begin) != 0)
  {
    while (save_begin != 0)
      {
	if (cmp((save_begin->next)->data, data_ref) == 0 &&
	    (save_begin->next) != 0)
	  save_begin->next = (save_begin->next)->next;
	save_begin = save_begin->next;
      }
  }
}
