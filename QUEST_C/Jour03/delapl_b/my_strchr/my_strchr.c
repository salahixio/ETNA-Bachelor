/*
** my_strchr.c for ok in /home/antoine/Jour03-C/delapl_b/my_strchr
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 09:58:20 2015 DELAPLACE Antoine
** Last update Wed Oct 21 10:46:54 2015 DELAPLACE Antoine
*/

char	*my_strchr(char *str, int c)
{
  while (*str != '\0' && *str != c)
      str = str + 1;
  return (str);
}
