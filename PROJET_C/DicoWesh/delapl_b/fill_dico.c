/*
** fill_dico.c for dico in /home/antoine/Documents/ALGO/DicoWesh/delapl_b/DicoWESH
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Nov  5 15:59:40 2015 DELAPLACE Antoine
** Last update Sat Nov  7 12:56:06 2015 DELAPLACE Antoine
*/

#include <stdlib.h>
#include "header/fonction_lib.h"
#include "header/struct_dico.h"

t_dico		*add_elem(t_dico *dico, char *wesh, char *fr, char *mp3);

t_dico		*fill_dico(t_dico *dico)
{
  dico->mot_wesh = "zobe";
  dico->mot_fr = "penis";
  dico->mp3 = "mp3/zobe.mp3";
  dico->next = NULL;
  if ((dico = add_elem(dico, "taspe", "salope", "mp3/taspe.mp3")) == 0)
    return (NULL);
  if ((dico = add_elem(dico, "facho", "faschiste", "mp3/facho.mp3")) == 0)
    return (NULL);
  if ((dico = add_elem(dico, "eclater", "frapper", "mp3/eclater.mp3")) == 0)
    return (NULL);
  if ((dico = add_elem(dico, "engrener", "provoquer", "mp3/engrener.mp3")) == 0)
    return (NULL);
  if ((dico = add_elem(dico, "mac", "proxenete", "mp3/mac.mp3")) == 0)
    return (NULL);
  if ((dico = add_elem(dico, "soce", "ami", "mp3/soce.mp3")) == 0)
    return (NULL);
  if ((dico = add_elem(dico, "emmerder", "importuner", "mp3/emmerder.mp3")) == 0)
    return (NULL);
  if ((dico = add_elem(dico, "kho", "frere", "mp3/kho.mp3")) == 0)
    return (NULL);
  if ((dico = add_elem(dico, "pede", "homosexuel", "mp3/pede.mp3")) == 0)
    return (NULL);
  if ((dico = add_elem(dico, "alpaguer", "attraper", "mp3/alpaguer.mp3")) == 0)
    return (NULL);
  return (dico);
}

t_dico		*add_elem(t_dico *dico, char *wesh, char *fr, char *mp3)
{
  t_dico	*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  if (new_elem == 0)
    {
      my_putstr("L'ajout dans la liste a échouée, problème m\
émoire\n");
      return (NULL);
    }
  new_elem->mot_wesh = wesh;
  new_elem->mot_fr = fr;
  new_elem->mp3 = mp3;
  new_elem->next = dico;
  return (new_elem);
}
