/*
** check_mise.c for ok in /home/antoine/Colle2/delapl_b/roulette
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 22:11:14 2015 DELAPLACE Antoine
** Last update Sat Oct 24 00:48:00 2015 DELAPLACE Antoine
*/

char	*readLine();
void	my_putstr(char *str);
int	my_getnbr(char *str);
char	*my_strcpy(char *dest, char *src);
void	clean_entry(char *str);

int	check_mise(int gains)
{
  char	entry[50];
  int	mise;

  my_putstr("N'ayez pas peur, dites moi le montant de votre mise svp...\n");
  mise = 0;
  while (mise <= 0 || mise > gains)
    {
      my_strcpy(entry, readLine());
      mise = my_getnbr(entry);
      if (mise <= 0)
	my_putstr("Ne soyez pas timide ... Recommencez svp\n");
      if (mise > gains)
	my_putstr("Doucement ... vous etes sur de vouloir faire ça ? Recommencez svp\n");
      clean_entry(entry);
    }
  my_putstr("\n");
  return (mise);
}
