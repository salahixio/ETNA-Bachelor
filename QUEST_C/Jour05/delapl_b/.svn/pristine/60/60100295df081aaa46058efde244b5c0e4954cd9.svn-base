/*
** my_put_nbr.c for ok in /home/antoine/Jour05-C/delapl_b/my_put_nbr
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 13:40:12 2015 DELAPLACE Antoine
** Last update Sat Oct 24 03:48:47 2015 DELAPLACE Antoine
*/

void	my_putchar(char c);
void	my_putstr(char *c);

void	my_put_nbr(int n)
{
  int	diviseur;
  int	reste;

  if(n == -2147483648)
    my_putstr("-2147483648");
  else
    {
      reste = 0;
      diviseur = 1;
      if (n < 0)
	{
	  my_putchar('-');
	  n = n * (-1);
	}
      while ((n / diviseur) > 10)
	diviseur = diviseur * 10;
      while (diviseur >= 1)
	{
	  reste = n / diviseur;
	  my_putchar(reste + 48);
	  n = n % diviseur;
	  diviseur = diviseur / 10;
	}
    }
}
