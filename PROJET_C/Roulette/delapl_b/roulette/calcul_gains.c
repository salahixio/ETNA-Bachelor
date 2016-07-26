/*
** calcul_gains.c for ok in /home/antoine/Colle2/delapl_b/roulette
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 22:45:21 2015 DELAPLACE Antoine
** Last update Sat Oct 24 01:30:05 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include<time.h>

void	my_put_nbr(int n);
int	my_is_even(int n);
int	my_is_odd(int n);
void	my_putstr(char *str);
int	my_random();
void	affiche_roulette();

int	calcul_gains(int gains, int mise, int chiffre)
{
  int	roulette;

  gains -= mise;
  roulette = my_random();
  affiche_roulette(roulette);
  if (chiffre == roulette)
    {
      gains += mise * 3;
      my_putstr("Vous êtes tombé sur le gros lot! Quel chanceux !\n");
    }
  else if ((my_is_even(chiffre) && my_is_even(roulette)) ||
	   (my_is_odd(chiffre) && my_is_odd(roulette)))
    {
      if (mise == 1)
	gains += 2;
      else
	gains += mise + (mise / 2);
      my_putstr("Vous avez trouvé la couleur! C'est gagné! Bravo!\n");
    }
  else
    my_putstr("Dommage ... C'est pour la prochaine partie !\n");
  my_putstr("Vos gains sont maintenant de ");
  my_put_nbr(gains);
  return (gains);
}

int	my_is_even(int n)
{
  return (n % 2 == 0);
}

int	my_is_odd(int n)
{
  return (!(n % 2 == 0));
}

int	my_random()
{
  srand (time (NULL));
  return ((rand()% 36) + 1);
}

void	affiche_roulette(int roulette)
{
  my_putstr("Je lance la roulette ...\n");
  my_putstr("Et la bille est tombé sur le ... ");
  my_put_nbr(roulette);
  my_putstr(" !!\n\n");
}

