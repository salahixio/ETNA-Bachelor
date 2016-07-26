/*
** print_gains.c for ok in /home/antoine/Colle2/delapl_b/roulette
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 22:01:57 2015 DELAPLACE Antoine
** Last update Fri Oct 23 23:40:08 2015 DELAPLACE Antoine
*/

void	my_put_nbr(int gains);
void	my_putstr(char *str);

void	print_gains(int gains)
{
  my_putstr("Votre porte-monnaie est de ... : ");
  my_put_nbr(gains);
  my_putstr(" euros !!\n\n");
}
