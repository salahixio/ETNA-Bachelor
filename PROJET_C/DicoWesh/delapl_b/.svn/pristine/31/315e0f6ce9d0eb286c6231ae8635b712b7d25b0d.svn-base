/*
** load_dico.c for dico in /home/antoine/Documents/ALGO/DicoWesh/delapl_b/DicoWESH
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Nov  5 17:01:55 2015 DELAPLACE Antoine
** Last update Sat Nov  7 13:03:08 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include "header/struct_dico.h"
#include "header/fonction_lib.h"

t_dico		*aff_dico_wesh(t_dico *dico);
t_dico		*aff_dico_fr(t_dico *dico);
void		wesh_to_fr(char *str, t_dico *dico);
void		fr_to_wesh(char *str, t_dico *dico);
t_dico		*ajout_def(t_dico *dico);
char		*saisir_mot_wesh();
char		*saisir_mot_fr();
char		*readLine();
t_dico		*add_elem(t_dico *dico, char *str1, char *str2);
void		load_def(char *choice, t_dico *dico);
int		check_word(char *str);
void		print_error_word();

t_dico		*load_dico(t_dico *dico, char *choice)
{
  if (my_strcmp(choice, "a") == 0)
    dico = aff_dico_wesh(dico);
  else if (my_strcmp(choice, "b") == 0)
    dico = aff_dico_fr(dico);
  else if (my_strcmp(choice, "1") == 0)
    dico = ajout_def(dico);
  else if (my_strcmp(choice, "q") != 0)
    load_def(choice, dico);
  return (dico);
}

void            load_def(char *choice, t_dico *dico)
{
  char          *mot_wesh;
  char          *mot_fr;

  if (my_strcmp(choice, "2") == 0)
    {
      mot_wesh = saisir_mot_wesh();
      wesh_to_fr(mot_wesh, dico);
      free(mot_wesh);
    }
  else if (my_strcmp(choice, "3") == 0)
    {
      mot_fr = saisir_mot_fr();
      fr_to_wesh(mot_fr, dico);
      free(mot_fr);
    }
}

char            *saisir_mot_fr()
{
  char          *entry;

  entry = "";
  my_putstr("Wesh c'est what ton mot en fr ?\n");
  while (!check_word(entry))
    {
      entry = readLine();
      if (!check_word(entry))
	print_error_word();
    }
  return (entry);
}

char            *saisir_mot_wesh()
{
  char          *entry;

  entry = "";
  my_putstr("Zyva c'est what ton mot en wesh ?\n");
  while (!check_word(entry))
    {
      entry = readLine();
      if (!check_word(entry))
	print_error_word();
    }
  return (entry);
}

t_dico		*ajout_def(t_dico *dico)
{
  char		*mot_wesh;
  char		*mot_fr;
  t_dico        *begin;
  int           find;

  mot_wesh = saisir_mot_wesh();
  mot_fr = saisir_mot_fr();
  begin = dico;
  find = 0;
  while (dico != 0 && find == 0)
    {
      if (my_strcmp(mot_wesh, dico->mot_wesh) == 0)
	{
	  dico->mot_fr = mot_fr;
	  find = 1;
	}
      else
	dico = dico->next;
    }
  dico = begin;
  if (!find)
    dico = add_elem(dico, mot_wesh, mot_fr);
  return (dico);
}
