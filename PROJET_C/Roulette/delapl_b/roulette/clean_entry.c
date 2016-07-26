/*
** clean_entry.c for ok in /home/antoine/Colle2/delapl_b/roulette
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Sat Oct 24 00:42:36 2015 DELAPLACE Antoine
** Last update Sat Oct 24 00:49:37 2015 DELAPLACE Antoine
*/

void	clean_entry(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      str[i] = '\0';
      ++i;
    }
}
