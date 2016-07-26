/*
** my_add_list_to_list.c for ok in /home/antoine/C/Jour10-C/delapl_b/my_add_list_to_list
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Thu Oct 29 01:55:01 2015 DELAPLACE Antoine
** Last update Thu Oct 29 03:59:33 2015 DELAPLACE Antoine
*/

#include "my_list.h"

t_list		*search_last_element(t_list *list)
{
  while (list->next != 0)
    {
      list = list->next;
    }
  return (list);
}

void		my_add_list_to_list(t_list **begin1, t_list *begin2)
{
  t_list	*save_begin;

  save_begin = *begin1;
  save_begin = search_last_element(save_begin);
  save_begin->next = begin2;
}
