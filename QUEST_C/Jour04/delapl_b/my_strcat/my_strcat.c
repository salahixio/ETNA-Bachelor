/*
** my_strcat.c for ok in /home/antoine/Jour04-C/delapl_b/my_strcat
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 23:00:06 2015 DELAPLACE Antoine
** Last update Thu Oct 22 06:40:47 2015 DELAPLACE Antoine
*/

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (*(str1 + i) != '\0')
    {
      i++;
    }
  while (*(str2 + j) != '\0')
    {
      *(str1 + i + j) = *(str2 + j);
      j++;
    }
  return (str1);
}
