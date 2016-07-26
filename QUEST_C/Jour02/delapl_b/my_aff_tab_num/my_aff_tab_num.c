/*
** my_aff_tab_num.c for my_aff_tab_num in /home/antoine/Jour02-C/delapl_b/my_aff_tab_num
** 
** Made by MOULINETTE Edouard
** Login   <moulin_e@etna-alternance.net>
** 
** Started on  Tue Oct 20 10:35:38 2015 MOULINETTE Edouard
** Last update Tue Oct 20 10:49:27 2015 MOULINETTE Edouard
*/

void	my_putchar(char c);

void	my_aff_tab_num(int tab[], int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      my_putchar(tab[i] + 48);
      my_putchar('\n');
      i = i + 1;
    }
}
