/*
** main.c for ok in /home/antoine/Colle2/delapl_b/roulette
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 21:59:25 2015 DELAPLACE Antoine
** Last update Sat Oct 24 01:28:38 2015 DELAPLACE Antoine
*/

#include<stdlib.h>

void	print_gains(int gains);
void	print_start();
void	print_finish();
int	check_mise(int gains);
int	check_chiffre();
int	calcul_gains(int gains, int mise, int chiffre);
int	check_stop(int gains);

int	main()
{
  int	gains;
  int	mise;
  int	chiffre;
  int	stop;

  system("clear");
  gains = 200;
  stop = 0;
  print_start();
  print_gains(gains);
  while (stop == 0)
    {
      mise = check_mise(gains);
      chiffre = check_chiffre();
      gains = calcul_gains(gains, mise, chiffre);
      stop = check_stop(gains);
    }
  if (gains != 0)
    print_finish();
  return (0);
}
