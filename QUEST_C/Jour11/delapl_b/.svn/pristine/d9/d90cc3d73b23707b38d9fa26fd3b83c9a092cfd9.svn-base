/*
** my_fibo_rec.c for fibo_rec in /home/antoine/ALGO/Jour01/delapl_b/my_fibo_rec
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Mon Nov  2 10:36:58 2015 DELAPLACE Antoine
** Last update Mon Nov  2 10:45:57 2015 DELAPLACE Antoine
*/

int	my_fibo_rec(int nb)
{
  int	fibo;

  fibo = 0;
  if (nb < 0)
    return (0);
  else if (nb >= 2)
    {
      fibo += my_fibo_rec(nb - 1) + my_fibo_rec(nb - 2);
      return (fibo);
    }
  else
    return (1);
}
