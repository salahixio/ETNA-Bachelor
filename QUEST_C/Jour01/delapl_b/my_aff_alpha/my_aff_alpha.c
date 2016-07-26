/*
** my_aff_alpha.c for my_aff_alpha in /home/delapl_b/Jour01-C/delapl_b/my_aff_alpha
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Mon Oct 19 15:20:12 2015 DELAPLACE Antoine
** Last update Mon Oct 19 15:37:14 2015 DELAPLACE Antoine
*/

void	my_putchar(char c);

void	my_aff_alpha()
{
  int	i;

  for (i = 97; i < 123; i = i + 1)
    {
      my_putchar(i);
    }
}
