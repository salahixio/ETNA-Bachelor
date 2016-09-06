/*
** my_strstr.c for my_strstr in /home/houvet_b/libmy
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Sat Oct 24 15:33:06 2015 HOUVET Benoît - Xavier
** Last update Wed Aug 24 11:52:02 2016 DELAPLACE Antoine
*/

char    *my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (to_find[0] == str[i])
	{
	  while (to_find[j] != '\0' && str[i + j] == to_find[j]
		 && str[i + j] != '\0')
	    {
	      j += 1;
	    }
	  if (to_find[j] == '\0')
	    {
	      return (&str[i]);
	    }
	}
      i += 1;
    }
  to_find = "null";
  return (to_find);
}
