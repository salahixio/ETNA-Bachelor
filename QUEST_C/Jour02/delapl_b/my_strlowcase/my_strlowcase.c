/*
** my_strlowcase.c for ok in /home/antoine/Jour02-C/delapl_b/my_strlowcase
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Tue Oct 20 13:18:00 2015 DELAPLACE Antoine
** Last update Tue Oct 20 13:18:18 2015 DELAPLACE Antoine
*/

char    *my_strlowcase(char str[])
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
	{
	  str[i] += 32;
	}
      i = i + 1;
    }
  return (str);
}
