/*
** my_strncpy.c for ok in /home/antoine/Jour04-C/delapl_b/my_strncpy
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 20:42:35 2015 DELAPLACE Antoine
** Last update Thu Oct 22 06:36:31 2015 DELAPLACE Antoine
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && *(src + i) != '\0')
    {
      *(dest + i) = *(src + i);
      ++i;
    }
  while (i < n)
    {
      *(dest + i) = '\0';
      ++i;
    }
  return (dest);
}
