/*
** my_params_in_list.c for ok in /home/antoine/C/Jour09-C/delapl_b/my_params_in_list
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Tue Oct 27 19:28:05 2015 DELAPLACE Antoine
** Last update Tue Oct 27 19:58:53 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "my_list.h"

t_list		*add_item(t_list *list, char *data)
{
  t_list	*node;

  node = malloc(sizeof(*node));
  if (node == 0)
    return (0);
  node->next = list;
  node->data = data;
  return (node);
}

t_list		*my_params_in_list(int ac, char **av)
{
  int		i;
  t_list	*list;

  i = 0;
  list = 0;
  while (i < ac)
    {
      list = add_item(list, av[i]);
      i++;
    }
  return (list);
}
