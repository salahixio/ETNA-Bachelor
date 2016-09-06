/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/houvet_b/Jour07c/houvet_b/my_str_to_wordtab
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Oct 26 11:54:30 2015 HOUVET Benoît - Xavier
** Last update Wed Nov 18 11:35:33 2015 HOUVET Benoît - Xavier
*/

#include <stdlib.h>
#include <stdio.h>

int     my_strlen(char *str);

int	is_numeric(char c)
{
  int	i;

  if ((c >= '0' && c <= '9') ||
      (c >= 'A' && c <= 'Z') ||
      (c >= 'a' && c <= 'z'))
    i = 1;
  else
    i = 0;
  return (i);
}

int     nbr_word(char *str)
{
  int   i;
  int   nbr;

  i = 0;
  nbr = 0;
  while (str[i] != '\0')
    {
      if ((is_numeric(str[i])) == 1)
	i = i + 1;
      else if (i != 0)
	{
	  if ((is_numeric(str[i - 1])) == 1)
	    nbr += 1;
	  i += 1;
	}
    }
  nbr += 1;
  return (nbr);
}

char    *strdupbx(char *str)
{
  char  *retour;
  int   length;
  int   i;

  i = 0;
  length = my_strlen(str);
  retour = malloc((length + 1) * sizeof(char));
  while ((is_numeric(str[i])) == 1)
    {
      retour[i] = str[i];
      i += 1;
    }
  retour[i] = '\0';
  return (retour);
}

char    **my_str_to_wordtab(char *str)
{
  char  **tab;
  int   nb_mots;
  int   i;
  int   j;

  i = 0;
  j = 0;
  nb_mots = nbr_word(str);
  tab = malloc(sizeof(char*) * nb_mots + 1);
  while (str[i] != '\0' && i < my_strlen(str))
    {
      tab[j] = strdupbx(str + i);
      i += my_strlen(tab[j]) + 1;
      while (is_numeric(str[i]) == 0)
	i += 1;
      j += 1;
    }
  tab[j] = "\0";
  return (tab);
}
