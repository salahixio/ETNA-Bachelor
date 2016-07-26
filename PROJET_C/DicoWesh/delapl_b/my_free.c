/*
** my_free.c for ok in /home/antoine/Documents/ALGO/DicoWesh/delapl_b/DicoWESH
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Sat Nov  7 11:25:14 2015 DELAPLACE Antoine
** Last update Sat Nov  7 11:52:38 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/struct_dico.h"

void	my_free(t_dico *dico)
{
  t_dico *next;

  next = dico;
  while (next != 0)
    {
      next = dico->next;
      free(dico);
      dico = next;
    }
}
