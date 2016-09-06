/*
** my_put_nbr.c for my_put_nbr in /home/houvet_b/Jour05c/houvet_b/my_put_nbr
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 15:07:27 2015 HOUVET Benoît - Xavier
** Last update Thu Sep  1 14:15:27 2016 LEJMAN Romain
*/

void	my_putchar(char c);

void	my_put_nbr(int n)
{
  if (n == -2147483648LL)
    {
      my_putchar('-');
      my_putchar('2');
      n = 147483648;
    }
  if (n < 0)
    {
      n *= -1;
      my_putchar('-');
    }
  if (n < 10)
    {
      my_putchar(n + '0');
    }
  else
    {
      my_put_nbr(n / 10);
      my_put_nbr(n % 10);
    }
}
