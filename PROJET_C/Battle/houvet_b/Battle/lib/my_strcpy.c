/*
** my_strcpy.c for my_strcpy in /home/houvet_b/libmy
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Sat Oct 24 15:07:00 2015 HOUVET Benoît - Xavier
** Last update Sat Oct 24 15:46:33 2015 HOUVET Benoît - Xavier
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (*(src + i) != '\0')
    {
      *(dest + i) = *(src + i);
      i += 1;
    }
  *(dest + i) = '\0';
  return (dest);
}
