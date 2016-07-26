/*
** my_apply_on_list.c for ok in /home/antoine/C/Jour09-C/delapl_b/my_apply_on_list
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 28 00:30:36 2015 DELAPLACE Antoine
** Last update Wed Oct 28 01:24:34 2015 DELAPLACE Antoine
*/

#include <stdlib.h>
#include "my_list.h"

void		my_apply_on_list(t_list *begin, int (*f)())
{
  t_list	*save_begin;

  save_begin = malloc(sizeof(t_list *));
  save_begin = begin;
  while (save_begin != 0)
    {
      f(save_begin->data);
      save_begin = save_begin->next;
    }
}
