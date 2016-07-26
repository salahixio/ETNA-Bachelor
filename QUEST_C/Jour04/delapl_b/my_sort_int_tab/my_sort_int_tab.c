/*
** my_sort_int_tab.c for ok in /home/antoine/Jour02-C/delapl_b/my_sort_int_tab
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Tue Oct 20 15:15:52 2015 DELAPLACE Antoine
** Last update Wed Oct 21 19:55:05 2015 DELAPLACE Antoine
*/

void		my_sort_int_tab(int *tab, int size)
{
  int		i;
  int		j;
  int		min;
  int		indice_min;
  
  i = 0;
  while (i < size - 1)
    {
      min = tab[i];
      indice_min = i;
      j = i;
      while (++j < size)
	{
	  if (tab[j] < min)
	    {
	      min = tab[j];
	      indice_min = j;
	    }
	}
      if (i != indice_min)
	{
	  tab[indice_min] = tab[i];
	  tab[i] = min;
	}
      i = i + 1;
    }
}
