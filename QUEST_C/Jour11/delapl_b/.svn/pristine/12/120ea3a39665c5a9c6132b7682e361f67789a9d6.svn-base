/*
** findstr_rec.c for findstr_rec in /home/antoine/ALGO/Jour01/delapl_b/findstr_rec
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Mon Nov  2 11:25:41 2015 DELAPLACE Antoine
** Last update Mon Nov  2 12:03:17 2015 DELAPLACE Antoine
*/

int	my_strncmp(char *s1, char *s2, int n);
int	my_strlen(char *str);

int	findstr_rec(char* str, char* to_find)
{
  int find;

  find = 0;
  if (my_strncmp(str, to_find, my_strlen(to_find)) == 0)
    return (1);
  if ((*str) != '\0')
    find = findstr_rec(str + 1, to_find);
  return (find);
}

int	my_strlen(char *str)
{
  int   i;

  i = 0;
  while (*(str + i) != '\0')
    {
      ++i;
    }
  return (i);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;
  int   compare;

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
