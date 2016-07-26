/*
** check_saisie.c for dico in /home/antoine/ALGO/DicoWesh/delapl_b/DicoWESH
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Nov  5 12:03:43 2015 DELAPLACE Antoine
** Last update Sat Nov  7 11:06:13 2015 DELAPLACE Antoine
*/

#include "header/fonction_lib.h"

int	check_saisie(char *str)
{
  if (!my_strcmp(str, "a") || !my_strcmp(str, "b") || !my_strcmp(str, "q"))
    return (1);
  else if (!my_strcmp(str, "1") || !my_strcmp(str, "2") || !my_strcmp(str, "3"))
    return (1);
  else
    return (0);
}

int	check_word(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] < '-' || str[i] > 'z' || (str[i] > '9' && str[i] < 'a'))
	return (0);
      ++i;
    }
  return (1);
}
