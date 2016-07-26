/*
** my_power_rec.c for power_rec in /home/antoine/ALGO/Jour01/delapl_b/my_power_rec
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Mon Nov  2 09:48:11 2015 DELAPLACE Antoine
** Last update Mon Nov  2 15:39:55 2015 DELAPLACE Antoine
*/

int	my_power_rec(int nb, int power)
{
  int	nb_power;

  nb_power = 0;
  if (power < 0)
    return (0);
  else if (power > 0)
    nb_power += my_power_rec(nb, power - 1) * nb;
  else
    nb_power = 1;
  return (nb_power);
}
