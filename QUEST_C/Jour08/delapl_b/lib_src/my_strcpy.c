/*
** my_strcpy.c for ok in /home/antoine/Jour04-C/delapl_b/my_strcpy
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 20:00:11 2015 DELAPLACE Antoine
** Last update Tue Oct 27 11:53:13 2015 DELAPLACE Antoine
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (*(src + i) != '\0')
    {
      *(dest + i) = *(src + i);
      ++i;
    }
  *(dest + i) = '\0';
  return (dest);
}
