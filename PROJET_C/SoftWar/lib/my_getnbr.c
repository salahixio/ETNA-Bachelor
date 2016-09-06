/*
** my_getnbr.c for my_getnbr in /home/houvet_b/Jour05c/houvet_b/my_getnbr
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 15:42:48 2015 HOUVET Benoît - Xavier
** Last update Sat Oct 24 15:53:13 2015 HOUVET Benoît - Xavier
*/

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	signe;
  int	nbr;

  i = 0;
  signe = 1;
  j = 1;
  nbr = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	signe *= -1;
      i += 1;
    }
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
      if (j == 1)
	  nbr = (str[i] - '0');
      else
	  nbr = ((nbr * 10) + str[i] - '0');
      j += 1;
      i += 1;
    }
  return (nbr * signe);
}
