/*
** my_strncpy.c for my_strncpy in /home/houvet_b/libmy
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Sat Oct 24 15:10:47 2015 HOUVET Benoît - Xavier
** Last update Sat Oct 24 15:13:52 2015 HOUVET Benoît - Xavier
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && *(src + i) != '\0')
    {
      *(dest + i) = *(src + i);
      i += 1;
    }
  while (i < n)
    {
      *(dest + i) = '\0';
      i += 1;
    }
  return (dest);
}
