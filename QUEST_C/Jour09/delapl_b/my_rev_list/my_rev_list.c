/*
** my_rev_list.c for ok in /home/antoine/C/Jour09-C/delapl_b/my_rev_list
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Tue Oct 27 20:17:36 2015 DELAPLACE Antoine
** Last update Wed Oct 28 00:25:44 2015 DELAPLACE Antoine
*/

#include <stdlib.h>
#include "my_list.h"

t_list		*search_last_element(t_list *list);

void		my_rev_list(t_list **begin)
{
  t_list	*first_element;
  t_list	*new_first_element;
  t_list	*tmp_first;
  t_list	*last_element;

  first_element = malloc(sizeof(t_list *));
  new_first_element = malloc(sizeof(t_list *));
  tmp_first = malloc(sizeof(t_list *));
  last_element = malloc(sizeof(t_list *));
  first_element = *begin;
  new_first_element = search_last_element(*begin);
  last_element = 0;
  while (first_element != new_first_element)
    {
      while ((*begin) != new_first_element)
	{
	  *begin = (*begin)->next;
	}
	  tmp_first = first_element;
	  first_element = first_element->next;
	  (*begin)->next = tmp_first;
	  tmp_first->next = last_element;
	  last_element = tmp_first;
	  (*begin) = first_element;
    }
}

t_list		*search_last_element(t_list *list)
{
  while (list->next != 0)
    {
      list = list->next;
    }
  return (list);
}
