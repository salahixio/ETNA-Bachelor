/*
** my_strcmp.c for my_strcmp in /home/houvet_b/libmy
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Sat Oct 24 15:15:40 2015 HOUVET Benoît - Xavier
** Last update Sat Oct 24 15:21:02 2015 HOUVET Benoît - Xavier
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	try;

  i = 0;
  try = 0;
  while (*(s1 + i) != '\0' && try == 0)
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
