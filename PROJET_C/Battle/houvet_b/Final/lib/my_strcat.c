/*
** my_strcat.c for my_strcat in /home/houvet_b/libmy
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Sat Oct 24 15:25:35 2015 HOUVET Benoît - Xavier
** Last update Sat Oct 24 15:30:26 2015 HOUVET Benoît - Xavier
*/

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (*(str1 + i) != '\0')
    {
      i += 1;
    }
  while (*(str2 + j) != '\0')
    {
      *(str1 + i + j) = *(str2 + j);
      j += 1;
    }
  return (str1);
}
