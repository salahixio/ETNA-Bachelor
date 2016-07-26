/*
** my_strstr.c for ok in /home/antoine/Jour04-C/delapl_b/my_strstr
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Thu Oct 22 03:54:26 2015 DELAPLACE Antoine
** Last update Thu Oct 22 06:24:58 2015 DELAPLACE Antoine
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
	compare= 1;
      else if (*(s2 + i) > *(s1 + i))
	compare= (-1);
    }
  return (compare);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    {
      ++i;
    }
  return (i);
}

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	trouve;
  
  i = 0;
  trouve = 0;
  while (str[i] && !trouve)
    {
      if (my_strncmp((str + i),to_find,my_strlen(to_find)) == 0)
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
