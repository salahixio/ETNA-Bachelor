/*
** my_apply_on_eq_list.c for ok in /home/antoine/C/Jour09-C/delapl_b/my_apply_on_eq_list
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 28 01:26:22 2015 DELAPLACE Antoine
** Last update Wed Oct 28 22:10:32 2015 DELAPLACE Antoine
*/

#include <stdlib.h>
#include "my_list.h"

void		my_apply_on_eq_list(t_list *begin, int (*f)(),
				    void *data_ref, int (*cmp)())
{
  t_list	*save_begin;

  save_begin = malloc(sizeof(t_list *));
  save_begin = begin;
  while (save_begin != 0)
    {
      if (cmp(save_begin->data, data_ref) == 0)
	f(save_begin->data);
      save_begin = save_begin->next;
    }
}
