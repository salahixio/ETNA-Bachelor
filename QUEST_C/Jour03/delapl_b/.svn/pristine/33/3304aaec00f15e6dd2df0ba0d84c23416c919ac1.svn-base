/*
** my_aff_params.c for ok in /home/antoine/Jour03-C/delapl_b/my_aff_params
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 12:05:52 2015 DELAPLACE Antoine
** Last update Wed Oct 21 16:10:22 2015 DELAPLACE Antoine
*/

void	my_putchar(char c);
void	my_putstr(char *str);

void	my_aff_params(int nbr, char **arg)
{
  int	i;

   for (i = 0; i < nbr; i = i + 1)
    {
      my_putstr(*(arg + i));
      my_putchar('\n');
    }
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    {
      my_putchar(*(str + i));
      ++i;
    }
}
