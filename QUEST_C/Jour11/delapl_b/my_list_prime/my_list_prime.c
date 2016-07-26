/*
** my_list_prime.c for list_prime in /home/antoine/ALGO/Jour01/delapl_b/my_list_prime
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Mon Nov  2 13:04:25 2015 DELAPLACE Antoine
** Last update Mon Nov  2 14:51:49 2015 DELAPLACE Antoine
*/

#include <unistd.h>

void	my_putchar(char c);
void	my_putstr(char *c);
void	my_put_nbr(int n);

void my_list_prime(int n, int k)
{
  if (k > 0)
    {
      if (n > 0)
	{
	  my_list_prime(n - 1, k);
	  if (k % n == 0)
	    {
	      my_put_nbr(n);
	      my_putstr("\n");
	    }
	}
    }
}

void    my_put_nbr(int n)
{
  int   diviseur;
  int   reste;

  if (n == -2147483648)
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

void    my_putstr(char *str)
{
  int   i;

  i = 0;
  while (*(str + i) != '\0')
    {
      my_putchar(*(str + i));
      ++i;
    }
}

void    my_putchar(char c)
{
  write(1, &c, 1);
}
