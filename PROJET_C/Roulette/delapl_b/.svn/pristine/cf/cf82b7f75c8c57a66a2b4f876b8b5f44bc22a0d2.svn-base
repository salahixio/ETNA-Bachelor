/*
** check_stop.c for ok in /home/antoine/Colle2/delapl_b/roulette
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 23:23:05 2015 DELAPLACE Antoine
** Last update Fri Oct 23 23:59:24 2015 DELAPLACE Antoine
*/

char	*readLine();
void	my_putstr(char *str);
char	*my_strcpy(char *dest, char *src);

int	check_stop(int gains)
{
  int	stop;
  char	entry[50];
  
  stop = 0;
  if (gains == 0)
    {
      my_putstr("\nVous êtes à sec... Désolé je dois vous demandez de partir...\n");
      stop = 1;
    }
  if (stop == 0)
    {
      my_putstr("\nUne autre partie ? (y/n)\n");
      while (entry[0] != 'y' && entry[0] != 'n')
	{
	  my_strcpy(entry, readLine());
	  if(entry[0] != 'y' && entry[0] != 'n')
	    my_putstr("Il me faut une reponse claire svp. (y/n)\n");
	  else if(entry[0] == 'n')
	    stop = 1;
	}
      my_putstr("\n");
    }
  return (stop);
}
