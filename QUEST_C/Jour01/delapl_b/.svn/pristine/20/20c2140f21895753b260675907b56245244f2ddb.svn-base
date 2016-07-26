/*
** my_aff_comb.c for my_aff_comb in /home/delapl_b/Jour01-C/delapl_b/my_aff_comb
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Mon Oct 19 17:09:38 2015 DELAPLACE Antoine
** Last update Mon Oct 19 17:14:15 2015 DELAPLACE Antoine
*/

void	print_chars(char i, char j, char k);
void    my_putchar(char c);

void	my_aff_comb()
{
  char	i;
  char	j;
  char	k;
  
  for (i = 48; i < 58; i = i + 1)
    {
      for (j = 48; j < 58; j = j + 1)
	{
	  for (k = 48; k < 58; k = k + 1)
	    {
	      if (i < j && i < k && j < k)
		{
		  print_chars(i, j, k);
		}
	    }
	}
    }
}

void	print_chars(char i, char j, char k)
{
  my_putchar(i);
  my_putchar(j);
  my_putchar(k);
  if(i == 55 && j == 56 && k == 57)
    {
      my_putchar('\n');
    }
  else
    {
      my_putchar(',');
      my_putchar(' ');
    }
}
