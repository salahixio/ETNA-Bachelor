/*
** my_strncat.c for ok in /home/antoine/Jour04-C/delapl_b/my_strncat
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 23:53:44 2015 DELAPLACE Antoine
** Last update Wed Oct 21 23:54:47 2015 DELAPLACE Antoine
*/

char	*my_strncat(char *str1, char *str2, int n)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (*(str1 + i) != '\0')
    {
      i++;
    }
  while (*(str2 + j) != '\0' && j < n)
    {
      *(str1 + i + j) = *(str2 + j);
      j++;
    }
  return (str1);
}
