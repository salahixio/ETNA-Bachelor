/*
** my_getnbr.c for ok in /home/antoine/Jour05-C/delapl_b/my_getnbr
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 17:16:22 2015 DELAPLACE Antoine
** Last update Fri Oct 23 18:15:06 2015 DELAPLACE Antoine
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;
  int	signe;

  i = 0;
  nbr = 0;
  signe = 1;
  while (*(str + i) == '+' || *(str + i) == '-')
    {
      if (*(str + i) == '-')
	signe = signe * (-1);
      i++;
    }
  
  while (*(str + i) >= '0' && *(str + i) <= '9' && *(str + i) != '\0')
    {
      if (i == 0)
	nbr = (*(str + i) - '0');
      else
	nbr = (nbr * 10) + (*(str + i) - '0');
      i++;
    }
  return (nbr * signe);
}
