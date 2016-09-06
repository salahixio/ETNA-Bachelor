/*
** my_strdup.c for my_strdup in /home/houvet_b/Jour07c/houvet_b/my_strdup
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Mon Oct 26 10:54:08 2015 HOUVET Benoît - Xavier
** Last update Wed Oct 28 14:25:14 2015 HOUVET Benoît - Xavier
*/

#include <stdlib.h>

char    *my_strcpy(char *dest, char *src);

int	my_strlen(char *str);


char	*my_strdup(char *str)
{
  int	length;
  char	*chaine;

  length = my_strlen(str);
  chaine = malloc((sizeof(char) * length) + 1);
  if (chaine == 0)
    return (NULL);
  else
    {
      my_strcpy(chaine, str);
      return (chaine);
    }
}
