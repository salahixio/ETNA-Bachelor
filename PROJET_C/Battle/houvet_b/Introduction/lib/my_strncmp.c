/*
** my_strncmp.c for my_strncmp in /home/houvet_b/libmy
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Sat Oct 24 15:21:47 2015 HOUVET Benoît - Xavier
** Last update Sat Oct 24 15:24:59 2015 HOUVET Benoît - Xavier
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;
  int   try;

  i = 0;
  try = 0;
  while (*(s1 + i) != '\0' && try == 0 && (i + 1) < n)
    {
      if (*(s1 + i) > *(s2 + i))
        try = 1;
      else if (*(s2 + i) > *(s1 + i))
        try = (-1);
      i += 1;
    }
  if (try == 0)
    {
      if (*(s1 + i) > *(s2 + i))
        try = 1;
      else if (*(s2 + i) > *(s1 + i))
        try = (-1);
    }
  return (try);
}
