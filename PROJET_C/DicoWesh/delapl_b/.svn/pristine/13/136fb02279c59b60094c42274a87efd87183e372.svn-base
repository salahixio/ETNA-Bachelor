/*
** aff_dico.c for dico in /home/antoine/Documents/ALGO/DicoWesh/delapl_b/DicoWESH
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Nov  5 17:22:12 2015 DELAPLACE Antoine
** Last update Fri Nov  6 20:07:12 2015 DELAPLACE Antoine
*/

#include "header/fonction_lib.h"
#include "header/struct_dico.h"

t_dico		*tri_dico(t_dico *dico, int sens);
void		play_sound_for_word(char *name);

t_dico		*aff_dico_wesh(t_dico *dico)
{
  t_dico	*begin;

  dico = tri_dico(dico, 1);
  begin = dico;
  while (dico != 0)
    {
      my_putstr(dico->mot_wesh);
      my_putstr(" : ");
      my_putstr(dico->mot_fr);
      my_putstr("\n");
      dico = dico->next;
    }
  dico = begin;
  return (dico);
}

t_dico		*aff_dico_fr(t_dico *dico)
{
  t_dico	*begin;

  begin = dico;
  dico = tri_dico(dico, 0);
  while (dico != 0)
    {
      my_putstr(dico->mot_fr);
      my_putstr(" : ");
      my_putstr(dico->mot_wesh);
      my_putstr("\n");
      dico = dico->next;
    }
  dico = begin;
  return (dico);
}

void		wesh_to_fr(char *str, t_dico *dico)
{
  t_dico	*begin;
  int		find;

  begin = dico;
  find = 0;
  while (dico != 0 && find == 0)
    {
      if (my_strcmp(str, dico->mot_wesh) == 0)
	{
	  my_putstr(str);
	  my_putstr(" : ");
	  my_putstr(dico->mot_fr);
	  my_putstr("\n");
	  find = 1;
	}
      else
	dico = dico->next;
    }
  if (!find)
    my_putstr("Le mot n'est pas dans le dictionnaire\n");
  else
    play_sound_for_word(dico->mp3);
  dico = begin;
}

void		fr_to_wesh(char *str, t_dico *dico)
{
  t_dico	*begin;
  int		find;

  begin = dico;
  find = 0;
  while (dico != 0 && find == 0)
    {
      if (my_strcmp(str, dico->mot_fr) == 0)
	{
	  my_putstr(str);
	  my_putstr(" : ");
	  my_putstr(dico->mot_wesh);
	  my_putstr("\n");
	  find = 1;
	}
      else
	dico = dico->next;
    }
  if (!find)
    my_putstr("Le mot n'est pas dans le dictionnaire\n");
  dico = begin;
}
