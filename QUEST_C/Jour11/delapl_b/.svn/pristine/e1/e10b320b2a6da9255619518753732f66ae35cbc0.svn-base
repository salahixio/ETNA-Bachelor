/*
** my_is_prime.c for my_is_prime in /home/antoine/ALGO/Jour01/delapl_b/my_is_prime
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Mon Nov  2 12:20:41 2015 DELAPLACE Antoine
** Last update Mon Nov  2 13:02:26 2015 DELAPLACE Antoine
*/

int	my_is_prime(int n, int k)
{
  int	is_prime;

  is_prime = 1;
  if (k <= 1)
    return (0);
  else if (k % n == 0 && n != k)
    return (0);
  else if (n > 2)
    is_prime = my_is_prime(n - 1, k);
  return (is_prime);
}
