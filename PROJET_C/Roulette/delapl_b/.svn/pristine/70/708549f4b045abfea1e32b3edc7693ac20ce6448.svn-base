/*
** check_chiffre.c for ok in /home/antoine/Colle2/delapl_b/roulette
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 22:36:02 2015 DELAPLACE Antoine
** Last update Sat Oct 24 01:08:30 2015 DELAPLACE Antoine
*/

char	*readLine();
void	my_putstr(char *str);
int	my_getnbr(char *str);
char	*my_strcpy(char *dest, char *src);
void	my_put_nbr(int n);
void	clean_entry(char *str);

int	check_chiffre()
{
  char	entry_chiffre[50];
  int	chiffre;

  my_putstr("C'est le moment de se concentrer, quel est votre chiffre ?\n");
  chiffre = 0;
  while (chiffre <= 0 || chiffre > 36)
    {
      my_strcpy(entry_chiffre, readLine());
      chiffre = my_getnbr(entry_chiffre);
      if (chiffre <= 0)
	my_putstr("Vous vous trompez ... Recommencez svp\n");
      if (chiffre > 36)
	my_putstr("Votre chiffre est trop grand ... Recommencez svp\n");
      clean_entry(entry_chiffre);
    }
  my_putstr("\nVous avez choisi le chiffre : ");
  my_put_nbr(chiffre);
  my_putstr("\n");
  return (chiffre);
}
