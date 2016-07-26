/*
** my_strdup.c for ok in /home/antoine/C/Jour07-C/delapl_b/my_strdup
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Mon Oct 26 10:24:55 2015 DELAPLACE Antoine
** Last update Mon Oct 26 16:18:23 2015 DELAPLACE Antoine
*/

#include <stdlib.h>

int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);

char	*my_strdup(char *str)
{
  char	*cpy_str;

  cpy_str = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (cpy_str == 0)
    return (NULL);
  cpy_str = my_strcpy(cpy_str, str);
  return (cpy_str);
}
