/*
** check_arguments.c for chifumi in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Thu Oct 29 20:59:50 2015 DELAPLACE Antoine
** Last update Sat Oct 31 15:54:01 2015 DELAPLACE Antoine
*/

#include "header/fonction_lib.h"

int	check_option(char *argv, char option);
int	verify_version(char *argv);
int	verify_duree(char *argv);

int	check_arguments(int argc, char **argv)
{
  my_putstr("\n");
  if (argc < 5)
    my_putstr("Il vous manque des arguments\n");
  else if (argc > 5)
    my_putstr("Vous avez entrez trop d'arguments\n");
  else if (!check_option(argv[1], 'v'))
    my_putstr("Vous n'avez pas indiqué la version\n");
  else if (!check_option(argv[3], 'd'))
    my_putstr("Vous n'avez pas indiqué la durée de la partie\n");
  else if (!verify_version(argv[2]))
    my_putstr("Votre version demandée n'existe pas\n");
  else if (!verify_duree(argv[4]))
    my_putstr("Le nombre de manche n'est pas valide\n");
  else
    return (1);
  my_putstr("Utilisation : ./chifumi -v (3 ou 5) -d (nombre impair)\n\n");
  return (0);
}

int	check_option(char *arg, char option)
{
  if (option == 'v'
      && (my_strcmp(arg, "--version") == 0 || my_strcmp(arg, "-v") == 0))
    return (1);
  else if (option == 'd'
	   && (my_strcmp(arg, "--duree") == 0 || my_strcmp(arg, "-d") == 0))
    return (1);
  else
    return (0);
}

int	verify_version(char *arg)
{
  if ((arg[0] == '3' || arg[0] == '5') && arg[1] == '\0')
    return (1);
  else
    return (0);
}

int	verify_duree(char *arg)
{
  if (my_getnbr(arg) <= 0 || !my_is_odd(my_getnbr(arg)))
    return (0);
  else
    return (1);
}
