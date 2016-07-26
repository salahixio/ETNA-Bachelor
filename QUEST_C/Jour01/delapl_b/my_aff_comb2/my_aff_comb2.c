/*
** my_aff_comb2.c for my_aff_comb2 in /home/delapl_b/Jour01-C/delapl_b/my_aff_comb2
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Mon Oct 19 17:09:38 2015 DELAPLACE Antoine
** Last update Mon Oct 19 17:14:15 2015 DELAPLACE Antoine
*/

void	print_chars(char i, char j, char k, char l);
void	my_putchar(char c);

void	my_aff_comb2()
{
  char	i;
  char	j;
  char	k;
  char	l;

  for (i = 48; i < 58; i = i + 1)
    {
      for (j = 48; j < 58; j = j + 1)
	{
	  for (k = 48; k < 58; k = k + 1)
	    {
	      for (l = 48; l < 58; l = l +1)
		{
		  if ((k > i) || (k == i && l > j))
		    {
		      print_chars(i, j, k, l);
		    }
		}
	    }
	}
    }
}

void print_chars(char i, char j, char k, char l)
{
   my_putchar(i);
   my_putchar(j);
   my_putchar(' ');
   my_putchar(k);
   my_putchar(l);
   if(i == 57 && j == 56 && k == 57 && l == 57)
     {
       my_putchar('\n');
     }
   else
     {
       my_putchar(',');
       my_putchar(' ');
     }
}
