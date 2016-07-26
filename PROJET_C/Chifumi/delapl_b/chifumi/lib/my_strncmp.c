/*
** my_strncmp.c for ok in /home/antoine/Jour04-C/delapl_b/my_strncmp
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 22:38:15 2015 DELAPLACE Antoine
** Last update Thu Oct 22 06:38:50 2015 DELAPLACE Antoine
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	compare;

  i = 0;
  compare = 0;
  while (*(s1 + i) != '\0' && compare == 0 && (i + 1) < n)
    {
      if (*(s1 + i) > *(s2 + i))
	compare = 1;
      else if (*(s2 + i) > *(s1 + i))
	compare = (-1);
      ++i;
    }
  if (compare == 0)
    {
      if (*(s1 + i) > *(s2 + i))
	compare = 1;
      else if (*(s2 + i) > *(s1 + i))
	compare = (-1);
    }
  return (compare);
}
