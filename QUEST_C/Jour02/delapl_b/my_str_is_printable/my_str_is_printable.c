/*
** my_str_is_printable.c for ok in /home/antoine/Jour02-C/delapl_b/my_str_is_printable
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Tue Oct 20 13:22:15 2015 DELAPLACE Antoine
** Last update Tue Oct 20 13:24:47 2015 DELAPLACE Antoine
*/

int	my_str_is_printable(char str[])
{
  int	i;
  int	j;

  i = 0;
  j = 1;
  while (j == 1 && str[i] != '\0')
    {
      if (str[i] < 31 || str[i] > 126)
	{
	  j = 0;
	}
      i = i + 1;
    }
  return (j);
}
