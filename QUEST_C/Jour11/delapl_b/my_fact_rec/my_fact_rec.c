/*
** my_fact_rec.c for fact_rev in /home/antoine/ALGO/Jour01/delapl_b/my_fact_rec
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Mon Nov  2 10:18:41 2015 DELAPLACE Antoine
** Last update Mon Nov  2 15:38:56 2015 DELAPLACE Antoine
*/

int	my_fact_rec(int nb)
{
  int	fact;

  fact = 0;
  if (nb < 0)
    return (0);
  else if (nb == 0)
    return (1);
  else
    fact += my_fact_rec(nb - 1) * nb;
  return (fact);
}
