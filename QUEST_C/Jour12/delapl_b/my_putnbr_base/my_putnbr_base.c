/*
** my_putnbr_base.c for putnbr in /home/antoine/ALGO/Jour02/delapl_b/my_putnbr_base
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Nov  3 11:00:18 2015 DELAPLACE Antoine
** Last update Tue Nov  3 15:25:47 2015 DELAPLACE Antoine
*/

int	my_strlen(char *str);
void	my_putchar(char c);

void	my_putnbr_base(int nbr, char *base)
{
  if (nbr >= my_strlen(base))
    {
      my_putnbr_base(nbr / my_strlen(base), base);
      my_putchar(base[(nbr % my_strlen(base))]);
    }
  else if (nbr < 0)
    {
      my_putchar('-');
      my_putnbr_base((-nbr), base);
    }
  else
    my_putchar(base[nbr]);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (*(str + i) != '\0')
    {
      ++i;
    }
  return (i);
}
