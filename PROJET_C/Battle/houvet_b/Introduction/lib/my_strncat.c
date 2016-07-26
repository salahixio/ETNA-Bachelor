/*
** my_strncat.c for my_strncat in /home/houvet_b/libmy
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Sat Oct 24 15:30:55 2015 HOUVET Benoît - Xavier
** Last update Sat Oct 24 15:32:36 2015 HOUVET Benoît - Xavier
*/

char	*my_strncat(char *str1, char *str2, int n)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (*(str1 + i) != '\0')
    {
      i += 1;
    }
  while (*(str2 + j) != '\0' && j < n)
    {
      *(str1 + i + j) = *(str2 + j);
      j += 1;
    }
  return (str1);
}
