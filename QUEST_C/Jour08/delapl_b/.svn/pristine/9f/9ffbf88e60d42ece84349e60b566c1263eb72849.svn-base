/*
** my_strstr.c for ok in /home/antoine/Jour04-C/delapl_b/my_strstr
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Thu Oct 22 03:54:26 2015 DELAPLACE Antoine
** Last update Tue Oct 27 11:56:14 2015 DELAPLACE Antoine
*/

int	my_strncmp(char *s1, char *s2, int n);
int	my_strlen(char *str);

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	trouve;

  i = 0;
  trouve = 0;
  while (str[i] && !trouve)
    {
      if (my_strncmp((str + i), to_find, my_strlen(to_find)) == 0)
	trouve = 1;
      else
	++i;
    }
  if (!trouve)
    {
      return "null";
    }
  return (str + i);
}
